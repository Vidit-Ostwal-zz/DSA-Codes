class Solution {
  vector<string> rightword(string word)
  {
    char chary = '$';
    
    vector<string> temp;
    int j = 0;
    
    for (int i = 0; i < word.length(); i++)
    {
      if (word[i] == chary)
      {
        if (i != j)
        {
          temp.push_back(word.substr(j,i-j));
          j = i+1;
        }
      }
    }
    
    for (int i = 0; i < temp.size(); i++)
      cout << temp[i] << endl;
    
    return temp;
  }
  
//   string round(double var)
// {
//     // 37.66666 * 100 =3766.66
//     // 3766.66 + .5 =3767.16    for rounding off value
//     // then type cast to int so value is 3767
//     // then divided by 100 so the value converted into 37.67
//     float value = (int)(var * 100 + .5);
//     cout << "Value     " <<  value << endl;
//     return to_string((float)value / 100);
// }
 
public:
    string discountPrices(string sentence, int discount) {
      cout << setprecision(20);
      discount = 100-discount;
         istringstream ss(sentence);
      string word;
      string answer = "";
      while (ss >> word)
      {
        if (word[0] != '$')
          answer += word;
        
        else
        {
          int count = 0;
          for (int i = 1; i < word.length(); i++)
            if (word[i] == '$' || (word[i] >= 'a' && word[i] <= 'z'))
              count++;
          
          
          if (count || word.length() == 1)
            answer += word;
          
          else
          {
            answer += "$";
            string temp = word.substr(1);
            long double tt = (stod(temp)*(double)discount);
            // cout << "tt    " <<  tt << endl;
            long double t = tt/(double)100;
            // cout << "t    " << t << endl;
            
            string oo = to_string(t);
            // answer += oo;
            answer += oo.substr(0,oo.length()-4);
          }
        }
        
        answer +=  ' ';
        // cout << answer << endl;
      }
      
      return answer.substr(0,answer.length()-1);
    }
};