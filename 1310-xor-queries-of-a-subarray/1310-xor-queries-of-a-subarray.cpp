class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix;
      
      for (int i=  0; i < arr.size(); i++)
        prefix.push_back((i > 0) ? prefix[i-1] ^ arr[i] : arr[i]);
      
      
      vector<int> answer;
      for (int i = 0; i < queries.size(); i++)
      {
        int Left = (queries[i][0] > 0) ? prefix[queries[i][0]-1] : 0;
        int Right = prefix[queries[i][1]];
        answer.push_back(Left^Right);
      }
      return answer;
    }
};