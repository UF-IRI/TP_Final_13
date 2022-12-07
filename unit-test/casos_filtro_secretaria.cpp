#include "gmock/gmock.h"
#include "filtro.h"
#include "filtro.cpp"

namespace casos_filtro_secretaria::tests
{
	TEST(relacion, Arch1_tiempo)
	{
		Consultas* ptr, * ptr_final;
		int tam = 0;
		string path = "..\\..\\..\\..\\data_files\\input\\PruebaConsultas.csv";
		int op;
		op = Archivo1(ptr, &tam, path);
		ASSERT_THAT(op, 0);

		ptr_final = tiempo(ptr, &tam);

		EXPECT_THAT(tam, 2);

	}
	TEST(relacion, unionlistas_Arch1_Arch2_Arch3)
	{
		Consultas* con;
		Pacientes* pac;
		Contactos* ctos;
		Retornantes* ptr;
		int tam1, tam2, tam3, tam4;
		tam1 = tam2 = tam3 = tam4 = 0;
		string path1, path2, path3;
		path1 = "..\\..\\..\\..\\data_files\\input\\PruebaConsultas.csv";
		path2 = "..\\..\\..\\..\\data_files\\input\\PruebaPacientes.csv";
		path3 = "..\\..\\..\\..\\data_files\\input\\PruebaContactos.csv";
		int op1, op2, op3;
		op1 = Archivo1(con, &tam1, path1);
		op2 = Archivo2(pac, &tam2, path2);
		op3 = Archivo3(ctos, &tam3, path3);

		ptr = unionListas(con, &tam1, pac, &tam2, ctos, &tam3, &tam4);

		ASSERT_THAT(tam4, 5);

	}

	TEST(filtro, path)
	{
		string path_cualquiera = "hello world";
		int op;
		op = filtro(path_cualquiera, path_cualquiera, path_cualquiera);
		EXPECT_THAT(op, -1);
	}
	TEST(filtro, funcion_caso_base)
	{
		int op;
		string path1, path2, path3;
		path1 = "..\\..\\..\\..\\data_files\\input\\PruebaConsultas.csv";
		path2 = "..\\..\\..\\..\\data_files\\input\\PruebaPacientes.csv";
		path3 = "..\\..\\..\\..\\data_files\\input\\PruebaContactos.csv";

		op = filtro(path1, path2, path3);
		ASSERT_THAT(op, 0);

	}

	TEST(escribir, prueba)
	{
		Retornantes* ptr = new Retornantes;

		ptr->diaturno = 14;
		ptr->mesturno = 5;
		ptr->anioturno = 2020;
		ptr->nombre = "Lionel";
		ptr->apellido = "Messi";
		ptr->celular = "+54(107)1234-5678";
		ptr->dni = "45759043";
		ptr->obraSocial = "Medicus";
		ptr->telefono = "+54(123)5678-4321";
		int op;

		op = escribir(ptr, 1);

		EXPECT_THAT(op, 0);
		delete ptr;
	}

	TEST(cantidad_final, Archivo1)
	{
		Consultas* ptr;
		int tam = 0;
		int op;
		string path = "..\\..\\..\\..\\data_files\\input\\Consultas.csv";
		op = Archivo1(ptr, &tam, path);

		EXPECT_THAT(tam, 1001);

		int tam1 = 0;
		Consultas* ptr1;
		string path1 = "..\\..\\..\\..\\data_files\\input\\PruebaConsultas.csv";

		op = Archivo1(ptr1, &tam1, path1);
		EXPECT_THAT(tam1, 6);
	}
	TEST(cantidad_final, Archivo2)
	{
		Pacientes* ptr;
		int tam = 0;
		int op;
		string path = "..\\..\\..\\..\\data_files\\input\\Pacientes.csv";
		op = Archivo2(ptr, &tam, path);

		EXPECT_THAT(tam, 101);

		int tam1 = 0;
		Pacientes* ptr1;
		string path1 = "..\\..\\..\\..\\data_files\\input\\PruebaPacientes.csv";

		op = Archivo2(ptr1, &tam1, path1);
		EXPECT_THAT(tam1, 15);
	}
	TEST(cantidad_final, Archivo3)
	{
		Contactos* ptr;
		int tam = 0;
		int op;
		string path = "..\\..\\..\\..\\data_files\\input\\Contactos.csv";
		op = Archivo3(ptr, &tam, path);

		EXPECT_THAT(tam, 101);

		int tam1 = 0;
		Contactos* ptr1;
		string path1 = "..\\..\\..\\..\\data_files\\input\\PruebaContactos.csv";

		op = Archivo3(ptr1, &tam1, path1);
		EXPECT_THAT(tam1, 9);
	}

	TEST(funcion_caso_nullptr, escribir)
	{
		Retornantes* ptr = nullptr;
		int op;
		op = escribir(ptr, 5);

		EXPECT_THAT(op, -1);
	}
	TEST(funcion_caso_nullptr, tiempo)
	{
		Consultas* ptr = nullptr;
		Consultas* op;
		int tam;
		tam = 5;
		op = tiempo(ptr, &tam);

		EXPECT_THAT(op, nullptr);
	}
	TEST(funcion_caso_nullptr, unionlistas)
	{
		Consultas* ptr1 = nullptr;
		Pacientes* ptr2 = nullptr;
		Contactos* ptr3 = nullptr;
		Retornantes* ptr;
		int tam1, tam2, tam3, tam4;
		tam1 = tam2 = tam3 = tam4 = 0;
		ptr = unionListas(ptr1, &tam1, ptr2, &tam2, ptr3, &tam3, &tam4);
		EXPECT_THAT(ptr, nullptr);
	}
	TEST(funcion_caso_nullptr, resize1)
	{
		Consultas* ptr = nullptr;
		Consultas* op;
		int tam;
		Consultas aux{};
		op = resize1(ptr, aux, &tam);

		EXPECT_THAT(op, nullptr);
	}
	TEST(funcion_caso_nullptr, resize2)
	{
		Pacientes* ptr = nullptr;
		Pacientes* op;
		int tam;
		Pacientes aux{};
		op = resize2(ptr, aux, &tam);

		EXPECT_THAT(op, nullptr);
	}
	TEST(funcion_caso_nullptr, resize3)
	{
		Contactos* ptr = nullptr;
		Contactos* op;
		int tam;
		Contactos aux{};
		op = resize3(ptr, aux, &tam);

		EXPECT_THAT(op, nullptr);
	}
	TEST(funcion_caso_nullptr, resize4)
	{
		Retornantes* ptr = nullptr;
		Retornantes* op;
		int tam;
		Retornantes aux{};
		op = resize4(ptr, aux, &tam);

		EXPECT_THAT(op, nullptr);
	}
	TEST(funcion_caso_nullptr, Archivo1)
	{
		Consultas* ptr = nullptr;
		int op;
		int tam;
		string path = "..\\..\\..\\..\\data_files\\input\\PruebaConsultas.csv";
		op = Archivo1(ptr, &tam, path);

		EXPECT_THAT(op, -1);
	}
	TEST(funcion_caso_nullptr, Archivo2)
	{
		Pacientes* ptr = nullptr;
		int op;
		int tam;
		string path = "..\\..\\..\\..\\data_files\\input\\PruebaPacientes.csv";
		op = Archivo2(ptr, &tam, path);

		EXPECT_THAT(op, -1);
	}
	TEST(funcion_caso_nullptr, Archivo3)
	{
		Contactos* ptr = nullptr;
		int op;
		int tam;
		string path = "..\\..\\..\\..\\data_files\\input\\PruebaContactos.csv";
		op = Archivo3(ptr, &tam, path);

		EXPECT_THAT(op, -1);
	}

}