#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int eval_infix(char *exp, int len);
char *substring(char *exp, int start, int end);
int find_outermost_op(char *exp, int len, char *op);
int parse_int(char *exp);
int contains_op(char *exp, int n);

int main(int argc, char **argv)
{
    char *a = argv[1];

    char *exp = malloc(strlen(a) + 1);
    int i;
    for (i = 0; i < strlen(a); i++)
        exp[i] = a[i];
    exp[i] = '\0';

    int result = eval_infix(exp, strlen(exp));
    char op;
    printf("%d\n", result);
}

int eval_infix(char *exp, int len)
{
    if (!contains_op(exp, len))
    {
        return parse_int(exp);
    }

    char op;
    int op_location = find_outermost_op(exp, len, &op);
    char *subexp1, *subexp2;
    int len1, len2;

    subexp1 = substring(exp, 1, op_location - 1);
    len1 = op_location - 1;
    subexp2 = substring(exp, op_location + 1, len - 2);
    len2 = len - (op_location + 1) - 1;

    free(exp);
    if (op == '+')
        return eval_infix(subexp1, len1) + eval_infix(subexp2, len2);
    else if (op == '*')
        return eval_infix(subexp1, len1) * eval_infix(subexp2, len2);
    else if (op == '-')
    {
        int subresult1 = eval_infix(subexp1, len1);
        return subresult1 - eval_infix(subexp2, len2);
    }
    else if (op == '/')
    {
        int subresult1 = eval_infix(subexp1, len1);
        return subresult1 / eval_infix(subexp2, len2);
    }
}

int find_outermost_op(char *exp, int len, char *op)
{
    int open_brackets = 0;

    for (int i = 0; i < len; i++)
    {
        if ((open_brackets == 1) && (exp[i] == '+' || exp[i] == '*' || exp[i] == '/' || exp[i] == '-'))
        {
            if (exp[i] == '+')
                *op = '+';
            else if (exp[i] == '*')
                *op = '*';
            else if (exp[i] == '-')
                *op = '-';
            else if (exp[i] == '/')
                *op = '/';

            return i;
        }
        if (exp[i] == '(')
            open_brackets++;
        else if (exp[i] == ')')
        {
            open_brackets--;
        }
    }

    return -1;
}

char *substring(char *exp, int start, int end)
{
    int len = end - start + 1;
    char *sub;
    if ((sub = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
        fprintf(stderr, "Not enough memory!");

    int i;
    int j = 0;
    for (i = start; i <= end; i++, j++)
    {
        sub[j] = exp[i];
    }
    sub[i] = '\0';

    return sub;
}

int parse_int(char *exp)
{
    int i = 0;
    while (exp[i] == '(' || exp[i] == ' ')
        i++;

    int num = 0;
    while (exp[i] >= '0' && exp[i] <= '9')
    {
        num = num * 10 + (exp[i] - '0');
        i++;
    }

    return num;
}

int contains_op(char *exp, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '+' || exp[i] == '*' || exp[i] == '-' || exp[i] == '/')
        {
            return 1;
        }
    }

    return 0;
}

/*

(((2 + 3) * (6 + 7)) * 3)

*/