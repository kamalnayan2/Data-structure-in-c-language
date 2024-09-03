#include<stdio.h>
void selectionsort(int arr[],int n)
{
    int index,temp,i,j;
    for(i=0;i<n-1;i++)
    {
        index=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[index])
            index=j;
        }
        temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
    }
}
void main()
{
    int arr[]={51,2,5,3,1,2},n,i;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("unsorted array is:");
    for (i = 0; i < n; i++)
    printf("%d ",arr[i]);
    
    selectionsort(arr,n);
    
    printf("\nsorted array is:");
    for (i = 0; i < n; i++)
    printf("%d ",arr[i]);
    getch();

}