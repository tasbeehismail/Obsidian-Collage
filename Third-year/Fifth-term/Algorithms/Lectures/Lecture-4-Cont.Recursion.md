## Back to merge sort: How to solving recurrences
$$ T(n) = 2T(n/2) + O(n) $$
![[mergeSort.png]]

$$ T(n) = (n+1) * \log_{2}(n) $$  $$ T(n) = O(n * \log(n)) $$  
## Divide & Conquer
+ Divide the problem to two identical sub-problems then merging them.
+ So the recurrence relation: 
	+ $a$ for the number of independent subproblems, $a \geq 1$
	+ $n$ for size of problem.
	+ size of each some problems $\leq\left[ \frac{n}{b} \right]$
	$$ T(n) = a * T\left[ \frac{n}{b} \right] + g(n)$$
 <span class="red">-> is top down approach</span>
 + #### Examples:
	 + Binary Search: $$ T(n) = T\left[ \frac{n}{2} \right] + c$$
	 + Merge Sort: $$ T(n) = 2 * T\left[ \frac{n}{2} \right] + cn$$
### Final result of solving recurrences, iteration - iterative substitution: (Master Theorem)
![[solvingRecurrences.png]]

+ Let T(n) defined by: $$ T(n) = 2 * T\left[ \frac{n}{2} \right] + O(n)$$
+ Compare with general form:-
	+ $a = 2, b = 2, f(n) = n$ 
	+ $f(n) \ VS \  n^{\log_{b}(a)}$
	+ $f(n) == n^{1}$
	+ $T(n) = 𝜽(n*\log(n))$

## Sorting Algorithms
Insertion, selection and bubble sort have quadratic $O(n^{2})$ worst-case performance.
The faster comparison based algorithm is?
$O(nlogn)$

+ ### Quick Sort
	```c
function quickSort(arr, l, r)
    if l < r
        pivotIndex = partition(arr, l, r)
        quickSort(arr, l, pivotIndex - 1)
        quickSort(arr, pivotIndex + 1, r)

function partition(arr, l, r)
    pivot = arr[r]
    i = l - 1
    
    for j = l to r - 1
        if arr[j] < pivot
            i = i + 1
            swap arr[i] and arr[j]
    
    swap arr[i + 1] and arr[r]
    return i + 1
```
	+ The result of partition method is:
		+ The value of pivot point is in correct position.
		+ The previous values are <= value of pivot.
		+ The next values are > value of pivot.
		+ And the two sides not sorted while pointers low < high.
	+ Best case running time: $O(n \log(n))$
	+  Worst case running time: $O(n^{2})$ !!!

*Revision the analysis of algorithm from slides 77 to 91.*