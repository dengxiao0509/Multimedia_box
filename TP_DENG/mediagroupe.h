#ifndef MEDIAGROUPE_H
#define MEDIAGROUPE_H

#include <list>
#include "film.h"
#include "photo.h"



#if CONTIENT_HERIRAT_LIST
//-------------------créer une classe qui contient une list d'objets---------------
class MediaGroupe
{
private:
    string nom_gr;
    list<Media*> mylist;

public:
    MediaGroupe() ;

    MediaGroupe(string);

    virtual ~MediaGroupe(){};

    virtual string getNom() const;

    virtual const list<Media*>& getList() const;
    virtual void addList(Media*);
    virtual void afficher();

};


#else
//----------------------créer une classe qui hérite d'une list d'objets----------------

#if INTRUSIVE_POINTER_USE
//list<intrusive_ptr< > >
/**
 * @brief The MediaGroupe class contents some different types of media
 */
class MediaGroupe : public list<intrusive_ptr<Media>>, public Pointable
{
private:
    string nom_gr;

public:

    MediaGroupe();
    MediaGroupe(string);
    /**
     * @brief Destructer
     */
    virtual ~MediaGroupe(){
       // cout<<this->getNom()<<" delete!"<<endl;
       // cout<<"-------------------"<<endl;
    }
    /**
     * @brief get name of this mediagroupe
     * @return
     */
    virtual string getNom() const;

    virtual void afficher();
    virtual void afficher(stringstream&);


};

#elif SHARED_POINTER_USE
class MediaGroupe : public list<std::tr1::shared_ptr<Media>>
{
private:
    string nom_gr;

public:
    MediaGroupe();

    MediaGroupe(string);

    virtual ~MediaGroupe(){
        cout<<this->getNom()<<" delete!"<<endl;
    }

    virtual string getNom() const;

    virtual void afficher();

};



#else
class MediaGroupe : public list<Media*>
{
private:
    string nom_gr;


public:
    MediaGroupe();

    MediaGroupe(string);

    virtual ~MediaGroupe(){
        cout<<this->getNom()<<" delete!"<<endl;
    }

    virtual string getNom() const;

    virtual void afficher();

};



#endif


#endif

#endif // MEDIAGROUPE_H
