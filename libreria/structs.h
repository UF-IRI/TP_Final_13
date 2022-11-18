#pragma once
#include <string>
using namespace std;

struct PacientesStruct {
	int dni;
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
	int dniPaciente;
	string telefono;
	string celular;
	string direccion;
	string mail;
};
typedef ContactosStruct Contactos;

struct ConsultasStruct
{
	int dni;
	int diaTurno;
	int mesTurno;
	int anioTurno;

	int diaSolicitado;
	int mesSolicitado;
	int anioSolicitado;

	int presento;
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
	int dni;
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