#ifndef RENDERER_H
#define RENDERER_H
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"Shapes/ShapeController.hpp"
#include"GL_Utils/Shader.hpp"
#include"GL_Utils/VertexArray.hpp"
#include"GL_Utils/Texture.hpp"
#include"Shapes/CubeClass.hpp"
#include"Camera.hpp"
#include"Shaders/ShaderModes.hpp"
bool first_time_cursor=true;
float MousePosX,MousePosY;
float pitch=0.0f,yaw=90.0f;
float sensivity=2.0f;
float deltax=0,deltay=0;
class Renderer
{
    private:
        GLFWwindow *window;




    public:


        static void pos_callback(GLFWwindow* window,double xpos,double ypos){
            float mousex=static_cast<float>(xpos);
            float mousey=static_cast<float>(ypos);

            if(first_time_cursor){
                
                MousePosX=mousex;
                MousePosY=mousey;
                first_time_cursor=false;

            }
            
            deltax=mousex-MousePosX;
            deltay=MousePosY-mousey;
            
            MousePosX=mousex;
            MousePosY=mousey;
            


        }
        float clampf(float val,float min,float max){
            if(val<=min){
                val=min;
            }else if(val>=max){
                val=max;
            }
            return val;
        }
        Renderer(){

            glfwInit();
            glfwWindowHint(GLFW_RESIZABLE,GLFW_FALSE);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
            glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
            GLFWwindow* window=glfwCreateWindow(1280,720,"Block",nullptr,nullptr);
            glfwMakeContextCurrent(window);
            glewInit();
            glEnable(GL_DEPTH_TEST);



            Shape Cube_Data=ShapeController::GetShape(Shapes::CUBE,glm::vec3(1.0f,1.0f,1.0f),glm::vec3(1.0f,1.0f,0.0f));
            
            VertexArray vao=VertexArray(Cube_Data.vertices,Cube_Data.indices);
            vao.LinkAttrib(0,3,sizeof(Vertex),(void*)(0));
            vao.LinkAttrib(1,3,sizeof(Vertex),(void*)(sizeof(float)*3));
            vao.LinkAttrib(2,2,sizeof(Vertex),(void*)(sizeof(float)*6));
            vao.LinkAttrib(3,3,sizeof(Vertex),(void*)(sizeof(float)*8));

            Shader shader2("Shaders/vertex2.glsl","Shaders/fragment2.glsl");
            Shader shader3("Shaders/vert3.glsl","Shaders/frag3.glsl");

            Texture tex2d("texture.png",GL_RGBA);

            Camera cam=Camera();
            cam.far=400.0f;
            cam.near=0.01f;
            ShaderModes shadermode=ShaderModes::TEXTURE_WITHOUT_LIGHT;
            std::vector<CubeClass*> cube_list;
            std::vector<glm::mat4> instance_mat_list;
            float offset=2.0f;
            for (int i = 0; i < 40; i++)
            {
                for (int j = 0; j < 1; j++)
                {
                     for (int k = 0; k < 40; k++)
                    {
                        CubeClass* cube=new CubeClass(glm::vec3(offset*i,offset*j,offset*k),glm::vec3(0.0f),glm::vec3(2.0f,2.0f,2.0f),&vao,&shader2);
                        instance_mat_list.push_back(cube->GetModelMatrix());
                        cube->LoadTexture(&tex2d);

                        cube_list.push_back(cube);                    
                        
                    }
                }
            }

            vao.BindVAO();
            unsigned int instance_buffer;
            glGenBuffers(1,&instance_buffer);
            glBindBuffer(GL_ARRAY_BUFFER,instance_buffer);
            glBufferData(GL_ARRAY_BUFFER,sizeof(glm::vec3)*1000000,NULL,GL_DYNAMIC_DRAW);

            glVertexAttribPointer(4,4,GL_FLOAT,GL_FALSE,sizeof(glm::vec4)*4,(void*)0);
            glEnableVertexAttribArray(4);
            glVertexAttribDivisor(4,1);
            
            glVertexAttribPointer(5,4,GL_FLOAT,GL_FALSE,sizeof(glm::vec4)*4,(void*)(sizeof(glm::vec4)));
            glEnableVertexAttribArray(5);
            glVertexAttribDivisor(5,1);
            
            glVertexAttribPointer(6,4,GL_FLOAT,GL_FALSE,sizeof(glm::vec4)*4,(void*)(sizeof(glm::vec4)*2));
            glEnableVertexAttribArray(6);
            glVertexAttribDivisor(6,1);

            glVertexAttribPointer(7,4,GL_FLOAT,GL_FALSE,sizeof(glm::vec4)*4,(void*)(sizeof(glm::vec4)*3));
            glEnableVertexAttribArray(7);
            glVertexAttribDivisor(7,1);



            
            
            glfwSetCursorPosCallback(window,pos_callback);
            glfwSetInputMode(window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);
            float speed=50.0f;
            float angularspeed=1.0f;
            float deltaTime=0,time=glfwGetTime();
            std::vector<CubeClass*> inside_frustum={};
            std::vector<glm::mat4> inside_frustum_pos={};


            float fake_fov=90.0f;

            while (!glfwWindowShouldClose(window))
            {
                //FRUSTUM CULLING
                inside_frustum.clear();
                inside_frustum_pos.clear();
                
                cam.fov=90.0f;
                for (int i = 0; i < cube_list.size(); i++)
                {
                    if(cam.FrustumOverlapShape(cube_list[i])){
                        inside_frustum.push_back(cube_list[i]);
                        if(shadermode==ShaderModes::SOLIDCOLOR){
                            cube_list[i]->Rotate(2*deltaTime,2*deltaTime,0.0f);
                        }if(shadermode==ShaderModes::TEXTURE_WITHOUT_LIGHT){
                            cube_list[i]->rotation=glm::vec3(0.0f);

                        }
                        inside_frustum_pos.push_back(cube_list[i]->GetModelMatrix());
                    }
                }
                
                
                glBindBuffer(GL_ARRAY_BUFFER,instance_buffer);
                glBufferSubData(GL_ARRAY_BUFFER,0,sizeof(glm::mat4)*inside_frustum_pos.size(),inside_frustum_pos.data());
                

                
                
                if(glfwGetKey(window,GLFW_KEY_ESCAPE)){
                    glfwSetWindowShouldClose(window,1);
                }
                if(glfwGetKey(window,GLFW_KEY_K)){
                    std::cout<<"a";
                    shadermode=ShaderModes::TEXTURE_WITHOUT_LIGHT;
                }
                if(glfwGetKey(window,GLFW_KEY_J)){
                    std::cout<<"b";
                    shadermode=ShaderModes::SOLIDCOLOR;
                }
                if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT)){
                    fake_fov+=20.0f*deltaTime;
                }if(glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_RIGHT)){
                    fake_fov-=20.0f*deltaTime;
                }
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glClearColor(0.0f,0.0f,0.0f,1.0f);
                deltaTime=glfwGetTime()-time;
                time=glfwGetTime();
                
                cam.Move(
                    (glfwGetKey(window,GLFW_KEY_D)-glfwGetKey(window,GLFW_KEY_A))*deltaTime*speed,
                    (glfwGetKey(window,GLFW_KEY_SPACE)-glfwGetKey(window,GLFW_KEY_LEFT_SHIFT))*deltaTime*speed,
                    -(glfwGetKey(window,GLFW_KEY_S)-glfwGetKey(window,GLFW_KEY_W))*deltaTime*speed
                );                
                cam.MouseControls(yaw,pitch);
                vao.BindVAO();
                
                
                cam.fov=fake_fov;
                switch (shadermode)
                {
                case ShaderModes::TEXTURE_WITHOUT_LIGHT:
                    shader3.UseProgram();
                    tex2d.BindTexture();
                    shader3.SetMat4("CamMatrix",cam.GetProjectionMatrix());
                    break;
                    case ShaderModes::SOLIDCOLOR:
                    shader2.UseProgram();
                    shader2.SetMat4("CamMatrix",cam.GetProjectionMatrix());
                    break;
                }
                
                vao.DrawInstanced(inside_frustum.size());
            /* code */

                //Mouse Movement
                yaw+=deltax*sensivity*deltaTime;
                pitch+=deltay*sensivity*deltaTime;
                if(pitch>=1.5f){
                    pitch=1.49f;
                }
                else if(pitch<=-1.5f){
                    pitch=-1.49f;
                }


                deltax=0;
                deltay=0;

                glfwPollEvents();
                glfwSwapBuffers(window);
            }


        }
};
#endif
