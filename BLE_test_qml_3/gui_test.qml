import QtQuick 2.2
import QtQuick.Controls 1.1
//import QtQuick.Window 2.0

Rectangle {
    id: page
        property string currentText: "Valor Introducido"
        property int angTemp_p: 20
        property int angTiempo_p:120

    width: 430; height: 400
    color: "black"

    Canvas {
        id:mycanvas
        anchors.rightMargin: 0
        anchors.bottomMargin: 1
        anchors.leftMargin: 0
        anchors.topMargin: -15
        anchors.fill: parent
        antialiasing: true


        onPaint: {
            var ctx = getContext("2d");
            ctx.reset();
            var centreX = width / 2;
            var centreY = height /2 -10;
            var pcAngulotemperatura = Math.PI*2* (page.angTemp_p/100);
            var pcAnguloTiempo = Math.PI*2*(page.angTiempo_p/100);
            // console.log(porcentToAngulo)

            if(true){// circulo temperatura
                // circulo temperatura gris
                ctx.beginPath();
                ctx.strokeStyle = 'rgba(45,45, 45,0.6)';
                ctx.lineWidth = 20;
                ctx.arc(centreX, centreY, width / 3+5, 0 , Math.PI *2 , true);
                ctx.stroke();
                // circulo temperatura rojo
                ctx.beginPath();
                ctx.strokeStyle = 'rgb(255, 20, 44)';
//                ctx.translate(0.9,0.9);
                ctx.lineWidth = 22;
                ctx.arc(centreX, centreY, width / 3+5, Math.PI/2*3 , Math.PI/2*3+ pcAngulotemperatura , false);
                ctx.stroke();
                // circulo temperatarura rojo oscuro
                ctx.beginPath();
                ctx.strokeStyle = '#9C1F1F';//'#731A1A';
//                ctx.translate(0.9,0.9);
                ctx.lineWidth = 24;
                ctx.arc(centreX, centreY, width / 3+5, Math.PI/2*3+pcAngulotemperatura-Math.PI/180*3 , Math.PI/2*3+ pcAngulotemperatura+Math.PI/180*1 , false);
                ctx.stroke();
                // circulo temperatarura raya blanca
                ctx.beginPath();
                ctx.strokeStyle = 'black';
                ctx.lineWidth = 20;
                ctx.arc(centreX, centreY, width / 3+5, Math.PI/2*3+pcAngulotemperatura-Math.PI/180*3 , Math.PI/2*3+pcAngulotemperatura-Math.PI/180*2.5  , false);
                ctx.stroke();
            }

            if(true){// circulo tiempo cuenta atrás
                var anguloColor_i =Math.PI/2*3
                var anguloColor = Math.PI/180*6//*
                var anguloColor_f = anguloColor_i + anguloColor
                var angulofondo_i = anguloColor_f
                var angulofondo = Math.PI/180*4//*
                var angulofondo_f = angulofondo_i + angulofondo
                var porcentColor = Math.PI*2/(anguloColor+angulofondo)*angTiempo_p/100

                for (var i=0; i<Math.PI*2/(anguloColor+angulofondo); i++){
                    ctx.beginPath();
                    ctx.strokeStyle = 'black'
                    ctx.lineWidth = 20;
                    ctx.arc(centreX, centreY,width /3.5, anguloColor_i ,anguloColor_f, false);
                    ctx.stroke();

                    if(i<porcentColor-1){
                        ctx.beginPath();
                        ctx.strokeStyle = 'white'
                        ctx.lineWidth = 15;
                        ctx.arc(centreX, centreY,width /3.5,anguloColor_f,anguloColor_f+angulofondo , false );
                        ctx.stroke();
                    }
                    if(i>porcentColor-1 && i<porcentColor){
                        ctx.beginPath();
                        ctx.strokeStyle = 'yellow'
                        ctx.lineWidth = 15;
                        ctx.arc(centreX, centreY,width /3.5,anguloColor_f,anguloColor_f+angulofondo , false );
                        ctx.stroke();
                    }

                    else if (i>porcentColor-1){
                        ctx.beginPath();
                        ctx.strokeStyle = 'rgb(40,40, 45)' //gris
                        ctx.lineWidth = 15;
                        ctx.arc(centreX, centreY,width /3.5,anguloColor_f,anguloColor_f+angulofondo , false );
                        ctx.stroke();
                    }
                    anguloColor_i = anguloColor_f+angulofondo
                    anguloColor_f = anguloColor_i+anguloColor
                }
            }

            if(true){// línea blanca separatoria
                ctx.beginPath();
                ctx.translate(0.9,0.9);
                ctx.strokeStyle = 'white';
                ctx.lineWidth = 2;
                ctx.moveTo(0,height/10*9);
                ctx.lineTo(width,height/10*9)
                ctx.stroke();
            }
        }

        Timer {
            interval: 500;
            repeat: true;
            running: true;
            onTriggered: {
                mycanvas.requestPaint ();
            }
        }

        Text {
            id: text_temperatura
            x: 14
            y: 374
            width: 95
            height: 50
            color: "#bd0f0f"
            text: qsTr(angTemp_p.toString())
            font.pointSize: 35
            font.family: "Waseem"
            style: Text.Normal
            font.bold: false
            verticalAlignment: Text.AlignBottom
            horizontalAlignment: Text.AlignHCenter

            Text {
                id: gradoC
                x: 79
                y: 0
                width: 33
                height: 27
                color: "#bd0f0f"
                text: qsTr("ºC")
                font.bold: true
                font.pixelSize: 16
            }
        }

        Text {
            id: text_tiempo
            x: 303
            y: 374
            width: 106
            height: 42
            color: "#5a5858"
            text: qsTr(((angTiempo_p*1.2).toFixed(0)).toString())
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignTop
            font.pointSize: 35
            font.family: "Waseem"
            style: Text.Normal
            font.bold: false

            Text {
                id: text_min
                x: 85
                y: 22
                width: 31
                height: 23
                color: "#5a5858"
                text: qsTr("min")
                font.italic: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                font.pixelSize: 15
                font.family: "Waseem"
                style: Text.Normal
                font.bold: true
            }
        }

    }




}
