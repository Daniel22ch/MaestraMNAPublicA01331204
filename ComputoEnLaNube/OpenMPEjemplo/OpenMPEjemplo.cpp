// OpenMPEjemplo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 



#ifdef _OPENMP 

#include <omp.h> 

#else 

#define omp_get_thread_num() 0  

#endif // _OPENMP 



#define N 24 

using namespace std;

int tid;

int main()

{

    std::cout << "Regiones paralelas!\n";



    std::cout << "Verificando la ejecucion de las directivas OMP !\n";



#ifdef _OPENMP 

    std::cout << "OMP disponible y funcionando " << std::endl;

#endif // _OPENMP 



    cout << "Estableciendo la cantidad de hilos! \n";

    int nHilos;

    cout << "Cuantos hilos quieres trabajar";

    cin >> nHilos;



#ifdef _OPENMP 

    omp_set_num_threads(nHilos);

#endif // _OPENMP 



#pragma omp parallel private(tid) 

    {

        tid = omp_get_thread_num();

        cout << "el thread " << tid << "esta en marcha " << endl;

        cout << "el thread " << tid << "ha terminado " << endl;

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
