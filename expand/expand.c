#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int main(int argc, char **argv){
	if(argc != 2){
		printf("Jumlah argumen tidak sesuai.\n");
		exit();
	}
	int fp = open(1, argv[1], O_RDONLY);
	if(fp < 0){
		printf(1, "%s tidak ditemukan.\n", argv[1]);
		exit();
	}
	char buf[1000];
	read(fp, buf, sizeof(buf));
	int lf = strlen(buf);
	int k;
	for(k=0;k<lf;k++){
		if(buf[k] != '\t')printf(1, "%c", buf[k]);
		else printf(1, "        ");
	}
	exit();
}
