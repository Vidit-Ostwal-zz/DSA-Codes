<h2><a href="https://leetcode.com/problems/maximum-erasure-value/">1695. Maximum Erasure Value</a></h2><h3>Medium</h3><hr><div><p>You are given an array of positive integers <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">nums</code> and want to erase a subarray containing&nbsp;<strong>unique elements</strong>. The <strong>score</strong> you get by erasing the subarray is equal to the <strong>sum</strong> of its elements.</p>

<p>Return <em style="color: rgb(203, 218, 200) !important;">the <strong>maximum score</strong> you can get by erasing <strong>exactly one</strong> subarray.</em></p>

<p>An array <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">b</code> is called to be a <span class="tex-font-style-it">subarray</span> of <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">a</code> if it forms a contiguous subsequence of <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">a</code>, that is, if it is equal to <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">a[l],a[l+1],...,a[r]</code> for some <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">(l,r)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;"><strong>Input:</strong> nums = [4,2,4,5,6]
<strong>Output:</strong> 17
<strong>Explanation:</strong> The optimal subarray here is [2,4,5,6].
</pre>

<p><strong>Example 2:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;"><strong>Input:</strong> nums = [5,2,1,2,5,2,1,2,5]
<strong>Output:</strong> 8
<strong>Explanation:</strong> The optimal subarray here is [5,2,1] or [1,2,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">1 &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>