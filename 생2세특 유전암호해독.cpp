#include<stdio.h>
#include<string.h>
char dna[101],rna[101];
char x1[100],x2[100],x3[100];
int i,j,k,a,c=0,d=0,e=0,v=0;
//예시 : AGACAACCGCCT , ACCAAACCGAGT , TACAGACAACCGCCT , TACCCGAGGTAG	
//우리 몸에서는 개시코돈이 있어야만 시작, 그 앞의 염기는 무시   
void AA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("라이신(Lys)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("아스파라진(Asn)// ");
	
}
void AG(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("아르지닌(Arg)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("세린(Ser)// ");

	
}
void AC(int i){
	printf("트레오닌(Thr)// ");
	
}
void AU(int i){
		if(x3[i]=='G')printf("메싸이오닌(Met)*개시// ");
		else printf("아이소류신(Ile)// ");
}//A
void GA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("글루탐산(Glu)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("아스파트산(Asp)// ");

	
}
void GG(int i){
	printf("글리신(Gly)// ");
}
void GC(int i){
	printf("알라닌(Ala)// ");
}
void GU(int i){
	printf("발린(Val)// ");
	
}//G
void CA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("글루타민(Gln)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("히스티딘 (His)// ");

	
}
void CG(int i){
	printf("아르지닌(Arg)// ");
}
void CC(int i){
	printf("프롤린(Pro)// ");
	
}
void CU(int i){
	printf("류신(Leu)// ");
	
}//C
void UA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("종결코돈// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("타이로신(Tyr)// ");
	
}
void UG(int i){
		if(x3[i]=='A')printf("종결코돈// ");
		else if(x3[i]=='G')printf("트립토판(Trp)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("시스테인(Cys)// ");
	
}
void UC(int i){
	printf("세린(Ser)// ");
	
}
void UU(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("류신(Leu)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("페닌알라닌(Phe)// ");
	
	
}//U
int main(){
	//DNA RNA변환(전사) 

	scanf("%s",&dna);
	a=strlen(dna);
	
	for(i=0; i<a; i++){
		if(dna[i]=='T')rna[i]='A';
		else if(dna[i]=='A')rna[i]='U';
		else if(dna[i]=='G')rna[i]='C';
		else if(dna[i]=='C')rna[i]='G';
	}
	printf("mRNA : %s\n",rna); 
	for(i=0; i<a; i++){
		if(i%3==0){
			x1[c]=rna[i];
			c++;	
		}
		else if(i%3==1){
			x2[d]=rna[i];
			d++;	
		}
		else if(i%3==2){
			x3[e]=rna[i];
			e++;	
		}
		
	}//첫번째,두번째, 세번째 염기 나눠서 저장한뒤에 세로로 맞춰서 void함수로 이동함.
//번역
for(i=0; i<=c; i++){
	if(x1[i]=='A'&&x2[i]=='U'&&x3[i]=='G'){
		v=i;
		
	
for(i=v; i<=c; i++){
	if(x1[i]=='A'){
		if(x2[i]=='A')AA(i);
		else if(x2[i]=='G')AG(i);
		else if(x2[i]=='C')AC(i);
		else if(x2[i]=='U')AU(i);
		}
	else if(x1[i]=='G'){
		if(x2[i]=='A')GA(i);
		else if(x2[i]=='G')GG(i);
		else if(x2[i]=='C')GC(i);
		else if(x2[i]=='U')GU(i);
		}
	else if(x1[i]=='C'){
		if(x2[i]=='A')CA(i);
		else if(x2[i]=='G')CG(i);
		else if(x2[i]=='C')CC(i);
		else if(x2[i]=='U')CU(i);
		}
	else if(x1[i]=='U'){
		if(x2[i]=='A')UA(i);
		else if(x2[i]=='G')UG(i);
		else if(x2[i]=='C')UC(i);
		else if(x2[i]=='U')UU(i);
		}
			}
	}
	else v=-1;
}	
if(v==-1)printf("*개시코돈이 없습니다*");			
	return 0;
}



