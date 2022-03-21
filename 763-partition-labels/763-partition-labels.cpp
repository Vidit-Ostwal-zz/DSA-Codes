class Solution {
  /*At most in one part, what more important, the last occuring index of the same 
This is a string always you can use a 26 size vector*/
  vector<int> Approach2(string s)
  {
    map<char,int>mp;
    
    for (int i = 0; i < s.length(); i++)
      mp[s[i]]++;
    
    map<char,bool> mp1;
    
    int answer = 0;
    vector<int> temp;
    for (int i = 0; i < s.length(); i++)
    {
      mp[s[i]]--;
      
      if (mp[s[i]])
        mp1[s[i]] = true;
      else 
        if (mp1.find(s[i]) != mp1.end())
        {
          mp1.erase(s[i]);
        }
      
      if (mp[s[i]] == 0 && mp1.size() == 0)
      {
        temp.push_back(i-answer+1);
        answer = i+1;
      }
    }
    return temp;
  }
  
  
public:
    vector<int> partitionLabels(string s) {
      /*We got Alpha which have the last occuring indexes of all*/ 
      
      return Approach2( s);
      vector<int> alpha(26,0);
      
      for (int i =0; i < s.length(); i++)
        alpha[s[i] - 'a'] = i;
      
     
      /*Now we will iterate and as we iterate we keep on updating j variable such that j will represent the 
      max of all the visited alpha bet last occurence .And as we get taht i  == j , at any moment,
This will reprsent the minimum length, so that all the aphabets before that have apperaed in it only and no further occurences are there for the same*/
      
      int j = 0;
      int anchor = 0;
      vector<int> answer;
      
      
      for (int i= 0; i < s.length(); i++)
      {
        j = max(j,alpha[s[i] - 'a']);
        cout << j << endl;
        if (i == j)
        {
          answer.push_back(j - anchor + 1);
          anchor = i + 1;
        }
      }
      return answer;
    }
};