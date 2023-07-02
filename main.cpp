
#include <txlib.h>
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

const float Meloch = 1e-6;
const int Pizda = -10;
const float Nan = 1e6;

//-----------------------------------------------------------------------------

#include "core.cpp"

void answer_output (int number_of_roots, float x_1, float x_2);

//-----------------------------------------------------------------------------

int main()
{
    while (true)
    {
        printf ("Введите числа или END, чтобы быть посланным нахуй\n");

        float a = scanf_or_pnahui ("a");
        if (a == Nan) break;

        float b = scanf_or_pnahui ("b");
        if (b == Nan) break;

        float c = scanf_or_pnahui ("c");
        if (c == Nan) break;

        if (a == Nan || b == Nan || c == Nan) break;

        float x_1 = 0, x_2 = 0;
        int number_of_roots = quadratic_equation (a, b, c, &x_1, &x_2);

        answer_output (number_of_roots, x_1, x_2);
    }

    printf ("Вы посланы нахуй\n");

    return 0;

}

//-----------------------------------------------------------------------------

void answer_output (int number_of_roots, float x_1, float x_2)
{
    if (number_of_roots == 2)     printf ("Афигеть, я нашел аж 2 корня, это числа: x_1 = %g, x_2 = %g\n\n",
                                           fix_zero_ret (x_1), fix_zero_ret (x_2));

    if (number_of_roots == 1)     printf ("Афигеть, я нашел корэн, это число: x = %g\n\n", fix_zero_ret (x_1));

    if (number_of_roots == 0)     printf ("гм, пук-пук, я слабый компьютер, "
                                          "я не ебу что делать, но походу нет решений\n\n");

    if (number_of_roots == -1)    printf ("Бля корней бесконечно, явахуи\n\n");

    if (number_of_roots == Pizda) printf ("WARNING: System Error 7725288: PIZDA occurred\n"
                                          "Press any key to throw your computer away...\n\n");
}

