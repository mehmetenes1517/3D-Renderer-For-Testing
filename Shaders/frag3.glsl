#version 440 core

in vec2 tex_pos;
out vec4 fragColor;


uniform sampler2D texture_color;
void main(){

    fragColor=texture(texture_color,tex_pos);


}

