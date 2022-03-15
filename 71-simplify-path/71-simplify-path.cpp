class Solution {
public:
    string simplifyPath(string path) {
        stack<string> temp;
      
      for (int i = 0; i < path.length(); i++)
      {
        if (path[i] != '/')
        {
          string temp_string = "";
          
          if (path[i] == '.')
          {
            int count = 0;
            
            while ( i <  path.length() && path[i] != '/')
            {
              temp_string += path[i];
              count++;
              i++;
            }
            
            if (count == 2 && temp_string.compare("..") == 0)
              if (!temp.empty())
                temp.pop();
            
            if (count > 2)
            {
              temp.push(temp_string);
            }
          }
          
          else
          {
            while (i <  path.length() && path[i] != '/')
            {
              temp_string += path[i];
              i++;
            }
            temp.push(temp_string);
          }
          cout << temp_string << endl;
        }
      }
      cout << temp.size() << endl;
      string answer = "";
      
      if (temp.size() == 0)
        return "/";
      
      while (!temp.empty())
      {
        answer = temp.top() + answer;
        answer = '/' + answer;
        temp.pop();
      }
      return answer;
    }
};