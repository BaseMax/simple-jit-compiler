/*
 * @Name: simple-jit-compiler
 * @Author: Max Base
 * @Date 2021-01-01
 * @Repository: https://github.com/BaseMax/simple-jit-compiler
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
	unsigned char code[] = {
		0xb8, // mov
		0x00,
		0x00,
		0x00,
		0x00,

		// +5
		0x83, // add
		0xC0,
		0x05,

		// +5
		0x83, // add
		0xC0,
		0x05,

		// +5
		0x83, // add
		0xC0,
		0x05,

		0xc3, // ret
	};

	if(argc < 2) {
		fprintf(stderr, "Usage: %s <number>\n", argv[0]); // argv[0] is name of program file
		return 1; // error
	}

	int num = atoi(argv[1]);

	memcpy(&code[1], &num, 4);
	void *mem = mmap(NULL, sizeof(code), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);

	memcpy(mem, code, sizeof(code));
	mprotect(mem, sizeof(code), PROT_READ | PROT_EXEC);
	// int (*func)() = (int(*)()) mem;
	int (*func)() = reinterpret_cast<int(*)()>(mem);

	printf("Your number was: %d\n", func());

	return 0; // success
}
