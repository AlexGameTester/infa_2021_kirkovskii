#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *prev;
};

struct Stack
{
    int size = 0;
    Node *last = NULL;
    void push(int value)
    {
        if (last == NULL)
        {
            last = new Node;
            last->value = value;
            last->prev = NULL;
            size = 1;
            return;
        }

        Node *new_last = new Node;
        new_last->value = value;
        new_last->prev = last;
        last = new_last;
        size++;
    }

    int pop()
    {
        if (last == NULL)
        {
            return -1;
        }

        int val = last->value;
        Node *old_last = last;
        last = last->prev;
        delete old_last;
        size--;

        return val;
    }

    void clear()
    {
        while (last != NULL)
        {
            Node *prev = last->prev;
            delete last;
            last = prev;
        }
    }
};

int main()
{
    int n;
    Stack *stack = new Stack;

    cin >> n;
    while (n != 0)
    {
        if (n > 0)
        {
            stack->push(n);
        }
        else
        {
            if (stack->size > 0)
            {
                int top = stack->pop();
                if (abs(n) < top)
                {
                    stack->push(n + top);
                }
            }
        }

        cin >> n;
    }
    int size = stack->size;
    int top = size > 0 ? stack->pop() : -1;
    cout << size << ' ' << top << endl;
    stack->clear();
    delete stack;
}