#include "sculptor.h"
#include <iostream>
#include <fstream>


int main(void)
{

    Sculptor abaju(60, 60, 60);

    abaju.setColor(0,0,0,1);                    //cor do suporte inferior - preto
    abaju.putEllipsoid(15,15,1,6,6,1);          //Suporte inferior

    abaju.cutVoxel(15,15,0);                    //Apagar detalhe inferior

    abaju.setColor(1,1,1,0.5);                  // Cor da tela - branca
    abaju.putBox(10,20,10,20,10,20);            //bloco superior (tela)

    abaju.cutBox(11,19,11,19,9,18);             //abertura quadrada inferior
    abaju.cutEllipsoid(15,15,15,5,5,8);         //Abertura circular supeior

    abaju.setColor(0,0,0,1);                    //Cor da barra - Preta
    abaju.putBox(14,16,14,16,1,15);             // Barra do centro 15, 15, 15


    abaju.setColor(1,1,0,1);                    //Cor da lampada - amarelo
    abaju.putSphere(15,15,15,3);                //lampada

    abaju.setColor(1,1,1,0.5);                  // Cor da tela - branca

    // ajustes de furo
    abaju.putVoxel(15,20,15);
    abaju.putVoxel(20,15,15);
    abaju.putVoxel(10,15,15);
    abaju.putVoxel(15,10,15);


    // Puchador
   // abaju.setColor(1,0,0,1);
   // abaju.putVoxel(15,17,12);
   // abaju.putBox(15,15,18,18,8,12);


    abaju.writeOFF("abaju.off");




/*
     Sculptor bloco(20,20,20);
     bloco.putVoxel(10,10,10);
     bloco.writeOFF("bloco.off");


    // *modelo do professor

     // cria um escultor cuja matriz tem 10x10x10 voxels
     Sculptor trono(10,10,10);
     // para mudar a cor do voxel
     trono.setColor(0,0,1.0,1.0); // azul
     // ativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
     trono.putBox(0,9,0,9,0,9);
     // desativa os voxels na faixa de [x,y,z] pertencendo a [0-9]
     trono.cutBox(1,8,1,9,1,9);
     // grava a escultura digital no arquivo "trono.off"
     trono.writeOFF("trono.off");
*/
}
