class Solution {
  int countthreeSum(vector<int>& nums, int start_index, int end_index, int target) 
  {
    int answer = 0;
      for (int i = start_index; i <= end_index-2; i++)
      {
        int first = nums[i];
        int start = i+1;
        int end = end_index;
        
        while (start < end)
        {
          int sum = first + nums[start] + nums[end];
          if (sum == target)
          {
            cout << target << "    " << nums[i] << "    " << i << "  " << nums[start] << "    " <<  nums[end] <<endl;
            if (nums[start] == nums[end])
            {
              int length = end - start + 1;
              answer += (length * (length-1))/2;
              return answer;
            }
            
            int count1 = 1;
            while (nums[start] == nums[start+1])
            {
              count1++;
              start++;
              cout << "Same" << endl;
            }
            
            int count2 = 1;
            while (nums[end] == nums[end-1])
            {
              count2++;
              end--;
            }
            
            answer += count1 * count2;
            start++;
            end--;
          }
          
          else if (sum > target)
            end--;
          
          else
            start++;
        }
      }
      return answer;
    }
  
  /*sort(nums.begin(),nums.end());
      int answer = 0;
      
      int i = nums.size()-1;
      while (i >= 3)
      {
        answer += countthreeSum(nums,0,i-1,nums[i]);
        cout << answer << endl;
        i--;
      }
      return answer++;*/
  
public:
    int countQuadruplets(vector<int>& nums) {
      /*Same Approach of using hash map
      https://leetcode.com/problems/4sum-ii/
      In this four differnet vectors are not their but we can make
      We are making all typical possible combination no need of sorting the vector*/
      int answer = 0;
      map<int,int> mp;
      /*b index will denote the 2 number*/
      for (int b = 1; b < nums.size()-2; b++)
      {
        for (int i = 0; i < b ;i++)
        {
          mp[nums[i]+nums[b]]++;
        }
        for (int j = b+2; j < nums.size();j++)
        {
          answer += mp[nums[j]-nums[b+1]];
        }
      }
      
      return answer;
    }
};