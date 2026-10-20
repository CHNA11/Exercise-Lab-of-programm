# include <stdio.h>
int main(){
    //parte di struttura è vicino verso programmazione per oggetti, che non è fatto per c
    //per ora, dichiarazione di dati è possibile solo per dati di stesso tipo, non per casi diversi
    //per esempio una persona, composta da diversi dati: nome, matricola, voti, media dei esami ecc.
    //matrice sono escluse, introduciamo strutture, reazione di dato personalizzato
    //creaiamo un struttura personalizzato, in corrispondenza alla richiesta, in base alle specifiche
    //se non ci sono specifiche si chiede di ragionare sulla struttura
    //dichiara composizione di nuovo tipo e le sue composizioni:
    //studente= nome, età, voto.
    //così c riconosce questa nuova tipologia.
    //esistono array di strutture
    //perché ogni cassella hanno stesso tipo di dato, quello che ho definito prima
    //possono tranquillamente lasciare campo vuoto
    //puntatori con le strutture
    //senza puntatori, è molto inefficiente le strutture
    //puntatore deve essere del tipo studente, se faccio puntare verso una struttura di tipo definito studente
    //utilizzare puntatori per struttre migliora molto efficienza, perché passare direttamente struttura che ha un 
    //tipologia più complesso, se passo puntatori, risparmia molto per lettura.
    //esistono pure allocazione dinamica per strutture.
    //definzione dello struct è meglio definirlo fuori dal main, accessibile a tutti, altrimenti per
    //funzioni che definiscono fuori dal main non riesce a riconoscerlo
    //perciò in generale si definisce in modo globale
    //dichiarazione vera e propria della struttura è meglio farlo dentro al main
    //Typedef, permette di definire una nuova tipologia, evita di richiamare struct ogni volta, sempre più comsigliato
    //dentro alla struttura, si può contenere un'altra struttura, per esempio mettere dentro struttura di studente,
    //mettere un indirizzo che a sua volta è un'altra struttura.
    //così ho struct nidificate
    //attenzione, nome di struttura non può avere stesso nome di variabile
    return 0;
}