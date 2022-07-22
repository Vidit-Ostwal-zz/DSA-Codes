class Solution {
  static bool srt(vector<int> A, vector<int> B)
  {
    if (A[0] != B[0])
    {
      return A[0] > B[0];
    }
    return A[1] <  B[1];
  }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),srt);
      
      vector<vector<int>> answer;
      
      for (auto &p: people)
        answer.insert(answer.begin()+p[1],p);
      
      return answer;
    }
};