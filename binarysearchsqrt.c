#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fInv(double x) {
    return x * x;
}

int main() {
    double target = 99;
    double lo = 9;
    double hi = 10;

    // assume we watn 6 digits
    for (int i = 0; i<20; i++) {
        double mid = (lo + hi) / 2;
        double ymid = fInv(mid);

        if (ymid >= target) {
            // mid was too large
            hi = mid;
        } else {
            // mid was too low
            lo = mid;
        }
    }

    printf("my sqrt %.10lf\n", (lo + hi) / 2);

    return 0;
}