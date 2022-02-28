class Solution {
  int get_f(string s)
  {
    sort(s.begin(),s.end());
    int i = 0;
    char c = s[0];
    while (i < s.length() && c == s[i])
      i++;
    return i;
  }
  
  /*Classical Binary Search return index if found, returns -1 if not found*/
int Binary_Search(vector<int> nums, int st, int ed,int target)
 {
  while (st <= ed)
  {
   int mid = st + (ed - st) / 2;
    
   if (nums[mid] == target)
    st = mid + 1;
    
   if (nums[mid] > target)
    ed = mid - 1;
    
   else
    st = mid + 1;
  }
  return st+1;
}
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> temp;
      for (int i = 0; i < words.size(); i++)
        temp.push_back(get_f(words[i]));
      
      sort(temp.begin(),temp.end());
      
      vector<int> answer;
      for (int i = 0; i < queries.size(); i++)
        answer.push_back(temp.size() - Binary_Search(temp,0,temp.size()-1,get_f(queries[i])) + 1);
      
      return answer;
    }
};