#ifndef _CLASSDATAESTADISTICA_H_
#define _CLASSDATAESTADISTICA_H_

#include <iostream>
#include <string>
#include <list>
#include "dataCurso.h"
using namespace std;

class DataAvance{
    private: 
        string curso;
        float avance;
    public:
        DataAvance(string, int);
        string getCurso() const;
        float getAvance() const;
};

class DataEstadisticaEstudiante{
    private:
        list<DataAvance> avancesEstudiante;
    public:
        DataEstadisticaEstudiante(list<DataAvance>);
        list<DataAvance> getAvances() const;
};

class DataEstadisticaProfesor{
    private:
        list<DataAvance> avancesCursos;
    public:
        DataEstadisticaProfesor(list<DataAvance>);
        list<DataAvance> getAvances() const;
};

class DataEstadisticaCurso{
    private:
        DataCurso curso;
        float promedioGeneral;
    public: 
        DataEstadisticaCurso(DataCurso, int);
        DataCurso getCurso() const;
        float getPromedioGeneral() const;
};

#endif