#include <stdio.h>
#include <stdlib.h>

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);
int **twoSum(int *nums, int numsSize, int target, int targLoc, int *returnSize);
int is_duplicate(int **nums, int N, int a, int b, int c);
int is_dup(int **nums, int N, int a, int b);
int sum_exists(int *nums, int N, int x);
void dealloc_twosum(int **nums, int N);

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
    int **result = malloc(sizeof(int *) * numsSize * 2);
    *returnColumnSizes = malloc(sizeof(int) * numsSize * 2);
    int t = 0;

    int **twoSumNums;
    int twoSize = 0;

    int target;

    for (int i = 0; i < numsSize; i++)
    {
        target = -nums[i];

        twoSumNums = twoSum(nums, numsSize, target, i, &twoSize);
        if (twoSize == 0)
            continue;

        for (int j = 0; j < twoSize; j++)
        {
            int a = nums[i];
            int b = twoSumNums[j][0];
            int c = twoSumNums[j][1];
            if (is_duplicate(result, t, a, b, c))
                continue;

            result[t] = malloc(sizeof(int) * 3);
            result[t][0] = a;
            result[t][1] = b;
            result[t][2] = c;

            (*returnColumnSizes)[t] = 3;
            t++;
        }
        dealloc_twosum(twoSumNums, twoSize);
        twoSize = 0;
    }

    *returnSize = t;
    return result;
}

int **twoSum(int *nums, int numsSize, int target, int targLoc, int *returnSize)
{
    int **result = malloc(sizeof(int *) * numsSize);

    int t = 0;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (i != targLoc && j != targLoc && nums[i] + nums[j] == target && !is_dup(result, t, nums[i], nums[j]))
            {
                result[t] = malloc(sizeof(int) * 2);
                result[t][0] = nums[i];
                result[t][1] = nums[j];

                t++;
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

int is_dup(int **nums, int N, int a, int b)
{
    int a_exists = 0, b_exists = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (!a_exists && nums[i][j] == a)
                a_exists = 1;
            else if (!b_exists && nums[i][j] == b)
                b_exists = 1;
        }

        if (a_exists && b_exists)
            return 1;
        else
        {
            a_exists = 0, b_exists = 0;
        }
    }

    return 0;
}

int sum_exists(int *nums, int N, int x)
{
    for (int i = 0; i < N; i++)
    {
        if (nums[i] == x)
            return 1;
    }

    return 0;
}

void dealloc_twosum(int **nums, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(nums[i]);
    }

    free(nums);
}