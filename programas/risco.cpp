#include "../include/registradores.h"
#include "../include/ula.h"
#include "../include/memoria.h"
#include "../include/funcoes.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
using namespace std;

int main() {
    MEM memoria;
    REGS registradores;
    ULA ula;
    int dados = 0, programa = 0, aux = 0, fim = 0, pos = 0, ciclos = 0;

    ifstream inFile;
    string STRING;
    string entrada, arquivo, instrucao;
    string t1t0, codigo, f1f0, kp, kg;
    string destino, op1, op2;
    int auxdestino, auxop1, auxop2;
    stringstream transformador;
    char ss2;
    string instrucoes[100];
    char *cstr;

    cout << "Insira o nome do arquivo com as intruções" << endl;
    cin >> arquivo;

    inFile.open(arquivo);
    if (!inFile) {
        cout << "Erro ao abrir o arquivo" << endl;
        return -1;
    }
    if (inFile.is_open()) {
      while (!inFile.eof()){
        inFile >> STRING;
        instrucoes[programa] = STRING;
        programa++;
      }
    }
    inFile.close();
    for(int CP = 0; CP < 128; CP++){
        cout << "PC: " << CP << endl;
        cout << "Registradores: " << endl;
        for(int i = 0; i < 32; i++){
            cout << i << ": " << registradores.get_reg(i) << " ";
        }
        cout << endl;
        cout << "Memória de dados: " << endl;
        for(int i = 128; i < 256; i++){
            cout << i << ": " << memoria.get_mem(i) << " ";
        }
        cout << endl;
        instrucao = instrucoes[CP];
        t1t0 = instrucao.substr(0,2);
        codigo = instrucao.substr(2,5);

        kp = instrucao.substr(21,11);
        kg = instrucao.substr(15,17);

        destino = instrucao.substr(10,5);
        transformador << destino;
        transformador >> auxdestino;
        auxdestino = BTD(auxdestino);

        f1f0 = instrucao.substr(8,2);
        if(f1f0 == "00"){
          //Recebe FT1 em string binario, transforma para int binario, transforma em decimal e recebe valor do registrador
          op1 = instrucao.substr(15,5);
          transformador << op1;
          transformador >> auxop1;
          auxop1 = BTD(auxop1);
          auxop1 = registradores.get_reg(auxop1);

          ss2 = instrucao[20];
          if(ss2 == '0'){
            op2 = instrucao.substr(21,5);
            transformador << op2;
            transformador >> auxop2;
            auxop2 = BTD(auxop2);
            auxop2 = registradores.get_reg(auxop2);
          }
          else{
            op2 = calculaKpe(kp);
            transformador << op2;
            transformador >> auxop2;
            auxop2 = BTD(auxop2);
          }
        }
        if(f1f0 == "01"){
          op1 = "00000";
          auxop1 = registradores.get_reg(0);
          op2 = calculaKgl(kg);
          transformador << op2;
          transformador >> auxop2;
          auxop2 = BTD(auxop2);
        }
        if(f1f0 == "10"){
          op1 = destino;
          auxop1 = registradores.get_reg(auxdestino);
          op2 = calculaKgh(kg);
          transformador << op2;
          transformador >> auxop2;
          auxop2 = BTD(auxop2);
        }
        if(f1f0 == "11"){
          op1 = destino;
          auxop1 = registradores.get_reg(auxdestino);
          op2 = calculaKgl(kg);
          transformador << op2;
          transformador >> auxop2;
          auxop2 = BTD(auxop2);
        }

        if(t1t0 == "00" || t1t0 == "00"){
          //ULA
          if(codigo == "00000"){
            //ADD
            ula.ADD(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00001"){
            //ADDC
            ula.ADDC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00010"){
            //SUB
            ula.SUB(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00011"){
            //SUBC
            ula.SUBC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00100"){
            //SUBR
            ula.SUBR(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00101"){
            //SUBRC
            ula.SUBRC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00110"){
            //AND
            ula.AND(auxdestino,auxop1,auxop2);
          }
          if(codigo == "00111"){
            //OR
            ula.OR(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01000"){
            //XOR
            ula.XOR(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01001"){
            //RRL
            ula.RRL(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01010"){
            //RRLC
            ula.RRLC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01011"){
            //RRA
            ula.RRA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01100"){
            //RRAC
            ula.RRAC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01101"){
            //RLL
            ula.RLL(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01110"){
            //RLLC
            ula.RLLC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "01111"){
            //RLA
            ula.RLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10000"){
            //RLAC
            ula.RLAC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10001"){
            //SRL
            ula.SRL(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10010"){
            //SRLC
            ula.SRLC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10011"){
            //SRA
            ula.SLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10100"){
            //SRAC
            ula.SLAC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10101"){
            //SLL
            ula.SLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10110"){
            //SRLC
            ula.SLAC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10111"){
            //SRA
            ula.SLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "11000"){
            //SRAC
            ula.SLAC(auxdestino,auxop1,auxop2);
          }
        }
        fim = 1;
        if(fim == 1){
            break;
        }
    }
    ofstream outFile ("saida.txt");
    if(outFile.is_open()){
        cout << "Registradores: " << endl;
        for(int i = 0; i < 32; i++){
            cout << i << ": " << registradores.get_reg(i) << " ";
        }
        outFile << "Ciclos: " << ciclos;
    }
    outFile.close();
    return 0;
}
