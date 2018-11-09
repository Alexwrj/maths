//
//  main.cpp
//  pm_lab_01
//
//  Created by Alexander Fomenko on 06.10.2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#include <iostream>
#include "NumMethods.hpp"
#include "Newtone.hpp"

int main()
{
    //Numerical methods for derivative equations
    
    /*vector<double>aVec;
    vector<double>eVec;
    vector<double>r2Vec;
    vector<double>r4Vec;
    NumMethods *obj = new NumMethods();
    aVec = obj->getVector(analyticVector);
    eVec = obj->getVector(eilerVector);
    r2Vec = obj->getVector(runge_2Vector);
    r4Vec = obj->getVector(runge_4Vector);
    
    obj->showVector(aVec, "analyticOutput");
    obj->showVector(eVec, "EilerOutput");
    obj->showVector(r2Vec, "Runge2Output");
    obj->showVector(r4Vec, "Runge4Output");
    
    cout << "\nDiscrepancy for Eiler: " << obj->discrepancy(aVec, eVec);
    cout << "\nDiscrepancy for Runge 2: " << obj->discrepancy(aVec, r2Vec);
    cout << "\nDiscrepancy for Runge 4: " << obj->discrepancy(aVec, r4Vec) << endl;
    
    delete obj;*/
    //-----------------------------------
    //iteration mathod and Newtone method
    const float e = 0.0001f;
    //set starter values
    Roots roots(-0.7f, -0.7f);
    
    Newtone *obj = new Newtone(e);
    
    //uncomment to use iteration method, !but comment strings 50 and 51; true=1-st system, false=2-nd system
    //roots = obj->iterMethod(roots, false);
    //cout << "Iter result:\n" << '(' << roots.x << ", " << roots.y << ')' << endl;
    
    roots = obj->newtonMethod(roots, false);
    cout << "Newtone result:\n" << '(' << roots.x << ", " << roots.y << ')' << endl;
    
    return 0;
}
