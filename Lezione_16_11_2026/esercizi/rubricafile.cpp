#include <iostream>
#include <fstream> //inclusione per file
#include <string> //inclusione per stringhe
#include <limits> //inclusione per cin.inore

using namespace std;

//definizione struttura di Nodo per contatto
typedef struct Nodocontatto
{
    string nome;
    string numero;
    Nodocontatto *next;
} Nodocontatto;

//dichiara funzioni per operazione come liste

Nodocontatto *creanodocontatto(string nome, string numero);
Nodocontatto *inserimentocodacontatto(Nodocontatto *testa);
void libera(Nodocontatto *testa);

int main()
{
    //dichiarare una variabile di appoggio per scelta
    int scelta;
    //inizializzare lista di contatto
    Nodocontatto *testa = NULL;
    do
    {
        //stampa le funzionalità
        cout << "Le funzionalità dei contatti sono : " << endl;
        cout << "1. Inserisci un nuovo contatto(nome + numero)." << endl;
        cout << "2. Visualizza tutti i contatti salvati." << endl;
        cout << "3. Salvare contatti in file." << endl;
        cout << "4. Esci." << endl;
        cout << "Inserisci la tua scelta : ";
        cin >> scelta;
        if (scelta != 1 && scelta != 2 && scelta != 3 && scelta != 4)
        {
            // casi non valide
            cout << "Scelta non valida" << endl;
        }
        else if (scelta == 1)
        {
            // inserisce nuovo nodo
            testa = inserimentocodacontatto(testa);
        }
        else if (scelta == 2)
        {
            //apertura file in lettura
            ifstream file("rubrica.txt");
            if (!file.is_open())
            { //controllo
                cerr << "Errore apertura file" << endl;
            }
            else
            {
                string frase;
                cout << "I contatti salvati nel file sono : " << endl;
                while (getline(file, frase))
                { //stampare finché si legge i dati
                    cout << frase << endl;
                }
                file.close(); //chiusura file
            }
        }
        else if (scelta == 3)
        { //apetura file in scrittura
            ofstream file("rubrica.txt");
            if (!file)
            { //controllo
                cerr << "Errore apertura file" << endl;
            }
            else
            { //scrivere dati scorrendo lista fino alla fine
                Nodocontatto *p = testa;
                while (p != NULL)
                {
                    file << p->nome << " " << p->numero << endl;
                    p = p->next;
                }
                cout << "File salvato correttamente" << endl;
                file.close(); //chiusura file
            }
        }
    } while (scelta != 4);
    libera(testa);
}

Nodocontatto *creanodocontatto(string nome, string numero)
{
    //allocazione dinamica e assegnare valori
    Nodocontatto *nuovo_contatto = new Nodocontatto;
    nuovo_contatto->nome = nome;
    nuovo_contatto->numero = numero;
    nuovo_contatto->next = NULL;
    return nuovo_contatto;
}

Nodocontatto *inserimentocodacontatto(Nodocontatto *testa)
{
    //dichiarare variabili di appoggio
    string nome;
    string numero;
    //chiedere input
    cout << "Inserisci il nome del nuovo contatto : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nome);
    cout << "Inserici il numero di contatto corrispondente : ";
    getline(cin, numero);
    //generare nodo con dati corrispondenti
    Nodocontatto *nuovo_nodo = creanodocontatto(nome, numero);
    if (testa == NULL)
    { //gestire caso lista nulla
        cout << "Contatto salvato correttamente" << endl;
        return nuovo_nodo;
    }
    else
    { //scorrere fino alla fine
        Nodocontatto *p = testa;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = nuovo_nodo; //assegnare nuovo nodo nella coda
        cout << "Contatto salvato correttamente" << endl;
        return testa;
    }
}

void libera(Nodocontatto *testa)
{
    //metodo di liberazione lista standard
    Nodocontatto *temp;
    while (testa != NULL)
    {
        temp = testa;
        testa = testa->next;
        delete temp;
    }
    cout << "Lista liberato correttamente" << endl;
    return;
}