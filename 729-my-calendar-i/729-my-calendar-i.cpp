class MyCalendar {
  vector<pair<int,int>> vect;
  
  int Binary_Search(int key)
  {
    int st = 0;
    int ed = vect.size()-1;
    int answer = -1;
    while (st <= ed)
    {
      int mid = st + (ed - st )/2;
      
      if (vect[mid].first >  key)
        ed = mid - 1;
      else 
      {
        answer = mid;
        st = mid + 1;
      }
    }
    return answer;
  }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
      
      if (vect.size() == 0)
      {
        vect.push_back(make_pair(start,end));
        return true;
      }
      int lower_index = Binary_Search(start);
      
      if (lower_index != -1)
      {
        if (vect[lower_index].second > start)
          return false;
      }
      lower_index++;
      
      if (lower_index <  vect.size() && end > vect[lower_index].first)
        return false;
      
      vect.insert(vect.begin() + lower_index,make_pair(start,end));
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */