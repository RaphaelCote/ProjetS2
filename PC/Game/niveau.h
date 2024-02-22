#ifndef NIVEAU_H
#define NIVEAU_H

class Niveau
{
private:
    int nbraft;
public:
    Niveau();
    Niveau(int);
    ~Niveau();
    int hight=1080;
    int wight=3000;

    int backimge[1];
    void creerListeRfat();

};

#endif