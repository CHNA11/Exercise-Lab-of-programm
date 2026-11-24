# include "Dipendenti.h" //inclusione classe definite 
# include <iostream> // inclusione generale

using namespace std;

int main(){
    //costruire qualche dipendente in modo casuale
    Dipendente d1("Renhao","Chen",130368,1000);
    DipendenteFullTime d2("Carlo","Alberto",1919810,800,400);
    DipendentePartTime d3("Mario","Rossi",14159265,180,10);
    Manager d4("Mask","X",114514,3000,1000,4000,1);
    //stampare lo stipendio totale
    cout <<"Gli stipendti totali dell'azienda è " << d1.calcolaStipendio()+d2.calcolaStipendio()+d3.calcolaStipendio()+d4.calcolaStipendio() << endl;
}