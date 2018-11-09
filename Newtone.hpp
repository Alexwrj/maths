//
//  Newtone.hpp
//  pm_lab_01
//
//  Created by Alexander Fomenko on 24/10/2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#ifndef Newtone_hpp
#define Newtone_hpp

#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

struct Roots
{
    float x;
    float y;
    
    Roots(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    
    Roots()
    {
        this->x = 0.f;
        this->y = 0.f;
    }
    ~Roots(){}
};

class Newtone
{
private:
    float eps;
    Roots iterSystems(Roots nextRoots, bool flag);
    Roots sourceSystems(Roots nextRoots, bool flag);
    Roots *derivatives(Roots nextRoots, bool flag);
    
public:
    Newtone(float eps);
    ~Newtone(){};
    
    Roots iterMethod(Roots approximateRoots, bool flag);
    Roots newtonMethod(Roots approximateRoots, bool flag);
};

#endif /* Newtone_hpp */
