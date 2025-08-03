#version 440 core

in vec3 VertexColor;

out vec4 fragColor;
in vec3 current_pos;
in vec3 VertexNormal;


void main(){

    vec3 LightSource=vec3(50.0f,2.0f,50.0f);

    vec3 LightDirection=normalize(LightSource-current_pos);
    float diffuse_light=dot(LightDirection,VertexNormal);


    fragColor=vec4(VertexColor,1.0f)*diffuse_light*0.02;


}

