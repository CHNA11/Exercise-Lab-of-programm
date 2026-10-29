#include <stdio.h>
#include <stdlib.h> //introdotto per allocazione dinamica

typedef struct Nodo // primi nome Nodo dato per poter definire dentro struttura puntatore verso Nodo
{
    int valore;
    struct Nodo *next;
} Nodo; // secondo nome Nodo per uso generale del typedef

//funzioni ricopiati da esercizio precedente
void liberazione(Nodo *testa)
{
    Nodo *p = testa;  // inizializzazione del puntatore per liberazione
    while (p != NULL) // finhcé non sia nullo, attenzione non il puntatore ma nodo stesso
    {
        Nodo *temp = p; // inizializzare un variabile Nodo* per liberare quello della posizione p
        p = p->next;    // scorre il p
        free(temp);     // liberare quello precedente
    }
    printf("Lista deallocata correttamente\n");
}

Nodo *creaNodo(int valore)                      // dando in input un valore
{                                               // come si crea un nodo nuovo
    Nodo *nuovo = (Nodo *)malloc(sizeof(Nodo)); // allocare nodo nuovo, definendo un puntatore
    if (nuovo == NULL)
    { // questo è solo un controllo normale di allocazione dinamica
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    nuovo->valore = valore; // assegnare alla parte del valore il valore inserito
    nuovo->next = NULL;     // assegnare al puntatore contenuto come deafaul verso il NULL
    return nuovo;
}

Nodo *inserisciInTesta(Nodo *testa, int valore)
{                                   // funzione di inserimento in testa, non serve ma scritto per capire meglio
    Nodo *nuovo = creaNodo(valore); // Generare un nodo con valore assegnato
    nuovo->next = testa;            // faccio puntare alla testa delle liste, và bene anche per lista vuota perché anche testa è NULL, però deve essere inizializzato fuori da funzione
    return nuovo;                   // ritornare nodo nuovo così ho nuovo come nuova testa
}

Nodo *inserisciInCoda(Nodo *testa, int valore)
{
    Nodo *nuovo = creaNodo(valore); // genera nuovo nodo con valore
    if (testa == NULL)
    { // per lista vuota, ho testa NULL, quindi nuovo diventa automaticamente testa
        return nuovo;
    }
    Nodo *p = testa; // inizializzare un puntatore che parte da testa per scorrere
    while (p->next != NULL)
    {
        p = p->next; // facendo scorrere fino all'ultimo
    }
    p->next = nuovo; // lo faccio puntare a quello nuovo
    return testa;    // ritornare comunque testa
}

Nodo *inserisciValore(Nodo *testa, int valore, int valorecerca)
{
    // provato a scrivere senza ricopiarlo, infatti creazione del nodo può essere messo più tardi evitando
    // una liberazione, e if del valore uguale non ha senso, ma comunque lascio
    Nodo *nuovo = creaNodo(valore);
    if (testa == NULL)
    { // controllo di lista vuota
        printf("lista vuota, nessun inserimento\n");
        free(nuovo);
        return testa;
    }
    Nodo *p = testa;
    while (p != NULL && p->valore != valorecerca)
    { // scorrere lista in cerca del valore ricercato
        p = p->next;
    }
    if (p == NULL)
    { // caso non trovato
        printf("valore non trovato, nessun inserimento\n");
        free(nuovo);
        return testa;
    }
    if (p->valore == valorecerca)
    {                          // se ho trovato
        nuovo->next = p->next; // faccio puntare nodo nuovo verso il prossimo della lista originale
        p->next = nuovo;       // faccio puntare p verso nodo nuovo
    }
    return testa; // ritornare sempre la testa delle liste
}

Nodo *EliminaElemento(Nodo *testa, int valore)
{
    if (testa == NULL)
    { // caso di lista vuota
        printf("Lista vuota\n");
        return testa;
    }
    Nodo *p = testa;   // puntatore per scorrere
    Nodo *prec = NULL; // puntatore per nodo precedente
    while (p != NULL && p->valore != valore)
    {
        prec = p; // scorrimento per ricerca del valore
        p = p->next;
    }
    if (p == NULL)
    { // siccome già escluso caso testa NULL, vuoldire che scorrendo alla fine non ho trovato
        printf("Elemento non trovato, nessun cancellazione\n");
        return testa;
    }
    if (prec == NULL)
    {                                   // se ho trovato con p ma prec è ancora NULL significa che ho testa da eliminare
        Nodo *nuovatesta = testa->next; // faccio diventare nuova testa il secondo elemento
        free(testa);                    // liberare testa vecchio
        return nuovatesta;              // ritornare nuova testa
    }
    prec->next = p->next; // ignorare p nella lista
    free(p);              // liberare p
    return testa;
}

int CercaElemento(Nodo *testa, int valore)
{
    if (testa == NULL)
    { //considera caso lista vuota
        return 0;
    }
    Nodo *p = testa;
    int ind = 1; //inizializzare indice di elemento 
    int flag = 0; //indicatore per cerca valore
    while (p != NULL)
    {
        if (p->valore == valore)
        {
            flag = 1;
            break; //uscire dal ciclo se ho trovato
        }
        p=p->next; //scorrimento
        ind++;
    }
    if (flag == 1)
    { //caso trovato
        return ind;
    }
    else
    { //caso non trovato
        return -1;
    }
}

void stampalista(Nodo *testa)
{
    if (testa == NULL)
    { //caso lista vuota
        printf("Lista vuota\n");
        return;
    }
    printf("Lista completo : ");
    Nodo *p = testa;
    while (p != NULL)
    { //scorrimento e stampa
        printf("%d -> ", p->valore);
        p = p->next;
    }
    printf("NULL\n"); //stampa la fine
    return;
}

void media(Nodo *testa)
{
    if (testa == NULL) 
    { //caso lista vuota
        printf("Lista vuota\n");
        return;
    }
    int sum = 0; //inizializzare variabile per somma
    int cont = 0; //inizializzare variabbile per quantità di elementi presenti nella lista
    Nodo *p = testa; 
    while (p != NULL)
    { //scorrimento
        sum = sum + p->valore; //sommare i valori
        cont++; //incremento contatore
        p = p->next;
    }
    printf("la media dei valori presenti nella lista è : %.2f\n", (float)sum / cont); //escluso caso divisione per 0 perché già considerato prima caso di lista vuota
    return;
}

void max(Nodo *testa)
{
    if (testa == NULL)
    { //caso lista vuota
        printf("Lista vuota\n");
        return;
    }
    Nodo *p = testa;
    int max = p->valore;
    while (p != NULL)
    { //scorrimento
        if (p->valore > max)
        {
            max = p->valore;
        }
        p = p->next;
    }
    printf("il massimo valore %d si trova nella posizone %d\n", max, CercaElemento(testa, max));
    return;
}

void min(Nodo *testa)
{
    if (testa == NULL)
    { //caso vuoto
        printf("Lista vuota\n");
        return;
    }
    Nodo *p = testa;
    int min = p->valore;
    while (p != NULL)
    { //scorrimento
        if (p->valore < min)
        {
            min = p->valore;
        }
        p = p->next;
    }
    printf("il minimo valore %d si trova nella posizone %d\n", min, CercaElemento(testa, min)); //richima funzione di ricerca per evitare lavori in più
    return;
}

// ricopiati da Gestionevoti.c
int menu()
{
    int s; // dichiarazione variabile che registra scelta
    printf("=== MENU LISTA COLLEGATA === \n");
    printf("1. Inserisci elemento in testa\n");
    printf("2. Inserisci elemento in coda\n");
    printf("3. Inserisci elemento dopo un valore specifico\n");
    printf("4. Elimina elemento\n");
    printf("5. Cerca elemento(indica se presente e la sua posizione)\n");
    printf("6. Stampa lista\n");
    printf("7. Calcola media dei valori\n");
    printf("8. Trova valore massimo\n");
    printf("9. Trova valore minimo\n");
    printf("10. Esci(deallocando memoria)\n");
    printf("inserisci la tua scelta : ");
    scanf("%d", &s); // chiedere scelta dal utente
    return s;        // ritornare valore per registrare scelta usato in funzione "scelta"
}

void scelta(Nodo *testa, int s)
{
    while (s != 10) // ha senso solo se non ha scelto uscire
    {
        switch (s)
        { // vari casi della scelta
            //nei primi tre casi si rinnova la testa della lista in generale, infatti ritornano testa
        case 1:
        {
            int valore;
            printf("inserisci il valore dell'elemento : ");
            scanf("%d", &valore);
            testa = inserisciInTesta(testa, valore);
            break;
        }
        case 2:
        {
            int valore;
            printf("inserisci il valore dell'elemento : ");
            scanf("%d", &valore);
            testa = inserisciInCoda(testa, valore);
            break;
        }
        case 3:
        {
            int valore;
            int valorecerca;
            printf("inserisci il valore dell'elemento : ");
            scanf("%d", &valore);
            printf("insersci il valore dopo il quale inserire il nuovo elemento : ");
            scanf("%d", &valorecerca);
            testa = inserisciValore(testa, valore, valorecerca);
            break;
        }
        case 4:
        {
            int valore;
            printf("inserisci il valore dell'elemento da cancellare : ");
            scanf("%d", &valore);
            testa = EliminaElemento(testa, valore);
            break;
        }
        case 5:
        { //si distingue vari casi, perché per funzione mi serve ritornare indice richiamato da altri funzioni
            int valore;
            printf("inserisci il valore dell'elemento da cercare : ");
            scanf("%d", &valore);
            int ind = CercaElemento(testa, valore);
            if (ind == 0)
            {
                printf("lista vuota\n");
            }
            else if (ind == -1)
            {
                printf("il valore inserito non è presente nella lista\n");
            }
            else
            {
                printf("il valore %d si trova nella posizione %d della lista\n", valore, ind);
            };
            break;
        }
        case 6:
        //tipi void, non rirnano nulla
            stampalista(testa);
            break;
        case 7:
            media(testa);
            break;
        case 8:
            max(testa);
            break;
        case 9:
            min(testa);
            break;
        default: // se non è uno dei precedenti
            printf("scelta non valida, si chiede di scegliere funzione valida : \n");
        }
        s = menu(); // rinnovare scelta
    }
    liberazione(testa); //liberazione per uscita
    printf("Uscita in corso........\n");
}

int main(){
    Nodo * testa=NULL; //inizializzare lista vuota
    scelta(testa,menu());
    return 0;
}