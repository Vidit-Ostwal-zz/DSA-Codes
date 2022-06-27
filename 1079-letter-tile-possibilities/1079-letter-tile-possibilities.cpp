class Solution {
  set<string> final_set;
  void All_Possible(int index, string tiles, string temp)
  {
    if (index >= tiles.length())
    {
      if (temp.length())
        final_set.insert(temp);
      return;
    }
    
    
    for (int i = 0; i < temp.length(); i++)
    {
      string pre = temp.substr(0,i);
      string next = temp.substr(i);
      
      string k = pre + tiles[index] + next;
      
      All_Possible(index+1,tiles,k);
    }
    
    All_Possible(index+1,tiles,temp);
    All_Possible(index+1,tiles,temp + tiles[index]);
    return;
  }
public:
    int numTilePossibilities(string tiles) {
       All_Possible(0,tiles,"");
      return final_set.size();
    }
};