#include "media.h"

/**
 * @brief This is the constructer by default.
 */
Media::Media():objet("Null"),date(0),ficher("Null"){
}
/**
 * @brief This is the constructer with initial arguments.
 */
Media::Media(string _objet,unsigned int _date,string _ficher)
    :objet(_objet),date(_date),ficher(_ficher) {
}
/**
 * @brief This is used to copy the media class profoundly, by using a(b).
 */
Media::Media(const Media& from){
    objet=from.objet;
    date=from.date;
    ficher=from.ficher;

}
/**
 * @brief This is used to copy the media class profoundly, by using a=b.
 * @return  Media&
 */
Media& Media::operator =(const Media& from){
    objet=from.objet;
    date=from.date;
    ficher=from.ficher;
    return *this;
}

/**
 * @brief used to set name of objet
 */
void Media::setNomObjet(string o){
    objet=o;
}
/**
 * @brief used to set the file associated
 */
void Media::setDate(unsigned int d){
    date=d;
}
/**
 * @brief used to set date
 */
void Media::setNomFicher(string f){
    ficher=f;
}
/**
 * @brief used to get the name of objet
 * @return name(string)
 */
string Media::getNomObjet() const{
    return objet;
}
/**
 * @brief used to get date
 * @return date(int)
 */
unsigned Media::getDate() const{
    return date;
}
/**
 * @brief used to get name of the file associated (entire path)
 * @return filename and path(string)
 */
string Media::getNomFicher() const{
    return ficher;
}


/**
 * @brief used to print all the attributes of objet to the console
 */
void Media::afficher(){
    cout <<this->getClassName()<<endl
        << "Nom de Objet est: " << objet<<endl
        << "La date est: " <<date<<endl
        << "Nom de ficher associe est: " <<ficher<<endl;
}
/**
 * @brief used to output all the attributes of objet to stringstream
 */
void Media::afficher(stringstream& ss){
#if IS_WRITESIMPLE

    ss<<this->getClassName()<<endl
     << objet << endl
     << date << endl
     << ficher << endl;
#else
    ss << "Nom de Objet est: " << objet << endl
       << "La date est: " << date << endl
       << "Nom de ficher associe est: " << ficher << endl;
#endif
}

/**
 * @brief used to output all the attributes of objet to one file(filename as an argument)
 */
void Media::afficher(string s){
    ofstream afficherfile;
    afficherfile.open(s,ofstream::out|ofstream::app);
    if (afficherfile.is_open()){

#if IS_WRITESIMPLE
        afficherfile <<this->getClassName()<<endl
                    << objet<<endl
                    <<date<<endl
                   <<ficher<<endl;
#else
        afficherfile<<"Nom de Objet est: " << objet<<endl
                   << "La date est: " <<date<<endl
                   << "Nom de ficher associe est: " <<ficher<<endl;
#endif

        afficherfile.close();
    }
    else{
        cout<<"Open file error!"<<endl;
    }


}

/**
 * @brief used to output all the attributes of objet to the server(by message)
 */
void Media::printtoclient(stringstream& ss){
    ss<<this->getClassName()<<" "
     << objet << " "
     << date << " "
     <<ficher << " ";
}

/**
 * @brief used to play a media
 */
void Media::play(const char* cmd) const {
    cout<<"Playing"<<objet<<"Now..."<<endl;

    //system(cmd);
    cout<<"Now we play this media by using system(cmd)..."<<endl;
}

/*------serialisation----*/
/**
 * @brief write a Media class (all of its attributes) to a file,with the name of object
 */
void Media::writeMedia(string& s,intrusive_ptr<Media> obj){
    ofstream ofs;
    ofs.open(s,ofstream::out|ofstream::app);
    if (ofs.is_open()){
#if IS_WRITESIMPLE
        ofs<<obj->getClassName()<<endl;
#else
        ofs<<"-----------------------"<<endl<<"Objet:  "<<obj->getClassName()<<endl;
#endif
        ofs.close();
    }
    else{
        cout<<"Open file error!"<<endl;
    }
    obj->afficher(s);

}
/**
 * @brief create a Media class by reading from a stream (assign values to its attributes)
 */
void Media::read(istream & ist){
    string _objet,_date,_ficher;

    getline(ist,_objet);
    getline(ist,_date);
    getline(ist,_ficher);
    this->setNomObjet(_objet);
    this->setDate(atoi(_date.c_str()));
    this->setNomFicher(_ficher);

}


