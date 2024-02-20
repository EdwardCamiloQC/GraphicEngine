#include <modelOBJ.h>
#include <iostream>
#include <fstream>

ModelObj::ModelObj(){
}

void ModelObj::loadFromFile(const char* fileName, std::vector<float>& dataVertex, std::vector<unsigned int>& elemVertex, std::vector<float>& normals){
    try{
        std::ifstream file(fileName);
        if(file.fail()){
            throw 'f';
        }else{
            //char currentMtlName[100];
            std::string line;
            Position pos;
            Unions uni;
            Normals norm;
            while(std::getline(file, line)){
                if(startWith(line, "v ")){
                    sscanf(line.c_str(), "v %f %f %f", &pos.x, &pos.y, &pos.z);
                    dataVertex.push_back(pos.x);
                    dataVertex.push_back(pos.y);
                    dataVertex.push_back(pos.z);
                }
                if(startWith(line, "vn ")){
                    sscanf(line.c_str(), "vn %f %f %f", &norm.x, &norm.y, &norm.z);
                    normals.push_back(norm.x);
                    normals.push_back(norm.y);
                    normals.push_back(norm.z);
                }
                if(startWith(line, "f ")){
                    sscanf(line.c_str(), "f %u//%u %u//%u %u//%u",
                        &uni.el_x, &uni.nr_x,
                        &uni.el_y, &uni.nr_y,
                        &uni.el_z, &uni.nr_z);
                    elemVertex.push_back(uni.el_x - 1);
                    elemVertex.push_back(uni.el_y - 1);
                    elemVertex.push_back(uni.el_z - 1);
                }
            }
            file.close();
        }
    }catch(char f){
        std::cout << "OBJ file loading failed" << std::endl;
    }
}

bool ModelObj::startWith(std::string& line, const char* text){
    std::string aux = text;
    size_t textLen = aux.length();
    if(line.size() < textLen){
        return false;
    }
    for(size_t i = 0; i < textLen; i++){
        if(line[i] == text[i]) continue;
        else return false;
    }
    return true;
}

ModelObj::~ModelObj(){
}
