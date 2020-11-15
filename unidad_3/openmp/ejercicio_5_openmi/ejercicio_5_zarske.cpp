#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    const int ARRAY_SIZE = 20;
    const int NTHREADS = 4;
    int hilo;
    omp_set_num_threads(NTHREADS);

    #pragma omp parallel private(hilo)
    {
        hilo = omp_get_thread_num();

        #pragma omp critical
            cout<< "hilo :" << hilo << endl;

        #pragma omp for schedule(static, 5)
        for (int i = 0; i <ARRAY_SIZE; i++)
        {
            #pragma omp critical    
                cout << "H: "<< hilo << "-> I: "<< i << " - " << endl;
        }
    }
}