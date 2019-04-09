#include <stdio.h>
#include <math.h>

//Вычисление максимума
int max(int* parr, int len) {
	int maxt = parr[0];
	
	//Работа с массивом
	for (int i = 1; i < len; i++) {
		if (parr[i] > maxt) {
			maxt = parr[i];
		}
	}
	return maxt;
}
//Вычисление минимума
int min(int* parr, int len) {
	int mint = parr[0];

	//Работа с массивом
	for (int i = 1; i < len; i++) {
		if (parr[i] < mint) {
			mint = parr[i];
		}
	}
	return mint;
}

//Вычисление среднего
float mean(int* parr, int len) {
	float mean = 0;

	//Расчёт среднего
	for (int i = 0; i < len; i++) {
		mean = mean + ((float)(*(parr + i)) / len);
	}

	return mean;
}
//Вычисление отклонения
float RMS(int* parr, int len) {
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

	return sqrt(sigma);
}

int main() {
	char ch;

	do {//Длина массива
		int len;
		int* parr;
		int mint, maxt;
		float meant, RMSt;
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

		maxt = max(parr, len);

		mint = min(parr, len);

		meant = mean(parr, len);
		
		RMSt = RMS(parr, len);

		free(parr);

		printf("Maximum - %d\nMinimum - %d\nMean - %f\nRMS - %f\n", maxt, mint, meant, RMSt);

		//Повтор программы
		printf("\nDo you wish to restart program? (y/n)\n");
		getchar();
		scanf_s("%c", &ch);
	} while (ch == 'y' || ch == 'Y');

	return 0;
}