class Solution {
  int max_length(vector<string> arr, int index,unordered_map<char,int> mp)
  {
    if (index == arr.size())
      return mp.size();
    
    int option1 = max_length(arr,index+1,mp);
    
    int size = mp.size();
    for (int i = 0; i < arr[index].length(); i++)
      mp[arr[index][i]]++;
    
    
    int option2;
    if (mp.size() - size == arr[index].length())
      option2 = max_length(arr,index+1,mp);
    else
      option2 = INT_MIN;
    
    return max(option1,option2);
  }
public:
    int maxLength(vector<string>& arr) {
      unordered_map<char,int> mp;
        return max_length(arr,0,mp);
    }
};