/*Dato un file di testo amici.txt, le cui righe rappresentano ciascuna i dati di una persona secondo la seguente struttura:
– cognome
 – nome
 – sesso
– anno di nascita 
 scrivi una funzione che visualizza un record alla volta sul video. 
 Successivamente chiedi all’utente la tipologia di nominativi che vuole visualizzare (solo maschi oppure femmine) ed effettua una ricerca visualizzando solo i record che rispettano questa richiesta.*/
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct persona {
    string cognome;
    string nome;
    string sesso;
    int anno_nascita;
};

void carica(vector<persona>& p);
void visualizza(const vector<persona>& p);
string controllaSesso( string& sesso);
string toLower( string str);
void ricerca(const vector<persona>& p,  string& se);

int main() {
    vector<persona> persone;
    carica(persone);
    visualizza(persone);
    string sesso;
    cout << "Vuoi visualizzare solo maschi o femmine? (m/f): \n";
    cin >> sesso;
    sesso = controllaSesso(sesso);
    ricerca(persone, sesso);
    return 0;
}

void carica(vector<persona>& p){
int n;
cout << "Quante persone vuoi inserire? \n";
cin >> n;
p.resize(n);
    ofstream letper("amici.txt");
    if(letper.is_open())
    {   for(int i = 0; i < n; i++){
        cout << "Inserisci i dati delle persone (cognome nome sesso anno_nascita), termina con 'fine': \n";
        string cognome, nome, sesso;
        int anno_nascita;
        
            cin >> p[i].cognome >> p[i].nome >> p[i].sesso >> p[i].anno_nascita;
            while(p[i].sesso != "m" && p[i].sesso != "f") {
                cout << "Input non valido. Inserisci 'm' per maschi o 'f' per femmine.\n";
                cin >> p[i].sesso;
            }
            letper << p[i].cognome << " " << p[i].nome << " " << p[i].sesso << " " << p[i].anno_nascita << "\n";   
        }
    }
    else{ 
        cout << "Impossibile aprire il file.\n";
    }
    letper.close();
}



void visualizza(const vector<persona>& p){
    ifstream usoper("amici.txt", ios::in);
    if(usoper.is_open()){
        string line;
        while (getline(usoper, line)) {
            cout << line << "\n";
        }
    }
    else {
        cout << "Impossibile aprire il file.\n";
    }
}

string controllaSesso(string& sesso) {
    while(sesso != "m" && sesso != "f") {
        cout << "Input non valido. Inserisci 'm' per maschi o 'f' per femmine.\n";
        cin >> sesso;
    }
    return controllaSesso(sesso);
}

string toLower( string str) {
    for (char& c : str) {
        c = tolower(c);
    }
    return str;
}

void ricerca(const vector<persona>& p,  string& se) {
    for( auto& pers : p) {
        // Confronto tra copie minuscole, i dati originali restano intatti
        if(toLower(pers.sesso) == toLower(se)) {
            cout << pers.cognome << " " << pers.nome << " " << pers.sesso << " " << pers.anno_nascita << endl;
        }
    }
}

//by antonio salducco
