#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include "../include/dataCurso.h"



   string DataCurso::getNomCurso()const{
      return nomCurso;
   }
   string DataCurso::getDesc()const{
      return descripcion;
   }
   dif DataCurso::getDif()const{
      return dificultad;
   }
   bool DataCurso::getHab()const{
      return habilitado;
   }
   DataIdioma DataCurso::getIdi()const{
      return idioma;
   }
   DataProfesor DataCurso::getProfe()const{
      return profe;
   }
   vector<DataLeccion> DataCurso::getLecciones()const{
      return lecciones;
   }
   list<DataInscripcion> DataCurso::getIns()const{
      return inscriptos;
   }
   list<DataCurso> DataCurso::getPrevias()const{
      return previas;
   }

   int DataCurso::getCantEjercicios()const{
      return cantEjercicios;
   }

   int DataCurso::getEsPrevia()const{
      return esPrevia;
   }

DataCurso::DataCurso(string n, string d, dif Dif, bool b, DataIdioma i, DataProfesor p, vector<DataLeccion> ls, list<DataInscripcion> is, list<DataCurso> ps, int ce, int ep){
    nomCurso = n;
    descripcion = d;
    dificultad = Dif;
    habilitado = b;
    idioma = i;
    profe = p;
    lecciones = ls;
    inscriptos = is;
    previas = ps;
    cantEjercicios = ce;
    esPrevia = ep;
}

string DataCurso::enumToString(){
   dif c = dificultad;
    switch (c)
    {
    case Principiante:
        return "Principiante";
    case Intermedio:
        return "Intermedio";
    case Avanzado:
        return "Avanzado";
    default: return "\0";
    }
 }

 string DataCurso::leccionesToString(){
   string s = "";
   if(lecciones.size() == 0){
      s = "No tiene \n";
   }else{
      for(int i = 0; i < lecciones.size(); i++){
         s += "Leccion " + to_string(i+1) + ": " + "\n" + lecciones[i].toString() + "\n";
      }
   }
   return s;
 }

 string DataCurso::inscriptosToString(){
   string s = "";
   if(inscriptos.size() == 0){
      s = "No tiene";
   }else{
      for(auto it = inscriptos.begin(); it != inscriptos.end(); ++it){
         s += (*it).toString() + "\n";
      }
   }
   return s;
 }

//Luego lo termino, me duele la cabeza
std::ostream& operator<<(std::ostream& os, DataCurso& c) {
   string s;
   if (c.habilitado == true){
      s = "Sí";
   }else{
      s = "No";
   }

    os << "Nombre: " << c.nomCurso << endl 
    << "Descripción: " << c.descripcion << endl 
    << "Dificultad: " << c.enumToString() << endl
    << "Idioma: " << c.getIdi().getNombre() << endl
    << "Profesor: " << c.getProfe().getNombre() << endl
    << "Habilitado: " << s << endl
    << "Lecciones: " << endl << endl << c.leccionesToString()
    << "Inscriptos: " << c.inscriptosToString() << endl;
    return os;
  }