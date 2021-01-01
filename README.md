# Simple JIT Compiler

This project is designed to illustrate the mechanism used in **JIT** compilers development.

## Using

C++ via g++:

```
g++ jit.cpp -o jit-cpp
./jit-cpp
```

C via gcc:

```
gc jit.c -o jit-c
./jit-c
```

Note: This also works if you enable `-m32` flag on your compiler. (e.g: `gcc jit.c -o jit -m32`)

However, this has architectural limitations and does not works everywhere.

[X86 Opcode and Instruction Reference Home](http://ref.x86asm.net/coder32.html#x00)

## x86 Instructions

Disassembling your assembly or compiled code shows you both the instructions and the machine code that implements them. 

Not only are there hundreds of different x86 instructions, there can be dozens of different machine code encodings for a given instruction (see opcodes in numerical order).  Here are a few examples:

Name | Machine code | Description
-------- | ------------ | -------------
add | 0x03 ModR/M |	Add one 32-bit register to another.
mov |	0x8B ModR/M |	Move one 32-bit register to another.
mov |	0xB8 DWORD |	Move a 32-bit constant into register eax.
ret |	0xc3 | 	Returns from current function.
xor | 	0x33 ModR/M |	XOR one 32-bit register with another.
xor | 	0x34 BYTE |	XOR register al with this 8-bit constant.
  
#### Credit

Thanks to Philip Bohun and Dr. Lawlor (Lecture).

---------

# Max Base

My nickname is Max, Programming language developer, Full-stack programmer. I love computer scientists, researchers, and compilers. ([Max Base](https://maxbase.org/))

## Asrez Team

A team includes some programmer, developer, designer, researcher(s) especially Max Base.

[Asrez Team](https://www.asrez.com/)
