#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct stack{
  int data;
  struct stack *link;
}stack;

stack *top;
stack *create_node();
void push(int);
void print_stack();
int pop();
int is_empty();

int main(int argc, char *argv[]) {
   
   top=create_node();
   int num=0,empty;
   
   while(1){
    printf("넣을 값 입력 : ");
 scanf("%d",&num);
 
 if(num==-1) break;
 
 push(num);
 print_stack(); 
   
   }
   
   printf("빼기:\n");
   
    while(1){
   num=pop();
   if(num==0) break;
   printf("%d\n",num); 
                       }
    if( is_empty()==1 ) printf("비어있어요 스택이\n");
   else   printf("안비었어요 스택이\n"); 

 return 0;
   
  
}

stack *create_node(){
  
  stack *p;
  
  p=(stack*)calloc(1,sizeof(stack));
  
  return p;
}
void push(int data){
  stack *q;
  
  q=create_node();
  q->data=data;
  
  

      q->link=top->link;
      top->link=q;
 
  
  
}
int pop(){
  stack *q;
  int res;
  
  if(top->link==NULL) return 0;
  
  q=top->link;
  res=q->data;
  top->link=q->link;
  free(q);
  
  return res;
   
}

void print_stack(){
  stack *q;
  
  q=top;
  
    while(q->link!=NULL){
   q=q->link;
   
   printf("%d ",q->data);
   
 }
printf("\n");
}
int is_empty(){
  
  return  top->link==NULL;
} 

//https://euns2ol.tistory.com/9 출처 
