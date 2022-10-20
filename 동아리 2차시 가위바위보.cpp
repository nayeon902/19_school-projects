#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	
	int you, I;
	srand(time(NULL));
	while(1){
	
	you=(rand()%3+1);
	printf("*1번 가위/2번 바위/3번 보\n");
	scanf("%d",&I); 
	if(I==1||I==2||I==3){//
		if(you==I){
		printf("<<무승부>>\n*다시도전하세요*\n");
		printf("컴퓨터:%d\n\n",you); 		
	}	
	else if(I==1&&you==2||you==3&&I==2||you==1&&I==3){
		printf("<<패>>\n");
		printf("컴퓨터:%d\n\n",you); 
	}
	else {
		printf("<<승>>\n");
		printf("컴퓨터:%d\n\n",you); 
		break; 
	}
	}//
	else printf("1,2,3중에서만 입력해주세요\n\n");//
	
	} 
	
	return 0;
}
