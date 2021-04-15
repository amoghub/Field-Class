# Field

# Description

Field was a project made during my 335 Software Analysis and Design 3 class, and allows a vector of vectors to be read and computed.

## Design

Two constructors are modified for Field to be properly executed and read, which can be seen in the ".h" file. Move and copy constructors are both made in O(n) time, where n is the amount of elements that are read from all vectors that are given to a Field object.

## Functions

There are two functions made in the Field class, which are Weight() and PathCost(). 

The Weight() function has 4 parameters, each being an integer coordinate corresponding to a location within the Field object. The coordinates are read as (X1, Y1, X2, Y2), which makes a total of 2 pairs. The 2 pairs can be seen as the two corners of a 2D array within the Field object, and the result of the function is the sum of every element within the 2D array (See example for demonstration).

### Weight Example:

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

