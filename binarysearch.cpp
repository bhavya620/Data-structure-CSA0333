#include<stdio.h>
int binarysearch(int arr[],int n,int key){
	int l=0,h=n-1;
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(arr[mid]==key)
		return mid;
		else if(arr[mid]<key)
		l=mid+1;
		else
		h=mid-1;
	}
	return -1;
}
int main()
	{
	int arr[]={1,5,6,7,9,10};
	int n=sizeof(arr)/sizeof(arr[0]);
	int key;
	printf("enter the number: ");
	scanf("%d",&key);
	int result=binarysearch(arr,n,key);
	if(result!=-1)
	printf("element found at inde %d\n",result);
	else
	printf("element not found ");
	return 0;
}