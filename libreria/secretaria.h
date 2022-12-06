#pragma once
const int CANTIDAD_COLUMNAS = 7;
void agregarPacientes(Retornantes*& listaPosiblesretornantes, Retornantes aux, int* tam);
void secretaria(Retornantes*& listaPosiblesReotrnantes, int tam);
int buscarPaciente(Retornantes *&listaPosiblesReotrnantes, int tam);
void imprimirLista(Retornantes *& listaPosiblesReotrnantes,int tam);
void retornates(Retornantes*& listaPosiblesRetornates, int tam, int posicion);
Retornantes crearRetornantes(string* registro);
void mostrarMenu();



