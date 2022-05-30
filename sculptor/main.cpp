#include "sculptor.h"
#include <iostream>
#include <fstream>


int main(void)
{
    Sculptor abaju(60, 60, 60);

    abaju.setColor(0,0,0,0);                //cor do suporte inferior - preto
    abaju.putEllipsoid(15,15,1,6,6,1);      //Suporte inferior

    abaju.cutVoxel(15,15,0);                //Apagar detalhe inferior

    abaju.setColor(1,1,1,0.5);               // Cor da tela - branca
    abaju.putBox(10,20,10,20,10,20);         //bloco superior (tela)

    abaju.cutBox(11,19,11,19,9,18);          //abertura quadrada inferior
    abaju.cutEllipsoid(15,15,15,5,5,8);      //Abertura circular supeior

    abaju.setColor(0,0,0,0.5);              //Cor da barra - Preta
    abaju.putBox(14,16,14,16,1,15);         // Barra do centro 15, 15, 15


    abaju.setColor(1,1,0,0.2);              //Cor da lampada - amarelo
    abaju.putSphere(15,15,15,3);            //lampada

    abaju.setColor(1,1,1,0.5);               // Cor da tela - branca
    // ajustes de furo
    abaju.putVoxel(15,20,15);
    abaju.putVoxel(20,15,15);
    abaju.putVoxel(10,15,15);
    abaju.putVoxel(15,10,15);
/*
    abaju.setColor(1.0,0,0,0);
    abaju.putBox(10,20,20,20,20,20);
    abaju.putBox(20,20,10,20,20,20);
    abaju.putBox(10,10,10,20,20,20);
    abaju.putBox(10,20,10,10,20,20);

*/
    abaju.writeOFF("abaju.off");


    //put voxel - ok
    //put box - ok
    //put Sphere - ok
    //put ellipsoid - ok

    //cut box - ok
    //cut voxel - ok
    //cut ellipsoid - ok
    //cut sphere -




/*

    *testes

     Sculptor bloco(10,10,10);
     bloco.putVoxel(9,9,9);
     bloco.writeOFF("bloco.off");


     *modelo do professor

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
