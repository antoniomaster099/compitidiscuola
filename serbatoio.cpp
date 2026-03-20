/*2. Controllo del serbatoio Un serbatoio inizialmente vuoto viene riempito ogni giorno di liquido,
 che affluisce nell’arco delle 24 ore. Per verificare che il serbatoio non abbia perdite, il livello del liquido viene misurato a ogni ora,
  bloccandone temporaneamente il flusso. Realizza una funzione che gestisca le 24 misurazioni con un array e, analizzando i dati, indichi se e in quali ore il liquido risulta diminuito, evidenziando una possibile perdita.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


// uso la stessa logica di prima 0 se ci sono perdite, 1 se non ci sono perdite
void riempimento(vector<bool>& misure);
void controlloperdite(const vector<bool>& misure);

int main(){
    srand(time(NULL));
    vector<bool> misure(24);
    riempimento(misure);
    controlloperdite(misure);
    return 0;
}







void riempimento(vector<bool>& misure){
    for(int i=0; i<misure.size(); i++){
        misure[i]=rand()%2;
    }
}

void controlloperdite(const vector<bool>& misure){
    for(int i=0; i<misure.size(); i++){
        if(misure[i]==0){
            cout<<"possibile Perdita rilevata all'ora "<<i+1<<"\n";
            break;
        }
    }
}
