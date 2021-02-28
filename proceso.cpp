#include "proceso.h"

Proceso::Proceso(std::string nombre, std::string operacion, unsigned int ID, 
                 unsigned int tiempoMax) : nombre(nombre), ID(ID),
                 tiempoMax(tiempoMax), operacion(operacion)
{}

Proceso::~Proceso()
{}

const unsigned int& Proceso::getID() const
{ return this->ID; }
const unsigned int& Proceso::getTiempoMax() const
{ return this->tiempoMax; }
const std::string& Proceso::getNombre() const
{ return this->nombre; }
const std::string& Proceso::getOperacion() const
{ return this->operacion; }

//Setters validados
bool Proceso::setNombre(const std::string& nombre)
{
    std::regex validacion("[a-zA-Z][a-zA-Z0-9]{2,}");
    if (std::regex_match(nombre, validacion)){
        this->nombre = nombre;
        return true;
    }
    return false;
}

bool Proceso::setOperacion(const std::string& operacion)
{
    std::regex validacion("(-?\\s*\\d\\s*[-|+|*|/|%]\\s*-?\\s*\\d)");
    if (std::regex_match(operacion, validacion)) {
        this->operacion = operacion;
        return true;
    }
    return false;
}

bool Proceso::setID(const std::string& ID)
{
    std::regex validacion("[0-9]{1,5}");
    if (std::regex_match(ID, validacion)){
        this->ID = std::stoul(ID);
        return true;
    }
    return false;
}
bool Proceso::setTiempoMax(const std::string& tiempoMax)
{
    std::regex validacion("[0-9]+");
    if (std::regex_match(tiempoMax, validacion)){
        this->tiempoMax = stoul(tiempoMax);
        return true;
    }
    return false;
}
