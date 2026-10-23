
#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
private:
    string nom;
    string role;

    static int nbUtilisateursConnectes;

public:
    // Constructeur : connexion
    Utilisateur(string n, string r) {
        nom = n;
        role = r;
        nbUtilisateursConnectes++;
    }

    // Destructeur : deconnexion
    ~Utilisateur() {
        nbUtilisateursConnectes--;
    }

    // Methode statique
    static int getNbUtilisateursConnectes() {
        return nbUtilisateursConnectes;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Role : " << role << endl;
    }
};

// Initialisation de l'attribut statique
int Utilisateur::nbUtilisateursConnectes = 0;

int main() {
    cout << "Nombre d'utilisateurs connectes : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u1("Amine", "admin");

    cout << "\nApres connexion de Amine : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    Utilisateur u2("Sara", "visiteur");

    cout << "Apres connexion de Sara : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    {
        Utilisateur u3("Youssef", "visiteur");

        cout << "Apres connexion de Youssef : "
             << Utilisateur::getNbUtilisateursConnectes() << endl;

        // u3 sera deconnecte a la fin de ce bloc
    }

    cout << "\nApres deconnexion de Youssef : "
         << Utilisateur::getNbUtilisateursConnectes() << endl;

    return 0;
}
