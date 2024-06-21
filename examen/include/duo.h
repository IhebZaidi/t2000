#ifndef DUO_H
#define DUO_H
#include <string>
#include <iostream>
#include <fstream>


class duo
{
    public:
        duo();
        virtual ~duo();

        string Getcin() { return cin; }
        void Setcin(string val) { cin = val; }
        string Getcinconjoint() { return cinconjoint; }
        void Setcinconjoint(string val) { cinconjoint = val; }
        int Getfloat() { return float; }
        void Setfloat(int val) { float = val; }
        int Getforfait() { return forfait; }
        void Setforfait(int val) { forfait = val; }
        bool operator=(const string& cin2) const;

    protected:
        string cin;
        string cinconjoint;
        int float;
        int forfait;

    private:
};

#endif // DUO_H
