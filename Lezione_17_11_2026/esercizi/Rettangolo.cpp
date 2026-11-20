#include <iostream>
using namespace std;
class Rettangolo
{
    //attributi privati
    private:
    double base;
    double altezza;
    public:
    //costruttore default
    Rettangolo() : base(1.0), altezza(1.0){
        cout << "Rettangolo creato in modo default con base 1.0 e altezza 1.0" << endl;
    }
    //costruttore per valore
    Rettangolo(double b, double h) : base(b), altezza(h){
        if(b<=0){
            base=1.0;
            cout << "base non valido, inizializzato per default con 1.0" << endl;
        }
        if(h<=0){
            altezza=1.0;
            cout << "Altezza non valido, inizializzato per default con 1.0" << endl;
        }
        cout << "Rettangolo creato con base " << base << " e altezza " << altezza << endl;
    }   
    
    //funzioni getter

    double getBase() const {
        return base;
    }
    double getAltezza() const {
        return altezza;
    }

    //funzioni setter

    int setBase(double b){
        if(b<=0){
            return 0;
        }
        else{
            base=b;
            return 1;
        }
    }
    int setAltezza(double h){
        if(h<=0){
            return 0;
        }
        else{
            altezza=h;
            return 1;
        }
    }
    //funzione che calcola area
    double calcolaArea() const{
        return base*altezza;
    }
    //funzione che calcola perimetro
    double calcolaPerimetro() const{
        return (2*base) + (2*altezza);
    }
    //funzione che controlla se è un quadrato
    bool isQuadrato() const{
        if(base==altezza){
            return true;
        }
        else {
            return false;
        }
    }
    //funzione di stampa
    void stampaInfo() const{
        cout << "Il rettangolo ha base " << base << " e altezza " << altezza << endl;
    }
};

int main(){
    //costruire rettangolo diversi
    Rettangolo r1;
    Rettangolo r2(2,2);
    Rettangolo r3(-1,1);
    Rettangolo r4(18,-8);
    //test getter
    cout << "Il rettangolo r1 ha base " << r1.getBase() << " Mentre rettangolo r4 ha altezzo " << r4.getAltezza() << endl;
    if(r2.isQuadrato()==true){ //test isQuadrato
        r2.stampaInfo();
        cout << "r2 è un quadrato " << endl;
    }
    else{
        cout << "r2 non è un quadrato" << endl;
    }
    double h;
    do{ //test setAltezza con validità
        cout << "Settare altezza di r3 in : ";
        cin >> h;
        if(r3.setAltezza(h)==0){
            cout <<"deve essere un numero >0 " << endl;
        }
        else{
            cout << "set Altezza con successo" << endl;
            r3.stampaInfo();
        }
    } while(h<=0);
    double b;
    do{ // test setBase con validità
        cout << "Settare base di r1 : ";
        cin >> b;
        if(r1.setBase(b)==0){
            cout <<"deve essere un numero >0" << endl;
        }
        else{
            cout <<"set Base con successo" << endl;
            r1.stampaInfo();
        }
    } while(b<=0);
    //test calcola perimetro e area
    cout << "Rettangolo r1 ha Perimetro " << r1.calcolaPerimetro() << " e Area " << r1.calcolaArea() << endl;
    return 0;
}