#include<stdio.h>
#define MAX 80

//stack implementaion

int top=-1;
int push(int num,int a[]){
	if(top==MAX)printf("cannot push");
	else{
		a[++top]=num;
	}
}
int pop(int a[]){
	if(top==-1)return -1;
	else{
	
		return a[top--];
	}
}

int operation(int num1,int num2,char op){
	switch(op){
		case '+':
		   return num1+num2;
		   break;
		case '-':
		   return num1-num2;
		   break;
		case '/':
		   return num1/num2;
		   break;
		case '*':
		   return num1*num2;
		   break;
	}
	return 0;
}
int is_digit(char digit){
     if(digit>='0' && digit<='9')return 1;
     else
     return 0;
}
 void evaluate(char exp[]){
 	int i,num1,num2,ans=0;
 	int stack[MAX];
 	 if(is_correct(exp)){
 	 		for(i=0;exp[i]!='\0';i++){
 		if(exp[i]==' ')continue;
 		if(is_digit(exp[i]))push(exp[i]-'0',stack);
 		else{
 			int num1=pop(stack);
 			int num2=pop(stack);
 			
 			ans=operation(num1,num2,exp[i]);
 			push(ans,stack);
 			
		 }
	 }
	 printf("%d",ans);
	  }
	  else{
	  	printf("incorrect");
	  }
 	
	 
 
 }
int is_correct(char postfix[]){
	int i=0;
	int top=-1;
	int count=0;
   
	for(i=0;postfix[i]!='\0';i++){
		if(postfix[i]==' ')continue;
		if(is_digit(postfix[i]))count++;
		else{
		 count-=2;
		 count++;
		}
		if(count>0)continue;
		else
		return 0;
	}
	if(count==1)return 1;
	else
	return 0;
	
}
int main(){
	char postfix[MAX];
	printf("enter the expression : ");
	scanf("%s",postfix);
	evaluate(postfix);
    
	return 0;
}



