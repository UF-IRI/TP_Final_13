#include "iri.cpp"
#include "structs.h"
#include "secretaria.h"
//#include "secretaria.cpp"
#include <iostream>
#include "filtro.h"
#include "filtro.cpp"
int main() {
    int op;
    int pip;
    string pathRetornantesConfirmados = "..\\..\\..\\..\\data_files\\output\\RetornantesConfirmados.csv";
    op = filtro("..\\..\\..\\..\\data_files\\input\\Consultas.csv", "..\\..\\..\\..\\data_files\\input\\Pacientes.csv", "..\\..\\..\\..\\data_files\\input\\Contactos.csv");

    if (op == -1)
        cout << "Hay problema en filtro" << endl;
    inicializarArchivoRetornantes(pathRetornantesConfirmados);
    pip = mainSecretria("..\\..\\..\\..\\data_files\\output\\Retornantes.csv",pathRetornantesConfirmados);

    if (pip == -1)
        cout << "Hay problema en secretaria" << endl;

    return EXIT_SUCCESS;
}
