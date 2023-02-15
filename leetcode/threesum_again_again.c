#include <stdio.h>
#include <stdlib.h>

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);
int is_duplicate(int **nums, int N, int a, int b, int c);
void sort(int *nums, int N);

int main()
{
    int nums[] = {-7, -4, -6, 6, 4, -6, -9, -10, -7, 5, 3, -1, -5, 8, -1, -2, -8, -1, 5, -3, -5, 4, 2, -5, -4, 4, 7};
    int numsSize = 27;
    int returnSize;
    int *returnColumnsSizes;

    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnsSizes);

    for (int k = 0; k < returnSize; k++)
    {
        printf("[");
        for (int j = 0; j < returnColumnsSizes[k]; j++)
        {
            printf("%d ", result[k][j]);
        }
        printf("] | ");
    }
    printf("\n");
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    sort(nums, numsSize);
    int **result = malloc(sizeof(int *) * numsSize * 2);
    *returnColumnSizes = malloc(sizeof(int) * numsSize * 2);
    int t = 0;

    int j = 0, k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        j = i + 1;
        k = numsSize - 1;
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] == 0 && !is_duplicate(result, t, nums[i], nums[j], nums[k]))
            {
                result[t] = malloc(sizeof(int) * 3);
                result[t][0] = nums[i];
                result[t][1] = nums[j];
                result[t][2] = nums[k];

                (*returnColumnSizes)[t] = 3;
                t++;
                j++;
                k--;
            }
            else if (nums[i] + nums[j] + nums[k] < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }

    *returnSize = t;
    return result;
}

int is_duplicate(int **nums, int N, int a, int b, int c)
{
    int present[3] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (nums[i][j] == a && !present[0])
                present[0] = 1;
            else if (nums[i][j] == b && !present[1])
                present[1] = 1;
            else if (nums[i][j] == c && !present[2])
                present[2] = 1;
        }

        if (present[0] && present[1] && present[2])
            return 1;
        else
        {
            present[0] = present[1] = present[2] = 0;
        }
    }

    return 0;
}

void sort(int *number, int N)
{
    int i, j;
    int a;
    for (i = 0; i < N; ++i)

    {

        for (j = i + 1; j < N; ++j)

        {

            if (number[i] > number[j])

            {

                a = number[i];

                number[i] = number[j];

                number[j] = a;
            }
        }
    }
}