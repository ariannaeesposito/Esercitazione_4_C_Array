#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;


int main()
{
    double S;
    size_t n;
    double *w= nullptr; // con nullptr il programma esplode e non prosegue con un valore errato
    double *r= nullptr;


    if(!Readfile("../data.txt",n,S,w,r))
    return 1;

    double R = Rateofreturn(n,w,r);
    double V = Finalvalue(n,S,R); 


    //SE HO UNA FUNZ CHE RSTITUISCE BOOLEANI METTERE IF
     if (!ExportResult("result.txt", n, S, w, r, R, V)) {
        cerr << "Errore: impossibile scrivere result.txt" << endl;

        delete[] w;
        delete[] r;

       //per garantire che la memoria venga liberata: sia in caso di errore nella scrittura del file, sia in caso di successo

        return 1;
    }

    
    // DEVO STAMPARLI QUA CHE SONO STATI APPENA IMPORTATI ( Se fallisce la scrittura su file (return false), non ha senso proseguire, meglio uscire subito. Anche perche potrei confondermi stampando prima i dati ( che magari non sono finiti nel file).)
    // Aggiungi una stampa di debug nel main() (per test visivo)
    

    cout << fixed << setprecision(2)<<"S = " << S  <<" , n = " << n << endl;
    cout << ArrayToString(n, w, "w") << endl;  //se escono numeri a caso:  segno chiarissimo che la memoria non è stata inizializzata correttamente, cioè stai leggendo numeri a caso dalla RAM.  
    cout << ArrayToString(n, r, "r") << endl;
    cout << setprecision(4) << "Rate of return of the portfolio : " << R << endl;
    cout << fixed << setprecision(2)<<"V = "<< V << endl;

    //libero la memoria
    delete[] w;
    delete[] r;



    return 0;
}

