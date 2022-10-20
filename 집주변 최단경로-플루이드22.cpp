#include<stdio.h>
#include<stdlib.h>

#define Count 21
#define NONE 2000

//숫자 없는건 최소경로, 2는 최소신호등 구하는 플로이드 
int Wei[Count][Count]={
	{0,261,238,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
	{261,0,NONE,201,404,473,468,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
	{238,NONE,0,215,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
	{NONE,201,215,0,NONE,NONE,NONE,351,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
	{NONE,404,NONE,NONE,0,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,570,NONE,NONE},
 	{NONE,473,NONE,NONE,NONE,0,300,NONE,158,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,80,NONE,NONE },
 	{NONE,468,NONE,NONE,NONE,300,0,275,NONE,250,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
 	{NONE,NONE,NONE,351,NONE,NONE,275,0,NONE,NONE,405,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
 	{NONE,NONE,NONE,NONE,NONE,158,NONE,NONE,0,NONE,NONE,417,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
 	{NONE,NONE,NONE,NONE,NONE,NONE,250,NONE,NONE,0,NONE,NONE,NONE,483,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,405,NONE,NONE,0,NONE,NONE,NONE,NONE,452,NONE,NONE,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,417,NONE,NONE,0,355,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,355,0,NONE,288,NONE,NONE,NONE,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,483,NONE,NONE,NONE,0,90,NONE,NONE,367,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,288,90,0,NONE,NONE,NONE,NONE,NONE,370},
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,452,NONE,NONE,NONE,NONE,0,100,NONE,NONE,NONE,NONE},
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,100,0,130,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,367,NONE,NONE,NONE,0,NONE,NONE,50},
 	{NONE,NONE,NONE,NONE,570,80,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,160,NONE},
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,160,0,NONE},
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,370,NONE,NONE,50,NONE,NONE,0},


};
int Wei2[Count][Count]={
	{0,1,1,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
	{1,0,NONE,2,2,2,2,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
	{1,NONE,0,2,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
	{NONE,2,2,0,NONE,NONE,NONE,2,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
	{NONE,2,NONE,NONE,0,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,2,NONE,NONE},
  	{NONE,2,NONE,NONE,NONE,0,2,NONE,1,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,2,NONE,NONE},
  	{NONE,2,NONE,NONE,NONE,2,0,1,NONE,1,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
  	{NONE,NONE,NONE,2,NONE,NONE,1,0,NONE,NONE,0,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
  	{NONE,NONE,NONE,NONE,NONE,1,NONE,NONE,0,NONE,NONE,0,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE},
  	{NONE,NONE,NONE,NONE,NONE,NONE,1,NONE,NONE,0,NONE,NONE,NONE,0,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,NONE,NONE,0,NONE,NONE,NONE,NONE,2,NONE,NONE,NONE,NONE,NONE},
 	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,NONE,NONE,0,2,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE },
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,2,0,NONE,2,NONE,NONE,NONE,NONE,NONE,NONE },
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,NONE,NONE,NONE,0,1,NONE,NONE,0,NONE,NONE,NONE},
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,2,1,0,NONE,NONE,NONE,NONE,NONE,3},
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,2,NONE,NONE,NONE,NONE,0,0,NONE,NONE,NONE,NONE},
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,0,1,NONE,NONE,NONE },
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,NONE,NONE,NONE,0,NONE,NONE,1},
   	{NONE,NONE,NONE,NONE,2,2,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,0,1,NONE},
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,1,0,NONE},
  	{NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,NONE,3,NONE,NONE,1,NONE,NONE,0},
};

int MinD[Count][Count];
int Point[Count][Count]; 
int MinD2[Count][Count]; 
int Point2[Count][Count];
void graph(){
	int i,j;
	printf("[저장된 최소경로그래프]\n");
	printf("     %5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d\n",0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20);
	for(i=0; i<21; i++){
		printf("%5d",i);
		for(j=0; j<21; j++){
			if(Wei[i][j]==NONE)printf("%5s","oo");
			else printf("%5d",Wei[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("[저장된 최소신호등그래프]\n");
	printf("     %5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d\n",0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20);
	for(i=0; i<21; i++){
		printf("%5d",i);
		for(j=0; j<21; j++){
			if(Wei2[i][j]==NONE)printf("%5s","oo");
			else printf("%5d",Wei2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void Floyd(){
	int i, j, k;
	for(i=0; i < Count; i++) 
		for(j=0; j < Count; j++){
			Point[i][j] = -1;
			MinD[i][j] = Wei[i][j];
		}
	for(k=0; k < Count; k++)
		for(i=0; i < Count; i++)
			for(j=0; j < Count; j++)
				if(MinD[i][j] > MinD[i][k] + MinD[k][j]){
					MinD[i][j] = MinD[i][k] + MinD[k][j];
					Point[i][j] = k;
				}
}
void Floyd2(){
	int i, j, k;
	for(i=0; i < Count; i++) 
		for(j=0; j < Count; j++){
			Point2[i][j] = -1;
			MinD2[i][j] = Wei2[i][j];
		}
	for(k=0; k < Count; k++)
		for(i=0; i < Count; i++)
			for(j=0; j < Count; j++)
				if(MinD2[i][j] > MinD2[i][k] + MinD2[k][j]){
		
					MinD2[i][j] = MinD2[i][k] + MinD2[k][j];
					Point2[i][j] = k;
				}
}
char* name[21]={"집","구산육거리","구산고","이구삼거리","연지공원사거리","가야의거리","북부지역 아동센터","가야로교차로","국립김해박물관",
	"수로왕비릉","알뜰주유소","구봉초등학교","김해여중","김해여고","대성동사거리","가야-호계로교차로","호계로교차로1","호계로교차로2","김해문화의전당","홈플러스","혜성사거리"};
void Print(int a, int b){
	int T;
	if(Point[a][b] != -1) { 
		Print(a, Point[a][b]);
		T=Point[a][b];
		printf("%s(%d)__", name[T],Point[a][b]);
		Print(Point[a][b], b);
	}

}
void Print2(int a, int b){ 
	int T;
	if(Point2[a][b] != -1) { 
		Print2(a, Point2[a][b]);
		T=Point2[a][b];
		printf("[%s(%d)]__", name[T],Point2[a][b]);
		Print(Point2[a][b], b);
	}

}

int main(int argc,char*argv[]){
	graph();
	Floyd();
	Floyd2();
	int a, b;
	float res;
	int sin; 
	printf("*0:집\n*1:구산육거리\n*2:구산고\n*3:이구삼거리\n*4:연지공원사거리\n*5:가야의거리\n*6:북부지역아동센터\n*7:가야로교차로\n*8:국립김해박물관\n*9:수로왕비릉\n*10:알뜰주유소\n*11:구봉초등학교\n*12:김해여중\n*13:김해여고\n*14:대성동사거리\n*15:갸야-호계로교차로5\n*16:호계로교차로1\n*17:호계로교차로2\n*18:김해문화의전당\n*19:홈플러스\n*20:혜성사거리");
	printf("\n\n출발점과 도착점을 입력하세요. (0 ~ %d)\n", Count - 1);
	scanf("%d %d", &a, &b);
	res= float(MinD[a][b])/1000;
	sin=MinD2[a][b]; 
	printf("\n최단거리 : %.3f km\n", res);
	printf("최단경로 : ");
	printf("[%s(%d)]__ ", name[a],a); 
	Print(a, b);

	if(MinD[a][b] != 0) printf("[%s(%d)]", name[b],b); 
	
	printf("\n\n최소신호등개수: %d \n", sin);
	printf("최소신호등경로 : ");
	printf("[%s(%d)]__ ", name[a],a); 
	Print2(a, b);
	if(MinD2[a][b] != 0) printf("[%s(%d)]", name[b],b); 
	
	
	return 0;
}

