#include "multimedia.h"


Multimedia::Multimedia()
{}
/**
 * @brief Constructer, initialize a map[command,fonction*] used by client/server
 * @param mul : name of multimedia
 */
Multimedia::Multimedia(string mul){
    Nommultimedia=mul;
// map pour les commands viennent du serveur et les methodes correspondantes
    mycmdmap["searchmedia"]=&Multimedia::SearchMedia;
    mycmdmap["searchgroup"]=&Multimedia::SearchMediaGroupe;
    mycmdmap["showall"]=&Multimedia::PrintMediatoclient;
    mycmdmap["play"]=&Multimedia::PlayMediatoclient;
}
/**
 * @brief Create and add a Photo objet to datebase
 * @param s_o_Photo : name of Photo
 * @param date_Photo : date of Photo
 * @param s_f_Photo : file of Photo
 * @param lieu_Photo : place of Photo
 * @return a Photo objet
 */
intrusive_ptr<Photo> Multimedia::CreatePhoto(string s_o_Photo, unsigned int date_Photo, string s_f_Photo,string lieu_Photo){
    intrusive_ptr<Photo> myphoto=new Photo(s_o_Photo,date_Photo,s_f_Photo,lieu_Photo);

    mymediamap[s_o_Photo]=myphoto;
    cout<<"creat successfully "<<s_o_Photo<<endl;
    return myphoto;
}
/**
 * @brief Create and add a Vedio objet to datebase
 * @param s_o_Vedio : name of Vedio
 * @param date_Vedio : date of Vedio
 * @param s_f_Vedio : file of Vedio
 * @param duree_Vedio : duration of Vedio
 * @return a Vedio objet
 */
intrusive_ptr<Vedio> Multimedia::CreateVedio(string s_o_Vedio, unsigned int date_Vedio, string s_f_Vedio,unsigned int duree_Vedio){
    intrusive_ptr<Vedio> myvedio=new Vedio(s_o_Vedio,date_Vedio,s_f_Vedio,duree_Vedio);

    mymediamap[s_o_Vedio]=myvedio;
    cout<<"create successfully "<<s_o_Vedio<<endl;
    return myvedio;
}
/**
 * @brief Create and add a Fillm objet to datebase
 * @param x : name of Film
 * @param y : date of Film
 * @param s : place of Film
 * @param d : date of Film
 * @param nb_cha : number of chapiters
 * @param du_ch : table of duration of every chapiter
 * @return
 */
intrusive_ptr<Film> Multimedia::CreateFilm(string x, unsigned int y, string s, unsigned int d,int nb_cha,int* du_ch){
    intrusive_ptr<Film> myfilm=new Film(x,y,s,d,nb_cha,du_ch);

    mymediamap[x]=myfilm;
    cout<<"creat successfully "<<x<<endl;
    return myfilm;
}
/**
 * @brief Create and add media group to database
 * @param s : name of media group
 * @return a MediaGroupe objet
 */
intrusive_ptr<MediaGroupe> Multimedia::CreateMediaGroupe(string s){

    intrusive_ptr<MediaGroupe> mymediagroupe=new MediaGroupe(s);

    mymediagroupemap[s]=mymediagroupe;
    cout<<"create successfully "<<s<<endl;
    return mymediagroupe;
}

/**
 * @brief Remove a media from database
 * @param s : name of media to be removed
 */
void Multimedia::RemoveMedia(string s){

    if(mymediamap.count(s)==0){
        cerr<<"< "<<s<<" >"<<"  not found,no remove!"<<endl;
    }
    else{
        int i=mymediamap.erase(s);
        if(i==1) cout<<"-------------"<<endl<<s<<" deleted successfully."<<endl;


        MediaGroupeMap::iterator it;
        //travers a map to find a mediagroupe
        for(it=mymediagroupemap.begin();it!=mymediagroupemap.end();++it){
            intrusive_ptr<MediaGroupe> groupe=(*it).second;
            intrusive_ptr<Media> media;
            //travers a mediagroupe(list) to find a media
            for(intrusive_ptr<Media> med: (*groupe)){
                if(med->getNomObjet()==s){
                    media=med;
                    break;
                }

            }

            if(media!=NULL){
                //cout<<groupe->size()<<endl;
                groupe->remove(media);
                //cout<<groupe->size()<<endl;
                cout<<s<<" removed from "<<groupe->getNom()<<endl<<"-------------"<<endl;
                break;

            }

        }
    }
}

/**
 * @brief Remove a Media Groupe from database
 * @param s : name of media group to be removed
 */
void Multimedia::RemoveMediaGroupe(string s){
    if(mymediagroupemap.count(s)==0){
        cerr<<s<<" not found,no remove!"<<endl;
    }
    else{
        mymediagroupemap.erase(s);
        cout<<s<<" deleted successfully."<<endl;
    }}
/**
 * @brief Search a Media from database and print it in the console
 * @param s : name of media to be found
 */
void Multimedia::SearchMedia(string s){
    if (mymediamap.count(s)==0){
        cerr<<"< "<<s<<" >"<<" not found! "<<endl;
    }
    else{
        cout<<s<<" found: "<<'\n'<<endl;
        mymediamap[s]->afficher();
    }
}
/**
 * @brief Search a Media Group from database and print it in the console
 * @param s : name of media group to be found
 */
void Multimedia::SearchMediaGroupe(string s){
    if (mymediagroupemap.count(s)==0){
        cerr<<"< "<<s<<" >"<<" not found! "<<endl;
    }
    else{
        cout<<s<<" found: "<<endl;
        mymediagroupemap[s]->afficher();
    }
}

/**
 * @brief Search a Media from database, and output it to a stringstream
 * @param s : name of media to be found
 */
void Multimedia::SearchMedia(string& s,stringstream& _ss){
    if (mymediamap.count(s)==0){
        cerr<<"< "<<s<<" >"<<" not found! "<<endl;
        _ss<<"Media <"<<s<<"> not found,try again!";
    }
    else{
        //  cout<<s<<" found: "<<endl;
        mymediamap[s]->printtoclient(_ss);
    }
}
/**
 * @brief Search a Media Group from database, and output it to a stringstream
 * @param s : name of media group to be found
 */
void Multimedia::SearchMediaGroupe(string& s,stringstream& _ss){
    if (mymediagroupemap.count(s)==0){
        cerr<<" < "<<s<<" > "<<" not found! "<<endl;
        _ss<<"Group <"<<s<<">"<<" not found,try again! ";
    }
    else{
        //cout<<s<<" found: "<<endl;
        mymediagroupemap[s]->afficher(_ss);
    }
}
/**
 * @brief Play a Media
 * @param s : name of media group to be played
 */
void Multimedia::PlayMedia(string& s){
    if(mymediamap.count(s)==0){
        cerr<<"< "<<s<<" >"<<" not found,no playing!"<<endl;
    }
    else{
        mymediamap[s]->play("media.xxx &");
    }
}
/**
 * @brief used to play a media in the side of client
 * @param s : name of media group to be played
 * @param ss : stringstream used to pass playing information to client
 */
void Multimedia::PlayMediatoclient(string& s,stringstream& ss){
    if(mymediamap.count(s)==0){
        ss<<"< "<<s<<" >"<<" not found,no playing!";
    }
    else{
        ss<<s<<" playing in server... ";
        mymediamap[s]->play("media.xxx &");
    }
}
/**
 * @brief Destructer
 */
Multimedia::~Multimedia() {

    // cout<<Nommultimedia<<" delete!"<<endl;
}


/**
 * @brief write all the medias in a multimedia to file
 * @param _filename :  name of output file
 * @param obj : objet of Multimedia to output
 */
void Multimedia::writeMultimedia(string& _filename,intrusive_ptr<Multimedia> obj){

    MediaMap testmap=obj->getMediamap();
    MediaMap::iterator itmap;
    ofstream ofs;
    stringstream ss;
    ofs.open(_filename);
    if(ofs.is_open()){
        for(itmap=testmap.begin();itmap!=testmap.end();++itmap){
            itmap->second->afficher(ss);

            /*
   * //-------write all the classes in the map to a file by calling write-to-file fonction of every class-----
    for(itmap=testmap.begin();itmap!=testmap.end();++itmap){
             Media::writeMedia(_filename,itmap->second);
  */
        }
        ofs<<ss.rdbuf();
        ofs.close();
    }
    else cerr<<"open file error!"<<endl;
}

/**
 * @brief create a media objet whose type is passed by argument
 * @param _classname : type of class
 * @return
 */
intrusive_ptr<Media> Multimedia::createMedia(string& _classname){
    if(_classname=="Photo"){
        intrusive_ptr<Photo> pho=new Photo();
        return pho;
    }
    else if(_classname=="Vedio"){
        intrusive_ptr<Vedio> ved=new Vedio();
        return ved;
    }
    else if(_classname=="Film"){
        intrusive_ptr<Film> fil=new Film();
        return fil;
    }

    else cerr<<"Media type not exist!"<<endl;
    return NULL;
}
/**
 * @brief create a media objet by reading from an istream and initialize all the attributes
 * @param ist : input istream
 * @return a media objet
 */
intrusive_ptr<Media> Multimedia::readMedia(istream& ist){
    string classname_;
    ist>>classname_;skipnl(ist);
    intrusive_ptr<Media> media_obj=Multimedia::createMedia(classname_);
    if(media_obj!=NULL) media_obj->read(ist);
    return media_obj;
}
/**
 * @brief create several medias by reading from a file and print them to console
 * @param file_name : name of input file
 */
void Multimedia::readMultimedia(string & file_name){
    ifstream ifs_;
    ifs_.open(file_name);

    if(ifs_.is_open()){
        intrusive_ptr<Media> media_;
       cout<<"*******************Les objets lits depuis un fichier sont******************"<<endl;
        cout<<"*****************************BEGIN*******************************"<<endl;
        while (ifs_.good()) {
            //if reach the end of file
            if (ifs_.peek()==EOF){cout<<"***************************END****************************"<<endl;break;}

            media_ = Multimedia::readMedia(ifs_);

            if(media_!=NULL)  media_->afficher();
            else              cout<<"No Media created!"<<endl;

        }
        ifs_.close();
    }

    else cerr<<"open file error!"<<endl;
}

/**
 * @brief print a list in detail of one type of medias(Photo,Film,Vedio...)
 * @param s : type of media to be listed
 */
void Multimedia::PrintMedia(string s){
    MediaMap::iterator it;
    string temp;
    cout<<"List of "<<s<<" :"<<endl;
    for(it=mymediamap.begin();it!=mymediamap.end();++it){
        temp=(*it).second->getClassName();
        if(temp.compare(s)==0)
            (*it).second->afficher();
    }
}
/**
 * @brief print a list of medias(only the name) of one type to client
 * @param s : type of media to be listed
 * @param ss :: stringstream to output
 */
void Multimedia::PrintMediatoclient(string& s,stringstream& ss){
    MediaMap::iterator it;
    string temp;
    if(s.compare("Photo")==0|| s.compare("Film")==0||s.compare("Vedio")==0){

        for(it=mymediamap.begin();it!=mymediamap.end();++it){
            temp=(*it).second->getClassName();
            if(temp.compare(s)==0)
               // (*it).second->printtoclient(ss);
                ss<<(*it).second->getNomObjet()<<" ";
        }
    }
    else ss<<"Media type not exist! Try <Photo>,<Vedio>,<Film>";
}
/**
 * @brief used to find the methode to call correspontant with the command of client
 * @param sf : command
 * @param sm : first parameter of methode to be called
 * @param ss : second parameter of methode to be called
 */
void Multimedia::Call(string& sf,string& sm,stringstream& ss){
    MFN fp=mycmdmap[sf];
    if (fp==NULL)
        ss<<"Command doesn't have fonction correspondant,please try <searchmedia>,<searchgroup>,<showall>,<play>";
    else (this->*fp)(sm,ss);
}
