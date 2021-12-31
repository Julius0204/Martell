#include "mapgen.h"
#include <stdio.h>

int main() {
	genHeightmap();
	for (int x=0; x<mapLength; x++) {
		for (int y=0; y < 2*(maxHeightDiff+1); y++) {
			if (y < heightmap[x] + maxHeightDiff+1)
				printf("@");
			else
				printf(" ");
		}
		printf("%d\n", heightmap[x]);
	}
	return 0;
}
