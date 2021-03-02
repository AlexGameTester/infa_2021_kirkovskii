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

bool is_operator(string input)
{
    char c = input[0];
    return (input.length() == 1) && (c == '+' || c == '-' || c == '*' || c == '/');
}

int apply_operator(string input, int val1, int val2) // val2 лежит ниже в стеке, чем val1
{
    char op = input[0];
    if (op == '+')
    {
        return val1 + val2;
    }
    else if (op == '*')
    {
        return val1 * val2;
    }
    else if (op == '-')
    {
        return val2 - val1;
    }
    else
    {
        return val2 / val1;
    }
}

int main()
{
    Stack *stack = new Stack;
    string input;
    while (cin >> input)
    {
        if (is_operator(input))
        {
            int val1 = stack->pop();
            int val2 = stack->pop();
            stack->push(apply_operator(input, val1, val2));
        }
        else
        {
            stack->push(stoi(input));
        }
    }

    cout << stack->pop() << endl;

    stack->clear();
    delete stack;
}