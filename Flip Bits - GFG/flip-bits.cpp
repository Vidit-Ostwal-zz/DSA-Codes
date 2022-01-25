// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    /*Time Complexity = O(N*2)*/
    int brute_force(int A[], int n)
    {
        int count = 0;
    /*This vector will represent the number of whihc have already appreared before it for a particular index.*/
    vector<int>number1;
    for (int i = 0; i < n;i++)
    {
        if (A[i] == 1) count++;
        number1.push_back(count);
    }
    vector<int> answer = {-1,-1};
    int max1 = INT_MIN;
    if (count == n)
    return count;

    for (int left = 0; left < n;left++)
    {
        for (int right = left; right < n;right++)
        {
            int left_sum = (left == 0) ? 0 : number1[left-1];
            int right_sum = count - number1[right];
            int middle_sum = number1[right]  - left_sum;

            if (max1 < left_sum + right_sum + (right - left + 1) - middle_sum)
            {
                max1 = left_sum + right_sum + (right - left + 1) - middle_sum;
                answer[0]=left+1;
                answer[1]=right+1;
            }
        }
    }
    return  max1;
    }
    
    int kadane (int A[], int n)
    {
        int max_answer = INT_MIN;
        int temp_answer = 0;
        int count =  0;
        for (int i =0; i < n ; i++)
        {
            if (A[i] == 1) count++;
            A[i] = (A[i] == 0) ? 1 : -1;
            temp_answer = temp_answer + A[i];
            
            if (temp_answer < 0)
            temp_answer  = 0;
            
            if (max_answer < temp_answer)
            max_answer = temp_answer;
        }
        
        return max_answer+count;
    }
    public:
    int maxOnes(int A[], int n)
    {
        return kadane(A,n);
    }
};


// { Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}
  // } Driver Code Ends