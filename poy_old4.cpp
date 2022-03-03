//#include "poly.h"
//#include <stdlib.h>
//#include <iostream>
//
//poly* poly_get(const char* str)
//{
//	poly* head = nullptr;
//	poly* element = nullptr;
//
//	while (*str != '\0') {
//		if (!element) {
//			element = get_monomial(&str);
//			head = element;
//		}
//		else {
//
//			element->next = get_monomial(&str);
//			element = element->next;
//		}
//	}
//	return head;
//}
//
//poly* get_monomial(const char** str)
//{
//	int coeff = parse_coefficient(str);
//	int exp = parse_exponent(str);
//	poly* element = (poly*)malloc(sizeof(poly));
//	if (element) {
//		element->coeff = coeff;
//		element->exp = exp;
//		element->next = nullptr;
//	}
//	return element;
//}
//
//int parse_coefficient(const char** str)
//{
//	int sign = 1;
//	if (**str == '-') {
//		sign *= -1;
//		++(*str);
//	}
//	else if (**str == '+') {
//		++(*str);
//	}
//
//	int coeff = parse_number(str);
//	return coeff * sign;
//}
//
//int parse_exponent(const char** str)
//{
//	int exp = 0;
//	if (**str == 'x') {
//		++(*str);
//		exp = 1;
//		if (**str == '^') {
//			++(*str);
//			exp = parse_number(str);
//		}
//	}
//	return exp;
//}
//int parse_number(const char** str)
//{
//	char* end_of_number;
//	int number = strtol(*str, &end_of_number, 10);
//	*str = end_of_number;
//
//	return number;
//}
//
//void poly_print(poly* p)
//{
//	poly* current = p;
//	while (current != nullptr)
//	{
//		int coeff = current->coeff;
//		int exp = current->exp;
//		if (coeff != 0) {
//			if (coeff > 0) {
//				std::cout << '+' << coeff;
//			}
//			else std::cout << coeff;
//
//			if (exp != 0) {
//				if (exp > 1) std::cout << 'x' << '^' << current->exp;
//				else std::cout << 'x';
//			}
//			current = current->next;
//		}
//	}
//}