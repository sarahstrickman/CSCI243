/// file: warning.c
/// description: faulty code example that needs fixing.
/// @author RIT CS Dept.

#include <stdio.h>

/// compute a value by multiplying it by 5.
int compute(int a) {
    int b = a * 5;
    return b;
}

#define SIZE 0

/// main function should print 2018 and return 0 as the process return status.
int main() {
    int x = 18;
    int y = compute(400);


    printf("%d \n", y + x);

    if ( y > 100) {
        return 0;
    }

    else {
        return 1;
    }
}

