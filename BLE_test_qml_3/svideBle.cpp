#include "svideBle.h"


svideBle::svideBle (){
    UUID_servicio ="53346d6d3163424c4573337276316365";
    UUID_EscrituraLectura="53346d6d3163424c45657363726c6563,0A,08";
    UUID_Notificacion="53346d6d3163424c456e6f7479666963,10,02";

    estado_info = "reposo";

}

svideBle::~svideBle(){

}

QString svideBle::characterEstado(){
    QString return_var;
    QString var1;
    if(true){///estado del svide
        if(estado_info=="reposo"){
            var1="0";
        }
        else if(estado_info=="calentando"){
            var1="1";
        }
        else if(estado_info=="calentamientoTerminado"){
            var1="2";
        }
        else if(estado_info=="ciclo"){
            var1="3";
        }
        else if(estado_info=="pausa"){
            var1="4";
        }
        else if(estado_info=="completado"){
            var1="5";
        }
    }
    QString var2;
    var2.append(QString("%1").arg(estado_tempAgua*100)); ///temperatura agua
    QString var3 = "0000"; /// temperatura sonda
    QString var4 ;
    if(estado_info=="calentando") var4=(QString("%1").arg(estado_tiempo_calentamiento,3,16)).replace(QString(" "),QString("0"));
    else if(estado_info=="ciclo" || estado_info=="pausa") var4= (QString("%1").arg(estado_tiempo_ciclo,3,16)).replace(QString(" "),QString("0"));

    if(var1=="2" || var1=="5" || var1=="0"){
        var4="000";
    }
    return return_var = var1+var2+var3+var4;
}

