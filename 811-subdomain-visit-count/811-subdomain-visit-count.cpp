class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
      
      unordered_map<string,int> map;
        for (int j = 0; j < cpdomains.size(); j++)
        {
          string temp(cpdomains[j].begin(),cpdomains[j].end());
          
          vector<string> vec1;
          
          int i = 0;
          string f = "";
          while (temp[i] != ' ')
          {
            f += temp[i];
             i++;
          }
          vec1.push_back(f);
          i++;
          
          while (i < temp.length())
          {
            string tempo = "";
            while (i < temp.length() && temp[i] != '.')
            {
              tempo += temp[i];
              i++;
            }
            vec1.push_back(tempo);
            i++;
          }
          
          int co = stoi(vec1[0]);
          string gg = "";
          for (int i = vec1.size()-1; i > 0; i--)
          {
            if (gg.length() == 0)
              gg = vec1[i] + gg;
            else
              gg = vec1[i] + '.' + gg;
            
            map[gg] += co;
          }
        }
      
      vector<string> answer;
      
      auto it = map.begin();
      
      while (it != map.end())
      {
        string f = it -> first;
        f = to_string(it->second) + " " + f;
        answer.push_back(f);
        it++;
      }
      return answer;
    }
};