#version 440 core

layout(location=0) in vec3 vert_position;
layout(location=1) in vec3 vert_color;
layout(location=2) in vec2 vert_tex;
layout(location=3) in vec3 vert_normal;

layout(location=4) in mat4 instance_Matrix;

out vec2 tex_pos;



uniform mat4 CamMatrix;

void main(){

    tex_pos=vert_tex;
    gl_Position=CamMatrix*instance_Matrix*vec4(vert_position,1.0f);


}