#ifndef _CLASSINSCRIPCION_H_
#define _CLASSINSCRIPCION_H_

#include <iostream>
#include <set>
#include <map>
#include "fecha.h"

using namespace std;
class Estudiante;
class Curso;
class Leccion;
class Ejercicio;
class DataInscripcion;
class Inscripcion{
    private:
            Estudiante* estud;
            Curso* curso;
            Leccion* lecActual;
            multimap<Leccion*, Ejercicio*> ejsCompletados;
            Fecha fechaIns;
            bool aprobado;

    public:
            Inscripcion(Estudiante*, Curso*, Fecha);
            Inscripcion(Estudiante*, Curso*, Leccion*, multimap<Leccion*, Ejercicio*>, Fecha, bool);
            ~Inscripcion();

            void agregarCompletado(Leccion*, Ejercicio*);
            float obtenerProgreso();
            void removerInscripcion();
            string toString();
            DataInscripcion insToData();

            Estudiante* getEstudiante();
            Curso* getCurso();
            bool getAprobado();
            Leccion* getLecActual();
            multimap<Leccion*, Ejercicio*> getEjsCompletados();
            set<Ejercicio*> getEjsCompletadosLecActual();

            void setLecActual(Leccion*);
            void setAprobado();

};

#include "estudiante.h"
#include "curso.h"
#include "leccion.h"
#include "ejercicio.h"
#include "dataInscripcion.h"
#endif