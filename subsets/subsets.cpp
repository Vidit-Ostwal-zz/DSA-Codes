class Solution {
public:
  
  /*Approach 1*/
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
  
  
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int> prev_vector;
      vector<vector<int>> final_vector;
      get_all_subsets_void(nums,0,prev_vector,final_vector);
      return final_vector;
    }
};