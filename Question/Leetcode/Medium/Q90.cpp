/* Iterative Solution When duplicate elements are present, first sorting is done, because solution works only when duplicate element are together
MoreOver, Thinking of iterative is to copy the final vector in one, iterate over the copied one and add element to it, and add those to final vector
Start pointer is made to have the index becasue when a duplicate element is present we only need to add the new element in the new final vector  - prev temp vector*/



class Solution {
public:
void print(vector<vector<int>> answer)
{
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer[i].size();j++)
        {
            cout << answer[i][j] ;
        }
        cout << endl;
    }
}

vector<vector<int>> get_subsets_iterative(vector<int> str)
{
    vector<vector<int>> final_vector = {{}};
    int temp_vector_size;
    for (int i = 0 ; i < str.size(); i++)
    {
      
      vector<vector<int>> temp_vector(final_vector.begin(),final_vector.end());
      int start = 0;
      
      if (i > 0 && str[i]  ==  str[i-1])
      {
        start = temp_vector_size;
      }
      
      for(int j = start; j < temp_vector.size();j++)
      {
            vector<int> temp_string = temp_vector[j];
            temp_string.push_back(str[i]);
            final_vector.push_back(temp_string);
      }
      print(final_vector);
      temp_vector_size = temp_vector.size();
      
        
    }
    return final_vector; 
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
      sort(nums.begin(),nums.end());
        return get_subsets_iterative(nums);
    }
};
