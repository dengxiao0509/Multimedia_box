//
// Client C++ pour communiquer avec un serveur TCP
// eric lecolinet - telecom paristech - 2013
//

#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include "Socket.h"
using namespace std;

static const char* DEFAULT_HOST = "localhost";
static const int DEFAULT_PORT = 3333;


int main(int argc, char* argv[]) {
    const char* host = DEFAULT_HOST;
    int port = DEFAULT_PORT;

    if (argc >=2) host = argv[1];
    if (argc >=3) port = atoi(argv[2]);

    Socket sock(SOCK_STREAM);

    int status = sock.connect(host, port);
    if (status >= 0)
        cout << "Connected to "<< host<<":"<<port << endl;
    else {
        cerr << "Couldn't connect to: "<< host<<":"<<port << endl;
        return 1;
    }

    SocketBuffer sockbuf(sock);

    while (cin.good()) {
        cout << "Message: ";
        string message;
        getline(cin, message);

        //send a message to the server
        ssize_t sent = sockbuf.writeLine(message);
        if (sent < 0) {
            cerr << "Could not send message to "<<host<<":"<<port<< endl;
            return 2;
        }

        string response;

        //wait for the response from the server,block
        //only the one line of response can be read at one time
        ssize_t received = sockbuf.readLine(response);

        if (received < 0) {
            cerr << "Could not receive message from "<<host<<":"<<port<< endl;
            return 3;
        }

        stringstream mes(message);
        string cmd,obj;
        mes>>cmd;
        mes>>obj;
        stringstream res(response);
        //modify the print style of command " searchmedia XXX"
        if(cmd.compare("searchmedia")==0){



            string typemedia;
            //typemedia<<res;  false!!
            res>>typemedia;
            cout<<"---------------------------------"<<endl;

            string temp;

            if(typemedia.compare("Photo")==0){
                cout<<"Type of media: "<<typemedia<<endl;
                res>>temp;
                cout<<"Name of objet: "<<temp<<endl;
                res>>temp;
                cout<<"Date: "<<temp<<endl;
                res>>temp;
                cout<<"Fichier: "<<temp<<endl;
                res>>temp;
                cout<<"Place: "<<temp<<endl;

            }
            else if(typemedia.compare("Vedio")==0){
                cout<<"Type of media: "<<typemedia<<endl;
                res>>temp;
                cout<<"Name of objet: "<<temp<<endl;
                res>>temp;
                cout<<"Date: "<<temp<<endl;
                res>>temp;
                cout<<"Fichier: "<<temp<<endl;
                res>>temp;
                cout<<"Duration: "<<temp<<endl;

            }
            else if(typemedia.compare("Film")==0){
                cout<<"Type of media: "<<typemedia<<endl;
                res>>temp;
                cout<<"Name of objet: "<<temp<<endl;
                res>>temp;
                cout<<"Date: "<<temp<<endl;
                res>>temp;
                cout<<"Fichier: "<<temp<<endl;
                res>>temp;
                cout<<"Total duration: " <<temp<<endl;
                int nb_c;
                res>>nb_c;
                cout<<"Number of chapiter: "<<nb_c<<endl;
                cout<<"Duration of every chapiter: "<<endl;
                int tem;
                for(int i=0;i<nb_c;i++){
                    if(i==nb_c-1){
                        res>>tem;
                        cout<<tem<<endl;
                    }
                    else {
                        res>>tem;
                        cout<<tem<<'\t';
                    }
                }

            }
            else cout<<res.str()<<endl;


        }//cmd=searchmedia

        else cout<<res.str()<<endl;
    }

    return 0;
}


