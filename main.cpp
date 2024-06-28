#include "matrice.h"
#include <iostream>
using namespace std;
void afficheMenu()
{
    cout<<"Menu :" << endl;

    cout<<"1.Creer une matrice" << endl;
    cout<<"2.Afficher une matrice" << endl;
    cout<<"3.Additionner deux matrices" << endl;
    cout<<"4.Soustraire deux matrices" << endl;
    cout<<"5.Multiplier une matrice par un scalaire" << endl;
    cout<<"6.Multiplier deux matrices" << endl;
    cout<<"7.Comparer ces deux matrices" << endl;
    cout<<"8.Quitter "<<endl;
}
Matrice creerMatrice(){
    int ligne,colonnes;
    cout<<"Nombre de lignes :" << endl;
    cin>>ligne;
    cout<<"Nombre de colonnes :" << endl;
    cin>>colonnes;
    cout<<"------------------------------------------------"<<endl;
    Matrice mat(ligne,colonnes);
    cout<<"Entrer les valeurs  de la matrice : " << endl;
    for(int i=0;i<ligne;++i){
        for(int j=0;j<colonnes;++j){

            cin>>mat[i][j];
        }
    }
        return mat;
}
int main()
{
    Matrice matr1(0,0),matr2(0,0),result(0,0);
    int c;
    bool quitter=false;
    while(!quitter){
        afficheMenu();
        cout<<"Choix : "<< endl;
        cin>> c;
        switch(c){
                    case 1:
                        matr1 = creerMatrice();// appel anle fonction creerMatrice()
                        cout<<"On a: "<<endl;
                        matr1.afficheMatrice();//appel ane fonction afficheMatrice()
                        cout<<"--------------------------------------------------------------" << endl;
                        break;
                    case 2:
                        cout<<"Nous avons : "<<endl;
                        matr1.afficheMatrice();
                        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                        cout<<"----------------------------Puis la menu s'affichera----------------------------------" << endl;
                        break;
                    case 3:
                        cout<<"Creation de la deuxieme matrice pour l'addition :"<<endl;
                        matr2=creerMatrice();
                        try{// try..catch ilaina raha itest zavatra isika;
                            result=matr1 + matr2;
                            cout<<"Resultat de l'addition : " <<endl;
                            result.afficheMatrice();
                        }catch(const invalid_argument& e){ //otranizao ny atao rehefa tia hamoka erreur isika;
                            cerr<<"Erreur : "<<e.what() << endl;
                        }
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<" Revient au menu precedent---------------------- "<< endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                break;
                    case 4:
                            cout<<"Creation de la deuxieme matrice pour la soustraction :"<<endl;
                            matr2=creerMatrice();
                        try{
                            result=matr1 - matr2;
                            cout<<"Resultat de la soustraction : " <<endl;
                            result.afficheMatrice();
                        }catch(const invalid_argument& e){
                            cerr<<"Erreur : "<<e.what() << endl;
                        }
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<" Revient au menu precedent---------------------- "<< endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                break;
                    case 5:
                        int scalaire;
                            cout<<"Entrer la scalaire:"<<endl;
                            cin>>scalaire;
                            result=matr1 *scalaire;
                            cout<<"Resultat de la multiplication par un scalaire : " <<endl;
                            result.afficheMatrice();
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<" Revient au menu precedent---------------------- "<< endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                break;
                     case 6:
                            cout<<"Creation de la deuxieme matrice pour la multiplication :"<<endl;
                            matr2=creerMatrice();
                        try{
                            result=matr1 * matr2;
                            cout<<"Resultat de la multiplcation matricielle : " <<endl;
                            result.afficheMatrice();
                        }catch(const invalid_argument& e){
                            cerr<<"Erreur : "<<e.what() << endl;
                        }
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<" Revient au menu precedent---------------------- "<< endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                break;
                    case 7:
                            cout<<"Creation de la deuxieme matrice pour la comparaison :"<<endl;
                            matr2=creerMatrice();
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                if(matr1==matr2){
                                cout<<"matrice 1 et la matrice 2 sont egaux "<<endl;
                                    }else
                                cout<<"matrice 1 et matrice 2 sont differents "<<endl;

                            cout<<"------------------------------------------------------------------------" <<endl;
                                break;
                    case 8:
                            quitter=true;
                                break;
                    default:
                            cout<<"------>Choix invalide,veuillez reesssayez "<<endl;
                                break;
        }
    }
    return 0;
}
