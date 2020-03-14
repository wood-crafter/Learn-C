#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *ptr, i , n1, n2;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n1);
    ptr = (int*) malloc(n1 * sizeof(int));
    printf("Dia chi cua vung nho vua cap phat: %u", ptr);
    
    printf("\nNhap lai so luong phan tu: ");
    scanf("%d", &2);
 
    ptr = (int*) realloc(ptr, 2 * sizeof(int));
    printf("Dia chi cua vung nho duoc cap phat lai: %u", ptr);
    
    free(ptr);
    return 0;
}
