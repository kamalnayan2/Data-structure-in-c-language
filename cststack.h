#define max 100
int top=-1,stack[max];
void push(char x)
{
      if(top == max-1){
          printf("stack overflow");
      }  else {
          stack[++top]=x;
      }

}
void pop()
{
      printf("%c",stack[top--]);
}