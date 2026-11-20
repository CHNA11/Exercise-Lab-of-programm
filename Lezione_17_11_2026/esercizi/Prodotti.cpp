#include <iostream>

using namespace std;

class Prodotto
{
private:
//attributi privati
    string codice;
    string nome;
    string descrizione;
    double prezzo;
    int quantitaDisponibile;
    int sogliaMinima;
    static int numeroVendite;

public:
// costruttore completo
    Prodotto(string code, string name, string description, double cost, int quantiti, int sogliamin) : codice(code), nome(name), descrizione(description)
    {
        while (cost <= 0)
        {
            cout << "Inserisci un costo positivo : ";
            cin >> cost;
        }
        while (quantiti <= 0)
        {
            cout << "Inserisci un costo positivo : ";
            cin >> quantiti;
        }
        while (sogliamin <= 0)
        {
            cout << "Inserisci un costo positivo : ";
            cin >> sogliamin;
        }
        prezzo = cost;
        quantitaDisponibile = quantiti;
        sogliaMinima = sogliamin;
        cout << "Prodotto costruito correttamente" << endl;
    }
    //costruttore abbreviato
    Prodotto(string code, string name, double cost) : codice(code), nome(name), descrizione("NULL")
    {
        while (cost <= 0)
        {
            cout << "Inserisci un costo positivo : ";
            cin >> cost;
        }
        prezzo = cost;
        quantitaDisponibile = 1;
        sogliaMinima = 0;
        cout << "Prodotto costruito correttamente" << endl;
    }
    // distruttore
    ~Prodotto()
    {
        cout << "Prodotto distrutto" << endl;
    }
    // funzioni setter
    int setCodice(string code)
    {
        codice = code;
        return 1;
    }
    int setNome(string name)
    {
        nome = name;
        return 1;
    }
    int setDescrizione(string description)
    {
        descrizione = description;
        return 1;
    }
    int setPrezzo(double cost)
    {
        if (cost <= 0)
        {
            return 0;
        }
        prezzo = cost;
        return 1;
    }
    int setQuantita(int quantiti)
    {
        if (quantiti <= 0)
        {
            return 0;
        }
        quantitaDisponibile = quantiti;
        return 1;
    }
    int setSoglia(int sogliamin)
    {
        if (sogliamin <= 0)
        {
            return 0;
        }
        sogliaMinima = sogliamin;
        return 1;
    }
    // funzioni getter
    string getCodice() const
    {
        return codice;
    }
    string getNome() const
    {
        return nome;
    }
    string getDescrizione() const
    {
        return descrizione;
    }
    double getPrezzo() const
    {
        return prezzo;
    }
    int getquantita() const
    {
        return quantitaDisponibile;
    }
    int getsoglia() const
    {
        return sogliaMinima;
    }
    //funzioni di operazioni
    bool vendi(int quantita)
    {
        if (quantitaDisponibile >= quantita)
        {
            quantitaDisponibile = quantitaDisponibile - quantita;
            numeroVendite = numeroVendite + quantita;
            return true;
        }
        else
        {
            return false;
        }
    }
    int rifornisci(int quantita)
    {
        while (quantita <= 0)
        {
            cout << "Inserisci un numero positivo : " << endl;
            cin >> quantita;
        }
        quantitaDisponibile = quantitaDisponibile + quantita;
        return 1;
    }
    //funzioni di operazioni
    bool necessitaRiordino() const
    {
        if (quantitaDisponibile <= sogliaMinima)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    float calcolaValoreMagazzino() const
    {
        return (float)prezzo * quantitaDisponibile;
    }
    int applicaSconto(double percentuale)
    {
        while (percentuale < 0 || percentuale > 100)
        {
            cout << "Inserisci un percentuale valido tra 0 e 100 : ";
            cin >> percentuale;
        }
        prezzo = prezzo * (100-percentuale) / 100;
        return 1;
    }
    static int getNumeroVenditeTotali()
    {
        return numeroVendite;
    }
    //funzioni di stampa
    void stampaDettaglio() const
    {
        cout << "il prodotto " << nome << " con codice " << codice << " con le descrizioni : " << endl;
        cout << descrizione << endl;
        cout << " ha prezzo " << prezzo << " con quantita " << quantitaDisponibile << " ad soglia minima " << sogliaMinima;
        if (necessitaRiordino() == true)
        {
            cout << " e serve riordine" << endl;
        }
        else
        {
            cout << " non serve riordine" << endl;
        }
        return;
    }
    void stamRiepilogo() const
    {
        cout << "il prodotto " << nome << "con codice " << codice << " ha prezzo " << prezzo << " con quantita " << quantitaDisponibile << endl;
    }
};

//inizializzazione static
int Prodotto::numeroVendite = 0;

int main()
{
    //costruire qualche prodotto
    Prodotto mela("1234", "Mela", 1);
    Prodotto pera("1123", "pera", 2);
    Prodotto banana("1000", "banana", 3);
    Prodotto fragola("1923", "fragole", 4);
    //effettuare qualche operazione
    mela.rifornisci(10);
    if (pera.vendi(1) == false)
    {
        cout << "Errore vendita impossibile" << endl;
    };
    fragola.rifornisci(18);
    banana.rifornisci(20);
    if (fragola.vendi(19) == false)
    {
        cout << "Errore vendita impossibile" << endl;
    };
    fragola.applicaSconto(50);
    //verificare quali servono riordine
    if (mela.necessitaRiordino() == true)
    {
        cout << "mela serve riordinare" << endl;
    }
    if (pera.necessitaRiordino() == true)
    {
        cout << "pera serve riordinare" << endl;
    }
    if (banana.necessitaRiordino() == true)
    {
        cout << "banana serve riordinare" << endl;
    }
    if (fragola.necessitaRiordino() == true)
    {
        cout << "fragola serve riordinare" << endl;
    }
    //calcolare valore totale del magazzino
    float tot = mela.calcolaValoreMagazzino() + pera.calcolaValoreMagazzino() + banana.calcolaValoreMagazzino() + fragola.calcolaValoreMagazzino();
    cout << "Valore totale del magazzino è : " << tot << endl;
    //visualizzare numero totale di vendite effettuate
    cout << "Ci sono in tutto " << mela.getNumeroVenditeTotali() << " vendite effettuate" << endl;
    return 0;
}