#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	double a = 0.1, b = 1, shag, y, n = 10, x, SN = 1, EL1, EL2, SE = 1;
	const double E = 0.0001;
	int h = 1;

	x = a;

	shag = (b - a) / n;

	while (x < b)
	{
		y = cos(x);

		for (int i = 1; i <= n; i++)
		{
			SN += pow(-1, i) * (pow(x, 2 * i) / 2 * i);
		}

		EL1 = 1;

		EL2 = pow(-1, h) * (pow(x, 2 * h) / 2 * h);

		while (abs(EL2 - EL1) > E)
		{
			EL1 = EL2;

			SE += EL1;

			h++;

			EL2 = pow(-1, h) * (pow(x, 2 * h) / 2 * h);

		}
		x += shag;

		cout << "X = " << x;
		cout << "\tSN = " << SN;
		cout << "\tSE = " << SE;
		cout << "\tY = " << y << endl;
	}
	return 0;
}