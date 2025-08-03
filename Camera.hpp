#ifndef CAMERA_HPP
#define CAMERA_HPP

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include"Frustum.hpp"
class Camera{

public:
    float near=0.1f;
    float far=100.0f;
    float fov=45.0f;
    
    glm::vec3 focus_point=glm::vec3(0.0f,0.0f,0.0f);
    glm::vec3 up_vector=glm::vec3(0.0f,1.0f,0.0f);
    glm::vec3 cam_position=glm::vec3(0.0f,0.0f,5.0f);

    float screen_ratio=(1280.0f/720.0f);

    Frustum frustum;

    Camera(){
    }


    void Move(float x,float y,float z){
    
        
        glm::vec3 forward_vec=glm::normalize(focus_point-cam_position);

        glm::vec3 right_vec=glm::normalize(glm::cross(forward_vec,up_vector));

        cam_position+=(right_vec*x + forward_vec*z + up_vector*y);
    }

    void MouseControls(float yaw,float pitch){

        glm::vec3 forward_vec;

        //forward vec calculations
        forward_vec.x=glm::cos(pitch)*glm::cos(yaw);
        forward_vec.y=glm::sin(pitch);
        forward_vec.z=glm::cos(pitch)*glm::sin(yaw);

        glm::vec3 right_vec=glm::normalize(glm::cross(forward_vec,glm::vec3(0.0f,1.0f,0.0f)));
        glm::vec3 up_vector=glm::normalize(glm::cross(right_vec,forward_vec));

        this->up_vector=up_vector;
        this->focus_point=cam_position+forward_vec;

    }





    glm::mat4 GetProjectionMatrix(){

        glm::mat4 perspective=glm::perspective(glm::radians(fov),screen_ratio,near,far);
        glm::mat4 view=glm::lookAt(cam_position,focus_point,up_vector);

        return perspective*view;
    }

    bool FrustumOverlapShape(CubeClass* cube){
        glm::mat4 camMatrix=this->GetProjectionMatrix();
        glm::vec3 cube_center=cube->position;
        glm::vec4 world_vector=camMatrix*glm::vec4(cube_center.x,cube_center.y,cube_center.z,1.0f);


        if(frustum.PointInClipSpace(world_vector)){
            return true;                
        }
        return false;
    }
};



#endif