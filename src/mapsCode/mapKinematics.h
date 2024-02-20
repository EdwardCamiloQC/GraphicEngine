#ifndef _KINEMATICS_H_
    #define _KINEMATICS_H_

    #include <map.h>
    #include <modelOBJ.h>

    class MapKinematics: public Map{
        public:
            MapKinematics(float xCam, float yCam, float zCam);
            void implementMap(unsigned int idShader) override;
            ~MapKinematics();
        private:
            unsigned int VAO, VBO, EBO;
            struct Position{float x, y, z;};
            ModelObj mapaPrub;
            std::vector<float> dataVertex1;
            std::vector<unsigned int> indicesVertex1;
            std::vector<float> normalsVertex1;
    };
#endif
