#include <iostream>

using namespace std;

int main(){

    //Declaración de las variables
    int n = 0, m = 0;

    //Se piden las variables de forma condicionada
    do{
        cout << "Ingrese el nummero de familias (n>0): ";cin >> n;
    }while(n < 0);

    //Se piden las variables de forma condicionada
    do{
        cout << "Ingrese el nummero de meses (m>0): ";cin >> m;
    }while(m < 0);

    //Creación de la matriz y arreglos
    float consumo[n][m] = {0};
    float Tkhw[n] = {0};
    float precio[n] = {0};

    //Llenamos la matriz
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){ //Iteradores de la matriz
            cout << "Familia ["<<i+1<<"] Mes["<<j+1<<"]: "; cin >> consumo[i][j];
        }
    }

    cout << "\n";
    //Se imprime la matriz

    cout << "\n\t\t*******DATOS DE LA MATRIZ DE CONSUMO*******\n\n";
    for (int i = 0; i<n; i++){

        for (int j = 0; j<m; j++){

            cout<<consumo[i][j]<<" ";
        }
        cout << "\n";
    }

    //Se recorre la matriz y se guardan los valores en un arreglo
    float consumoT = 0.0;
    for (int i = 0; i<n; i++){
        consumoT = 0.0;
        //Que se guarde en consumoT cada valor de la matriz consumo
        for (int j = 0; j<m; j++){
            consumoT += consumo[i][j];            
        }
        //Hacemos el arreglo igual a cada uno de los valores que va tomando consumot
        //Esto es para guardar el consumo maximo en kWh de cada familia
        Tkhw[i] = consumoT;
    }

    //Aqui sumamos el total de cada familia en kWh y lo guardamos en arreglo y el total en total
    
    cout << "\n";
    cout <<"\n\t\t**********CONSUMO TOTAL DE LAS FAMILIAS EN kWh**********\n";
    float total = 0.0;
    for (int i = 0; i<n; i++){
        
        cout <<"FAMILIA 0"<<i+1<<": "<< Tkhw[i]<< "kWh" << ", ";
        total += Tkhw[i];
    }

    //Aqui hacemos lo mismo pero para otro numero que en los datos de prueba es igual
    float mayor = 0.0, mayor2 = 0.0;
    int posMayor = 0,posMayor2;
    for (int i=0; i<n; i++)
    {   
        //Algoritmo de ordenamiento
        if(Tkhw[i]>mayor)
        {
            mayor = Tkhw[i];
            posMayor = i;

            for (int j = 0; j<n; j++){
                //Si es igual a lo que esta en mayor
                if (Tkhw[j] == mayor){

                    mayor2 = Tkhw[j];
                    posMayor2 = j;
                }
            }
        }
    }

    //En esta parte vamos a guardar nuestras filas(familias), especificamente cada valor que se encuentra en cada fila
    float var;
    for (int i = 0; i<n; i++){

        var = 0.0;

        for (int j = 0; j<m; j++){
            //Como se tienen que condicionar los precios entonces hacemos un if para los valores que entran en la matriz
            if(consumo[i][j]>=0 and consumo[i][j] <= 173){
                var += consumo[i][j]*400.0;                
            }else if (consumo[i][j]>=174 and consumo[i][j] <= 999){
               var += consumo[i][j]*550.0; 
            }           
        }
        //Lo que guarda var al salir del ciclo anidado que se nos guarde en precio[i]
        precio[i] += var; 
    }

    //Impresion de los datos bajo la condicion de que pueden existir datos máximos iguales
    if (posMayor == posMayor2){
        cout<<"\n\nLA FAMILIA QUE MAS CONSUMIO FUE LA FAMILIA 0"<<posMayor+1<< " CON UN TOTAL DE "<<mayor<<"kWh"<<endl;
    }else
    {
        cout<<"\n\nLAS FAMILIAS QUE MAS CONSUMIERON FUERON LA FAMILIA 0"<<posMayor+1<<" Y LA FAMILIA 0"<<posMayor2+1<< " CON UN TOTAL DE  "<<mayor<<"kWh"<<endl;
    }
    cout <<"\n\nCANTIDAD CONSUMIDA DE TODAS LAS FAMILIAS "<< total << "kWh";

    cout << "\n\nPRECIO EN CONSUMO DE CADA FAMILIA (DINERO)\n";
    for (int i = 0; i<n; i++){
        
        cout <<"FAMILIA 0"<<i+1<<": "<<"$"<<precio[i]<< ", ";
        
    }

    cin.ignore();
    cin.get();

    return 2009;
}