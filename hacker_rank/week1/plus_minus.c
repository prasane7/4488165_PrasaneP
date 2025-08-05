#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int positive = 0, negative = 0, zero = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] > 0) {
            positive++;
        } else if(arr[i] == 0) {
            zero++;
        } else {
            negative++;
        }
    }

    double p_ratio = (double)positive / size;
    double n_ratio = (double)negative / size;
    double z_ratio = (double)zero / size;

    printf("%.6lf\n", p_ratio);
    printf("%.6lf\n", n_ratio);
    printf("%.6lf\n", z_ratio);

    return 0;
}
