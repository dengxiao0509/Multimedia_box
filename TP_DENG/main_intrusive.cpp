
#include "mediagroupe.h"
/*
 *
 * pour tester l'utilisation de intrusive_ptr
 *
 *
 */
int main(){

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


    intrusive_ptr<Media> my_film_Tantanic= new Film("myfilm_Tantanic",2016,"fichierfilm_Tantanic",200,nb_cha1,my_p1);
    intrusive_ptr<Media> my_film_SuperMan= new Film("myfilm_SuperMan",2016,"fichierfilm_SuperMan",220,nb_cha2,my_p2);


    intrusive_ptr<Media> my_vedio=new Vedio("myvedio",20141210,"fichervedio",10);

    intrusive_ptr<Media> my_photo_Paris=new Photo("myphoto_Paris",20141220,"ficherphoto_Paris","Paris");
    intrusive_ptr<Media> my_photo_Chongqing=new Photo("myphoto_Chongqing",20140721,"ficherphoto_Chongqing","Chongqing");


    intrusive_ptr<MediaGroupe> my_groupe1=new MediaGroupe("mylist1");
    intrusive_ptr<MediaGroupe> my_groupe2=new MediaGroupe("mylist2");


    my_groupe1->push_back(my_film_Tantanic);
    my_groupe1->push_back(my_vedio);
    my_groupe1->afficher();


    my_groupe2->push_back(my_film_SuperMan);
    my_groupe2->push_back(my_vedio);
    my_groupe2->push_back(my_photo_Chongqing);
    my_groupe2->push_back(my_photo_Paris);
    my_groupe2->afficher();

    cout<<"Enlever \"myvedio\" du \"myliste1\""<<endl;
    my_groupe1->remove(my_vedio);
    my_groupe1->afficher();
    my_groupe2->afficher();



    return 0;
}
