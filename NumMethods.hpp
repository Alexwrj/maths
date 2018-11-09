//
//  NumMethods.hpp
//  pm_lab_01
//
//  Created by Alexander Fomenko on 07.10.2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#ifndef NumMethods_hpp
#define NumMethods_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

enum VType
{
    analyticVector,
    eilerVector,
    runge_2Vector,
    runge_4Vector
};

class NumMethods
{
private:
    double solFunction(double t);
    double Equation(double t, double y);
    
    int n;
    double h;
    double y0;
public:
    NumMethods();
    NumMethods(int n, double h, double y0);
    ~NumMethods();
    
    vector<double>getVector(VType type);
    double discrepancy(vector<double>vec1, vector<double>vec2);
    void showVector(vector<double> vec, string name);
};

#endif /* NumMethods_hpp */
