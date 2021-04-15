# Field

# Description

The Field Class was made during my 335 Software Analysis and Design 3 class, and allows a vector of vectors to be read and computed.

## Design



##Functions

There are two functions made in the Field class, which are Weight() and PathCost(). 

The Weight() function has 4 parameters, each being an integer coordinate corresponding to a location within the Field object. If connected, the 4 coordinates are the corners of a box, or border, that is inside the Field object. The output of Weight() is the sum of all numbers that are within the border of the 4 inputted coordinates. 

### Example:

Let us make a Field object X, which has the values:

{1, 2, 3, 4, 5, 6},

{1, 2, 3, 4, 5, 6},

{1, 2, 3, 4, 5, 6},

{1, 2, 3, 4, 5, 6},

{1, 2, 3, 4, 5, 6}
