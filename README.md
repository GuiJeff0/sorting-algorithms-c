<h1>SORTING ALGORITHMS IN C</h1>

## Quick Sort

### QuickSort is an efficient and widely used sorting algorithm. It uses the "divide and conquer" paradigm to order elements in a list or array. The basic idea of QuickSort is to choose a "pivot" and partition the list elements into two sublists: one containing elements smaller than or equal to the pivot and the other containing elements greater than the pivot. You then apply QuickSort recursively to the two sublists.

### Runtime

QuickSort execution time depends on the choice of pivot and the nature of the data to be sorted:

Average Case: The expected execution time is 𝑂(𝑛log 𝑛) .This occurs when the chosen pivot splits the list into two approximately equal sublists on each recursive call.

Best Case: The best case is also 𝑂(𝑛log 𝑛), which occurs when partition divides the list exactly in half on each recursive call.

Worst Case: The worst case is 𝑂(𝑛^2), which occurs when the chosen pivot is always the largest or smallest element, resulting in highly imbalanced partitions (for example, if the list is already sorted or reversely sorted and the pivot is chosen as the first or last element).


