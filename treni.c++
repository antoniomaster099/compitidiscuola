/*Realizza un programma che consenta di consultare gli orari di una tratta ferroviaria. Realizza una struct
 fermata che contenga il nome di una stazione e ora e minuti in cui è previsto l’arrivo del treno. Definisci un
  array con N variabili di tipo fermata, che rappresenta il viaggio di un treno (ciascun elemento dell’array è una tappa del viaggio,
   quindi gli orari inseriti devono essere progressivi). Realizza infine un procedimento che consenta di inserire i nomi di due stazioni e di calcolare il numero di ore e minuti 
   di durata del viaggio tra le due stazioni
n.b. si possono convertire le  ore in minuti*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct fermata {
    string nome;
    int ora;
    int minuti;
};
void caricafermata(vector<fermata>&viaggio);
void calcolodurata(vector<fermata>& viaggio);
int main() {
    vector<fermata> viaggio;
    caricafermata(viaggio);
    calcolodurata(viaggio);
    return 0;
}



void caricafermata(vector<fermata>&viaggio) {
    int N;
    cout << "Quante fermate vuoi inserire? ";
    cin >> N;
    viaggio.resize(N);
    for (int i = 0; i < N; i++) {
        fermata f;
        cout << "Inserisci prima  il nome della stazione poi  l'ora di arrivo (0-23) e i minuti di arrivo (0-59) per la fermata " << i + 1 << ": ";
        cin >> f.nome >> f.ora >> f.minuti;
        viaggio[i] = f;
    }
}

void calcolodurata(vector<fermata>& viaggio){
    cout << "Inserisci il nome della stazione di partenza: ";
    string partenza;
    cin >> partenza;
    cout << "Inserisci il nome della stazione di arrivo: ";
    string arrivo;
    cin >> arrivo;

    int cOre;
    int cMinuti;
    auto ipartenza= find_if(viaggio.begin(), viaggio.end(), [&partenza](const fermata& f) { return f.nome == partenza; });/*find_if restituisce un iteratore al primo elemento che soddisfa la condizione specificata, in questo caso la stazione di partenza
    si utilizza una lambda che si scompone cosi [&partenza] e il raggio d azione della lambda dicee con quale variabile esterna alla lambda si vuole lavorare, in questo caso partenza,
    (const fermata& f) è il parametro della lambda , che rappresenta un elemento del vettore viaggio, in questo caso un iteratore
    {return f.nome == partenza;} è la condizione che viene verificata per ogni elemento del vettore viaggio, in questo caso si confronta il nome della stazione con la stazione di partenza inserita dall'utente
    */
    auto iarrivo= find_if(viaggio.begin(), viaggio.end(), [&arrivo](const fermata& f) { return f.nome == arrivo; });
    while(iarrivo == viaggio.end() || ipartenza == viaggio.end()){//find_if restituisce v.end()(dove v sta per vettore) se non trova l'elemento, quindi se una delle due stazioni non è presente nel viaggio chiedo di inserire nuovamente i nomi delle stazioni
        cout << "Una o entrambe le stazioni inserite non sono presenti nel viaggio, inserisci nuovamente i nomi delle stazioni: \n ";
        cin >> partenza >> arrivo;
        ipartenza= find_if(viaggio.begin(), viaggio.end(), [&partenza](const fermata& f) { return f.nome == partenza; });
        iarrivo= find_if(viaggio.begin(), viaggio.end(), [&arrivo](const fermata& f) { return f.nome == arrivo; });
    }
    while(iarrivo <=ipartenza){//controllo che la stazione di arrivo sia successiva a quella di partenza, se non lo è chiedo di inserire nuovamente la stazione di arrivo
        cout << "La stazione di arrivo deve essere successiva alla stazione di partenza, inserisci nuovamente il nome della stazione di arrivo: \n ";
        cin >> arrivo;
        iarrivo= find_if(viaggio.begin(), viaggio.end(), [&arrivo](const fermata& f) { return f.nome == arrivo; });
    }
    cOre= (*iarrivo).ora - (*ipartenza).ora;//faccio la differenza tra le ore di arrivo e partenza
    cMinuti= (*iarrivo).minuti - (*ipartenza).minuti;//faccio la differenza tra i minuti di arrivo e partenza
    if(cMinuti<0){
        cMinuti+=60;
        cOre--;
    } 
    cout << "La durata del viaggio tra " << partenza << " e " << arrivo << " è di " << cOre << " ore e " << cMinuti << " minuti.\n";
}
