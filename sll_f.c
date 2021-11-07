#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
	int number;
	struct node *next;
}node;

void insert(struct node *prev, int new_data)
{
    if (prev == NULL)
    {
    printf("the given previous node cannot be NULL");    
    return;
    }   
    struct node *new =malloc(sizeof(struct node));
    new->number = new_data;
    new->next = prev->next;
    prev->next = new;
}
void print(node *ref)
{
    while(ref!=NULL)
{
    printf("%d\n", ref->number);
    ref=ref->next;
}
}
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

printf("\nPress 1 to add a node, 2 to delete any node, 3 to modify the contents of a node ");
int c;
scanf("%d",&c);

if (c==1)
{
    printf("\nEnter the data you want to add");
    int a;
    scanf ("%d",&a);
    insert(numbers, a);
  print(numbers);
}
else if (c==2)
{
printf("Enter the position of the node");
int p;
scanf("%d", &p);
delete(numbers, p);
print(numbers);
}
else if (c==3)
{
    printf("\nEnter the number you want to replace");
    int old, recent;
    scanf("%d", &old);
    printf("\nEnter the new number");
    scanf("%d", &recent);
    node *current=numbers;
    while(current!=NULL)
    {
        if(current->number==old)
        current->number=recent;

        current=current->next;
    }
    print(numbers);
}
}
