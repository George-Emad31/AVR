#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define		ASSIGN_PORT(Var , Val)	Var = Val
#define		SET_BIT(Var , BitNo)	Var = Var | (1 << BitNo)
#define		CLEAR_BIT(Var , BitNo)	Var = Var & ~(1 << BitNo)
#define		GET_BIT(Var , BitNo)	( (Var >> BitNo) & 1 )
#define		TOGGLE_BIT(Var , BitNo)	Var = Var ^ (1 << BitNo)
#define     CONC_BIT(B7,B6,B5,B4,B3,B2,B1,B0) 	CONC_BIT_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
// CONC_BIT_HELP(1,1,1,1,1,1,1,1) text replacement
#define		CONC_BIT_HELP(B7,B6,B5,B4,B3,B2,B1,B0) 	0b##B7##B6##B5##B4##B3##B2##B1##B0  
// 0b11111111 // concatnate
#endif