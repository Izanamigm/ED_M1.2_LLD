#include <stdio.h>
#include <stdlib.h>

//Declaracion de funciones
void menu();
void menu2();
void insertarincio();
void insertarfinal();
void insertarposicion();
void eliminarincio();
void eliminarfinal();
void eliminarposicion();
void mostrar();
void recorrer();
void buscar();
void ordas();
void ordde();
void eliminardat();

//Declaracion de estructura NODO DOBLEMENTE ENLAZADO
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
}NODO;

//declaracion de nodo cabeza
NODO *cabeza = NULL;

int main()
{
    //Llamada a la funcion menu
    menu();
    return 0;
}

void menu()
{
    int opcion;
    do
    {
        printf(" __________________________________________________ \n"
                "| 1. Insertar al inicio                            |\n"
                "| 2. Insertar al final                             |\n"
                "| 3. Insertar en una posicion                      |\n"
                "| 4. Eliminar al inicio                            |\n"
                "| 5. Eliminar al final                             |\n"
                "| 6. Eliminar en una posicion                      |\n"
                "| 7. Mostrar                                       |\n"
                "| 8. Recorrer                                      |\n"
                "| 9. Extra                                         |\n"
                "| 10. Salir                                        |\n"
                "|__________________________________________________|\n");
        printf(" Ingrese una opcion: "); scanf("%d", &opcion); //lectura de la opcion
        //condicion para llamar a las funciones
        switch(opcion)
        {
            case 1: insertarincio(); break;
            case 2: insertarfinal(); break;
            case 3: //insertarposicion(); break;
            case 4: //eliminarincio(); break;
            case 5: //eliminarfinal(); break;
            case 6: //eliminarposicion(); break;
            case 7: mostrar(); break;
            case 8: //recorrer(); break;
            case 9: menu2(); break;
            case 10: printf("Saliendo del programa..."); break;
            //opcion por defecto en caso de que el usuario ingrese una opcion incorrecta
            default: printf("Opcion incorrecta, intente de nuevo\n"); 
        }
    }while(opcion != 8); //condicion para salir del menu principal
}

//Funcion para insertar al inicio

void insertarincio()
{
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    printf(" Ingrese el dato: "); scanf("%d", &nuevo->dato);
    //enlazamiento del nuevo nodo
    nuevo->siguiente = cabeza;
    nuevo->anterior = NULL;
    //condicion para verificar si la lista esta vacia
    if(cabeza != NULL)
    {
        cabeza->anterior = nuevo;
    }
    //cabeza apunta al nuevo nodo
    cabeza = nuevo;
}

//Funcion insertar al final
void insertarfinal()
{
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    printf(" Ingrese el dato: "); scanf("%d", &nuevo->dato);
    //Enlazamiento del nuevo nodo
    nuevo->siguiente = NULL;
    //condicion para verificar si la lista esta vacia
    if(cabeza == NULL)
    {
        nuevo->anterior = NULL;
        cabeza = nuevo;
    }
    else
    {
        NODO *actual = (NODO*)malloc(sizeof(NODO));
        actual = cabeza;
        while(actual->siguiente != NULL)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

//Funcion para insertar en una posicion
void insertarposicion()
{
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    int posicion;
    printf(" Ingrese la posicion: "); scanf("%d", &posicion);
    //condicion si la posicion es 1 se llama a la funcion insertar al inicio
    if(posicion == 1)
    {
        insertarincio();
    }//condicion si la posicion es igual al numero de nodos se llama a la funcion insertar al final
    else if(posicion == numeroNodos())
    {
        insertarfinal();
    }
    printf(" Ingrese el dato: "); scanf("%d", &nuevo->dato);
    //condicion para verificar si la posicion es valida
    if(cabeza == NULL)
    {
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
        cabeza = nuevo;
    }
    else
    {
        NODO *actual = (NODO*)malloc(sizeof(NODO));
        actual = cabeza;
        int i = 1;
        while(i < posicion-1)
        {
            actual = actual->siguiente;
            i++;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
        nuevo->siguiente->anterior = nuevo;
    }
}

//Funcion de mostrar

void mostrar()
{
    NODO * actual = (NODO*)malloc(sizeof(NODO));
    actual = cabeza;
    if(cabeza != NULL)
    {
        while(actual != NULL)
        {
            printf(" %d <-> ", actual->dato);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
    else
    {
        printf(" La lista esta vacia\n");
    }

}

//menu extra de funciones para el usuario
void menu2()
{
    printf(" __________________________________________________ \n"
            "| 1. Buscar                                        |\n"
            "| 2. Ordenar de menor a mayor                      |\n"
            "| 3. Ordenar de mayor a menor                      |\n"
            "| 4. Eliminar dato                                 |\n"
            "| 5. Salir                                         |\n"
            "|__________________________________________________|\n");
    int opcion;
    printf(" Ingrese una opcion: "); scanf("%d", &opcion);
    switch(opcion)
    {
        case 1: buscar(); break;
        case 2: ordas(); break;
        case 3: ordde(); break;
        case 4: eliminardat(); break;
        case 5: printf("Regresando a menu principal..."); break;
        default: printf("Opcion incorrecta, intente de nuevo\n");
    }
}