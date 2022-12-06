#include"structs.h"
#include"secretaria.h"
#include <iostream>
#include<sstream>

#include <fstream>


int mainSecretria(string pahtPosiblesRetornantes, string pathRetornantesConfirmados) {
	ifstream posiblesRetornantes;
	Retornantes* listaPosiblesReotrnantes = new Retornantes[0];
	Retornantes aux;
	int tam = 0;
	string registro[CANTIDAD_COLUMNAS];
	string linea, palabra;
	int campo = 0;

	posiblesRetornantes.open(pahtPosiblesRetornantes);
	if (!(posiblesRetornantes.is_open())) {
		return -1;
	}
	if (posiblesRetornantes.good()) {
		//cabecera
		getline(posiblesRetornantes, linea);
	}
	while (getline(posiblesRetornantes, linea)) {
		istringstream streamLinea(linea);
		campo = 0;
		while (getline(streamLinea, registro[campo++], ',')) {
		}
		aux = crearRetornantes(registro);
		agregarPacientes(listaPosiblesReotrnantes, aux, &tam);
	}
	posiblesRetornantes.close();
	secretaria(listaPosiblesReotrnantes, tam,pathRetornantesConfirmados);
	delete[]listaPosiblesReotrnantes;
	return 0;
}

void agregarPacientes(Retornantes*& listaPosiblesretornantes, Retornantes aux, int* tam) {
	*tam += 1;
	Retornantes* listaAux = new Retornantes[*tam];

	for (int i = 0; i < *tam - 1; i++) {
		listaAux[i] = listaPosiblesretornantes[i];
	}
	listaAux[*tam - 1] = aux;
	delete[]listaPosiblesretornantes;
	listaPosiblesretornantes = listaAux;
}
void secretaria(Retornantes*& listaPosiblesReotrnantes, int tam, string pathRetornantesConfirmados) {
	int opcion, posicion;
	string dni;
	mostrarMenu();

	while (cin >> opcion && opcion != 3) {
		
		switch (opcion)
		{
		case 1:
			imprimirLista(listaPosiblesReotrnantes, tam);
			break;
		case 2:
			cout << "\nIngrese el DNI del paciente: " << endl;
			cin >> dni;
			posicion = buscarPaciente(listaPosiblesReotrnantes, tam,dni);
			retornates(listaPosiblesReotrnantes, tam, posicion, pathRetornantesConfirmados);
			break;
		default:
			cout << "Opci'on incorrecta. Pulse 3 para salir";
			break;
		}
		mostrarMenu();
	}
}
void mostrarMenu() {
	cout << "MENU" << endl;
	cout << "ingrese una opcion: " << endl;
	cout << "1) Mostrar la lista de pacientes retornantes" << "\n2) Bucacar al paciente " << endl;
	cout << "3) Cerrar el programa" << endl;
}



void imprimirLista(Retornantes*& listaPosiblesReotrnantes, int tam) {

	for (int i = 0; i < tam; i++)
	{
		cout << "\nPaciente: " << listaPosiblesReotrnantes[i].nombre << " " << listaPosiblesReotrnantes[i].apellido << endl;
		cout << "\nDNI: " << listaPosiblesReotrnantes[i].dni << "\nTelefono:  " << listaPosiblesReotrnantes[i].telefono << endl;
		cout << "\nCelular: " << listaPosiblesReotrnantes[i].celular << endl;
	}
}


int buscarPaciente(Retornantes*& listaPosiblesRetornantes, int tam, string dni) {
	int posicion, i;
	posicion = 0;
	for (i = 0; i < tam; i++) {
		if (listaPosiblesRetornantes[i].dni == dni) {
			posicion = i;
			break;
		}
	}
	if (i == tam) {
		cout << "El paciente no fue encontrado" << endl;
		return -1;
	}
	return posicion;
}


void retornates(Retornantes*& listaPosiblesRetornates, int tam, int posicion, string pathRetornantesConfirmados) {
	int respuestaRetorna;
	int respuestaNuevaConsulta;
	int largo = 0;
	string nuevafecha;
	
	Retornantes* listaArchivados = new Retornantes[0];
	Retornantes noRetorna;


	cout << " " << listaPosiblesRetornates[posicion].nombre << " " << listaPosiblesRetornates[posicion].apellido << " " << listaPosiblesRetornates[posicion].celular << " " << listaPosiblesRetornates[posicion].telefono << endl;
	cout << " " << listaPosiblesRetornates[posicion].turno << endl;

	do {
		cout << "¿El paciente desea retornar?" << endl;
		cout << "1)Si" << endl;
		cout << "2)No" << endl;
		cout << "3)No se contacto" << endl;
		cin >> respuestaRetorna;

		if (respuestaRetorna == 2)
		{
			noRetorna = listaPosiblesRetornates[posicion];
			agregarPacientes(listaArchivados, noRetorna, &largo);
		}

		else if (respuestaRetorna == 3)
		{
			break;
		}

		else if (respuestaRetorna == 1)
		{
			cout << "Ingrese dia, mes y año de la nueva consulta";
			cin >> nuevafecha;
			string obrasocial;
			listaPosiblesRetornates[posicion].turno = nuevafecha;


			do {
				cout << "¿El paciente sigue teniendo la misma cobertura medica? " << endl;
				cout << "1)Si" << endl;
				cout << "2)No" << endl;
				cin >> respuestaNuevaConsulta;

				if (respuestaNuevaConsulta == 2)
				{
					cout << "Ingrese el nombre de la nueva cobertura médica";
					cin >> obrasocial;
					listaPosiblesRetornates[posicion].obraSocial = obrasocial;
				}
				else if (respuestaNuevaConsulta == 1)
				{
					break;
				}
				else
				{
					cout << "Seleccione una opcion valida" << endl;
				}

			} while (respuestaNuevaConsulta != 1 && respuestaNuevaConsulta != 2);
			grabarRetornantes(listaPosiblesRetornates[posicion], pathRetornantesConfirmados);
		}
		else
		{
			cout << "Seleccione una opcion valida" << endl;
		}
	} while (respuestaRetorna != 1 && respuestaRetorna != 2 && respuestaRetorna == 3);
}

Retornantes crearRetornantes(string* registro) {
	Retornantes aux;
	aux.dni = registro[0];
	aux.nombre = registro[1];
	aux.apellido = registro[2];
	aux.obraSocial = registro[3];
	aux.celular = registro[4];
	aux.telefono = registro[5];
	aux.turno = registro[6];
	return aux;
}

void inicializarArchivoRetornantes(string retornantesConfirmados){
	char comma = ',';
	ofstream retornantesConf;
	retornantesConf.open(retornantesConfirmados);
	if (!(retornantesConf.is_open())) {
		cout << "El Archivo no se encontro";
	}
	retornantesConf << "Dni" << comma << "Nombre" << comma << "Apellido" << comma << "ObraSocial" << comma << "Celular" << comma << "Telefono" << comma << "fechaTurno" << endl;
	retornantesConf.close();
}
void grabarRetornantes(Retornantes confirmado, string retornantesConfirmados) {
	char comma = ',';
	ofstream retornantesConf;
	retornantesConf.open(retornantesConfirmados,ios::app);
	if (!(retornantesConf.is_open())) {
		cout << "El Archivo no se encontro";
	}
	retornantesConf << confirmado.dni << comma << confirmado.nombre << comma << confirmado.apellido << comma << confirmado.obraSocial << comma << confirmado.celular << comma << confirmado.telefono << comma << confirmado.turno << endl;
	retornantesConf.close();
}