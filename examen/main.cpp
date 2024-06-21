#include <iostream>


#include <iostream>
#include <vector>
#include "duo.h"
#include "familials.h"
#include "plateforme.h"


using namespace std;

int main() {
    plateforme p;
    duo d1;
    d1.Setcin("12345678");
    d1.Setforfait(50);

    familials f1;
    f1.Setcin("87654321");
    f1.Setforfait(75);

    familials f2;
    f2.Setcin("13579111");
    f2.Setforfait(100);

    p.ajouter(d1);
    p.ajouter(f1);
    p.ajouter(f2);

    enfant e1("enfant1", 15);
    enfant e2("enfant12", 14);
    enfant e3("enfant13", 16);
    enfant e4("enfant14", 17);
    enfant e5("enfan", 18);

    try {
        p.ajouterEnfant("87654321", e1);
        p.ajouterEnfant("87654321", e2);
        p.ajouterEnfant("87654321", e3);
        p.ajouterEnfant("87654321", e4);
        p.ajouterEnfant("87654321", e5);
    } catch (const invalid_argument& e) {
       cout <<" " << endl;
    }

    p.mettreAJourPrix();
    p.supprimer("12345678");
    p.enregistrerCINsFamillesNombreuses("cins_familles_nombreuses.txt");

    return 0;
}
