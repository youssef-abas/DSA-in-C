#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int eval_infix(char *exp, int start, int end);
char *substring(char *exp, int start, int end);
int find_outermost_op(char *exp, int start, int end, char *op);
int parse_int(char *exp, int start);
int contains_op(char *exp, int start, int end);

int main(int argc, char **argv)
{
    char *a = argv[1];

    char *exp = malloc(strlen(a) + 1);
    int i;
    for (i = 0; i < strlen(a); i++)
        exp[i] = a[i];
    exp[i] = '\0';

    int result = eval_infix(exp, 0, strlen(exp) - 1);
    char op;
    printf("%d\n", result);
}

int eval_infix(char *exp, int start, int end)
{
    if (!contains_op(exp, start, end))
    {
        return parse_int(exp, start);
    }

    char op;
    int op_location = find_outermost_op(exp, start, end, &op);

    int start1, end1, start2, end2;

    start1 = start + 1;
    end1 = op_location - 2;
    start2 = op_location + 2;
    end2 = end - 1;

    printf("Exp1: ");
    for (int i = start1; i <= end1; i++)
    {
        printf("%c", exp[i]);
    }
    printf("\n");
    printf("Exp2: ");
    for (int i = start2; i <= end2; i++)
    {
        printf("%c", exp[i]);
    }
    printf("\n");

    if (op == '+')
        return eval_infix(exp, start1, end1) + eval_infix(exp, start2, end2);
    else if (op == '*')
        return eval_infix(exp, start1, end1) * eval_infix(exp, start2, end2);
    else if (op == '-')
    {
        int subresult1 = eval_infix(exp, start1, end1);
        return subresult1 - eval_infix(exp, start2, end2);
    }
    else if (op == '/')
    {
        int subresult1 = eval_infix(exp, start1, end1);
        return subresult1 / eval_infix(exp, start2, end2);
    }
}

int find_outermost_op(char *exp, int start, int end, char *op)
{
    int open_brackets = 0;

    for (int i = start; i <= end; i++)
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

// char *substring(char *exp, int start, int end)
// {
//     int len = end - start + 1;
//     char *sub;
//     if ((sub = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
//         fprintf(stderr, "Not enough memory!");

//     int i;
//     int j = 0;
//     for (i = start; i <= end; i++, j++)
//     {
//         sub[j] = exp[i];
//     }
//     sub[i] = '\0';

//     return sub;
// }

int parse_int(char *exp, int start)
{
    int i = start;
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

int contains_op(char *exp, int start, int end)
{
    for (int i = start; i <= end; i++)
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