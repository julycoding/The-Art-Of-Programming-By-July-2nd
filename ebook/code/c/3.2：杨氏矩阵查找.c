#include <stdio.h>

int young_matrix(int* matrix, int width, int height, int key)
{
    if (matrix == NULL)
        return 0;
    int i = 0, j = width - 1;
    int v = matrix[i * width + j];
    while (1) {
        if (v == key)
            return 1;
        else if (v < key && i < height - 1)
            v = matrix[(++i) * width + j];
        else if (v > key && j > 0)
            v = matrix[i * width + (--j)];
        else
            return 0;
    }
    return 0;
}

int main()
{
    int matrix[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
    int i;
    int width = 4, height = 4;
    for (i = 0; i < width * height; i++) {
        if (1 != young_matrix(matrix, width, height, matrix[i]))
            printf("error when search %d\n", matrix[i]);
    }
    printf("%d\n", young_matrix(matrix, width, height, 0));
    printf("%d\n", young_matrix(matrix, width, height, 14));
    return 0;
}
