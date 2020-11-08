#include <iostream>
#include <cmath>

using namespace std;

double z(const double x);

int main()
{
	double kz, kg, p;
	int n;

	cout << "kz = "; cin >> kz;
	cout << "kg = "; cin >> kg;
	cout << "n = "; cin >> n;

	double dk = (kg - kz) / n;

	double k = kz;

	while (k <= kg)
	{
		p = (z(2.0 * k - 1.0)) - pow( z(2.0 * k - 1.0), 2) + sqrt(z(k));
		cout << k << " " << p << endl;
		k += kg;
	}

	return 0;
}

double z(const double x)
{
	if (abs(x) >= 1)
		return (cos(x) + 1.0) / (sin(x) * sin(x) + exp(x));
	else
	{
		double S = 0;
		int j = 0;
		double a = 1;
		S = a;
		do
		{
			j++;
			double R = -x / ((j - 2) * (j - 1) * j);
			a *= R;
			S += a;
		} while (j < 7);
		return (1 / (exp(x)) * S);
	}
}
