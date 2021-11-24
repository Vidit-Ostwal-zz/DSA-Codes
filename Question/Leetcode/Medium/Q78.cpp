class Solution {
public:
  /* process of processed and unprocessed string 
  - Base condition when met return the final_answer vector
  Recursion call will also return the vector but those will not aquired by anyone.
  Here a property of vector is highly used where when a vector is psssed a copy of it is passed not a pointer 
  Again the get _subsets function can be made void as final_answer is passed as a pointer 
  the temp answer and final vector is passed in each function call*/
  vector<vector<int>> get_subsets(vector<int>& nums, int index, vector<int>temp_answer, vector<vector<int>>& final_answer)
  {
    if (index == nums.size())
    {
      final_answer.push_back(temp_answer);
      return final_answer;
    }
    
    get_subsets(nums,index+1,temp_answer,final_answer);
    temp_answer.push_back(nums[index]);
    get_subsets(nums,index+1,temp_answer,final_answer);
    
    return final_answer;
  }

  
  /* Another way where we don't require to pass the vector of final vector of vector we make a new one and add them at last*/
  vector<vector<int>> get_subsets1(vector<int>& nums, int index, vector<int>prev_answer)
  {
    if (index == nums.size())
    {
      vector<vector<int>> temp_vector;
      temp_vector.push_back(prev_answer);
      return temp_vector;
    }
    
    vector<vector<int>> answer1 = get_subsets1(nums,index+1,prev_answer);
    prev_answer.push_back(nums[index]);
    vector<vector<int>> answer2 = get_subsets1(nums,index+1,prev_answer);
    answer1.insert(answer1.end(),answer2.begin(),answer2.end());
    
    return answer1;
  }
  
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<int>temp_answer;
      return get_subsets1(nums,0,temp_answer);
    }
};
