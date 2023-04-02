#include <stdio.h>
#include <stdlib.h>

#include <time.h>

long nmDice(long, long);
long nmDice_td(long, long);
long nmDice_bu(long, long);

long **tab;

long main(long argc, char **argv)
{
    long n = atoi(argv[1]);
    long m = atoi(argv[2]);

    tab = malloc(sizeof(long *) * (n + 1));
    for (long i = 1; i <= n; i++)
    {
        tab[i] = malloc(sizeof(long) * (m + 1));
    }

    for (long i = 1; i <= n; i++)
    {
        for (long j = 1; j <= m; j++)
        {
            if (i == 1)
            {
                if (j >= 1 && j <= 6)
                    tab[i][j] = 1;
                else
                    tab[i][j] = 0;
            }
            else
                tab[i][j] = -1;
        }
    }

    time_t start = time(NULL);
    long ans = nmDice(n, m);
    time_t end = time(NULL) - start;
    printf("Algo took %ld seconds to produce answer: %ld\n", end, ans);
}

long nmDice(long n, long m)
{
    if (n == 1)
    {
        if (m > 0 && m < 7)
            return 1;
        else
            return 0;
    }

    return nmDice(n - 1, m - 1) + nmDice(n - 1, m - 2) + nmDice(n - 1, m - 3) +
           nmDice(n - 1, m - 4) + nmDice(n - 1, m - 5) + nmDice(n - 1, m - 6);
}

long nmDice_td(long n, long m)
{
    if (m <= 0)
        return 0;

    if (tab[n][m] != -1)
        return tab[n][m];

    tab[n][m] = nmDice_td(n - 1, m - 1) + nmDice_td(n - 1, m - 2) + nmDice_td(n - 1, m - 3) +
                nmDice_td(n - 1, m - 4) + nmDice_td(n - 1, m - 5) + nmDice_td(n - 1, m - 6);

    return tab[n][m];
}

long nmDice_bu(long n, long m)
{
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int k1 = j - 1,
                k2 = j - 2,
                k3 = j - 3,
                k4 = j - 4,
                k5 = j - 5,
                k6 = j - 6;

            tab[i][j] = ((k1 > 0) ? tab[i - 1][k1] : 0) +
                        ((k2 > 0) ? tab[i - 1][k2] : 0) +
                        ((k3 > 0) ? tab[i - 1][k3] : 0) +
                        ((k4 > 0) ? tab[i - 1][k4] : 0) +
                        ((k5 > 0) ? tab[i - 1][k5] : 0) +
                        ((k6 > 0) ? tab[i - 1][k6] : 0);
        }
    }

    return tab[n][m];
}