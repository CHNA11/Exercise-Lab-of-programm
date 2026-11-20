# include <iostream>
# include <vector>

using namespace std;

class Studente{
    //attributi privati
    private:
    string nome;
    string cognome;
    int matricola;
    std::vector<int> voti; //voti come vettore, senza bisogno di liberazione manuale
    int numeroVoti;
    public:
    //costruttore
    Studente(string s1, string s2, int n) : nome(s1), cognome(s2), matricola(n){
        numeroVoti=0;
        cout << "Studente costruito con successo " << endl;
    }
    //funzione che aggiunge un voto
    int aggiungiVoto(int voto){
        if(voto<18 || voto >30){
            return 0;
        }
        else{
            voti.push_back(voto);
            numeroVoti++;
            return 1;
        }
    }
    //funzione che calcola media, nel caso senzavoti restituisce 0
    float calcolaMedia() const{
        if(numeroVoti==0){
            return 0;
        }
        else {
            int sum=0;
            for(int i=0; i<numeroVoti; i++){
                sum=sum+voti[i];
            }
            return (float)sum/numeroVoti;
        }
    }
    //funzioni getter
    int getNumeroVoti() const{
        return numeroVoti;
    }
    string getNome() const{
        return nome;
    }
    string getCognome() const{
        return cognome;
    }
    int getMatricola() const{
        return matricola;
    }
    //funzioni stampa
    void stampaVoti() const{
        if(numeroVoti==0){
            cout << "Non ci sono voti presenti" << endl;
            return;
        }
        cout << "I voti sono : ";
        for (int i=0; i<numeroVoti; i++){
            cout << voti[i] << " ";
        }
        cout << endl;
        return;
    }
    void stampaInfo() const{
        cout << "Lo studente " << nome << " " << cognome << " con numero di matricola " << matricola << " ha " << numeroVoti << " voti" << endl;
        if(numeroVoti>0){
            stampaVoti();
        }
        cout << "E ha la media " << calcolaMedia() << endl;
        return;
    }
};

int main(){
    //costruire un studente
    Studente s1("Renhao","Chen",130368);
    int voto;
    //chiedere qualche voti
    int i=0;
    do{
        cout << "Inserisci un voto : ";
        cin >> voto;
        if(s1.aggiungiVoto(voto)!=0){
            i++;
        };
    } while (i<5);
    //stampa le informazioni
    cout << "La media dei voti è : " << s1.calcolaMedia() << endl;
    s1.stampaInfo();
    return 0;
}
