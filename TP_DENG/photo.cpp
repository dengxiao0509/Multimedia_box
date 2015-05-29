#include "photo.h"

Photo::Photo(){}

Photo::Photo(string s_o_Photo, unsigned int date_Photo, string s_f_Photo,
             string lieu_Photo) :
    Media(s_o_Photo,date_Photo,s_f_Photo)
{
    lieu=lieu_Photo;
}


string Photo::getLieu() const {
    return lieu;
}

void Photo::afficher(){

    Media::afficher();
    cout<<"Le lieu est: "<< lieu << endl<<"------------------"<<endl;;
}



//output the description of photo to a file (file_name=s)
void Photo::afficher(string s){

    Media::afficher(s);
    ofstream afficherfile;
    afficherfile.open(s,ofstream::out| ofstream::app);
    if(afficherfile.is_open()){
#if IS_WRITESIMPLE
        afficherfile <<this->getLieu() <<endl;
#else

        afficherfile <<"Le lieu est: "<< this->getLieu() <<endl;
#endif
        afficherfile.close();
    }
    else
        cout<<"Open file error!"<<endl;

}

//output the description of photo to a stringstream
void Photo::afficher(stringstream& ss){

    Media::afficher(ss);
#if IS_WRITESIMPLE
    ss  << this->getLieu() << endl;
#else
    ss  <<"Le lieu est: "<< this->getLieu() << endl;
#endif
}

void Photo::printtoclient(stringstream& ss){
    Media::printtoclient(ss);
    ss  <<this->getLieu();
}

void Photo::play(const char *cmd) const{
     cout<<"Now we play this photo by using system(cmd)..."<<endl;
    //system(cmd);

}
void Photo::read(istream& ist){
    Media::read(ist);
    string _lieu;
    getline(ist,_lieu);
    this->setLieu(_lieu);
}
