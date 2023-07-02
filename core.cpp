
#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------

/*const float Nan = 1e6;
const float Meloch = 1e-6;
const int Pizda = -10; */

//-----------------------------------------------------------------------------

void fix_zero (float* x);
float fix_zero_ret (float x);
float scanf_or_pnahui (const char text[ ]);
void eat_symbols ( );
int quadratic_equation (float a, float b, float c, float* x_1, float* x_2);
int linear_equation (float b, float c, float* x_1);
bool is_zero (float d);
int cmp_string (char word_1[], char word_2[]);

//-----------------------------------------------------------------------------

float fix_zero_ret (float x)
{
    if (is_zero (x))
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
    if (is_zero (*x))
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
        char word [20] = "";
        scanf  ("%s", word);
        if (cmp_string (word, "END") == 0) return Nan;

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

bool is_zero (float d)
{
    return (-Meloch < d && d < +Meloch);
}

//-----------------------------------------------------------------------------

int quadratic_equation (float a, float b, float c, float* x_1, float* x_2)
{
    if (is_zero (a)) return linear_equation (b, c, x_1);

    float d = b * b - 4 * a * c;

    if (d > 0)
    {
        *x_1 = (-b + sqrt (d)) / (2 * a);
        *x_2 = (-b - sqrt (d)) / (2 * a);
        return 2;
    }

    else if (is_zero (d))
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

int linear_equation (float b, float c, float* x_1)
{

    if (is_zero (b) && is_zero (c))  return -1;

    if (is_zero (b) && !is_zero (c)) return 0;

    if (!is_zero (b) && !is_zero (c))
    {
        *x_1 = -c / b;
        return 1;
    }

    return Pizda;
}
//-----------------------------------------------------------------------------
/*

bool is_zero (float d)
{
    if (-Meloch < d && d < +Meloch) return true;
    else                            return false;
}

*/
//-----------------------------------------------------------------------------
/*int main()
{
    printf ("1: %d, should be 0\n", cmp_string ("END", "END"));
    printf ("2: %d, should be 1\n", cmp_string ("END", "ENDOK"));
    printf ("3: %d, should be 0\n", cmp_string ("", ""));
    printf ("4: %d, should be 1\n", cmp_string ("", "END"));
    printf ("5: %d, should be 1\n", cmp_string ("END", ""));
    printf ("6: %d, should be 0\n", cmp_string ("k", "k"));
    printf ("7: %d, should be 1\n", cmp_string ("k", "l"));
}*/

//-----------------------------------------------------------------------------

int cmp_string (char word_1[], char word_2[])
{
    int i = 0;
    while (word_1[i] != 0 || word_2[i] != 0)
    {
        if (word_1[i] != word_2[i]) return 1;
        i++;
    }

    return 0;
}

//-----------------------------------------------------------------------------
