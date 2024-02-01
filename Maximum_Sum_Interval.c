
#include <stdio.h>

int maximum(int a, int b, int c)
{
  if (a>=b && a>=c)
    return a;
  else if (b>=a && b>=c)
    return b;
  return c;
}


int maxcrossrray(int ar[], int low, int mid, int high)
{

  int left_sum = -8888888;
  int sum = 0;
  int i;

  for (i=mid; i>=low; i--)
  {
    sum = sum+ar[i];
    if (sum>left_sum)
      left_sum = sum;
  }

  int right_sum = -8888888;
  sum = 0;

  for (i=mid+1; i<=high; i++)
  {
    sum=sum+ar[i];
    if (sum>right_sum)
      right_sum = sum;
  }

  return (left_sum+right_sum);
}


int maxsubarray(int ar[], int low, int high)
{
  if (high == low)
  {
    return ar[high];
  }

  int mid = (high+low)/2;


  int leftsubarray = maxsubarray(ar, low, mid);
  int rightsubarray = maxsubarray(ar, mid+1, high);
  int maxcrossrray1 = maxcrossrray(ar, low, mid, high);


  return maximum(leftsubarray,rightsubarray, maxcrossrray1);
}


int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxsum = maxsubarray(arr, 0, n - 1);

    printf("Maximum sum interval: %d\n", maxsum);

    return 0;
}
