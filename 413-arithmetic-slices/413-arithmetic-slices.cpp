class Solution {
  bool check(vector<int> nums, int end_index, int start_index)
  {
    vector<int> temp(nums.begin() + start_index, nums.begin() +end_index + 1);
    
    for (int i = 2 ; i < temp.size(); i++)
    {
      if (temp[i] - temp[i-1] != temp[1] - temp[0])
        return false;
    }
    return true;
  }
  
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      if (nums.size() <= 2)
        return 0;
      
      vector<vector<bool>> final_answer;
      int i = 0;
      int count = 0;
      vector<bool> temp; 
      
      while (i < nums.size()-2)
      {
        temp.push_back(check(nums,i+2,i));
        cout << temp[temp.size() - 1] << "   " ;
        if (temp[temp.size()-1])
          count++;
        
        i++;
      }
      
      cout << endl;
      final_answer.push_back(temp);
      int size = final_answer[final_answer.size()-1].size();
      
      while (size != 1)
      {
        vector<bool> temp;
        vector<bool> check = final_answer[final_answer.size()-1];
        int index = 1;
        while (index < size)
        {
          temp.push_back(check[index] && check[index-1]);
          if (temp[temp.size()-1])
            count++;
          index++;
        }
        final_answer.push_back(temp);
        size = final_answer[final_answer.size()-1].size();
      }
      return count;
    }
};