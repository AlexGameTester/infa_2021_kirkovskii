#include <iostream>
using namespace std;

struct Node
{
    Node *prev = NULL;
    Node *next = NULL;
    int value;
};

struct Queue //Head и Tail всегда присутсвуют и не являются элементами очереди
{
    Node *head = new Node;
    Node *tail = new Node;
    int size = 0;
    Queue()
    {
        head->next = tail;
        tail->prev = head;
    }
    void push_back(int value)
    {
        Node *new_node = new Node;
        new_node->value = value;
        Node *before_tail = tail->prev;
        tail->prev = new_node;
        new_node->next = tail;
        new_node->prev = tail->prev;
        before_tail->next = new_node;
        ++size;
    }
    int pop()
    {
        Node *node = head->next;
        int val = node->value;
        head->next = node->next;
        node->next->prev = head;

        size--;
        delete node;
        return val;
    }

    void push_after(int index, int value)
    {
        Node *current = head->next;
        if (index == 0 && size == 0)
        {
            current = head;
        }
        else
        {
            while (index > 0)
            {
                current = current->next;
                index--;
            }
        }

        Node *new_node = new Node;
        new_node->value = value;
        new_node->prev = current;
        new_node->next = current->next;
        Node *current_next = current->next;
        current->next = new_node;
        current_next->prev = new_node;
        size++;
    }

    void clear()
    {
        Node *current = head->next;
        while (current->next != NULL)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
        size = 0;
    }

    void del()
    {
        clear();
        delete head;
        delete tail;
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
            cout << i << endl;
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

    queue->del();

    delete queue;
}
