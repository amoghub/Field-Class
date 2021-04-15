#include "Field.h"

//default constructor
Field::Field()
{

}

//copy constructor
Field::Field(const std::vector<std::vector<int>>& trg)
{
    forPath = trg;      //forPath is used for pathCost function
    vec = trg;          //vec is used for Weight function

    //base case
    if(trg.size() == 0)
    {
        return;
    }

    //for Weight function
    for (int i = 0; i < vec.size(); i++) 
    { 
        for (int j = 0; j < vec[i].size(); j++)
        {
            //checks largest amount of elements in vector
            if(size < vec[i].size())
            {
                size = vec[i].size();
            }

            //if boundaries are not exceeded
            if(j + 1 < vec[i].size())
            {
                vec[i][j + 1] += vec[i][j];   //store values for 0th vector
            }

            if(i > 0)
            {
                vec[i][j] = vec[i][j] + vec[i - 1][j];  //store values for rest of vectors
            }
        }
    }
}

//move constructor
Field::Field(std::vector<std::vector<int>>&& trg)
{

    forPath = trg;      //forPath is used for pathCost function
    vec = trg;          //vec is used for Weight function

    //base case
    if(trg.size() == 0)
    {
        return;
    }

    //for Weight function
    for (int i = 0; i < vec.size(); i++) 
    { 
        for (int j = 0; j < vec[i].size(); j++)
        {
            //checks largest amount of elements in vector
            if(size < vec[i].size())
            {
                size = vec[i].size();
            }

            //if boundaries are not exceeded
            if(j + 1 < vec[i].size())
            {
                vec[i][j + 1] += vec[i][j];   //store values for 0th vector
            }

            if(i > 0)
            {
                vec[i][j] = vec[i][j] + vec[i - 1][j];  //store values for rest of vectors
            }
        }
    }

    trg.clear();
}

//weight function
int Field::Weight(int x1, int y1, int x2, int y2)
{
    int sum, first, second, third, fourth, maxX, maxY, minX, minY;

    //base cases
    if(vec.size() == 0)
    {
        throw std::out_of_range("No elements! Please reinput.");
    }

    if(vec.size() - 1 < y1 || vec.size() - 1 < y2)
    {
        throw std::out_of_range("One of your inputs is out of range! Please reinput.");
    }
    
    if(size - 1 < x1 || size - 1 < x2)
    {
        throw std::out_of_range("One of your inputs is out of range! Please reinput.");
    }

    //bottom right corner of weight rectangle
    maxX = std::max(x1, x2);
    maxY = std::max(y1, y2);

    //top left corner of weight rectangle
    minX = std::min(x1, x2);
    minY = std::min(y1, y2);

    //checks if negative number is inputted
    if(minY < 0 || minX < 0 || maxX < 0 || maxY < 0)
    {
        throw std::out_of_range("One of your inputs is not a positive integer! Please reinput.");
    }

    first = vec[maxY][maxX];                    //largest value
    
    //second value
    //checks if minY can be subtracted
    if(minY == 0)
    {
        second = 0;
    }
    else{
        second = vec[minY - 1][maxX];           //value to the bottom left of 2d vector
    }

    //third
    //checks if minX can be subtracted
    if(minX == 0)
    {
        third = 0;
    }
    else{
        third = vec[maxY][minX - 1];            //value to upper right of 2d vector
    }

    //fourth
    //checks if minY or minX can be subtracted
    if(minX == 0 || minY == 0)
    {
        fourth = 0;
    }
    else{
        fourth = vec[minY - 1][minX - 1];       //value to be added, value diagonally adjacent to 2d vector
    }

    //in case anything is negative integer
    if(first < 0 )
    {
        first = 0;
    }
    if(second < 0 )
    {
        second = 0;
    }
    if(third < 0 )
    {
        third = 0;
    }
    if(fourth < 0)
    {
        fourth = 0;
    }

    sum = first - second - third + fourth;      //adds up all values to sum

    return sum;                     
}

//pathcost function
int Field::PathCost()
{
    //base cases
    if(forPath.size() == 0)
    {
        return 0;
    }

    if(forPath.size() == 1)
    {
        return vec[0][vec.size() - 1];
    }




    for(int i = 0; i < forPath.size(); i++)
    {
        for(int j = 0; j < forPath[i].size(); j++)
        {
            Sadge = forPath[i].size();                  //Sadge = last vector's size so that it can be returned at the end

            //if iterator goes through first loop
            if(i == 0 && j + 1 < forPath[i].size())
            {
                forPath[i][j + 1] += forPath[i][j];       //add the same way as the Weight Matrix for first vector
            }

            //if iterator goes through first column
            if(i > 0 && j == 0)
            {
                forPath[i][j] += forPath[i - 1][j];     //add only the first column 
            }

            //else
            if(i > 0 && j > 0)
            {
                forPath[i][j] += std::min(forPath[i-1][j], forPath[i][j-1]);       //add the min value between top and left adjacent sides
            }
        }
    }

    return forPath[forPath.size() - 1][Sadge - 1];      //return last element in last vector
}