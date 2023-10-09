#include<iostream>
using namespace std;

//quick sort
void swap(int *a,int *b)
{
    int t=*b;
    *b=*a;
    *a=t;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);

    return i+1;
}

void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int partitionIndex=partition(arr,low,high);

        quickSort(arr,low,partitionIndex-1);

        quickSort(arr,partitionIndex+1,high);
    }
}

//merge sort
void merge(int arr[],int p,int q,int r)
{
    int n1=q-p+1;
    int n2=r-q;

    int L[n1], M[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]=arr[p+i];
    }
    for(int i=0;i<n2;i++)
    {
        M[i]=arr[q+1+i];
    }

    int i=0,j=0,k=p;

    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=M[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        arr[k]=M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low, int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
}

//binary search
int binarySearch(int arr[],int low,int high, int x)
{
    if(low<high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==x) return mid;

        if(x>arr[mid]) return binarySearch(arr,mid+1,high,x);
        return binarySearch(arr,low,mid-1,x);
    }
    return -1;
}

void printArray(int arr[],int n)
{
    cout<<"The array: ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter size of the array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    printArray(arr,n);
    quickSort(arr,0,n-1);
    //mergeSort(arr,0,n-1);
    printArray(arr,n);
    int x;
    cout<<"Enter what to search: ";
    cin>>x;
    cout<<"The index: "<<binarySearch(arr,0,n-1,x)<<endl;

    return 0;
}
