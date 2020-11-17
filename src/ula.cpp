#include "../include/ula.h"

ULA::ULA()
{ 
  
}

void ULA::ADD(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, fa + fb);
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

void ULA::ADDC(int dest, int fa, int fb){

}

void ULA::SUB(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, fa - fb + 1);
}

void ULA::SUBC(int dest, int fa, int fb){

}

void ULA::SUBR(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, fb - fa + 1);
}

void ULA::SUBRC(int dest, int fa, int fb){
	
}

void ULA::AND(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, fa & fb);
}

void ULA::OR(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, fa | fb);
}

void ULA::XOR(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, fa ^ fb);
}

void ULA::RRL(int dest, int fa, int fb){

}
void ULA::RRLC(int dest, int fa, int fb){

}
void ULA::RRA(int dest, int fa, int fb){

}
void ULA::RRAC(int dest, int fa, int fb){

}

void ULA::RLL(int dest, int fa, int fb){

}
void ULA::RLLC(int dest, int fa, int fb){

}
void ULA::RLA(int dest, int fa, int fb){

}
void ULA::RLAC(int dest, int fa, int fb){

}

void ULA::SRL(int dest, int fa, int fb){

}
void ULA::SRLC(int dest, int fa, int fb){

}
void ULA::SRA(int dest, int fa, int fb){

}
void ULA::SRAC(int dest, int fa, int fb){

}

void ULA::SLL(int dest, int fa, int fb){

}
void ULA::SLLC(int dest, int fa, int fb){

}
void ULA::SLA(int dest, int fa, int fb){

}
void ULA::SLAC(int dest, int fa, int fb){

}