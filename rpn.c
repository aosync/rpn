#include <stdlib.h>
#include "stack.h"
#include <math.h>
#include <stdio.h>

#define reqst(X) {if (s.len < X) {printf("stack too short\n"); break;}}

typedef def_stack(double) double_stack;

double_stack s;

int main() {
	unsigned h;
	double a;
	char c;
	stinit(s, double);

	while (1) {
		if (scanf("%lf", &a) > 0) {
			stpush(s, a);
		} else if (scanf("%c", &c) > 0) {
			switch (c) {
			case '+':
				reqst(2);
				a = stpop(s);
				s.data[s.len-1] += a;
				break;
			case '-':
				reqst(2)
				a = stpop(s);
				s.data[s.len-1] -= a;
				break;
			case '*':
				reqst(2)
				a = stpop(s);
				s.data[s.len-1] *= a;
				break;
			case '/':
				reqst(2)
				a = stpop(s);
				s.data[s.len-1] /= a;
				break;
			case 'p':
				reqst(1)
				printf("%lf\n", s.data[s.len-1]);
				break;
			case 's':
				reqst(1)
				s.data[s.len-1] = sqrt(s.data[s.len-1]);
				break;
			case 'd':
				reqst(1)
				stpush(s, s.data[s.len-1]);
				break;
			case 'c':
				reqst(1)
				stfree(s);
				break;
			case 'q':
				goto quit;
			default:
				printf("%c: unimplemented\n", c);
			}
		}
	}

quit:
	stfree(s);
	return 0;
}
