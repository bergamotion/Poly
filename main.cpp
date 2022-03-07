#include "poly.h"
#include <iostream>
using namespace std;


int main()
{
    const char* str2 = "x^2-3";
    poly* p2 = poly_get(str2);
    poly_print(p2);
}
