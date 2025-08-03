
#ifndef SHADER_HPP
#define SHADER_HPP
#include<iostream>
#include<fstream>
#include<sstream>
class Shader{
    private:
        unsigned int shaderprogram;

        std::string ReadFromFile(const char* filename){
            std::ifstream file(filename);

            std::stringstream buffer;
            buffer<<file.rdbuf();

            std::string source_code=buffer.str();
            file.close();

            return source_code;

        }
        void DebugShaderCompilation(unsigned int shader){
            int success;
            glGetShaderiv(shader,GL_COMPILE_STATUS,&success);
            if(!success){
                char infolog[512];
                glGetShaderInfoLog(shader,512,0,infolog);
                std::cout<<"\nShader Error Log : "<<infolog;
            }
        }


    public:
        Shader(const char* vshader_file,const char* fshader_file){
            std::string vshader_source=ReadFromFile(vshader_file);
            std::string fshader_source=ReadFromFile(fshader_file);
            
            const char* v_source_raw=vshader_source.c_str();
            const char* f_source_raw=fshader_source.c_str();

            unsigned int vertex_shader=glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex_shader,1,&v_source_raw,0);
            glCompileShader(vertex_shader);
            DebugShaderCompilation(vertex_shader);

            unsigned int fragment_shader=glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment_shader,1,&f_source_raw,0);
            glCompileShader(fragment_shader);
            DebugShaderCompilation(fragment_shader);

            shaderprogram=glCreateProgram();
            glAttachShader(shaderprogram,vertex_shader);
            glAttachShader(shaderprogram,fragment_shader);
            glLinkProgram(shaderprogram);


        }   
        

        void UseProgram(){
            glUseProgram(shaderprogram);
        }
        void SetMat4(const char* var_name,glm::mat4 matrix4){
            unsigned int location=glGetUniformLocation(shaderprogram,var_name);
            glUniformMatrix4fv(location,1,GL_FALSE,(const float*)(&matrix4));
        }
        void SetVec3(const char* var_name,glm::vec3 vector3){
            unsigned int location=glGetUniformLocation(shaderprogram,var_name);
            glUniform3fv(location,1,(const float*)(&vector3));
        }
        void SetInteger(const char* var_name,int i){
            unsigned int location=glGetUniformLocation(shaderprogram,var_name);
            glUniform1i(location,i);
        }
        void SetFloat(const char* var_name,float value){
            unsigned int location=glGetUniformLocation(shaderprogram,var_name);
            glUniform1f(location,value);
        }


};
#endif