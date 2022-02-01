class Solution {
public:
  void permu(vector<int> nums,int index, vector<int> processed, vector<vector<int>> &final_vector)
  {
    if (index == nums.size())
    {
      final_vector.push_back(processed);
      return;
    }
    
    for (int i = 0; i < processed.size()+1; i++)
    {
      processed.insert(processed.begin()+i,nums[index]);
      permu(nums,index+1,processed,final_vector);
      processed.erase(processed.begin()+i);
    }
  }
  
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> final_vector;
      permu(nums,0,{},final_vector);
      set<vector<int>>set_vector(final_vector.begin(),final_vector.end());
      vector<vector<int>> temp_vector(set_vector.begin(),set_vector.end());
      return temp_vector;
    }
};