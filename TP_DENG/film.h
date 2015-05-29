#ifndef FILM_H
#define FILM_H
//#define NB_C 10 non!

#include "vedio.h"


/**
 * @brief One type of media (inherit from Media)
 */
class Film : public Vedio
{

private:
    int nb_ch;
    int* dc = new int[nb_ch]; //declaration d'un tableau d'entier

public:

    Film();
    Film(string,unsigned int,string,unsigned int,int,int*);


    Film(const Film&);
    Film& operator=(const Film&);


    virtual void setTableDuree(int*);
    virtual void setNbCha(int);
    virtual const int* getTableDuree() const;
    virtual const int getNbCha() const;
    virtual void afficher();
    virtual void afficher(string);
    virtual void afficher(stringstream&);
    virtual void printtoclient(stringstream&);
    virtual void play(const char*) const;


    /**
     * @brief destructer, deletes the table of duration created by Film
     */
    virtual ~Film( ){
        delete [] dc;
        cout <<this->getNomObjet()<<" delete !"<< '\n';
    }


    virtual const char* getClassName() const {return "Film";}
    /**
     * @brief create a Film objet by reading from an istream
     */
    virtual void read(istream &);


};

#endif // FILM_H
