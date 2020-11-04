#include "../include/ula.h"

ULA::ULA()
{ 
  
}

void ULA::ADD(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) + r.get_reg(fb));
}

/*void ULA::ADDC(int dest, int fa, int fb){
	REGS r;
	r.LDR(reg, r.get_reg(reg) + mem);
	if(r.get_reg(reg) == 0) r.LDR(4, 1);
	else r.LDR(4, 0);
	if(r.get_reg(reg) < 0) r.LDR(3, 1);
	else r.LDR(3, 0);
	if(r.get_reg(reg) > 127) {
		r.LDR(reg, r.get_reg(reg) - 128);
		r.LDR(5, 1);
	}
	else if(r.get_reg(reg) < -127) {
		r.LDR(reg, r.get_reg(reg) + 128);
		r.LDR(5, 1);
	}
	else r.LDR(5, 0);
}*/

void ULA::SUB(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) - r.get_reg(fb) + 1);
}

/*void ULA::SUBC(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) - r.get_reg(fb) + 1);
}*/

void ULA::SUBR(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fb) - r.get_reg(fa) + 1);
}

/*void ULA::SUBRC(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fb) - r.get_reg(fa) + 1);
}*/

void ULA::AND(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) & r.get_reg(fb));
}

void ULA::OR(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) | r.get_reg(fb));
}

void ULA::XOR(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) ^ r.get_reg(fb));
}