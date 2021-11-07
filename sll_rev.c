#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number;
	struct node *next;
}node;

void reverse(node *ref)
{
 node *current=ref, *prev=NULL,*next=NULL;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
 ref=prev;

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
    else if( num==0) 
    break;
    }
	reverse(numbers);
}