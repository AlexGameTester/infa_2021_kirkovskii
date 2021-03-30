#include <cmath>

double find_root(double (&f)(double), double a, double b, double tol)
{
    const double eps = 1e-6;
    if (b - a < tol)
    {
        if (abs(f(a)) < eps)
        {
            return a;
        }
        if (abs(f(b)) < eps)
        {
            return b;
        }
    }
    else
    {
        double x = (a + b) / 2;
        double f_x = f(x);
        if (f_x * f(a) <= 0)
        {
            return find_root(f, a, x, tol);
        }
        else
        {
            return find_root(f, x, b, tol);
        }
    }
}
