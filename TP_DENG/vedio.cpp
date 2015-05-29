#include "vedio.h"

//contructeur

Vedio::Vedio():Media() {duree=0;}

Vedio::Vedio(string s_o_Vedio, unsigned int date_Vedio, string s_f_Vedio,
             unsigned int duree_Vedio) :
    Media(s_o_Vedio,date_Vedio,s_f_Vedio)
{
    duree=duree_Vedio;
}
Vedio::Vedio(const Vedio & from):Media(from){
    duree=from.duree;

}
Vedio& Vedio::operator=(const Vedio& from){
    Media::operator =(from);   //pas heritage
    duree=from.duree;
    return *this;
}

//

unsigned Vedio::getDuree() const {
    return duree;
}

void Vedio::afficher() {

    Media::afficher();  //pas super!!!
    cout  << "La duree est: "<< duree<<endl;
}


void Vedio::afficher(stringstream& ss){
    Media::afficher(ss);
#if IS_WRITESIMPLE
    ss  << this->getDuree()<<endl;
#else
    ss  << "La duree est: "<< this->getDuree()<<endl;
#endif
}

void Vedio::printtoclient(stringstream& ss){
    Media::printtoclient(ss);
    ss<< this->getDuree()<<" ";
}

void Vedio::afficher(string s){

    Media::afficher(s);
    ofstream afficherfile;
    afficherfile.open(s,ofstream::out|ofstream::app);
    if(afficherfile.is_open()){
#if IS_WRITESIMPLE
        afficherfile << this->getDuree()<<endl;
#else
        afficherfile << "La duree est: "<< this->getDuree()<<endl;
#endif
        afficherfile.close();
    }
    else{
        cout<<"Open file error!"<<endl;
    }
}



void Vedio::play(const char *cmd)const{
     cout<<"Now we play this vedio by using system(cmd)..."<<endl;
    //system(cmd);
}

void Vedio::read(istream& ist){
    Media::read(ist);
    string _duree;
    getline(ist,_duree);
    this->setDuree(atoi(_duree.c_str()));
}
