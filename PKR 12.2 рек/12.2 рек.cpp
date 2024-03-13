// pkr_12_2_rec

#include <iostream>
using namespace std;


struct Elem
{
    double info;
    Elem* link;
};

Elem* first = NULL;  // Початок списку

// Функція для додавання нового елемента в кінець списку
void AddElem(double info)
{
    Elem* newElem = new Elem;
    newElem->info = info;
    newElem->link = NULL;

    // Якщо список порожній, то новий елемент стає першим
    if (first == NULL)
    {
        first = newElem;
    }
    // Якщо ні - новий елемент додається в кінець
    else
    {
        Elem* tmp = first;
        while (tmp->link != NULL)
        {
            tmp = tmp->link;
        }
        tmp->link = newElem;
    }
}

void PrintList()
{
    Elem* tmp = first;
    while (tmp != NULL)
    {
        cout << tmp->info << "; ";
        tmp = tmp->link;
    }
    cout << endl;
}

// Функція для додавання нового елемента після певного елемента
void AddAfterElem(Elem* current, int V1, int V2)
{
    // якщо поточний елемент NULL, то додавання елемента закінчується
    if (current == NULL)
    {
        return;
    }

    // якщо поточний елемент має задане значення, то додається новий елемент після нього
    if (current->info == V1)
    {
        Elem* newElem = new Elem;                                       // створює новий елемент та виділяє пам'ять для нього
        newElem->info = V2;
        newElem->link = current->link;                                // присвоює вказівник на наступний елемент
        current->link = newElem;                                     // присвоює вказівник на новий елемент 

        // викликається ф-ція для перевірки наступного елементу
        AddAfterElem(newElem->link, V1, V2);
    }
    else
    {
        // якщо поточний елемент не має заданого значення, то викликається ф-ція для перевірки наступного елементу
        AddAfterElem(current->link, V1, V2);
    }
}


int main()
{
    int n;
    double info;

    cout << "Enter n of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter info for element: ";
        cin >> info;
        AddElem(info);
    }
    cout << "List of elements: ";
    PrintList();

    int V1, V2;
    cout << "Enter V1: ";
    cin >> V1;
    cout << "Enter V2: ";
    cin >> V2;
    AddAfterElem(first, V1, V2);

    cout << "List of elements: ";
    PrintList();

    return 0;
}
