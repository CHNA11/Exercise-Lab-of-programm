#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricola;
    char nome[50];
    char cognome[50];
    int voti[6]; // dichiarato come puntatore
    int num_esami_sostenuti;
} Studente;

// questi sono funzioni ripresi da Gestione Università e modificati
int menu();
void scelta(Studente *classe, int s, int n_studente);
float calcolamedia(Studente studente);
void trovamediaalta(Studente *classe, int n_studente);
int richiesta();
Studente *allocazione(int n);
void inserimentostudente(Studente *classe, int n_studente);
void aggiuntaesame(Studente *studente);

int main()
{
    int n = richiesta();
    Studente *classe = (Studente *)malloc(n * sizeof(Studente)); // allocazione dinamica
    scelta(classe, menu(), n);
    return 0;
}

int richiesta()
{
    int n; // dichiarazione di variabile per registro
    printf("inserisci quantità di studenti che desideri gestire : ");
    scanf("%d", &n);
    if (n <= 0) // controllare se valore ha senso
    {
        exit(0);
    }
    return n;
}

Studente *allocazione(int n)
{
    Studente *classe = (Studente *)malloc(n * sizeof(Studente)); // allocazione dinamico
    if (classe == NULL)
    { // controllo
        printf("allocazione insuccesso\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    { // iniizializzazione e allocazione per esami
        classe[i].matricola = 0;
        classe[i].num_esami = 0;
        classe[i].esami = (Esame *)malloc(5 * sizeof(Esame)); // allocazioni per defaul 5
        if (classe[i].esami == NULL)
        { // controllo
            printf("allocazione insuccesso\n");
            exit(1);
        }
    }
    return classe;
}

void inserimentostudente(Studente *classe, int n_studente)
{
    int flag = 0; // indicatrice se inserimento è andato con successo
    do
    {
        int ind; // indice di inserimento dello studente
        flag = 0;
        do
        {
            printf("inserisci numero di posizione per studente da gestire : ");
            scanf("%d", &ind);
        } while (ind < 0 || ind > n_studente);
        if (classe[ind - 1].matricola != 0) // si ricorda che computer comincia da 0, quindi si trasla di uno a sinistra
        {                                   // controllare di non scrvivere sopra quello già fatto
            printf("studente già esistente nella posizione %d\n", ind);
        }
        else
        {
            printf("inserisci numero di matricola dello studente : ");
            scanf("%d", &classe[ind - 1].matricola); // questo è un int
            for (int j = 0; j < ind - 1; j++)
            {
                if (classe[j].matricola == classe[ind - 1].matricola)
                { // controllare che non inserisca studente allo stesso numero di matricola
                    printf("numero di matricola già esistente");
                    return;
                }
            }
            printf("inserisci nome dello studente : ");
            scanf("%s", classe[ind - 1].nome); // questi sono puntatori
            printf("inserisci cognome dello studente : ");
            scanf("%s", classe[ind - 1].cognome);
            classe[ind - 1].max_esami = 0; // inizializzare
            flag = 1;                      // se ha inserito in modo valido si esce dal ciclo
        }
    } while (flag != 1); // controlla se ha effettivamente inserito dati del studente
}

int aggiuntaesame(Studente *studente)
{
    do
    {
        printf("inserisci voto del esame nella posizione %d : ",studente->num_esami_sostenuti+1);
        scanf("%d", &studente->voti[studente->num_esami_sostenuti]); // studente è puntatore, ma tutto non lo è, richiede &
    } while (studente->voti[studente->num_esami_sostenuti] < 18 || studente->voti[studente->num_esami_sostenuti] > 30); // un voto che viene registrato deve essere valido
}

float calcolamedia(Studente studente)
{
    int TC = 0;    // inizializzazione di CFU totale
    float sum = 0; // inizializzare una somma per voti * CFU e dividere per TC alla fine
    if (studente.num_esami == 0)
    { // si considera caso non ha ancora registrato alcun esame
        return 0;
    }
    for (int i = 0; i < studente.num_esami; i++)
    { // se ha esami registrati, si sommano i valori per calcolare media pesata
        sum = sum + (studente.esami[i].CFU * studente.esami[i].voto);
        TC = TC + studente.esami[i].CFU;
    }
    float media = (float)sum / TC; // si esclude automaticamente caso TC =0, perché numero di esami se è 0, esce prima, per limite di inserimento di CFU ha almeno 1
    return media;                  // invece di void ritorna la media e stampa a funzione scelta, perché così richiamo anche per trovare media, e statistica
}

void trovamediaalta(Studente *classe, int n_studente)
{
    int ind_max = 0;
    for (int i = 0; i < n_studente; i++)
    {
        if (calcolamedia(classe[ind_max]) < calcolamedia(classe[i])) // in effetti uso ritorno di calcolamedia per confrontare
        {
            ind_max = i; // classico metodo di ricerca massimo
        }
    }
    // stampa risultato
    printf("lo studente %s %s ha media più alta : %.2f \n", classe[ind_max].nome, classe[ind_max].cognome, calcolamedia(classe[ind_max]));
}

void visualizzadecrescente(Studente studente)
{
    Esame temp; // dichiarazione temporanea di variabile per scambio
    if (studente.num_esami == 0)
    { // considera caso senza esami
        printf("lo studente scelto non ha esami registrati\n");
    }
    else
    { // bubble sort per comodità
        for (int i = 0; i < studente.num_esami - 1; i++)
        {
            for (int j = 0; j < studente.num_esami - 1 - i; j++)
            {
                if (studente.esami[j].voto < studente.esami[j + 1].voto) // decrescente
                {                                                        // scambio
                    temp = studente.esami[j];
                    studente.esami[j] = studente.esami[j + 1];
                    studente.esami[j + 1] = temp;
                }
            }
        }
        // stampa risultato
        printf("ecco la tabella degli esami registrati ordinati per voto decrescente\n");
        printf("%-20s %-4s %-4s %-12s\n", "nome del corso", "voto", "CFU", "data");
        for (int i = 0; i < studente.num_esami; i++)
        { // stampa in modo tabulato
            printf("%-20s %-4d %-4d %-12s\n", studente.esami[i].nome_corso, studente.esami[i].voto, studente.esami[i].CFU, studente.esami[i].data);
        }
    }
}

int menu()
{
    int s; // dichiarazione variabile che registra scelta
    printf("i funzioni possibili sono i seguenti : \n");
    printf("1.Inserire nuovo studente\n");
    printf("2.Aggiugere un voto a uno studente esistente\n");
    printf("3.Salvi i dati su un file binario(studenti.dat)\n");
    printf("4.Generi un report in formato testo(report_studenti.txt\n");
    printf("5.Carichi i dati dal file binario\n");
    printf("6.Cercare uno studente per matricola\n");
    printf("7.Visualizza gli studenti ordinati per media decrescente\n");
    printf("8.Esci\n");
    printf("inserisci la tua scelta : ");
    scanf("%d", &s); // chiedere scelta dal utente
    return s;        // ritornare valore per registrare scelta usato in funzione "scelta"
}

void scelta(Studente *classe, int s, int n_studenti)
{
    int c = 0;
    int *p = &c;
    while (s != 8) // ha senso solo se non ha scelto uscire
    {
        switch (s)
        { // vari casi della scelta
        case 1:
            inserimentostudente(classe, p);
            break;
        case 2:
        {                  // in realtà si può scrivere una funzione per inserimento, ma per differenza di frase per inserimento non lo faccio
            int matricola; // dichiarazione locale della variabile per inserimento
            printf("inserisci numero di matrico dello studente che intendi registrare esami : ");
            scanf("%d", &matricola);
            int flag = 0; // indicatrice per registrazione dell'esame
            for (int i = 0; i < n_studenti; i++)
            {
                if (classe[i].matricola == matricola)
                { // avvisare studente corrispondente al numero di matricola
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
            int matricolaa; // ho poca fantasia per nome di variabili di inserimento
            printf("inserisci numero di matrico dello studente che intendi calcolare la media : ");
            scanf("%d", &matricolaa);
            int flagg = 0; // ho poca fantasia per nome dei indicatori
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
            int matricolaaa; // come caso 2, 3
            printf("inserisci numero di matrico dello studente che intendi visualizzare esami : ");
            scanf("%d", &matricolaaa);
            int flaggg = 0; // come caso 2,3
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
