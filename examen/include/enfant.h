#ifndef ENFANT_H
#define ENFANT_H
#include <string>
#include <iostream>
#include <fstream>
class enfant
{
    public:
        enfant();
        virtual ~enfant();

        int Getage() { return age; }
        void Setage(int val) { age = val; }
        int Getidentifiant() { return identifiant; }
        void Setidentifiant(int val) { identifiant = val; }

    protected:
        int age;
        int identifiant;

    private:
};

#endif // ENFANT_H
