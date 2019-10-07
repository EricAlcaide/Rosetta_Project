#include<stdio.h>
#include<stdlib.h>
char arr[20];
int top = -1;
int precedence(char ele){
	if(ele == '+' || ele == '-')
		return 1;
	if(ele == '*' || ele == '/')
		return 2;
	if(ele == '^')
		return 3;
	else
		return 0;
}
int operand(char ele){
	if(ele == '+' || ele == '/' || ele == '-' || ele == '*' || ele == '^')
		return 0;
	else
		return 1;}
void push(char ele){
	if(top == 19){
		printf("Overflow \n");
	}
	else
		arr[++top] = ele;
}
char peek(){
	return arr[top];
}
int main(){
	char expression[20],output[20];
	scanf("%s", expression);
	int i =0,j=0;
	while(expression[i] != '\0'){
		if(operand(expression[i]))
			output[j++] = expression[i++];
		else{
			if(precedence(expression[i]) > precedence(peek()))
				push(expression[i++]);
			else{
				output[j++] = peek();
				top--;
			}
		}
    }
    while(top != -1){
    	output[j++] = peek();
    	top--;
    }
    output[j] = '\0';
    printf("%s", output);
    return 0;
}