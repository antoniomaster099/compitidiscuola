/*La popolazione italiana C( divisa in boomer, gen z e millenials. Caricare in due vettori
rispettivamente il nome e l'anno di nascita di N cittadini. Mediante funzioni e procedure:-
Caricare e visualizzare i vettori
- Dire quanti sono i boomer (nati fino al 1990), quanti sono i Millenials
(Nati dal 1991 al 2005) e quanti di gen z (nati dopo il 2005)
- Ordinare e visualizzare ordinati per anno di nascita
- Dato un anno in input visualizzare tutti i nominativi nati in quell'anno
- Creare e visualizzare un vettore contenente solo i nomi dei cittadini nati nel nuovo secolo

TUTTI I QUESITI DOVRANNO ESSERE RISOLTI CON FUNZIONI O PROCEDURE E PASSAGGIO DI PARAMETRI!!!*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void carica(vector <int> & date, vector<string> & nomi);
void conta(vector <int> & date, vector<string> & nomi);
void ricerca(int k,vector <int> & date, vector<string> & nomi);
void ns(vector <int> & date, vector<string> & nomi, vector <string>& nuovosecolo);
void ordina(vector <int> & date, vector<string> & nomi);

int main() {
	vector <int> date;
	vector <string> nomi;
	vector <string> nuovosecolo;
	int k,scelta;
	carica(date, nomi);
	cout<<" fai la tua scelta  1) conta 2) ricerca 3) nuovo secolo 4) ordinamento 0) esci ";
	cin>>scelta;
	while(scelta!=0) {
		switch (scelta)
		{
		case 1:
			conta(date, nomi);
			break;
		case 2:
			cout<<"inserisci l'anno di ricerca: ";
			cin>>k;
			ricerca(k, date, nomi);
			break;
		case 3:
			ns(date, nomi, nuovosecolo);
			break;
		case 4:
			ordina(date, nomi);
			break;
		case 0:
			cout<<" uscita in corso ";
			break;

		default:
			cout<<" scelta non valida ";
			break;
		}
		cout<<"\n fai la tua scelta  1) conta 2) ricerca 3) nuovo secolo 4) ordinamento 0) esci ";
		cin>>scelta;
	}
}

//carica
void carica(vector <int> & date, vector<string> & nomi) {
	int n;
	cout<< " qaunti numeri mettere? ";
	cin>>n;
	nomi.resize(n);
	date.resize(n);
	for(int i=0; i<n; i++) {
		cout<<" metti il nome e l anno di nascita della "<<i+1<<" persona ";
		cin>>nomi[i]>>date[i];
	}
}

void conta(vector <int> & date, vector<string> & nomi) {
	int boomer=0,millenial=0,genz=0;
	for(int i=0; i<date.size(); i++) {
		if(date[i]<=1990 and date[i]>=1941)
		{
			boomer++;
		}
		else if(date[i]>=1991 and date[i] <=2005)
		{
			millenial++;
		}
		else if(date[i]<1941 or date[i]>2026)
		{
			cout<<" data non valida ";
		}
		else
		{
			genz++;
		}
	}
	cout<<" ci sono "<<boomer<<" boomer "<<" ci sono "<<millenial<<" millenials "<<" ci sono "<<genz<<" gen z ";
}

void ricerca(int k,vector <int> & date, vector<string> & nomi) {
	for(int i=0; i<date.size(); i++) {
		if(date[i]==k)
		{
			cout<<nomi[i];
		}
	}
}

void ns(vector <int> & date, vector<string> & nomi, vector <string>& nuovosecolo) {
    nuovosecolo.clear();//pulise il vettore
    for(int i=0; i<date.size(); i++) {
        if(date[i]>2000)
        {
            nuovosecolo.push_back(nomi[i]);
        }
    }
    cout<<" i cittadini nati nel nuovo secolo sono: ";
    for(int i=0; i<nuovosecolo.size(); i++) {
        cout<<nuovosecolo[i]<<"\n";
    }
}

void ordina(vector <int> & date, vector<string> & nomi) {
	cout<<" gli anni di nascita ordinati sono: ";
	sort(date.begin(), date.end());
	for(int i=0; i<date.size(); i++) {
		cout<<" \n: "<<date[i]<<"\n";
	}
}
