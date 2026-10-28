# include <stdio.h>
int main(){
    /*
    Esistono diversi tipi di struttre di dati, a secondo della classistica, occore usare diverse tipi di strutture.
    linked list, una struttura da dati, che conette diversi nodi, consente utilizzo più efficiente della memoria per cambiamento di allocazione
    differentemente da quello di allocazione dinamica, che una volta riempito, bisogna operare per aumentare dimensione.
    invece nelle liste, basta operare sui collegamenti per aumentare e togliere elementi.
    Nodo è composto da un valore, puntatore al successivo nodo, tranne ultimo che punta nulla.
    Vantaggio: dimensione variabile, gestire elementi facile.
    Inserimento ed eliminazione efficiente a testa: per array bisogna spostare tutti gli elementi, e poi scrivere sul spazio svuotato
    per grandi dimensione è inefficiente, per nodo, basta creare un nodo, cambiare un puntatore verso di lui
    per cancellazione, basta cambiare un puntatore.
    Ogni nodo viene creato solo se serve
    Un svantaggio è che per arrivare a un elemento preciso, devo passare prima tutti i precedenti, ha un accesso sequenziale.
    un'altra è Overhead di memoria, richiede un spazio in più per puntatore.
    Creazione del nodo richiede un valore, allocazione dinamico, assegnare puntatore al prossimo nodo, e ritornare il puntatore del nodo
    ogni elemento, ritorna sempre un puntatore.
    Esiste inserimento in testa, in coda, ecc.
    in testa, basta creare nodo, facendo puntare la vecchia testa, e ritorna puntatore del nodo nuovo
    per inserire nodo in nuova lista, richie prima di creare un nodo che punta null, inserire valore, ritornerà null, e poi comincierà con null
    posso anche inserire per coda, simile, scorrere fino alla fine, e poi farlo puntare al nuovo nodo.
    oppure posso inserire dopo un valore.
    Facendo operazione sul puntatore, posso anche cancellare un valore, per cancellare la testa, bisogna inserire nuova testa, in qualsiasi caso,
    richiede free perché sono allocato dinamicamente.
    Ricordare anche diallocazione della lista.
    mancano ancora 6 lezioni.
    1 parziale sarà in cosegna circa 8 dicembre, secondo sarà circa 18 gennaio
    */
   return 0;
}