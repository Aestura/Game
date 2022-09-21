#include <stdio.h>
#define MAX 100

typedef struct Stack{
 char word[MAX];
 int top;
}Stack;

void init(Stack *S){
 S->top = -1;
}

int full(Stack *S){
 return (S->top+1) == MAX;
}

int empty(Stack *S){
 return S->top == -1;
}

void push(Stack *S, char word){
 if(full(S))
 {
  printf("FULL");
 }
 else
 {
  S->top++;
  S->word[S->top] = word;
 }
}

char pop(Stack *S){
 int Temp;
 if(empty(S)){
  printf("EMPTY");
  return 0;
 }
 Temp = S->word[S->top];
 S->top--;
 return Temp;
}

int palindrome(char String[]){
 Stack S;
 int i;
 init(&S);
 for(i = 0; String[i] != 0; i++){
  if(String[i] >= 65 && String[i] <= 90)
   String[i] += 32;
  push(&S, String[i]);
 }
 for(i = 0; String[i] != 0; i++){
  if(String[i] != pop(&S))
  {
   return 0;
  }
 }
 return 1;
}

int main(void){
 char String[MAX];
 gets(String);
 if(palindrome(String))
  printf("TRUE");
 else
  printf("FALSE");
 return 0;
}

//m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=ndb796&logNo=220705493924
