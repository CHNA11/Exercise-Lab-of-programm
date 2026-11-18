# include <iostream>

//inclusione funzione standard
using namespace std;
//dichiara funzione prototipo richiesto
double divide(double a, double b);

int main(){
    // inizializzare validità del input
    int flag=0;
    do{
        try{
            //dichairare variabile di inpu
            double a;
            double b;
            //chiedere inserimento
            cout << "Inserisci il numeratore : ";
            cin >> a;
            cout << "Inserisci il denominatore : ";
            cin >> b;
            //prova a fare divisione e stampare risultato
            cout << "Il risultato della divisione è : " << divide(a,b) << endl;
            // se non ci sono errori usce dal ciclo
            flag=1;
        }
        catch(const std::invalid_argument& e){
            //avvisare errore se presenta divisione per zero
            cout << "Catturato errore di divisione per zero" << endl;
            flag=0;
        }
    }while(flag==0);
    return 0;
}

double divide(double a, double b){
    if(b==0){ //verificare se denominatore ha 0
        throw std::invalid_argument("divisione per zero"); //resituire errore
    }
    return a/b;
}