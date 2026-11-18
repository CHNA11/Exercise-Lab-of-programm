#include <iostream>

//inclusione standard
using namespace std;

// funzione richiesto che trova massimo
int massimo(int *numeri, int n);

int main()
{
    //inizializzare numero di dimensione da allocare
    int n=0;
    do{
        //chiedere in input
    cout << "Inserisci dimensione di allocazione : ";
    cin >> n;
    } while(n<1); //finche sia maggiore di 0
    int *numeri = new int[n]; //allocazione dinamica
    for (int i = 0; i < n; i++)
    { //riempi chiedendo da input
        cout << "Inserisci numero nella posizione " << i + 1 << " : ";
        cin >> numeri[i];
    }
    //stampa il massimo richiamando funzione
    cout << "Il massimo dei valori che hai inserito è : " << massimo(numeri, n) << endl;
    delete numeri; //liberare memoria
}

int massimo(int *numeri, int n)
{
    int max = numeri[0]; //inizializzare massimo
    for (int i = 1; i < n; i++)
    {
        if (numeri[i] > max) //confrontare con numeri presenti
        {
            max = numeri[i]; //se è maggiore di massimo cambia
        }
    }
    return max;
}