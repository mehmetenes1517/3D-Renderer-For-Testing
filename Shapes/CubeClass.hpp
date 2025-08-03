#ifndef CUBECLASS_HPP
#define CUBECLASS_HPP
#include"../GL_Utils/Shader.hpp"
#include"../GL_Utils/VertexArray.hpp"
#include"../GL_Utils/Texture.hpp"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

class CubeClass{

    private:
    
    
    public:
        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
        Shader* shader=nullptr;
        VertexArray* vao=nullptr;
        Texture* tex=nullptr;

        CubeClass(glm::vec3 position,glm::vec3 rotation,glm::vec3 scale, VertexArray *vao,Shader *shader){
            this->position=position;
            this->rotation=rotation;
            this->scale=scale;

            this->shader=shader;
            this->vao=vao;
            if(shader==nullptr){
                std::cout<<"\nShader cannot be loaded";
            }
            if(vao==nullptr){
                std::cout<<"\nVertex Array cannot be loaded";
            }
        
        }
        void ChangeShader(Shader* shader){
            this->shader=shader;
        }
        void LoadTexture(Texture* texture){
            tex=texture;
        }
        glm::mat4 GetModelMatrix(){
            glm::mat4 translate_matrix = glm::translate(glm::mat4(1),position);
            glm::mat4 x = glm::rotate(glm::mat4(1),rotation.x,glm::vec3(1.0f,0.0f,0.0f));
            glm::mat4 y = glm::rotate(glm::mat4(1),rotation.y,glm::vec3(0.0f,1.0f,0.0f));
            glm::mat4 z = glm::rotate(glm::mat4(1),rotation.z,glm::vec3(0.0f,0.0f,1.0f));
            glm::mat4 scale_matrix=glm::scale(glm::mat4(1),scale);
            return translate_matrix*x*y*z*scale_matrix;
        }
        void SetPosition(float x ,float y ,float z){

            position.x=x;
            position.y=y;
            position.z=z;

        }
        void SetRotation(float x ,float y ,float z){

            rotation.x=x;
            rotation.y=y;
            rotation.z=z;

        }
        void SetScale(float x,float y,float z){

            scale.x=x;
            scale.y=y;
            scale.z=z;

        }

        void Rotate(float x ,float y ,float z){

            rotation.x+=x;
            rotation.y+=y;
            rotation.z+=z;

        }
         void Translate(float x ,float y ,float z){

            position.x+=x;
            position.y+=y;
            position.z+=z;

        }
};
#endif