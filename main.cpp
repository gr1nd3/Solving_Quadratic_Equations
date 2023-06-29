#include <txlib.h>
#include <stdio.h>
#include <math.h>



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
        printf ("%f", x);

        return 0;
    }

    else
    {
        float x_1 = (-b + sqrt (d)) / (2 * a);
        float x_2 = (-b - sqrt (d)) / (2 * a);

        printf ("%f %f", x_1, x_2);

        return 0;
    }
}
