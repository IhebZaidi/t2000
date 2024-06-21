#include "plateforme.h"

plateforme::plateforme()
{
    //ctor
}

plateforme::~plateforme()
{
    //dtor
}



vector<duo*>::iterator plateforme::rechercherDuo(string cin) {
    vector<duo*>::iterator it;
    for(it = abonnements.begin(); it != abonnements.end(); ++it) {
        if((*it)->Getcin() == cin) {
            return it;
        }
    }
    return abonnements.end();
}

void plateforme::ajouter(const duo& d) {
    if(rechercherDuo(d.Getcin()) == abonnements.end()) {
        duo* p = new duo(d);
        abonnements.push_back(p);
    } else {
        cout << "Le duo existe d�j�" << endl;
    }
}

void plateforme::ajouter(const familials& f) {
    if(rechercherDuo(f.Getcin()) == abonnements.end()) {
        duo* p = new familials(f);
        abonnements.push_back(p);
    } else {
        cout << "Le duo familial existe d�j�" << endl;
    }
}


void plateforme::mettreAJourPrix() {
    vector<duo*>::iterator it;
    for(it = abonnements.begin(); it != abonnements.end(); ++it) {
        duo* d = *it;
        if(typeid(*d) == typeid(familials)) {
            familials* f = dynamic_cast<familials*>(d);
            cout << "Prix de l'abonnement familial pour " << f->Getcin() << " : " << f->Getprix() << " dinars" << endl;
        } else {
            cout << "Prix de l'abonnement duo pour " << d->Getcin() << " : " << d->Getprix() << " dinars" << endl;
        }
    }
}


void plateforme::ajouterEnfant(string cin, const enfant& e) {
    if(e.getAge() < 13) {
        throw invalid_argument("L'�ge de l'enfant doit �tre d'au moins 13 ans.");
    }

    vector<duo*>::iterator it;
    for(it = abonnements.begin(); it != abonnements.end(); ++it) {
        if((*it)->Getcin() == cin && typeid(**it) == typeid(familials)) {
            familials* f = static_cast<familials*>(*it); // Casting normal
            f->ajouterEnfant(e);
            cout << "Enfant ajout� � l'abonnement familial avec CIN " << cin << "." << endl;
            return;
        }
    }

    cout << "Aucun abonnement familial trouv� avec le CIN " << cin << "." << endl;
}

void plateforme::supprimer(const string& cin) {
    vector<duo*>::iterator it;
    for(it = abonnements.begin(); it != abonnements.end(); ++it) {
        if(**it == cin) {
            delete *it;
            abonnements.erase(it);
            cout << "Abonnement avec CIN " << cin << " supprim�." << endl;
            return;
        }
    }
    cout << "Aucun abonnement trouv� avec le CIN " << cin << "." << endl;
}



void plateforme::enregistrerCINsFamillesNombreuses(const string& filename) {
    ofstream file(filename);
    if(!file) {
        cerr << "Erreur lors de l'ouverture du fichier " << filename << "." << endl;
        return;
    }

    vector<duo*>::iterator it;
    for(it = abonnements.begin(); it != abonnements.end(); ++it) {
        if(typeid(**it) == typeid(familials)) {
            familials* f = static_cast<familials*>(*it);
            if(f->enfants.size() > 4) {
                file << f->Getcin() << endl;
            }
        }
    }

    file.close();
    cout << "CINs enregistr�s dans le fichier " << filename << "." << endl;
}
