#include <emmintrin.h>
#include <smmintrin.h>
#include <stdio.h>

#define ROWS 3
#define COLS 4

void getMatrixValues(__m128i matrix[ROWS]) {

    printf("------ Get Matrix Values ------\n");

    for (int i = 0; i < ROWS; i++) {

        int values[] = {0, 0, 0, 0};
        
        int value;

        for (int j = 0; j < COLS; j++) {

            printf("Value [%d, %d]: ", i, j);
            scanf("%d", &value);
            values[j] = value;

        }

        matrix[i] = _mm_set_epi32(values[3], values[2], values[1], values[0]);
        
    }

    printf("-------------------------------\n\n");
    
}

void showMatrix(__m128i matrix[ROWS]) {

    printf("------------ Matrix -----------\n");

    for (int i = 0; i < ROWS; i++) {

	    printf("%d \t", _mm_extract_epi32(matrix[i], 0));       
        printf("%d \t", _mm_extract_epi32(matrix[i], 1));
        printf("%d \t", _mm_extract_epi32(matrix[i], 2));
        printf("%d \t", _mm_extract_epi32(matrix[i], 3));

        printf("\n");

    }

    printf("-------------------------------\n\n");

}

__m128i getMaxValues(__m128i matrix[ROWS]) {

    __m128i max_values = _mm_set_epi32(0, 0, 0, 0);

    for (int i = 0; i < ROWS; i++) {

        max_values = _mm_max_epi32(max_values, matrix[i]);

    }

    return max_values;

}

int main(int argc, char const *argv[]) {

    __m128i matrix[ROWS];

    getMatrixValues(matrix);

    showMatrix(matrix);

    __m128i max_values = getMaxValues(matrix);

    printf("----------- Result ------------\n");

	printf("%d \t", _mm_extract_epi32(max_values, 0));
    printf("%d \t", _mm_extract_epi32(max_values, 1));
    printf("%d \t", _mm_extract_epi32(max_values, 2));
    printf("%d \t\n", _mm_extract_epi32(max_values, 3));

    printf("-------------------------------\n\n");

    return 0;

}
