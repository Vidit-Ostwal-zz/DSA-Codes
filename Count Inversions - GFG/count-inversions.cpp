// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge_sort(vector<long long> &vect, long long i, long long j)
{
    if (i == j)
    {
        return 0;
    }
    
    long long mid = i + (j-i)/2;
    
    long long int left_count = merge_sort(vect,i,mid);
    long long int right_count = merge_sort(vect,mid+1,j);
    
    vector<long long> temp;
    long long int merge_count = 0;
    
    long long st_left = i;
    long long ed_left = mid;
    long long st_right = mid+1;
    long long ed_right = j;
    
    while (st_left <= ed_left && st_right <= ed_right)
    {
        if (vect[st_left] <= vect[st_right])
        {
            temp.push_back(vect[st_left++]);
        }
        else
        {
            temp.push_back(vect[st_right++]);
            merge_count+= (ed_left - st_left + 1);
        }
    }
    
    while (st_left <= ed_left)
    {
        temp.push_back(vect[st_left++]);
    }
    
    while (st_right <= ed_right)
    {
        temp.push_back(vect[st_right++]);
    }
    
    long long st = 0;
    for (int k = i; k <= j; k++)
    {
        vect[k] = temp[st++];
    }
    return left_count + right_count + merge_count;
}

    
    
    long long int inversionCount(long long arr[], long long N)
    {
        vector<long long> vect;
    for (int i = 0; i < N; i++)
    {
        vect.push_back(arr[i]);
    }
    
    return merge_sort(vect,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends