#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>



#include <iostream>

using namespace cv;
using namespace std;
	
VideoCapture capture = VideoCapture(0); 
Mat frame;
Mat frameVermelho;
int i,j,k;

int campos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int thresholds[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int maiorThreshold = -1;
bool terminou = false;
int bitsVer = 0;


int main( int argc, char** argv ) {
	cout << "\nComecou!\n---------------------------------------------------------" << endl;

	
	if (!capture.isOpened()) // Caso falhe em iniciar webam
	{
		return 1;
	}
	
	while (terminou != true) {
		
		capture >> frame;
		if(frame.empty()){
			break;
		}
		if(waitKey(10) >= 0){
			break;
		}

		//Verificando os campos de sleção, se caso todos já estiverem alocados pode fechar o jogo
		terminou = true;

		for (i = 0; i < 9; i++) {
		
			if (campos[i] == 0) {
				terminou = false;
				i = 9;
			}

		}

		cv::inRange(frame, cv::Scalar(3, 3, 100), cv::Scalar(40, 40, 255), frameVermelho);

		imshow("vermelho", frameVermelho);

		
		// Zera thresholds
		thresholds[0] = 0;
		thresholds[1] = 0;
		thresholds[2] = 0;
		thresholds[3] = 0;
		thresholds[4] = 0;
		thresholds[5] = 0;
		thresholds[6] = 0;
		thresholds[7] = 0;
		thresholds[8] = 0;

		// Calcula thresholds - Vericifar objeto vermelho em cadas espaço
		for(i=0;i<frame.rows;i++) 
			for(j=0;j<frame.cols;j++) {
			//for(k=0;k<channels;k++) {
				uchar* temp_ptr_thresh = &((uchar*)(frameVermelho.data + frameVermelho.step*i))[j];				
				if(temp_ptr_thresh[0] == 255) {
					cout << "objeto vermelho em" << i << "," << j <<endl;
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
		// Escolhe o maior threshold
		int guardaThresh = 50;  // Minimo threshold aceito (evita que outros objetos nao vermelhos sejam aceitos)
		for (i=0; i < 9; i++) {

			if (thresholds[i] > guardaThresh) {
				guardaThresh = thresholds[i];
				maiorThreshold = i;
			}

		}

		// Alocar espaço em que o objeto foi detectado
		if (maiorThreshold != -1) {
			
			if (campos[maiorThreshold] == 0) {
				campos[maiorThreshold] = 1;

			} else
				maiorThreshold = -1;

		}
		//Adicionar divisorias e colorir o espaço em que o objeto foi encontrado;
		for(i=0;i<frame.rows;i++) {
			for(j=0;j<frame.cols;j++) {
			//for(k=0;k<channels;k++) {
				uchar* temp_ptr = &((uchar*)(frame.data + frame.step*i))[j*3];
				
				if (((i > (frame.rows-10)/3) && (i < ((frame.rows-10)/3)+5)) ||
					((i > ((frame.rows-10)/3)*2) && (i < (((frame.rows-10)/3)*2)+5)) ||
					((j > (frame.cols-10)/3) && (j < ((frame.cols-10)/3)+5)) ||
					((j > ((frame.cols-10)/3)*2) && (j < (((frame.cols-10)/3)*2)+5))) {
					temp_ptr[0] = 234;
					temp_ptr[1] = 217;
					temp_ptr[2] = 153;   
				}

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
		imshow("webcam", frame);
	}
	
    return 0;

}
