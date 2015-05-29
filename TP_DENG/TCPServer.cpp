//
//  TCPServer.cpp: TCP/IP INET Server.
//  (c) Eric Lecolinet - Telecom ParisTech - 2013.
//  http://www.telecom-paristech.fr/~elc
//

#include "TCPServer.h"
#include <unistd.h>
#include <iostream>


using namespace std;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Hook for TCPServer::startReadMessages() (see TCPServer::run())

struct TCPServerHook {
  TCPServerHook(TCPServer* _server, Socket* _sock)
  : server(_server), sock(_sock) {}
  TCPServer* server;
  Socket* sock;
};

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

TCPServer::TCPServer(intrusive_ptr<Multimedia> _multimedia ) : servsock() {

  tcp_multimedia=_multimedia;

  pthread_rwlock_init(&lock, NULL);
}

TCPServer::~TCPServer() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

int TCPServer::run(int port)
{
  // lier le ServerSocket a ce port
  int status = servsock.bind(port);
  
  if (status < 0) {
    cerr << "TCPServer: can't bind on port: "<<port<<" status="<<status<< endl;
    return status;  // valeur negative, voir Socket::bind()
  }

  // ignorer le signal SIGPIPE qui avorterait le serveur en cas d'erreur reseau
  servsock.ignoreSigPipe();
  
  while (true) {
    Socket* sock = servsock.accept();

    if (sock == NULL) {
      cerr << "TCPServer: accept() failed" << endl;
      continue;  // continue va a la prochaine iteration de while()
    }

    // lancer la lecture des messages de ce socket dans un thread.
    // pthread_create() cree un thread qui appelle la methode statique
    // startReadMessages() avec un argument de type (void*) qui est en fait
    // un TCPServerHook*. Ceci permet a startReadMessages() d'appeller la
    // methode d'instance readMessages() avec les argument adequats.

    TCPServerHook* hook = new TCPServerHook(this, sock);
    pthread_t tid;
    
    int status = pthread_create(&tid, NULL, startReadMessages, hook);
    if (status < 0)
      cerr << "TCPServer: pthread_create() failed" << endl;
  }
  
  pthread_exit(NULL);
  return 0;  // OK
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// called by pthread_create()

void* TCPServer::startReadMessages(void* _hook)
{
  TCPServerHook* hook = static_cast<TCPServerHook*>(_hook);
  hook->server->readMessages(hook->sock);
  delete hook;
  return NULL;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TCPServer::readMessages(Socket* sock)
{
  SocketBuffer sockbuf(sock);
  
  while (true) {
    string message, response;
    
    // lire les données envoyées par le client
    // SocketBuffer::readLine() lit jusqu'au premier '\n' (qui est supprimé)
    ssize_t received = sockbuf.readLine(message);
    
    if (received < 0) {
      closeSocketAndThread(sock, "read error");
      continue;
    }
    
    if (received == 0) {
      closeSocketAndThread(sock, "connection closed by client");
      continue;
    }
    
    // traiter le message et retourner la reponse
    // ferme la connection si la valeur de retour est false
    if (! processMessage(message, response)) {
      closeSocketAndThread(sock, "closing connection with client");
      continue;
    }
    
    // toujours envoyer une reponse au client (sinon il va se bloquer)
    // SocketBuffer::writeLine() envoie tout et rajoute '\n'
    ssize_t sent = sockbuf.writeLine(response);
    
    if (sent < 0) {
      closeSocketAndThread(sock,"write error");
      continue;
    }
    
    if (sent == 0) {
      closeSocketAndThread(sock, "connection closed by client");
      continue;
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TCPServer::closeSocketAndThread(Socket* sock, const char* msg)
{
  cerr << "TCPServer: " << msg << " on socket: "<< sock << endl;
  delete sock;          // detruit le socket (NB: le destr fait sock.close())
  pthread_exit(NULL);   // termine le thread
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// Traite le message 'message' et retourne la reponse 'response' ainsi qu'un
// booleen (par return) qui indique si la connection avec le client doit se
// poursuivre (true) ou etre fermée (false).
//
// Cette fonction peut etre executee en parallele par plusieurs threads sauf si
// le verrou 'lock' est bloqué en mode WRITE
/**
 * @brief Used to process the message passed from client,
 * by using a map to store the commands and correspondant fonctions
 * @param message from client
 * @param response to client
 * @return
 */
bool TCPServer::processMessage(const string& message, string& response)
{
  // cette variable indique si la commande modifie les donnees du programme
  // par defaut on suppose que non
  bool change_data = false;

  // supposons que la commande "deletePhotos" modifie les donnees
  if (message == "deletePhotos") change_data = true;

  // suivant le cas, bloquer le verrou en mode WRITE ou en mode READ
  if (change_data)
    pthread_rwlock_wrlock(&lock);  // bloque en mode WRITE
  else
    pthread_rwlock_rdlock(&lock);  // bloque en mode READ



  cout << "TCPServer: message: " << message << endl;
  /*response = "OK: ";
  response += message;
  // sleep(8);                    // sert uniquement a tester le verrou
  */


 // ----traitements des commandes--------/
  string cmd,obj;


  stringstream ss(message);
  stringstream ss_afficher;
  ss>>cmd;
  ss>>obj;  //par reference?

 // CmdMap _cmdmap=tcp_multimedia->getCmdmap();

   tcp_multimedia->Call(cmd,obj,ss_afficher);
 /*
  if(cmd.compare("searchmedia")==0){

      tcp_multimedia->SearchMedia(obj,ss_afficher);

  }
  else if(cmd.compare("searchgroup")==0){
      tcp_multimedia->SearchMediaGroupe(obj,ss_afficher);
 }

  else if(cmd.compare("play")==0){
      tcp_multimedia->PlayMedia(obj);
  }

  else if(cmd.compare("showall")==0){
      tcp_multimedia->PrintMediatoclient(obj,ss_afficher);
  }

  else{
       ss_afficher<<"Command not correct!\n"<<endl;
  }

 */
  response =ss_afficher.str();

  cout << "TCPServer:TCPServer response: " << response << '\n';




  // debloque le verrou (attention ne pas oublier cette ligne !)
  pthread_rwlock_unlock(&lock);

  // retourner false pour fermer la connexion
  return true;
}

