#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int pasarPilaDistinta (Pila * pOrigen, Pila * pDestino, int elemento);
void cargarPila(Pila * punteroPila);
void CuadradoArreglo (int Z[], int cantVal);
void ArregloInverso (int Z[], int cantVal);
void SumaArreglo (int Z[], int cantVal);
void ArregloDePila (Pila * A, Pila * B, int Z[], int cantVal);
void MostrarArreglo (int Z[], int cantVal);
void pasarpila (Pila * A, Pila * B);
void agregaEnBase (Pila * punteroPila, int elemento);

int main()
{
    /*///Ejercicio 1.
    Pila A;
    Pila B;
    inicpila(&A);
    inicpila(&B);

    cargarPila(&A);
    cargarPila(&B);
    mostrar(&A);
    mostrar(&B);

    int elementos = pasarPilaDistinta(&A,&B,5);

    mostrar(&A);
    mostrar(&B);
    printf("se pasaron %d elementos", elementos);*/
    ///Ejercicio 2.
    /*int N[];{1,2,3,4,5};

    CuadradoArreglo (N[], int 5);*/

    ///Ejercicio 3.
   /*int N[]= {1,2,3,4,5};

   ArregloInverso(N[], 5);*/

   int N[]={1,5,6,7,8};
   SumaArreglo(N[],5);



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
void CuadradoArreglo (int Z[], int cantVal)
{
    int i = 0;


    for (i=0; i<cantVal, i++)
    {
        Z[i]= i*i;
        printf("el cuadrado es... \n &d", Z[i]);
    }

}
///(3)Escriba un programa que dado un arreglo...........................
///   de números enteros, genere otro en orden inverso.

void ArregloInverso (int Z[], int cantVal)
{
      int i =0;

      for (i=cantVal-1; i>=0;i--)
      {
          printf("%d",Z[i]);
      }

}
///(4){1,5,6,7,8} escribir un programa que genere otro arreglo con la suma del..............................
///contenido de todo los elementos anteriores al índice actual. El resultado final
///del segundo arreglo es el siguiente: {1,6,12,19,27}.
void SumaArreglo (int Z[], int cantVal)
{
    int i,j;

    for (i=0;i<cantVal; i++)
    {
        if (i!=0)
        {
            Z[i]+=Z[i-1];
        }
    }
    for (j=0; j<cantVal; j++)
    {
        printf("nuevo arreglo: %d\n",Z[j]);

    }
}

///(5)Dadas dos pilas ordenadas......................................................
///y un arreglo vacío, hacer una función que pase los
///elementos de ambas pilas al arreglo, manteniendo el orden.
void ArregloDePila (Pila * A, Pila * B, int Z[], int cantVal)
{
    Pila aux;
    inicpila(&aux);

    cargarPila(&A);
    cargarPila (&B);

    int i=0;

    while (!pilavacia(&A))
    {
         for (i=0; i<cantVal; i++)
         {
             Z[i] == desapilar(&A);
         }


    }
    while (!pilavacia(&B))
    {
         for (i=0; i<cantVal; i++)
         {
             Z[i] == desapilar(&B);
         }


    }


}
///Mostrar los elementos de un arreglo
void MostrarArreglo (int Z[], int cantVal)
{
     int i = 0;


    for (i=0; i<cantVal, i++)
    {
        printf("&d", Z[i]);
    }
}

///(6) Hacer una función que agregue un elemento a una pila,
///    pero debe agregarlo en la base de la misma
void agregaEnBase (Pila * punteroPila, int elemento)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(punteroPila))
    {
        pasarpila(punteroPila, &aux);
        apilar(punteroPila, elemento);
        pasarpila(&aux, punteroPila);
        mostrar(punteroPila);
    }

}
///pasa elementos de la pila A a la pila B
void pasarpila (Pila * A, Pila * B)
{
    while (!pilavacia(A))
    {
        apilar(B, desapilar(A));
        mostrar(B);

    }

}
///7) Hacer una función que elimine el elemento
///    que se encuentra en la base de una pila.
void eliminaBasePila (Pila * A)
{
    Pila aux;
    inicpila(&aux);

    pasarpila(A, &aux);
    desapilar(tope(&aux));
    pasarpila(&aux, A);
}


///   -* &'s
///   -* punteros
///   -* ejercicios



