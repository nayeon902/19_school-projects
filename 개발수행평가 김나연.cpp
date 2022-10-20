#include<stdio.h>
#include <stdlib.h> 
int a[15],b[10];
void drawgame(){
	int c=1;
	printf("=====================================\n");
	printf("           징검다리 게임  \n");
	printf("=====================================\n");
	printf("*각 열에서 두가지 숫자중 하나를 골라 입력해주세요*\n");
	printf("\n");
	printf("-----------출발!!------------\n\n");
	for(int i=1; i<=5; i++){
		printf("■■■■■    ");
		printf("■■■■■\n");
		printf("■ %02d   ■    ",c);
		c++;
		printf("■ %02d   ■\n",c);
		printf("■■■■■    ");
		printf("■■■■■\n");
		printf("\n");
		c++;
	}
}
void out(){
	printf("탈락!\n");
	printf("======================\n");
	printf("내가 선택한 징검다리목록:");
	for(int i=1; i<=10; i++){
		if(a[i]!=0)printf("%d ",i);
			}
}
int main(){
	int i,n,c=1,c1=1,c2=2;
	drawgame();
	
	for(i=1; i<=5; i++){
		b[1]=(rand()%2)+1;//1,2중 하나 
		b[2]=(rand()%2)+3;//3,4중 하나
		b[3]=(rand()%2)+5;//5,6중 하나
		b[4]=(rand()%2)+7;//7,8중 하나
		b[5]=(rand()%2)+9;//9,10중 하나
		printf(" %d과 %d중 어느다리로 건너시겠습니까?\n",c1,c2);
		c1=c1+2; 
		c2=c2+2;
		scanf("%d",&n);
		a[n]=1;
		if(n==b[i]){
			out();		
			break;
		}
		else printf("<통과>\n"); 
		if(i==5&&n!=b[i]){
			printf("======================\n");
			printf("도착! 성공했습니다!!");	
			}
	}
	
	return 0;
}
