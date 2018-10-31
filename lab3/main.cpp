#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

int instruction = 0;

void quick_sort(vector<int> &arr, int l, int r)
{
	int left = l;
	int right = r;
	int mid = ceil((double(l + r)) / 2);

	int pivot = 0;
	if (arr[mid] < arr[left] && arr[left] < arr[right] || arr[mid] > arr[left] && arr[left] > arr[right])
		pivot = left;
	else if (arr[mid] < arr[right] && arr[right] < arr[left] || arr[mid] > arr[right] && arr[right] > arr[left])
		pivot = right;
	else
		pivot = mid;


	while (left < pivot || pivot < right)
	{
		if (left < pivot)
		{
			while (arr[left] < arr[pivot])
			{
				left++;
			}
		}
		if (right > pivot)
		{
			while (arr[right] > arr[pivot])
			{
				right--;
			}
		}

		if (left < pivot && right > pivot)
		{
			swap(arr[left], arr[right]);
			right--;
			left++;
		}

		else if (left < pivot && pivot >= right)
		{
			for (int i = left; i < pivot; i++)
			{
				swap(arr[i], arr[i + 1]);
			}
			pivot--;
			left++;
		}
		else if (left >= pivot && pivot < right)
		{
			for (int i = right; i > pivot; i--)
			{
				swap(arr[i], arr[i - 1]);
			}
			pivot++;
		}


	}


	if (l < pivot)
	{
		quick_sort(arr, l, pivot - 1);
	}
	if (pivot < r)
	{
		quick_sort(arr, pivot + 1, r);
	}
}

void insertion_sort(vector<int> &arr)
{
	int length = arr.size();
	int left;
	int right;
	for (int i = 0; i < length - 1; i++)
	{
		left = i;
		right = i + 1;
		while (left > 0 && arr[right] < arr[left])
		{
			swap(arr[right], arr[left]);
			right--;
			left--;
			instruction++;
		}
		instruction++;
	}

}


int main()
{
	int n;
	srand(time(0));
	cout << "Please enter the number of integers to be in the array: ";
	cin >> n;
	cout << "Timer starting" << endl;
	auto start = chrono::high_resolution_clock::now();
	for (int l = 0; l < 100; l++)
	{
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			vec.push_back((rand() % 10001 - 5000));
		}
		insertion_sort(vec);
	}

	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>((end - start) / 100);
	cout << "insertion takes " << duration.count() << " microseconds" << endl;
	duration = chrono::duration_cast<chrono::microseconds>((end - start));
	double instructionTime = double(duration.count()) / instruction;
	cout << "An instruction takes " << instructionTime << " microseconds." << endl;

	cout << "Timer starting" << endl;
	start = chrono::high_resolution_clock::now();
	for (int l = 0; l < 100; l++)
	{
		vector<int> vec;
		for (int i = 0; i < n; i++)
		{
			vec.push_back((rand() % 10001 - 5000));
		}
		quick_sort(vec, 0, (vec.size() - 1));
	}
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>((end - start) / 100);
	cout << "quick takes " << duration.count() << " microseconds" << endl;
	cout << endl;

}