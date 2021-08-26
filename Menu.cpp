#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Opcion: ", cin >> n;

    if(n == 1){
        cout << "Seleccionaste la opcion 1";
    }else if(n == 2){
        cout << "Seleccionaste la opcion 2";
    }else if(n == 3){
        cout << "Seleccionaste la opcion 3";
    }else{
        cout << "Opcion no valida";
    }
}
