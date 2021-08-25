#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<cctype>
using namespace std;
/*********************************************
Autor: Bryan Mendiola Correa

Descripcion: Programita que calcula las raices de ecuaciones lineales, cubicas y cuadraticas.

Algunos: Ejemplos de entrada

- x^2 + 7x - 10 = 0 OK
9x + 2 + 3 = 5x - 6x OK
x^2 + x + 1 = 0 OK
7x^2 + 21x - 28 = 0 OK
9x + 1 - 2 = 6x + 7x + 10 OK
x^3 - 4x^2 - 3x - 10 = 0 OK

**********************************************/


struct cof{
    float cua = 0;
    float cub = 0;
    float lin = 0;
    float ind = 0;
    int signo = 1;
};

//Toma como parametro una cadena y la procesa

void procesa(string& s, cof& scof, int& ult_s){
    int tam = s.size();
    char ult_c = s.back();

    if(ult_c == '+'){
        ult_s = 1;
    }else if(ult_c == '-'){
        ult_s = -1;
    }else if(ult_c  == '='){
        scof.signo = -1;
    }else if(ult_c == 'x'){
        scof.lin += ult_s * scof.signo * ((tam > 1)?stof(s.substr(0, tam - 1)):1);
    }else if(isdigit(ult_c)){
        if(tam >= 3){
            string temp = s.substr(tam - 3, tam);
            string aux = s.substr(0, tam - 3);
            if(temp == "x^3"){
                scof.cub += ult_s * scof.signo * ((aux.size() >= 1)?stof(aux):1);
            }else if(temp == "x^2"){
                scof.cua += ult_s * scof.signo * ((aux.size() >= 1)?stof(aux):1);
            }else{
                scof.ind += ult_s * scof.signo * stof(s);
            }
        }else{
            scof.ind += ult_s * scof.signo * stof(s);
        }
    }else{
        cout << "Expresion no valida";
    }
}

//Recuelve la exprecion cubica, pero solo obtiene una raiz(la real)
void resuelve_cubica(float a, float b, float c){
    float pol  = -2 * a * a * a + 9.0 * a * b - 27 * c;
    float pol2 = pow(-1 * pol, 2);
    float pol3 = pow(4 * (-1 * a * a + 3.0 * b), 3);
    float big_one = pow(((pol + sqrt(pol2 + pol3)) / 54), 1/3);
    float big_two = pow(((pol - sqrt(pol2 + pol3)) / 54), 1/3);
    float ans = (-1 * a / 3.0) + big_one + big_two;

    cout << "x = " << ans << "\n";
}

//Resuelve la exprecion cuadratica
void resuelve_cuadratica(float& a, float& b, float& c){
    float dis = b * b - 4 * a * c;
    if(dis >= 0){
        float x1 = (-1 * b - sqrt(dis)) / (2 * a);
        float x2 = (-1 * b + sqrt(dis)) / (2 * a);
        cout << "x1 = " << x1 << " x2 = " << x2 << "\n";
        return ;
    }else{
        cout << "No tiene solucion en R\n";
    }
}

//Resuelve la expresion lineal
void resuelve_lineal(float& a, float& b){
    float ans = -1 * b / a;
    cout << "x = " << ans << "\n";
}

//Detecta el grado de la ecuacion y evalua si es posible resolverla
void resuelve(cof& scof){
    if(scof.cub != 0 && scof.cua != 0 && scof.lin != 0 && scof.ind != 0){
        resuelve_cubica(scof.cua/scof.cub, scof.lin/scof.cub, scof.ind/scof.ind);
    }else if(scof.cua != 0 && scof.lin != 0 && scof.ind != 0){
        resuelve_cuadratica(scof.cua, scof.lin, scof.ind);
    }else if(scof.lin != 0 && scof.ind != 0){
        resuelve_lineal(scof.lin, scof.ind);
    }else{
        cout << "No se pudo encontrar alguna solucion\n";
    }
}

int main(){
    char c = 'S';
    string eq;

    do{
        int ult_s = 1;
        cof scof = {0, 0, 0, 0, 1};
        cout << "Teclee la expresion: ";

        if(c == 'S' || c == 's'){
            while(cin >> eq){
                if(eq == "OK")break;
                procesa(eq, scof, ult_s);
            }
            resuelve(scof);
        }
        cout << "Desea continuar (S/N)?: ", cin >> c;
        getchar();
    }while(c != 'N' && c != 'n');
}
