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

void ULA::ADDC(int dest, int fa, int fb){

}

void ULA::SUB(int dest, int fa, int fb){
	REGS r;
	r.LDR(dest, r.get_reg(fa) - r.get_reg(fb) + 1);
}

void ULA::SUBC(int dest, int fa, int fb){

}

void ULA::SUBR(int dest, int fa, int fb){
	
}

void ULA::SUBRC(int dest, int fa, int fb){
	
}

void ULA::AND(int dest, int fa, int fb){
	
}

void ULA::OR(int dest, int fa, int fb){
	
}

void ULA::XOR(int dest, int fa, int fb){
	
}

void RRL(int dest, int fa, int fb){

}
void RRLC(int dest, int fa, int fb){

}
void RRA(int dest, int fa, int fb){

}
void RRAC(int dest, int fa, int fb){

}

void RLL(int dest, int fa, int fb){

}
void RLLC(int dest, int fa, int fb){

}
void RLA(int dest, int fa, int fb){

}
void RLAC(int dest, int fa, int fb){

}

void SRL(int dest, int fa, int fb){

}
void SRLC(int dest, int fa, int fb){

}
void SRA(int dest, int fa, int fb){

}
void SRAC(int dest, int fa, int fb){

}

void SLL(int dest, int fa, int fb){

}
void SLLC(int dest, int fa, int fb){

}
void SLA(int dest, int fa, int fb){

}
void SLAC(int dest, int fa, int fb){

}