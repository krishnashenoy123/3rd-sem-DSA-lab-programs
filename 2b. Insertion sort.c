#include<stdio.h>
int a[10],i,j,n,temp;
void isr(int a[],int n)
{
    if(n<=1)
    return;
    isr(a,n-1);
    temp=a[n-1];
    j=n-2;
    while(j>=0&&a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
}
int main()
{
    printf("Enter the size of an array : \n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    isr(a,n);
    printf("Sorted array is : \n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\n");
    return 0;
}