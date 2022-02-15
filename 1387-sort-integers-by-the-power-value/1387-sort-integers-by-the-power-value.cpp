class Solution {
  int get_power (int n)
  {
    int count = 0;
    while (n != 1)
    {
      if (n % 2 == 0) n = n/2;
      else n = n*3 + 1;
      
      count++;
    }
    return count;
  }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> answer;
      
      for (int i = lo;i <= hi; i++)
      {
        answer.push_back(make_pair(get_power(i),i));
        cout << answer[answer.size()-1].first << "   " <<  answer[answer.size()-1].second << endl;
      }
      
      sort(answer.begin(),answer.end());
      
      
      
      return answer[k-1].second;
    }
};