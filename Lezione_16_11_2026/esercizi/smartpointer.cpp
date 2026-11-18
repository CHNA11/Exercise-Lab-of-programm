# include <iostream>
# include <memory> //per smartpointer

using namespace std;

//dichiarare funzione per stampa
void stampa(const unique_ptr<int>& numero);

int main(){
    unique_ptr<int> numero=make_unique<int>(); //allocare dinamicamente un numero
    cout <<"Inserisci il numero : ";
    cin >> *numero; //come puntatore per cin richiede *
    stampa(numero);
    //caso senza &
}

void stampa(const unique_ptr<int>& numero){
    //stampa il valore puntato
    cout <<"Il numero inserito è : " << *numero << endl;
}