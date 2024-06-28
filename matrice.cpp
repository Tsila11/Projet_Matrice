#include "matrice.h"
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

Matrice::Matrice(int r,int c):rows(r),cols(c)
{
data.resize(rows,vector<int>(cols,0));
}
  vector<int>& Matrice::operator[] (int index)
{
    return data[index];

}
Matrice Matrice:: operator+ (const Matrice &p) const
{
    if(rows!= p.rows || cols != p.cols){
        throw invalid_argument("Les dimensions des matrices ne correspondent pas pour l'addition");
    }
        Matrice result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] =data[i][j] + p.data[i][j];
            }
        }
        return result;
}
Matrice Matrice:: operator- (const Matrice &m) const
{
    if(rows!= m.rows || cols != m.cols){
        throw invalid_argument("Les dimensions des matrices ne correspondent pas pour la soustraction");
    }
        Matrice result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] =data[i][j] - m.data[i][j];
            }
        }
        return result;
}
Matrice Matrice::operator* (int scalaire) const
{
        Matrice result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                result.data[i][j] =data[i][j] * scalaire;
            }
        }
        return result;
}
Matrice Matrice:: operator* (const Matrice &a) const
{
    if(cols!= a.rows ){
        throw invalid_argument("Les dimensions des matrices ne correspondent pas pour la multiplication");
    }
        Matrice result(rows,cols);
        for(int i=0;i<rows;++i){
            for(int j=0;j<a.cols;++j){
                for(int k=0;k<cols;++k){
                result.data[i][j] +=data[i][k] * a.data[k][j];
            }
        }
    }
        return result;
}
void Matrice::afficheMatrice() const
{
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            cout<<data[i][j]<<" ";
        }
            cout<<endl;
    }
}
bool Matrice::operator== (const Matrice &o)const{
if(rows!=o.rows || cols!=o.cols){
    return false;
}
    for(int i=0;i<rows;++i){
        for(int j=0;j<cols;++j){
            if(data[i][j] !=o.data[i][j]){

            }
        }
    }
    return true;
}
bool Matrice::operator!=(const Matrice &o)const
{
    return !(*this==o);
}
