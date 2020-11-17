#include "../include/funcoes.h"

int BinaryToDecimal(int n) {
  int decimalNumber = 0;
  int base = 1;
  int temp = n;
  while (temp) {
    int lastDigit = temp % 10;
    temp = temp/10;
    decimalNumber += lastDigit*base;
    base = base*2;
  }
  return decimalNumber;
}