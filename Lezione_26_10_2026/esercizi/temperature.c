#include <stdio.h>
#include <stdlib.h>
//dichiarazione prototipo delle funzione neccessarie
int richiesta();
void inserimento(FILE *fp, int n);
float *caricafile(FILE *fp, int n);
float media(float *temperature, int n);
int max(float *temperature, int n);
int min(float *temperature, int n);
int numsup(float *temperature, int n);

int main()
{
    int n = richiesta(); //inizializzazione numero di inserimento richiamando funzione di inserimento
    FILE *fp = fopen("temperature.txt","w+"); //apertura file con w+ per lettura e scrittura, e in caso neccessario creare il file
    if (fp == NULL) //controllo apertura
    {
        printf("Errore apertura file.\n");
        return 1;
    }
    inserimento(fp, n); //richiama funzione di inserimento dati nel file
    rewind(fp); //ricominciare da inizio per lettura
    float *temperature = caricafile(fp, n); //salvare dati dal file con puntatore
    //stampa risultati
    printf("la media delle temperature trovate nel file è : %.2f\n", media(temperature, n));
    printf("il massimo delle temperature trovate nel file è : %.2f\n", temperature[max(temperature, n)]);
    printf("ll minimo delle temperature trovate nel file è : %.2f\n", temperature[min(temperature, n)]);
    printf("quantità di numeri con temperatura superiore a 25C trovate nel file è : %d\n", numsup(temperature, n));
    fclose(fp); //chiusura file
    free(temperature); //liberare dal allocazione dinamico nella funzione caricafile
    return 0;
}

int richiesta()
{
    int n; //dichiarazione numero di inserimento
    do
    {
        printf("inserisci quante temperature giornaliere vuole registrare con massimo 31 : ");
        scanf("%d", &n);
    } while (n < 1 || n > 31); //controllare che sia un numero aspettato
    return n;
}

void inserimento(FILE *fp, int n)
{
    float temp; //dichiarazione variabile temporanea
    for (int i = 0; i < n; i++)
    {
        printf("inserisci temperatura del giorno nella posizione %d : ", i + 1);
        scanf("%f", &temp); //legge valore da tastiera e salvare in temp
        fprintf(fp, "%.2f ", temp); //stampare questo valore salvato in temp nel file, con 2 cifre dopo virgola
        if ((i + 2) % 7 == 1)
        {
            fprintf(fp, "\n"); //generare rige con 7 elementi, evitando di lasciare spazio a prima riga
        }
    }
}

float *caricafile(FILE *fp, int n)
{
    float *temperature = (float *)malloc(n * sizeof(float)); //allocazione dinamica di vettore dei dati
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%f", &temperature[i]); //leggere dati dal file
    }
    return temperature; //ritornare puntatore
}

float media(float *temperature, int n)
{
    float somma = 0; //inizializzare variabile per somma, si ricorda che sono di tipo float
    for (int i = 0; i < n; i++)
    {
        somma = somma + temperature[i]; //aggiungere valore nella somma
    } 
    return somma / n; //si assicura che durante inserimento non può inserire 0
}

int max(float *temperature, int n)
{
    int indmax = 0; //classico metodo di ricerca per max
    for (int i = 0; i < n; i++)
    {
        if (temperature[indmax] < temperature[i])
        {
            indmax = i;
        }
    }
    return indmax;
}

int min(float *temperature, int n)
{
    int indmin = 0; //analogamente da max
    for (int i = 0; i < n; i++)
    {
        if (temperature[indmin] > temperature[i])
        {
            indmin = i;
        }
    }
    return indmin;
}

int numsup(float *temperature, int n)
{
    int cont = 0; //inzializzazione contatore per temperature superiore a 25C
    for (int i = 0; i < n; i++)
    {
        if (temperature[i] > 25)
        {
            cont++; //incremento
        }
    }
    return cont;
}