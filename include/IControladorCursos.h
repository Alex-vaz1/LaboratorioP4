#ifndef _CLASSICONTROLADORCURSOS_H_
#define _CLASSICONTROLADORCURSOS_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>

using namespace std;
//enum dif {Principiante, Intermedio, Avanzado};

#include "curso.h"
#include "estudiante.h"
#include "dataCurso.h"
#include "dataIdioma.h"
#include "dataUsuario.h"
#include "dataEjercicio.h"
#include "dataLeccion.h"

class IControladorCursos{//Interfaz
   public:
        virtual void crearCurso(string nomCurso, string descCurso, dif difCurso) = 0;
        virtual void elegirProfesor(string nickProfesor) = 0;
        virtual list<DataCurso> listarCursosHab() = 0;
        virtual list<DataCurso> listarCursosNA() = 0;
        virtual void agregarPrevia(string nPrevia) = 0;
        virtual void agregarLeccionCN(string nomTema, string objLeccion) = 0;
        virtual void agregarEjercicio(string desc, string, string) = 0;
        virtual void agregarEjercicio(string desc, string, vector<string>) = 0;
        virtual void finalizarAltaCurso() = 0;
        virtual list<DataIdioma> listarIdiomasProfesor() = 0;
        //virtual void crearTraducir(string desc, string fraseT, string solT) = 0;
        //virtual void crearCompletar(string desc, string fraseC, vector<string> solC) = 0;
        virtual void eliminarCurso(string nc) = 0;
        virtual void seleccionarEstudiante(string nickE) = 0;
        virtual list<DataCurso> obtenerCursosNoAprobadosEstudiante() = 0;
        virtual void seleccionarCurso(string nombre) = 0;
        virtual list<DataEjercicio> listarEjerciciosNoAprobados() = 0;
        virtual void ingresarSolEjercicio(string resp) = 0;
        virtual bool comprobarSolucionEjercicio() = 0;
        virtual bool comprobarCompletarPalabra() = 0;
        virtual bool comprobarTraducir() = 0;
        //virtual string mostrarFraseATraducir() = 0;
        //virtual string mostrarFraseACompletar() = 0;
        virtual void ingresarSolEjercicio(vector<string> respuestas) = 0;
        virtual string enunciarEjercicio() = 0;
        virtual void seleccionarEjercicio(DataEjercicio ej) = 0;
        virtual list<DataCurso> listarCursos() = 0;
        virtual void habilitarCurso(string c) = 0;
        //virtual void obtenerInformacionCurso(DataCurso) = 0;
        virtual void elegirIdiomaProfesor(DataIdioma) = 0;
        virtual Curso* encontrarCurso(string nomCurso) = 0;
        virtual list<DataCurso> listarCursosDisponibles() = 0;
        virtual void nuevoCurso(DataCurso) = 0;
        virtual void insLeccion(string nomCurso, string nomTema, string obj) = 0;
        virtual void finalizarAgLec() = 0;
        virtual vector<DataLeccion> listarLecciones() = 0;
        virtual void darAltaEjercicio() = 0;
        virtual void seleccionarLeccion(DataLeccion l) = 0;
        virtual void finalizarInscripcion() = 0;
        virtual bool getTipoEjercicio() = 0;
        virtual bool esCursoHabilitable(string c) = 0;
        virtual void seleccionarInscripcion() = 0;
        virtual void aMimir() = 0;
        virtual bool finDeRealizarEjercicio() = 0;
        virtual ~IControladorCursos(){};
};
#endif