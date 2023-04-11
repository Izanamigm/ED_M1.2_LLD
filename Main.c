#include <stdio.h>
#include <stdlib.h>

//Declaracion de funciones
void menu();
/*
void insertarincio();
void insertarfinal();
void insertarposicion();
void eliminarincio();
void eliminarfinal();
void eliminarposicion();
void mostrar();
*/

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
                "| 8. Salir                                         | \n"
                "|__________________________________________________|\n");
        printf(" Ingrese una opcion: "); scanf("%d", &opcion); //lectura de la opcion
        //condicion para llamar a las funciones
        switch(opcion)
        {
            case 1: //insertarincio(); break;
            case 2: //insertarfinal(); break;
            case 3: //insertarposicion(); break;
            case 4: //eliminarincio(); break;
            case 5: //eliminarfinal(); break;
            case 6: //eliminarposicion(); break;
            case 7: //mostrar(); break;
            case 8: printf("Saliendo del programa..."); break;
            //opcion por defecto en caso de que el usuario ingrese una opcion incorrecta
            default: printf("Opcion incorrecta, intente de nuevo\n")
        }
    }while(opcion != 8); //condicion para salir del menu principal
}

//Funcion para insertar al inicio
/*
void insertarincio()
{
    NODO *nuevo = (NODO*)malloc(sizeof(NODO));
    printf(" Ingrese el dato: "); scanf("%d", &nuevo->dato);
    nuevo->siguiente = cabeza;
    nuevo->anterior = NULL;
    if(cabeza != NULL)
    {
        cabeza->anterior = nuevo;
    }
    cabeza = nuevo;
}
*/