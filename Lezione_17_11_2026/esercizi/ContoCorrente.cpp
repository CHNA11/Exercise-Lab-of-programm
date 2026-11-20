#include <iostream>

//utilizzo libreria standard
using namespace std;

//definzione classe Conto Corrente
class ContoCorrente
{
private:
//attributo in forma privato
    string intestatario;
    string numeroConto;
    double saldo;

public:
//costruttore con Initializer list
    ContoCorrente(string nome, string numero) : intestatario(nome), numeroConto(numero), saldo(0)
    {
        cout << "Conto Corrente creato con intestatario " << nome << " e numero di Conto " << numero << endl;
    }
    //funzione di deposita
    int deposita(double importo)
    {
        if (importo <= 0)
        {
            return 0;
        }
        else
        {
            saldo = saldo + importo;
            return 1;
        }
    }
    //funzione di preleva
    int preleva(double importo)
    {
        if (importo > saldo)
        {
            return -1;
        }
        else if (importo <= 0)
        {
            return 0;
        }
        else
        {
            saldo = saldo - importo;
            return 1;
        }
    }
    
    //funzioni getter
    //funzione di get intestatario
    string getIntestatario() const
    {
        return intestatario;
    }
    //funzione di get numeroConto
    string getnumeroConto() const
    {
        return numeroConto;
    }
    //funzione di get saldo
    double getSaldo() const
    {
        return saldo;
    }
    //funzione di stampa info
    void stampaInfo() const
    {
        cout << "L'intestatario " << intestatario << " con numero di conto " << numeroConto << " ha saldo" << saldo << endl;
    }
};

int main()
{
    //costruzione Conto Corrente
    ContoCorrente c1("Renhao", "12345678");
    //dichiarare variabile di appoggio
    double importo;
    //inizializzare variabile di controllo per validità di importo
    bool flag = 0;
    do
    {
        cout << "Inserisci valore di deposita : ";
        cin >> importo;
        //controlla casi di importo
        if (c1.deposita(importo) == 0)
        {
            cout << "Si chiede di inserire un valore positivo" << endl;
            flag = 0;
        }
        else
        {
            flag=1;
            cout << "deposti con successo" << endl;
            c1.stampaInfo();
        }
    } while (flag == 0);
    flag=0; //reset a 0 per preleva
    do
    {
        cout << "Inserisci valore di preleva : ";
        cin >> importo;
        int risultato=c1.preleva(importo);
        //gestisce vari casi del preleva
        if(risultato==-1){
            cout << "L'intestatario " << c1.getIntestatario() << "ha saldo " << c1.getSaldo() << ", non è sufficiente per preleva di valore " << importo << endl;
            flag=0;
        }
        else if (risultato == 0)
        {
            cout << "Si chiede di inserire un valore positivo" << endl;
            flag = 0;
        }
        else
        {
            cout << "preleva con successo" << endl;
            c1.stampaInfo();
            flag = 1;
        }
    } while (flag == 0);
    return 0;
}