#include <emmintrin.h>
#include <smmintrin.h>
#include <stdio.h>

#define N 4

void getMatrixValues(__m128i matrix[N]) {

    printf("------ Get Matrix Values ------\n");

    for (int i = 0; i < N; i++) {

        int values[] = {0, 0, 0, 0};
        
        int value;

        for (int j = 0; j < N; j++) {

            printf("Value [%d, %d]: ", i, j);
            scanf("%d", &value);
            values[j] = value;

        }

        matrix[i] = _mm_set_epi32(values[3], values[2], values[1], values[0]);
        
    }

    printf("-------------------------------\n\n");
    
}

__m128i createVector() {
    
    int values[] = {0, 0, 0, 0};
    
    int value;

    printf("------ Get Vector Values ------\n");

    for (int i = 0; i < N; i++) {

        printf("Value [%d]: ", i);
        scanf("%d", &value);
        values[i] = value;

    }

    __m128i vector = _mm_set_epi32(values[3], values[2], values[1], values[0]);

    printf("-------------------------------\n\n");

    return vector;

}

void multMatrixVector(__m128i result[N], __m128i matrix[N], __m128i vector) {

    for (int i = 0; i < N; i++) {

        result[i] = _mm_mullo_epi32(matrix[i], vector);

    }

}

void showMatrix(__m128i matrix[N]) {

    printf("------------ Matrix -----------\n");

    for (int i = 0; i < N; i++) {

	    printf("%d \t", _mm_extract_epi32(matrix[i], 0));       
        printf("%d \t", _mm_extract_epi32(matrix[i], 1));
        printf("%d \t", _mm_extract_epi32(matrix[i], 2));
        printf("%d \t", _mm_extract_epi32(matrix[i], 3));

        printf("\n");

    }

    printf("-------------------------------\n\n");

}

int main(int argc, char const *argv[]) {

    __m128i matrix[N], result[N];

    getMatrixValues(matrix);

    showMatrix(matrix);

    __m128i vector = createVector();

    multMatrixVector(result, matrix, vector);

    printf("----------- Result ------------\n");

    showMatrix(result);

    return 0;
    
}