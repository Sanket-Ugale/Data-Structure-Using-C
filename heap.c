#include<stdio.h>
#include<conio.h>
#define N 10
int arr[N],parent,value,i,choice;

void insertHeap(){
    N=N+1;
    arr[N]=value;
    i=N;
    while (i>1)
    {
        parent=i/2;
        if (arr[parent]<arr[i])
        {
            swap(arr[parent],arr[i]);
            i=parent;
        }
        else
        {
            return;
        }
              
    }
    
}

int main(){
    printf("\nEnter data in Heap: ");
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }    
    printf("\nEntered data in Heap is: ");
    for (int i = 0; i < N; i++)
    {
        printf("\t%d",arr[i]);
    }
    printf("\n----------------------------------------------------------------\n");
    printf("\n1. Press 1 to insert data in Heap.");
    printf("\n2. Press 2 to delete data from Heap.");
    printf("\n3. Press 3 to insert data in Heap.");
    printf("\n----------------------------------------------------------------\n");
    scanf("%d",&choice);
}