#include "duo.h"

duo::duo()
{
    //ctor
}

duo::~duo()
{
    //dtor
}


bool duo::operator=(const string& cin2) const {
    return this->cin == cin2;
}
