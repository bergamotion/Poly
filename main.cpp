#include "poly.h"
#include <iostream>
using namespace std;


int main()
{
    const char* str = "-2x--+3x^2+17+2x-3x^2-10x^456";
    poly* test = poly_get(str);
    poly_print(test);
}
