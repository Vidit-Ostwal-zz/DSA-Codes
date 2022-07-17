class Solution {
  void find_answer(int len, vector<pair<int,int>> vect, vector<int>&answer, vector<string>&nums)
  {
    vector<pair<string,int>> temp;
    
    for (int i = 0; i < nums.size(); i++)
    {
      temp.push_back(make_pair(nums[i].substr(nums[i].length()-len),i));
    }
    
    sort(temp.begin(),temp.end());
    
    for (int i = 0; i < vect.size(); i++)
    {
      int rank = vect[i].first - 1;
      int index = vect[i].second;
      
      answer[index] = temp[rank].second;
    }
  }
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
      map<int,vector<pair<int,int>>> map1;
      
      for (int i = 0; i < queries.size(); i++)
      {
        map1[queries[i][1]].push_back(make_pair(queries[i][0],i));
      }
      vector<int> answer(queries.size(),0);
      
      auto it = map1.begin();
      
      while (it != map1.end())
      {
        find_answer(it->first,it->second,answer,nums);
        it++;
      }
      return answer;
    }
};