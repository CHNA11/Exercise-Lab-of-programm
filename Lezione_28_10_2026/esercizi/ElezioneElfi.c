#include <stdio.h>
#include <stdlib.h> //introdotto per allocazione dinamica
#include <string.h> //introdotto per copia nome

//definzione strutture del candidato e Nodo
typedef struct
{
    char nome[19];
    int voto;
} candidato;

typedef struct Nodo
{
    candidato elfo;
    struct Nodo *next;
} Nodo;

//dichiarazione funizioni prototipo
Nodo *creanodo(char *nome);
Nodo *inserimentocoda(Nodo *testa, char *nome);
Nodo *lettura(Nodo *testa);
void stampalista(Nodo *testa, int cont);
Nodo *aggiunta(Nodo *testa, char *nome);
void cercacandidato(Nodo *testa, char *nome, int cont);
char menu();
void scelta(Nodo *testa, char s);
int conta(Nodo *testa);
void liberazione(Nodo *testa);

int main()
{
    Nodo *testa = NULL; //inzializzare lista vuota;
    testa = lettura(testa);  //leggere elementi nel file e ritornare testa della lista nuova
    scelta(testa, menu()); //richiama funzioni di scelte
    return 0;
}

Nodo *creanodo(char *nome)
{  //funzione di creazione nodo per nome
    Nodo *nuovo = (Nodo *)malloc(sizeof(Nodo)); //allocazione dinamica
    if (nuovo == NULL)
    { //controllo
        printf("Errore allocazione\n");
        exit(1);
    }
    nuovo->next = NULL; //assegnazione puntatore
    strcpy(nuovo->elfo.nome, nome); //asseganzione char nome
    nuovo->elfo.voto = 1; //quando si registra nome si conta il suo primo vot
    return nuovo;
}

Nodo *inserimentocoda(Nodo *testa, char *nome)
{
    Nodo *nuovo = creanodo(nome); //inizializzare un nodo nuovo
    if (testa == NULL)
    { //considerare caso lista nulla
        return nuovo;
    }
    Nodo *p = testa; //puntatore per scorrimento
    while (p->next != NULL)
    { //scorrere fino al ultimo
        p = p->next;
    }
    //facendo puntare ultimo nodo verso nodo nuovo
    p->next = nuovo;
    return testa; //ritornare testa della lista
}

Nodo *lettura(Nodo *testa)
{
    FILE *fp; //apertura file
    fp = fopen("elezioni.txt", "r");
    if (fp == NULL)
    {
        printf("apertura file insuccesso");
        return testa;
    }
    char nome[19]; //dichiarare una variabile per salvar lettura file
    while (fgets(nome, 19, fp) != NULL)
    { //scorrere per riga fino alla fine
        nome[strcspn(nome, "\n")] = '\0'; //pulizia buffer
        testa = aggiunta(testa, nome); //richiama funzione per aggiornamento lista
    };
    fclose(fp); //chiusura file
    return testa; //ritornare testa
}

void stampalista(Nodo *testa, int cont)
{
    // sapendo che lista non è vuota
    Nodo *p = testa; //inizializzazione variabile per scorrimento
    while (p != NULL)
    { //stampare lista letta da file
        printf("%s ha ottenuto %d voti pari al %.2f%%\n", p->elfo.nome, p->elfo.voto, (float)p->elfo.voto * 100 / cont);
        p = p->next;
    }
    return;
}

char menu()
{
    char s; //dichiarazione variabile per scelta
    printf("MENU\n");
    printf("a) per visualizzare la lista dei candidati\n");
    printf("b) per cercare un candidato\n");
    printf("c) per uscire\n");
    printf("Scegli: ");
    scanf(" %c", &s); //questa volta con %c per char
    return s;
}

void scelta(Nodo *testa, char s)
{
    int cont = conta(testa); //richiama funzione di conteggio per quantità totale di voti
    while (s != 'c' && s != 'C') //questa volta per char basta != e ==, distingue casi maiuscola e minuscola
    {
        if (s == 'a' || s == 'A') //usa if invece di switch perché scelta è di tipo char
        {
            stampalista(testa, cont);
        }
        else if (s == 'b' || s == 'B')
        {
            char nome[19]; //dichiarare una variabile per inserimento del nome
            printf("Inserisci il nome del candidato da cercare: ");
            scanf("%18s", nome); //lettura nome, vettori sono già puntatori
            cercacandidato(testa, nome, cont); //cerca questo nome sulla lista e stampa risultato
        }
        else //caso defaul
        {
            printf("Usa solo i caratteri consentiti\n");
        }
        s = menu();
    }
    liberazione(testa); //nodi sono allocati dinamicamente, quindi si ricorda di liberare
    return;
}

Nodo *aggiunta(Nodo *testa, char *nome)
{
    Nodo *p = testa;
    while (p != NULL && strcasecmp(p->elfo.nome, nome) != 0)
    { //scorrere finché non trova stesso nome sulla lista
        p = p->next;
    }
    if (p == NULL)
    { //se sono arrivato alla fine, questo nome non è ancora registrato, inserisco per prima volta nella lista
        testa = inserimentocoda(testa, nome);
        return testa;
    }
    else
    {
        p->elfo.voto++; //se ho trovato stesso nome nella lista, incremento numero di voto
    }
    return testa;
}
void cercacandidato(Nodo *testa, char *nome, int cont)
{
    Nodo *p = testa;
    int voto = 0; //inizializzare voto per stampa, come nella richiesta, se nome non è presente nella lista si comporta dati come zeri
    while (p != NULL && strcasecmp(p->elfo.nome, nome) != 0)
    { //scorre fino a trovare nome cercato o fine
        p = p->next;
    }
    if (p != NULL && strcasecmp(p->elfo.nome, nome) == 0)
    { //se non sono arrivato alla fine, ho già trovato questo noto, considero il suo voto
        voto = p->elfo.voto;
    }
    printf("%s ha ottenuto %d voti pari al %.2f%%\n", nome, voto, (float)voto * 100 / cont); //stampa
    return;
}

int conta(Nodo *testa)
{
    int cont = 0; //inizializzare contatore per numero di voti totale
    Nodo *p = testa;
    while (p != NULL)
    { //scorrimento
        cont = cont + p->elfo.voto; //siccome sulla lista gli stessi nomi sono già accumulati insieme, basta aggiungere il voto
        p = p->next;
    }
    return cont;
}

void liberazione(Nodo *testa)
{
    Nodo *temp; //puntatore temporanea per memoria
    Nodo *p = testa;
    while (p != NULL)
    { //scorrimento
        temp = p; //salvare indirizzo del nodo
        p = p->next; //scorrere
        free(temp); //liberare quello salvato
    }
    //stampa risultato
    printf("liberazione memoria con successo\n");
}