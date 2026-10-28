#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int matricola;
    char nome[50];
    char cognome[50];
    int voti[6]; 
    int num_esami_sostenuti;
} Studente; //definizione  struttura richiesto

// questi sono funzioni ripresi da Gestione Università e modificati
int menu();
void scelta(Studente *classe, int s, int n);
float calcolamedia(Studente studente);
int trovamediaalta(Studente *classe, int c);
int richiesta();
Studente *allocazione(int n);
void inserimentostudente(Studente *classe, int *p, int n);
void aggiuntaesame(Studente *studente);
void visualizzadecrescente(Studente *classe, int c);
//questi sono funzioni prototipo scritte da 0
void salva(Studente *classe, int *p);
void cerca(Studente *classe, int c, int matricola);
void carica(Studente *classe, int *p, int n);
void report(Studente *classe, int c);

int main()
{
    int n = richiesta(); //chiedere a utante quanti sono numeri di studente da gestire
    Studente *classe = allocazione(n); // allocazione dinamica
    scelta(classe, menu(), n); //richiama funzione di scelta con menu
    free(classe); //liberazione allocazione dinamica
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
    return classe;
}

void inserimentostudente(Studente *classe, int *p, int n)
{
    int temp; //dichiarazione variabile temporanea
    int c = *p; //inizializzare valore nel puntatore p per comodità
    if (c >= n) //controllare di non uscire dal limite
    {
        printf("numero di studente esistente superiore dalla capacità definita all'inizio\n");
        return;
    }
    printf("inserisci numero di matricola dello studente : "); //richiesta dati dello studente
    scanf("%d", &temp); // prima si salva in temp per controllare
    for (int j = 0; j < c; j++)
    { //controlla che studente non deve ripetere per numero di matricola
        if (classe[j].matricola == temp)
        { // controllare che non inserisca studente allo stesso numero di matricola
            printf("numero di matricola già esistente");
            return;
        }
    }
    //se non ci sono errori, si registra effettivamente dati
    classe[c].matricola = temp;
    printf("inserisci nome dello studente : ");
    scanf("%s", classe[c].nome); // questi sono puntatori
    printf("inserisci cognome dello studente : ");
    scanf("%s", classe[c].cognome);
    classe[c].num_esami_sostenuti = 0; // inizializzare
    (*p)++; //incrementare contatore per numero di studenti registrati, puntatore per modifica globale
}

void aggiuntaesame(Studente *studente)
{
    if(studente->num_esami_sostenuti>=6){ //controllo di array pieno
        printf("il studente corrispondente ha già registrato tutti 6 esami\n");
        return;
    }
    do
    {
        printf("inserisci voto del esame nella posizione %d : ", studente->num_esami_sostenuti + 1);
        scanf("%d", &studente->voti[studente->num_esami_sostenuti]); // studente è puntatore, ma tutto non lo è, richiede &
    } while (studente->voti[studente->num_esami_sostenuti] < 18 || studente->voti[studente->num_esami_sostenuti] > 30); // un voto che viene registrato deve essere valido
    studente->num_esami_sostenuti++; //ogni volta che registra un voto incrementa anche numero di esami sostenuti
}

float calcolamedia(Studente studente)
{
    int sum = 0; // inizializzare una somma per voti
    if (studente.num_esami_sostenuti == 0)
    { // si considera caso non ha ancora registrato alcun esame
        return 0; //uscire per evitare divisione per 0
    }
    for (int i = 0; i < studente.num_esami_sostenuti; i++)
    { // se ha esami registrati, si sommano i valori
        sum = sum + (studente.voti[i]);
    }
    float media = (float)sum / studente.num_esami_sostenuti; // si esclude automaticamente divisione per 0 considerato già prima
    return media;                                            // invece di void ritorna la media e stampa a funzione scelta, perché così facilita nelle richiami dei altri funzioni
}

int trovamediaalta(Studente *classe, int c)
{
    int ind_max = 0; //inizializzazione variabile per indice di massimo
    for (int i = 0; i < c; i++)
    {
        if (calcolamedia(classe[ind_max]) < calcolamedia(classe[i])) // in effetti uso ritorno di calcolamedia per confrontare
        {
            ind_max = i; // classico metodo di ricerca massimo
        }
    }
    return ind_max; //ritornare un valore di indice per scrittura nel file
}

void visualizzadecrescente(Studente *classe, int c)
{
    Studente temp; // dichiarazione temporanea di variabile per scambio
                   // bubble sort per comodità
    for (int i = 0; i < c - 1; i++)
    {
        for (int j = 0; j < c - 1 - i; j++)
        {
            if (calcolamedia(classe[j]) < calcolamedia(classe[j + 1])) // decrescente
            {                                                              // scambio
                temp = classe[j];
                classe[j] = classe[j + 1];
                classe[j + 1] = temp;
            }
        }
    }
    // stampa risultato
    printf("ecco la tabella degli studenti ordinati per media decrescente\n");
    printf("%-10s %-10s %-10s %-20s %-10s\n", "matricola", "nome", "cognome", "numero di esami sostenuti", "media");
    for (int i = 0; i < c; i++)
    { // stampa in modo tabulato
        printf("%-10d %-10s %-10s %-20d %-10.2f\n", classe[i].matricola, classe[i].nome, classe[i].cognome, classe[i].num_esami_sostenuti, calcolamedia(classe[i]));
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

void scelta(Studente *classe, int s, int n)
{
    int c = 0; //inizializzazione contatore per numero di studenti inseriti
    int *p = &c; //inizializzare anche puntatore per c, che poi viene presa dalle funzione e modificate valori di c
    while (s != 8) // ha senso solo se non ha scelto uscire
    {
        switch (s)
        { // vari casi della scelta
        case 1:
            inserimentostudente(classe,p, n);
            break;
        case 2:
        {                  // in realtà si può scrivere una funzione per inserimento, ma per differenza di frase per inserimento non lo faccio
            int matricola; // dichiarazione locale della variabile per inserimento
            printf("inserisci numero di matrico dello studente che intendi registrare esami : ");
            scanf("%d", &matricola);
            int flag = 0; // indicatrice per registrazione dell'esame
            for (int i = 0; i < c; i++)
            {
                if (classe[i].matricola == matricola)
                { // avvisare studente corrispondente al numero di matricola
                    printf("il numero di matricola corrisponde a studente %s %s\n", classe[i].nome, classe[i].cognome);
                    aggiuntaesame(&classe[i]);
                    flag = 1;
                    break; //si può direttamente uscire dal primo trovato perché nella registrazione dei dati ho già escluso casi di ripetizione
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
            salva(classe, p);
            break;
        }
        case 4:
            report(classe, c);
            break;
        case 5:
        {
            carica(classe,p, n);
            break;
        }
        case 6:
        {
            int matricola;
            printf("inserisci numero di matricola dello studenta : ");
            scanf("%d", &matricola);
            cerca(classe, c, matricola);
        }
        break;
        case 7:
            visualizzadecrescente(classe, c);
            break;
        default: // se non è uno dei precedenti
            printf("scelta non valida, si chiede di scegliere funzione valida : \n");
        }
        s = menu(); // rinnovare scelta
    }
    printf("Uscita in corso........\n");
}

void salva(Studente *classe, int *p)
{
    int c=*p; //inizializzare valore salvato nel indirizzo puntato da p per comodità
    FILE *fp;
    fp = fopen("studenti.dat", "wb"); //apertura file binario in scrittura
    if (fp == NULL)
    { //controllo
        printf("Errore nel salvare dati\n");
        return;
    }
    size_t flag; //inizializzare indicatore per controllo di scrittura
    flag = fwrite(p, sizeof(int), 1, fp); //si scrive all'inizio valore di studenti registrati per essere usati dopo
    if (flag != 1)
    { //controllo
        printf("Errore scrittura\n");
        fclose(fp); //si ricorda di chiudere file
        return;
    }
    flag = fwrite(classe, sizeof(Studente), c, fp);
    if (flag != c)
    { //controllo
        printf("Errore scrittura\n");
        fclose(fp);
        return;
    }
    fclose(fp);//in qualsiasi caso chiudere il file
    printf("file salvato con successo\n"); //stampa andamento della funzione
    return;
}

void cerca(Studente *classe, int c, int matricola)
{ //in questo caso serve solo valore di c
    // stampa risultato
    printf("ecco la tabella degli studenti corrispondenti\n"); //in realtà può esistere al più 1
    printf("%-10s %-10s %-10s %-20s %-10s\n", "matricola", "nome", "cognome", "numero di esami sostenuti", "media");
    for (int i = 0; i < c; i++)
    {
        if (classe[i].matricola == matricola)
        {
            printf("%-10d %-10s %-10s %-20d %-10.2f\n", classe[i].matricola, classe[i].nome, classe[i].cognome, classe[i].num_esami_sostenuti, calcolamedia(classe[i]));
            return; //come detto prima trovato 1 si può uscire dal ciclo
        }
    }
    return;
}

void carica(Studente *classe, int *p, int n)
{
    FILE *fp;
    fp = fopen("studenti.dat", "rb"); //apertura file binario da leggere
    if (fp == NULL)
    { //controllo
        printf("Errore apertura file\n");
        return;
    }
    size_t flag; //dichiarazione variabile per controllo lettura
    flag = fread(p, sizeof(int), 1, fp); //lettura quantità di studenti all'inizio
    if (flag != 1)
    { //controllo
        printf("Errore Lettura file\n");
        fclose(fp);
        return;
    }
    if (*p > n)
    { //controlla di non superare spazio allocato dinamicamente all'inzio
        printf("File contiene numero di studenti superiori allo numero definito all'inizio  \n");
        fclose(fp);
        //si può fare pure una funzione di riallocazione in questo caso, ma non ho voglia
        return;
    }
    flag = fread(classe, sizeof(Studente), *p, fp);
    if (flag != *p)
    { //controllo
        printf("Errore Lettura file\n");
        fclose(fp);
        return;
    }
    fclose(fp); //infatti mi sono scordato di chiudere il file
    printf("File caricato correttamente\n");
    return;
}

void report(Studente *classe, int c)
{
    FILE *fp;
    fp = fopen("report_studenti.txt", "w"); //apertura file txt in scrittura
    if (fp == NULL)
    { //controllo
        printf("Errore apertura file");
        return;
    }
    if (c == 0)
    { //evitare di fare lavori inutili e divisione per 0
        fprintf(fp, "non ci sono studenti registrati\n");
        fclose(fp);
        return;
    }
    // stampa risultato
    fprintf(fp, "ecco la tabella degli studenti\n");
    fprintf(fp, "%-10s %-10s %-10s %-20s %-10s\n", "matricola", "nome", "cognome", "numero di esami sostenuti", "media");
    float sum = 0; //inizializzazione variabile per media generale
    for (int i = 0; i < c; i++)
    { // stampa in modo tabulato
        sum = sum + calcolamedia(classe[i]); //sfeuttare direttamente questo ciclo per summa e media generale
        fprintf(fp, "%-10d %-10s %-10s %-20d %-10.2f\n", classe[i].matricola, classe[i].nome, classe[i].cognome, classe[i].num_esami_sostenuti, calcolamedia(classe[i]));
    }
    int ind = trovamediaalta(classe, c);
    fprintf(fp, "Lo studente %s %s ha la media più alta : %.2f\n", classe[ind].nome, classe[ind].cognome, calcolamedia(classe[ind]));
    int cont = 0; //inizializzazione contatore per quantità di studenti registrati tutti gli 6 esami
    for (int i = 0; i < c; i++)
    { //in realtà posso anche mettere insieme a quello di sopra, però ormai....
        if (classe[i].num_esami_sostenuti == 6)
        {
            cont++;
        }
    }
    //scrivere risultato sul file
    fprintf(fp, "%.2f %% di studenti hanno sostetuno tutti 6 esami\n", (float)cont * 100 / c);
    fprintf(fp, "La media generale dei studenti è %.2f\n", sum / c);
    fclose(fp); //chiusura file
    return;
}
