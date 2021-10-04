#ifndef MACROS_H_
#define MACROS_H_

#define  SET_BIT(Reg, Bit_no) ((Reg) |= (1U << (Bit_no)))
#define  CLEAR_BIT(Reg, Bit_no) ((Reg) &=~ (1U << (Bit_no)))
#define  TOGGLE_BIT(Reg, Bit_no) ((Reg) ^= (1U << (Bit_no)))
#define  READ_BIT(Reg, Bit_no) (((Reg) & (1U << Bit_no)) >> (Bit_no))


#endif /* MACROS_H_ */