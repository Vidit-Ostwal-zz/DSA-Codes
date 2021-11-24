/* Skip a particular sub stirng say apple without passing the processed vetor in it.*/

vector<char> printskipapple2(string characters,int index)
{
  if (index == characters.length())
  {
    return {};
  }
  
  vector <char> answer;
  vector<char> answer1;
  if (characters.find("apple",index) == index)
  {
    answer1 = printskipapple2(characters,index+5);
  }
  else
  {
    answer.push_back(characters[index]);
    answer1 = printskipapple2(characters,index+1);
  }
  answer.insert(answer.end(),answer1.begin(),answer1.end());
  return answer;
  
}

int main()
{
    vector <char> answer1  = printskipapple2("bssdapplevidappleitapple",0);
    print(answer1);
}
