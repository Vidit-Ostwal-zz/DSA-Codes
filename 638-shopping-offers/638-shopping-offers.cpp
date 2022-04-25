class Solution {
  bool isPossible (vector<int> need, vector<int> offer)
  {
    for (int i = 0; i < need.size(); i++)
      if (offer[i] > need[i])
        return false;
    
    return true;
  } 
  
  vector<int> make_change(vector<int> need, vector<int> temp)
  {
    for (int i = 0; i < need.size(); i++)
      need[i] -= temp[i];
    
    return need;
  }
  
  int all_possible (vector<int> price, vector<int> needs, vector<vector<int>> special, int index)
  {
    if (index == special.size())
    {
      int sum = 0;
      for (int i = 0; i < needs.size(); i++)
        sum += needs[i]*price[i];
      
      return sum;
    }
    
    if (isPossible(needs,special[index]))
    {
      int pre = special[index][special[index].size()-1];
      return min(all_possible(price,needs,special,index+1),pre + all_possible(price,make_change(needs,special[index]),special,index));
    }
    
    return all_possible(price,needs,special,index+1);
  }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return all_possible (price,needs,special,0);
    }
};