#ifndef MEDIA_H
#define MEDIA_H

#define CONTIENT_HERIRAT_LIST 0  //1 pour contient une liste,et 0 pour herite
#define INTRUSIVE_POINTER_USE 1  // 1 pour use,0 pour non
#define SHARED_POINTER_USE 0  //1 pour use,et il faut mettre INTRUSIVE_POINTER_USE a 0
#define IS_WRITESIMPLE 1  //pour tester serialisation 1


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "intrusive_ptr.h"
#include <tr1/memory>

using namespace std;


//for debugging
//#define SMART_PTR_DEBUG
//#define SMART_PTR_DEBUG_MESSAGES

#if INTRUSIVE_POINTER_USE

/**
 * @brief used to delete a '\n' in a istream
 * @param f
 */

inline void skipnl (istream& f) {
    f.ignore(numeric_limits<streamsize>::max(),'\n');
}



/**
 * @brief The Media class is the base class of other types of medias.
 */

class Media : public Pointable
{
private:

    string objet;
    unsigned int date;
    string ficher;


public:

    Media();
    Media(string,unsigned int,string);

    Media(const Media&);
    Media& operator=(const Media&);

    /*------------------accesseurs--------------------*/

    virtual string getNomObjet() const;
    virtual unsigned int getDate() const;
    virtual string getNomFicher() const;

    virtual void setNomObjet(string);
    virtual void setDate(unsigned int);
    virtual void setNomFicher(string);

    /*-----different fonctions used to output attributes of objet---------*/

    virtual void afficher();
    virtual void afficher(stringstream&);
    virtual void afficher(string);

    virtual void printtoclient(stringstream&);

    virtual void play(const char*) const;

    /**
     * @brief This is the destructer
     */
    virtual ~Media(){
         cout <<"Media delete !"<< '\n';
        // cout<<"----------------------"<<endl;
    }

    /*------fonctions used for serialisation----*/
    /**
     * @brief get the name of Class
     * @return  name of class(string)
     */
    virtual const char* getClassName() const {return "Media";}
    static void writeMedia(string&,intrusive_ptr<Media>);
    virtual void read(istream&);
};

#else

class Media
{
private:

    string objet;
    unsigned int date;
    string ficher;
public:

    Media();
    Media(string,unsigned int,string);

    Media(const Media&);
    Media& operator=(const Media&);

    /*------------------accesseurs--------------------*/

    virtual string getNomObjet() const;
    virtual unsigned int getDate() const;
    virtual string getNomFicher() const;


    virtual void setNomObjet(string);
    virtual void setDate(unsigned int);
    virtual void setNomFicher(string);




    /*-----different fonctions used to output attributes of objet---------*/

    virtual void afficher();
    virtual void afficher(stringstream&);
    virtual void afficher(string);
    virtual void printtoclient(stringstream&);


    virtual void play(const char*) const;
    virtual ~Media(){
         cout <<"Media delete !"<< '\n';
         cout<<"----------------------"<<endl;
    }


    /*------fonctions used for serialisation----*/

    virtual const char* getClassName() const {return "Media";}
    static void writeMedia(string&,intrusive_ptr<Media>);
    virtual void read(istream&);


};
#endif

#endif // MEDIA_H
