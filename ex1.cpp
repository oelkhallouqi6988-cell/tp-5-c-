
#include <iostream>
using namespace std;

class Boite {
private:
    float longueur;
    float largeur;
    float hauteur;

    static int nbBoites;

public:
    // Constructeur
    Boite(float l, float la, float h) {
        longueur = l;
        largeur = la;
        hauteur = h;
        nbBoites++;
    }

    // Destructeur
    ~Boite() {
        nbBoites--;
    }

    // Methode statique
    static int getNombreBoites() {
        return nbBoites;
    }
};

// Initialisation de l'attribut statique
int Boite::nbBoites = 0;

int main() {
    Boite b1(10, 5, 3);
    Boite b2(8, 4, 2);
    Boite b3(6, 3, 2);

    cout << "Nombre de boites : "
         << Boite::getNombreBoites() << endl;

    return 0;
}
