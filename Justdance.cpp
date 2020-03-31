#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/videoio.hpp>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <thread> 
#include "IdentificadorObjetoIndicador.hpp"
#include "Coreografia.hpp"
#include "Justdance.hpp"
int op = 0;

using namespace cv;
using namespace std;
	
VideoCapture capture = VideoCapture(0); 
Mat frame;
int passosMus1[] = {0,5,2,6,3,5,3,5,1,7,0,8,4,4}; //Quantidade par e terminar em 44
void musica() { 
	
	while(op==0){
	
	}
	switch (op)
	{
	case 1:
		system("/home/mirele/Documentos/Projetos/Justdance/play.txt"); 
		break;
	case 2:
		system("/home/mirele/Documentos/Projetos/Justdance/play2.txt");
		break;
	
	default:
		break;
	}
	
}

void exibeMenu(){
            printf("\n\n\t\t________________________Escolha sua música: ____________________\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t|\t\t\t1 - Bad Romance -  Lady Gaga\t\t\t|\n"
            "\t\t|\t\t\t2 - Just Dance - Lady Gaga\t\t\t\t|\n"
			"\t\t|\t\t\t\t\t\t\t\t|\n"
			"\n\n\t\t________________________Sair do programa: ____________________\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t|\t\t\t3 - Fechar \t\t\t\t|\n"
            "\t\t|\t\t\t\t\t\t\t\t|\n"
            "\t\t-----------------------------------------------------------------\n\n");
}

int main( int argc, char** argv ) {

	 
	//Testando classes
	IdentificadorObjetoIndicador id = IdentificadorObjetoIndicador(capture);
	Coreografia co = Coreografia("caminhoMusica",passosMus1);
	Justdance jus = Justdance(co,id);

	thread first = thread(musica);
	while(1){

		exibeMenu();
		cout << "\t >>> Digite uma opcao: ";
        cin >> op;

		if(op==3){
			break;
		}

		cout << "\nComecou!\n---------------------------------------------------------" << endl;
		if (!id.capture.isOpened()) // Caso falhe em iniciar webcam
		{
			return 1;
		}
		
		//inicia o justdance
		jus.play();
		first.join(); 
		cout << "Sua pontuação foi " << jus.pontos << endl;

	}
	

    return 0;

}