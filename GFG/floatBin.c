#include <stdio.h>
#include <stdint.h>
#include <string.h>

void print_binary(float f) {
    // Define a union to access the same memory as a float and a 32-bit unsigned int
    union {
        float f_val;
        uint32_t i_val;
    } data;

    data.f_val = f;

    // Iterate through the bits from most significant to least significant
    for (int i = 31; i >= 0; i--) {
        // Use bitwise operations on the integer representation
        if ((data.i_val >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
        // Add spaces for clarity between sign, exponent, and mantissa
        if (i == 31 || i == 23) {
            printf(" ");
        }
    }
    printf("\\n");
}

int main() {
    float num = 4.75f;
    printf("Decimal: %.2f\\n", num);
    printf("Binary representation: ");
    print_binary(num);

    float neg_num = -3.14f;
    printf("Decimal: %.2f\\n", neg_num);
    printf("Binary representation: ");
    print_binary(neg_num);
    
    return 0;
}

