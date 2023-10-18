#ifndef _SHADERS_H_
    #define _SHADERS_H_

    #include <string>

    class ProgramShaders{
        public:
            ProgramShaders(const char* pathVertex, const char* pathFragment);
            unsigned int getIdProgram();
            ~ProgramShaders() = default;
        private:
            unsigned int vertex, fragment, shaderProgram;
        private:
            unsigned int compileShaders(const std::string& shaderPath, unsigned int moduleType);
            void linkShaders();
    };
#endif