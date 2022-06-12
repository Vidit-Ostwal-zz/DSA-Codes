class Solution {
//   int isPossible(vector<int> cookies, int k)
//   {
//     int partition = 1;
//     int sum = 0;
//     for (int i = 0; i < cookies.size(); i++)
//     {
//       sum += cookies[i];
      
//       if (sum > k)
//       {
//         partition++;
//         sum = cookies[i];
//       }
//     }
//     return partition;
//   }
  
  int try_all (vector<int> &cookies, int &k, int index, vector<int> temp)
  {
    if (index == cookies.size())
    {
      int maxi = INT_MIN;
      
      for (int i = 0; i < temp.size(); i++)
      {
        maxi = max(maxi,temp[i]);
      }
      return maxi;
    }
    
    int value = cookies[index];
    int maxi = INT_MAX;
    for (int i = 0; i < k; i++)
    {
      temp[i] += value;
      maxi = min(maxi,try_all(cookies,k,index+1,temp));
      temp[i] -= value;
      
      // if (temp[i] == 0)
      // {
      //   break;
      // }
    }
    return maxi;
  }
public:
    int distributeCookies(vector<int>& cookies, int k) {
      
      if (cookies.size() == k)
      {
        sort(cookies.begin(),cookies.end());
        return cookies[k-1];
      }
      // unordered_map<int,int> map1;
      vector<int> temp(k,0);
      return try_all(cookies,k,0,temp);
    }
};