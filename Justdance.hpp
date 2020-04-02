#pragma once
#include "Coreografia.hpp"
#include "IdentificadorObjetoIndicador.hpp"
#include <fstream>
#include <iostream>
int seq = 1;
int maiorThreshold1 = -1;
int maiorThreshold2 = -1 ;
class Justdance
{
    private:
        /* data */
    public:
        int campos[8];
        int thresholds[8];
        
        int pontos;
        Coreografia coreograf;
        IdentificadorObjetoIndicador identificador;
        bool terminou;
        int i,j;

        Justdance(){}
        Justdance(Coreografia coreograf, IdentificadorObjetoIndicador identificador){
            for (i = 0; i < 9; i++) {
                this->campos[i] = 0;
                this->thresholds[i] = 0;
            }
            this->pontos = 0;
            this->coreograf = coreograf;
            this->identificador = identificador;
            this->terminou = false;
        }
       
        ~Justdance(){}

        void verificarAlocacaoDeObjeto(){

            // Escolhe os dois maiores thresholds 
            int guardaThresh1 = 60;  // Minimo threshold aceito (evita que outros objetos nao vermelhos sejam aceitos)
            int guardaThresh2 = 60;  // Minimo threshold aceito (evita que outros objetos nao vermelhos sejam aceitos)
            maiorThreshold1 = -1;
            maiorThreshold2 = -1;
            for (i=0; i < 9; i++) {

                if (thresholds[i] > guardaThresh1) {
                    guardaThresh1 = thresholds[i];
                    maiorThreshold1 = i;
                }

            }

            for (i=0; i < 9; i++) {
                if ((i != maiorThreshold1) && (maiorThreshold1 != -1)){
                    if (thresholds[i] > guardaThresh2) {
                        guardaThresh2 = thresholds[i];
                        maiorThreshold2 = i;
                    }
                }

            }
            if ( coreograf.passosMus[seq]  == 8 ){
                campos[8] = 1 ;
            }
            cout << maiorThreshold1 << " - " << maiorThreshold2 <<  " 8 = " << campos[maiorThreshold1] << endl;
            // Alocar espaço em que o objeto foi detectado
            if ((maiorThreshold1 != -1) && (maiorThreshold2 != -1) && (campos[maiorThreshold1] == 1) && (campos[maiorThreshold2] ==1)){
                    pontos+= 100;
                    identificador.pintarVerde(campos);
                    seq += 2;		

            }
            else if((maiorThreshold1 != -1) && (campos[maiorThreshold1] == 1 )){
                for (i = 0; i < 9; i++) {
                    if (i != maiorThreshold1)
                    {
                        campos[i] = 0;
                    }
                }
                identificador.pintarVerde(campos);
                pontos -= 1;
            }
            else {
                //Zerar campos 
                for (i = 0; i < 9; i++) {
                    campos[i] = 0;
                }
            }
            imshow("webcam", identificador.frame);

        }
        void play(){
            
            while (terminou != true) {
                
                identificador.capture >> identificador.frame;

                if(identificador.frame.empty()){ //Caso frame não tenha elementos 
                    break;
                }
                if(waitKey(10) >= 0){
                    break;
                }

                identificador.filtrarFrameVermelho();

                //Adicionar divisorias e pinta o espaço em que o objeto deve ser encontrado de azul;
                identificador.pintarAzul(campos,coreograf.passosMus,seq);
                /* Procurar objetos vermelhos e salvar em quais quadrados eles se encontram */

                // Calcula thresholds - Vericifar objeto vermelho em cadas espaço
                identificador.buscarObjetoVermelho(thresholds);

                //verificar objeto no devido local definido

                verificarAlocacaoDeObjeto();
                //Verificar se terminou
                
                if (campos[4] == 1) {
                    terminou = true;
                }

            }

        }
        
        int ranking(){
            fstream stream;
            int pontosArquivo = 0;

            stream.open("ranking.txt", ios::in);
            if (!stream.is_open()) {
                cout << "Nao foi possivel abrir o arquivo para leitura" << endl;
            }

            if (!stream.eof() && !stream.bad() && !stream.fail()){
                stream >> pontosArquivo;
            }
            
            stream.close();
            if (pontos > pontosArquivo){
                stream.open("ranking.txt", ios::out);
                if (!stream.is_open()) {
                    cout << "Nao foi possivel abrir o arquivo para escrita" << endl;
                }
                stream << pontos;
                stream.close();
            }
            return pontosArquivo;
        }
};
