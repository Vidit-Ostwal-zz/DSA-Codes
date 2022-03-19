<h2><a href="https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/">1493. Longest Subarray of 1's After Deleting One Element</a></h2><h3>Medium</h3><hr><div><p>Given a binary array <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">nums</code>, you should delete one element from it.</p>

<p>Return <em style="color: rgb(203, 218, 200) !important;">the size of the longest non-empty subarray containing only </em><code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">1</code><em style="color: rgb(203, 218, 200) !important;">'s in the resulting array</em>. Return <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">0</code> if there is no such subarray.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 186, 156) !important;"><strong>Input:</strong> nums = [1,1,0,1]
<strong>Output:</strong> 3
<strong>Explanation:</strong> After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
</pre>

<p><strong>Example 2:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 186, 156) !important;"><strong>Input:</strong> nums = [0,1,1,1,0,1,1,0,1]
<strong>Output:</strong> 5
<strong>Explanation:</strong> After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
</pre>

<p><strong>Example 3:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 186, 156) !important;"><strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You must delete one element.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">nums[i]</code> is either <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">0</code> or <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">1</code>.</li>
</ul>
</div>