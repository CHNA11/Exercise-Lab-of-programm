# include <stdio.h>
int main(){
    //per gestione della memoria, allocazione quanto neccessario
    //passare quantità grande dati
    //esiste sia in c sia in c++, in altri linguaggi non è detto esiste
    //c usa sopretutto per esistenza di puntatori
    // & restituisce indirizzo di memoria di una variabile
    // %d &x stampa indirizzo di memoria
    //quando si fa con scanf("%d",&x), stiamo dicendo di dare in input e salvare nell'indirzzo di x
    //.* dichiara una variabile puntatore
    //.* serve ad operatore di deferenziazione
    // se ho puntatore p, ha indirizzo di memoria di x come contenuto,
    //*p legge e scrive su quel indirizzo
    // int p=&x
    //aritmetica puntatori
    //x=10 variabile semplice
    // int *p=&x puntatore che punta x
    //a=*p + 10 è valore contenuto in indrizzo , quindi x+10
    //* ha sempre precedenza di tutti
    //*p=*p+10  è come modificare valore di x, diventa 20
    //++*p incremento valore di x
    // incrementa comunque x
    //*p++ è l'unico modo di modificarlo, ma bisogna stare attenti su quello che punta, ameno che sia in un array
    // in un array di 10, 20, 30, 40 
    //se faccio *p che punta numeri, va a puntare prima cassella dell'array
    //incrementando p di uno, va a puntare il secondo elemento
    //esiste array di puntatore
    //serve per gestire array delle stringhe, vantaggia nella gestione della memoria
    //cioè, faccio puntare ogni elemento ad una stringa ognuno ad lughenzza diversa
    //malloc ci permette di creare strutture di dati che cambia dimensione nel tempo
    // malloc=memory allocation, memoria divisa in ip e stac, ip è porzione di memoria grande, stac più piccola
    // stac è più veloce, ma per grande valore c'è stacoverflow 
    //ip ha memoria dinamica, gestiamo con funzione malloc, carloc ecc...
    //non hanno dimensione fissa, bisogna fissare limitatezza
    //malloc serve libreria predefinita
    //restituisce null se non c'è memoria disponibile
    //chiede refree per liberarle
    //se non refree rishcia memoryleek che crashia il programma
    //pseudo definizione crea problema perché non è limitato,rischia overflow
    //riallocamente, metodo più efficiente è radoppiare ogni volta la grandezza.
}