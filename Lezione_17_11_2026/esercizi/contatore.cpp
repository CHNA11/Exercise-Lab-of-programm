#include <iostream>

//inclusione standard
using namespace std;

//definizione di classe contatore
    class Contatore
{
private:

// attributi di tipo privato
    int valore;

public:

// Costruttore

Contatore(int numero) : valore(numero) //initializer list
{
    //costruttore con valore inziale
    cout << "Contatore creato con valore " << valore << endl;
}
Contatore() : valore(0)
//costruttore con valore iniziale 0 per default
{
    cout << "Contatore creato con valore " << valore << endl;
}
// metodi pubblici
//funzione che incrementa valore di uno
 int incremente(){
    valore++;
    return valore;
 }
 //funzione che decrementa valore di uno
 int decrementa(){
    valore--;
    return valore;
 }
 //funzione che risetta valore in 0
 int reset(){
    valore=0;
    return valore;
 }
 //funzione che ritorna valore con tipo const
 int getValore() const {
    return valore;
 }
 //funzione che stampa valore di contatore
 void stampaValore() const {
    cout << "il valore corrente è : " << valore << endl;
    return;
 }
};

int main(){
    //costruisce 2 classi
    Contatore c1;
    Contatore c2(10);
    //incrementa primo di uno, deve essere 1 adesso
    c1.incremente();
    //decremente secondo di uno, deve essere 9
    c2.decrementa();
    //stampa valore di uno
    c1.stampaValore();
    //decrementa secondo di uno, deve essere 8
    c2.decrementa();
    //stampa valore di secondo
    c2.stampaValore();
    //settare valore di secondo a zero
    c2.reset();
    //stampa valore che deve essere 0
    c2.stampaValore();
    return 0;
}