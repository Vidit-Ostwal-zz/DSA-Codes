**Question Description**
--
Given a vector, with the some integer, in it, we start increasing the values in the vector in some ranges, the ranges can overlap and the amount with 
which one range varies the vector is also differnet and given, Basically when the ranges, have effect on other thing and we can think of each range independently and have 
no work with each other.

**Approach 1** 
--
We can Iterate over the range and then again iterate in a particular range and increment each indexes individually.

**Approach 2**
--
The Better apprach, make two vector, start and end, 
- Which will store the starting indexes of each range and the other one will keep track of each ending indexes,
- And the **Prefix Sum** Approach, now we iterate over each indexes , in the dimension and at the starting of each indexes with the vectors and global note of their indexes,
- We can determine whether this or a different range have started, and update the global variable with the starting of that range, similarly with each index we can tell
when a partiular range will end,
- And therefore, the prefix sum can help wihtout keeping or need of iterating over ech range index, 
- The **prefix sum** can direclty tell the effect of all the queries, on that particular index and this needs to be remembered



**Question Description**
--
Now again, given some ranges, we need to determine a particular range with respect to this particular range, be it distance of some kind or so,
In this cases Binary Search will be very help ful to determine the index of the range vector to determine which range index this particular index belongs too.
Prefix Sum is used alongside for some operation varying directly with respect to type of question.
