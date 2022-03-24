<h2><a href="https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/">1130. Minimum Cost Tree From Leaf Values</a></h2><h3>Medium</h3><hr><div><p>Given an array <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">arr</code> of positive integers, consider all binary trees such that:</p>

<ul>
	<li>Each node has either <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">0</code> or <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">2</code> children;</li>
	<li>The values of <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">arr</code> correspond to the values of each <strong>leaf</strong> in an in-order traversal of the tree.</li>
	<li>The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.</li>
</ul>

<p>Among all possible binary trees considered, return <em style="color: rgb(255, 255, 255) !important;">the smallest possible sum of the values of each non-leaf node</em>. It is guaranteed this sum fits into a <strong>32-bit</strong> integer.</p>

<p>A node is a <strong>leaf</strong> if and only if it has zero children.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/tree1.jpg" style="width: 500px; height: 169px; filter: saturate(0.3);" transition="filter">
<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 218) !important;"><strong>Input:</strong> arr = [6,2,4]
<strong>Output:</strong> 32
<strong>Explanation:</strong> There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
</pre>

<p><strong>Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/tree2.jpg" style="width: 224px; height: 145px; filter: saturate(0.3);" transition="filter">
<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 218) !important;"><strong>Input:</strong> arr = [4,11]
<strong>Output:</strong> 44
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">2 &lt;= arr.length &lt;= 40</code></li>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">1 &lt;= arr[i] &lt;= 15</code></li>
	<li>It is guaranteed that the answer fits into a <strong>32-bit</strong> signed integer (i.e., it is less than 2<sup>31</sup>).</li>
</ul>
</div>