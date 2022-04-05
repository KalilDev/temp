#include <stdbool.h>
#include <stdio.h>

int main() {
	if (true, false) {
		puts("Condição verdadeira");
	} else {
		puts("Condição falsa");
	}
	return 0;
}
