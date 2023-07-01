
#include <txlib.h>
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

const float Meloch = 1e-6;

//-----------------------------------------------------------------------------

#include "core.cpp"

void answer_output (int number_of_roots, float x_1, float x_2);

//-----------------------------------------------------------------------------

int main()
{
    float a = scanf_or_pnahui ("a"),
          b = scanf_or_pnahui ("b"),
          c = scanf_or_pnahui ("c");

    float x_1 = 0, x_2 = 0;
    int number_of_roots = quadratic_equation (a, b, c, &x_1, &x_2);

    answer_output (number_of_roots, x_1, x_2);

    return 0;
}

//-----------------------------------------------------------------------------

void answer_output (int number_of_roots, float x_1, float x_2)
{
    if (number_of_roots == 2) printf ("Афигеть, я нашел аж 2 корня, это числа: x_1 = %g, x_2 = %g\n",
                                       fix_zero_ret (x_1), fix_zero_ret (x_2));

    if (number_of_roots == 1) printf ("Афигеть, я нашел корэн, это число: x = %g\n", fix_zero_ret (x_1));

    if (number_of_roots == 0) printf ("гм, пук-пук, я слабый компьютер, "
                                      "я не ебу что делать с отрицательными дискриминантами\n");
}
