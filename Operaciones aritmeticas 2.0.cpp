#include<iostream>
using namespace std;


//suma
float suma(float a, float b){
    return a + b;
}

//resta
float resta(float a, float b){
    return a - b;
}

//multiplicacion
float multi(float a, float b){
    return a * b;
}

//division
float div(float a, float b){
    return a / b;
}

int main(){
    //declaracion de variables
    float a;
    float b;

    //Lectura de variables
    cin >> a >> b;

    //Impresion de resultados
    cout << "Suma: " << suma(a, b) << "\n";
    cout << "Resta: " << resta(a, b) << "\n";
    cout << "Multiplicacion: " << multi(a, b) << "\n";
    cout << "Division: " << div(a, b) << "\n";
}

