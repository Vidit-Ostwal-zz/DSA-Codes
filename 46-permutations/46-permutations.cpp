class Solution {
public:
  
  /* Main difference from subsets problem is that the processed part size will surely be equal to the initial unprocessed 
  Time Complexity = O(N! * N)
  Sapce Complexity = O(N! * N)*/ 
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
  
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> final_vector;
      permu(nums,0,{},final_vector);
      return final_vector;
    }
};