#include <stdio.h>

void hanota(int num, char A, char B, char C)
{
	if (num == 1) {
		printf("把第%d个元素从%c移到%c\n", num, A, C);
	} else {
//		printf("把第%d个元素从%c移到%c\n", num, A, B);
		hanota(num-1, A, C, B);
		printf("把第%d个元素从%c移到%c\n", num, A, C);
		hanota(num-1, B, A, C);	
	}
}

int main(void)
{
	char A = 'A';
	char B = 'B';
	char C = 'C';
	hanota(30, A, B, C);
	return 0;
}
