## Mastering Algorithms with C --Book-- 

* Three reasons for using data structures are: **efficiency, abstraction, and reusability.**

* In computing, some of the most common organizations are **linked lists, stacks, queues, sets, hash tables, trees, heaps, priority queues, and graphs.**

*  In C, we make a data structure store data of any type by using void pointers to the data rather than by maintaining private copies of the data in the data structure itself.

* A void pointer (void \*) is a type of pointer that can point to any data type. Since it doesn't have a specific type, it can be used to store addresses of any kind of data.

* As with data structures, three reasons for using formal algorithms are **efficiency, abstraction, and reusability.**

* **Modularity:** in computing and programming refers to dividing a system into separate modules or components. Each module handles a specific functionality and operates independently. 

* Readability

* Simplicity

* Consistency

### Pointer Manipulation

* **Generic pointers and casts:**
    - Mechanisms that bypass and override C’s type system.**Generic pointers** let us point to data without being concerned with its type for the moment. **Casts** allow us to override the type of a variable temporarily.

* **Function pointers:**
    - Pointers that point to executable code, or blocks of information needed to invoke executable code, instead of pointing to data. They are used to store and manage functions as if they were pieces of data.

* Recall that a pointer is simply a variable that stores the address where a piece of data resides in memory rather than storing the data itself. That is, pointers contain memory addresses. Even for experienced developers, at times this level of indirection can be a bit difficult to visualize, particularly when dealing with more complicated pointer constructs, such as pointers to other pointers. Thus, one of the best things we can do to understand and communicate information about pointers is to draw diagrams (see Figure 2.1). Rather than listing actual addresses in diagrams, pointers are usually drawn as arrows linking one location to another. When a pointer points to nothing at all—that is, when it is set to NULL—it is illustrated as a line terminated with a double bar (||).

* As with other types of variables, we should not assume that a pointer points anywhere useful until we explicitly set it. It is also important to remember that nothing prevents a pointer in C from pointing to an invalid address.**Pointers that point to invalid addresses are sometimes called dangling pointers.** Some examples of programming errors that can lead to dangling pointers include casting arbitrary integers to pointers, adjusting pointers beyond the bounds of arrays, and deallocating storage that one or more pointers still reference.

* When we declare a pointer in C, a certain amount of space is allocated for it, just as for other types of variables. Pointers generally occupy one machine word, but their size can vary. Therefore, for portability, we should never assume that a pointer has a specific size. Pointers often vary in size as a result of compiler settings and type specifiers allowed by certain C implementations. It is also important to remember that when we declare a pointer, space is allocated only for the pointer itself; no space is allocated for the data the pointer references. Storage for the data is allocated in one of two ways: by declaring a variable for it or by allocating storage dynamically at runtime (using malloc or realloc, for example).

* 
