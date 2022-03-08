#pragma once

struct poly {
	int coeff;
	int exp;
	struct poly* next;
};

int parse_number(const char** str);
int parse_exponent(const char** str);
int parse_coefficient(const char** str);
poly* get_monomial(int coeff, int exp);
poly* poly_add_monomial(poly* p, int c, int e);
void poly_print(poly* p);
poly* poly_get(const char* str);
poly* poly_add(poly* p1, poly* p2);
poly* poly_multiply(poly* p1, poly* p2);
poly* poly_copy(poly* p);

