#include "mediagroupe.h"

/**
 * @brief Constructer by default
 */
MediaGroupe::MediaGroupe()
{
    list();
    nom_gr="Null";
}
/**
 * @brief Constructer with arguments
 * @param name of group
 */
MediaGroupe::MediaGroupe(string n_g){
    list();
    nom_gr=n_g;
}

string MediaGroupe::getNom() const{
    return nom_gr;
}




#if CONTIENT_HERIRAT_LIST
//ici,on utilise valeur de retour par reference,sinon on ne peut
//pas delete les objets dans la liste par "for"
const list<Media*>& MediaGroupe::getList() const{
    return mylist;
}

#endif


#if  INTRUSIVE_POINTER_USE

/**
 * @brief print all the media dans this group to the console
 */
void MediaGroupe::afficher(){

    cout<<"************************"<<"Nom de la liste :"<<nom_gr<<'\n';

    for(list<intrusive_ptr<Media>>::iterator it=this->begin();it !=this->end();++it)
    {
        //cout<<"-------------Afficher un type de Media------------- :"<<'\n';
        (*it)->afficher();
    }

    //    cout<<"afficher done"<<endl;

}
/**
 * @brief print a list of media in this group to a stringstream
 * @param the stringstream output to
 */
void MediaGroupe::afficher(stringstream& ss){

   // ss<<"Nom de la liste :"<<nom_gr<<"; ******* Contenu: ";


    for(list<intrusive_ptr<Media>>::iterator it=this->begin();it !=this->end();++it)
    {
         //(*it)->printtoclient(ss);
         ss<< (*it)->getNomObjet()<<" ";
    }

}


#elif SHARED_POINTER_USE

void MediaGroupe::afficher(){

    cout<<"Nom de la liste :"<<nom_gr<<'\n';

    for(list<std::tr1::shared_ptr<Media>>::iterator it=this->begin();it !=this->end();++it)
    {
        cout<<"-------------Afficher un type de Media------------- :"<<'\n';
        (*it)->afficher();
    }

    //    cout<<"afficher done"<<endl;

}




#else

void MediaGroupe::afficher(){

    cout<<"Nom de la liste :"<<nom_gr<<'\n';

    for(list<Media*>::iterator it=this->begin();it !=this->end();++it)
    {
        cout<<"-------------Afficher un type de Media------------- :"<<'\n';
        (*it)->afficher();
    }
    //    cout<<"afficher done"<<endl;

}
#endif
