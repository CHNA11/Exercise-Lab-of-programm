#include <iostream>

using namespace std;

class Libro
{
    //attributi privati
private:
    string titolo;
    string autore;
    int annoPubblicazione;
    bool disponibile;
    static int numeroLibri;

public:
//costruzione per parametri
    Libro(string titol, string author, int anno) : titolo(titol), autore(author), annoPubblicazione(anno)
    {
        disponibile = 1;
        numeroLibri++;
        cout << "Libro costruito con successo" << endl;
    }
    //costruzione per duplicazione
    Libro(const Libro &altro) : titolo(altro.titolo), autore(altro.autore), annoPubblicazione(altro.annoPubblicazione), disponibile(1)
    {
        numeroLibri++;
        cout << "Libro copiato con successo" << endl;
    }
    //distruzione
    ~Libro(){
            numeroLibri--;
    }
    //funzione di prestito
    bool prestito(){
        if(disponibile==true){
            disponibile=false;
            return true;
        }
        else{
            return false;
        }
    }
    //funzione di restituzione
    bool restituzione(){
        if(disponibile==false){
            disponibile=true;
            return true;
        }
        else{
            return false;
        }
    }
    //funzioni getter
    string getTitolo() const{
        return titolo;
    }
    string getautore() const{
        return autore;
    }
    int getAnnoPubblicazione() const{
        return annoPubblicazione;
    }
    bool isDisponibile() const{
        return disponibile;
    }
    static int getNumeroTotaleLibri(){
        return numeroLibri;
    }
    //funzione di stampa
    void stampaInfo(){
        cout << "Il libro " << titolo << " dell'autore " << autore << " pubblicato nell'anno " << annoPubblicazione;
        if(disponibile==true){
            cout << " ed è disponibile per adesso" << endl;
        }
        else{
            cout << " ed è stato prestato, non disponibile per adesso" << endl;
        }
        return;
    }
};

//inizializzare attributo statico
int Libro::numeroLibri=0;

int main(){
    //Costruire qualche libro
    Libro l1("Carla","Alberto",2004);
    Libro l2("Anna","Maria",2005);
    Libro l3(l1);
    //fare qualche operazione 
    l1.prestito();
    l2.prestito();
    l3.prestito();
    l2.restituzione();
    //stampare libri presenti
    cout << "Ci sono " << l1.getNumeroTotaleLibri() << " libri" << endl; 
    //creare nuovi libri
    Libro l4(l2);
    Libro l5(l3);
    //stampa libri presenti
    cout << "Ci sono " << l1.getNumeroTotaleLibri() << " libri" << endl; 
}
