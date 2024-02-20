#ifndef _MODELS_OBJ_H_
    #define _MODELS_OBJ_H_

    #include <vector>
    #include <string>

    class ModelObj{
        public:
            ModelObj();
            void loadFromFile(const char* fileName, std::vector<float>& dataVertex,
                            std::vector<unsigned int>& elemVertex,
                            std::vector<float>& normals);
            ~ModelObj();
        private:
            struct Position{float x, y, z;};
            struct Normals{float x, y, z;};
            struct Unions{
                unsigned int el_x, el_y, el_z;
                unsigned int nr_x, nr_y, nr_z;
            };
        private:
            bool startWith(std::string& line, const char* text);
    };
#endif