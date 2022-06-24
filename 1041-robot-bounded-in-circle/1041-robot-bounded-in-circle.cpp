class Solution {
  int Direction_index = 1;
  int x = 0;
  int y = 0;
  // 0-West 1-North 2-East 3-South;
  
  
public:
    bool isRobotBounded(string instructions) {
        for (int i = 0; i < instructions.length(); i++)
        {
          if (instructions[i] == 'G')
          {
            if (Direction_index == 0)
              x--;
            else if (Direction_index == 1)
              y++;
            else if (Direction_index == 2)
              x++;
            else
              y--;
          }
          else if (instructions[i] == 'L')
            Direction_index--;
          else
            Direction_index++;
          
          Direction_index = (Direction_index+4)%4;
        }
      
      if (x == 0 && y == 0)
        return true;
      else if (Direction_index != 1)
        return true;
      return false;
    }
};