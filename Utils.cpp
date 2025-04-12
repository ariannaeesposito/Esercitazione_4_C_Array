#include "Utils.hpp" // la prima riga che si scrive nei file cpp

#include "iostream"
#include "fstream"
#include "sstream"
#include "vector"
#include <iomanip>

using namespace std;

bool Readfile( const string& inputFile, 
    size_t& n,                      
    double& S,
    double*& w,      
    double*& r) 
{
    ifstream file (inputFile);  
    if(file.fail()) {
        cout << "Errore: il file non esiste o non si può aprire." << endl;
        return false;
    }

    //inizializzo le variabili

    string linea;
    size_t rigacorrente = 0; // size_t Intero senza segno, usato per indici e taglie ( potremmo anche mettere int)
    size_t indicearray = 0;
    

    while(getline(file,linea)){
     stringstream ss;
     ss.str(linea);

     string primo;
     string secondo;
    
       if (getline(ss,primo,';') && getline(ss,secondo)){ //Questa riga legge e separa una stringa come "S;1000" in due parti: primo riceve S,secondo riceve 1000

         //getline legge fino al punto e virgola e mette cio che legge in primo
         if (rigacorrente==0){ 
            S=stod(secondo);}   //serve per convertire una stringa (std::string) in un double (d). infatti S = 1000 ( posso assegnare mille che è diventato un numero ad S)

            else if (rigacorrente==1){ 
            n=stoi(secondo);
             w = new double[n]; // inizializzo dopo aver definito n . ATTENZIONE dev'essere nell'else if
             r = new double[n];
            }
            // avri potuto saltare indice 2 mettendo continue

            

            else if ( rigacorrente>2 && indicearray<n ){  // riga corrente si ferma per il while
             w[indicearray]=(stod(primo)); // dato che è un array c-style usiamo indice per assegnare i valori
             r[indicearray]=(stod(secondo));
             indicearray ++;

            }
        }
 
        rigacorrente++;
    }
       return true;
}
     


double Rateofreturn(const size_t& n,
    const double* const& w, //è una referenza costante a un puntatore costante 
    const double* const& r)
{  // R= ∑ w(i)*r(i)

    double R = 0.0 ;

    for (int i=0; i<n ; i++){
        R+= w[i]*r[i];
    }

    return R;
}  



double Finalvalue(const size_t& n,
    const double & S,
    const double& R)
{  // V=S⋅(1+R)

        double V = S*( 1+R );

        return V;
}


string ArrayToString(const size_t& n,
    const double* const& v,
    const string& nome)  {

    ostringstream toString; //è uno stream di output su stringa (cioè puoi scriverci dentro come faresti con cout)
    toString << nome << " = [ ";   //Quando fai toString << qualcosa, stai "scrivendo" dentro una stringa che vive internamente.
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str(); //quando chiami toString.str(), estrai la stringa risultante da tutto quello che hai scritto.


}


bool ExportResult(const string& outputFile,
    const size_t& n,
    const double& S,
    const double* const& w,
    const double* const& r,
    const double& R,   
    const double& V)  {      
    
    ofstream file(outputFile); 

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << fixed << setprecision(2)<<"S = " << S  <<" , n = " << n << endl;
    file << ArrayToString(n, w, "w") << endl;  //se escono numeri a caso:  segno chiarissimo che la memoria non è stata inizializzata correttamente, cioè stai leggendo numeri a caso dalla RAM.  
    file << ArrayToString(n, r, "r") << endl;
    file<< setprecision(4) << "Rate of return of the portfolio : " << R << endl;
    file << fixed << setprecision(2)<<"V = "<< V << endl;
   
    file.close();

    return true; 
}





    




