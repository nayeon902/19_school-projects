#include<stdio.h>
#include<string.h>
char dna[101],rna[101];
char x1[100],x2[100],x3[100];
int i,j,k,a,c=0,d=0,e=0,v=0;
//���� : AGACAACCGCCT , ACCAAACCGAGT , TACAGACAACCGCCT , TACCCGAGGTAG	
//�츮 �������� �����ڵ��� �־�߸� ����, �� ���� ����� ����   
void AA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("���̽�(Lys)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("�ƽ��Ķ���(Asn)// ");
	
}
void AG(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("�Ƹ�����(Arg)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("����(Ser)// ");

	
}
void AC(int i){
	printf("Ʈ������(Thr)// ");
	
}
void AU(int i){
		if(x3[i]=='G')printf("�޽��̿���(Met)*����// ");
		else printf("���̼ҷ���(Ile)// ");
}//A
void GA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("�۷�Ž��(Glu)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("�ƽ���Ʈ��(Asp)// ");

	
}
void GG(int i){
	printf("�۸���(Gly)// ");
}
void GC(int i){
	printf("�˶��(Ala)// ");
}
void GU(int i){
	printf("�߸�(Val)// ");
	
}//G
void CA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("�۷�Ÿ��(Gln)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("����Ƽ�� (His)// ");

	
}
void CG(int i){
	printf("�Ƹ�����(Arg)// ");
}
void CC(int i){
	printf("���Ѹ�(Pro)// ");
	
}
void CU(int i){
	printf("����(Leu)// ");
	
}//C
void UA(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("�����ڵ�// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("Ÿ�̷ν�(Tyr)// ");
	
}
void UG(int i){
		if(x3[i]=='A')printf("�����ڵ�// ");
		else if(x3[i]=='G')printf("Ʈ������(Trp)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("�ý�����(Cys)// ");
	
}
void UC(int i){
	printf("����(Ser)// ");
	
}
void UU(int i){
		if(x3[i]=='A'||x3[i]=='G')printf("����(Leu)// ");
		else if(x3[i]=='C'||x3[i]=='U')printf("��Ѿ˶��(Phe)// ");
	
	
}//U
int main(){
	//DNA RNA��ȯ(����) 

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
		
	}//ù��°,�ι�°, ����° ���� ������ �����ѵڿ� ���η� ���缭 void�Լ��� �̵���.
//����
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
if(v==-1)printf("*�����ڵ��� �����ϴ�*");			
	return 0;
}



