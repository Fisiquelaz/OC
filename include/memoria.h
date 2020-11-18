#ifndef MEM_H
#define MEM_H

#include <iostream>
using namespace std;

class MEM
{
    private:
    	static int mem[256];
    public:
	    MEM();
	    int get_mem(int posicao);
	    void ST(int dest, int fa, int fb);
};

#endif