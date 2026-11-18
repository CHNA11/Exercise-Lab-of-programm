# include <iostream>

//inclusione libreria standard
using namespace std;

//funzioen che incrementa dando riferimento
void incrementa(int& numero);
//funzione che incrementa di n il valore puntato
void incrementa(int* numero, int n);


int main(){
    //chiede un numero iniziale
    cout << "Inserisci un numero : ";
    //dichiarare un variabile per appoggio
    int numero;
    cin >> numero;
    // definire un riferimento per distinguere
    int& riferimento=numero;
    //incrementa passando riferimento
    incrementa(riferimento);
    cout << "Dopo incremento per riferimento si ha : " << numero << endl;
    //incrementa per puntatore, per default 5
    incrementa(&numero, 5);
    cout << "Dopo incremento per puntatore con 5 si ha : " << numero << endl;
    return 0;
}

void incrementa(int& numero){
    numero++;
}

void incrementa(int* numero, int n){
    *numero=*numero+n;
}