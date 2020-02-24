# include <iostream>
# include <cstdlib>
# include <ctime>

using namespace std;

void Merge(int arr[], int low, int mid, int high)
{
    int i, j, k, b[20];
    i = low; j = mid+1; k = low;
    while ( i <= mid && j <= high )
{
    if( arr[i] <= arr[j] )
        b[k++] = arr[i++] ;
    else
        b[k++] = arr[j++] ;
}
    while (i<=mid) b[k++] = arr[i++] ;
    while (j<=high) b[k++] = arr[j++] ;

    for(k=low; k<=high; k++)
        arr[k] = b[k];
}
void MergeSort(int arr[], int low, int high)
{
    int mid;
    if(low >= high)
        return;
    mid = (low+high)/2 ;
    MergeSort(arr, low, mid);
    MergeSort(arr, mid+1, high);
    Merge(arr, low, mid, high);
}
int main()
{
    int n, arr[2000], k;
    clock_t st, et;
    double ts;

    cout<<"Enter How many Numbers: ";
    cin>>n;
    cout<<"The Random Numbers are: "<<endl;
    for(k = 1; k <= n; k++){
        arr[k] = rand();
        cout<<"\t"<<arr[k]<<endl ;
    }
    st = clock();
    MergeSort(arr, 1, n);
    et = clock();
    ts = (double)(et-st)/CLOCKS_PER_SEC;
    cout<<"Sorted Numbers are : "<<endl;
    for(k = 1; k <= n; k++)
        cout<<"\t"<< arr[k]<<endl;
    cout<<"The time taken is "<<ts;

    return 0;
}
