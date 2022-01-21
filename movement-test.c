#include "movement.h"
#include <stdio.h>

int main() {
	for (int i = 0; i < 5; i++) {
		printf("\nRound: %d\n", i);
		move();
	}
	return 0;
}
