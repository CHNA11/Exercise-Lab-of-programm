#include <stdio.h>
#include <stdlib.h> //per allocazione dinamico

//definizione delle strutture richieste
typedef struct
{
    int numero_fila;
    int numero_posto;
    int occupato;
} Posto;

typedef struct
{
    char nome_sala[30];
    Posto **posti;
    int num_file;
    int posti_per_fila;
} Sala;

typedef struct
{
    char nome_cliente[50];
    Sala *sala;
    int fila;
    int posto;
} Prenotazione;

//dichiarazione funzione prototipe
int richnumfila();
int richnumpos();
Sala creazionesala(int fila);
Sala inzializzazionesala(Sala sala, int fila, int posto);
int menu();
void scelta(Sala sala, int s, int fila, int posto);
void visualizzazione(Sala sala, int fila, int posto);
Prenotazione prenotare(Sala sala, int fila, int posto);
void cancella(Sala sala, int fila, int posto);
void perc(Sala sala, int fila, int posto);
void primoposto(Sala sala, int fila, int posto);
void liberazione(Sala sala, int fila);

int main()
{
    int n_fila = richnumfila(); //inizializzazione numero di fila inserita dal utente
    int n_posti = richnumpos(); //inizializzazione numero di posti per ogni fila
    Sala sala = inzializzazionesala(creazionesala(n_fila), n_fila, n_posti); // inizializzazione della sala con due funzioni
    scelta(sala, menu(), n_fila, n_posti); //funzione che richiama il menu e chiede scelti dell'utente
    liberazione(sala, n_fila); //funzione definito per liberazione delle allocazione dinamico
    return 0;
}

int richnumfila()
{
    int n; //dichiarazione di variabile per numero di fila
    do
    { //inserimento
        printf("inserisci numero di fila nella sala : ");
        scanf("%d", &n);
    } while (n < 1); //controllo
    return n;
}

int richnumpos()
{ //analogo a quello della numero di fila
    int n;
    do
    {
        printf("inserisci numero di posti per ogni fila : ");
        scanf("%d", &n);
    } while (n < 1); //controllo
    return n;
}

Sala creazionesala(int fila)
{
    Sala sala; //dichiarazione variabile tipo sala
    printf("inserisci nome della sala : ");
    scanf("%s", sala.nome_sala);//inserimento nome
    sala.posti = (Posto **)malloc(fila * sizeof(Posto *)); //allocazione dinamico nei campi dei posti
    if (sala.posti == NULL) //controllo di allocazione
    {
        printf("allocazione insuccesso");
        exit(1);
    }
    sala.num_file = fila; //assegnazione numero di fila
    return sala;
}

Sala inzializzazionesala(Sala sala, int fila, int posto)
{
    for (int i = 0; i < fila; i++) //ciclo per allocazione dinamico ad ogni fila
    {
        sala.posti[i] = (Posto *)malloc(posto * sizeof(Posto));
        if (sala.posti[i] == NULL) //controllo di ogni fila durante allocazione
        {
            printf("allocazione insuccesso");
            exit(1);
        }
        for (int j = 0; j < posto; j++)
        { //assegnazione valori di ogni posti
            sala.posti[i][j].numero_fila = i;
            sala.posti[i][j].numero_posto = j;
            sala.posti[i][j].occupato = 0;
        }
    }
    return sala;
}

void visualizzazione(Sala sala, int fila, int posto)
{ //stampa mappa della sala
    printf("mappa della sala con X per occupato, O per libero : \n");
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < posto; j++)
        {
            if (sala.posti[i][j].occupato == 1)
            {
                printf("%s ", "X"); //stampa per simbolo quello occupato
            }
            else
            {
                printf("%s ", "O"); //simbolo di posto libero
            }
        }
        printf("\n"); //andare a capo dopo ogni fila
    }
}

Prenotazione prenotare(Sala sala, int fila, int posto)
{
    Prenotazione p1; //dichiarazione variabile di prenotazione
    do
    {
        printf("inserisci il numero di fila e di posti di cui si intende prenotare : ");
        scanf("%d %d", &p1.fila, &p1.posto);
    } while ((p1.fila < 1 || p1.fila > fila) || (p1.posto < 1 || p1.posto > posto)); //controllo valore legale
    if (sala.posti[p1.fila - 1][p1.posto - 1].occupato == 1)
    {// controlla se posto è libero
        printf("il posto corrispondente è occupato\n");
        p1.sala = NULL; //segnare nullo per controllo nella funzione scelta
        return p1;
    }
    else
    {
        p1.sala = &sala;
        printf("il posto corrispondente è libero, insersci il nome del cliente : ");
        scanf("%s", p1.nome_cliente);//richiesta input
        sala.posti[p1.fila - 1][p1.posto - 1].occupato = 1;
        return p1;
    }
}

void cancella(Sala sala, int fila, int posto)
{
    int n_fila;
    int n_posto;
    int flag = 0;
    do
    {
        do
        { //richiesta di dati
            printf("inserisci numero di fila e del posto di cui si intende cancellare prenotazione : ");
            scanf("%d %d", &n_fila, &n_posto);
        } while ((n_fila < 1 || n_fila > fila) || (n_posto < 1 || n_posto > posto)); //controlla
        if (sala.posti[n_fila - 1][n_posto - 1].occupato == 1) //controlla se esiste prenotazione
        {
            sala.posti[n_fila - 1][n_posto - 1].occupato = 0;
            printf("cancellazione andato con successo\n");
        }
        else //caso in cui non è prenotato
        {
            printf("il posto corrsipondente non è stato prenotato\n");
        }
        printf("per ripetere cancellazione inserisci 0, altrimenti inserisci 1\n");
        scanf("%d", &flag);
    } while (flag != 1);//controllo per ripetizione
}

void perc(Sala sala, int fila, int posto)
{
    int cont = 0;//inizializzazione dei contatori
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < posto; j++)
        {
            if (sala.posti[i][j].occupato == 1)
            {
                cont++; //conta quanti posti sono occupati
            }
        }
    }
    printf("ci sono %.2f %% di posti occupati\n", ((float)cont / (fila * posto)) * 100); //fare calcolo in printf
}

void primoposto(Sala sala, int fila, int posto)
{
    Prenotazione p1;
    int ind = 0; //indicatrice per vedere se ha già trovato un posto libero
    if (ind == 1)
    {
        return;
    }
    else
    {
        for (int i = 0; i < fila; i++)
        {
            if (ind == 1)
            {
                return;
            }
            else
            {
                for (int j = 0; j < posto; j++)
                {
                    if (sala.posti[i][j].occupato == 0)
                    { //dire quale sia primo posto libero
                        printf("il primo posto libero disponibile è quello della fila %d numero %d\n", i + 1, j + 1);
                        printf("se desideri prenotare questo posto inserisci 1, altrimenti 0 : ");
                        scanf("%d", &ind); //chiedere se desidera prenotare questa posto
                        if (ind == 1)
                        {
                            printf("inserisci nome del cliente : ");
                            scanf("%49s", &p1.nome_cliente);
                            sala.posti[i][j].occupato = 1;
                            ind = 1; //indicatrice che ha già prenotato questo posto
                            return;
                        }
                    }
                }
            }
        }
    }
}

int menu()
{
    int s;//dichiarazione variabile che registra scelta
    printf("i funzioni possibili sono i seguenti : \n");
    printf("1.Visualizzare la mappa della sala\n");
    printf("2.Prenotare un posto\n");
    printf("3.Cancellare una prenotazione\n");
    printf("4.Visualizzare la percentuale di occupazione della sala\n");
    printf("5.Cercare il primo posto \n");
    printf("6.Uscire dal menu\n");
    printf("inserisci la tua scelta : ");
    scanf("%d", &s); //chiedere scelta dal utente
    return s;
}

void scelta(Sala sala, int s, int fila, int posto)
{
    while (s != 6) // ha senso solo se non ha scelto uscire
    {
        switch (s)
        { //vari casi della scelta
        case 1:
            visualizzazione(sala, fila, posto);
            break;
        case 2:
        {
            Prenotazione p1 = prenotare(sala, fila, posto);
            if (p1.sala == NULL) //se con funzione prenota ha dato questo risultato nullo, è andata male la prenotazione
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

void liberazione(Sala sala, int fila)
{ //liberazione delle allocazione dinamico
    for (int i = 0; i < fila; i++)
    {
        free(sala.posti[i]);
    }
    free(sala.posti);
}