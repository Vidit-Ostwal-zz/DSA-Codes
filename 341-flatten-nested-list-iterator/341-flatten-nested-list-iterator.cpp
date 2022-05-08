/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
  vector<int> hold;
  int p = 0;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
  
    void flatten(vector<NestedInteger> temp)
    {
      for (int i = 0; i < temp.size(); i++)
      {
        if (temp[i].isInteger())
          hold.push_back(temp[i].getInteger());
        else
          flatten(temp[i].getList());
      }
    }
  
  
    int next() {
        return hold[p++];
    }
    
    bool hasNext() {
        return p < hold.size();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */