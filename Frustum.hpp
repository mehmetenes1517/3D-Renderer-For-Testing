#ifndef FRUSTUM_HPP
#define FRUSTUM_HPP
#include<glm/glm.hpp>
#include<vector>
#include"Shapes/CubeClass.hpp"
struct Frustum
{

    bool PointInClipSpace(glm::vec4 &point) const{
        return (point.x/point.w)>=-1 && (point.x/point.w)<=1 && (point.y/point.w)>=-1 && (point.y/point.w)<=1 && (point.z/point.w)>=-1 && (point.z/point.w)<=1;
    }

};




#endif