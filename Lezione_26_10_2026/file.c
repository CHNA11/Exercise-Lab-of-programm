# include <stdio.h>
int main(){
    /*
    con i file riusciamo a salvare delle informazioni, non spesso viene usato, rispetto a Database
    che è molto più comodo, ma ci sono ancora ambienti vecchi che utilizzano file
    obiettivo è fermare e ricominciare da una parte, oppure salvataggio di dati permanenti
    utile per scambiare informazioni in piattaforma non connessi.
    In linguaggio c, file è una sequenza di byte, avvia accesso con un string di dati
    Abbiamo bisogno di stdio.h, sopratutto FILE è un tipo di dato già esistente, rappresenta un tipo di file aperto
    apriamo un file, ritorna un puntatore riferito al file, come se fosse un segnalibro.
    Con 3 funzioni:
    leggere, scrivere e chiudere.
    Tutto ciò che apro devono essere chiuso.
    Se file non è aperto correttamente viene ritornato con un risultato.
    In generale si usa variabile fp per file pointer.
    Apertura e chiusura: Aprire con fopen e ci restituisce un puntatore, con if NULL si controlla.
    ci sono diversi modalità di apertura(su dispenser), e si chiude con fclose.
    la modalità più semplice è lettura, per aprirlo in lettura bisogna prima esistere il file, altrimenti
    ci dà errore.
    con w si crea o sovrascrive il file, cioè se ci sono già informazione sul file, se perde tutte
    con a si continua a scrivere.
    r + ammette di lettura e scrivere, ma chiede esistenza.
    Attenzione ad aprire in modo opportuno, per evitarlo casini.
    puntatore è di tipo FILE,
    fp=fopen(path(con nome),w);
    in teoria senza path si salva su dove si trova il programma
    ogni volta si ricorda di controllare
    ....
    fp=fclose(path);
    problema del path non è sempre vero, si consiglia di dare path completo.
    Lettura e scrittura:
    esistono diverse metodologie:
    fprintf, fscanf, richiede prima puntatore del file, stampa e legge valori dal file
    fputse, fgets, fputc.
    fputse è scrive una stringa nel file
    fgets legge stringa, è la parte molto contorta.
    fputc, fgetc si legge per singolo carattere.
    Scrive sul file tramite fprintf
    molto simile al printf.
    fputs, scrittura non ha formattazione, direttamente caratteri, si usa solo quando ho dati formattati
    o solamente stringa.
    Lettura con fscanf, Assumiamo che dati ho salvati su un file, aprò in lettura, fscanf restituisce numero di elementi letti.
    fgets, sempre in lettura, legge una riga intera, spazi inclusi, se si ripete , finisce finché arriva endfile
    termina automaticamente, ma se ci fosse troppo contenuti, se avanza mette automaticamente \n
    così non dà errore, allo stesso tempo perdiamo controllo
    fscanf si usa per dati tabellati, separati con spazi
    fgets serve per un unico testo.
    Fgets può usare anche per leggere dati da tastiera, legge tutto fino a newline o eof
    Attenzione: Fgets legge anche \n e \o , che in generale non deve essere
    si ripulisce, con funzione specifica(su dispenser), neccessariamente.
    quando mischia utilizzo fscanf e fgets, intercambia, neccessariamente ripulire buffer con questo funzione.
    è un difetto dello c, bisogna essere abituato

    File Binari

    file molto più strutturato, serve per strutture di dati, ci dà possibilità di accesso diretto
    esempio: ho un testo, che non è detto di essere strutturato in modo computazionale, invece per file
    binari tutti i dati sono strutturati, so la loro distanza e spazi ecc.
    richiede specificazione b
    sizet, fwrite, flead
    richiede puntatore di grandezza per array
    sizet ci dice grandezza di questo tipo dato.(quanti byte occupa una struttura)
    numero di elementi di strutture da fare
    fp puntatore di file
    non è tipo void, ristituisce sizet, numero di elementi letti e scritti, facile da controllo.
    */
   return 0;
}