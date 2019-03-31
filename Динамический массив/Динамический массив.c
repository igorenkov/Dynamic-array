#include <stdio.h>
#include <math.h>

//Вычисление максимума/минимума
void minax(int* parr, int len) {
	int maxt = parr[0], mint = parr[0];
	
	//Работа с массивом
	for (int i = 1; i < len; i++) {
		if (parr[i] > maxt) {
			maxt = parr[i];
		}
		else if (parr[i] < mint) {
			mint = parr[i];
		}
	}
	printf("Maximum - %d\nMinimum - %d\n", mint, maxt);
}

//Вычисление среднего и отклонения
void meams(int* parr, int len) {
	float sigma = 0, mean = 0;
	//sigma - квадрат отклонения

	//Расчёт среднего
	for (int i = 0; i < len; i++) {
		mean = mean + ((float)(*(parr + i)) / len);
	}

	//Расчёт квадрата отклонения
	for (int i = 0; i < len; i++) {
		sigma = sigma + ((mean - (*(parr + i)))*(mean - (*(parr + i))) / len);
	}

	printf("Mean - %f\nRMS - %f\n", mean, sqrt(sigma));
}

int main() {
	char ch;

	do {//Длина массива
		int len;
		int* parr;
		printf("Input length: ");
		scanf_s("%d", &len);

		//Выделение памяти
		parr = malloc(sizeof(int)*len);
		if (parr == NULL) {
			printf("Can't allocate the memory. ");
			return 0;
		}

		//Инициализация массива
		printf("Input array: ");
		for (int i = 0; i < len; i++) {
			scanf_s("%d", &parr[i]);
		}

		minax(parr, len);

		meams(parr, len);

		free(parr);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');

	return 0;
}