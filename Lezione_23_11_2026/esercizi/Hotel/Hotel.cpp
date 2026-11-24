#include "Hotel.h"
#include <iostream>
#include <vector>

using namespace std;
Data::Data(int gg, int mm, int aaaa)
{
    if ((gg < 1 || gg > 31) || (mm < 1 || mm > 12) || ((mm == 2 || mm == 4 || mm == 6 || mm == 9 || mm == 11) && gg == 31) || ((aaaa % 4) != 0 && mm == 2 && gg == 29))
    {
        cerr << "Data non valida" << endl;
    }
    else
    {
        giorno = gg;
        mese = mm;
        anno = aaaa;
    }
}
void Data::stampaData() const
{
    cout << giorno << "/" << mese << "/" << anno << endl;
    return;
}
int Data::getGiorno() const
{
    return giorno;
}
int Data::getMese() const
{
    return mese;
}
int Data::getAnno() const
{
    return anno;
}
int Data::confrontaData(const Data &altra)
{
    if (anno == altra.getAnno())
    {
        if (altra.getMese() == mese)
        {
            if (altra.getGiorno() == (giorno + 1))
            {
                return -1;
            }
            else if (altra.getGiorno() == (giorno - 1))
            {
                return 1;
            }
            else
            {
                return -2;
            }
        }
        else if (altra.getMese() != 12 && mese == (altra.getMese() + 1))
        {
            if ((altra.getMese() % 2) == 1 && altra.getMese() < 8)
            {
                if (giorno == 1 && altra.getGiorno() == 31)
                {
                    return 1;
                }
                else if (mese == 3)
                {
                    if ((giorno == 1 && altra.getGiorno() == 28 && anno % 4 != 0) || (giorno == 1 && altra.getGiorno() == 29 && anno % 4 == 0))
                    {
                        return 1;
                    }
                }
                else
                {
                    return -2;
                }
            }
            else if (((altra.getMese() % 2) == 0) && altra.getMese() > 7)
            {
                if (giorno == 1 && altra.getGiorno() == 31)
                {
                    return 1;
                }
                else
                {
                    return -2;
                }
            }
        }
        else if (altra.getMese() != 1 && mese == (altra.getMese() - 1))
        {
            if ((altra.getMese() % 2) == 1 && altra.getMese() < 8)
            {
                if (giorno == 30 && altra.getGiorno() == 1)
                {
                    return -1;
                }
                else
                {
                    return -2;
                }
            }
            else if (((altra.getMese() % 2) == 0) && altra.getMese() > 7)
            {
                if (mese == 7)
                {
                    if (giorno == 31 && altra.getGiorno() == 1)
                    {
                        return -1;
                    }
                }
                else if (giorno == 30 && altra.getGiorno() == 1)
                {
                    return -1;
                }
                else
                {
                    return -2;
                }
            }
        }
    }
    else if (altra.getAnno() == (anno + 1))
    {
        if ((mese == 12 && altra.getAnno() == 1) && (giorno == 31 && altra.giorno == 1))
        {
            return -1;
        }
        else
        {
            return -2;
        }
    }
    else if (altra.getAnno() == (anno - 1))
    {
        if ((mese == 1 && altra.getAnno() == 12) && (giorno == 1 && altra.giorno == 31))
        {
            return 1;
        }
        else
        {
            return -2;
        }
    }
}

Camera::Camera(int numCam, double prezz, int numPos) : numeroCamera(numCam), prezzoPerNotte(prezz), numeroPosti(numPos), occupata(false)
{
    cout << "Camera costruita correttamente" << endl;
}
double Camera::calcolaPrezzoTotale(int notti) const
{
    return prezzoPerNotte * notti;
}
void Camera::stampaDettagli() const
{
    cout << "il numero di camera è " << numeroCamera << " con " << numeroPosti << " posti ad " << prezzoPerNotte << " euro per notte" << endl;
}
void Camera::prenota()
{
    occupata = true;
}
void Camera::libera()
{
    occupata = false;
}
bool Camera::isOccupata() const
{
    return occupata;
}
int Camera::getNumeroCamera()
{
    return numeroCamera;
}
double Camera::getPrezzoPerNotte()
{
    return prezzoPerNotte;
}
int Camera::getNumeroPosti()
{
    return numeroPosti;
}

double CameraSingola::calcolaPrezzoTotale(int notti) const
{
    return prezzoPerNotte * notti + 20;
}
void CameraSingola::stampaDettagli() const
{
    Camera::stampaDettagli();
    cout << " Con la visione del mare" << endl;
}

double Suite::calcolaPrezzoTotale(int notti) const
{
    int sum = Camera::calcolaPrezzoTotale(notti);
    if (jacuzzi == true)
    {
        sum = sum + 50;
    }
    if (servizioIncamera == true)
    {
        sum = sum + 20;
    }
    return sum;
}
void Suite::stampaDettagli() const
{
    Camera::stampaDettagli();
    if (jacuzzi == true)
    {
        cout << " con jacuzzi ";
    }
    else
    {
        cout << " senza jacuzzi ";
    }
    if (servizioIncamera == true)
    {
        cout << "e con servizio in camera" << endl;
    }
    else
    {
        cout << "e senza servizio in camera" << endl;
    }
}

int Prenotazione::getNotti() const
{
    int diffanno = dataFine.getAnno() - dataInizio.getAnno();
    int diffmese = dataFine.getMese() - dataInizio.getMese();
    int diffgiorno = dataFine.getGiorno() - dataInizio.getGiorno();
    return (diffanno * 365) + (diffmese * 30) + diffgiorno;
}
void Prenotazione::stampaPrenotazione() const
{
    cout << "il codice di prenotazione è " << codicePrenotazione << " per il cliente " << nomeCliente << endl;
    cout << "Con la camera ";
    camera->stampaDettagli();
    cout << "Dal ";
    dataInizio.stampaData();
    cout << " al ";
    dataFine.stampaData();
    cout << endl;
}
double Prenotazione::calcolaCostoTotale() const
{
    return camera->calcolaPrezzoTotale(getNotti());
}

void Hotel::aggiungiCamera(Camera *c) {
    camera.push_back(c);
}
void Hotel::visualizzaCamereDisponibili() const {
    for (const Camera* c:camera){
        if(!c->isOccupata()){
            c->stampaDettagli();
        }
    }
}
void Hotel::creaPrenotazione(Prenotazione prenotazione) {
    prenotazioni.push_back(prenotazione);
}
void Hotel::cancellaPrenotazione() {}
double Hotel::calcolaIncassoTotale() const {}
void Hotel::stampaStatistiche() const {}
