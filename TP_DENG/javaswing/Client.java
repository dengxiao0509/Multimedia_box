package javaswing;

//
//Client Java pour communiquer avec le Serveur C++ 
//eric lecolinet - telecom paristech - 2013
//

import java.io.*;
import java.net.*;


public class Client {
private static final long serialVersionUID = 1L;

private Socket sock;
private BufferedReader input;
private BufferedWriter output;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -



public Client(String host, int port) throws UnknownHostException, IOException {
 try {
   sock = new java.net.Socket(host, port);
 }
 catch (java.net.UnknownHostException e) {
   System.err.println("Client: couldn't find host: "+host+":"+port);
   throw e;
 }
 catch (java.io.IOException e) {
   System.err.println("Client: couldn't reach host: "+host+":"+port);
   throw e;
 }
 
 try {
   input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
   output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
 }
 catch (java.io.IOException e) {
   System.err.println("Client: couldn't open input or output streams");
   throw e;
 }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

/** envoie une commande au server et retourne sa reponse.
* noter que la fonction bloque si le serveur ne repond pas.
*/
public String send(String command) {
 
 // Envoyer la commande au serveur
 try {
   command += '\n';  // ajouter le delimiteur qui separe les messages
   output.write(command, 0, command.length());
   output.flush();
 }
 catch (java.io.IOException e) {
   System.err.println("Client couldn't write: " + e);
   return null;
 }
 
 // Recuperer le resultat retourne par le serveur
 try {
   return input.readLine();
 }
 catch (java.io.IOException e) {
   System.err.println("Client couldn't read: " + e);
   return null;
 }
}
}
