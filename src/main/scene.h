#ifndef _SCENE_H_
    #define _SCENE_H_

    #include <map.h>

    class Scene{
        public:
            Scene();
            void loadMap(Map* map);
            void eraseMap();
            void drawMap(unsigned int idShader);
            Camera& requestCamera();
            ~Scene();
        private:
            Map* actMap;
    };
#endif
