# include <stdio.h>

int main(){
    /* 
    linguaggio compatibile a c, c++ molto efficiente, estremamente utilizzato.
    Sempre per livello basso attenzione di memoria.
    File deve essere di tipo .cpp invece di .c
    compilatore serve g++ invece di gcc.
    Impostazione simile a quello del c, invece di stdio avremo stream.
    Using in space.
    In main, invece di printf, si usa cout
    Impostazione di base è sempre analoga.
    Namespace è contenitore logico, tutto ciò che nella libreria, cout è contenuto in std, per più spazi di nomi, o specificare ogni volta, o includere all'inizio.
    per funzione di una sola volta, non c'è bisogno di specificare, mentre come cout si consiglia di using o std::.
    cout ha operatore [], di inserimento.
    nel caso :: specifica al compilatore cosa c'è da fare per compilatore
    Scompare scanf, si usa cin, >< cin si ferma al primo spazio, non c'è bisogno di specificare tipo di dato.
    usa getline per input di spazi, però come prima richiede pulizia di buffer.
    stringhe richiede comunque inclusione.
    Tipologie di dati sono simili.
    Tranne : 
    auto : automaticamente tipo di dato.
    Utile, ma per debug non si capisce, lascia libertà a macchina.
    string : fa parte di libreria standard,
    bool : per default, non più inclusione.
    
    Try/catch
    Serve per gestire errori, cattura errore e riesce ad gestire evitando crash.
    Un modo di utilizzare è do{ try/catch}while 

    Riferimenti 
    In c usiamo puntatori per riferimenti, invece in c++, riferimenti deve essere perforza assegnato a qualcosa:
    dichiararo una variabile con &b=a faccio b=20, allora a=20 automaticamente(ragiona come puntatori)
    Come vantaggio è più leggibile, non si può usare aritmetica dei puntatori.
    
    Overloading di funzione
    possiamo definire stesso funzione con diversi parametri.
    Posso anche definire parametro di default.

    Allocazione dinamica:
    diverso dallo c, viene in aiuto tante funzioni, in c si usa malloc e free;
    In c++, per nuova puntatore, si fa con new e delete.
    (Sempre ricordare delete per evitare memory leak);
    esiste puntatori intelligenti, si pensa automatico il programma per liberazione

    FILE
    simile a c, fstream.

    Librerie utili:
    su dispenser.
    la più importante è vector, che serve per tutte le strutture di dati(Serve anche per progetto)

    Documentazione su c++:
    dispenser.
    */
   return;
}