#ifndef VERTEX_HPP
#define VERTEX_HPP
#include<iostream>
struct Vertex{
    float x,y,z;
    float r,g,b;
    float tex_x,tex_y;
    float norm_x,norm_y,norm_z;

    void Display(){
        std::cout<<"\n"<<x<<y<<z;
    }
};
#endif