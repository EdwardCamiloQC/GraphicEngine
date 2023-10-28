#ifndef _MAPLEVEL2_H_
    #define _MAPLEVEL2_H_

    #include <map.h>
    #include <figure.h>

    struct positionCube{
        float x, y, z;
    };

    class MapCube : public Map{
        public:
            MapCube(float xCam, float yCam, float zCam);
            void implementMap(unsigned int idShader) override;
            ~MapCube();
        protected:
            struct vertexCube cube;
            unsigned int VAO, VBO, EBO;
            struct positionCube position;
    };
#endif
