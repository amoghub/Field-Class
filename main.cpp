#include "Field.cpp"

int main()
{
    std::vector<std::vector<int>> vec
    {
        // {1, 2, 5, 9, 3, 6},
        // {6, 9, 4, 0, 1, 9},
        // {4, 20, 1, 3, 7, 14},
        // {3, 4, 8, 12, 5, 29},
        // {9, 3, 1, 4, 6, 1}

        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6},
        {1, 2, 3, 4, 5, 6}

        //{1, 2, 3}

    };


    std::cout << " bye" << std::endl;
    Field hello(vec);
    std::cout << "Weight is: " << hello.Weight(1, 0, 4, 2) << std::endl;
    std::cout << "Pathcost is: " << hello.PathCost() << std::endl;
    std::cout << " kai" << std::endl;


}