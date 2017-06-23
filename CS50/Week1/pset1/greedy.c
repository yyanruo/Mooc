#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
	float money ;
while(true){
	printf("Enter the money:$");
	money = GetFloat();
	if(money<=0){
		continue;
	}else{
	money = round(money*100);
	int a = 0;
	while(money>=25.0){
		money -=25.0;
		a++;
	}
	while(money>=10.0){
		money -=10.0;
		a++;
	}
	while(money>=5.0){
		money -=5.0;
		a++;
	}
	while(money>=1.0){
		money -=1.0;
		a++;
	}
	printf("%i\n", a);
	break;
}
};
return 0;
}