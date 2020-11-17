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
    string t1t0, codigo, f1f0;
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
        if(t1t0 == "00"){
          //ULA
          destino = instrucao.substr(10,5);
          f1f0 = instrucao.substr(8,2);
          if(f1f0 == "00"){
            op1 = instrucao.substr(15,5);
            ss2 = instrucao[20];
            if(ss2 == '0'){
              op2 = instrucao.substr(21,5);
            }
            else{
              //op2 = kpe
            }
          }
          if(f1f0 == "01"){
            op1 = "00000";
            //op2 = kgl
          }
          if(f1f0 == "10"){
            op1 = destino;
            //op2 = kgh
          }
          if(f1f0 == "11"){
            op1 = destino;
            //op2 = kgl
          }
          transformador << destino;
          transformador >> auxdestino;
          transformador << op1;
          transformador >> auxop1;
          transformador << op2;
          transformador >> auxop2;
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
            ula.RLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10100"){
            //SRAC
            ula.RLAC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10101"){
            //SLL
            ula.RLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10110"){
            //SRLC
            ula.RLAC(auxdestino,auxop1,auxop2);
          }
          if(codigo == "10111"){
            //SRA
            ula.RLA(auxdestino,auxop1,auxop2);
          }
          if(codigo == "11000"){
            //SRAC
            ula.RLAC(auxdestino,auxop1,auxop2);
          }
        }
        fim = 1;
        if(fim == 1){
            break;
        }
    }
    ofstream outFile ("saida.txt");
    if(outFile.is_open()){
        if(memoria.get_mem(pos+1) != 0){
            outFile << "Resultado: " << (memoria.get_mem(pos)*128) + memoria.get_mem(pos+1) << endl;
        }
        else{
            outFile << "Resultado: " << memoria.get_mem(pos) << endl;
        }
        outFile << "Ciclos: " << ciclos;
    }
    outFile.close();
    return 0;
}
