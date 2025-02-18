#include <stdio.h>

int* merge (int *left, int *right) {
    int pr = 0;
    int pl = 0;
    int count = 0;
    int n = (sizeof(left) + sizeof(right))/sizeof(left[0]);
    int res[n];
    int leftval, rightval;

    if (sizeof(left) == 0 && sizeof(right) == 0) {
        return NULL;
    } else if(sizeof(left) == 0) {
        return right;
    } else if (sizeof(right) == 0) {
        return left;
    }

    while (pl + pr < n){
        if(pl > sizeof(left)) {
            leftval = 0;
        } else {
            leftval = left[pl];
        }
        if(pr >sizeof(right)) {
            rightval = 0;
        } else {
            rightval = right[pr];
        }
        
        if (leftval >= rightval) {
            res[count] = leftval;
                count++;
                pl++;
        } else {
            res[count] = rightval;
            count++;
            pr++;
        }
    }

    return res;


}
int main() {
    int arr1[] = {4,2,3,1,8};
    int arr2[] = {5,-1,3,1,8};
    int size = sizeof(arr1) + sizeof(arr2)/ sizeof(arr1[0]);
    
   int* x = merge(arr1, arr2);

   for (int i = 0; i < size; i++) {
       printf("%d ", x[i]);
   }
   printf("\n");

}
