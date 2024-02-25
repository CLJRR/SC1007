void infixtoPrefix(char *infix, char *prefix)
{

    /* add your code here */
    Stack s;
    s.ll.head = NULL;
    s.ll.size = 0;

    int lenInfix = strlen(infix);
    int j = 0;
    int i;

    for (i = lenInfix - 1; i >= 0; i--)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            prefix[j++] = ch;
        }
        else if (ch == ')')
        {
            push(&s, ch);
        }
        else if (ch == '(')
        {
            while (!isEmptyStack(&s) && peek(&s) != ')')
            {
                prefix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (!isEmptyStack(&s) && precedence(peek(&s)) > precedence(ch))
            {
                prefix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (!isEmptyStack(&s))
    {
        if (peek(&s) != '(' && peek(&s) != ')')
            prefix[j++] = pop(&s);
    }

    prefix[j] = '\0';

    for (i = 0; i < j / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[j - i - 1];
        prefix[j - i - 1] = temp;
    }
}