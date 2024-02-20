#ifndef _SCENE_H_
    #define _SCENE_H_

    #include <map.h>

    class Scene{
        public:
            Scene();
            Scene(const Scene& s);
            ~Scene();
            void loadMap(Map* map);
            void eraseMap();
            void drawMap(unsigned int idShader);
            Camera& requestCamera();
        private:
            Map* actMap;
    };
#endif
