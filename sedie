/* 1. Sala d’attesa In una sala d’aspetto ci sono 15 sedie disposte su un’unica fila. Rappresentando la 
fila come un array di valori vero (sedia occupata) e falso (sedia libera),
 scrivi un procedimento che verifichi se ci sono due persone sedute vicine. */
#include <iostream>
#include <vector>
#include <cstdlib>//uso rand perchè c++ vede 0 e 1 come false e true, rispettivamente
#include <ctime>
using namespace std;
void riempimento(vector<bool>& fila);
void visualizza(const vector<bool>& fila);
void sedie(const vector<bool>& fila);
int main(){
srand(time(NULL));
vector<bool> fila(15);
riempimento(fila);
visualizza(fila);
sedie(fila);

}
void riempimento(vector<bool>& fila){
    for(int i=0; i<fila.size(); i++){
        fila[i]=rand()%2;
    }
}
void visualizza(const vector<bool>& fila){
    for(int i=0; i<fila.size(); i++){
        cout<<fila[i]<<" ";
    }
}
void sedie(const vector<bool>& fila){
    for(int i=0; i<fila.size()-1; i++){
        if(fila[i] and fila[i+1]){
            cout<<"\nCi sono due persone sedute vicine alla posizione "<<i+1<<"\n";
            
        }
    }
}
