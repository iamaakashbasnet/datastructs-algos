/**
 * @brief Linear search
 *
 */

#include <iostream>

void linearSearch(int[], int, int);

int main()
{
    int arr1[] = {1, 5, 3, 6, 7, 2};
    int arr2[] = {5, 6, 3};

    linearSearch(arr1, sizeof(arr1) / sizeof(arr1[0]), 10);
    linearSearch(arr2, sizeof(arr2) / sizeof(arr2[0]), 6);

    return 0;
}

void linearSearch(int arr[], int len, int target)
{
    // Can't calculate array size here as array decay to ptr

    bool targetFound = false;

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == target)
        {
            std::cout << "Target " << target << " found at index " << i << std::endl;
            targetFound = true;
            break;
        }
    }

    if (!targetFound)
        std::cout << "Target does not exist in the given array" << std::endl;
}