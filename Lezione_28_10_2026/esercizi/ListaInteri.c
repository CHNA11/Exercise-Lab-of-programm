#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valore;
    struct Nodo *next;
} Nodo;

Nodo *creaNodo(int valore)
{
    Nodo *nuovo = (Nodo *)malloc(sizeof(Nodo));
    if (nuovo == NULL)
    {
        printf("Errore di allocazione memoria\n");
        exit(1);
    }
    nuovo->valore = valore;
    nuovo->next = NULL;
    return nuovo;
}

Nodo *inserisciInTesta(Nodo *testa, int valore)
{
    Nodo *nuovo = creaNodo(valore);
    nuovo->next = testa;
    return nuovo;
}

Nodo *inserimento();

int contaElementi(Nodo *testa);
int sommaValori(Nodo *testa);
void liberazione(Nodo *testa);
void stampalista(Nodo *teste);

int main()
{
    Nodo *testa = inserimento();
    liberazione(testa);
    return 0;
}

Nodo *inserimento()
{
    Nodo *testa = NULL;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci numero intero nella posizione %d : ", i + 1);
        scanf("%d", &temp);
        testa = inserisciInTesta(testa, temp);
    }
    return testa;
}

void liberazione(Nodo *testa)
{
    stampalista(testa);
    printf("il numero totale di elementi presenti nella lista è : %d\n", contaElementi(testa));
    printf("la somma di tutti i valori presenti nella lista è : %d\n", sommaValori(testa));
    Nodo *p = testa;
    while (p != testa)
    {
        Nodo *temp = p;
        p = p->next;
        free(temp);
    }
    printf("Lista deallocata correttamente\n");
}

int contaElementi(Nodo *testa)
{
    int cont = 0;
    Nodo *p = testa;
    while (p != NULL)
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
    while (p != NULL)
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
    while (p != NULL)
    {
        printf("%d -> ", p->valore);
        p = p->next;
    }
    printf("NULL\n");
    return;
}