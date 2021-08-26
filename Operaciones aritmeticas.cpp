#include<iostream>
using namespace std;


//suma
float suma(int a, float b){
    return a + b;
}

//resta
float resta(int a, float b){
    return a - b;
}

//multiplicacion
float multi(int a, float b){
    return a * b;
}

//division
float div(int a, float b){
    return a / b;
}

int main(){
    //declaracion de variables de entrada
    int a = 5;
    float b = 10;

    //Impresion de resultados
    cout << "Suma: " << suma(a, b) << "\n";
    cout << "Resta: " << resta(a, b) << "\n";
    cout << "Multiplicacion: " << multi(a, b) << "\n";
    cout << "Division: " << div(a, b) << "\n";
}

