#include <iostream>
template <typename T>


class Fifo
{
    struct Struktura
    {
        T val;
        struct Struktura* next;
    };
    Struktura* head = NULL;
public:

    void push(T val)
    {
        
        if(head == NULL) {
            head = new Struktura;
            head->val = val;
            head->next = NULL;
        }
        else {
            Struktura* tmp = head;
            while (tmp->next)
                tmp = tmp->next;

            tmp->next = new Struktura;
            tmp->next->val = val;
            tmp->next->next = NULL;
        
        
        }
        
    }

    void top()
    {
        Struktura * tmp = head;
        while(tmp)
        {
            std::cout<<tmp->val;
                tmp = tmp->next;
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
        else std::cout << "x";
    }
};

int main()
{
    Fifo<int> s;
    int x;
    

    char choice = '4';
    while (choice != '3') {
        std::cin >> choice;
        if (choice == '0') {
            std::cin >> x;
            s.push(x);
        }
        if (choice == '1') {
            s.pop();
        }
        if (choice == '2') {
            s.top();
        }


    }
    

}