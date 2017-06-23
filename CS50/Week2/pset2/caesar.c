#include <stdio.h>
#include <cs50.h>
#include <string.h>



int main(int argc, string argv[]){

    string p = GetString();
	int k = atoi(argv[1])%26;//make 0<=k<=26;
    /*
     *test code
     *int k = 13;
     *string p ="Be sure to drink your Ovaltine!";
	*/
	for (int i = 0; i < strlen(p); ++i)
	{
		if(p[i]>=65&&p[i]<=90){
		    
		    printf("%c",(p[i]+k-65)%26+65);
		    
		}else if(p[i]>=97&&p[i]<=122){

	        printf("%c",(p[i]+k-97)%26+97);
	        
	    }else{
	        printf("%c",p[i]);
	    }
	}
	printf("\n");
	
}