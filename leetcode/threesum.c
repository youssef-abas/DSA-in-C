#include <stdio.h>
#include <stdlib.h>

int is_duplicate(int **nums, int N, int a, int b, int c);
int *twoSum(int *nums, int numsSize, int target, int targLoc);
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes);

int main()
{
    int nums[] = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    int numsSize = 11;
    int returnSize = 0;
    int *returnColumnSizes;

    int **result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n", (*(&returnColumnSizes))[i]);
    // }

    for (int i = 0; i < returnSize; i++)
    {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("] | ");
    }
    printf("\n");
}

int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;

    char used[numsSize];
    int **trips = malloc(sizeof(int *) * numsSize);
    *returnColumnSizes = malloc(sizeof(int) * numsSize);

    int t = 0;
    int *locations;
    for (int i = 0; i < numsSize; i++)
    {
        int target = -1 * nums[i];
        if ((locations = twoSum(nums, numsSize, target, i)) != NULL)
        {
            if (is_duplicate(trips, t, nums[i], nums[locations[0]], nums[locations[1]]))
            {
                free(locations);
                continue;
            }
            trips[t] = malloc(sizeof(int) * 3);
            trips[t][0] = nums[i];
            trips[t][1] = nums[locations[0]];
            trips[t][2] = nums[locations[1]];

            free(locations);

            (*returnColumnSizes)[t] = 3;
            (*returnSize)++;
            t++;
        }
    }

    return trips;
}

int *twoSum(int *nums, int numsSize, int target, int targLoc)
{
    int *locs = malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target && i != targLoc && j != targLoc)
            {
                locs[0] = i;
                locs[1] = j;
                return locs;
            }
        }
    }

    return NULL;
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

            if (nums[i][j] == b && !present[1])
                present[1] = 1;

            if (nums[i][j] == c && !present[2])
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