#include <stdio.h>
#include <math.h>

double function1(double x) 
{
    return pow(x, 2) - 9;
}

double function2(double x) 
{
    return sin(x);
}

double function3(double x)
{
    return exp(x) - 2;
}

double regula(double x1, double x2, double (*f)(double))
{
    double value;

    if (f(x1) * f(x2) >= 0)
    {
        return x1;
    }

    do 
    {
        value = x1 - (f(x1) * ((x2 - x1)/(f(x2) - f(x1))));

        if (f(value) * f(x1) < 0) {
            x2 = value;
        } 
        else
        {
            x1 = value;
        }
    } while (fabs(f(value)) > 1e-6);

    return value;
}

int main(void)
{
    double d = regula(0, 2, function3);
    printf("%f\n", d);

    return 0;
}
