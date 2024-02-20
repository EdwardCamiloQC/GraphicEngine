#ifndef _HEART_H_
    #define _HEART_H_

    #include <map.h>
    #include <modelOBJ.h>

    class MapHeart: public Map{
        public:
            MapHeart(float xCam, float yCam, float zCam);
            void implementMap(unsigned int idShader) override;
            ~MapHeart();
        private:
            unsigned int VAO, VBO, EBO;
            struct Position{float x, y, z;};
            ModelObj heart;
            std::vector<float> heartVertex;
            std::vector<unsigned int> heartElements;
            std::vector<float> heartNormals;
    };
#endif
