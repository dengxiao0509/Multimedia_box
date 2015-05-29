#include "film.h"
#include "photo.h"

int main(){

    int nb_cha=10;
    int* my_p= new int[nb_cha];


    for(int i=0;i<nb_cha;i++)
    {
        my_p[i]=i*10;
    }
    cout<<endl;

    /*
    *
    * ---test accesseurs---pas tres interessant------------
    *
    *
    Media* m=new Vedio("myvedio",20141210,"fichervedio",10);
    //------seulement les methodes communs marchent, si non on dois ajouter (Vedio*)------
    unsigned int my_duree=((Vedio*)m)->getDuree();
    cout<<"------Afficher m --------------"<<endl;
    m->afficher();

    cout<< "-----------------------"<<endl
     <<"Apres,on va changer les noms des objet,fichers associes et la date en utilisant les accesseurs"
        <<endl;
    m->setNomObjet("Novelmedia");
    m->setDate(20141211);
    m->setNomFicher("Novelficher");
    cout<<"------Afficher m --------------"<<endl;
    m->afficher();

    Media* m2=new Photo("myphoto",20141220,"ficherphoto","Paris");
    //-------seulement les methodes communs marchent, si non on dois ajouter (Vedio*)
    string my_lieu=((Photo*)m2)->getLieu();
    cout<<"lieu de myphoto : "<<my_lieu<<endl;

*/


    /*---testing copy fonction-----*/

    Film *f= new Film("myfilm",2016,"fichierfilm",120,nb_cha,my_p);
    cout<<"-----------Afficher f------------"<<endl;
    f->afficher();

    Film *f2=new Film(*f);
    cout<<"-----------Afficher f2------------"<<endl;
    f2->afficher();

    Film *f3=new Film();
    *f3=*f;
    cout<<"-----------Afficher f3------------"<<endl;
    f3->afficher();


    /*----testing afficher(stringstream ss),afficher les attributs par stringstream----*/
    /*stringstream ssv;
    m->afficher(ssv);
    cout<<ssv.str()<<endl;
    */

    /*----testing afficher(string s),afficher les attributs dans un ficher----*/
    //m->afficher("affichertest_Vedio.txt");



    delete m;
    m=NULL;
    delete m2;
    m2=NULL;

    delete f;
    f=NULL;

    delete f2;
    f2=NULL;

    delete f3;
    f3=NULL;


    return 0;
}
