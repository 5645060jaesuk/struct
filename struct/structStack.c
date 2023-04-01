#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10

typedef int element;



typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;


void init_stack(StackType* s)
{
	s->top = -1;
}


int is_empty(StackType* s)
{
	return(s->top == -1);
}


int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}


void push(StackType* s, element item)
{
	if (is_full(s))
	{
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}


element pop(StackType* s)
{
	if (is_empty(s))
	{
		fprintf(stderr, "���� ���� ����\n");
		return;
	}
	else return s->data[(s->top)--];
}

int main(void)
{
	srand(time(NULL));
	StackType s;

	init_stack(&s);

	for (int i = 0; i < 30; i++)
	{
		int rand_num = rand() % 100 + 1;
		if (rand_num % 2 == 0)
		{
			push(&s, rand_num);
			printf("push %d\n", rand_num);
		}
		else
		{
			printf("pop %d\n", pop(&s));
		}
	}
}

