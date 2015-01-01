#ifndef SVIDE
#define SVIDE

#include <QString>

class svideBle
{

public:
      svideBle();
     ~svideBle();

      QString characterEstado();

public:
    QString UUID_servicio;
    QString UUID_Notificacion;
    QString UUID_EscrituraLectura;

/*charEstado*/
    QString estado_info;
    float estado_tempAgua;
    float estado_tempSonda;
    int estado_timpo;


};

#endif // SVIDE
