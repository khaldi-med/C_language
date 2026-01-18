// backtracking_subsets.c
#include <stdio.h>

void print_subset(int subset[], int len) {
    printf("{");
    for (int i = 0; i < len; ++i) {
        printf("%d", subset[i]);
        if (i + 1 < len) printf(", ");
    }
    printf("}\n");
}

void gen_subsets(int arr[], int n, int idx, int subset[], int k) {
    if (idx == n) { print_subset(subset, k); return; }
    // Exclude arr[idx]
    gen_subsets(arr, n, idx + 1, subset, k);
    // Include arr[idx]
    subset[k] = arr[idx];
    gen_subsets(arr, n, idx + 1, subset, k + 1);
}

int main(void) {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int subset[32];
    gen_subsets(arr, n, 0, subset, 0);
    return 0;
}