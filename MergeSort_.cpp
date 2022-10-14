#include <iostream>
using namespace std;

void Merge(int *arr, int begin,int mid, int end);
void MergeSort(int *arr, int begin, int end);
int totalanswer = 0;
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

void Merge(int * array, int begin, int mid, int end){
    int * temp = new int[end-begin+1];
    int i = begin, j = mid+1;
    int k = 0;
    while(i <= mid && j <= end){
        if(array[i] < array[j]){
            temp[k++] = array[i++];
        }
        else{
            temp[k++] = array[j++];
        }
    }
    while(j <= end){
        temp[k++] = array[j++];
    }
    while(i <= mid){
        temp[k++] = array[i++];
    }
    for(int i = begin, k = 0; i <= end; i++, k++){
        array[i] = temp[k];
    }
    totalanswer += array[end] - array[begin];
    delete [] temp;
}
void MergeSort(int* array, int begin, int end){
    if(begin >= end){
        return ;
    }
    int mid = (begin+end)/2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);

}