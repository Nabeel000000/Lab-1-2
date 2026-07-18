#include <stdio.h>

double power(double mid, int n)
{
    double res = 1.0;
    for (int i = 0; i < n; i++)
    {
        res *= mid;
    }
    return res;
}

double nth_root(double y, int n)
{
    double l = 0.0;

    double h = (y > 1.0) ? y : 1.0;

    double epsilon = 0.000001;

    while ((h - l) > epsilon)
    {
        double mid = l + (h - l) / 2.0;
        double val = power(mid, n);

        if (val < y)
        {
            l = mid;
        }
        else
        {
            h = mid;
        }
    }
    return l + (h - l) / 2.0;
}

int main()
{
    double y;
    int n;
    printf("Enter number:");
    scanf("%lf", &y);
    printf("Enter the value of n(nth-root):");
    scanf("%d", &n);
    double res = nth_root(y, n);
    printf("The %d-th root of %f is approximately %f\n", n, y, res);

    return 0;
}
