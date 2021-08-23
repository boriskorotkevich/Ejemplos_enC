#include<bits/stdc++.h>
using namespace std;

//Programa que calcula raices de ecuaciones cubicas, cuadraticas y lineales

//Opcion 2
void lineal(int a, int b, int c, int d, int e){
    b *= -1;
    double res = b / a;
    cout << "Solucion: " <<  res << "\n";
}

long long int revisa(int a, int b, int c, int d, int mitad){
    long long int ans;

    ans = (a * mitad * mitad * mitad + b * mitad * mitad + c * mitad + d);

    return ans;
}

//Opcion 0
void cubica(int a, int b, int c, int d, int e){
    int ini = 0;
    int fin = 100000;

    long long int mitad, ans;
    while (ini <= fin) {

        mitad = ini + (fin - ini) / 2;
        ans = revisa(a, b, c, d, mitad);

        if (ans == e) {
            cout << "Solucion: " << mitad << "\n";
            return ;
        }

        if (ans < e){
            ini = mitad + 1;
        }else{
            fin = mitad - 1;
        }

    }

    cout << "Sin solucion\n";

}

//Opcion 1
void cuadratica(int a, int b, int c, int d, int e){
    int dis = b * b - 4 * a * c;

    if(dis < 0){
        cout << "Sin solucion\n";
        return ;
    }

    double sol1, sol2;
    sol1 = (-1 * b - sqrt(dis))/(2 * a);
    sol2 = (-1 * b + sqrt(dis))/(2 * a);

    cout << "Soluciones: " << sol1 << " " << sol2 << "\n";
}


int main(){
    char opt;
    int a = 0, b = 0, c = 0, d = 0, e = 0;

    while(true){

        cout << "Selecciona la operacion que deseas realizar:\n0. Raiz cubica\n1. Raiz cuadratica\n2. Raiz de una recta\n3. Salir\nOpcion: ";
        cin >> opt;
        cout << "Digita los coeficientes separados por un espacio\n";

        if(opt == '0'){
            cout << "AX^3 + Bx^2 + Cx + D = E\n";
            cin >> a >> b >> c >> d >> e;
        }else if(opt == '1'){
            cout << "Ax^2 + Bx + C = 0\n";
            cin >> a >> b >> c;
        }else if(opt == '2'){
            cout << "AX + B = 0\n";
            cin >> a >> b;
        }else{
            break;
        }

        void(*menu[3])(int, int, int, int, int) = {cubica, cuadratica, lineal};
        menu[opt - '0'](a, b, c, d, e);

        cout << "Desea realizar otra operacion (S/N)?: ", cin >> opt;

        if(opt == 'N')break;
    }
}

//Posibles entradas

/*
Ecuacion cubica
0
1 0 0 0 27

Ecuacion cuadratica
1
3 -5 1

Ecuacion lineal
2
3 2
*/
