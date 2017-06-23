#include <stdio.h>
#include <cs50.h>
#include <string.h>

int shift(char a){
	//calculate the shift of the 'a' represent;
	if(a>=97&&a<=122){
		//'a-z';
		return a-97;
	}else if(a>=65&&a<=90){
		//'A-Z';
		return a-65;
	}else if(a>=48&&a<=57){
		//char '0-9';
		return a-48;
	}else{
		return -1;
	}
}

int main(int argc, string argv[]){

    string p = GetString();
	//Default the input of key is argv[1] after ./vignere;
	string key = argv[1];
    /*test code 
     *purpose = Negh zf av huf pcfx bt gzrwep oz;
     *string key = "bacon";
     * string p ="Meet me at the park at eleven am";
	*/
	
	for (int i = 0,j = 0; i < strlen(p); ++i,++j)
	{
		if(p[i]>=65&&p[i]<=90){
		    
		    printf("%c",(p[i]-65+shift(key[j%strlen(key)]))%26+65);
		    
		}else if(p[i]>=97&&p[i]<=122){

	        printf("%c",(p[i]-97+shift(key[j%strlen(key)]))%26+97);
	     
	    }else{
	        printf("%c",p[i]);
	        --j; //get across the space;
	    }
	}
	printf("\n");
}

