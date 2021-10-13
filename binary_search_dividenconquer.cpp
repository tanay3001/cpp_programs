#include<iostream>

using namespace std;

void bubbleSort(int arr[],int size)     {
        
   for (int i = 0; i < size; i++)      
 
       for (int j = 0; j < size-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(arr[j], arr[j+1]);

}

int binarySearch(int arr[],int start,int last,int search)	{
        
        if(last>=start)  {
                                
                int mid=(start+last)/2;
                
                if(arr[mid]==search)    {
                        return mid;
                }
                else if(arr[mid]>search)        {
                        return binarySearch(arr,start,mid-1,search);
                }
                else    {
                        return binarySearch(arr,mid+1,last,search);
                }  
        }
        return -1;
}

int main()	{
	
	int length,element,choice;
	cout<<"\nEnter array size: ";
	cin>>length;
	
	int array[length];
	
	cout<<"\nEnter array elements: ";
	for(int i=0;i<length;i++){
	        cin>>array[i];
	}
	
	bubbleSort(array,length);
	
	
	
	cout<<"\nSorted Array: ";
	for(int i=0;i<length;i++){
	        cout<<"\t"<<array[i];
	}
	
	while(1)	{

		cout<<"\nMENU "
		<<"\n1. Iterative Approach" 
		<<"\n2. Recursive Approach"
		<<"\n3. Exit"
		<<"\n   Enter your choice: ";
		cin>>choice;


		switch(choice)  {
		
		        case 1: {
		        		cout<<"\nEnter element to search: ";
						cin>>element;
		                int start=0, last=length-1,mid;
		                
		                while(last>=start)  {
	                                        
	                                mid=(start+last)/2;
	                                
	                                if(array[mid]==element)    {
	                                        cout<<"\nElement found at position: "<<mid+1<<endl;
	                                        break;
	                                }
	                                else if(array[mid]>element)        {
	                                        last=mid-1;
	                                }
	                                else    {
	                                        start=mid+1;
	                                }  
	                        }
	                        if(last<start) {
	                                cout<<"\nElement doesn't exist in array!!! Search Failed.."<<endl;
	                        }
		        }
		        break;
		        
		        case 2: {
	        			cout<<"\nEnter element to search: ";
						cin>>element;
		                int result=binarySearch(array,0,length-1,element);
	                
	                        if(result==-1){
	                                cout<<"\nElement doesn't exist in array!!! Search Failed.."<<endl;
	                        }
	                        else{
	                                cout<<"\nElement found at position: "<<result+1<<endl;
	                        }
	                }        
		        break;
		        case 3: exit(0);
		        default : cout<<"\nWrong choice entered";
		        	
		}
	}
	        return 0;
}
