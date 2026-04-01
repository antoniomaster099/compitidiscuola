#include <iostream>
using namespace std;
int recursione(int n){
    n=n-1;
    if(n==1){
        cout<<" sei uscito "<<n<<" ";
        return 0;
    }
    else{
        cout<<"sei passato per l else "<<n<<" ";
        int risu;
        risu=recursione(n);
        return risu;
    }
}
int controllo(int& n){
    if(n<1){
        cout<<" un numero minore di 1 come "<<n<<" non è accetato\n ";
        cin>>n;
        controllo(n);
        return n;
    }
    else{
        cout<<" un numero come "<<n<<" è accetato ";
        return n;
    }
}
int main()
{
    int n,num;
    cout<<" che numero vuoi mettere? ";
    cin>>n;
    num=controllo(n);
    recursione(num);
    return 0;
}
