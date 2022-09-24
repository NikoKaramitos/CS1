#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool enoughShade(double sunAngle, int *pos, int *height, int numBuildings, int length, double percentRequired) {

    // Sigma
    double buildingAngle = 90 - sunAngle;

    double coveredGround = 0;
    double leftMostCovered = 1e9;

    // Go right to left because of math (drawing)
    for (int i = numBuildings - 1; i>=0; i--) {

        // get the length covered by this tower
        double bottomLength = height[i] * tan(buildingAngle);
        double alreadyCoveredLength = pos[i] - leftMostCovered;

        // take out overlap
        if (alreadyCoveredLength > 0)
            bottomLength -= alreadyCoveredLength;

        // add to our ground
        coveredGround += bottomLength;

        //update leftmost
        double candidatenewLeftMost = pos[i] - bottomLength;
        if (candidatenewLeftMost < leftMostCovered)
            leftMostCovered = candidatenewLeftMost;
    }

    double percentCovered = coveredGround / length;

    return percentCovered >= percentRequired;
}

int main() {

    // Take input
    int n, l, p;
    scanf("%d %d %d", &n, &l, &p);

    // populate input arrays
    int *pos, *height;
    pos = malloc(n * sizeof(int));
    height = malloc(n * sizeof(int));

    for (int i = 0; i<n; i++) {
        int p, h;
        scanf("%d %d", &p, &h);
        pos[i] = p;
        height[i] = h;
    }

    // binary search
    double lo = 0, hi = 90;
    for (int i = 0; i<60; i++) {
        double mid = (lo + hi) / 2;
        if (enoughShade(mid, pos, height, n, l, p))
            lo = mid;
        else
            hi = mid;
    }

    printf("Angle on right = %.3f", lo);

    return 0;
}   
