#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <unistd.h>
<<<<<<< HEAD
#include <stdlib.h>
#include <thread> 
=======
>>>>>>> 5751c6af1c346ad1b37c68a9b867221436b1d307

using namespace cv;
using namespace std;

VideoCapture capture = VideoCapture(0); 
Mat frame;
Mat frameVermelho;
int i,j,k;
int campos[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int thresholds[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int passosMus1[] = {0,8,2,6,3,5,3,5,1,7,0,8,4,4}; //Quantidade par e terminar em 44
int maiorThreshold1 = -1;
int maiorThreshold2 = -1;
bool terminou = false;
int pontos = 0;
int seq = 1;

<<<<<<< HEAD
void musica() { system("/home/louise/Justdance/play.txt"); }

=======
>>>>>>> 5751c6af1c346ad1b37c68a9b867221436b1d307
void pintarVerde(){
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
<<<<<<< HEAD

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

=======

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

>>>>>>> 5751c6af1c346ad1b37c68a9b867221436b1d307
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

int main( int argc, char** argv ) {
	thread first = thread(musica); 

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

		cv::inRange(frame, cv::Scalar(3, 3, 100), cv::Scalar(40, 40, 255), frameVermelho);

		imshow("vermelho", frameVermelho);
		//Zerar campos 
		for (i = 0; i < 9; i++) {
			campos[i] = 0;
		}
		//Definir campos que devem receber objeto
		campos[passosMus1[seq-1]] = 1;
		campos[passosMus1[seq]] = 1;

		//Adicionar divisorias e colorir o espaço em que o objeto deve ser encontrado de azul;
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

		/* Procurar objetos vermelhos e salvar em quais quadrados eles se encontram */
		// Zera thresholds
		for (i = 0; i < 9; i++) {
			thresholds[i] = 0;
		}

		// Calcula thresholds - Vericifar objeto vermelho em cadas espaço
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

		// Alocar espaço em que o objeto foi detectado
		if ((maiorThreshold1 != -1) && (maiorThreshold2 != -1) && (campos[maiorThreshold1] == 1) && (campos[maiorThreshold2] ==1)){
				pontos+= 100;
				pintarVerde();
				seq += 2;		

		}
<<<<<<< HEAD
		else if((maiorThreshold1 != -1 && (campos[maiorThreshold1] == 1 ))){
=======
		else if((maiorThreshold1 != 0) && (campos[maiorThreshold1] == 1 )){
>>>>>>> 5751c6af1c346ad1b37c68a9b867221436b1d307
			for (i = 0; i < 9; i++) {
				if (i != maiorThreshold1)
				{
					campos[i] = 0;
				}
			}
			pintarVerde();
			pontos -= 1;
		}
		else {
			//Zerar campos 
			for (i = 0; i < 9; i++) {
				campos[i] = 0;
			}
		}
		imshow("webcam", frame);
		//Verificar se terminou
		
		if (campos[4] == 1) {
			terminou = true;
		}

	}
<<<<<<< HEAD
	first.join(); 
=======
>>>>>>> 5751c6af1c346ad1b37c68a9b867221436b1d307
	cout << "Sua pontuação foi " << pontos << endl;
    return 0;

}