#include<stdio.h>


int arr[100];

int readfile(int a[])
{
    int i=0;
    FILE *fp;
    
    if((fp=fopen("dataip.txt","r"))!=NULL )
    {
        while (!feof(fp))
        {
            fscanf(fp,"%d",&a[i]);
            i++;
        }
        
    }
    return(i-1);

}

void writefile(int a[],int n)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("dataop.txt","w"))!=NULL)
    {
        for (i = 0; i < n; i++)
        {
            fprintf(fp,"%d",a[i]);
        }
        
    }
}

void quicksort(int a[100], int low, int high)
{
	int pivot,t,i,j;
	if(low<high)
	{
		pivot=a[low];
		i=low;
		j=high;
		while(i<j)
		{
			while(pivot>=a[i] && i<=high)
			i++;
			while(pivot<a[j] && j>=low)
			j--;
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		a[low]=a[j];
		a[j]=pivot;
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
	}
}
void main()
{
    int n,i;
    clrscr();
    n=readfile(arr);
    quicksort(arr,0,n-1);
    writefile(arr,n);
    printf("sorted element is ..");
    for ( i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\nsave successful in file\n");
    


    getch();



}