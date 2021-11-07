#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number;
	struct node *next;
}node;

void print(node *ref)
{
    while(ref!=NULL)
{
    printf("%d\n", ref->number);
    ref=ref->next;
}
}
int main(void)
{

	node *numbers = NULL;
	while(1)
	{
		int num;
		printf("\nenter your number except 0: ");
		scanf("%d", &num);
	
		if (num!= 0)
		{
		
		node *n = malloc(sizeof(node));

		if(!n)
		{
			return 1;		
		}

		n-> number =num;
		n-> next = NULL;

		if(numbers)
		{
			for (node *ptr =numbers; ptr!=NULL; ptr=ptr->next)
            {
			if(ptr->next == NULL)
			{
				ptr->next=n;
				break;
			}
		}
        }
		else
		{
			numbers=n;		
		}

	}	
    else if(num==0)
    {
    printf("\nEnter the number you want to replace\n");
    int old, recent;
    scanf("%d", &old);
    printf("\nEnter the new number\n");
    scanf("%d", &recent);
    node *current=numbers;
    while(current!=NULL)
    {
        if(current->number==old)
        current->number=recent;
        current=current->next;

    }
    break;
    }
}
print (numbers);
}
