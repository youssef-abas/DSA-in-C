#include <stdio.h>
#include <stdlib.h>

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);
void sort(int *nums, int N);

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
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
    int **result = malloc(sizeof(int *) * 20000);
    *returnColumnSizes = malloc(sizeof(int) * 20000);
    int t = 0;

    int j = 0, k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        j = i + 1;
        k = numsSize - 1;
        while (j < k)
        {
            int a = nums[i];
            int b = nums[j];
            int c = nums[k];

            int sum = a + b + c;
            if (sum == 0)
            {
                result[t] = malloc(sizeof(int) * 3);
                result[t][0] = a;
                result[t][1] = b;
                result[t][2] = c;

                (*returnColumnSizes)[t] = 3;
                t++;
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }

            while (j < k && nums[j] == b)
            {
                j++;
            }
            while (j < k && nums[k] == c)
            {
                k++;
            }
        }

        while (i + 1 < numsSize && nums[i + 1] == nums[i])
        {
            i++;
        }
    }

    *returnSize = t;
    return result;
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