#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	
	int you, I;
	srand(time(NULL));
	while(1){
	
	you=(rand()%3+1);
	printf("*1�� ����/2�� ����/3�� ��\n");
	scanf("%d",&I); 
	if(I==1||I==2||I==3){//
		if(you==I){
		printf("<<���º�>>\n*�ٽõ����ϼ���*\n");
		printf("��ǻ��:%d\n\n",you); 		
	}	
	else if(I==1&&you==2||you==3&&I==2||you==1&&I==3){
		printf("<<��>>\n");
		printf("��ǻ��:%d\n\n",you); 
	}
	else {
		printf("<<��>>\n");
		printf("��ǻ��:%d\n\n",you); 
		break; 
	}
	}//
	else printf("1,2,3�߿����� �Է����ּ���\n\n");//
	
	} 
	
	return 0;
}
