#include "Field.cpp"

int main()
{
    std::vector<std::vector<int>> vec
    {
        /* 
        Other vectors that can be used:
        
  1:    {1, 2, 5, 9, 3, 6},
        {6, 9, 4, 0, 1, 9},
        {4, 20, 1, 3, 7, 14},
        {3, 4, 8, 12, 5, 29},
        {9, 3, 1, 4, 6, 1}
        
  2:    {1, 2, 3}
  
        Try them out for yourself, or make some of your own! Make sure you use inputs that are within range of each vector!
        */

        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6}

    };
    
    Field hello(vec);
    std::cout << "Weight is: " << hello.Weight(1, 0, 4, 2) << std::endl;
    std::cout << "Pathcost is: " << hello.PathCost() << std::endl;

}
