# Field

# Description

Field was a project made during my 335 Software Analysis and Design 3 class, and allows a vector of vectors to be read and computed.

## Design

Two constructors are modified for Field to be properly executed and read, which can be seen in the ".h" file. Move and copy constructors are both made in O(n) time, where n is the amount of elements that are read from all vectors that are given to a Field object. The "forPath" vector in the private header of the class is used during the PathCost function, and the "vec" vector is made in both constructors for the Weight function. 



## Functions
There are two functions made in the Field class, which are Weight() and PathCost(). 

### Weight

The Weight() function has 4 parameters, each being an integer coordinate corresponding to a location within the Field object. The coordinates are read as (X1, Y1, X2, Y2), which makes a total of 2 pairs. The 2 pairs can be seen as the two corners of a 2D array within the Field object, and the result of the function is the sum of every element within the 2D array (See example for demonstration).

Weight Example:

Let us make a Field object X, which has the values:

```
{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6}
```

Let's input the numbers 1, 0, 4, and 2 into the parameters of the Weight function. This would make a pairing of (1, 0) and (4, 2). Now lets remove the commas and brackets around the values, to give a better view of what 2D array was made when those numbers are inputted into the Weight function.


1   **2   3   4   5**   6

1   **2   3   4   5**   6

1   **2   3   4   5**   6

1   **2   3   4   5**   6

1    2    3    4    5    6

Try adding the bolded text together, and see what you get! The answer should be 42. (Weight will return the same output with inputs (1, 2, 4, 0), as the corners are the same.)

Weight is done in O(1) time, and all precomputation is done via the constructors.

### PathCost
The function PathCost computes the "cheapest" possible path from the upper left hand corner of a Field object, to the lower right hand corner of the Field object. The function can move in any direction, except diagonally, and is able to read if the Field object has vectors that are not similar in size to others. The result of the function is the sum of the elements it used to get from the upper left to the bottom right, which is said to be the cheapest "cost", hence the name PathCost. 

PathCost Example:

Lets use the same Field object used in the Weight function, and show how it computes PathCost().

**1**    2    3    4    5    6

**1**    2    3    4    5    6

**1**    2    3    4    5    6

**1**    2    3    4    5    6

**1**    **2**    **3**    **4**    **5**    **6**

As you can see in the bolded text, PathCost saw that the left hand side was all 1's, and the last 5 elements in the final vector was the cheapest way to get to the bottom right hand corner. Now, if we add up the bolded elements, the total is 25! 

PathCost is done in O(n) time, where n is the amount of elements used to find the path. All precomputation was done via the constructors. 

## Skills Learned

Time complexities, vectors, Big 5, constructors, class implementation, header files, cpp files, and compiling. 


## Built With

Visual Studio Code.

Coded with C++.

Tested on Windows 10 and macOS.

## Authors

Amogh Kalyan - Code

