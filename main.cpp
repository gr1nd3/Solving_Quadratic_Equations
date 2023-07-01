#include <txlib.h>
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

const float Meloch = 1e-6;

//-----------------------------------------------------------------------------

void fix_zero (float* x);
float fix_zero_ret (float x);
float scanf_or_pnahui (const char text[ ]);
void eat_symbols ( );
int quadratic_equation (float a, float b, float c, float* x_1, float* x_2);
bool cmp_zero (float d);
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

float fix_zero_ret (float x)
{
    if (cmp_zero (x))
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
    if (cmp_zero (*x))
    {
        *x = 0;
    }
}

//-----------------------------------------------------------------------------

float scanf_or_pnahui (const char text[ ])
{
    printf ("Пожалуйста, умоляем вас, пожертвуйте коэффицит %s" "\n", text);
    float a = 0;

    while (scanf ("%f", &a) != 1)
    {
        eat_symbols ( );

        printf ("ИДИ НАХУЙ педик" "\n");
    }

    return a;
}

//-----------------------------------------------------------------------------

void eat_symbols ( )
{
    while (getchar() != '\n')
        ;

}

//-----------------------------------------------------------------------------
/*

bool cmp_zero (float d)
{
    if (-Meloch < d && d < +Meloch) return true;
    else                            return false;
}

*/
//-----------------------------------------------------------------------------

bool cmp_zero (float d)
{
    return (-Meloch < d && d < +Meloch);
}

//-----------------------------------------------------------------------------

int quadratic_equation (float a, float b, float c, float* x_1, float* x_2)
{
    float d = b * b - 4 * a * c;

    if (d > 0)
    {
        *x_1 = (-b + sqrt (d)) / (2 * a);
        *x_2 = (-b - sqrt (d)) / (2 * a);
        return 2;
    }

    else if (cmp_zero (d))
    {
        *x_1 = -b / (2 * a);
        return 1;
    }

    else
    {
        return 0;
    }
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
