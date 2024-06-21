#ifndef PLATEFORME_H
#define PLATEFORME_H
#include "duo.h"

class plateforme
{
    public:
        plateforme();
        virtual ~plateforme();
        vector<duo*>::iterator rechercherDuo(string cin);
        void ajouter(const duo& d);
        void ajouter(const familials& f);
        void mettreAJourPrix();
        void ajouterEnfant(string cin, const enfant& e);
        void ajouterEnfant(string cin, const enfant& e);
        void enregistrerCINsFamillesNombreuses(const string& filename);

    protected:
        string nom;
        vector<duo*>abonnements;

    private:
};

#endif // PLATEFORME_H
