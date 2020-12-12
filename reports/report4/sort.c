/* sort.c : sort algorithm test program, by donghyeon */
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

void selection_sort(int *arr, int n);
void insertion_sort(int *arr, int n);
void bubble_sort(int *arr, int n);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
    int i, choice = 1, size = 0;
    struct timeval stime, etime, gap;
    void (*func_ptr) (int *arr, int n);

    if (argc != 3) {
        printf("Usage : sort option size\n");
        return -1;
    }
    choice = atoi(argv[1]);
    size = atoi(argv[2]);
    switch(choice) {
        case 1:
            func_ptr = selection_sort;
            printf("Selection sort - size : %d\n", size);
            break;
        case 2:
            func_ptr = insertion_sort;
            printf("Insertion sort - size : %d\n", size);
            break;
        case 3:
            func_ptr = bubble_sort;
            printf("bubble sort - size : %d\n", size);
            break;
        default:
            printf("Choose the number from 1 to 3\n");
	    break;
    }

    int *array = malloc(sizeof(int) * size);
    for (i = 0; i < size; i++) {
        array[i] = (rand() % 1000) + 1;
    }
    gettimeofday(&stime, NULL);
    func_ptr(array, size);
    gettimeofday(&etime, NULL);
    gap.tv_sec = etime.tv_sec - stime.tv_sec;
    gap.tv_usec = ((etime.tv_sec - stime.tv_sec)*1000000 + (etime.tv_usec - stime.tv_usec)) % 1000000;
    if (gap.tv_usec < 0) gap.tv_sec = gap.tv_sec - 1;
    printf("Elapsed time %ldsec : %ldusec\n", gap.tv_sec, gap.tv_usec); 
}

void selection_sort(int* arr, int n) {
    int i, j, least, temp;

	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[least]) {
				least = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[least];
		arr[least] = temp;
	}
}

void insertion_sort(int* arr, int n) {
    int i, j, key;

	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void bubble_sort(int* arr, int n) {
    bool isSorted = false;
    int i, j, temp;

	for (i = n - 1; i > 0 && !isSorted; i--) {
		isSorted = false;
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
				isSorted = false;
			}
		}
	}
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
