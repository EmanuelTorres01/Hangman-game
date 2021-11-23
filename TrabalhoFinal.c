#include<stdio.h>
#include<conio.h>
char chute();
void tentativaChute(char chute, char palavra[]);
int incrementoForca(int x);
char continuarJogo(char testePalavra, char palavra[]);
void principal();
char palavra[25], tema[25], letra, tentativa[25], continuar, testePalavra, espaco[25];
int x, tamanhoTema, tamanhoPalavra, controle, forca;
main(){
	principal();
}
void principal(){
	forca = 0;
	system("color 03");
	//Leitor e Validador de Tema
	do{
		puts("Informe o tema da palavra:");
		fflush(stdin);
		gets(tema);
		tamanhoTema = strlen(tema);
		if(tamanhoTema>25)
			puts("O tema ultrapassou o limite de caracter!");
	}while(tamanhoTema>25);
	
	//Leitor e Validador da Palavra
	do{
		puts("Informe a palavra para iniciar o jogo:");
		fflush(stdin);
		gets(palavra);
		tamanhoPalavra = strlen(palavra);

		for(x=0; x<tamanhoPalavra; x++)
			palavra[x] = toupper(palavra[x]);
				
		if(tamanhoPalavra>25)
			puts("A palavra ultrapassou o limete de caracter!");
				
		if(tamanhoPalavra<3)
			printf("A palavra deve ter no m%cnimo 3 caracteres!\n", 161);
				
	}while(tamanhoPalavra>25 || tamanhoPalavra<3);

	//Inicio do Jogo
	for(x=0;x<tamanhoPalavra;x++)
		espaco[x]='_';

	do{
		system("cls");
		printf("Tema: %s\n",tema);
		printf("Palavra: %s", espaco);
	
		forca = incrementoForca(forca);
		testePalavra=chute();
		
		continuar = continuarJogo(testePalavra, palavra);
		
		if(continuar=='N' && testePalavra=='S')
			return 0;
		if(continuar=='S'){
			system("color 00");
			principal();
			return 0;
		}
			
		printf("\nInforme a letra que deseja!\n");
		letra=getche();
		letra=toupper(letra);
		controle = 1;
		for(x=0; x<tamanhoPalavra; x++){
			if(palavra[x] == letra){
				controle = 0;
				espaco[x]=letra;
			}
		}
		if(controle == 1)
			forca++;
			
		system("cls");
		printf("Tema: %s\n",tema);
		printf("Palavra: %s", espaco);
		
		forca = incrementoForca(forca);
	}while(forca<6 && strcmp(palavra, espaco)!=0);
	
	if(strcmp(palavra, espaco)==0)
		system("color 02");
		printf("\nPARAB%cNS, VOC%c VENCEU!\n",144, 210);
		
	if(forca==6)
		system("color 04");
		printf("VOC%c PERDEU! TENTE NOVAMENTE.\n", 210);
		
	printf("Deseja jogar de novo?\n");
	continuar=getche();
	continuar=toupper(continuar);
	system("cls");
	
	if(continuar=='N' && testePalavra=='S')
		return 0;
	if(continuar=='S'){	
		system("color 15");
		principal();
		return 0;
	}
}

char chute(){
	char chute;
	do{
		puts("\nDeseja tentar adivinhar a palavra toda?");
		chute = getche();
		chute = toupper(chute);
		if(chute!='S' && chute!='N')
			printf("\nUse S para sim e N para n%co!", 198);
	}while(chute!='S' && chute!='N');
	return chute;
}

void tentativaChute(char chute, char palavra[]){
	char tentativa[25];
	int tamanhoTentativa, i;
	if (chute=='S'){
		printf("Informe a sua tentativa:\n");
		fflush(stdin);
		gets(tentativa);
		tamanhoTentativa = strlen(tentativa);
		for(i=0; i<tamanhoTentativa; i++){
			tentativa[i] = toupper(tentativa[i]);
		}
	}
	if(strcmp(tentativa, palavra)==0){
		system("color 02");
		printf("PARAB%cNS, VOC%c VENCEU!\n",144, 210);
	}
	else
		printf("VOC%c PERDEU! TENTE NOVAMENTE.\n", 210);
}

int incrementoForca(int x){
	switch (x){
		case 0: printf("\n%c%c%c%c\n%c \n%c\n%c\n%c",218 , 196, 196, 191, 179, 179, 179, 193);
			break;
		case 1: printf("\n%c%c%c%c\n%c  O\n%c\n%c\n%c",218 , 196, 196, 191, 179, 179, 179, 193);
			break;
		case 2: printf("\n%c%c%c%c\n%c  O\n%c  |\n%c\n%c",218 , 196, 196, 191, 179, 179, 179, 193);
			break;
		case 3: printf("\n%c%c%c%c\n%c  O\n%c /|\n%c\n%c",218 , 196, 196, 191, 179, 179, 179, 193);
			break;
		case 4: printf("\n%c%c%c%c\n%c  O\n%c /|%c \n%c\n%c",218 , 196, 196, 191, 179, 179, 92, 179, 193);
			break;
		case 5: printf("\n%c%c%c%c\n%c  O\n%c /|%c \n%c /\n%c\n",218 , 196, 196, 191, 179, 179, 92, 179, 193);
			break;
		case 6: printf("\n%c%c%c%c\n%c  O\n%c /|%c \n%c / %c\n%c\n",218 , 196, 196, 191, 179, 179, 92, 179, 92, 193);
			break;
	}
	return x;
}

char continuarJogo(char testePalavra, char palavra[]){
	char continuar;
	if(testePalavra=='S'){
		tentativaChute(testePalavra, palavra);
		printf("Deseja jogar de novo?\n");
		continuar=getche();
		continuar=toupper(continuar);
		system("cls");
	}
	return continuar;
}
