#include<stdio.h>
int main(){
	//ppm��, �ۼ�Ʈ��, ������ ��� 
	float per, ppm, mol,m, a, b, c,a1;
	//a=������ ����(g), b=����� ����(g), c=����� ����(kg);
	printf("������ ����(g)/����� ����(g)�� ���ʴ�� �Է��Ͻÿ�: ");
	scanf("%f %f", &a,&b);
	c=(b-a)*0.001;
	per=(a/b)*100;
	ppm=(a/b)*1000000; 
	printf("\n�ۼ�Ʈ��: %.2f %%\n",per); //�ۼ�Ʈ�� �� 
	printf("ppm��: %.2f ppm\n\n",ppm); //ppm�� 
	
	printf("�����󵵸� ���ϰ� ������ ������ ���ڷ��� �Է��Ͻÿ�(�ǳʶٰ������ 0�Է�): ");
	scanf("%f",&a1);
	if(a1!=0){
		mol=a/a1;
		m=mol/c;
		printf("������: %.2f m\n",m); //������	
	}
	
	return 0;
}
