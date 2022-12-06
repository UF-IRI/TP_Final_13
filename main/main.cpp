#include "iri.cpp"
#include "structs.h"
#include "secretaria.h"
#include "secretaria.cpp"
#include <iostream>
//#include "filtro.h"
//#include "filtro.cpp"
int main() {

    cout << "Hello World TP_Final";
    /*int op;
    op = filtro("..\..\..\..\data_files\input\Consultas.csv", "..\..\..\..\data_files\input\Pacientes.csv", "..\..\..\..\data_files\input\Contactos.csv");

    if (op == -1)
        cout << "Hubo drama" << endl;
    else
        cout << "Todo cool" << endl;*/
    

    mainSecretria(R"(..\..\..\..\data_files\output\prueba.txt)");


    return EXIT_SUCCESS;
}
