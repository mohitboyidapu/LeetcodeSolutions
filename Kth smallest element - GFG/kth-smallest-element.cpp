// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        //will solve this by using heap - Max Heap
        //This takes nlogk time in the worst case, o(k) space
        // Also try hashmap solution
        
        priority_queue<int> maxHeap;
        
        for(int i=l; i<=r; i++){
            maxHeap.push(arr[i]); // pushing element into heap;
            if(maxHeap.size()>k) maxHeap.pop(); 
            //at the end we have only heap of size k, as this is a max Hea, we get min of k largest elemts, ele at top;
        }
        return maxHeap.top();
        
        
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends