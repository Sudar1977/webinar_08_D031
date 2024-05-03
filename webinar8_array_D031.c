#include <stdio.h>
#include <inttypes.h>

#define SIZE 5

int Input(int n,int arr[])
{
int i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    return i;
}

int InputFix(int n,int arr[])
{
int i;
    int tmp[SIZE] = {7,16,8,1,9};
    for(i=0;i<n;i++)
        arr[i]=tmp[i];
    return i;
}

void Print(int n,int arr[])
{
    for(int i=0;i<n;i++)
        printf("%5d",arr[i]);
    printf("\n");
}

void Mult(int n,int arr[],int k)
{
    for(int i=0;i<n;i++)
        arr[i]*=k;
}

int Min(int len,int arr[])
{
    int min=arr[0];
    for (int i = 1; i < len; i++)
    {
        if(arr[i]<min)
            min = arr[i];
    }
    return min;
}

int PosMin(int len,int arr[])
{
    int min=arr[0],pos=0;
    for (int i = 1; i < len; i++)
    {
        if(arr[i]<min)
        {
            min = arr[i];
            pos = i;
        }
    }
    return pos;
}

int PosMax(int len,int arr[])
{
    int max=arr[0],pos=0;
    for (int i = 1; i < len; i++)
    {
        if(arr[i]>max)
        {
            max = arr[i];
            pos = i;
        }
    }
    return pos;
}

void SwapArr(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i]   = arr[j];
    arr[j]   = temp;
}

void SwapArrPtr(int* arr,int i,int j)
{
    int temp = *(arr+i);//+ i - к-во элементов
    *(arr+i) = *(arr+j);
    *(arr+j) = temp;
}

void BubbleSort(int len,int arr[])
{
    int noSwap;
    for (int i = 0; i < len; i++)
    {
        noSwap = 1;
        for (int j = len-1; j > i; j--)
        {
            if(arr[j-1]>arr[j])
            {
                SwapArr(arr,j-1,j);
                noSwap = 0;
            }
        }
        if(noSwap)
            break;
    }
}

int main()
{
    int arr[SIZE]={0};
    //~ Input(SIZE,arr);
    InputFix(SIZE,arr);
    int i = 3;
    arr[++i] = 12;//arr[4]=12;i=4;
    Print(SIZE,arr);
    int coef = 5;
    Mult(SIZE,arr,coef);
    Print(SIZE,arr);
    printf("Min =\t\t%d\n",Min(SIZE,arr));
    printf("PosMin =\t%d\n",PosMin(SIZE,arr));
    printf("PosMax =\t%d\n",PosMax(SIZE,arr));
    SwapArr(arr,PosMin(SIZE,arr),PosMax(SIZE,arr));
    Print(SIZE,arr);
    SwapArrPtr(arr,PosMin(SIZE,arr),PosMax(SIZE,arr));
    Print(SIZE,arr);
    BubbleSort(SIZE,arr);
    Print(SIZE,arr);
    return 0;
}
