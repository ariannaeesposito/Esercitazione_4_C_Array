#pragma once

#include <iostream>

using namespace std;

bool Readfile(  const string& inputFile,
                size_t& n,
                double& S,
                double*& w,
                double*& r);



double Rateofreturn(const size_t& n,
                        const double* const& w,
                        const double* const& r);   
                        
                        

double Finalvalue(const size_t& n,
                        const double & S,
                        const double& Rateofreturn); 

                        

bool ExportResult(const string& outputFile,
                  const size_t& n,
                  const double& S,
                  const double* const& w,
                  const double* const& r,
                  const double& Rateofreturn,   // nel cpp li definisco R e V che si ottengono con questi metodi 
                  const double& Finalvalue);   

                  
string ArrayToString(const size_t& n,
                    const double* const& v,
                    const string& nome);