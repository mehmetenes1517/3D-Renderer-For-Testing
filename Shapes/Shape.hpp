#ifndef SHAPE_HPP
#define SHAPE_HPP
#include<vector>
#include"../GL_Utils/Vertex.hpp"
struct Shape{

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

};

enum class Shapes{

    CUBE



};



#endif