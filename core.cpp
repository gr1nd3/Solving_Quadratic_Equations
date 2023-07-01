

//-----------------------------------------------------------------------------

void fix_zero (float* x);
float fix_zero_ret (float x);
float scanf_or_pnahui (const char text[ ]);
void eat_symbols ( );
int quadratic_equation (float a, float b, float c, float* x_1, float* x_2);
bool cmp_zero (float d);

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
/*

bool cmp_zero (float d)
{
    if (-Meloch < d && d < +Meloch) return true;
    else                            return false;
}

*/
//-----------------------------------------------------------------------------
