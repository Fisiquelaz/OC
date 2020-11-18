#include "../include/memoria.h"

int MEM::mem[256] = {0};

MEM::MEM()
{
  
}

int MEM::get_mem(int posicao){
	return (mem[posicao]);
}

void MEM::ST(int dest, int fa, int fb){
  mem[fa+fb] = dest;
}
