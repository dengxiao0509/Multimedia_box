
#include "mediagroupe.h"

int main(){


    int nb_cha=10;
    int* my_p= new int[nb_cha];

    for(int i=0;i<nb_cha;i++)
    {
        my_p[i]=i*10;
    }

    Media* my_film= new Film("myfilm",2016,"fichierfilm",120,nb_cha,my_p);
    Media* my_vedio=new Vedio("myvedio",20141210,"fichervedio",10);
    Media* my_photo=new Photo("myphoto",20141220,"ficherphoto","Paris");

    MediaGroupe* my_groupe=new MediaGroupe("mylist");




#if CONTIENT_HERIRAT_LIST  //include a list

    // il faut utiliser retour de valeur par reference pour changer la liste
    my_groupe->addList(my_film);
    my_groupe->addList(my_vedio);
    my_groupe->addList(my_photo);

    my_groupe->afficher();

    //il faut detruire les objets dans le groupe
    for(list<Media*>::const_iterator m=my_groupe->getList().begin();m!=my_groupe->getList().end();++m)
        delete *m;

    //il faut detruire le groupe
    delete my_groupe;


#else             //inhirat a list
    my_groupe->push_back(my_film);
    my_groupe->push_back(my_vedio);
    my_groupe->push_back(my_photo);

    my_groupe->afficher();

    //il faut detruire les objets dans le groupe
    for(list<Media*>::iterator m=my_groupe->begin();m!=my_groupe->end();++m)
        delete *m;

    //il faut detruire le groupe
    delete my_groupe;

#endif
    return 0;
}
