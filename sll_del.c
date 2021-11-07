#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int number;
	struct node *next;
}node;

void delete(struct node *ref, int key)
{
    struct node *temp = ref, *prev;

    if (temp != NULL && temp->number == key) 
    {
        ref = temp->next; 
        free(temp); 
        return;
    }
 
    while (temp != NULL && temp->number != key) 
    {
        prev = temp;
        temp = temp->next;
    }
 
    if (temp == NULL)
        return;
 
    prev->next = temp->next;
 
    free(temp);
}
 
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
    break;
   }
print (numbers);
printf("Enter the position of the node");
int p;
scanf("%d", &p);
delete(numbers, p);
print(numbers);
}
