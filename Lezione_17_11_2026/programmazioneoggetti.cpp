# include <iostream>

int main(){
    /*
    In c non è permesso programmazione oggetto
    In c++ si, ricordiamo definizione di strutture in c, componente ha tipi diversi, ma struttura e funzioni sono separati
    Un oggetto è formato, suddiviso in 2 parti :
    la parte iniziale ha dati, non più struct
    Sotto comportamenti/metodi/funzioni.
    Esempio: macchina ha targa, marcha, modello, potenza ecc....
    Può accendersi, accellerare, frenare, cambiare proprietario...
    Esemoui studente 
    funzioni sono stampare voti, fare un esame ecc.
    dati possono essere a piacere
    Tutte le funzioni sono dentro oggetto, altri non interessa.
    Utilizzatore non interessa logica interno, importante è che funziona
    Eredarietà, meglio la composizione.
    Sia un azienda con dipendenti, può essere un impiegato, un dirigente, un operaio
    Quelli comune le definisco sopra, mentre quelli specifiche le metto dentro ogni parte.
    Composizione : per un oggetto motore, un oggetto macchina, tra le variabile della macchina c'ha motore, ma ognuno fa prioprio lavoro.
    Diagramma di classi: argomento.
    Polinorfismo : stesso nome, comportamenti diversi :
    sommare numeri con la virgola, interi o complessi..
    Teoria è diverso dal pratica.
    Eredarietà è possibile ma non per forza, non usare forzando.

    Classe è la parte principale di po, come la macchinaç:
    Con dati e comportamenti....
    Tutto cià che è dati e funzioni, vengono messi dentro, dati detti proprietà, funzioni detti metodi.
    classe non esiste in memoria, diventa un oggetto solo quando istanziamo un oggetto.
    Per un oggetto macchina, può essere di classe macchina, che è unico.
    Può essere infiniti oggetti di classe macchina.
    Ogni classe ha una file a parte, funziona anche messo insieme.
    Per prassi, classe si chiama sempre con lettera maiuscola prima.
    
    Modificatori accesso:
    Chi può modificare che cosa...
    Attributi di tipo pubblic, rende accessibile a tutti con valori senza senso.
    Esiste private e pubblic
    Variabili in generale non deve essere pubblici
    Metodi maggior parte pubblici
    Prottetti, accessibili da derivate e di classe
    privati accessibile solo per chi dentro classe
    Getter e Setter serve per metodi di attributi

    Costruttore
    Funziona ugualmente per programmazione oggetti, è il metodo che permette di costruire un oggetto
    Esiste costrutture default, almeno uno deve essere, ha stesso nome del classe, non ha tipo di ritorno.
    Possiamo anche non dichiarare, dichiare uno o più , come overloading si distingue per parametri.

    Cerca sempre di dare nomi uguali per parametri.

    Posso anche ridefinire costruttori di default

    Initializer list è quasi obbligatoria

    Distruttore : funzione che distrugge quelli compiuto il lavoro.
    Non sempre bisogna implementare.
    Deve essere definito solo se : memoria con new, file , socket.....
    Può essere utile se bisogna tracciare istruzione
    ~ "Nome del costruttore"

    Puntatore this:
    this->nome attributo, fa riferimento al variabile dichiarato, non parametro passato

    Metodi const
    const non modifica mai metodi

    Metodi static

    in condivisione con tutti i oggetti definiti di quella classe
    */
   return 0;
}