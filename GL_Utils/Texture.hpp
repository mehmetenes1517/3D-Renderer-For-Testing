#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include<iostream>
#include<GL/glew.h>
#define STB_IMAGE_IMPLEMENTATION
#include<stb/stb_image.h>
class Texture{
    unsigned int texture;
public:
    Texture(const char* filename,GLenum color_format){
        LoadTexture(filename,color_format);
    }
    void LoadTexture(const char* filename,GLenum color_format){
        int w,h,c;
        unsigned char* bytes=stbi_load(filename,&w,&h,&c,0);
        stbi_set_flip_vertically_on_load(true);
        glGenTextures(1,&texture);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,texture);

        glTexImage2D(GL_TEXTURE_2D,0,color_format,w,h,0,color_format,GL_UNSIGNED_BYTE,bytes);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(bytes);

    }
    void BindTexture(){
        glBindTexture(GL_TEXTURE_2D,texture);
    }



};




#endif