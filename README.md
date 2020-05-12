# ConcurrentQueue

I need to run a function inside while loop as a separate process that will always take a new input in every loop.
I want the thread to keep taking new input inside loop and execute the function in the right order, I have to implement the pop and push queue operation.

Common way to parallelize a serial algorithm is to split it into independent chunks and make a pipeline — each stage in the pipeline can be run on a separate thread, and each stage adds the data to the input queue for the next stage when it's done. For this to work properly, the input queue needs to be written so that data can safely be added by one thread and removed by another thread without corrupting the data structure.

Best explanation : 
 - https://juanchopanzacpp.wordpress.com/2013/02/26/concurrent-queue-c11/
 - https://www.justsoftwaresolutions.co.uk/threading/implementing-a-thread-safe-queue-using-condition-variables.html
 
 Result :
 ```
 0
---->0
1
---->1
2
---->2
3
---->3
4
---->4
5
---->5
6
---->6
7
---->7
8
---->8
9
---->9
10
---->10
11
---->11
```
