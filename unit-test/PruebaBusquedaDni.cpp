#include "gmock/gmock.h"
#include "secretaria.h"
#include "secretaria.cpp"
//#include"structs.h"

namespace PruebaBusquedaDni::tests {
	TEST(PruebaBusquedaDni, DniNoExistente) {
		string dni = "0";
		Retornantes* lista = new Retornantes[1];
		lista[0].dni = 15;
		int result = buscarPaciente(lista, 1,dni);
		ASSERT_EQ(result, -1);
	}

	TEST(PruebaBusquedaDni, DniNegativo) {
		string dni = " - 11";
		Retornantes* lista = new Retornantes[1];
		lista[0].dni = 16;
		int result = buscarPaciente(lista, 1,dni);
		ASSERT_EQ(result, -1);
	}
	TEST(PruebaBusquedaDni, DniPosicion) {
		string dni = "38852819";
		Retornantes* lista = new Retornantes[2];
		lista[0].dni = 1234;
		lista[1].dni = dni;
		int result = buscarPaciente(lista, 2,dni);
		ASSERT_EQ(result, 1);
	}
	TEST(PruebaBusquedaDni, PosicionCorrecta) {
		string dni = "38852819";
		Retornantes* lista = new Retornantes[1];
		lista[0].dni = dni;
		int result = buscarPaciente(lista, 1,dni);
		ASSERT_EQ(result, 0);
	}
}