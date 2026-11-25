# include "Hotel.h"
# include <iostream>

using namespace std;

int main(){
    //costruzione hotel
    Hotel hotel("Nan");
    //costruzione camere
    Camera c1(1,2,3);
    CameraSingola c2(2,2,2,true);
    Suite c3(3,4,2,true,2,true);
    Suite c4(4,8,8,true,4,false);
    Suite c5(5,3,4,false,2,false);
    //aggiungere camere nel hotel
    hotel.aggiungiCamera(&c1);
    hotel.aggiungiCamera(&c2);
    hotel.aggiungiCamera(&c3);
    hotel.aggiungiCamera(&c4);
    hotel.aggiungiCamera(&c5);
    //costruire prenotazione
    Prenotazione p1("Renhao",&c3,Data(21,11,2026),Data(23,11,2026));
    Prenotazione p2("Kizuna", &c4,Data(20,11,2026), Data(25,11,2026));
    Prenotazione p3("Diana", &c2, Data(10,10,2026),Data(25,10,2026));
    //aggiungere prenotazione nel hotel
    hotel.creaPrenotazione(p1);
    hotel.creaPrenotazione(p2);
    hotel.creaPrenotazione(p3);
    //stampa camere disponibili in hotel
    hotel.visualizzaCamereDisponibili();
    //stampa informazioni del hotel
    p1.stampaPrenotazione();
    p2.stampaPrenotazione();
    p3.stampaPrenotazione();
    //stampa informazione statistica del hotel
    hotel.stampaStatistiche();
    return 0;
}