# 9. Minimum Swaps
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given two&nbsp;array<strong>&nbsp;A[] </strong>and<strong> B[] </strong>of same size<strong>&nbsp;N</strong>.&nbsp;<br>
In one swap, You can swap A[i] with B[i]. The task is to calculate the minimum number of swaps requeired to make&nbsp;all elements of the array A[] equal, or make all elements of the array B[] equal.&nbsp;<br>
<strong>Note: </strong>If it is not possible to make the all elements of any one&nbsp;array equal then return -1.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 4
A[] = {2,1,2,2}
B[] = {3,2,4,4}
<strong>Output: </strong>1<strong>
Explanation: </strong>we can swap A[2] and B[2].
A[] becomes {2,2,2,2} , B[] becomes {3,1,4,4}
Now all elements of the array A[] are equal.
</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 3
A[] = {1,1,2}
B[] = {1,1,1}
<strong>Output: </strong>0<strong>
Explanation: </strong>No swaps required,
All elements of the array B[] are already equal.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 3:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 2
A[] = {1,2}
B[] = {4,3}
<strong>Output: </strong>-1<strong>
Explanation: </strong>It is not possible to make all
elements of one array equal.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your&nbsp;task is to complete the function&nbsp;<strong>minSwaps</strong>() which takes N,&nbsp;an array A[ ] and an array B[]&nbsp;as input and returns the minimum number of swaps required to make the all elements of the array A[] or B[] equal. If it is not possible then return -1.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&nbsp;<u>&lt;</u>&nbsp;N&nbsp;<u>&lt;</u>&nbsp;10<sup>5</sup><br>
1&nbsp;<u>&lt;</u>&nbsp;A[i]&nbsp;<u>&lt;</u>&nbsp;10<sup>5</sup></span></p>
 <p></p>
            </div>