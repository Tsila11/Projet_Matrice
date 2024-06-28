#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include <vector>
#include <stdexcept>
using namespace std;
class Matrice
{
private:
    vector<vector<int>> data;
    int rows;
    int cols;
public:
    Matrice(int r,int c);//constructeur pour cette classe
    vector<int> & operator[] (int index);//otranizao ampesaina bibliotheque <vector>
    Matrice operator+ (const Matrice & ) const;//surcharge operateur d'addition
    Matrice operator- (const Matrice &) const;
    Matrice operator* (int scalaire) const;
    Matrice operator* (const Matrice & ) const;
    void afficheMatrice() const;//methode pour afficher cette classe Matrice
    bool operator== (const Matrice &)const;// methode pour faire la comparaison
    bool operator!= (const Matrice &)const;
};

#endif // MATRICE_H_INCLUDED
