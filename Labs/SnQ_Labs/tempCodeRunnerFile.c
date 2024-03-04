(s == NULL || s->ll.size == 0 || s->ll.head->item == NULL)
	// 	return -1;
	// Stack *temp;
	// temp->ll.head = NULL;
	// temp->ll.size = 0;
	// while (!isEmptyStack(s))
	// {
	// 	if (s->ll.head->item % 2)
	// 		push(temp, s->ll.head->item);
	// 	else
	// 		pop(s);
	// }
	// while (!isEmptyStack(temp))
	// 	push(s, pop(temp));