#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next = NULL;
    Node *prev = NULL;
};

struct Queue
{
    Node *head = NULL;
    Node *tail = NULL;
    unsigned int size = 0;

    void push_back(int value)
    {
        if (head == NULL)
        {
            head = new Node;
            head->value = value;
            tail = head;
            size = 1;
            return;
        }

        Node *new_node = new Node;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->value = value;
        tail = new_node;
        ++size;
    }
    int pop()
    {
        cout << "Size before " << size << endl;
        int val = head->value;
        cout << endl
             << "Value " << val << endl;
        Node *old_head = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete old_head;
        size--;

        return val;
    }

    int pop_last()
    {
        int last_val = tail->value;
        Node *old_tail = tail;
        tail = tail->prev;
        tail->next = NULL;

        delete old_tail;
        size--;

        return last_val;
    }

    void push_after(int index, int value)
    {
        Node *current = head;
        while (index > 0)
        {
            current = current->next;
            index--;
        }

        Node *new_node = new Node;
        new_node->value = value;
        new_node->prev = current;
        new_node->next = current->next;
        current->next = new_node;
        size++;
    }

    void push_after_center(int value)
    {
        int center;
        if (size == 0)
        {
            center = 0;
        }
        else
        {
            center = size % 2 == 0 ? size / 2 - 1 : size / 2;
        }
        push_after(center, value);
    }

    void clear()
    {
        while (head != NULL)
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
        size = 0;
    }
};

int main()
{
    Queue *queue = new Queue;
    int n;
    cin >> n;

    string input;
    for (int j = 0; j < n; j++)
    {
        cin >> input;
        if (input[0] == '-')
        {
            int i = queue->pop();
            cout << i;
        }
        else if (input[0] == '+')
        {
            int i;
            cin >> i;
            queue->push_back(i);
        }
        else if (input[0] == '*')
        {
            int i;
            cin >> i;
            queue->push_after_center(i);
        }
    }

    queue->clear();

    delete queue;
}