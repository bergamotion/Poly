#include "poly.h"
#include <iostream>
using namespace std;


int main()
{
    const char* str1 = "-3+8x^3-2x+0";
    poly* p1 = poly_get(str1);
    poly_print(p1);

    const char* str2 = "x^2+6x+3x-1+2+8x^4";
    poly* p2 = poly_get(str2);
    poly_print(p2);

    poly* prod = poly_multiply(p1, p2);
    poly_print(prod);
}
