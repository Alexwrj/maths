//
//  NumMethods.cpp
//  pm_lab_01
//
//  Created by Alexander Fomenko on 07.10.2018.
//  Copyright © 2018 Alexander Fomenko. All rights reserved.
//

#include "NumMethods.hpp"

NumMethods::NumMethods()
{
    n = 100;
    h = 0.1;
    y0 = 2.0;
}

NumMethods::NumMethods(int n, double h, double y0)
{
    this->n = n;
    this->h = h;
    this->y0 = y0;
}

vector<double> NumMethods::getVector(VType type)
{
    vector<double> outVector;
    
    switch (type)
    {
        case analyticVector:
            for (int i = 0; i < n; i++)
            {
                outVector.push_back(solFunction(i * h));
            }
            break;
            
        case eilerVector:
            outVector.push_back(y0);
            
            for (int i = 0; i < n; i++)
            {
                double newValue = outVector.back() + h * Equation(i * h, outVector.back());
                outVector.push_back(newValue);
            }
            break;
            
        case runge_2Vector:
            outVector.push_back(y0);
            
            for (int i = 0; i < n; i++)
            {
                double tmp = outVector.back() + (h / 2.0) * Equation(i * h, outVector.back());
                double newValue = outVector.back() + h * Equation(i * h + h / 2.0, tmp);
                outVector.push_back(newValue);
            }
            break;
        
        case runge_4Vector:
            outVector.push_back(y0);
            
            for (int i = 0; i < n; i++)
            {
                double k1 = h * Equation(i * h, outVector.back());
                double k2 = h * Equation(i * h + h / 2.0, outVector.back() + k1 / 2.0);
                double k3 = h * Equation(i * h + h / 2.0, outVector.back() + k2 / 2.0);
                double k4 = h * Equation(i * h + h, outVector.back() + k3);
                double newValue = outVector.back() + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
                outVector.push_back(newValue);
            }
            break;
        
        default:
            cerr << "Error!\n:";
    }
    
    return outVector;
}

double NumMethods::solFunction(double t)
{
    return 1.93 * exp(-3.0 * t)
    + (3.0 / 13.0) * sin(2.0 * t)
    - (2.0 / 13.0) * cos(2.0 * t)
    - (2.0 / 3.0) * t
    + (2.0 / 9.0);
}

double NumMethods::Equation(double t, double y)
{
    return -3.0 * y - 2.0 * t + sin(2.0 * t);
}

void NumMethods::showVector(vector<double> vec, string name)
{
    fstream of("/Users/alexanderfomenko/Documents/pm_lab_01/" + name + ".txt", ios_base::out);
    
    for (auto value : vec)
    {
        of << value << "\n";
    }
}

double NumMethods::discrepancy(vector<double>vec1, vector<double>vec2)
{
    vector<double>diff;
    double result = 0.f;
    
    for(int i = 0; i < vec1.size(); i++)
    {
        diff.push_back(vec1[i] - vec2[i]);
    }
    
    for(auto vec : diff)
    {
        result += vec * vec;
    }
    
    return sqrt(result);
}

NumMethods::~NumMethods(){}
