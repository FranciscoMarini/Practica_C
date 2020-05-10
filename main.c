#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int pasarPilaDistinta (Pila * pOrigen, Pila * pDestino, int elemento);
void cargarPila(Pila * punteroPila);
void cuadradoArreglo (int Z[], int cantVal);
void arregloInverso (int Z[], int cantVal);
void sumaArreglo (int Z[], int cantVal);
void arregloDePila (Pila * A, Pila * B, int Z[], int cantVal);
void mostrarArreglo (int Z[], int cantVal);
void pasarPila (Pila * A, Pila * B);
void agregaEnBase (Pila * punteroPila, int elemento);
void eliminaBasePila (Pila * A);

int main()
{
    int ejercicio;
    char control;

    do
    {

        system("cls");
        printf("Escriba el numero del ejercicio al que quiere ir:\n");
        printf("Ejercicio 1: Pasar los elementos de la pila A a la B que sean distintos al numero ingresado\n");
        printf("Ejercicio 2: Hacer el cuadrado de los elementos del arreglo Z y lo almacene en otro arreglo.\n");
        printf("Ejercicio 3: Dado un arreglo de numeros enteros, genere otro en orden inverso.\n");
        printf("Ejercicio 4: Realizar la suma del contenido de todo los elementos anteriores al indice de un arreglo\n");
        printf("Ejercicio 5: Hacer una funcion que pase los elementos de ambas pilas al arreglo, manteniendo el orden\n");
        printf("Ejercicio 6: Hacer una funcion que agregue un elemento a la base de una pila\n");
        printf("Ejercicio 7: Eliminar el elemento que se encuentra en la base de una pila.\n");

        scanf("%i", &ejercicio);

        switch (ejercicio)
        {
        case 1:

           {
                    Pila A;
                    Pila B;
                    inicpila(&A);
                    inicpila(&B);

                    apilar(&A,4);
                    apilar(&A,5);
                    apilar(&A,6);

                    apilar(&B,4);
                    apilar(&B,5);
                    apilar(&B,6);
                    int elemento;

                    mostrar(&A);
                    mostrar(&B);

                    elemento=pasarPilaDistinta(&A,&B,5);
                    printf("cantidad de veces:\n%d",elemento);

                    mostrar(&A);
                    mostrar(&B);
           }
                break;

            case 2:
            {
                int N[3]={2,3,4};
                cuadradoArreglo(N,3);
            }



                break;

            case 3:
                {
                    int N[3]={2,3,4};
                        arregloInverso(N,3);

                }
                break;

            case 4:
                {
                    int N[]={1,5,6,7,8};

                    sumaArreglo(N,5);
                }

                break;

            case 5:

                    {

                        Pila A;
                        Pila B;
                        inicpila(&A);
                        inicpila(&B);
                        int N[6]={0};

                        arregloDePila(&A,&B,N,6);
                    }

                break;

            case 6:
                {
                    Pila A;
                    inicpila(&A);
                    apilar(&A,4);
                    apilar(&A,5);
                    apilar(&A,6);

                    agregaEnBase(&A,5);

                }
                break;

            case 7:
                {
                   Pila A;
                    inicpila(&A);
                    apilar(&A,4);
                    apilar(&A,5);
                    apilar(&A,6);

                    eliminaBasePila(&A);
                }
                break;

                default:

                printf("Ese ejercicio no existe \n");

            }
             printf("Quiere ver otro ejercicio? s/n\n");
            fflush(stdin);
            printf("%c\n", control = getch());

    }
    while(control == 's');


    return 0;
}

///(1) reciba dos pilas y un número ingresado por el usuario.
/// Pasar los elementos de la pila A a la B que sean distintos al número ingresado por el usuario.
/// La función debe retornar cuantos elementos se pasaron.
int pasarPilaDistinta (Pila * pOrigen, Pila * pDestino, int elemento)
{
    Pila aux1;
    inicpila(&aux1);

    int i=0;

    while (!pilavacia(pOrigen))
    {
        if(tope(pOrigen) == elemento)
        {
            apilar(&aux1, desapilar(pOrigen));

        }
        else
        {
           apilar(pDestino, desapilar (pOrigen));
           i++;
        }
    }
    return i;
}
///ingresar varios elementos a una Pila, tantos como quiera el usuario.
void cargarPila(Pila * punteroPila)
{
      char control;
    do
    {

        leer(punteroPila);
        printf("desea continuar? s/n \n");
        control=getch();


    }
     while (control != 'n');

}

///(2)Hacer una función que calcule el cuadrado de los
///    elementos del arreglo Z y lo almacene en otro arreglo.
void cuadradoArreglo (int Z[], int cantVal)
{
    int i = 0;
    int N[cantVal];

    for (i=0; i<cantVal; i++)
    {
        N[i]= Z[i]*Z[i];

    }
   printf("el arreglo nuevo es: ");
   mostrarArreglo(N,cantVal);
}
///(3)Escriba un programa que dado un arreglo
///   de números enteros, genere otro en orden inverso.

void arregloInverso (int Z[], int cantVal)
{
      int i,j=0;
      int Y[]={};


      for (i=cantVal-1; i<=0; i--)
      {
          Y[j]=Z[i];
          j++;
      }
     printf("el nuevo arreglo es: \n");
     mostrarArreglo(Y, cantVal);
}
///(4){1,5,6,7,8} escribir un programa que genere otro arreglo con la suma del..............................
///contenido de todo los elementos anteriores al índice actual. El resultado final
///del segundo arreglo es el siguiente: {1,6,12,19,27}.
void sumaArreglo (int Z[], int cantVal)
{
    int i;
    printf("el arreglo es:\n");
    mostrarArreglo(Z, cantVal);

    for(i=0;i<cantVal; i++)
    {
        if (i!=0)
        {
            Z[i]+=Z[i-1];
        }
    }
    printf("\nel nuevo arreglo es:\n");
    mostrarArreglo(Z, cantVal);
}

///(5)Dadas dos pilas ordenadas......................................................
///y un arreglo vacío, hacer una función que pase los
///elementos de ambas pilas al arreglo, manteniendo el orden.
void arregloDePila (Pila * A, Pila * B, int Z[], int cantVal)
{
    Pila aux;
    inicpila(&aux);

    int i=0;

    while (!pilavacia(&A))
    {
         for (i=0; i<cantVal; i++)
         {
             Z[i] = desapilar(&A);
         }


    }
    while (!pilavacia(&B))
    {
         for (i=0; i<cantVal; i++)
         {
             Z[i] = desapilar(&B);
         }


    }


}
///Mostrar los elementos de un arreglo
void mostrarArreglo (int Z[], int cantVal)
{
    int i = 0;

    for (i=0; i<cantVal; i++)
    {
        printf("\n%d", Z[i]);
    }
}

///(6) Hacer una función que agregue un elemento a una pila,
///    pero debe agregarlo en la base de la misma
void agregaEnBase (Pila * punteroPila, int elemento)
{
    Pila aux;
    inicpila(&aux);

    printf("Pila original");
    mostrar(punteroPila);

    while (!pilavacia(punteroPila))
    {
        pasarPila(punteroPila, &aux);
        printf("Pila Aux");
        mostrar(&aux);
    }

    apilar(punteroPila, elemento);

    while(!pilavacia(&aux))
    {
        pasarPila(&aux, punteroPila);
    }

    printf("la pila nueva es:");
    mostrar(punteroPila);

}
///pasa elementos de la pila A a la pila B
void pasarPila (Pila * A, Pila * B)
{
    while (!pilavacia(A))
    {
        apilar(B, desapilar(A));

    }

}
///7) Hacer una función que elimine el elemento
///    que se encuentra en la base de una pila.
void eliminaBasePila (Pila * A)
{
    Pila aux;
    Pila Basura;
    inicpila(&aux);
    inicpila(&Basura);


    printf("Pila Origen");
    mostrar(A);
    while (!pilavacia(A))
    {
        pasarPila(A, &aux);

    }
        apilar(&Basura, desapilar(&aux));
        pasarPila(&aux, A);

        printf("Pila nueva:");
        mostrar(A);

}

///   -* &'s
///   -* punteros
///   -* ejercicios











