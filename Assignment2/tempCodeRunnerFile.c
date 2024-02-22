void infixtoPrefix(char *infix, char *prefix)
{
    Stack o, r, t;
    o.ll.head = NULL;
    r.ll.head = NULL;
    t.ll.head = NULL;
    o.ll.size = 0;
    r.ll.size = 0;
    t.ll.size = 0;
    while (*infix)
    {
        push(&o, *infix);
        infix++;
    }

    while (!isEmptyStack(&o))
    {
        if (isalnum(peek(&o)))
        {
            push(&r, pop(&o));
        }
        else if (peek(&o) == ')')
        {
            push(&t, pop(&o));
        }
        else if (peek(&o) == '(')
        {
            while (1)
            {
                push(&r, pop(&t));
                if (peek(&t) == ')')
                    break;
            }
            pop(&t);
        }
        else if (isEmptyStack(&t))
            push(&t, pop(&o));
        else
        {
            while ((precedence(peek(&o)) <= precedence(peek(&t))) && peek(&t) != ')')
            {
                push(&r, pop(&t));
                if (isEmptyStack(&t) || peek(&t) == '(')
                    break;
            }
            push(&t, pop(&o));
        }
    }
    while (!isEmptyStack(&t))
    {
        push(&r, pop(&t));
    }
    while (!isEmptyStack(&r))
    {
        *prefix = pop(&r);
        prefix++;
    }
    *prefix = '\0';
}