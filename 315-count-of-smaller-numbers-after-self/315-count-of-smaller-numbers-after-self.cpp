#define pi pair<int,int>

class Solution {
  vector<int> count;
  
  void merge_sort(vector<pi> &nums, int start_index, int end_index)
  {
    if (start_index >= end_index)
      return;
    
    int middle = (start_index + end_index)/2;
    
    // vector<pi> left(nums.begin(),nums.begin()+middle);
    // vector<pi> right(nums.begin()+middle,nums.end());
    
    merge_sort(nums,start_index,middle);
    merge_sort(nums,middle+1,end_index);
    
    // left = merge_sort(left);
    // right = merge_sort(right);
    
    vector<pi> merged;
    
    int i = start_index;
    int j = middle+1;
    int cnt = 0;
    
    while (i <= middle && j <= end_index)
    {
      int left_element = nums[i].first;
      int right_element = nums[j].first;
      
      if (left_element <= right_element)
      {
        count[nums[i].second] += cnt;
        merged.push_back(nums[i]);
        i++;
      }
      else 
      {
        merged.push_back(nums[j]);
        cnt++;
        j++;
      }
    }
    
    while (i <= middle)
    {
      count[nums[i].second] += cnt;
      merged.push_back(nums[i]);
      i++;
    }
    
    while (j <= end_index)
    {
      merged.push_back(nums[j]);
      j++;
    }
    
    
    j = start_index;
    for (int i = 0; i < merged.size(); i++)
    {
      nums[j].first = merged[i].first;
      nums[j].second = merged[i].second;
      j++;
    }
    return;
  }
public:
    vector<int> countSmaller(vector<int>& nums) {
        
      int size = nums.size();
      
     vector<pi> nums_updated(size,{0,0});
      count = vector<int>(size,0);
      
      for (int i = 0; i < nums.size(); i++)
      {
        nums_updated[i].first = nums[i];
        nums_updated[i].second = i;
      }
      
      merge_sort(nums_updated,0,size-1);
      return count;
    }
};