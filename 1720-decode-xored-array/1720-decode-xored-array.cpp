class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> answer;
      answer.push_back(first);
      
      for (int i = 0; i < encoded.size(); i++)
        answer.push_back(answer[i]^encoded[i]);
      
      return answer;
    }
};