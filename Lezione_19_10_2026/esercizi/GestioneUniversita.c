#include <stdio.h>
#include <stdlib.h>

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
    Esame *esami;
    int num_esami;
    int max_esami;
} Studente;

int richiesta();
Studente *allocazione(int n);
void inserimentostudente(Studente *classe, int n_studente);
void aggiuntaesame(Studente studente);
void calcolamedia(Studente studente);
void trovamediaalta(Studente *classe);
void visualizzadecrescente(Studente studente);
void statistica(Studente *classe);
int menu();
void scelta(Studente *classe, int s, int n_studente);

int main()
{
    int n_studente = richiesta();
    Studente *classe = allocazione(n_studente);
    allocazioneesami(classe);
    scelta(classe, menu(), n_studente);
    return 0;
}

int richiesta()
{
    int n;
    printf("inserisci quantità di studenti che desideri gestire : ");
    scanf("%d", &n);
    return n;
}

Studente *allocazione(int n)
{
    Studente *classe = (Studente *)malloc(n * sizeof(Studente));
    if (classe == NULL)
    {
        printf("allocazione insuccesso\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        classe[i].matricola = NULL;
        classe[i].num_esami=0;
        classe[i].esami = (Esame *)malloc(classe[i].num_esami* sizeof(Esame));
        if (classe[i].esami == NULL)
        {
            printf("allocazione insuccesso\n");
            exit(1);
        }
    }
    return classe;
}

void inserimentostudente(Studente *classe, int n_studente)
{
    int flag=0;
    do
    {
        int ind;
        flag=0;
        do
        {
            printf("inserisci numero di posizione per studente da gestire : ");
            scanf("%d", &ind);
        } while (ind < 0 || ind > n_studente);
        if (classe[ind].matricola != NULL)
        {
            printf("studente già esistente nella posizione %d\n", &ind + 1);
        }
        else
        {
            printf("inserisci numero di matricola dello studente : ");
            scanf("%d", &classe[ind].matricola);
            printf("inserisci nome dello studente : ");
            scanf("%s", classe[ind].nome);
            printf("inserisci cognome dello studente : ");
            scanf("%s", classe[ind].cognome);
            flag = 1;
        }
    } while (flag!= 1);
}

void aggiuntaesame(Studente studente){
    int flag=0;
    int n=0;
    do{
    printf("inserisci quantità di esami che desidere aggiungere : ");
    scanf("%d",&n);
    } while(n<0);
    studente.num_esami=studente.num_esami+n;
    int it=0;
    for(int i=studente.num_esami; i<studente.num_esami+n; i++){
        if(studente.num_esami+n>5*(2^it)){
            it++;
        realloc(studente.esami,5*(2^it));
        }
        printf("inserisci nome del corso per esame nella posizione %d : ",i+1);
        scanf("%s",studente.esami[i].nome_corso);
        do{
        printf("inserisci voto del esame corrispondente : ");
        scanf("%d",studente.esami[i].voto);
        } while(studente.esami[i].voto<0 || studente.esami[i].voto>30); //ho escluso caso di lode
        do{
            printf("inserisci CFU del esame corrispondente : ");
        scanf("%d",studente.esami[i].CFU);
        } while(studente.esami[i].CFU<0 || studente.esami[i].CFU>180);
        printf("inserisci data del esame corrispondente in forma gg/mm/aaaa : ");
        scanf("%s",studente.esami[i].data);
    }
}

void calcolamedia(Studente studente){
    int TC=0;
    float sum=0;
    for(int i=0; i<studente.num_esami; i++){
       sum=sum+(studente.esami[i].CFU*studente.esami[i].voto);
       TC=TC+studente.esami[i].CFU; 
    }
    printf("la media pesata dello studente è %.2f", (float)sum/TC);
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
        printf("7.Uscire dal menu");
        printf("inserisci la tua scelta : ");
        scanf("%d", &s); // chiedere scelta dal utente
        return s;
    }

    void scelta(Studente * classe, int s, int n_studenti, int n_esami)
    {
        while (s != 7) // ha senso solo se non ha scelto uscire
        {
            switch (s)
            { // vari casi della scelta
            case 1:
                visualizzazione(sala, fila, posto);
                break;
            case 2:
            {
                Prenotazione p1 = prenotare(sala, fila, posto);
                if (p1.sala == NULL) // se con funzione prenota ha dato questo risultato nullo, è andata male la prenotazione
                {
                    printf("prenotazione insuccesso");
                }
                else
                {
                    printf("prenotazione con successo");
                }
                break;
            }
            case 3:
                cancella(sala, fila, posto);
                break;
            case 4:
                perc(sala, fila, posto);
                break;
            case 5:
                primoposto(sala, fila, posto);
                break;
            default: // se non è uno dei precedenti
                printf("scelta non valida, si chiede di scegliere funzione valida : \n");
            }
            s = menu(); // rinnovare scelta
        }
        printf("Uscita in corso........\n");
    }