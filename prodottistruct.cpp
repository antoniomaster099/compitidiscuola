#include <iostream>
#include <vector>
using namespace std;

struct ordini{
    int numero_ordine;
    int codice;
    int quantita;
    float prezzo;
};

void visualizza_codice( vector <ordini>& p){
    for(int i=0; i<p.size();i++){
        cout<<"\n"<<p[i].codice;
    }
}

void visualizza_prezzounitario( vector <ordini>& p){
        for(int i=0; i<p.size();i++){
        cout<<"\n"<<(float)p[i].quantita*p[i].prezzo;
    }
}

int main(){
    int n;
vector <ordini> p;
    cout<<"inserisci i quanti numeri";
    cin>>n;
    p.resize(n);
    for(int i=0; i<p.size();i++){
        cout<<"metti i dati ";
        cin>>p[i].numero_ordine>>p[i].codice>>p[i].prezzo>>p[i].quantita;


    }
    visualizza_codice(p);
    visualizza_prezzounitario(p);
}
