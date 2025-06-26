#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//1 WPM = 1 CPM / 5 (standard is to consider length of word 5 character)

double accu(char* , char*);

int main(){
    printf("Instructions:- After you press Enter a sentence will be shown , you have to type that sentence at max speed you can\n");
    printf("Press any number and hit enter to start ");
    int waste;
    srand(time(0)); //time(0) generates current time and is used as seed for srand() here basically tells how to shuffle to rand()
    scanf("%d",&waste);
    while (getchar() != '\n');  // clear input buffer(scan f leaves a /n buffer)
    char sentences[10][100] = {"Consistency is what transforms average coding skills into mastery. Keep typing, keep refining it.",
        "To become truly fast, you must first become precise. Type with purpose, and let speed follow next.",
        "Every character typed is a step closer to mastery. Dont rush it—feel the rhythm, trust the flow.",
        "When you type like a machine, you build code like an architect. Accuracy is your foundation.",
        "Typing tests arent about speed alone they are about calm control under pressure. Breathe and strike.",
        "In every session, train your fingers to respond before thought. Thats how muscle memory is built.",
        "Your fingers are the soldiers, your brain the commander. Typing fast is war—discipline wins wars.",
        "Forget errors. Focus on control, focus on flow. Let the characters fall perfectly into position.",
        "Typing with intent is the difference between noise and code. You are here to dominate the keys.",
        "The code you write reflects the precision of your hands. Let every keystroke echo your discipline."};
    int random = rand();
    random%=10;
    int length = strlen(sentences[random]);
    printf("%s\n",sentences[random]);
    char input[500]; // To avoid error if user entered extra character
    clock_t start_time = clock();//stores in tick
    fgets(input,500,stdin);
    clock_t end_time = clock();
    int input_length = strlen(input);
    double time_taken = (double)(end_time - start_time)/CLOCKS_PER_SEC;//A constant to help convert tick to seconds
    double raw_wpm = ((double)input_length / 5.0) / (time_taken / 60.0);
    int wpm = (int)(raw_wpm + 0.5);  // Rounded WPM
    double accuracy = accu(sentences[random],input);
    printf("\n");
    printf("WPM:- %d\n",wpm);
    printf("Accuracy:- %.2f\n",accuracy);
    printf("Time Taken:- %.2f\n",time_taken);
}

double accu(char*expected , char*input){
    int match = 0.0;
    int length = (strlen(expected)>strlen(input))?(strlen(input)):(strlen(expected));
    for(int i = 0 ; i<length ; i++){
        if(expected[i] == input[i]) match++;
    }
    return ((double)match/strlen(expected))*100;
}
