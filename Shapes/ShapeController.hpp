#ifndef SHAPE_CONTROLLER_HPP
#define SHAPE_CONTROLLER_HPP
#include"Shape.hpp"
#include<glm/glm.hpp>

class ShapeController{
public:
    static Shape GetShape(Shapes shape_type,glm::vec3 scale,glm::vec3 color){

        switch (shape_type)
        {
        case Shapes::CUBE:
            return (Shape){
                .vertices={
                    (Vertex){ scale.x/2, scale.y/2, scale.z/2,color.r,color.g,color.b,1.0f,1.0f,0.0f,0.0f,1.0f},//0
                    (Vertex){ scale.x/2,-scale.y/2, scale.z/2,color.r,color.g,color.b,1.0f,0.0f,0.0f,0.0f,1.0f},//1
                    (Vertex){-scale.x/2,-scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,0.0f,0.0f,0.0f,1.0f},//2
                    (Vertex){-scale.x/2, scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,1.0f,0.0f,0.0f,1.0f},//3

                    (Vertex){ scale.x/2, scale.y/2,-scale.z/2,color.r,color.g,color.b,0.0f,1.0f,0.0f,0.0f,-1.0f},//4
                    (Vertex){ scale.x/2,-scale.y/2,-scale.z/2,color.r,color.g,color.b,0.0f,0.0f,0.0f,0.0f,-1.0f},//5
                    (Vertex){-scale.x/2,-scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,0.0f,0.0f,0.0f,-1.0f},//6
                    (Vertex){-scale.x/2, scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,1.0f,0.0f,0.0f,-1.0f},//7

                    (Vertex){ scale.x/2, scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,1.0f,1.0f,0.0f,0.0f},//8
                    (Vertex){ scale.x/2,-scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,0.0f,1.0f,0.0f,0.0f},//9
                    (Vertex){ scale.x/2,-scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,0.0f,1.0f,0.0f,0.0f},//10
                    (Vertex){ scale.x/2, scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,1.0f,1.0f,0.0f,0.0f},//11

                    (Vertex){-scale.x/2, scale.y/2, scale.z/2,color.r,color.g,color.b,1.0f,1.0f,-1.0f,0.0f,0.0f},//12
                    (Vertex){-scale.x/2,-scale.y/2, scale.z/2,color.r,color.g,color.b,1.0f,0.0f,-1.0f,0.0f,0.0f},//13
                    (Vertex){-scale.x/2,-scale.y/2,-scale.z/2,color.r,color.g,color.b,0.0f,0.0f,-1.0f,0.0f,0.0f},//14
                    (Vertex){-scale.x/2, scale.y/2,-scale.z/2,color.r,color.g,color.b,0.0f,1.0f,-1.0f,0.0f,0.0f},//15

                    (Vertex){-scale.x/2, scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,1.0f,0.0f,1.0f,0.0f},//16
                    (Vertex){ scale.x/2, scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,0.0f,0.0f,1.0f,0.0f},//17
                    (Vertex){ scale.x/2, scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,0.0f,0.0f,1.0f,0.0f},//18
                    (Vertex){-scale.x/2, scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,1.0f,0.0f,1.0f,0.0f},//19

                    (Vertex){ scale.x/2,-scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,1.0f,-1.0f,0.0f,0.0f},//20
                    (Vertex){-scale.x/2,-scale.y/2,-scale.z/2,color.r,color.g,color.b,1.0f,0.0f,-1.0f,0.0f,0.0f},//21
                    (Vertex){-scale.x/2,-scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,0.0f,-1.0f,0.0f,0.0f},//22
                    (Vertex){ scale.x/2,-scale.y/2, scale.z/2,color.r,color.g,color.b,0.0f,1.0f,-1.0f,0.0f,0.0f}//23
                    },
                    .indices={
                        0,1,2,
                        0,3,2,

                        7,6,5,
                        7,4,5,

                        8,9,10,
                        8,11,10,

                        12,13,14,
                        12,15,14,

                        16,17,18,
                        16,19,18,

                        20,21,22,
                        20,23,22               

            }};
            break;
        
        default:
            return (Shape){
                .vertices={},
                .indices={}
            };
            break;
        }

    } 










};





#endif
