<h2><a href="https://leetcode.com/problems/course-schedule-ii/">210. Course Schedule II</a></h2><h3>Medium</h3><hr><div><p>There are a total of <code style="">numCourses</code> courses you have to take, labeled from <code style="">0</code> to <code style="">numCourses - 1</code>. You are given an array <code style="">prerequisites</code> where <code style="">prerequisites[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> indicates that you <strong>must</strong> take course <code style="">b<sub>i</sub></code> first if you want to take course <code style="">a<sub>i</sub></code>.</p>

<ul>
	<li>For example, the pair <code style="">[0, 1]</code>, indicates that to take course <code style="">0</code> you have to first take course <code style="">1</code>.</li>
</ul>

<p>Return <em style="">the ordering of courses you should take to finish all courses</em>. If there are many valid answers, return <strong>any</strong> of them. If it is impossible to finish all courses, return <strong>an empty array</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre style=""><strong>Input:</strong> numCourses = 2, prerequisites = [[1,0]]
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
</pre>

<p><strong>Example 2:</strong></p>

<pre style=""><strong>Input:</strong> numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
<strong>Output:</strong> [0,2,1,3]
<strong>Explanation:</strong> There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
</pre>

<p><strong>Example 3:</strong></p>

<pre style=""><strong>Input:</strong> numCourses = 1, prerequisites = []
<strong>Output:</strong> [0]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code style="">1 &lt;= numCourses &lt;= 2000</code></li>
	<li><code style="">0 &lt;= prerequisites.length &lt;= numCourses * (numCourses - 1)</code></li>
	<li><code style="">prerequisites[i].length == 2</code></li>
	<li><code style="">0 &lt;= a<sub>i</sub>, b<sub>i</sub> &lt; numCourses</code></li>
	<li><code style="">a<sub>i</sub> != b<sub>i</sub></code></li>
	<li>All the pairs <code style="">[a<sub>i</sub>, b<sub>i</sub>]</code> are <strong>distinct</strong>.</li>
</ul>
</div>