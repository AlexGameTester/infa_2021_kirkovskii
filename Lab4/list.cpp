#include <iostream>
#include <bits/stdc++.h>

struct Node {
    int value;
    Node * next = NULL;
    Node * prev = NULL;
};

struct List
{
    Node * head = NULL;
    Node * tail = NULL;
    unsigned int size = 0;

    void print()
    {
        Node * p_node = head;
        while (p_node != NULL) {
            std::cout << p_node->value << ' ';
            p_node = p_node->next;
        }
        std::cout << '\n';
    }

    void clear()
    {
        while(head != NULL) {
            Node * next = head->next;
            delete head;
            head = next;
        }
        size = 0;
    }

    bool equals(List list2)
    {
        return false;
    }

    void push_back(int value)
    {
        if (head == NULL) {
            head = new Node;
            head->value = value;
            tail = head;
            size = 1;
            return;
        }

        Node * new_node = new Node;
        tail->next = new_node;
        new_node->prev = tail;
        new_node->value = value;
        tail = new_node;
        ++size;
    }


    void push_left(int value)
    {

    }

    int pop(int index)
    {
        return INT_MIN;
    }

};


int main(int argc, char const *argv[])
{
    List list1;
    for (int i = 1; i <= 10; ++i)
        list1.push_back(i);

    list1.print();
    list1.clear();
    list1.print();
    return 0;
}
