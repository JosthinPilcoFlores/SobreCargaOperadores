#ifndef _ESTUDIANTE_H_
#define _ESTUDIANTE_H_
#include <string>
class Estudiante{
        std::string nombre;
        int cui;
        int edad;
        char sexo;
        std::string semestre;
    public:
        Estudiante();
        Estudiante(std::string,int,int,char,std::string);
        //Getters
        std::string getNombre() const;
        int getCui()const;
        int getEdad()const;
        char getSexo()const;
        std::string getSemestre()const;
        //Setters
        void setNombre(std::string);
        void setCui(int);
        void setEdad(int);
        void setSexo(char);
        void setSemestre(std::string);
        friend std::ostream &operator << (std::ostream &o, const Estudiante &e);
};
Estudiante::Estudiante(){
    nombre="";
    cui=0;
    edad=0;
    sexo='I';
    semestre="";
}
Estudiante::Estudiante(std::string nombre,int cui,int edad,char sexo,std::string semestre){
    this->nombre=nombre;
    this->cui=cui;
    this->edad=edad;
    this->sexo=sexo;
    this->semestre=semestre;
}
std::string Estudiante::getNombre()const{
    return nombre;
}
int Estudiante::getCui()const{
    return cui;
}
int Estudiante::getEdad()const{
    return edad;
}
char Estudiante::getSexo()const{
    return sexo;
}
std::string Estudiante::getSemestre()const{
    return semestre;
}
void Estudiante::setNombre(std::string nombre){
    this->nombre=nombre;
}
void Estudiante::setCui(int cui){
    this->cui=cui;
}
void Estudiante::setEdad(int edad){
    this->edad=edad;
}
void Estudiante::setSexo(char sexo){
    this->sexo=sexo;
}
void Estudiante::setSemestre(std::string semestre){
    this->semestre=semestre;
}
std::ostream& operator << (std::ostream &o, const Estudiante &e){
    o << e.getNombre()<<", "<<e.getCui()<<", "<<e.getEdad()<<", "<<e.getSexo()<<", "<<e.getSemestre()<<std::endl;
    return o;
}
#endif