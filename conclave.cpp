/*Dichiarare una struttura CONCLAVE con attributi:
numero_fumata, voti_validi, voti_non_validi.
Acquisire i dati di N fumate e visualizzare il totale dei
voti di ciascuna fumata (validi+nonvalidi). Poi visualizzare
il massimo dei voti validi. Infine, dato il
numero di una fumata in input, visualizzare i suoi voti validi.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct conclave{
    int n_f;
    int v_v;
    int vnv;
};

void carica (vector <conclave>& c);
int visualizza(const vector <conclave>& c);
int mx(const vector <conclave>& c);
void ricerca(const vector <conclave>& c,int n);
void errore(int& n,const vector <conclave>& c);
void papa( int m, const vector <conclave>& c);

int main(){
int n,m;
vector <conclave> c;
carica(c);
cout<<"totale fumate "<<visualizza(c);
m=mx(c);
cout<<" il massimo è "<<m;
cout<<" metti un numero di fumata da ricercare ";
cin>>n;
errore(n,c);
ricerca(c,n);
papa(m,c);
}



void carica (vector <conclave>& c){
    int n;
    cout<<" quante fumate ci sono? \n";
    cin>>n;
    c.resize(n);
    for( int i=0; i<c.size(); i++){
        cout<<" metti i dati in questo ordine \n voti validi \n voti non validi \n";
        cin>>c[i].v_v>>c[i].vnv;
        c[i].n_f=i+1;
    }
}


int visualizza(const vector <conclave>& c){
   int tot=0;
   for( int i=0; i<c.size(); i++){
    tot+=c[i].v_v+c[i].vnv;
   } 
   return tot;
}

int mx(const vector <conclave>& c){
int mx=c[0].v_v;
for(int i=1; i<c.size(); i++){
    if(c[i].v_v>mx){
        mx=c[i].v_v;
    }
}
return mx;

}



void ricerca(const vector <conclave>& c,int n){
for(int i=0; i<c.size(); i++){
    if(c[i].n_f==n){
        cout<<" voti validi "<<c[i].v_v;
    }
}
}

void errore(int& n,const vector <conclave>& c){
    if(n<0 || n>c.size()){
        cout<<"  non possibile riprova ";
        cin>>n;
    }
}

void papa( int m, const vector <conclave>& c){
    bool flag=false;
    for(int i=0; i<c.size(); i++){
    if(c[i].v_v>c[i].vnv){
        flag=true;
    }
}

    if(flag){
        cout<<" habemus papam ";
    }
    else{
        cout<<" habemus nada ci si pensa un altra volta ";
    }
}




