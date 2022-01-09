class Solution {
public:
  
  /*Approach 1
  Final Vector returned by adding Sub final vector
  Time Complexity = O(2^N)
  Space Complexity = O(N)*/
  vector<vector<int>> get_all_subsets(vector<int>&nums,int index,vector<int> prev_vector)
  {
    if (index == nums.size())
    {
      vector<vector<int>> temp_vector;
      temp_vector.push_back(prev_vector);
      return temp_vector;
    }
    
    vector<vector<int>> first_vector = get_all_subsets(nums,index+1,prev_vector);
   
    prev_vector.push_back(nums[index]);
    vector<vector<int>> second_vector = get_all_subsets(nums,index+1,prev_vector);
    first_vector.insert(first_vector.end(),second_vector.begin(),second_vector.end());
    
    return first_vector;
  }
  
  /*Approach 2
  Final_vector passed by address
  Time Complexity = O(2^N)
  Space Complexity = O(N)*/
  void get_all_subsets_void(vector<int>&nums,int index,vector<int> prev_vector,vector<vector<int>> & final_vector)
  {
    if (index == nums.size())
    {
      final_vector.push_back(prev_vector);
      return ;
    }
    
    get_all_subsets_void(nums,index+1,prev_vector,final_vector);
    prev_vector.push_back(nums[index]);
    get_all_subsets_void(nums,index+1,prev_vector,final_vector);
  }
  
  
  /*Iterative Approach
  Space Compleixty = O (2^N * N)
  
  Total Number of levels and time taken at each level.
  Time Complexity = O(N * 2^N) 
  N for a Loop and 2^N for copying at each level. 
  */
  vector<vector<int>> iterative_approach(vector<int> nums)
  {
    vector<vector<int>> final_vector = {{}};
    for (int i = 0; i < nums.size(); i++)
    {
      vector<vector<int>> temp_vector(final_vector.begin(),final_vector.end());
      for (int j= 0 ;j< temp_vector.size(); j++)
      {
        temp_vector[j].push_back(nums[i]);
        final_vector.push_back(temp_vector[j]);
      }
    }
    return final_vector;
  }
  
  
    vector<vector<int>> subsets(vector<int>& nums) {
      return iterative_approach(nums);
    }
};