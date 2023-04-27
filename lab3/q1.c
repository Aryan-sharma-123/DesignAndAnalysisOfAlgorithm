#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[100], n, temp, flag;
    int count=0;
    printf("Enter the size of the list: \n");
    scanf("%d", &n);
    printf("\nEnter the elements into the list: \n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nAfter the bubble sort the elements arranges as follows: \n");

    for(int i = 0; i < n-1; i++) {
        flag = 0;
        for(int j = 0; j < n-1-i; j++) {
        count++;
            if(a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("The count is: %d",count);
    return 0;
}
