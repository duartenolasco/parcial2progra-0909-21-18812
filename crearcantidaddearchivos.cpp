/*  un programa en c++ con las siguientes caracterisiticas:
 * 1). que sea para windows.
 * 2). que pregunte al usuario cuantos archivos desea crear y de acuerdo a la cantidad cree los archivos correspondientes.
 * 3). los archivos creados se deben llamar file1, file2, file3, y asi sucesivamente hasta llegar a la cantidad escrita por el usuario.
 * 4). crea una funcion que agregue texto a los archivos creados y que de acuerdo al numero de archivo debe crearle una linea de texto,
 * si el file2 debe crearle, 2 lineas de texto, si es el file 3 debe crearles 3 lineas de texto y asi sucesivamente.
 * 5). crea una funcion que permita buscar el archivo mas grande osea que contenga mas lineas por ejemplo el file1 solo tiene una linea,
 * file2 tiene 2 lineas, file3 tiene 3 lineas entonces lo que debe hacer esta funcion es escoger el 3 ya que es el que contiene mas lineas.
 */

#include <iostream>

using namespace std;

void creararchivos();

int main() {

    creararchivos();

    return 0;
}
void creararchivos(){
    int numero;

    cout<<"Digite un numero: "; cin>>numero;

    if(numero==0){ //esto en dado caso el numero sea 0
        cout<<"el numero es cero";//el programa me lo dira
        cout<<"\n 0 archivos es lo mismo que crear 0 archivos";
    }
        //y el else aca me funciona que si en dado caso no es 0 me aplique la siguiente caracteristica
    else if(numero%2==0){//& este se usa para division y nos muestra el residuo y si este residuo es 0 es un numero par
        cout<<"el numero es par";
    }
    else{ //y pues aca ya no es necesario ya que si no es 0 el numero o un numero par
        cout<<"el numero es impar"; //automaticamente sabremos que es un numero impar
    }
}