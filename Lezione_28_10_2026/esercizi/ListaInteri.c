#include <stdio.h>
#include <stdlib.h> //introdotto per allocazione dinamica

typedef struct Nodo //primi nome Nodo dato per poter definire dentro struttura puntatore verso Nodo
{
    int valore;
    struct Nodo *next;
} Nodo; //secondo nome Nodo per uso generale del typedef

Nodo *creaNodo(int valore) //dando in input un valore
{ //come si crea un nodo nuovo
    Nodo *nuovo = (Nodo *)malloc(sizeof(Nodo)); //allocare nodo nuovo, definendo un puntatore
    if (nuovo == NULL)
    { //questo è solo un controllo normale di allocazione dinamica
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    nuovo->valore = valore; //assegnare alla parte del valore il valore inserito
    nuovo->next = NULL; //assegnare al puntatore contenuto come deafaul verso il NULL
    return nuovo;
}

Nodo *inserisciInTesta(Nodo *testa, int valore)
{ //funzione di inserimento in testa, non serve ma scritto per capire meglio
    Nodo *nuovo = creaNodo(valore); //Generare un nodo con valore assegnato 
    nuovo->next = testa; //faccio puntare alla testa delle liste, và bene anche per lista vuota perché anche testa è NULL, però deve essere inizializzato fuori da funzione
    return nuovo; //ritornare nodo nuovo così ho nuovo come nuova testa
}

Nodo * inserisciInCoda(Nodo *testa, int valore){
    Nodo* nuovo=creaNodo(valore); //genera nuovo nodo con valore
    if(testa==NULL){ //per lista vuota, ho testa NULL, quindi nuovo diventa automaticamente testa
        return nuovo;
    }
    Nodo* p=testa; //inizializzare un puntatore che parte da testa per scorrere
    while(p->next !=NULL){
        p=p->next; //facendo scorrere fino all'ultimo
    }
    p->next=nuovo; //lo faccio puntare a quello nuovo
    return testa; //ritornare comunque testa
}

//dichiarazione prototipo delle funzioni
Nodo *inserimento();

//int per richiesta dell'esercizio, in realtà posso mettere con void
int contaElementi(Nodo *testa);
int sommaValori(Nodo *testa);
void liberazione(Nodo *testa);
void stampalista(Nodo *teste);

int main()
{
    Nodo *testa = inserimento(); //creazione delle liste con dei inserimenti valori
    liberazione(testa); //contiene sia stampa dei risultati sia liberazione dell'allocazione dinamica
    return 0;
}

Nodo *inserimento()
{
    Nodo *testa = NULL; //inizializzare una testa per lista vuota
    int temp; //dichiarazione variabile per usato da scanf e assegnato al nodo
    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci numero intero nella posizione %d : ", i + 1);
        scanf("%d", &temp); //inserimento
        testa = inserisciInCoda(testa, temp);
    }
    return testa; //ritornare testa della lista
}

void liberazione(Nodo *testa)
{
    stampalista(testa); //richiama funzione di stampa lista
    printf("il numero totale di elementi presenti nella lista è : %d\n", contaElementi(testa));//stampa risultato delle funzioni richiesta
    printf("la somma di tutti i valori presenti nella lista è : %d\n", sommaValori(testa));
    Nodo *p = testa; //inizializzazione del puntatore per liberazione
    while (p != NULL) //finhcé non sia nullo, attenzione non il puntatore ma nodo stesso
    {
        Nodo *temp = p; //inizializzare un variabile Nodo* per liberare quello della posizione p
        p = p->next; //scorre il p
        free(temp); //liberare quello precedente
    }
    printf("Lista deallocata correttamente\n");
}

int contaElementi(Nodo *testa)
{
    int cont = 0; //contatore per elementi presenti
    Nodo *p = testa;
    while (p != NULL) //analogamente a liberazione
    {
        cont++;
        p = p->next;
    }
    return cont;
}

int sommaValori(Nodo *testa)
{
    int sum = 0;
    Nodo *p = testa;
    while (p != NULL) //analogamente a liberazione e cont
    {
        sum = sum + p->valore;
        p = p->next;
    }
    return sum;
}

void stampalista(Nodo *testa)
{
    printf("Lista completa: ");
    Nodo *p = testa;
    while (p != NULL) //analogamente a liberazione
    {
        printf("%d -> ", p->valore);
        p = p->next;
    }
    printf("NULL\n");
    return;
}

