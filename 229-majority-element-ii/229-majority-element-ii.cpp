class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int answer1 = -1;
      int answer2 = -1;
      
      int count1 = 0;
      int count2 = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] == answer1)
          count1++;
        else if (nums[i] == answer2)
          count2++;
        else if (count1 == 0)
        {
          answer1 = nums[i];
          count1++;
        }
        else if (count2 == 0)
        {
          answer2 = nums[i];
          count2++;
        }
        else
        {
          count1--;
          count2--;
        }
      }
      
      int check1 = 0;
      int check2 = 0;
      
      for (int i = 0; i < nums.size(); i++)
      {
        if (nums[i] == answer1)
          check1++;
        else if (nums[i] == answer2)
          check2++;
      }
      
      vector<int> answer;
      if (check1 > nums.size()/3)
        answer.push_back(answer1);
      if (check2 > nums.size()/3)
        answer.push_back(answer2);
      
      return answer;
    }
};