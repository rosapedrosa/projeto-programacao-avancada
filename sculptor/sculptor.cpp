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
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
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
                  v[i][j][k].r = r;
                  v[i][j][k].g = g;
                  v[i][j][k].b = b;
                  v[i][j][k].a = a;
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
    for(int i=0; i <nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                 if((pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2) <= pow(radius,2))){
                      v[i][j][k].isOn =1;
                      v[i][j][k].r = r;
                      v[i][j][k].g = g;
                      v[i][j][k].b = b;
                      v[i][j][k].a = a;
                   }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i=0; i <nx; i++){
        for(int j=0; j<ny; j++){
            for(int k=0; k<nz; k++){
                 if((pow(i-xcenter,2) + pow(j-ycenter,2) + pow(k-zcenter,2) <= pow(radius,2))){
                      v[i][j][k].isOn =0;
                      v[i][j][k].r = r;
                      v[i][j][k].g = g;
                      v[i][j][k].b = b;
                      v[i][j][k].a = a;
                   }
            }
        }
    }

}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)

{       for(int i=0; i <nx; i++){
            for(int j=0; j<ny; j++){
                for(int k=0; k<nz; k++){
                     if((pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry,2) + pow(k-zcenter,2)/pow(rz,2) <= 1)){
                          v[i][j][k].isOn =1;
                          v[i][j][k].r = r;
                          v[i][j][k].g = g;
                          v[i][j][k].b = b;
                          v[i][j][k].a = a;
                       }
                }
            }
        }

}


void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{       for(int i=0; i <nx; i++){
            for(int j=0; j<ny; j++){
                for(int k=0; k<nz; k++){
                     if((pow(i-xcenter,2)/pow(rx,2) + pow(j-ycenter,2)/pow(ry,2) + pow(k-zcenter,2)/pow(rz,2) <= 1)){
                          v[i][j][k].isOn =0;
                          v[i][j][k].r = r;
                          v[i][j][k].g = g;
                          v[i][j][k].b = b;
                          v[i][j][k].a = a;
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

    int cont=0, sum =0;

    for(int i=0; i < nx; i++){
                for(int j=0; j< ny; j++){
                    for(int k=0; k< nz; k++){
                        if(v[i][j][k].isOn){
                           cont++;

                        }
                    }
               }
     }

    fout << "OFF \n";
    fout << cont*8 <<' ' << cont*6<<' ' << cont*0 <<"\n";

    for(int i=0; i<nx; i++){
                for(int j=0; j<ny; j++){
                    for(int k=0; k<nz; k++){
                     if(v[i][j][k].isOn){

                     fout<< i - 0.5 << ' ' <<j + 0.5<< ' '<<k -0.5 << std:: endl;
                     fout<< i - 0.5 << ' ' <<j - 0.5 << ' ' <<k - 0.5 << std:: endl;
                     fout<< i + 0.5 << ' ' <<j - 0.5 << ' ' <<k - 0.5 << std:: endl;
                     fout<< i + 0.5 << ' ' <<j + 0.5 << ' ' <<k - 0.5 << std:: endl;
                     fout<< i - 0.5 << ' ' <<j + 0.5 << ' ' <<k + 0.5 << std:: endl;
                     fout<< i - 0.5 << ' ' <<j - 0.5 << ' ' <<k + 0.5 << std:: endl;
                     fout<< i + 0.5 << ' ' <<j - 0.5 << ' ' <<k + 0.5 << std:: endl;
                     fout<< i + 0.5 << ' ' <<j + 0.5 << ' ' <<k + 0.5 << std:: endl;

                    }
}
             }
    }

    for(int i=0; i <nx; i++){
                for(int j=0; j<ny; j++){
                    for(int k=0; k<nz; k++){

                     if(v[i][j][k].isOn){
                     fout<< 4 << ' ' << 0+sum << ' ' << 3+sum << ' ' << 2+sum << ' ' << 1+sum << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '<< v[i][j][k].a << std:: endl;
                     fout<< 4 << ' ' << 4+sum << ' ' << 5+sum << ' ' << 6+sum << ' ' << 7+sum << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '<< v[i][j][k].a << std:: endl;
                     fout<< 4 << ' ' << 0+sum << ' ' << 1+sum << ' ' << 5+sum << ' ' << 4+sum << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '<< v[i][j][k].a << std:: endl;
                     fout<< 4 << ' ' << 0+sum << ' ' << 4+sum << ' ' << 7+sum << ' ' << 3+sum << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '<< v[i][j][k].a << std:: endl;
                     fout<< 4 << ' ' << 3+sum << ' ' << 7+sum << ' ' << 6+sum << ' ' << 2+sum << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '<< v[i][j][k].a << std:: endl;
                     fout<< 4 << ' ' << 1+sum << ' ' << 2+sum << ' ' << 6+sum << ' ' << 5+sum << ' ' << v[i][j][k].r << ' ' << v[i][j][k].g << ' ' << v[i][j][k].b << ' '<< v[i][j][k].a << std:: endl;

                     sum += 8;

                     }

}
             }
    }
    fout.close();

}
