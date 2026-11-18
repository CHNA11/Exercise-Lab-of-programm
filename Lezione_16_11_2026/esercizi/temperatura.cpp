# include <iostream> // in c++ si usa questo invece di stdio

//inclusione della libreria standard
using namespace std;

//Funzione che converte Celsius in Fahrenheit
double toFahrenheit(double c);

int main(){
    //stampa richiesta di inserimento
    cout << "Inserisci valore di temperatura in Celsius : ";
    double temperaturaC; //dichairare variabile di appoggio
    cin >> temperaturaC; //legge da tastiera
    double temperaturaF=toFahrenheit(temperaturaC); //converte in Fahrenheit
    cout << "La temperatura " << temperaturaC <<" in Celsius corrisponde a " << temperaturaF <<" in Fahrenheit" << endl;
    return 0;
}

double toFahrenheit(double c){
    return (c*1.8)+32; //formula di trasformazione
}