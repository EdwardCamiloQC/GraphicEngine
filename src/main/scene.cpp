#include <scene.h>

Scene::Scene():actMap(nullptr){
}

void Scene::loadMap(Map* map){
    actMap = map;
}

void Scene::eraseMap(){
    Map* auxMap = actMap;
    delete auxMap;
    actMap = nullptr;
}

void Scene::drawMap(unsigned int idShader){
    actMap->implementMap(idShader);
}

Camera& Scene::requestCamera(){
    return actMap->getCamera();
}

Scene::~Scene(){
    if(actMap != nullptr){
        eraseMap();
    }
}