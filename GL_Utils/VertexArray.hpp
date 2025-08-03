#ifndef VERTEXARRAY_HPP
#define VERTEXARRAY_HPP
class VertexArray{
    private:
    void LoadData(std::vector<Vertex> vertices,std::vector<unsigned int> indices){
        glGenVertexArrays(1,&vao);
        glGenBuffers(1,&vbo);
        glGenBuffers(1,&ibo);
        
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER,vbo);
        glBufferData(GL_ARRAY_BUFFER,sizeof(Vertex)*vertices.size(),vertices.data(),GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(unsigned int)*indices.size(),indices.data(),GL_STATIC_DRAW);
            
        }
        
    public:
        unsigned int vao,vbo,ibo;
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;

        VertexArray(std::vector<Vertex> vertices,std::vector<unsigned int> indices){
            LoadData(vertices,indices);
            this->vertices=vertices;
            this->indices=indices;
        }
        
        void LinkAttrib(int index , int size , size_t stride, void* pointer){
            glVertexAttribPointer(index,size,GL_FLOAT,GL_FALSE,stride,pointer);
            glEnableVertexArrayAttrib(this->vao,index);
        }

        void BindVAO(){
            glBindVertexArray(vao);
        }
        void Draw(){
            glDrawElements(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0);
        }


        void DrawInstanced( int instance){
            glDrawElementsInstanced(GL_TRIANGLES,indices.size(),GL_UNSIGNED_INT,0,instance);
        }

};
#endif