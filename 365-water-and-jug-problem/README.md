<h2><a href="https://leetcode.com/problems/water-and-jug-problem/">365. Water and Jug Problem</a></h2><h3>Medium</h3><hr><div><p>You are given two jugs with capacities <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">jug1Capacity</code> and <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">jug2Capacity</code> liters. There is an infinite amount of water supply available. Determine whether it is possible to measure exactly <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">targetCapacity</code> liters using these two jugs.</p>

<p>If <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">targetCapacity</code> liters of water are measurable, you must have <code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">targetCapacity</code> liters of water contained <strong>within one or both buckets</strong> by the end.</p>

<p>Operations allowed:</p>

<ul>
	<li>Fill any of the jugs with water.</li>
	<li>Empty any of the jugs.</li>
	<li>Pour water from one jug into another till the other jug is completely full, or the first jug itself is empty.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 186, 156) !important;"><strong>Input:</strong> jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4
<strong>Output:</strong> true
<strong>Explanation:</strong> The famous <a href="https://www.youtube.com/watch?v=BVtQNK_ZUJg&amp;ab_channel=notnek01" target="_blank" style="transition-property: -border-bottom-color !important; --link-color:rgb(143, 176, 140) !important; --link-color-hover:rgb(160, 188, 158) !important; --link-color-active:rgb(143, 176, 140) !important; --visited-color:rgb(245, 187, 71) !important; --visited-color-hover:rgb(247, 198, 100) !important; --visited-color-active:rgb(245, 187, 71) !important; border-top-color: rgb(124, 140, 100) !important; border-right-color: rgb(124, 140, 100) !important; border-left-color: rgb(124, 140, 100) !important;">Die Hard</a> example 
</pre>

<p><strong>Example 2:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 186, 156) !important;"><strong>Input:</strong> jug1Capacity = 2, jug2Capacity = 6, targetCapacity = 5
<strong>Output:</strong> false
</pre>

<p><strong>Example 3:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 186, 156) !important;"><strong>Input:</strong> jug1Capacity = 1, jug2Capacity = 2, targetCapacity = 3
<strong>Output:</strong> true
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(160, 185, 156) !important;">1 &lt;= jug1Capacity, jug2Capacity, targetCapacity &lt;= 10<sup>6</sup></code></li>
</ul>
</div>