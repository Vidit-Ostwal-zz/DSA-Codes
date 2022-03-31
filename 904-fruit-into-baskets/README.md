<h2><a href="https://leetcode.com/problems/fruit-into-baskets/">904. Fruit Into Baskets</a></h2><h3>Medium</h3><hr><div><p>You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array <code style="">fruits</code> where <code style="">fruits[i]</code> is the <strong style="">type</strong> of fruit the <code style="">i<sup style="">th</sup></code> tree produces.</p>

<p>You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:</p>

<ul>
	<li>You only have <strong style="">two</strong> baskets, and each basket can only hold a <strong style="">single type</strong> of fruit. There is no limit on the amount of fruit each basket can hold.</li>
	<li>Starting from any tree of your choice, you must pick <strong style="">exactly one fruit</strong> from <strong style="">every</strong> tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.</li>
	<li style="">Once you reach a tree with fruit that cannot fit in your baskets, you must stop.</li>
</ul>

<p style="">Given the integer array <code style="">fruits</code>, return <em style="">the <strong>maximum</strong> number of fruits you can pick</em>.</p>

<p style="">&nbsp;</p>
<p style=""><strong>Example 1:</strong></p>

<pre style=""><strong style="">Input:</strong> fruits = [<u style="">1,2,1</u>]
<strong style="">Output:</strong> 3
<strong style="">Explanation:</strong> We can pick from all 3 trees.
</pre>

<p style=""><strong>Example 2:</strong></p>

<pre style=""><strong style="">Input:</strong> fruits = [0,<u style="">1,2,2</u>]
<strong style="">Output:</strong> 3
<strong style="">Explanation:</strong> We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
</pre>

<p style=""><strong>Example 3:</strong></p>

<pre style=""><strong style="">Input:</strong> fruits = [1,<u style="">2,3,2,2</u>]
<strong style="">Output:</strong> 4
<strong style="">Explanation:</strong> We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
</pre>

<p style="">&nbsp;</p>
<p style=""><strong>Constraints:</strong></p>

<ul>
	<li style=""><code style="">1 &lt;= fruits.length &lt;= 10<sup style="">5</sup></code></li>
	<li style=""><code style="">0 &lt;= fruits[i] &lt; fruits.length</code></li>
</ul>
</div>