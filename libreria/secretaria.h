#pragma once
#include "structs.h"
const int CANTIDAD_COLUMNAS = 7;
void agregarPacientes(Retornantes*& listaPosiblesretornantes, Retornantes aux, int* tam);
int mainSecretria(string pahtPosiblesRetornantes, string pathRetornantesConfirmados);
void secretaria(Retornantes*& listaPosiblesReotrnantes, int tam, string pathRetornantesConfirmados);
int buscarPaciente(Retornantes *&listaPosiblesReotrnantes, int tam,string dni);
void imprimirLista(Retornantes *& listaPosiblesReotrnantes,int tam);
void retornates(Retornantes*& listaPosiblesRetornates, int tam, int posicion, string pathRetornantesConfirmados);
Retornantes crearRetornantes(string* registro);
void mostrarMenu();
void grabarRetornantes(Retornantes confirmado, string retornantesConfirmados);
void inicializarArchivoRetornantes(string retornantesConfirmados);


