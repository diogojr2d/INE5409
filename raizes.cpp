#include <cstdio>
#include <cmath>

const int maxIteracoes = 100;

double f(double x) {
	return (exp(x)-x-1);
}

double f1(double x) {
	return (exp(x)-1);
}

/*double f(double x) {
	return (exp(x) * sin(x) - 1);
}*/

void bissecao(double a, double b, double err) {
	double c = 10;
	int i = 0;
	while (std::abs(f(c)) > err && i < maxIteracoes) {
		c = (a + b)/2;
		if (f(a)*f(c) < 0) {
			b = c;
		} else {
			a = c;
		}
		i++;
		/*printf("a: %f ", a);
		printf("b: %f ", b);
		printf("c: %f \n", c);*/
	}
	printf("c: %f \n", c);
	printf("f(c): %f \n", f(c));
	printf("iteracoes: %d \n", i);
}

void falsaPosicao(double a, double b, double err) {
	double c = 10;
	int i = 0;
	while (std::abs(f(c)) > err && i < maxIteracoes) {
		c = a - ( f(a)*(b-a)/(f(b)-f(a)) );
		if (f(a)*f(c) < 0) {
			b = c;
		} else {
			a = c;
		}
		i++;
		/*printf("a: %f ", a);
		printf("b: %f ", b);
		printf("c: %f \n", c);*/
	}
	printf("c: %f \n", c);
	printf("f(c): %f \n", f(c));
	printf("iteracoes: %d \n", i);
}

void newton(double x, double err) {
	double xk = 0;
	int i = 0;
	while (std::abs(f(x)) > err && i < maxIteracoes) {
		if (f1(x) == 0) {
			printf("Ponto crítico. x: %f\n", x);
			return;
		}
		xk = x - (f(x)/f1(x));
		i++;
		printf("x: %f xk: %f f(xk): %f\n", x, xk, f(xk));
		x = xk;
	}
	printf("xk: %f \n", xk);
	printf("f(xk): %f\n", f(xk));
	printf("iteracoes: %d\n", i);
}

void secante() {
	
}

int main() {
	printf("Bisseção:\n");
	bissecao(-1, 1, 1.0e-6);
	printf("\n");
	printf("Falsa Posição:\n");
	falsaPosicao(-1, 1, 1.0e-6);
	printf("\n");
	printf("Newton:\n");
	newton(1, 1.0e-6);

	return 0;
}