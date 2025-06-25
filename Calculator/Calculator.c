#include <stdio.h>
#include <string.h>
double main(){
    char s[500];
    printf("Enter Everything you want:- ");
    fgets(s,500,stdin);
    int length = strlen(s); //it doesnt counts \0
    double num = 0;
    int operator;
    double result = 0;
    int check = s[0];
    int i = 0;
    char last_recorded_operator = '+';
    if (s[0] == '-') {
    result = 0;
    last_recorded_operator = '-';
    i = 1;  // start loop from second char
    }
    for( ; i<length ; i++){
       if(s[i]>='0' && s[i]<='9') {
        num = num*10.0 + (s[i] - '0');
        }
        if(s[i] == '+' || s[i] == '-' || s[i] == '/'  || s[i] == '*' || i == length-1){
            if(last_recorded_operator == '+') result+=num;
            if(last_recorded_operator == '-') result-=num;
            if(last_recorded_operator == '*') result*=num;
            if(last_recorded_operator == '/') result/=num;
            num = 0;
            last_recorded_operator = s[i];
        }
        //This calculator also keep capability to ignore typos 
    }

    printf("%s = %.2f",s,result);
}
