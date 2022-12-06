#pragma once
#include <string>
#include <time.h>
using namespace std;

struct PacientesStruct {
	string dni;
	string nombre;
	string apellido;
	char sexo;
	string natilicio;
	string estado;
	string obraSocial;
};
typedef PacientesStruct Pacientes;

struct ContactosStruct
{
	string dniPaciente;
	string telefono;
	string celular;
	string direccion;
	string mail;
};
typedef ContactosStruct Contactos;

struct ConsultasStruct
{
	string dniPaciente;
	struct tm fechaTurno;
	string fechaSolicitado;
	bool presento;
	string matriculaMedico;
};
typedef ConsultasStruct Consultas;

struct MedicosStruct
{
	string matricula;
	string nombre;
	string apellido;
	string telefono;
	string especialidad;
	int activo;

};
typedef MedicosStruct Medicos;

struct RetornantesStruct
{
	string dni;
	string nombre;
	string apellido;
	string obraSocial;
	string celular;
	string telefono;
	int diaturno;
	int mesturno;
	int anioturno;

};
typedef RetornantesStruct Retornantes;