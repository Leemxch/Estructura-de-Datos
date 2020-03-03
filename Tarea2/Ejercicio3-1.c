#include <stdio.h>
void main() {
    int a[] = { 1,2,3,4,5 };
    printf("%d\n", binsearch(1, a, 6));
    printf("%d\n", binsearch(1, a, 2));
    printf("%d\n", binsearch(1, a, 0));
}
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid]){
            high = mid + 1;
        }
        if (x > v[mid]) {
            printf("%d", v[mid]);
            low = mid + 1;
        }
        else { 
        /* found match */
            return mid;
        }
    }
   return -1; /* no match */
}