(!isEmptyStack(s))
	{
		pop(s);
	}
	while (!isEmptyStack(&temp))
	{
		push(s, pop(&temp));
	}
	write your code here