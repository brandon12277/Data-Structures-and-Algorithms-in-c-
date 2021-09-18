#include <stdio.h>
#define SIZE 10
char stack[SIZE],reverse[SIZE];
int top=-1;
void push(char elem){
	if(top>=SIZE)return;
	else{
		stack[++top]=elem;
	}
}
char pop(){
	if(top==-1)return;
	else{
		return stack[top--];
	}
}

void stack_reverse(char word[]){
	int i=0,j=0;
	for(i=0;word[i]!='\0';i++)push(word[i]);
	for(j=0;word[j]!='\0';j++)reverse[j]=pop();
	return reverse;
}

int main(){
	 char word[SIZE];
	 printf("\ninput your word: ");
	 scanf("%s",word);
	 stack_reverse(word);
	 printf("\nReversed: %s",reverse);
	
	
	return 0;
}
