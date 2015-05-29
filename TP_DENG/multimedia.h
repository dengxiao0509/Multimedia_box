#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include<iostream>
#include<map>
#include <cstdio>
#include "mediagroupe.h"

typedef map<string,intrusive_ptr<Media>> MediaMap;
typedef map<string,intrusive_ptr<MediaGroupe>> MediaGroupeMap;
/**
 * @brief The Multimedia class is used to manage these medias and media groups
 */

class Multimedia : public Pointable
{
 typedef void (Multimedia::*MFN)(string&,stringstream&); // function pointer type
 typedef map<string,MFN> CmdMap;


private:

    MediaMap mymediamap;
    MediaGroupeMap mymediagroupemap;
    string Nommultimedia;
    CmdMap mycmdmap;



public:

    Multimedia();
    Multimedia(string);
    virtual MediaMap getMediamap()const {return mymediamap;}
   // virtual CmdMap getCmdmap()const {return mycmdmap;}
    virtual intrusive_ptr<Photo> CreatePhoto(string,unsigned int, string,string);
    virtual intrusive_ptr<Vedio> CreateVedio(string,unsigned int,string,unsigned int);
    virtual intrusive_ptr<Film> CreateFilm(string,unsigned int,string,unsigned int,int,int*);
    virtual intrusive_ptr<MediaGroupe> CreateMediaGroupe(string);
    virtual void RemoveMedia(string);
    virtual void RemoveMediaGroupe(string);
    virtual void SearchMedia(string);
    virtual void SearchMediaGroupe(string);
    virtual void SearchMedia(string&,stringstream&);//string& par reference est necessaire
    virtual void SearchMediaGroupe(string&,stringstream&);
    virtual void PlayMedia(string&);
    virtual void PlayMediatoclient(string&,stringstream&);
    virtual void PrintMedia(string);
    virtual void PrintMediatoclient(string&,stringstream&);
    virtual void Call(string&,string&,stringstream&);
    virtual ~Multimedia();

    static void writeMultimedia(string&,intrusive_ptr<Multimedia>);
    static intrusive_ptr<Media> createMedia(string&);  //creat a Media class by its classname
    static intrusive_ptr<Media> readMedia(istream&);   //creat a Media class by reading from a istream
    static void readMultimedia(string&);

};

#endif // MULTIMEDIA_H
