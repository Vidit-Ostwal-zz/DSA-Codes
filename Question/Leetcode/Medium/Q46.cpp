/* 
1> Every element needs to be added so in subsets problem two recursive call were need where we reject one and accept one 
here we have to accept every answer
2> No of recursive call will be dependent on the size of previous proccessed one
3> We are in this approach passing the final vector by pointer 
*/

void print(vector<int> temp_vector)
{
  for (int i = 0; i < temp_vector.size();i++)
  {
    cout << temp_vector[i]; 
  }
  cout << endl;
}

vector<vector<int>> get_permutations(vector<int>& nums, int index, vector<int> temp_vector, vector<vector<int>>& final_vector)
{
  if (index == nums.size())
  {
    final_vector.push_back(temp_vector);
    return final_vector;
  }
  
  for(int i = 0; i < (temp_vector.size()+1);i++)
  {
    auto it = temp_vector.insert(temp_vector.begin()+i,nums[index]);
    get_permutations(nums,index+1,temp_vector,final_vector);
    temp_vector.erase(it);
  }
  return final_vector;
}
  
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> final_vector;
      vector<int> temp_vector;
        return get_permutations(nums,0,temp_vector,final_vector);
    }
};






/* Second appraoch of not passing the final_vector to the function call */
void print(vector<int> temp_vector)
{
  for (int i = 0; i < temp_vector.size();i++)
  {
    cout << temp_vector[i]; 
  }
  cout << endl;
}

vector<vector<int>> get_permutations(vector<int>& nums, int index, vector<int> temp_vector)
{
  if (index == nums.size())
  {
    vector<vector<int>> final_vector1;
    final_vector1.push_back(temp_vector);
    return final_vector1;
  }
  vector<vector<int>> final_vector;
  for(int i = 0; i < (temp_vector.size()+1);i++)
  {
    auto it = temp_vector.insert(temp_vector.begin()+i,nums[index]);
    vector<vector<int>> temp_ve = get_permutations(nums,index+1,temp_vector);
    final_vector.insert(final_vector.end(),temp_ve.begin(),temp_ve.end());
    temp_vector.erase(it);
  }
  return final_vector;
}
  
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> final_vector;
      vector<int> temp_vector;
        return get_permutations(nums,0,temp_vector);
    }
};
