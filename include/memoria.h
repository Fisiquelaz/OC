#ifndef MEM_H
#define MEM_H

#include <iostream>
using namespace std;

#define TAMANHO 1048576

class MEM
{
    private:
    	static int mem[TAMANHO];
    public:
	    MEM();
	    int get_mem(int posicao);
	    void ST(int dest, int fa, int fb);
};

#endif