<h2><a href="https://leetcode.com/problems/vowels-of-all-substrings/">2063. Vowels of All Substrings</a></h2><h3>Medium</h3><hr><div><p>Given a string <code style="">word</code>, return <em style="">the <strong>sum of the number of vowels</strong> (</em><code style="">'a'</code>, <code style="">'e'</code><em style="">,</em> <code style="">'i'</code><em style="">,</em> <code style="">'o'</code><em style="">, and</em> <code style="">'u'</code><em style="">)</em> <em style="">in every substring of </em><code style="">word</code>.</p>

<p>A <strong>substring</strong> is a contiguous (non-empty) sequence of characters within a string.</p>

<p><strong>Note:</strong> Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style=""><strong>Input:</strong> word = "aba"
<strong>Output:</strong> 6
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
</pre>

<p><strong>Example 2:</strong></p>

<pre style=""><strong>Input:</strong> word = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
All possible substrings are: "a", "ab", "abc", "b", "bc", and "c".
- "a", "ab", and "abc" have 1 vowel each
- "b", "bc", and "c" have 0 vowels each
Hence, the total sum of vowels = 1 + 1 + 1 + 0 + 0 + 0 = 3.
</pre>

<p><strong>Example 3:</strong></p>

<pre style=""><strong>Input:</strong> word = "ltcd"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There are no vowels in any substring of "ltcd".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="">1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code style="">word</code> consists of lowercase English letters.</li>
</ul>
</div>