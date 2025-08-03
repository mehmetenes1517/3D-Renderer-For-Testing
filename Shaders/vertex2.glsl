#version 440 core

layout(location=0) in vec3 vert_position;
layout(location=1) in vec3 vert_color;
layout(location=2) in vec2 vert_tex;
layout(location=3) in vec3 vert_normal;

layout(location=4) in mat4 instance_Matrix;

out vec3 VertexColor;

out vec3 current_pos;
out vec3 VertexNormal;

uniform mat4 CamMatrix;

void main(){

    current_pos=vec3(instance_Matrix*vec4(vert_position,1.0f));
    VertexNormal=vec3(instance_Matrix*vec4(vert_normal,1.0f));

    VertexColor=vert_color;
    gl_Position=CamMatrix*vec4(current_pos,1.0f);


}