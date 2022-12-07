#include <filtro.h>

int filtro(string path1, string path2, string path3)
{
    Consultas* lista1;
    Consultas* lista2 = new Consultas[0];
    Consultas* lista3 = new Consultas[0];
    int tam1 = 0;
    int tam2 = 0;
    int i;
    Pacientes* lista4;
    Pacientes* lista5 = new Pacientes[0];

    int tam4 = 0;
    int tam5 = 0;
    int j;
    int op;

    op = Archivo1(lista1, &tam1, path1);//cargo todas las consutas en una lista.
    if (op == -1)
        return -1;
    for (i = 0; i < tam1; i++)
    {
        if (lista1[i].presento == false)//filtro por ausencias en las consultas.
        {
            lista2 = resize1(lista2, lista1[i], &tam2); //copio en la lista2 solo aquellos pacientes que no asistieron a su ultima consulta
        }
    }

    delete[] lista1;
    lista1 = nullptr;
    lista3 = tiempo(lista2, &tam2); //filtro por tiempo.

    delete[] lista2;
    lista2 = nullptr;

    op = Archivo2(lista4, &tam4, path2);// cargo los datos del archivo a la lista.
    if (op == -1)
        return -1;

    for (i = 0; i < tam4; i++) // filtro lista pacientes.
    {
        if (lista4[i].estado == "n/c")
        {
            lista5 = resize2(lista5, lista4[i], &tam5);// copio en la lista5 solo aquellos pacientes que no esten fallecidos o internados.
        }

    }

    delete[] lista4;
    lista4 = nullptr;

    Contactos* lista6 = new Contactos[0];
    int tam6 = 0;
    op = Archivo3(lista6, &tam6, path3);
    if (op == -1)
        return -1;


    Retornantes* listafinal = new Retornantes[0];
    int tamf = 0;


    listafinal = unionListas(lista3, &tam2, lista5, &tam5, lista6, &tam6, &tamf);  //uno las 3 listas ya filtradas.

    delete[] lista3;
    lista3 = nullptr;
    delete[] lista5;
    lista5 = nullptr;
    delete[] lista6;
    lista6 = nullptr;

    op = escribir(listafinal, tamf);

    delete[] listafinal;
    listafinal = nullptr;

    if (op == -1)
        return -1;

    return 0;
}
Retornantes* unionListas(Consultas*& lista1, int* tam1, Pacientes*& lista2, int* tam2, Contactos*& lista3, int* tam3, int* tam4)
{
    if (lista1 == nullptr || lista2 == nullptr || lista3 == nullptr)
    {
        Retornantes* ptr = nullptr;
        return ptr;
    }

    int i, j, k;
    string dni;
    Retornantes* listaf = new Retornantes[0];
    Retornantes aux;
    int tamf = 0;

    for (i = 0; i < *tam1; i++) //recorro la lista de ultimas consultas
    {
        dni = lista1[i].dniPaciente;// me guardo un dni

        for (j = 0; j < *tam2; j++)
        {
            if (dni == lista2[j].dni) //recorro la lista de pacientes buscando coincidencia con el dni
            {
                for (k = 0; k < *tam3; k++)
                {
                    if (dni == lista3[k].dniPaciente) //recorro la lista de contactos buscando coincidencia con el dni
                    {
                        aux.dni = lista1[i].dniPaciente;
                        aux.nombre = lista2[j].nombre;
                        aux.apellido = lista2[j].apellido;
                        aux.obraSocial = lista2[j].obraSocial;
                        aux.celular = lista3[k].celular;
                        aux.telefono = lista3[k].telefono;
                        aux.diaturno = lista1[i].fechaTurno.tm_mday;
                        aux.mesturno = lista1[i].fechaTurno.tm_mon;
                        aux.anioturno = lista1[i].fechaTurno.tm_year;

                        listaf = resize4(listaf, aux, &tamf);//copio en la lista final solo aquellos pacientes que se encuentren en las 3 listas
                        break;

                    }

                }
                break;
            }
        }
    }
    *tam4 = tamf; // tamf va a ser la cantidad de coincidencias que hubo entre las 3 listas, por ende la cantidad final de pacientes a contactar 
    return listaf;
}

int escribir(Retornantes*& lista, int k)
{
    if (lista == nullptr)
        return -1;
    ofstream fp;
    char comma = ',';
    char slash = '/';
    fp.open("..\\..\\..\\..\\data_files\\output\\Retornantes.csv"); 
    if (!(fp.is_open()))
        return -1;
    int i = 0;
    fp << "Dni" << comma << "Nombre" << comma << "Apellido" << comma << "ObraSocial" << comma << "Celular" << comma << "Telefono" << comma << "fechaTurno" << endl;
    for (i = 0; i < k; i++)
    {
        fp << lista[i].dni << comma << lista[i].nombre << comma << lista[i].apellido << comma << lista[i].obraSocial << comma << lista[i].celular << comma << lista[i].telefono << comma << lista[i].diaturno << slash << lista[i].mesturno << slash << lista[i].anioturno << endl;


    }
    return 0;
}

Consultas* resize1(Consultas*& lista_, Consultas aux, int* tamactual)
{
    if (lista_ == nullptr)
        return lista_;
    *tamactual += 1;
    Consultas* listaAux = new Consultas[*tamactual];

    for (int i = 0; i < *tamactual - 1; i++) {
        listaAux[i] = lista_[i];
    }
    listaAux[*tamactual - 1] = aux;
    delete[]lista_;
    lista_ = listaAux;
    return lista_;
}
Pacientes* resize2(Pacientes*& lista_, Pacientes aux, int* tamactual)
{
    if (lista_ == nullptr)
        return lista_;
    *tamactual += 1;
    Pacientes* listaAux = new Pacientes[*tamactual];

    for (int i = 0; i < *tamactual - 1; i++)
    {
        listaAux[i] = lista_[i];
    }
    listaAux[*tamactual - 1] = aux;
    delete[]lista_;
    lista_ = listaAux;
    return lista_;
}
Contactos* resize3(Contactos*& lista_, Contactos aux, int* tamactual)
{
    if (lista_ == nullptr)
        return lista_;
    *tamactual += 1;
    Contactos* listaAux = new Contactos[*tamactual];

    for (int i = 0; i < *tamactual - 1; i++)
    {
        listaAux[i] = lista_[i];
    }
    listaAux[*tamactual - 1] = aux;
    delete[]lista_;
    lista_ = listaAux;
    return lista_;
}
Retornantes* resize4(Retornantes*& lista_, Retornantes aux, int* tamactual)
{
    if (lista_ == nullptr)
        return lista_;
    *tamactual += 1;
    Retornantes* listaAux = new Retornantes[*tamactual];

    for (int i = 0; i < *tamactual - 1; i++) {
        listaAux[i] = lista_[i];
    }
    listaAux[*tamactual - 1] = aux;
    delete[]lista_;
    lista_ = listaAux;
    return lista_;
}

int Archivo1(Consultas*& lista, int* tam1, string path)
{
    if (lista == nullptr)
        return -1;
    string dummy;
    char comma = ',';
    char slash = '/';
    ifstream fp;
    Consultas aux;
    Consultas* lista_aux = new Consultas[0];
    int tam = 0;

    fp.open(path); //cambio de path a "..."
    if (!(fp.is_open()))
        return -1;
    fp >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy;
    //headers 

    while (fp)
    {
        fp >> aux.dniPaciente >> comma >> aux.fechaSolicitado >> comma >> aux.fechaTurno.tm_mday >> slash >> aux.fechaTurno.tm_mon >> slash >> aux.fechaTurno.tm_year >> comma >> aux.presento >> comma >> aux.matriculaMedico;
        aux.fechaTurno.tm_hour = 0;
        aux.fechaTurno.tm_isdst = 0;
        aux.fechaTurno.tm_min = 0;
        aux.fechaTurno.tm_sec = 0;
        aux.fechaTurno.tm_yday = 0;
        aux.fechaTurno.tm_wday = 0;    //inicializo el resto de las variables

        lista_aux = resize1(lista_aux, aux, &tam);//cargo todos los pacientes en una lista
    }

    lista = lista_aux;
    fp.close();
    *tam1 = tam;
    return 0;
}
int Archivo2(Pacientes*& lista, int* tam1, string path)
{
    if (lista == nullptr)
        return -1;
    string dummy;
    char comma = ',';
    ifstream fp;
    Pacientes aux;
    Pacientes* lista_aux = new Pacientes[0];
    int tam = 0;

    fp.open(path);
    if (!(fp.is_open()))
        return -1;
    fp >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy;
    //headers

    while (fp)
    {
        fp >> aux.dni >> comma;
        getline(fp, aux.nombre, comma);
        getline(fp, aux.apellido, comma);
        fp >> aux.sexo >> comma >> aux.natilicio >> comma >> aux.estado >> comma >> aux.obraSocial;

        lista_aux = resize2(lista_aux, aux, &tam);//cargo todos los pacientes en una lista
    }

    lista = lista_aux;
    fp.close();
    *tam1 = tam;
    return 0;

}
int Archivo3(Contactos*& lista, int* tam1, string path)
{
    if (lista == nullptr)
        return -1;
    string dummy;
    char comma = ',';
    ifstream fp;
    Contactos aux;
    Contactos* lista_aux = new Contactos[0];
    int tam = 0;

    fp.open(path);
    if (!(fp.is_open()))
        return -1;
    fp >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy >> comma >> dummy;
    //headers

    while (fp)
    {
        fp >> aux.dniPaciente >> comma >> aux.telefono >> comma >> aux.celular >> comma;
        getline(fp, aux.direccion, comma);
        fp >> aux.mail;

        lista_aux = resize3(lista_aux, aux, &tam);//cargo todos los pacientes en una lista
    }

    lista = lista_aux;
    fp.close();
    *tam1 = tam;
    return 0;

}

Consultas* tiempo(Consultas*& lista2, int* tamactual)
{
    if (lista2 == nullptr)
        return lista2;
    Consultas aux;
    int tam = 0;
    int tam_ult = 0;
    Consultas* lista = new Consultas[tam];
    Consultas* lista_ultconsultas = new Consultas[tam_ult];
    int i, j, cont, contxdni, posmax;
    double seganio = 31536000;
    double segundos, max, fecha1, fecha2, fechaactual;
    time_t var1;
    posmax = 0;



    for (i = 0; i < *tamactual; i++)
    {
        lista2[i].fechaTurno.tm_mon -= 1;
        lista2[i].fechaTurno.tm_year -= 1900;


        var1 = time(NULL);

        segundos = difftime(var1, mktime(&lista2[i].fechaTurno));
        if ((segundos / seganio) < 10 && (lista2[i].fechaTurno.tm_year + 1900) > 1970)
        {
            lista = resize1(lista, lista2[i], &tam);
        }
    }



    for (i = 0; i < tam - 1; i++)
    {
        cont = 0;
        for (j = 0; j < tam - 1; j++)
        {
            if (stoi(lista[j].dniPaciente) < stoi(lista[j + 1].dniPaciente))
            {
                aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
                cont++;
            }
        }
        if (cont == 0)
            break;
    }



    for (i = 0; i < tam; i++)
    {
        fecha1 = (double)mktime(&lista[i].fechaTurno);
        fechaactual = (double)time(NULL);
        contxdni = 0;
        if (i == 0)
        {
            for (j = 0; j < tam; j++)
            {
                if (!(fecha1 < fechaactual))
                    break;
                if (stoi(lista[i].dniPaciente) == stoi(lista[j].dniPaciente))
                {
                    contxdni++;
                }
            }

            if (contxdni == 1)
            {
                lista_ultconsultas = resize1(lista_ultconsultas, lista[i], &tam_ult);
            }
            else if (contxdni > 1)
            {
                for (j = i; j < i + contxdni; j++)
                {
                    fecha2 = (double)mktime(&lista[j].fechaTurno);
                    if (j == i || fecha2 > max)
                    {
                        max = fecha2;
                        posmax = j;
                    }
                }
                lista_ultconsultas = resize1(lista_ultconsultas, lista[posmax], &tam_ult);
            }
        }
        else if (i > 0)
        {
            contxdni = 0;

            for (j = 0; j < tam; j++)
            {
                if (!(fecha1 < fechaactual))
                    break;
                if (stoi(lista[i].dniPaciente) == stoi(lista[j].dniPaciente) && stoi(lista[i].dniPaciente) != stoi(lista[i - 1].dniPaciente))
                {
                    contxdni++;
                }
            }

            if (contxdni == 1)
            {
                lista_ultconsultas = resize1(lista_ultconsultas, lista[i], &tam_ult);
            }
            else if (contxdni > 1)
            {
                for (j = i; j < i + contxdni; j++)
                {
                    fecha2 = (double)mktime(&lista[j].fechaTurno);
                    if (j == i || fecha2 > max)
                    {
                        max = fecha2;
                        posmax = j;
                    }
                }
                lista_ultconsultas = resize1(lista_ultconsultas, lista[posmax], &tam_ult);
            }
        }

    }
    for (i = 0; i < tam_ult; i++)
    {
        lista_ultconsultas[i].fechaTurno.tm_mon += 1;
        lista_ultconsultas[i].fechaTurno.tm_year += 1900;
    }

    *tamactual = tam_ult;
    delete[]lista;
    lista = nullptr;
    
    return lista_ultconsultas;

}
