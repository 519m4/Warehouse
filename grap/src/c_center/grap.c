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
    printf("6. XOR Fractal 2\n");
    printf("7. XOR Fractal 3\n");
    printf("grap> ");
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
    case 6: 
        graphic6();//XOR fractal type2
        break;
    case 7:
        graphic7();//XOR fractal type3
        break;
    default:
        break;
    }
}