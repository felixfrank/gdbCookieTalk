#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void sort(long *array, size_t size) {
  int sorted;

  do {
    sorted = 1;

    for (int i = 0; i < size; ++i) {
      long *first = &array[i];
      long *second = &array[i + 1];

      if (*first <= *second) {
        continue;
      }

      sorted = 0;
      long swap_store = *second;
      *second = *first;
      *first = swap_store;
    }
  } while (sorted == 0);
}

int main(int argc, char const *argv[]) {
  struct timespec tp;
  int res = clock_gettime(CLOCK_MONOTONIC, &tp);
  srand(tp.tv_nsec);

  long data[50];
  for (int i = 0; i < rand() % sizeof(data); ++i) {
    data[i] = rand();
  }

  // printf("Unsorted array:\n [");
  // for (int i = 0; i < 49; ++i)
  // {
  //   printf("%hd, ", data[i]);
  // }
  // printf("%hd]\n", data[49]);

  sort(data, 50);

  // printf("Sorted array:\n [");
  // for (int i = 0; i < 49; ++i)
  // {
  //   printf("%hd, ", data[i]);
  // }
  // printf("%hd]\n", data[49]);
  return 0;
}