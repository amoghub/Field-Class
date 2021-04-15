# Field

# Description

Field was a project made during my 335 Software Analysis and Design 3 class, and allows a vector of vectors to be read and computed.

## Design

Two constructors are modified for Field to be properly executed and read, which can be seen in the ".h" file. Move and copy constructors are both made in O(n) time, where n is the amount of elements that are read from all vectors that are given to a Field object.

## Functions

There are two functions made in the Field class, which are Weight() and PathCost(). 

The Weight() function has 4 parameters, each being an integer coordinate corresponding to a location within the Field object. The coordinates are read as (X1, Y1, X2, Y2), which makes a total of 2 pairs. The 2 pairs are then put into the 

If all 4 coordinates are connected, they form an imaginary box, or border, that is inside the Field object. The output of Weight() is the sum of all numbers that are within the border of the 4 inputted coordinates. 

### Example:

Let us make a Field object X, which has the values:

`
{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6},

{1,  2,  3,  4,  5,  6}
`

If you were to output the result of X.Weight(1, 0, 4, 2), the result would be 42.
