#include <stdio.h>
#include <stdlib.h>

struct stack
{
	struct stack *pre;
	int data;
}* top1,*top2;

int deque(int);
int enque(int, int);
void push1();
int pop1();
void push2();
void pop2();

int main()
{
	int n,
		max;
	printf("Enter no. of elements in Queue\n");
	scanf("%d", &max);
	n = 0;
	char c;

	do
	{
		fflush(stdin);
		printf("Enter 'E' for enque, 'D' for deque, 'O' for stop\n");
		scanf("%c", &c);
		if (c == 'E')
			n = enque(n, max);
		if (c == 'D')
			n = deque(n);
	}

	while (c != 'O');
}

int enque(int n, int max)
{
	if (n == max)
	{
		printf("Queue is Full\n");
	}
	else
	{
		printf("Enter data for Queue\n");
		push1();
		n++;
	}

	return n;
}

int deque(int n)
{
	if (!n)
	{
		printf("Queue is empty\n");
	}
	else
	{
		n--;
		push2();
	}

	return n;
}

void push1()
{
	struct stack *new;
	new = (struct stack *)malloc(sizeof(struct stack));
	new -> pre = top1;
	scanf("%d", &(new -> data));
	top1 = new;
}

void push2()
{
	if (!top2)
	{
		while (top1)
		{
			struct stack *new;
			new = (struct stack *)malloc(sizeof(struct stack));
			new -> pre = top2;
			new -> data = pop1();
			top2 = new;
		}
	}

	pop2();
}

int pop1()
{
	int temp = top1 -> data;
	top1 = top1 -> pre;
	return temp;
}

void pop2()
{
	printf("%d \n", top2 -> data);
	top2 = top2 -> pre;
}
