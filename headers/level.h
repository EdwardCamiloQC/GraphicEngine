#ifndef _LEVEL_H_
    #define _LEVEL_H_

    template<class L>
    class Level{
        public:
            Level():inicio(nullptr){
            }
            void addLevel(const L &t){
                Level<L> *aux = new Level<L>(t, inicio);
                inicio = aux;
            }
            L popLevel(){
                L temp(*inicio->pT);
                Level<L> *aux = inicio;
                inicio = aux->anterior;
                delete aux;
                return temp;
            }
            bool empty(){
                return inicio == nullptr;
            }
            ~Level(){
                while(inicio){
                    popLevel();
                }
            }

            template<class M>
            class Map{
                public:
                    Map(const M& t, Map<M> *ant):anterior(ant){
                        pT = new M(t);
                    }
                    Map(Map<M> &n){
                        pT = new M(*n.pT);
                        anterior = n.anterior;
                    }
                    ~Map(){
                        delete pT;
                    }
                    Map<M> *anterior;
                    M *pT;
            };
        private:
            Map<L> *inicio;
    };
#endif
