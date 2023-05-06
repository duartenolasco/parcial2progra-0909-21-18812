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
    }
        //y el else aca me funciona que si en dado caso no es 0 me aplique la siguiente caracteristica
    else if(numero%2==0){//& este se usa para division y nos muestra el residuo y si este residuo es 0 es un numero par
        cout<<"el numero es par";
    }
    else{ //y pues aca ya no es necesario ya que si no es 0 el numero o un numero par
        cout<<"el numero es impar"; //automaticamente sabremos que es un numero impar
    }
}