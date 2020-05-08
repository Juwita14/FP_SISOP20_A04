#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char **argv){
	if(argc != 3){
		printf(1, "Jumlah argumen tidak sesuai.\n");
		exit();
	}
	int f = 0;
	int fa = open(argv[1], O_RDONLY);
	if(fa < 0){
		printf(1, "%s tidak ditemukan.\n", argv[1]);
		exit();
	}
	int fb = open(argv[2], O_RDONLY);
	if(fb < 0){
		printf(1, "%s tidak ditemukan.\n", argv[2]);
		exit();
	}
	char bufa[1000], bufb[1000];
	read(fa, bufa, sizeof(bufa));
	read(fb, bufb, sizeof(bufb));
	int la = strlen(bufa), lb = strlen(bufb);
	int cba = 0, cbb = 0;
	while(1){
		int cla = 0, clb = 0;
		char linea[100], lineb[100];
		memset(linea, '\0', sizeof(linea));
		memset(lineb, '\0', sizeof(lineb));
		while(cba < la){
			if(bufa[cba] != '\n'){
				linea[cla] = bufa[cba];
				cla++;
				cba++;
			}
			else{
				cba++;
				break;
			}
		}
		while(cbb < lb){
			if(bufb[cbb] != '\n'){
				lineb[clb] = bufb[cbb];
				clb++;
				cbb++;
			}
			else{
				cbb++;
				break;
			}
		}
		if(strlen(linea) > 0){
			printf(1, "%s ", linea);
			f = 1;
		}
		if(strlen(lineb) > 0){
			printf(1, "%s", lineb);
			f = 1;
		}
		if(f){
			printf(1, "\n");
			f = 0;
		}
		else break;
	}
	exit();
}
