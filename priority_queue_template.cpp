#include <iostream>
template <typename T>

class Fifo
{
    struct Struktura
    {
        T val;
        int priorytet;
        struct Struktura* next;
    };
    Struktura* head = NULL;
    Struktura* tail = NULL;
    public:

    void push(T val, int priorytet)
    {
            Struktura* current = new Struktura;
            Struktura* tmp;
            current->next = NULL;
            current->priorytet = priorytet;
            current->val = val;

            if (!head) head = tail = current;
            else if (head->priorytet < priorytet) 
            {
                current->next = head;
                head = current;
            }
            else
            {
                tmp = head;
                while ((tmp->next) && (tmp->next->priorytet >= priorytet))
                    tmp = tmp->next;
              
                current->next = tmp->next;
                tmp->next = current;
                if (!current->next) tail = current;

            }
    }
    void pop()
    {
        Struktura* t = NULL;
        if (head != NULL)
        {
            t = head->next;
            std::cout << head->val;
            delete head;
            head = t;
        }
        else
            std::cout << "o";
    }
};

int main()
{
    Fifo<char> s;
    char x;
    int priorytet;

    char choice = '4';
    while (choice != '2') {
        std::cin >> choice;
        if (choice == '0') {
            std::cin >> x;
            std::cin >> priorytet;
            s.push(x, priorytet);
        }
        else if (choice == '1') {
            s.pop();
        }
    }
}