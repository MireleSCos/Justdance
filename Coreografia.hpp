#pragma once
#include <string>

using namespace std;

class Coreografia
{
    private:
        /* data */

    public:
        string musica;
        int passosMus[];
        Coreorafia(/* args */);
        Coreorafia(string musica, int passosMus[]);
        
        ~Coreografia();

};

Coreografia::Coreorafia(){

}
Coreografia::Coreorafia(string musica, int passosMus[]){
    this->musica = musica;
    this->passosMus = passosMus;
}
Coreografia::~Coreorafia(){

}

