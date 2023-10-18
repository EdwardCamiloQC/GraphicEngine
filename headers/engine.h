#ifndef _ENGINE_H_
    #define _ENGINE_H_

    #include <window.h>
    #include <memory>
    //#include <map1.h>

    class Engine{
        public:
            const char* nombre = "Engine";
            const uint32_t ancho = 800;
            const uint32_t alto = 600;
            Engine();
            void run();
            ~Engine();
        private:
            std::unique_ptr<Principal>m_window{};
            unsigned int idP, VAO, VBO, EBO;
    };
#endif
