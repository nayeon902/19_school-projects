#include<stdio.h>
#include <stdlib.h> 
int a[15],b[10];
void drawgame(){
	int c=1;
	printf("=====================================\n");
	printf("           ¡�˴ٸ� ����  \n");
	printf("=====================================\n");
	printf("*�� ������ �ΰ��� ������ �ϳ��� ��� �Է����ּ���*\n");
	printf("\n");
	printf("-----------���!!------------\n\n");
	for(int i=1; i<=5; i++){
		printf("������    ");
		printf("������\n");
		printf("�� %02d   ��    ",c);
		c++;
		printf("�� %02d   ��\n",c);
		printf("������    ");
		printf("������\n");
		printf("\n");
		c++;
	}
}
void out(){
	printf("Ż��!\n");
	printf("======================\n");
	printf("���� ������ ¡�˴ٸ����:");
	for(int i=1; i<=10; i++){
		if(a[i]!=0)printf("%d ",i);
			}
}
int main(){
	int i,n,c=1,c1=1,c2=2;
	drawgame();
	
	for(i=1; i<=5; i++){
		b[1]=(rand()%2)+1;//1,2�� �ϳ� 
		b[2]=(rand()%2)+3;//3,4�� �ϳ�
		b[3]=(rand()%2)+5;//5,6�� �ϳ�
		b[4]=(rand()%2)+7;//7,8�� �ϳ�
		b[5]=(rand()%2)+9;//9,10�� �ϳ�
		printf(" %d�� %d�� ����ٸ��� �ǳʽðڽ��ϱ�?\n",c1,c2);
		c1=c1+2; 
		c2=c2+2;
		scanf("%d",&n);
		a[n]=1;
		if(n==b[i]){
			out();		
			break;
		}
		else printf("<���>\n"); 
		if(i==5&&n!=b[i]){
			printf("======================\n");
			printf("����! �����߽��ϴ�!!");	
			}
	}
	
	return 0;
}
