class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> contain_one;
      for (int i = 0; i < boxes.length(); i++)
        if (boxes[i] == '1') contain_one.push_back(i);
      
      vector<int> answer;
      
      for (int i = 0; i < boxes.length(); i++)
      {
        int temp = 0; 
        for (int j = 0; j < contain_one.size(); j++)
          temp += abs(i - contain_one[j]);
        
        answer.push_back(temp);
      }
      return answer;
    }
};