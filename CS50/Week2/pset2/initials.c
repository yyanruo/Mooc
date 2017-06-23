#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Thanslate the 'a-z' to 'A-Z',of cause we can ues the 'toupper' in the ctype.h;
void print(char c){
    if(c>='a'&&c<='z')
            {
                printf("%c",c-32);
            }else{
                printf("%c",c);
            }
}

int main(void){
    string s = GetString();
    print(s[0]);
    for(int i = 0 ; i<strlen(s);i++){
        //find the space to find the word;
        if(s[i]==' '){
            print(s[i+1]);
        }
    }
    printf("\n");
}