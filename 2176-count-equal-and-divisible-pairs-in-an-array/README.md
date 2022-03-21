<h2><a href="https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/">2176. Count Equal and Divisible Pairs in an Array</a></h2><h3>Easy</h3><hr><div>Given a <strong>0-indexed</strong> integer array <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">nums</code> of length <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">n</code> and an integer <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">k</code>, return <em style="color: rgb(255, 255, 255) !important;">the <strong>number of pairs</strong></em> <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">(i, j)</code> <em style="color: rgb(255, 255, 255) !important;">where</em> <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">0 &lt;= i &lt; j &lt; n</code>, <em style="color: rgb(255, 255, 255) !important;">such that</em> <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">nums[i] == nums[j]</code> <em style="color: rgb(255, 255, 255) !important;">and</em> <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">(i * j)</code> <em style="color: rgb(255, 255, 255) !important;">is divisible by</em> <code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">k</code>.
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 224) !important;"><strong>Input:</strong> nums = [3,1,2,2,2,1,3], k = 2
<strong>Output:</strong> 4
<strong>Explanation:</strong>
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 224) !important;"><strong>Input:</strong> nums = [1,2,3,4], k = 1
<strong>Output:</strong> 0
<strong>Explanation:</strong> Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">1 &lt;= nums.length &lt;= 100</code></li>
	<li><code style="background-color: rgb(19, 27, 31) !important; color: rgb(209, 219, 223) !important;">1 &lt;= nums[i], k &lt;= 100</code></li>
</ul>
</div>