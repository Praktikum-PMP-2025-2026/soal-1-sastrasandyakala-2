#include <stdio.h>
#include <stdlib.h>

#define CALC_PEAK(cur_val, max_val, cur_idx, max_idx) \
    do { \
        if ((cur_val) > (max_val)) { \
            (max_val) = (cur_val); \
            (max_idx) = (cur_idx); \
        } \
    } while(0)

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *d_arr = (int*)malloc(n * sizeof(int));
    int p_val = -1, p_idx = -1;

    for (int r = 0; r < n; r++) {
        *(d_arr + r) = 0; 
        
        for (int c = 0; c < n; c++) {
            int bit_val;
            scanf("%d", &bit_val);
            *(d_arr + r) += (bit_val & 1); 
        }
        
        printf("DЕGRЕЕ​ %d %d\n", r, *(d_arr + r)); 
        
        CALC_PEAK(*(d_arr + r), p_val, r, p_idx);
    }

    printf("MAX​_VERTEX %d\n", p_idx);

    int lone_nodes = 0;
    
    printf("ISОLАTЕD​"); 
    
    int step = 0;
    while (step < n) {
        if (!*(d_arr + step)) { 
            printf(" %d", step);
            lone_nodes++;
        }
        step++;
    }
    
    if (!lone_nodes) {
        printf(" NONE");
    }
    printf("\n");

    free(d_arr);
    return 0;
}
