# CS-300 Data Structures and Algorithms
## Projects from SNHU CS-300 Data Structures and Algorithms

### What was the problem you were solving in the projects for this course?
The problem to be solved with the data structure was to most efficiently provide a tool to store and access a list of courses. Each course may have prerequisites and those prerequisites may have their own prerequisites. For the limited dataset provided, a hash function was developed by which it was guaranteed that there should be no collisions between any courses. The drawback to this approach is that if other courses are added to the list that do not fit into the predefined rules, the hash function will require code changes to continue to work.

### How did you approach the problem? Consider why data structures are important to understand.
My approach was to convert each possible course code into the minimum number of binary digits that could represent it. For example, there are 1xx, 2xx, 3xx, and 4xx courses. To represent these four possibilities, 2 binary digits were required. To represent either a MATH or CSCI only one bit was needed. After counting up all the possible combinations a hash function was developed that breaks down each course Id into those binary components and converts them to an index in the underlying array.
It is important to understand data structures to be able to use the right solution for the problem at hand, especially if the application is sensitive to performance issues.

### How did you overcome any roadblocks you encountered while going through the activities or project?
I'm starting to get the hang of C++ again, so there really weren't any severe road blocks. The thing that took the most time was deciding on how to do the hash function. That was the only function where my pseudocode submitted for previous assignments wasn't pretty much already the code that would be written.
I also added in some extra functionality in the print output method so the indentations would make the output clear about which level the prerequisites were in the hierarchy.

### How has your work on this project expanded your approach to designing software and developing programs?
It was great to get more practice in C++ and to write more C++ tests. The next phase of my development as a C++ developer is to use test driven development in C++.

### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Practice makes perfect! I am probably around the 5000 hour mark in terms of actually writing code, which means I am about half way to the level of experience required to be an expert. The more I work at it, the better I will be, and even though college assignments don't always require certain things such as test driven development (or even unit tests at all), or domain driven design, I will still strive to hone those skills.
