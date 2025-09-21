#include "test.hpp"

void sort_bouble(int arr[], int len)
{
	int temp;

	std::cout << "test\n";

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void reverse_arr(int *arr, int len)
{
    int temp;
    for (int i = 0; i < len / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = low -1 ;
	int temp;

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+ 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}