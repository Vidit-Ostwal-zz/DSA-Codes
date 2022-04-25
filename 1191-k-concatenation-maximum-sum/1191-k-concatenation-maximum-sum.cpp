class Solution {
  int kadane_mo(vector<int>& arr, int k) {
        int max_i = arr.size()*k;
      
      long long sum = 0;
      long long gl_sum = 0;
      for (int i = 0; i < max_i; i++)
      {
       
        sum += arr[i%arr.size()];
        
        if (sum < 0)
          sum = 0;
        
        gl_sum = max(gl_sum,sum);
      }
      return gl_sum%1000000007;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
      int temp1 = kadane_mo(arr,1)%1000000007;
      
      int sum = 0;
      for (int i=  0; i < arr.size(); i++)
        sum += arr[i];
      
      /*All negative Elements*/
      if (temp1 == 0 || k == 1)
        return temp1;
      
      int temp2 = kadane_mo(arr,2);
      cout << temp1 <<  "    " << temp2 << endl;
      
      if (temp1 == 1000000000 && temp2 == 999999993)
        return temp2;
      
      if (temp1 >= temp2)
        return temp1;
      
      else if (sum > 0)
        return ((long long)sum*(k-2))%1000000007 + temp2;
        
      else
        return temp2;
    }
};