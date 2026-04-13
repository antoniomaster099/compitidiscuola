#include <iostream>
using namespace std;


struct citta{

    string nome;
    int numero_abbitanti;
    int abbitanti_annoscorso
}

void differenza(int citta.numero_abbitanti, int abbitanti_annoscorso){
    if(citta.numero_abbitanti>citta.abbitanti_annoscorso){
        cout<<" ci sta un aumento  di"<<citta.numero_abbitanti-citta.abbitanti_annoscorso
    }
    else if (citta.numero_abbitanti<citta.abbitanti_annoscorso){
        cout<<" ci sta un diminuimento  di"<<citta.abbitanti_annoscorso-citta.numero_abbitanti
    }
}

int main(){
    cout<<"metti i dati ome numero abbitanti attuali e numero abbitanti dell anno scorso";
    cin>>citta.nome>>citta.numero_abbitanti>>citta.abbitanti_annoscorso;
    differenza(citta.numero_abbitanti,citta.abbitanti_annoscorso);
}
