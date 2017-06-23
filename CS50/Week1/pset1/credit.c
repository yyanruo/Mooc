#include <stdio.h>
#include <cs50.h>
#include <math.h>

int check(int long long card,int b){
	int long long num =0,sum =0,h,h1;

	if (b%2==0)
	{
		for (int i=2 ; i <= b+1; i++){
	if (i%2==0)
	{
		h = pow(10,i-2);
		h1= pow(10,i);
		//printf("1h:%lli\n",h);
		num = card%h/h1;
	//	printf("1:%lli\n",num);
		if (num<5){
			sum += num*2;
			//printf("2:%lli\n",sum);
		}
		else if (num>5){

			sum += num*2-10+1;
			//printf("3:%lli\n",num);
		}
	}
	else if (i%2!=0){
		h1= pow(10,i);
		h = pow(10,i-2);
		num = card%h/h1;
		//printf("4:%lli\n",num);
		sum += num;
	}	
}
	}else{
		for (int i=1 ; i <= b; i++){
	if (i%2==0)
	{
		h = pow(10,i);
		h1= pow(10,i-1);
	//	printf("1h:%lli\n",h);
		num = card%h/h1;
	//	printf("1:%lli\n",num);
		if (num<5){
			sum += num*2;
			//printf("2:%lli\n",sum);
		}
		else if (num>5){

			sum += num*2-10+1;
			//printf("3:%lli\n",num);
		}
	}
	else if (i%2!=0){
		h1= pow(10,i-1);
		h = pow(10,i);
		num = card%h/h1;
		//printf("4:%lli\n",num);
		sum += num;
	}	
}	
	}
	return sum%10;
}

int weishu(int long long card){
	int i = 0;
	while(card>1){

		card = card/10;
		i++;
	};
	return i;
}



int main(void){
	int long long card;
	int long long a;
	int b;
	
	printf("numbers:");
	card = GetLongLong();
	b = weishu(card);
	
	//printf("%i\n",b);
	a = card/pow(10,b-2);
	if (a==37||a==34)
	{
		if (check(card,b)==0)
		{
			printf("AMEX\n");
		}else{
			printf("INVALID\n");
		}
	}else if (a>=51&&a<=55)
	{
		if (check(card,b)==0)
		{
			printf("MASTERCARD\n");
		}else{
			printf("INVALID\n");
		}
	}else if (a>=40&&a<=49)
	{
		if (check(card,b)==0)
		{
			printf("VISA\n");
		}else{
			printf("INVALID\n");
		}
	}else{
		printf("INVALID\n");
	}
return 0;
}