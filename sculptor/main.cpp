#include "sculptor.h"
#include <iostream>
#include <fstream>


int main(void)
{
      Sculptor bloco(10,10,10);
      //bloco.putVoxel(9,9,9);
      bloco.writeOFF("bloco.off");
}
