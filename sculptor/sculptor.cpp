#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>




Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel **[nx];
      for (int i = 0; i < nx; i++)
      {
          v[i] = new Voxel *[ny];

          for (int j = 0; j < ny; j++)
          {
                v[i][j] = new Voxel[nz];
           }
       }
}

Sculptor::~Sculptor()
{

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
              delete []v[i][j];
         }
         delete [] v[i];
     }

    delete []v;

}


void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this ->r = r;
    this ->g = g;
    this ->b = b;
    a = alpha;


}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn =1;
    v[x][y][z].r = r;


}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn =0;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0; i <= x1; i++){
        for(int j=y0; j<= y1; j++){
            for(int k=z0; k<=z1; k++){

                  v[i][j][k].isOn =1;
            }
        }
    }
}



void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int i=x0; i <= x1; i++){
        for(int j=y0; j<= y1; j++){
            for(int k=z0; k<=z1; k++){

                  v[i][j][k].isOn =0;
            }
        }
    }

}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=0; i <= nx; i++){
        for(int j=0; j<= ny; j++){
            for(int k=0; k<=nz; k++){
                 if((pow(xcenter,2) + pow(ycenter,2) + pow(zcenter,2) <= pow(radius,2))){
                      v[i][j][k].isOn =1;
                   }
            }
        }
    }
}


void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=0; i <= nx; i++){
            for(int j=0; j<= ny; j++){
                for(int k=0; k<=nz; k++){
                     if((pow(xcenter,2) + pow(ycenter,2) + pow(zcenter,2) <= pow(radius,2))){
                          v[i][j][k].isOn =0;
                       }
                }
            }
        }

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)

{       for(int i=0; i <= nx; i++){
            for(int j=0; j<= ny; j++){
                for(int k=0; k<=nz; k++){
                     if((pow(xcenter,2)/pow(rx,2) + pow(ycenter,2)/pow(ry,2) + pow(zcenter,2)/pow(rz,2) <= 1)){
                          v[i][j][k].isOn =1;
                       }
                }
            }
        }

}


void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
        for(int i=0; i <= nx; i++){
                    for(int j=0; j<= ny; j++){
                        for(int k=0; k<=nz; k++){
                             if((pow(xcenter,2)/pow(rx,2) + pow(ycenter,2)/pow(ry,2) + pow(zcenter,2)/pow(rz,2) <= 1)){
                                  v[i][j][k].isOn =0;
                               }
                        }
                    }
                }

}

void Sculptor::writeOFF(const char *filename)
{

    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
      exit(1);
    }
    fout << "OFF \n";

    for(int i=0; i <= nx; i++){
                for(int j=0; j<= ny; j++){
                    for(int k=0; k<=nz; k++){
                        if(v[i][j][k].isOn == 1){
                            fout << 8*i<<' ' << 6*j<<' ' << 0*k <<"\n";



                        }
                    }
               }
            }





    fout << 8<<' ' << 6<<' ' << 0 <<"\n";





    fout.close();


}
