<h2><a href="https://leetcode.com/problems/implement-strstr/">28. Implement strStr()</a></h2><h3>Easy</h3><hr><div><p>Implement <a href="http://www.cplusplus.com/reference/cstring/strstr/" target="_blank" style="transition-property: -border-bottom-color !important; --link-color:rgb(161, 178, 190) !important; --link-color-hover:rgb(180, 193, 203) !important; --link-color-active:rgb(158, 175, 188) !important; --visited-color:rgb(160, 117, 234) !important; --visited-color-hover:rgb(179, 144, 238) !important; --visited-color-active:rgb(157, 113, 234) !important; border-top-color: rgb(92, 119, 133) !important; border-right-color: rgb(92, 119, 133) !important; border-left-color: rgb(92, 119, 133) !important;">strStr()</a>.</p>

<p>Return the index of the first occurrence of needle in haystack, or <code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">-1</code> if <code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">needle</code> is not part of <code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">haystack</code>.</p>

<p><strong>Clarification:</strong></p>

<p>What should we return when <code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">needle</code> is an empty string? This is a great question to ask during an interview.</p>

<p>For the purpose of this problem, we will return 0 when <code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">needle</code> is an empty string. This is consistent to C's&nbsp;<a href="http://www.cplusplus.com/reference/cstring/strstr/" target="_blank" style="transition-property: -border-bottom-color !important; --link-color:rgb(161, 178, 190) !important; --link-color-hover:rgb(180, 193, 203) !important; --link-color-active:rgb(158, 175, 188) !important; --visited-color:rgb(160, 117, 234) !important; --visited-color-hover:rgb(179, 144, 238) !important; --visited-color-active:rgb(157, 113, 234) !important; border-top-color: rgb(92, 119, 133) !important; border-right-color: rgb(92, 119, 133) !important; border-left-color: rgb(92, 119, 133) !important;">strstr()</a> and Java's&nbsp;<a href="https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf(java.lang.String)" target="_blank" style="transition-property: -border-bottom-color !important; --link-color:rgb(161, 178, 190) !important; --link-color-hover:rgb(180, 193, 203) !important; --link-color-active:rgb(158, 175, 188) !important; --visited-color:rgb(160, 117, 234) !important; --visited-color-hover:rgb(179, 144, 238) !important; --visited-color-active:rgb(157, 113, 234) !important; border-top-color: rgb(92, 119, 133) !important; border-right-color: rgb(92, 119, 133) !important; border-left-color: rgb(92, 119, 133) !important;">indexOf()</a>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre style="background-color: rgb(20, 28, 32) !important; color: rgb(182, 198, 206) !important;"><strong>Input:</strong> haystack = "hello", needle = "ll"
<strong>Output:</strong> 2
</pre><p><strong>Example 2:</strong></p>
<pre style="background-color: rgb(20, 28, 32) !important; color: rgb(182, 198, 206) !important;"><strong>Input:</strong> haystack = "aaaaa", needle = "bba"
<strong>Output:</strong> -1
</pre><p><strong>Example 3:</strong></p>
<pre style="background-color: rgb(20, 28, 32) !important; color: rgb(182, 198, 206) !important;"><strong>Input:</strong> haystack = "", needle = ""
<strong>Output:</strong> 0
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">0 &lt;= haystack.length, needle.length &lt;= 5 * 10<sup>4</sup></code></li>
	<li><code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">haystack</code> and&nbsp;<code style="background-color: rgb(20, 28, 32) !important; color: rgb(183, 198, 205) !important;">needle</code> consist of only lower-case English characters.</li>
</ul>
</div>