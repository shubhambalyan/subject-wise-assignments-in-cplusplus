//Write a C++ program for Syntax tree for a given expression
/* Steps followed:
   1. Convert the given Expression into Postfix Notation 
   2. Convert the postfix into Expression Tree and Check for the Infix notation 
      If the infix notation obtained from the inorder traversal of the tree is equal 
      to the original expression, then the correct syntax tree is obtained.*/

#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
using namespace std;
#define MAX 100
#define EMPTY -1
const int size=50;
int top = -1;
char stack[size];
void push(char item);
char pop();
int oper(char symbol);
int precedence(char symbol);

struct node
{
    char element;
    struct node *left,*right;
};

struct stack
{
    struct node *data[MAX];
    int top;
};

int isempty(struct stack *s)
{
    return (s->top == EMPTY) ? 1 : 0;
} 

void emptystack(struct stack* s)
{
    s->top=EMPTY;
}

void push(struct stack* s, struct node *item)
{
    if(s->top == (MAX-1))
    {
       printf("\nSTACK FULL");
    }
    else
    {
        ++s->top;
        s->data[s->top]=item;
    }
} 

struct node* pop(struct stack* s)
{
    struct node *ret=NULL;
    if(!isempty(s))
    {
        ret= s->data[s->top];
        --s->top;
    }
    return ret;
}

void post2exp(char* postfix, struct node **root)
{
    struct stack X;
    struct node *newnode,*op1,*op2;
    char *p;
    p = &postfix[0];
    emptystack(&X);
    while(*p)
    {
         while(*p == ' ' || *p == '\t')
        {
           p++;
        }
         if(isalpha(*p) || isdigit(*p))
        {
            newnode = new node;
            newnode->element = *p;
            newnode->left = NULL;
            newnode->right = NULL;
            push(&X,newnode);
        }
        else
        {
            op1 = pop(&X);
            op2 = pop(&X);
            newnode = new node;
            newnode->element = *p;
            newnode->left = op2;
            newnode->right = op1;
            push(&X,newnode);
        }
        p++;
    }
    *root = pop(&X);
}

void inorder(struct node *x)
{
    if(x != NULL)
    {
        inorder(x->left);
        cout<<x->element;
        inorder(x->right);
    }
}

int main()
{
int i=0, j=0;
char infix_exp[size], postfix_exp[size];
char item, x;
cout<<"\nEnter the arithmetic expression (It should start with a opening bracket and end with a closing bracket): \n\nFor example: (a=b+c*d)\n";
cout<<"\n\nNOTE:::::Operators used: +,-,*,/,=,^ and Operands used: (a to z) or (A to Z)\n";
cout<<"\n\nExpression: ";
gets(infix_exp);
item = infix_exp[i++];

while(item != '\0')
{

if(item == '(')
{
push(item);
}

else if((item >= 'A' && item <= 'Z') || (item >= 'a' && item <= 'z'))
{
postfix_exp[j++]=item;
}

else if(oper(item) == 1)
{
x = pop();
while(oper(x) == 1 && precedence(x) >= precedence(item))
{
postfix_exp[j++] = x;
x = pop();
}
push(x);
push(item);
}

else if(item == ')')
{
x = pop();
while(x != '(')
{
postfix_exp[j++] = x;
x = pop();
}
}

else
{
cout<<"\nInvalid Arithmetic Expression.\n";
getch();
}
item = infix_exp[i++];
}
postfix_exp[j++] = '\0';
cout<<"\nArithmetic expression in Postfix notation.....\n\n";
Sleep(1000);
puts(postfix_exp);
struct node *r;
post2exp(postfix_exp,&r);
cout<<"\nInorder Traversal of the syntax tree.....\n\n";
Sleep(1000);
inorder(r);
cout<<"\n\n\nNOTE::::If the Inorder notation obtained from the traversal of the "; 
cout<<"tree is same as the original expression, then the correct syntax tree is obtained...";
getch();
return 0;
}

void push(char item)
{
if(top == size-1)
       cout<<"\nOVERFLOW!!!\n";
else
{
             top = top+1;
          stack[top] = item;
}
}


char pop()
{
char item = '\0';
if(top == -1)
{
         cout<<"\nUNDERFLOW!!!\n";
}
else
{
      item = stack[top];
        top = top-1;
}
return item;
}


int oper(char symbol)
{
if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-' || symbol == '=')
   return 1;
else
   return 0;
}


int precedence(char symbol)
{
if(symbol == '^')
   return 4;
else if(symbol == '*' || symbol == '/')
    return 3;
else if(symbol == '+' || symbol == '-')
   return 2;
else if(symbol == '=')
    return 1;
else
    return 0;
}
