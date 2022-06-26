class Solution {
  int kadane(vector<int> diff, vector<int> nums1)
  {
    int sum = 0;
      int k = 0;
      int answer = 0;
      for (int i = 0; i < diff.size(); i++)
      {
        k += nums1[i];
        sum += diff[i];
        
        answer = max(answer,sum);
        
        if (sum < 0)
        {
          sum = 0;
        }
      }
      
      return k+  answer;
  }
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diff1;
      vector<int> diff2;
      for (int i = 0; i < nums1.size(); i++)
      {
        diff1.push_back(nums2[i]-nums1[i]);
        diff2.push_back(nums1[i]-nums2[i]);
      }
      
      return max(kadane(diff1,nums1),kadane(diff2,nums2));
    }
};