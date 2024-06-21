#ifndef FAMILIALS_H
#define FAMILIALS_H
#include <string>
#include <iostream>
#include <fstream>
#include "enfant.h"
#include "duo.h"


class familials : public duo
{
    public:
        familials();
        virtual ~familials();

    protected:
vector<enfant>enfants;
    private:
};

#endif // FAMILIALS_H
