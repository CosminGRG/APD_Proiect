// C++ program of above implementation
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

// Pair struct is used to return
// two values from getMinMax()2147483647
struct Pair
{
    int min;
    int max;
};

Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;

    // If there is only one element
    // then return it as min and max both
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }

    // If there are more than one elements,
    // then initialize min and max
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
            minmax.max = arr[i];

        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}

// Driver code
int main()
{
	int* arr = new int[100000000];
	int arr_size = 0;
	
	ifstream infile;
	infile.open("100.000.000-ints.txt");

	if (infile.fail())
	{
		cout << "input file could not be opened" << endl;
		system("pause");
		exit(1);
	}

	while (infile >> arr[arr_size])
	{
		arr_size++;
	}

	cout << "There are " << arr_size << " numbers in the file" << endl;

	clock_t tStart = clock();

	Pair minmax = getMinMax(arr, arr_size);

	cout << "nMinimum element is "
		<< minmax.min << endl;
	cout << "nMaximum element is "
		<< minmax.max << endl;
	
	delete[] arr;

	printf("Time taken: %.5fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	return 0;
}

// This code is contributed by nik_3112
