#include "grap.h"

int main()
{
    INT e;
    printf("Select an option:\n");
    printf("1. Mandelbrot\n");
    printf("2. Plasma\n");
    printf("3. Rainbow Gradient\n");
    printf("4. XOR Fractal\n");
    printf("5. RGB!\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &e);
    switch (e) {
    case 1:
        graphic1();//mandelbrot
        break;
    case 2:
        graphic2();//plasma
        break;
    case 3:
        graphic3();//rainbowgradient
        break;
    case 4:
        graphic4();//XOR fractal
        break;
    case 5:
        graphic5();//RGB!
        break;
    default:
        break;
    }
}