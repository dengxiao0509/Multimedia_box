#ifndef VEDIO_H
#define VEDIO_H


#include "media.h"  //important

/**
 * @brief One type of media (inherit from Media)
 */
class Vedio : public Media {

private:
    unsigned int duree;

public:

    Vedio();
    Vedio(string,unsigned int,string,unsigned int);
    Vedio(const Vedio&);
    Vedio& operator=(const Vedio&);



    /**
     * @brief get the time of duration of vedio
     */
    virtual unsigned getDuree() const;
    /**
     * @brief set the time of duration of vedio
     * @param _d
     */
    virtual void setDuree(unsigned int _d){this->duree=_d;}

    //void afficher() const; on ne peut pas mettre const ici
    virtual void afficher() ;
    virtual void afficher(string);
    virtual void afficher(stringstream&);
    virtual void printtoclient(stringstream&);
    virtual void play(const char*) const;

    virtual ~Vedio(){
        cout <<"Vedio delete !"<< '\n';
    }
    virtual const char* getClassName() const {return "Vedio";}
    /**
     * @brief create a Vedio objet by reading from an istream
     */
    virtual void read(istream&);
};

#endif // VEDIO_H
