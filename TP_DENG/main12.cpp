#include "multimedia.h"
#include "TCPServer.h"

#define IS_TCPSERVER 1  //0 pour non server
#define IS_SERIALISATION_OUTPUT 0
#define IS_SERIALISATION_INPUT 0
#define IS_TESTFONCTION 0


int main(){

#if IS_SERIALISATION_INPUT

#else
    int nb_cha1=10,nb_cha2=16;
    int* my_p1= new int[nb_cha1];
    int* my_p2= new int[nb_cha2];

    for(int i=0;i<nb_cha1;i++)
    {
        my_p1[i]=i*10;
    }
    for(int i=0;i<nb_cha2;i++)
    {
        my_p2[i]=i*15;
    }

    intrusive_ptr<Multimedia> mymultimedia=new Multimedia("mymultimedia");



    intrusive_ptr<Photo> photo_pekin= mymultimedia->CreatePhoto("myphoto_Pekin",20140721,"ficherphoto_Pekin","Pekin");
    intrusive_ptr<Photo> photo_paris= mymultimedia->CreatePhoto("myphoto_Paris",20141220,"ficherphoto_Paris","Paris");

    intrusive_ptr<Film> film_tantanic=mymultimedia->CreateFilm("myfilm_Tantanic",2016,"fichierfilm_Tantanic",200,nb_cha1,my_p1);
    intrusive_ptr<Film> film_sm=mymultimedia->CreateFilm("myfilm_SuperMan",2016,"fichierfilm_SuperMan",220,nb_cha2,my_p2);

    intrusive_ptr<Vedio> vedio_dx=mymultimedia->CreateVedio("myvedio_Telecom",20141210,"fichervedio_Telecom",10);

    //-----create 2 MediaGroupe--------
    intrusive_ptr<MediaGroupe> my_groupe1=mymultimedia->CreateMediaGroupe("mylist1");
    intrusive_ptr<MediaGroupe> my_groupe2=mymultimedia->CreateMediaGroupe("mylist2");

    //-----add created 5 Media classes into those 2 Mediagroupe-------
    my_groupe1->push_back(photo_paris);
    my_groupe1->push_back(film_tantanic);

    my_groupe2->push_back(photo_pekin);
    my_groupe2->push_back(film_sm);
    my_groupe2->push_back(vedio_dx);
#endif

#if IS_TESTFONCTION


    //-----test fonctions--------
    mymultimedia->RemoveMedia("myphoto_Pekin");
    cout<<"----------Devant remove myphoto_Paris---------------"<<endl;
    my_groupe1->afficher();
    mymultimedia->RemoveMedia("myphoto_Paris");
    cout<<"----------Apres remove myphoto_Paris---------------"<<endl;
    my_groupe1->afficher();

    mymultimedia->SearchMedia("myfilm SuperMan");
    mymultimedia->PrintMedia("Film");


#endif


#if IS_TCPSERVER
    TCPServer* mytcpserver=new TCPServer(mymultimedia);

    mytcpserver->run(3333);

#endif

#if IS_SERIALISATION_OUTPUT
    //----Serialisation----------------
    string file_name="test_map.txt";
    //-------output tous les medias dans mymultimedia a un fichier--------------
    Multimedia::writeMultimedia(file_name,mymultimedia);

#elif IS_SERIALISATION_INPUT
    //-------input---------------
    string file_name="test_map.txt";
    Multimedia::readMultimedia(file_name);
#endif


    return 0;
}
