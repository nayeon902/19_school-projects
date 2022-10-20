#include<stdio.h>
int main(){
	//ppm농도, 퍼센트농도, 몰랄농도 계산 
	float per, ppm, mol,m, a, b, c,a1;
	//a=용질의 질량(g), b=용액의 질량(g), c=용매의 질량(kg);
	printf("용질의 질량(g)/용액의 질량(g)을 차례대로 입력하시오: ");
	scanf("%f %f", &a,&b);
	c=(b-a)*0.001;
	per=(a/b)*100;
	ppm=(a/b)*1000000; 
	printf("\n퍼센트농도: %.2f %%\n",per); //퍼센트농 도 
	printf("ppm농도: %.2f ppm\n\n",ppm); //ppm농도 
	
	printf("몰랄농도를 구하고 싶으면 용질의 분자량을 입력하시오(건너뛰고싶으면 0입력): ");
	scanf("%f",&a1);
	if(a1!=0){
		mol=a/a1;
		m=mol/c;
		printf("몰랄농도: %.2f m\n",m); //몰랄농도	
	}
	
	return 0;
}
