#ifndef ULA_H
#define ULA_H

#include "../include/registradores.h"
#include <iostream>
using namespace std;

class ULA {

  private:

  public:
    ULA();
    
    void ADD(int dest, int fa, int fb);
    void ADDC(int dest, int fa, int fb);

    void SUB(int dest, int fa, int fb);
    void SUBC(int dest, int fa, int fb);
    void SUBR(int dest, int fa, int fbm);
    void SUBRC(int dest, int fa, int fb);

    void AND(int dest, int fa, int fb);
    void OR(int dest, int fa, int fb);
    void XOR(int dest, int fa, int fb);

    void RRL(int dest, int fa, int fb);
    void RRLC(int dest, int fa, int fb);
    void RRA(int dest, int fa, int fb);
    void RRAC(int dest, int fa, int fb);

    void RLL(int dest, int fa, int fb);
    void RLLC(int dest, int fa, int fb);
    void RLA(int dest, int fa, int fb);
    void RLAC(int dest, int fa, int fb);

    void RRL(int dest, int fa, int fb);
    void RRLC(int dest, int fa, int fb);
    void RRA(int dest, int fa, int fb);
    void RRAC(int dest, int fa, int fb);

    void RLL(int dest, int fa, int fb);
    void RLLC(int dest, int fa, int fb);
    void RLA(int dest, int fa, int fb);
    void RLAC(int dest, int fa, int fb);

};
#endif