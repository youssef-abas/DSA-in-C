#include <stdio.h>

int eval_prefix();
int i;
char *a;

int eval_prefix_f(char *exp, int start, int end);

int main(int argc, char **argv)
{
    char *exp = argv[1];

    int k = 0;
    while (exp[k] != '\0')
        k++;

    int result = eval_prefix_f(exp, 0, k - 1);

    printf("%d\n", result);
}

int eval_prefix_f(char *exp, int start, int end)
{
    int num;

    for (int i = start; i <= end; i++)
        printf("%c", exp[i]);
    printf("\n");

    if (exp[start] != '+' && exp[start] != '*')
    {
        num = 0;
        while (exp[start] != ' ' && exp[start] != '\0')
            num = num * 10 + (exp[start++] - '0');

        return num;
    }
    else
    {
        char op = exp[start];
        start += 2;
        if (exp[start] != '+' && exp[start] != '*')
        {
            num = 0;
            while (exp[start] != ' ' && start <= end)
                num = num * 10 + (exp[start++] - '0');

            start += 1;
            return (op == '+') ? num + eval_prefix_f(exp, start, end) : num * eval_prefix_f(exp, start, end);
        }
        else
        {
            int prod = 1;
            num = 0;
            while (exp[end] != ' ' && start <= end)
            {
                num = (exp[end--] - '0') * prod + num;
                prod *= 10;
            }

            end--;
            return (op == '+') ? num + eval_prefix_f(exp, start, end) : num * eval_prefix_f(exp, start, end);
        }
    }
}

int eval_prefix()
{
    int num = 0;

    while (a[i] == ' ')
        i++;
    if (a[i] != '+' && a[i] != '*')
    {
        while (a[i] != ' ' && a[i] != '\0')
            num = num * 10 + (a[i++] - '0');

        return num;
    }
    else
    {
        if (a[i] == '+')
        {
            i++;
            return eval_prefix() + eval_prefix();
        }
        else
        {
            i++;
            return eval_prefix() * eval_prefix();
        }
    }
}