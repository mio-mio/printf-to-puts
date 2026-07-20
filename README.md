# Why Did My printf() Become puts()? Observing Compiler Transformations

## 1. Introduction
When I was studying GOT and PLT, I made a short C program to observe how the external function calls appear in a binary.

<C program screen shot>

Since the source code used printf() twice, I expected to see two calls to printf@plt in the disassembly. However, I only saw `puts@plt` in the binary. 

<objdump screenshot>

At first, I thought I had misunderstood something about GOT and PLT. But after looking into it, I realized that the compiler had transformed my printf calls into puts calls.

I initially assumed that this was caused by compiler optimization.

That made me wonder: What source-code patterns trigger specific compiler transformations?

In this post, I explore that question by comparing small variations of printf() and observing how they appear in the compiled binary.

## 2.What happened to printf()?
Compilers such as GCC (GNU compiler collection) convert source code into a machine-executable program. 

GCC may transform a function call into a simpler function or instruction sequence while preserving the program’s observable behavior.
Compiler options such as -O0, -O2, and -fno-builtin can affect these transformations. I compared the generated binaries under each configuration.


## 3. Experiment Setup
I prepared eight small C programs  and compiled with three compiler configurations: -O0, -O2, -O0 -fno-builtin. I compared the disassembly of the main() function under each configuration.

The C programs are stored in the src/ directory.

### 3-1. Cases
01: printf("hello\n");  
02: printf("hello");  
03: printf("%s\n", "hello");  
04: printf("%d\n", 123);  
05: printf("%c", ‘A’);  
06: printf("hello %s\n", name);  
07: fprintf(stdout, "hello\n");  
08: puts("hello");  

### 3-2. Compiler Options
-O0 -fno-builtin:
Disables GCC’s special built-in treatment of standard library functions.  
-O0:
Disables most optimization passes.  
-O2:
Enables a broad set of compiler optimizations.  
