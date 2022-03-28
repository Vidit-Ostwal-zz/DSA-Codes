<h2><a href="https://leetcode.com/problems/super-ugly-number/">313. Super Ugly Number</a></h2><h3>Medium</h3><hr><div><p>A <strong>super ugly number</strong> is a positive integer whose prime factors are in the array <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">primes</code>.</p>

<p>Given an integer <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">n</code> and an array of integers <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">primes</code>, return <em style="color: rgb(255, 255, 255) !important;">the</em> <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">n<sup>th</sup></code> <em style="color: rgb(255, 255, 255) !important;"><strong>super ugly number</strong></em>.</p>

<p>The <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">n<sup>th</sup></code> <strong>super ugly number</strong> is <strong>guaranteed</strong> to fit in a <strong>32-bit</strong> signed integer.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 218) !important;"><strong>Input:</strong> n = 12, primes = [2,7,13,19]
<strong>Output:</strong> 32
<strong>Explanation:</strong> [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
</pre>

<p><strong>Example 2:</strong></p>

<pre style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 218) !important;"><strong>Input:</strong> n = 1, primes = [2,3,5]
<strong>Output:</strong> 1
<strong>Explanation:</strong> 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">1 &lt;= n &lt;= 10<sup>6</sup></code></li>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">1 &lt;= primes.length &lt;= 100</code></li>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">2 &lt;= primes[i] &lt;= 1000</code></li>
	<li><code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">primes[i]</code> is <strong>guaranteed</strong> to be a prime number.</li>
	<li>All the values of <code style="background-color: rgb(14, 19, 22) !important; color: rgb(200, 212, 217) !important;">primes</code> are <strong>unique</strong> and sorted in <strong>ascending order</strong>.</li>
</ul>
</div>