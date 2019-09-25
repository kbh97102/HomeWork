#include <stdio.h>


#define MAX_INDEX 10
int main() {
	int sum = 0;
	int number[MAX_INDEX];
	for (int i = 0; i < MAX_INDEX; i++) {
		scanf("%d", number[i]);
		sum += number[i];
	}

	return 0;
}