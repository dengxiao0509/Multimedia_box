#ifndef PHOTO_H
#define PHOTO_H
#include "media.h"

/**
 * @brief One type of media (inherit from Media)
 */
class Photo : public Media
{
private:
    string lieu;
public:
    Photo();
    Photo(string,unsigned int,string,string);

    virtual void afficher();
    virtual void afficher(string);
    virtual void afficher(stringstream&);
    virtual void printtoclient(stringstream&);
    /**
     * @brief get name of the place where tho photo was token
     * @return name of place(string)
     */
    virtual string getLieu() const;
    /**
     * @brief set name of the place where tho photo was token
     * @param _lieu
     */
    virtual void setLieu(string _lieu){this->lieu=_lieu;}

    virtual void play(const char*) const;

    virtual ~Photo(){
       cout <<this->getNomObjet()<<" delete !"<< '\n';
    }

    virtual const char* getClassName() const {return "Photo";}
    /**
     * @brief create a Photo objet by reading from an istream
     */
    virtual void read(istream&);
};

#endif // PHOTO_H
