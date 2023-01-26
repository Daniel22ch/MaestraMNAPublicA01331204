// SolucionSumaArreglosParalela_Daniel_Chavarria.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <omp.h> 

#define NUM_MAX_HILOS 16
#define TAMANO_MAX_ARREGLOS 1000
using namespace std;

float arregloA[TAMANO_MAX_ARREGLOS], arregloB[TAMANO_MAX_ARREGLOS], arregloSuma[TAMANO_MAX_ARREGLOS];
int i;

void printArray(float* f, int cantidad);

int main()
{

    std::cout << "Suma de arreglos en paralelo!\n";
    #ifdef _OPENMP 
        std::cout << "OMP disponible y funcionando\n " << std::endl;
    #endif // _OPENMP 


    cout << "Configuracion... \n";
    int nHilos;
    int arregloSize;

    cout << "Cuantos hilos quieres trabajar:\n";
    cin >> nHilos;

    if (nHilos > NUM_MAX_HILOS)
    {
        nHilos = 16;
    }

    if(nHilos < 1)
    {   
        nHilos = 1;
    }
    omp_set_num_threads(nHilos);

    cout << "Tamano de los arreglos: \n";
    cin >> arregloSize;

    if (arregloSize > TAMANO_MAX_ARREGLOS)
    {
        arregloSize = 1000;
    }

    if (arregloSize < 1)
    {
        arregloSize = 1;
    }

    

    cout << "Creando Arreglos...\n";

    for (int j = 0; j < arregloSize; j++)
    {
        arregloA[j] = j + 1;
        arregloB[j] = j + 1.87;
    }

    cout << "Arreglos creados!\n";

    


    #pragma omp parallel for shared (arregloA,arregloB, arregloSuma, arregloSize)  private(i)  schedule (static, 5)

    for ( i = 0; i < arregloSize; i++)
    {
        arregloSuma[i] = arregloA[i] + arregloB[i];
    }

    cout << "Arreglo A:"<<endl;
    printArray(arregloA, arregloSize);
    cout << "\nArreglo B:" << endl;
    printArray(arregloB, arregloSize);
    cout << "\nArreglo C:\n" << endl;
    printArray(arregloSuma, arregloSize);

    cout << "\nFin del programa\n" << endl;

}


void printArray(float *f, int cantidad)
{
    for (int ii = 0; ii < cantidad; ii++) 
    {
        cout << f[ii] << "|";
        if (ii != 0 && ii % 10 == 0 ) 
        {
            cout << "\n";
        }
    }
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln