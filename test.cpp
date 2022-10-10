#include <iostream>
using namespace std;
int totalanswer = 0;
void Merge(int *arr, int begin, int mid, int end)
{
    int i = begin, j = mid + 1, k = 0;
    int *temp = new int[end - begin + 1];
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for (int i = begin, k = 0; i <= end; i++, k++)
    {
        arr[i] = temp[k];
    }
    delete[] temp;
}

void MergeSort(int *arr, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = begin + (end - begin) / 2;
    MergeSort(arr, begin, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, begin, mid, end);
    totalanswer += arr[end] - arr[begin];
}

int main()
{
    int n = 0;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        cin >> m;
        arr[i] = m;
    }
    MergeSort(arr, 0, n - 1);

    cout << totalanswer;
    return 0;
}