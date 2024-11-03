# Chapter 3


## Building
On Linux:
1. `javac <.java files>`
2. `java <.class file with main>`


## Question 3.2
Build the stack on top of a [(Doubly) Linked List][dll] with an additional pointer in each node to track the next minimum node. On each push compare the node to be added with the current mimimum. If the new value is a new minimum, point it to the previous minimum, track it as the newest minimum, and then push it on to the stack. On each popcheck the value being popped. If the popped value is the minimum, set the new minimum node to it's previous node. If it is not, adjoin the links to the next node in each respective direction. At any point the `min` method will return the minimum node in `O(1)` time.


[dll]: https://en.wikipedia.org/wiki/Doubly_linked_list
