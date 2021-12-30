#include "mapgen.h"
#include <stdio.h>

int main() {
	genHeightmap();
	for (int x=0; x<mapLength; x++) {
		for (int y=0; y<22; y++) {
			if (y < heightmap[x]+11)
				printf("@");
			else
				printf(" ");
		}
		printf("%d\n", heightmap[x]);
	}
	return 0;
}
