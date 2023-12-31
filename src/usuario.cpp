#include <iostream>
#include <string>
#include <list>
#include "../include/usuario.h"
#include "../include/dataNotificacion.h"
using namespace std;

Usuario::Usuario(string nick, string contra, string descripcion, string nombre):nick(nick), contra(contra), descripcion(descripcion), nombre(nombre){}

string Usuario::getNick() const{return this->nick;}

string Usuario::getDescripcion() const{return this->descripcion;}

string Usuario::getNombre() const{return this->nombre;}

DataUsuario Usuario::getDataUsuario(){
    DataUsuario data = DataUsuario(this->nick, this->descripcion, this->nombre);
    return data;}

void Usuario::setNick(string nuevoNick){this->nick = nuevoNick;}

void Usuario::setContra(string contra){this->contra = contra;}

void Usuario::setDescripcion(string nuevaDesc){this->descripcion = nuevaDesc;}

void Usuario::setNombre(string nuevoNombre){this->nombre = nuevoNombre;}

void Usuario::agregarSuscripcion(Idioma* idi){
    this->suscripciones.insert(make_pair(idi->getNombre(),idi));
}

list<DataIdioma> Usuario::obtenerSuscripciones(){
    list<DataIdioma> sus;
    for (auto it = this->suscripciones.begin(); it != this->suscripciones.end(); it++)
    {
        sus.insert(sus.end(),it->second->getDataIdioma());
    }
    return sus;
};

void Usuario::removerSuscripcionAIdioma(Idioma* idi){
    this->suscripciones.erase(idi->getNombre());
}

bool Usuario::estaSuscritoA(Idioma* idi){
    return this->suscripciones.count(idi->getNombre()) > 0;
}

bool Usuario::operator==(const Usuario &user){
   return this->getNick() == user.getNick();
}

void Usuario::Notificar(Notificacion* noti){
    this->notificaciones.insert(make_pair(noti->getCursoNuevo(),noti));
}

list<DataNotificacion> Usuario::obtenerNotificaciones(){
    list<DataNotificacion> notis;
    for (auto it = this->notificaciones.begin(); it != this->notificaciones.end(); it++)
    {
        notis.push_back(it->second->getDataNotificacion());
    }
    return notis;
}

void Usuario::eliminarNotificacion(string nomCurso){
    if (this->notificaciones.count(nomCurso)>0)
    {
        Notificacion * borrar = this->notificaciones.find(nomCurso)->second;
        this->notificaciones.erase(nomCurso);
        delete(borrar);
    }
}

void Usuario::eliminarNotificaciones(){
    if (this->notificaciones.size() != 0)
    {
        for(auto it = this->notificaciones.begin(); it != this->notificaciones.end();it++)
        {
            Notificacion * noti = it->second;
            delete(noti);
        }
        this->notificaciones.clear();
    }
}