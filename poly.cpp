#include "poly.h"
#include <stdlib.h>
#include <iostream>

poly* poly_get(const char* str)
{
	poly* head = nullptr;
	poly* element = nullptr;
	int coeff, exp;
	while (*str != '\0') {
		if (!element) {
			coeff = parse_coefficient(&str);
			exp = parse_exponent(&str);
			element = get_monomial(coeff, exp);
			head = element;
		}
		else {
			coeff = parse_coefficient(&str);
			exp = parse_exponent(&str);
			head = poly_add_monomial(head, coeff, exp);
		}
	}
	return head;
}

poly* get_monomial(int coeff, int exp)
{
	poly* element = (poly*)malloc(sizeof(poly));
	if (element) {
		element->coeff = coeff;
		element->exp = exp;
		element->next = nullptr;
	}
	return element;
}

poly* poly_add_monomial(poly* p, int c, int e) 
{
	poly* result;

	if (e > p->exp) {
		result = get_monomial(c, e);
		result->next = p;
	}
	else if (e == p->exp) {								   		
		p->coeff += c;
		result = p;
		if (p->coeff == 0) {
			result = p->next;
			free(p);
		}
	}
														   // Ёкспонента точно меньше экспоненты начала списка
	else {
		result = p;
		poly* prev = p;
		poly* current = p->next;

		while (current != nullptr && e < current->exp) {
			prev = current;
			current = current->next;
		}
								   					   // ƒобавл€ем моном в конец списка
		if (current == nullptr) {
			prev->next = get_monomial(c, e);
		}
		else if (e > current->exp) {                     // ƒобавл€ем моном куда-то в середину списка
			prev->next = get_monomial(c, e);
			(prev->next)->next = current;
		}
		else if (e == current->exp) {
			current->coeff += c;
			if (current->coeff == 0) {
				prev->next = current->next;
				free(current);
			}
		}
	}
	return result;
}


int parse_coefficient(const char** str)
{
	int sign = 1;
	if (**str == '-') {
		sign *= -1;
		++(*str);
	}
	else if (**str == '+') {
		++(*str);
	}

	int coeff = parse_number(str);
	return coeff * sign;
}

int parse_exponent(const char** str)
{
	int exp = 0;
	if (**str == 'x') {
		++(*str);
		exp = 1;
		if (**str == '^') {
			++(*str);
			exp = parse_number(str);
		}
	}
	return exp;
}

int parse_number(const char** str)
{
	char* end_of_number;
	int number = strtol(*str, &end_of_number, 10);
	if (*str == end_of_number) number = 1;
	*str = end_of_number;
	return number;
}

void poly_print(poly* p)
{
	poly* current = p;
	while (current)
	{
		int coeff = current->coeff;
		int exp = current->exp;
		if (coeff != 0) {
			if (coeff > 1) std::cout << '+' << coeff;
			else if (coeff == 1) std::cout << '+';
			else if (coeff == -1) std::cout << '-';
			else std::cout << coeff;

			if (exp != 0) {
				if (exp > 1) std::cout << 'x' << '^' << current->exp;
				else std::cout << 'x';
			}
			current = current->next;
		}
	}
	std::cout << std::endl;
}


poly* poly_add(poly* p1, poly* p2)
{
	poly* result = get_monomial(p1->coeff, p1->exp);
	p1 = p1->next;
	while (p1) {
		result = poly_add_monomial(result, p1->coeff, p1->exp);
		p1 = p1->next;
	}
	while (p2) {
		result = poly_add_monomial(result, p2->coeff, p2->exp);
		p2 = p2->next;
	}
	return result;
}

//poly* poly_multiply(poly* p1, poly* p2)
//{
//
//}