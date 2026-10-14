# include <stdio.h>
int main(){
    //ci permette di riusare il codice, montarlo e facile per fare debug
    //blocco di codice, ha 3 grossi componente:
    //nome: "calcolare"
    //parametri : lato ecc. e anche tipologia: int, float ...
    //ritorno: risultato, anche nullo
    //chiudere con return, si può anche senza ritornare nulla, del tipo void, possibilmente evitarlo
    //ha 3 momenti particolari:
    //dichiarazione prototico, non ancora implementate
    //defizione : implementare la funzione
    //richiama, utilizzare funzion nel main
    //quando richiama, come se mettesse un breakpoint in main, salta su funzione e con return o } ritorna in main
    //in linguaggio c, dentro funzioni contengono solo variabili locali, passaggio per valore, ovvero riceve una copia del risultato eseguito
    //e con le applicazione non modifica veramente parametri in main
    //passaggio di riferimento : per modificare elemento in c si usa puntatori e non è possibile con altri modi
    //posso passare solo un puntatore, invece di tutta la matrice.
    //attento a usare puntatori, perché puntatori vengono usati solo quando sono neccessario
    //scambio di variabili, non si può passare per valori
    //passare un vettore, richiede anche la lunghezza per non uscire dal vettore e fare casino.
    //non è importante il nome del parametro, ma importante è che siano del stesso tipo
    //array dichiarato dentro funzione, quando funzione smette di esistere, viene cancellato
    //usa comando static, rimanere, e richiede nel main un puntatore che punta la cassella
    //array dinamico non richiede puntatore
    //consiglia fare più funzioni posibili, per main rimane solo esecuzione
    //in generale per comodità evitare variabile con stesso nome, anche per locale.
    //variabile globale si può definire fuori da main, modificata, accessibile per tutti, ma come
    //svantaggio è che è difficile debug, gestione della memoria non è tanta chiara
    //funzioni ricorsive : funzione richiama se stessa, richiede caso base, e richiama. esempio fattoriale.
    //richiede memoria e processione, quindi iterativo è migliore.
    //come vantaggio è molto più semplice, risolve facilmente molti problemi.
    //mancano 3 lezione per concludere c, finito le liste ci sarà primo parziale. 26 ottobre finisce con liste.
    return 0;
}