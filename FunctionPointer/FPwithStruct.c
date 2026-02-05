#include <stdio.h>

/* Interface */
typedef struct {
    void (*start)(void);
} Motor;

/* Implementations */
void dc_motor_start(void) {
    printf("DC Motor Started\n");
}

void stepper_motor_start(void) {
    printf("Stepper Motor Started\n");
}

int main() {
    Motor motor;

    motor.start = dc_motor_start;
    motor.start();

    motor.start = stepper_motor_start;
    motor.start();

    return 0;
}

