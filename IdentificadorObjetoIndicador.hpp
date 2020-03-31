#pragma once
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>

using namespace cv;
using namespace std;
	

class IdentificadorObjetoIndicador{
    public:
	    VideoCapture capture;
        Mat frame, frameVermelho;
		int i,j;
		
        IdentificadorObjetoIndicador(){}
        IdentificadorObjetoIndicador(VideoCapture capture, Mat frame, Mat frameVermelho){
            this->capture = capture;
            this->frame = frame;
            this->frameVermelho = frameVermelho;
        }
        virtual ~IdentificadorObjetoIndicador(){}
       /* void pintarVerde();
        void pintarAzul(int array[], int passosMus[], int sequencia);
        void filtrarFrameVermelho(int thresholds[]);
        void buscarObjetoVermelho();
		*/




	//Adiciona bordas verdes quando o objeto foi encontrado no campo = 1, referente ao local que deveria está 
	void pintarVerde(int campos[]){
		//mudar cor para verde 
		for(i=0;i<frame.rows;i++) {
			for(j=0;j<frame.cols;j++) {
			//for(k=0;k<channels;k++) {
				uchar* temp_ptr = &((uchar*)(frame.data + frame.step*i))[j*3];
				
				/*if (((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) ||
					((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5)) ||
					((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) ||
					((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5))) {
					temp_ptr[0] = 234;
					temp_ptr[1] = 217;
					temp_ptr[2] = 153;   
				}*/

				if (campos[0] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j < ((frame.cols-10)/3)+5)) || 
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&(i <= (frame.rows-10)/3))) {
					
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;  
					
						
					}

				}

				if (campos[1] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&(i <= (frame.rows-10)/3))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i <= (frame.rows-10)/3)))){
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				}

				if (campos[2] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j > ((frame.cols-10)/3)*2)) || 
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i <= (frame.rows-10)/3)))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				} 

				if (campos[3] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j < ((frame.cols-10)/3)+5))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5)))||
						(((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j < ((frame.cols-10)/3)+5))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				}

				if (campos[4] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5)))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5))))||
						(((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				}

				if (campos[5] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j > ((frame.cols-10)/3)*2)) || 
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5))))||
						(((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j > ((frame.cols-10)/3)*2))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				}

				if (campos[6] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j < ((frame.cols-10)/3)+5))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) && (i > ((frame.rows-10)/3)*2))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				} 
				if (campos[7] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&(i > ((frame.rows-10)/3)*2))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i > ((frame.rows-10)/3)*2)))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				}

				if (campos[8] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j > ((frame.cols-10)/3)*2))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i > ((frame.rows-10)/3)*2)))) {
						temp_ptr[0] = 0;
						temp_ptr[1] = 255;
						temp_ptr[2] = 0;   
					}

				}
				
			}
		}
	}

	//Adicionar divisorias e pinta o espaço em que o objeto deve ser encontrado de azul;
	void pintarAzul(int campos[], int passosMus[], int seq){
		//Zerar campos 
		for (i = 0; i < 9; i++) {
			campos[i] = 0;
		}
		//Definir campos que devem receber objeto e ser pintado de azul
		campos[passosMus[seq-1]] = 1;
		campos[passosMus[seq]] = 1;

		for(i=0;i<frame.rows;i++) {
			for(j=0;j<frame.cols;j++) {
				uchar* temp_ptr = &((uchar*)(frame.data + frame.step*i))[j*3];
				
				/*if (((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) ||
					((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5)) ||
					((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) ||
					((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5))) {
					temp_ptr[0] = 234;
					temp_ptr[1] = 217;
					temp_ptr[2] = 153;   
				}*/

				if (campos[0] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j < ((frame.cols-10)/3)+5)) || 
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&(i <= (frame.rows-10)/3))) {
					
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;  
					
							
					}

				}

				if (campos[1] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&(i <= (frame.rows-10)/3))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i <= (frame.rows-10)/3)))){
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				}

				if (campos[2] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j > ((frame.cols-10)/3)*2)) || 
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i <= (frame.rows-10)/3)))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				} 

				if (campos[3] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j < ((frame.cols-10)/3)+5))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5)))||
						(((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j < ((frame.cols-10)/3)+5))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				}

				if (campos[4] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5)))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5))))||
						(((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				}

				if (campos[5] == 1) {
					
					if ((((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) && (j > ((frame.cols-10)/3)*2)) || 
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&((i > (frame.rows-10)/3) && (i < (((frame.rows-10)/3)*2)+5))))||
						(((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j > ((frame.cols-10)/3)*2))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				}

				if (campos[6] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j < ((frame.cols-10)/3)+5))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) && (i > ((frame.rows-10)/3)*2))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				} 
				if (campos[7] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&((j > (frame.cols-10)/3)&&((j < (((frame.cols-10)/3)*2)+5))))||
						(((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) &&(i > ((frame.rows-10)/3)*2))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i > ((frame.rows-10)/3)*2)))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				}

				if (campos[8] == 1) {
					
					if ((((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5))&&(j > ((frame.cols-10)/3)*2))||
						(((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5) &&(i > ((frame.rows-10)/3)*2)))) {
						temp_ptr[0] = 234;
						temp_ptr[1] = 217;
						temp_ptr[2] = 153;   
					}

				}
				
			}
		}
	}

	//Filtra a matriz frame par um frame vermelho
	void filtrarFrameVermelho(){
		cv::inRange(frame, cv::Scalar(3, 3, 100), cv::Scalar(40, 40, 255), frameVermelho);
		imshow("vermelho", frameVermelho);
	}

	//Verifica em que possuição está o objeto vermelho 
	void buscarObjetoVermelho(int thresholds[]){
		// Zera thresholds
		for (i = 0; i < 9; i++) {
			thresholds[i] = 0;
		}
		for(i=0;i<frame.rows;i++){
			for(j=0;j<frame.cols;j++) {
			//for(k=0;k<channels;k++) {
				uchar* temp_ptr_thresh = &((uchar*)(frameVermelho.data + frameVermelho.step*i))[j];				
				if(temp_ptr_thresh[0] == 255) {
					if ((i < (frame.rows-10)/3) && (j < ((frame.cols-10)/3))) {
						thresholds[0]++;
					} else if (i < (frame.rows-10)/3 && j > ((frame.cols-10)/3)+5 && j < ((frame.cols-10)/3)*2) {
						thresholds[1]++;
					} else if (i < (frame.rows-10)/3 && j > (((frame.cols-10)/3)*2)+5) {
						thresholds[2]++;
					} else if (i > ((frame.rows-10)/3)+5 && i < ((frame.rows-10)/3)*2 && j < ((frame.cols-10)/3)) {
						thresholds[3]++;
					} else if (i > ((frame.rows-10)/3)+5 && i < ((frame.rows-10)/3)*2 && j > ((frame.cols-10)/3)+5 && j < ((frame.cols-10)/3)*2) {
						thresholds[4]++;
					} else if (i > ((frame.rows-10)/3)+5 && i < ((frame.rows-10)/3)*2 && j > (((frame.cols-10)/3)*2)+5) {
						thresholds[5]++;
					} else if (i > (((frame.rows-10)/3)*2)+5 && j < ((frame.cols-10)/3)) {
						thresholds[6]++;
					} else if (i > (((frame.rows-10)/3)*2)+5 && j > ((frame.cols-10)/3)+5 && j < ((frame.cols-10)/3)*2) {
						thresholds[7]++;
					} else if (i > (((frame.rows-10)/3)*2)+5 && j > (((frame.cols-10)/3)*2)+5) {
						thresholds[8]++;
					}

				}

			}
		}
	}
};