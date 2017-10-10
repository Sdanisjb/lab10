#include <iostream>

using namespace std;

void iniciar_Mat(int**matriz,int filas,int columnas,int i=0){
    if(i==filas){
        return;
    }
    *(matriz+i)=new int[columnas];
    return iniciar_Mat(matriz,filas,columnas,i+1);
}

void clean(int**matriz,int filas,int columnas,int i=0,int j=0){
    if(j==columnas){
        return clean(matriz,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    *(*(matriz+i)+j)=0;
    return clean(matriz,filas,columnas,i,j+1);
}

void elementos(int**matriz,int filas,int columnas,int i=0, int j=0){
    if(j==columnas){
        return elementos(matriz,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }

    int elemento;
    //cout<<"Ingresar el valor ["<<i<<"] ["<<j<<"] :"<<endl;
    cin>>elemento;

    *(*(matriz+i)+j)=elemento;

    return elementos(matriz,filas,columnas,i,j+1);
}

void mayor(int**matrizA, int**matrizB, int**matrizC,int filas, int columnas,int i=0, int j=0){
    if(j==columnas){
        return mayor(matrizA,matrizB,matrizC,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    *(*(matrizC+i)+j)= (*(*(matrizA+i)+j) > *(*(matrizB+i)+j))? *(*(matrizA+i)+j): *(*(matrizB+i)+j);
    return mayor(matrizA,matrizB,matrizC,filas,columnas,i,j+1);

}

void menor(int**matrizA, int**matrizB, int**matrizC,int filas, int columnas,int i=0, int j=0){
    if(j==columnas){
        return menor(matrizA,matrizB,matrizC,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    *(*(matrizC+i)+j)= (*(*(matrizA+i)+j) < *(*(matrizB+i)+j))? *(*(matrizA+i)+j): *(*(matrizB+i)+j);
    return menor(matrizA,matrizB,matrizC,filas,columnas,i,j+1);

}

void promedio(int**matrizA, int**matrizB, int**matrizC,int filas, int columnas,int i=0, int j=0){
    if(j==columnas){
        return promedio(matrizA,matrizB,matrizC,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    *(*(matrizC+i)+j)= (*(*(matrizA+i)+j) + *(*(matrizB+i)+j))/2;
    return promedio(matrizA,matrizB,matrizC,filas,columnas,i,j+1);
}

void suma(int**matrizA, int**matrizB, int**matrizC,int filas, int columnas,int i=0, int j=0){
    if(j==columnas){
        return suma(matrizA,matrizB,matrizC,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    *(*(matrizC+i)+j)= *(*(matrizA+i)+j) + *(*(matrizB+i)+j);
    return suma(matrizA,matrizB,matrizC,filas,columnas,i,j+1);
}

void resta(int**matrizA, int**matrizB, int**matrizC,int filas, int columnas,int i=0, int j=0){
    if(j==columnas){
        return resta(matrizA,matrizB,matrizC,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    *(*(matrizC+i)+j)= *(*(matrizA+i)+j) - *(*(matrizB+i)+j);
    return resta(matrizA,matrizB,matrizC,filas,columnas,i,j+1);
}

void multi(int**matrizA, int**matrizB, int**matrizC,int filas1, int columnas1,int filas2,int columnas2,int i=0, int j=0,int k =0){
    if(filas2!=columnas1){
        cout<<"Error. Dimensiones incorrectas en las matrices"<<endl;
        return;
    }
    if(k==filas2){
        return multi(matrizA,matrizB,matrizC,filas1,columnas1,filas2,columnas2,i,j+1,0);
    }
    if(j==columnas2){
        return multi(matrizA,matrizB,matrizC,filas1,columnas1,filas2,columnas2,i+1,0,k);
    }
    if(i==filas1){
        return;
    }
    *(*(matrizC+i)+j)=*(*(matrizC+i)+j)+(*(*(matrizA+i)+j) * *(*(matrizB+i)+j));
    return multi(matrizA,matrizB,matrizC,filas1,columnas1,filas2,columnas2,i,j,k+1);

}

void printMatriz(int**matriz,int filas,int columnas,int i=0, int j=0){
    if(j==columnas){
        cout<<endl;
        return printMatriz(matriz,filas,columnas,i+1,0);
    }
    if(i==filas){
        return;
    }
    cout<<*(*(matriz+i)+j)<<" ";
    return printMatriz(matriz,filas,columnas,i,j+1);
}

void borrarMatrices(int**matriz,int filas,int i=0){
    if(i==filas){
        delete []matriz;
        return;
    }
    delete [] matriz[i];
    return borrarMatrices(matriz,filas,i+1);
}

int main()
{
    int filas1,columnas1,filas2,columnas2;

    cout<<"Ingresa el numero de filas de la primera matriz"<<endl;
    cin>>filas1;
    cout<<"Ingresa el numero de columnas de la primera matriz"<<endl;
    cin>>columnas1;
    cout<<"Ingresa el numero de filas de la segunda matriz"<<endl;
    cin>>filas2;
    cout<<"Ingresa el numero de columnas de la segunda matriz"<<endl;
    cin>>columnas2;

    int**matrizA= new int*[filas1];
    int**matrizB= new int*[filas2];


    iniciar_Mat(matrizA,filas1,columnas1);
    iniciar_Mat(matrizB,filas2,columnas2);

    cout<<"Ingresa los elementos de la primera Matriz"<<endl;
    elementos(matrizA,filas1,columnas1);
    cout<<"Ingresa los elementos de la segunda Matriz"<<endl;
    elementos(matrizB,filas2,columnas2);

    cout<<"Selecciona la Operacion"<<endl;
    cout<<"1 --> Mayores Elementos"<<endl;
    cout<<"2 --> Menores Elementos"<<endl;
    cout<<"3 --> Promedio de los Elementos"<<endl;
    cout<<"4 --> Suma de Matrices"<<endl;
    cout<<"5 --> Resta de Matrices"<<endl;
    cout<<"6 --> Multiplicacion de Matrices"<<endl;


    void (*ptrOperador)(int**,int**,int**,int,int,int,int);
    int operacion=0;
    cin>>operacion;

    if(operacion==1){
        ptrOperador=mayor;
    }
    else if(operacion==2){
        ptrOperador=menor;
    }
    else if(operacion==3){
        ptrOperador=promedio;
    }
    else if(operacion==4){
        ptrOperador=suma;
    }
    else if(operacion==5){
        ptrOperador=resta;
    }

    if(operacion!=6){
        if(filas1!=filas2 || columnas1!=columnas2){
            cout<<"Error en las dimensiones. Las matrices deben ser iguales"<<endl;
            borrarMatrices(matrizA,filas1);
            borrarMatrices(matrizB,filas2);
            return 0;
        }
        int**matrizC= new int*[columnas1];
        iniciar_Mat(matrizC,filas1,columnas1);
        ptrOperador(matrizA,matrizB,matrizC,filas1,columnas1,0,0);
        printMatriz(matrizC,filas1,columnas1);
        borrarMatrices(matrizC,filas1);
    }



    if(operacion==6){
        int**matrizC= new int*[columnas1];
        iniciar_Mat(matrizC,filas1,columnas2);
        clean(matrizC,filas1,columnas2);
        multi(matrizA,matrizB,matrizC,filas1,columnas1,filas2,columnas2);
        printMatriz(matrizC,filas1,columnas2);
        borrarMatrices(matrizC,filas1);
    }

    borrarMatrices(matrizA,filas1);
    borrarMatrices(matrizB,filas2);


    return 0;

}
