#ifndef _MAP_H_
    #define _MAP_H_

    #include <camera.h>

    class Map{
        public:
            Map(float xCam, float yCam, float zCam):camera(xCam, yCam, zCam){}
            virtual void implementMap(unsigned int idShader){}
            Camera& getCamera(){
                return camera;
            }
            virtual ~Map(){}
        protected:
            Camera camera;
    };
#endif
