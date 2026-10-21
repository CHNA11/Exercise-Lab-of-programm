#include <stdio.h>
#include <stdlib.h> //per allocazione dinamica
#include <strings.h> //per controllo prodotti con stessi nomi

typedef struct
{ // definizione struttura richiesto
    int codice;
    char nome[50];
    int quantita;
    float prezzo_unitario;
} Prodotto;

int numeroprod(); //chiede numero di prodotti
Prodotto *allocazione(int n); //allocazione dinamica con funzione
void inserimento(Prodotto *prodotti, int n); //funzione che fasì inserire dati nell'array di tipo Prodotto
int menu(); //stampare menu e resituire scelta del utente
void scelta(Prodotto *prodotti, int s, int n); //prende la scelta e dati di prodotti e lavora
void visualizza(Prodotto *prodotti, int n); //funzione che stampa tutti i dati dei prodotti inseriti
void cerca(Prodotto *prodotti, int n); //funzione che cerca prodotto con articolo inserito
void valoretotale(Prodotto *prodotti, int n); //calcola e stampa valore totale
void ordine(Prodotto *prodotti, int n); //ordina array in modo con prezzo unitario crescente
int controllo(Prodotto *prodotti, int i); //una piccola funzione che controlla se utenta ha inserito stessi elementi

int main()
{
    int n = numeroprod(); //inizializzazione della variabile per numero di prodotti
    if (n == 0) //se non ci sono elementi da inserire si esce direttamente
    {
        return 0;
    }
    Prodotto *prodotti = allocazione(n); //altrimenti si inzia allocazione dinamico
    if(prodotti==NULL){ //controllo di allocazione
        printf("allocazione insuccesso");
        return 1;
    }
    inserimento(prodotti, n); //richiama funzione ad iniziare inserire i dati
    scelta(prodotti, menu(), n); //prendere scelta sulle funzioni
    free(prodotti); //ricordare di liberare la memoria
    return 0;
}

int numeroprod()
{
    int n; //dichiarazione locale da inserire
    do
    { //controllare che sia un numero legale
        printf("inserisci numero di quantità di prodotti che si intende gerstire : ");
        scanf("%d", &n); //inserimento
    } while (n < 0);
    return n;
}

Prodotto *allocazione(int n)
{ //allocazione dinamico
    Prodotto *prodotti = (Prodotto *)malloc(n * sizeof(Prodotto));
    return prodotti; //ritornare il puntatore
}

void inserimento(Prodotto *prodotti, int n)
{
    int indicatrice = 0; //inizializzare un indicatrice per attivare o no la conferma
    do
    {
        printf("se preferisci chiudere conferma inserisci 1, altrimenti inserisci 0 : ");
        scanf("%d", &indicatrice); //chiede se volesse chiudere conferma
    } while (indicatrice != 1 && indicatrice != 0); //assicurare che sia un valore valido
    for (int i = 0; i < n; i++)
    {
        int flag = 0;//un indicatrice per chiedere conferma
        do
        {
            flag = 0; //rinnovare ogni volta che entra in ciclo
            //inserimenti
            printf("inserisci dati del prodotto nella posizione %d : \n", i + 1);
            printf("inserisci codice del prodotto : ");
            scanf("%d", &prodotti[i].codice);
            printf("inserisci nome del prodotto : ");
            scanf("%49s", prodotti[i].nome);
            do
            {
                printf("inserisci quantità del prodotto : ");
                scanf("%d", &prodotti[i].quantita);
                if (prodotti[i].quantita < 0)
                {
                    printf("la quantità del prodotto non deve essere negativo\n");
                }
            } while (prodotti[i].quantita < 0); //controlli
            do
            {
                printf("inserisci prezzo unitario del prodotto : ");
                scanf("%f", &prodotti[i].prezzo_unitario);
                if (prodotti[i].prezzo_unitario < 0)
                {
                    printf("il prezzo unitario del prodotto non deve essere negativo\n");
                }
            } while (prodotti[i].prezzo_unitario < 0); //controlli
            if (indicatrice == 0) //se non ha chiuso conferma
            {
                printf("i dati del prodotto che hai inserito sono :\n");
                printf("%-10s %-20s %-10s %-15s\n", "codice", "nome", "quantità", "prezzo unitario");
                printf("%-10d %-20s %-10d %-15.2f\n", prodotti[i].codice, prodotti[i].nome, prodotti[i].quantita, prodotti[i].prezzo_unitario);
                do
                {
                    printf("per confermare dati inserisci premi 1, altrimenti premi 0 : ");
                    scanf("%d", &flag);
                } while (flag != 1 && flag != 0);
            }
            else
            {
                flag = 1;
            }
            if (flag == 1) //solo se ha confermato dati inseriti
            {
                int cont = controllo(prodotti, i);
                if (cont != 1) //se ha inserito con ripetizione
                {
                    printf("inserisci di nuovo i dati del prodotto\n");
                    flag = 0;
                }
            }
        } while (flag == 0); //finché non dà conferma sui dati inseriti
    }
}

int controllo(Prodotto *prodotti, int i)
{
    int cont = 1; //assumiamo che tutto vada bene
    for (int j = 0; j < i; j++)
    {//controllare se ci sono casi strani
        if (prodotti[j].codice == prodotti[i].codice)
        {
            printf("esiste già prodotto con stesso codice inserito, si consiglia di controllare,\n se confermi azione inserisci 1, altrimenti inserisci un qualunque numero intero : ");
            scanf("%d", &cont);
            return cont;
        }
        if (strcasecmp(prodotti[j].nome, prodotti[i].nome) == 0)
        {
            printf("esiste già prodotto con stesso nome inserito, si consiglia di controllare,\n se confermi azione inserisci 1, altrimenti un qualunque numero intero : ");
            scanf("%d", &cont);
            return cont;
        }
    }
    return cont; //ritornare risultato
}
int menu()
{ //stampa il menu
    int n; //dihciarare una variabile per registrare scelta
    printf("I funzioni possibili da svolgere sono i seguenti :\n");
    printf("1.Visualizzare tutti i prodotti\n");
    printf("2.Cercare un prodotto per codice\n");
    printf("3.Calcola il valore totale del magazzino\n");
    printf("4.Ordinare i prodotti per prezzo crescente\n");
    printf("5.Uscire dal menu\n");
    printf("scegli funzione in cui si intendi svolgere : ");
    scanf("%d", &n);
    return n;
}

void scelta(Prodotto *prodotti, int s, int n)
{
    while (s != 5) //ha senso solo se non ha scelto uscire
    {
        switch (s)
        {
        case 1:
            visualizza(prodotti, n); //richiama funzione di visualizzazione
            break;
        case 2:
            cerca(prodotti, n); //richiama funzione di ricerca
            break;
        case 3:
            valoretotale(prodotti, n); //richiama funzione di calcolare valore totale
            break;
        case 4:
            ordine(prodotti, n); //ordinare array
            break;
        default: //se non è uno dei precedenti
            printf("scelta non valida, si chiede di scegliere funzione valida : \n");
        }
        s = menu(); //rinnovare scelta
    }
    printf("Uscita in corso........\n");
}

void visualizza(Prodotto *prodotti, int n)
{ //stampa con ciclo e tabulazione
    printf("i dati di tutti i prodotti inseriti sono : \n");
    printf("%-10s %-20s %-10s %-15s\n", "codice", "nome", "quantità", "prezzo unitario");
    for (int i = 0; i < n; i++)
    {
        printf("%-10d %-20s %-10d %-15.2f\n", prodotti[i].codice, prodotti[i].nome, prodotti[i].quantita, prodotti[i].prezzo_unitario);
    }
}

void cerca(Prodotto *prodotti, int n)
{
    int temp; //dichiarare variabile per inserire codice da cercare
    printf("inserisci il codice di articolo che intendi cercare : ");
    scanf("%d", &temp);
    printf("il prodotto con corrispondente codice è :\n");
    printf("%-10s %-20s %-10s %-15s\n", "codice", "nome", "quantità", "prezzo unitario");
    for (int i = 0; i < n; i++)
    {
        if (prodotti[i].codice == temp) //controllare se ci sono codice uguali
        {
            printf("%-10d %-20s %-10d %-15.2f\n", prodotti[i].codice, prodotti[i].nome, prodotti[i].quantita, prodotti[i].prezzo_unitario);
        }
    }
}

void valoretotale(Prodotto *prodotti, int n)
{
    float somma = 0; //inizializzare una variabile per somma dei valori
    for (int i = 0; i < n; i++)
    {
        somma = somma + ((float)prodotti[i].quantita * prodotti[i].prezzo_unitario); //sommare ad ogni iterazione
    }
    printf("il valore totale del magazzino è : %.2f\n", somma); //stampa risultato
}

void ordine(Prodotto *prodotti, int n)
{
    Prodotto temp;
    for (int i = 0; i < n - 1; i++) //bubble sort
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (prodotti[j].prezzo_unitario > prodotti[j + 1].prezzo_unitario)
            {
                temp = prodotti[j];
                prodotti[j] = prodotti[j + 1];
                prodotti[j + 1] = temp;
            }
        }
    }
    printf("dopo ordinamento "); //stampa risultato ordinato
    visualizza(prodotti, n); //una volta ordinato, basta richiamare punzione che stampa
}