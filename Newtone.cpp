//
//  Newtone.cpp
//  pm_lab_01
//
//  Created by Alexander Fomenko on 24/10/2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#include "Newtone.hpp"
#include <iostream>

using namespace std;

Newtone::Newtone(float eps)
{
    this->eps = eps;
}

Roots Newtone::iterSystems(Roots nextRoots, bool flag)
{
    Roots roots;
    
    if (flag)
    {
        roots.x = 0.8f - cos(nextRoots.y + 0.5f);
        roots.y = -0.5f * (1.6f - sin(nextRoots.x));
    }
    else
    {
        roots.x = sin(nextRoots.x + nextRoots.y) / 1.4f;
        //change the - to + to get positive solution in iterative method 
        roots.y = -sqrt(1 - powf(nextRoots.x, 2.f));
    }
    
    return roots;
}

Roots Newtone::iterMethod(Roots approximateRoots, bool flag)
{
    Roots roots = approximateRoots;
    float eps_x = 1.f;
    float eps_y = 1.f;
    
    int i = 0;
    
    while (true)
    {
        Roots tmpRoots = iterSystems(roots, flag);
        eps_x = abs(tmpRoots.x - roots.x);
        eps_y = abs(tmpRoots.y - roots.y);
        
        roots = tmpRoots;
        i++;
        
        if (i > 999 || (eps_x < eps && eps_y < eps))
        {
            break;
        }
        
    }
    
    cout << "\nIterations: " << i << endl;
    
    return roots;
}

Roots Newtone::sourceSystems(Roots nextRoot, bool flag)
{
    Roots roots;
    
    if (flag)
    {
        roots.x = cos(nextRoot.y + 0.5f) + nextRoot.x - 0.8f;
        roots.y = sin(nextRoot.x) - 2 * nextRoot.y - 1.6f;
    }
    else
    {
        roots.x = sin(nextRoot.x + nextRoot.y) - 1.4f * nextRoot.x;
        roots.y = powf(nextRoot.x, 2.f) + powf(nextRoot.y, 2.f) - 1.f;
    }
    
    return roots;
}

Roots* Newtone::derivatives(Roots nextRoot, bool flag)
{
    Roots *dRoots = new Roots[2];
    
    if (flag)
    {
        dRoots[0].x = 1.f;
        dRoots[0].y = -sin(nextRoot.y + 0.5f);
        
        dRoots[1].x = cos(nextRoot.x);
        dRoots[1].y = -2.f;
    }
    else
    {
        dRoots[0].x = cos(nextRoot.x + nextRoot.y) - 1.4f;
        dRoots[0].y = cos(nextRoot.x + nextRoot.y);
        
        dRoots[1].x = 2.f * nextRoot.x;
        dRoots[1].y = 2.f * nextRoot.y;
    }
    
    return dRoots;
}

Roots Newtone::newtonMethod(Roots approximateRoots, bool flag)
{
    Roots roots = approximateRoots;
    float eps_x = 1.f;
    float eps_y = 1.f;
    int i = 0;
    
    while (true)
    {
        Roots tmpRoots;
        Roots *dRoots = derivatives(roots, flag);
        float jacobian = dRoots[0].x * dRoots[1].y - dRoots[1].x * dRoots[0].y;
        Roots source = sourceSystems(roots, flag);
        
        float h = -(1 / jacobian) * (source.x * dRoots[1].y - source.y * dRoots[0].y);
        float k = -(1 / jacobian) * (dRoots[0].x * source.y - dRoots[1].x * source.x);
        tmpRoots.x = roots.x + h;
        tmpRoots.y = roots.y + k;
        
        eps_x = abs(tmpRoots.x - roots.x);
        eps_y = abs(tmpRoots.y - roots.y);
        
        roots = tmpRoots;
        i++;
        
        if (i > 999 || (eps_x < eps && eps_y < eps))
        {
            break;
        }
        
    }
    cout << "\nIterations: " << i << endl;
    
    return roots;
}
