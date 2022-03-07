How to pick the middle element?
Choices we have
1> Random Element
2> Corner Element
3> Pick the middle element
Recursion Relation
T(N) = T(K) + T(N-K-1) + O(N)
Worst Case:
Pivot Element -> Smallest or Largest Element
K = 0; T(N) = T(N-1) + O(N)
Time Complexity >O(N^2)
Best Case Middle Element
K = N/2;
T(N) = 2*T(N/2) + O(N)
Like Merge Sort (N*LogN)
Not Stable
In-Place
Merge Sort is preferred in Linked List due to memory allocaion not being continous
Hybrid Sorting Algortihm
Merge Sort + Insertion Sort (Works very well with patially sorted array)