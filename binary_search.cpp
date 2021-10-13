#include<iostream>
#include <time.h> 
using namespace std;

int binarySearch(int arr[], int low, int high, int a) {
	cout<<"binarySearch() starts \n"; 
    cout<<"Press enter to stop binarySearch \n";	
   if (high >= low) 
   { 
        int mid = low + (high - low)/2; 
        if (arr[mid] == a)  return mid; 
  
        if (arr[mid] > a) return binarySearch(arr, low, mid-1, a); 
        return binarySearch(arr, mid+1, high, a); 
   } 
   cout<<"binarySearch() ends \n";
   return -1; 
   
} 
  
int main(void) 
{ 
	clock_t t; 
    t = clock(); 
   	int low=0,high,mid,n,a;
	cout<<"Enter the size of the array : ";
	cin>>n;
	int arr[n];
	high=n-1;
	cout<<"\nEnter the elements of the array one by one : ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<"\nEnter the element you want to search : ";
	cin>>a;
   int result = binarySearch(arr, low, high, a); 
   (result == -1)? printf("Element is not present in array") 
                 : printf("Element is present at index %d", result); 
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    cout<<"\nbinarySearch() took "<<time_taken<<" seconds to execute \n";
   return 0; 
} 
