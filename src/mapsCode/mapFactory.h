#ifndef _MAP_FACTORY_H_
    #define _MAP_FACTORY_H_

    #include <mapPyramid.h>
    #include <mapCube.h>
    #include <mapPyramid.h>

    class Map;

    enum MAP{
        CUBE = 1,
        PYRAMID
    };

    class MapFactory{
        public:
            Map* createMap(enum MAP idLevel, float x0, float y0, float z0){
                switch(idLevel){
                    case PYRAMID:
                        return new MapPyramid(x0, y0, z0);
                    case CUBE:
                        return new MapCube(x0, y0, z0);
                    default:
                        return new MapPyramid(x0, y0, z0);
                }
            }
    };
#endif
