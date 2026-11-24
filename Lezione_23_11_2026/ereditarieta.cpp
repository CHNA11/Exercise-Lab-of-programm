# include <iostream>

int main(){
    /*
    assente

    Ereditarietà è essenzialmente figlio del caso base, con ereditarietà su attributi publici e pretected, e analgolamente i metodi.
    Per definire si costruisca prima il caso base, poi quelle derivate, e deve essere inizializzate chiamando costruttore della clesse genitore.
    Si ricorda caso derivato usare inizializer list.
    Per distruggere si usa ordine inverso, prima classe derivate, poi classe base.
    Se una classe è pensata per essere ereditata, distruttore deve essere virtual.
    Metodi possono essere override, che distingue per classe di accesso, però può comunque accedere metodo originale e aggiunta di qualcos'altro.
    modo migliore è usare override per definire esplicitamente override.

    Overloar dei metodi:
    si può definire metodi con stessi nome ma parametri diversi, facendo pure tornare risultati diversi.

    Si usa ereditarietà quando :
    ha un relazione di categoria(gatto/animale),
    è una specializzazione,
    neccessità di polimorfismo.
    Si usa composizione quando :
    ha un relazione di avere(motore di un auto);
    riutilizzare funzionalità senza tipo di
    maggiore flessibilità

    Distinzione del codice:
    generalmente si suddivide in :
    - header file.h per dichairazioni, prototipo dellle funzioni.
    - source file.cpp per implementazioni dei metodi.
    - main.cpp funzioni di avvio com import degli header.

    per header, si inizia con " #pragma once " che protegge ed evita errore di inclusione multipla
    per source e main si usa "#include "header.h"".
    per source definisce metodo con nomeclasse::nometodo(parametri){}.
    per compilare su Vscode si usa "g++ main.cpp nomesource.cpp -o programma" sul terminale
    */
   return 0;
}