/* Get all the subsets of ['a','b','c'] along with ascii characters */


/* Approach one when we have a final vector passing in all the arguement, along with processed and unprocessed 
A push back will happen when base condition is met 
Remember in this final vector will create itself, therefore, we just need to call recursive function, with differnet manipulated inputs*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<string>> answer)
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

vector<vector<string>> get_subsets(vector<char>& nums, int index, vector<string>temp_answer, vector<vector<string>>& final_answer)
  {
    if (index == nums.size())
    {
      final_answer.push_back(temp_answer);
      return final_answer;
    }
    
    get_subsets(nums,index+1,temp_answer,final_answer);
    
    string ssa(1,nums[index]);
    temp_answer.push_back(ssa);
    get_subsets(nums,index+1,temp_answer,final_answer);
    temp_answer.pop_back();
    
    string ss = to_string(int(nums[index]));
    temp_answer.push_back(ss);
    get_subsets(nums,index+1,temp_answer,final_answer);
    
    return final_answer;
  }
int main()
{
    vector<char> nums = {'a','b','c'};
    vector<string> temp_answer;
    vector<vector<string>> final_answer;
    print(get_subsets(nums,0,temp_answer,final_answer));
}





/*Second Approach when a the final vector is not passed and we need to get different vector and combine them all
Remember you need to return a vector when base condition is met and also need to add differnet vectors.*/

#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<string>> answer)
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

vector<vector<string>> get_subsets(vector<char>& nums, int index, vector<string>temp_answer)
  {
    if (index == nums.size())
    {
      vector<vector<string>> final_answer;
      final_answer.push_back(temp_answer);
      return final_answer;
    }
    
    vector<vector<string>> vector1 = get_subsets(nums,index+1,temp_answer);
    
    string ssa(1,nums[index]);
    temp_answer.push_back(ssa);
    vector<vector<string>> vector2 = get_subsets(nums,index+1,temp_answer);
    temp_answer.pop_back();
    
    string ss = to_string(int(nums[index]));
    temp_answer.push_back(ss);
    vector<vector<string>> vector3 = get_subsets(nums,index+1,temp_answer);
    
    vector1.insert(vector1.end(),vector2.begin(),vector2.end());
    vector1.insert(vector1.end(),vector3.begin(),vector3.end());
    return vector1;
  }
int main()
{
    vector<char> nums = {'a','b','d'};
    vector<string> temp_answer;
    print(get_subsets(nums,0,temp_answer));
}
