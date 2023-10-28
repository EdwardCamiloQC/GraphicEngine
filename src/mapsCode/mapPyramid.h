#ifndef _MAP_LEVEL1_H_
    #define _MAP_LEVEL1_H_

    #include <map.h>
    #include <figure.h>

    struct positionCam{
        float x, y, z;
    };

    class MapPyramid : public Map{
        public:
            MapPyramid(float xCam, float yCam, float zCam);
            void implementMap(unsigned int idShader) override;
            ~MapPyramid();
        protected:
            struct vertexPyramid pyramid;
            unsigned VAO, VBO, EBO;
            struct positionCam position;
    };
#endif
