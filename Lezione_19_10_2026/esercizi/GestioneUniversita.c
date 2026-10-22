#include <stdio.h>
#include <stdlib.h> //per allocaizone dinamico

//definizione delle strutture richieste
typedef struct
{
    char nome_corso[50];
    int voto;
    int CFU;
    char data[11];
} Esame;

typedef struct
{
    int matricola;
    char nome[50];
    char cognome[50];
    Esame *esami; //dichiarato come puntatore
    int num_esami;
    int max_esami; //massimo voto tra gli esami registrati
} Studente;

//dichiarazione prototipo delle funzioni
int richiesta();
Studente *allocazione(int n);
void inserimentostudente(Studente *classe, int n_studente);
void aggiuntaesame(Studente *studente);
float calcolamedia(Studente studente);
void trovamediaalta(Studente *classe, int n_studente);
void visualizzadecrescente(Studente studente);
void statistica(Studente *classe, int n_studente);
int menu();
void scelta(Studente *classe, int s, int n_studente);
void liberazione(Studente *classe, int n_studente);

int main()
{
    int n_studente = richiesta(); //chiedere a utente quantità di studenti da gestire
    Studente *classe = allocazione(n_studente); //richiama funzione di allocazione per insieme di studenti
    scelta(classe, menu(), n_studente); //richiare delle funzioni in base alla scelta
    liberazione(classe, n_studente); //liberare la memoria quando si esce dal menu
    return 0;
}

int richiesta()
{
    int n;//dichiarazione di variabile per registro
    printf("inserisci quantità di studenti che desideri gestire : ");
    scanf("%d", &n);
    if (n <= 0) //controllare se valore ha senso
    {
        exit(0);
    }
    return n;
}

Studente *allocazione(int n)
{
    Studente *classe = (Studente *)malloc(n * sizeof(Studente)); //allocazione dinamico
    if (classe == NULL)
    { //controllo
        printf("allocazione insuccesso\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    { //iniizializzazione e allocazione per esami
        classe[i].matricola = 0;
        classe[i].num_esami = 0;
        classe[i].esami = (Esame *)malloc(5 * sizeof(Esame)); //allocazioni per defaul 5
        if (classe[i].esami == NULL)
        { //controllo
            printf("allocazione insuccesso\n");
            exit(1);
        }
    }
    return classe;
}

void inserimentostudente(Studente *classe, int n_studente)
{
    int flag = 0; //indicatrice se inserimento è andato con successo
    do
    {
        int ind; //indice di inserimento dello studente
        flag = 0;
        do
        {
            printf("inserisci numero di posizione per studente da gestire : ");
            scanf("%d", &ind);
        } while (ind < 0 || ind > n_studente);
        if (classe[ind-1].matricola != 0) //si ricorda che computer comincia da 0, quindi si trasla di uno a sinistra
        { //controllare di non scrvivere sopra quello già fatto
            printf("studente già esistente nella posizione %d\n", ind);
        }
        else
        {
            printf("inserisci numero di matricola dello studente : ");
            scanf("%d", &classe[ind-1].matricola); //questo è un int
            for(int j=0; j<ind-1; j++){
                if(classe[j].matricola==classe[ind-1].matricola){ //controllare che non inserisca studente allo stesso numero di matricola
                    printf("numero di matricola già esistente");
                    return;
                }
            }
            printf("inserisci nome dello studente : ");
            scanf("%s", classe[ind-1].nome); //questi sono puntatori
            printf("inserisci cognome dello studente : ");
            scanf("%s", classe[ind-1].cognome);
            classe[ind-1].max_esami = 0; //inizializzare
            flag = 1;//se ha inserito in modo valido si esce dal ciclo
        }
    } while (flag != 1); //controlla se ha effettivamente inserito dati del studente
}

void aggiuntaesame(Studente *studente)
{
    int flag = 0;
    int n = 0;
    do
    {
        printf("inserisci quantità di esami che desidere aggiungere : ");
        scanf("%d", &n);
    } while (n < 0);
    int it = 0;//indicatore di espansione
    /* versione precedenti
    prima ho scritto in un'altro modo che funziona comunque ma meno efficiente, lascio nei commeti
    while(studente->num_esami+n>5*(1 << it)){
        it++;
        (Esame *)realloc(studente->esami,(5*(1 << it))*sizeof(Esame));   
    }
        Esempio: se ho 4 esami già registrati e ne voglio aggiungere 7, sono in tutto 11, chiede 2 iterazioni dove ogni volta rialloco studente->esami
        Versione migliorato : protare fuori realloc dai ciclo -> come sonseguenza si rialloca anche quando non ho bisogno
    */
    int futuro = studente->num_esami + n; //inziizalizzazione locale per vedere se c'è bisogno di riallocare
    while (5 * (1 << it) < studente->num_esami) //quando numero di esami è maggiore da quello disponibile
    { //evita di cominciare da zero per itt quando ho già esami registrati
        it++; //incremento indicatore
    };
    int itt = it; //considerare un secondo indicatrice
    while (5 * (1 << itt) < futuro) //se aggiunto a quello che bisogna essere inserito manca memoria disponibile
    { //è qui che vedo se effettivamente ho bisogno di riallocazione
        itt++;
    };
    if (itt > it) //con doppio controllo faccio riallocazione solo se è neccessario
    {
        Esame *temp = (Esame *)realloc(studente->esami, (5 * (1 << it)) * sizeof(Esame)); //riallocazione con comando realloc, non c'è bisogno di riallocare
        if (temp == NULL)  //si usa temp proprio per evitare che durante riallocazione si perde informazioni vecchi
        {
            printf("allocazione insuccesso");
            return;
        } 
        studente->esami = temp; //si assegna indirizzo solo che riallocazione è andata con successo
    }
    for (int i = studente->num_esami; i < studente->num_esami + n; i++) //parte da numero di esami, perché per esempio numero esami =2 allora 0,1 sono già registrati
    {
        printf("inserisci nome del corso per esame nella posizione %d : ", i + 1); //se ha già inserito i esami, si registra al esame del i+1
        scanf("%s", studente->esami[i].nome_corso); //studente è puntatore, anche in tutto
        do
        {
            printf("inserisci voto del esame corrispondente : ");
            scanf("%d", &studente->esami[i].voto);  //studente è puntatore, ma tutto non lo è, richiede &
        } while (studente->esami[i].voto < 18 || studente->esami[i].voto > 31); //un voto che viene registrato deve essere valido
        if (studente->esami[i].voto > studente->max_esami)
        { //ogni volta che inserisce controlla se ha superato massimo voto preso
            studente->max_esami = studente->esami[i].voto; //se si, registra il nuovo massimo
        }
        do
        {
            printf("inserisci CFU del esame corrispondente : ");
            scanf("%d", &studente->esami[i].CFU);
        } while (studente->esami[i].CFU < 1 || studente->esami[i].CFU > 180); //CFU deve essere in un intervallo valido, assumo che più di 180 non può esistere
        printf("inserisci data del esame corrispondente in forma gg/mm/aaaa : ");
        scanf("%s", studente->esami[i].data); //non metto alcun controllo perché non riesce ad limitarlo
    }
    studente->num_esami = studente->num_esami + n; //dopo aver registrato tutto, rinnova numero di esami
}

float calcolamedia(Studente studente)
{
    int TC = 0; //inizializzazione di CFU totale
    float sum = 0; //inizializzare una somma per voti * CFU e dividere per TC alla fine
    if (studente.num_esami == 0)
    { //si considera caso non ha ancora registrato alcun esame
        return 0;
    }
    for (int i = 0; i < studente.num_esami; i++)
    { //se ha esami registrati, si sommano i valori per calcolare media pesata
        sum = sum + (studente.esami[i].CFU * studente.esami[i].voto);
        TC = TC + studente.esami[i].CFU;
    }
    float media = (float)sum / TC; //si esclude automaticamente caso TC =0, perché numero di esami se è 0, esce prima, per limite di inserimento di CFU ha almeno 1
    return media; //invece di void ritorna la media e stampa a funzione scelta, perché così richiamo anche per trovare media, e statistica
}

void trovamediaalta(Studente *classe, int n_studente)
{
    int ind_max = 0;
    for (int i = 0; i < n_studente; i++)
    {
        if (calcolamedia(classe[ind_max]) < calcolamedia(classe[i])) //in effetti uso ritorno di calcolamedia per confrontare
        {
            ind_max = i; //classico metodo di ricerca massimo
        }
    }
    //stampa risultato
    printf("lo studente %s %s ha media più alta : %.2f \n", classe[ind_max].nome, classe[ind_max].cognome, calcolamedia(classe[ind_max]));
}

void visualizzadecrescente(Studente studente)
{ 
    Esame temp; //dichiarazione temporanea di variabile per scambio
    if (studente.num_esami == 0)
    { //considera caso senza esami
        printf("lo studente scelto non ha esami registrati\n");
    }
    else
    { //bubble sort per comodità
        for (int i = 0; i < studente.num_esami - 1; i++)
        {
            for (int j = 0; j < studente.num_esami - 1 - i; j++)
            {
                if (studente.esami[j].voto < studente.esami[j + 1].voto) //decrescente
                { //scambio
                    temp = studente.esami[j];
                    studente.esami[j] = studente.esami[j + 1];
                    studente.esami[j + 1] = temp;
                }
            }
        }
        //stampa risultato
        printf("ecco la tabella degli esami registrati ordinati per voto decrescente\n");
        printf("%-20s %-4s %-4s %-12s\n", "nome del corso", "voto", "CFU", "data");
        for (int i = 0; i < studente.num_esami; i++)
        { //stampa in modo tabulato
            printf("%-20s %-4d %-4d %-12s\n", studente.esami[i].nome_corso, studente.esami[i].voto, studente.esami[i].CFU, studente.esami[i].data);
        }
    }
}

void statistica(Studente *classe, int n_studente)
{
    int tot_esami = 0;
    float mediamedia = 0;
    int cont = 0; //contatore per intervallo 18-21
    int contt = 0; //22-25
    int conttt = 0; //26-28
    int contttt = 0; //29-31 , 31 si intende per 30 e lode
    for (int i = 0; i < n_studente; i++)
    {
        tot_esami = tot_esami + classe[i].num_esami;
        mediamedia = mediamedia + calcolamedia(classe[i]);
        for (int j = 0; j < classe[i].num_esami; j++)
        { //per intervalli è più facile if invece di switch case
            if (classe[i].esami[j].voto >= 18 && classe[i].esami[j].voto <= 21)
            {
                cont++;
            }
            else if (classe[i].esami[j].voto >= 22 && classe[i].esami[j].voto <= 25)
            {
                contt++;
            }
            else if (classe[i].esami[j].voto >= 26 && classe[i].esami[j].voto <= 28)
            {
                conttt++;
            }
            else //si ricorda che durante inserimento ho già escluso valore <18 o >31
            {
                contttt++;
            }
        }
    }
    mediamedia = (float)mediamedia / n_studente; //calcola media genelare
    //stampa risultati
    printf("il numero totale degli esami nel sistema è : %d\n", tot_esami);
    printf("la media generale di tutti gli studenti è : %.2f\n", mediamedia);
    //in modo tabulato
    printf("la distribuzione dei voti sono come seguenti : \n");
    printf("%-7s %-7s %-7s %-7s\n", "18-21", "22-25", "26-28", "29-30L");
    printf("%-7d %-7d %-7d %-7d\n", cont, contt, conttt, contttt);
}
int menu()
{
    int s; // dichiarazione variabile che registra scelta
    printf("i funzioni possibili sono i seguenti : \n");
    printf("1.Inserire nuovo studente\n");
    printf("2.Aggiugere esame a uno studente esistente\n");
    printf("3.Calcolare la media pesata di uno studente\n");
    printf("4.Trovare lo studente con la media più alta\n");
    printf("5.Visualizzare tutti gli esami di uno studente ordinati per voto decrescente \n");
    printf("6.Generare statistiche: numero totale esami nel sistema,\n media generale di tutti gli studenti, distrubuzione dei voti\n");
    printf("7.Uscire dal menu\n");
    printf("inserisci la tua scelta : ");
    scanf("%d", &s); // chiedere scelta dal utente
    return s; //ritornare valore per registrare scelta usato in funzione "scelta"
}

void scelta(Studente *classe, int s, int n_studenti)
{
    while (s != 7) // ha senso solo se non ha scelto uscire
    {
        switch (s)
        { // vari casi della scelta
        case 1:
            inserimentostudente(classe, n_studenti);
            break;
        case 2:
        { //in realtà si può scrivere una funzione per inserimento, ma per differenza di frase per inserimento non lo faccio
            int matricola; //dichiarazione locale della variabile per inserimento
            printf("inserisci numero di matrico dello studente che intendi registrare esami : ");
            scanf("%d", &matricola);
            int flag = 0; //indicatrice per registrazione dell'esame
            for (int i = 0; i < n_studenti; i++)
            {
                if (classe[i].matricola == matricola)
                { //avvisare studente corrispondente al numero di matricola
                    printf("il numero di matricola corrisponde a studente %s %s\n", classe[i].nome, classe[i].cognome);
                    aggiuntaesame(&classe[i]);
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                printf("numero di matricola non registrato\n");
            }
            else
            {
                printf("esame registrato con successo\n");
            }
            break;
        }
        case 3:
        {
            int matricolaa; //ho poca fantasia per nome di variabili di inserimento
            printf("inserisci numero di matrico dello studente che intendi calcolare la media : ");
            scanf("%d", &matricolaa);
            int flagg = 0; //ho poca fantasia per nome dei indicatori
            for (int i = 0; i < n_studenti; i++)
            {
                if (classe[i].matricola == matricolaa)
                {
                    printf("il numero di matricola corrisponde a studente %s %s\n", classe[i].nome, classe[i].cognome);
                    printf("il studente corrispondente ha media pesata : %.2f\n", calcolamedia(classe[i]));
                    flagg = 1;
                }
            }
            if (flagg == 0)
            {
                printf("numero di matricola non registrato\n");
            }
            break;
        }
        case 4:
            trovamediaalta(classe, n_studenti);
            break;
        case 5:
        {
            int matricolaaa; //come caso 2, 3
            printf("inserisci numero di matrico dello studente che intendi visualizzare esami : ");
            scanf("%d", &matricolaaa);
            int flaggg = 0; //come caso 2,3
            for (int i = 0; i < n_studenti; i++)
            {
                if (classe[i].matricola == matricolaaa)
                {
                    printf("il numero di matricola corrisponde a studente %s %s\n", classe[i].nome, classe[i].cognome);
                    visualizzadecrescente(classe[i]);
                    flaggg = 1;
                }
            }
            if (flaggg == 0)
            {
                printf("numero di matricola non registrato\n");
            }
            break;
        }
        case 6:
            statistica(classe, n_studenti);
            break;
        default: // se non è uno dei precedenti
            printf("scelta non valida, si chiede di scegliere funzione valida : \n");
        }
        s = menu(); // rinnovare scelta
    }
    printf("Uscita in corso........\n");
}

void liberazione(Studente *classe, int n_studente)
{ //funzione di liberazione
    for (int i = 0; i < n_studente; i++)
    {
        free(classe[i].esami);
    }
    free(classe);
}