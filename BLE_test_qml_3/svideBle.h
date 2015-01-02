#ifndef SVIDE
#define SVIDE

#include <QString>

class svideBle
{

public:
      svideBle();
     ~svideBle();

      QString characterEstado();
      QString preConfigBleSammic(int pos_Ble);
public:
    QString UUID_servicio;
    QString UUID_Notificacion;
    QString UUID_EscrituraLectura;

/*BLE caractristica para Estado*/
    QString estado_info;
    int estado_tempAgua;
    int estado_tempSonda;
    int estado_tiempo_ciclo;
    int estado_tiempo_calentamiento;


};

#endif // SVIDE
