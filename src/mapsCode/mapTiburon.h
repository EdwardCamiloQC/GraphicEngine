#ifndef _TIBURON_H_
    #define _TIBURON_H_

    #include <map.h>
    #include <modelOBJ.h>

    class MapTiburon: public Map{
        public:
            MapTiburon(float xCam, float yCam, float zCam);
            void implementMap(unsigned int idShader) override;
            ~MapTiburon();
        private:
            unsigned int VAO, VBO, EBO;
            struct Position{float x, y, z;};
            ModelObj tiburon;
            std::vector<float> tiburonVertex;
            std::vector<unsigned int> tiburonElements;
            std::vector<float> tiburonNormals;
    };
#endif
