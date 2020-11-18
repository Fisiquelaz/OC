#include "../include/funcoes.h"

int BTD(int n) {
  int decimal = 0;
  int base = 1;
  int temp = n;
  while (temp) {
    int lastDigit = temp % 10;
    temp = temp/10;
    decimal += lastDigit*base;
    base = base*2;
  }
  return decimal;
}

string calculaKpe(string kp){
  string kpe="";
  for(int i = 0; i < 22; i++){
    kpe += kp[0];
  }
  for(int i = 0; i < 10; i++){
    kpe += kp[1+i];
  }
  return kpe;
}

string calculaKgh(string kg){
  string kgh="";
  for(int i = 0; i < 16; i++){
    kgh += kg[0];
  }
  for(int i = 0; i < 16; i++){
    kgh += kg[1+i];
  }
  return kgh;
}

string calculaKgl(string kg){
  string kgl="";
  for(int i = 0; i < 16; i++){
    kgl += kg[0];
  }
  for(int i = 0; i < 16; i++){
    kgl += kg[1+i];
  }
  return kgl;
}