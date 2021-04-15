#include <iostream>
#include <vector>

#pragma once

class Field
{
 private:
    std::vector<std::vector<int>> forPath;      //forPath is for PathCost function
    std::vector<std::vector<int>> vec;          //vec is weight matrix

   //used for vector sizes
    int size = 0;
    int Sadge = 0;

 public:
    Field();                                                //default constructor
    Field(const std::vector<std::vector<int>>& trg);        //copy constructor
    Field(std::vector<std::vector<int>>&& trg);             //move constructor

    //functions
    int Weight(int x1, int y1, int x2, int y2);             //Weight returns the value of the coords inputted
    int PathCost();                                         //PathCost finds the smallest path from start to finish
};