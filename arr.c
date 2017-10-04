#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

//#define true 1
//#define false 0
struct arr{
	int len;
	int cnu;
	int *pbase;
};

void init_arr(struct arr *parr, int len)
{
	parr->pbase = (int *)malloc(sizeof(int)*len);
	if (NULL == parr->pbase){
		printf("动态分配内存失败\n");
	} else {
		parr->len = len;
		parr->cnu = 0;
	}
}

bool isempty(struct arr *parr)
{
	if (0 == parr->len) {
		return true;
	} else {
		return false;
	}
}

bool isfull(struct arr *parr)
{
	if (parr->cnu == parr->len) {
		return true;
	} else {
		return false;
	}
}

void showarr(struct arr *parr)
{
	if (isempty(parr)) {
		printf("数组为空\n");
	} else {
		int i;
		printf("--------------------------\n");
		for (i=0; i<parr->cnu; i++) {
			printf("%d", parr->pbase[i]);
		}
		printf("\n--------------------------\n");
	}
}

bool apend(struct arr *parr, int val)
{
	if (isfull(parr)) {
		printf("数组满了\n");
		return false;
	} else {
		parr->pbase[parr->cnu] = val;
		parr->cnu++;
		return true;
	}
}

bool insert(struct arr *parr, int pos, int val)
{
	if (isfull(parr)) {
		printf("数组满了\n");
		return false;
	} else {
		int i;
		for (i=parr->cnu; i>=pos; i--) {
			parr->pbase[i] = parr->pbase[i-1];
		}
		parr->pbase[pos-1] = val;
		parr->cnu++;
		return true;
	}
}

bool delete(struct arr *parr, int pos, int *val)
{
	if (pos<1 || pos>parr->cnu) {
		printf("删除位置不合法\n");
		return false;
	} else {
		int i;
		*val = parr->pbase[pos-1];
		for (i=pos; i<parr->cnu; i++) {
			parr->pbase[i-1] = parr->pbase[i];
		}
		parr->cnu--;
		return true;
	}
}

bool inverse(struct arr *parr)
{
	if (isempty(parr)) {
		printf("倒置失败，数组为空\n");
		return false;
	} else {
		int i;
		int tmp;
		for (i=parr->cnu/2; i>0; i--) {
			tmp = parr->pbase[i-1];
			parr->pbase[i-1] = parr->pbase[parr->cnu-i];
			parr->pbase[parr->cnu-i] = tmp;
		}
		return true;
	}
}

int main(void)
{
	struct arr arr;
	init_arr(&arr, 7);
	apend(&arr, 1);
	apend(&arr, 2);
	apend(&arr, 3);
	apend(&arr, 4);
	apend(&arr, 5);
	apend(&arr, 6);
	apend(&arr, 7);
	showarr(&arr);
	inverse(&arr);
	showarr(&arr);
	int val;
	delete(&arr, 3, &val);
	printf("删除了：%d\n", val);
	showarr(&arr);
	insert(&arr, 5, 2);
	showarr(&arr);

	return 0;
}


