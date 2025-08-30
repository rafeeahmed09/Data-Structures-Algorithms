#include<iostream>
using namespace std;
void selection(int arr[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int smallestindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallestindex])
            {
                smallestindex = j;
            }
        }
        swap(arr[i], arr[smallestindex]);
    }
}
void prind(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){
    int n = 5;
    int arr[] = {40,10,20,30,50};
    selection(arr, n);
    prind(arr, n);

    return 0;
}