#ifndef _PENTAGONO_H_
    #define _PENTAGONO_H_

    #include <map.h>
    #include <modelOBJ.h>

    class MapPentagono: public Map{
        public:
            MapPentagono(float xCam, float yCam, float zCam);
            void implementMap(unsigned int idShader) override;
            ~MapPentagono();
        private:
            unsigned int VAO, VBO, EBO;
            struct Position{float x, y, z;};
            ModelObj pentagono;
            std::vector<float> pentagonoVertex;
            std::vector<unsigned int> pentagonoElements;
            std::vector<float> pentagonoNormals;
    };
#endif