/*Dato un vettore T[n], contenente le n temperature giornaliere
 di una città scrivi un programma che mediante procedure e
 funzioni carichi il vettore T[n] e restituisca la temperatura
  media, la massima e la minima nel corso degli N giorni.
Il programma deve anche contenere una funzione che restituisce
 il numero totale dei giorni in cui la temperatura è risultata
  compresa fra 15° e 25°C.*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void carica(int& n, vector<int>& t);
void media(vector <int>& t);
void minimo(vector <int>& t);
void massimo(vector <int>& t);
void compreso(vector <int>&  t);
int main(){
  int n,scelta;
  vector <int> t;
  carica(n,t);
  cout<<" 1) per la media 2) per il minimo 3) per il massimo 4) per vedere i numeri compresi tra 15 e 25 0) per uscire";
  cin>>scelta;
  while(scelta!=0){
  switch (scelta)
  {
  case 1:
    media(t);
    break;
  case 2:
  minimo(t);
  break;
  case 3:
  massimo(t);
  break;
  case 0:
  break;
  case 4:
  compreso(t);
  break;
  default:
  cout<<" numero sbagliato";
    break;
  }
  cin>>scelta;
}
}


void carica(int& n, vector<int>& t){
  cout<<" quanti numeri vuoi mettere? \n";
  cin>>n;
  t.resize(n);
  for(int i=0;i<t.size();i++){
    cout<<"metti il "<<i<<" numero ";
    cin>>t[i];
  }
}

void media(vector <int>& t){
  float tot=0;
  for(int i=0;i<t.size();i++){
    tot+=t[i];
  }
  float media=tot/t.size();
  cout<<" \nla media è di "<<media<<"\n";
}

void minimo(vector <int> &t){
auto min=min_element(t.begin(),t.end());// commento fatto per far capire che non uso chatgpt, con questa funzione ti viene restituito un iteratore ( ci servira dopo ), auto serve a dire a c++ " quello che sta a destra è il tipo che devi prendere "
cout<<"\nil minimo è "<<*min<<"\n";// con * diciamo al interattore " mi fai vedere il valore di questa cella di memoria?"

}

void massimo(vector <int> &t){
  auto m=max_element(t.begin(),t.end());//esiste anche la funzione minmax solo che per come l ho sviluppato io ( ovvero che l utente pupo scegliere cosa fare ) non mi sembrava giusta
  cout<<"\nil massimo è"<<*m<<"\n ";


}

void compreso(vector <int> &t){
  int conta=0;
  for(int i=0;i<t.size();i++){
    if(t[i]>15 and t[i]<25){
      conta++;
    }
  }
  cout<<"i giorni in cui la temperatura era minore di quindici e maggiore di venticinque sono "<<conta;
}
