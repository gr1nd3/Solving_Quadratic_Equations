#include <txlib.h>
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

const float Meloch = 1e-6;

//-----------------------------------------------------------------------------

void fix_zero (float* x);
float fix_zero_ret (float x);

//-----------------------------------------------------------------------------

int main()
{
    float a = 0, b = 0, c = 0;

    scanf ("%f %f %f", &a, &b, &c);

    float d = b * b - 4 * a * c;

    if (d < 0)
    {
        printf ("XOPOIII MEHYA MYUATb\n");

        return 0;
    }

    else if (d == 0)
    {
        float x = -b / (2 * a);

        fix_zero (&x);
        printf ("%g", x);

        return 0;
    }

    else
    {
        float x_1 = (-b + sqrt (d)) / (2 * a);
        float x_2 = (-b - sqrt (d)) / (2 * a);

        fix_zero (&x_2);
        printf ("%g %g", fix_zero_ret (x_1), x_2);

        return 0;
    }
}

//-----------------------------------------------------------------------------

float fix_zero_ret (float x)
{
    if (-Meloch < x && x < Meloch)
    {
        return 0;
    }

    else
    {
        return x;
    }
}

//-----------------------------------------------------------------------------

void fix_zero (float* x)
{
    if (-Meloch < *x && *x < Meloch)
    {
        *x = 0;
    }
}

//-----------------------------------------------------------------------------
