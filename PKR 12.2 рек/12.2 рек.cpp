// pkr_12_2_rec

#include <iostream>
using namespace std;


struct Elem
{
    double info;
    Elem* link;
};

Elem* first = NULL;  // ������� ������

// ������� ��� ��������� ������ �������� � ����� ������
void AddElem(double info)
{
    Elem* newElem = new Elem;
    newElem->info = info;
    newElem->link = NULL;

    // ���� ������ �������, �� ����� ������� ��� ������
    if (first == NULL)
    {
        first = newElem;
    }
    // ���� � - ����� ������� �������� � �����
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

// ������� ��� ��������� ������ �������� ���� ������� ��������
void AddAfterElem(Elem* current, int V1, int V2)
{
    // ���� �������� ������� NULL, �� ��������� �������� ����������
    if (current == NULL)
    {
        return;
    }

    // ���� �������� ������� �� ������ ��������, �� �������� ����� ������� ���� �����
    if (current->info == V1)
    {
        Elem* newElem = new Elem;                                       // ������� ����� ������� �� ������ ���'��� ��� �����
        newElem->info = V2;
        newElem->link = current->link;                                // �������� �������� �� ��������� �������
        current->link = newElem;                                     // �������� �������� �� ����� ������� 

        // ����������� �-��� ��� �������� ���������� ��������
        AddAfterElem(newElem->link, V1, V2);
    }
    else
    {
        // ���� �������� ������� �� �� �������� ��������, �� ����������� �-��� ��� �������� ���������� ��������
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
