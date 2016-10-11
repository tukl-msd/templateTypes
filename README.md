
### Buiding the project with QTCreator
Execute the *QTCreator*.

``` bash
$ qtcreator &
```

Use the menu bar and open the project file.

**File -> Open Project -> templateTypes.pro**

When you open the project for the first time a configuration window pops-up.
Then click in **Configure Project** and after that **Build** the project.


### About the BOOST UNITS library:

This video describes my (Andre) own experience with the library. Unfortunately I have found it way later than I should.
Do watch it if you have the time, it provides very useful examples (which you won't find in the library tutorial itself!).

https://www.youtube.com/watch?v=qphj8ZuZlPA

In summary, (pros) the library is very complete:
1. it has by default almost all dimensions and units one would use;
2. easy way of adding new dimensions and units (once you know how);
3. has very little or none run time overhead;
4. has a reasonable compile time;
5. does make your code much more explicit and readable, and therefore, less prone to errors;
6. seems to be the most reliable library for dimensional analisys,

but (cons):
1. is badly documented;
2. does not provide a clear way (step by step eg.) of using its features;
3. the implementation is virtually unreadable.
