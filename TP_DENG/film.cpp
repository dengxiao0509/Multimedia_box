#include "film.h"


Film::Film():Vedio(){nb_ch=0;dc=NULL;}

Film::Film(string x, unsigned int y, string s, unsigned int d,int nb_cha,int* du_ch) :
    Vedio(x,y,s,d) {
    nb_ch=nb_cha;
    dc=du_ch;

}


Film::Film(const Film& from):Vedio(from){

    //if(this == &from)  //meme objet ne rien faire
    nb_ch=from.getNbCha();
    const int* dc_from=from.getTableDuree();

    if(dc_from !=NULL)
    {
        dc=new int[nb_ch];
        for(unsigned int i=0;i<sizeof(dc_from);i++)
        {
            dc[i]=dc_from[i];

        }

    }
    else dc=NULL;

}


Film& Film::operator=(const Film& from){

    Vedio::operator =(from);

    nb_ch=from.getNbCha();
    const int* dc_from=from.getTableDuree();

    // if(from.dc != NULL)  //from.dc est pas accede
    if(dc_from !=NULL)
    {
        dc=new int[nb_ch];

        //memcpy(this->dc,from->dc,sizeof(from->dc));  pas de fonction pour copier un tableau
        for(unsigned int i=0;i<sizeof(dc_from);i++)
        {

            dc[i]=dc_from[i];
        }

    }
    else dc=NULL;
    return *this;

}

void Film::setNbCha(int c){
    this->nb_ch=c;

}

void Film::setTableDuree(int* p){
    if(sizeof(p)<=0){
        cerr<< "The size of duree table shouldn't be vide or negative! "<<endl;
    }
    this->dc=p;
}

const int Film::getNbCha() const{
    return this->nb_ch;
}

const int* Film::getTableDuree() const{
    return this->dc;
}
void Film::afficher(){

    Vedio::afficher();
    cout<<"Le nombre de chapitre est: "<<nb_ch<<endl
          <<"Les durees de chaque chaptre sont: "<<endl;
    for(int i=0;i<nb_ch;i++){
        cout << this->dc[i] << '\t';
        if(i==nb_ch-1) cout<<endl;
    }

}

void Film::afficher(stringstream& ss){
    Vedio::afficher(ss);
#if IS_WRITESIMPLE
    ss<<nb_ch<<endl;
#else
    ss << "Le nombre de chapitre est: "<<nb_ch<<endl
        << "Les durees de chaque chaptre sont: "<<endl;
#endif
    for(int i=0;i<nb_ch;i++){
        ss << this->dc[i] << '\t';
        if(i==nb_ch-1){ss<<endl;}
    }

}

void Film::printtoclient(stringstream& ss){
    Vedio::printtoclient(ss);
    ss<<nb_ch<<" ";
    for(int i=0;i<nb_ch;i++){
        ss << this->dc[i];
        if(i<nb_ch-1) ss<< " ";

    }

}


void Film::afficher(string s){
    Vedio::afficher(s);
    ofstream afficherfile;
    afficherfile.open(s,ofstream::out|ofstream::app);
    if(afficherfile.is_open()){
#if IS_WRITESIMPLE
        afficherfile<<nb_ch<<endl;
#else
        afficherfile<<"Le nombre de chaptre est: "<<nb_ch<<endl;
        afficherfile << "Les durees de chaque chaptre sont: "<<endl;
#endif
        for(int i=0;i<nb_ch;i++){
            afficherfile << this->dc[i] << '\t';
        }

        afficherfile.close();
    }
    else
        cout<<"Open file error!"<<endl;
}


void Film::play(const char* cmd) const{
     cout<<"Now we play this film by using system(cmd)..."<<endl;
    //system(cmd);
}

void Film::read(istream & ist){
    Vedio::read(ist);
    string nb_chap,temp;

    getline(ist,nb_chap);
    nb_ch=atoi(nb_chap.c_str());

    int* dc_ = new int[nb_ch];
    for(int i=0;i<nb_ch;i++){

        ist>>dc_[i];
    }
    //skipnl(ist);
 this->setTableDuree(dc_);
}




