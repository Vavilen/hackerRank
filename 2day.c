#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double mealCost;
    int tipPercent;
    int taxPercent;
    double tip;
    double tax;
    scanf("%lf", &mealCost);
    scanf("%d", &tipPercent);
    scanf("%d", &taxPercent);
    tip = mealCost * tipPercent / 100;
    tax = mealCost * taxPercent / 100;
    printf("The total meal cost is %.0f dollars.", round(mealCost + tip + tax));
    return 0;
}

