//Programming Exercise 3: Test Program

//22 34 56 2 89 90 0 14 56 11 43 55 -999

#include <iostream>
#include "unorderedLinkedList.h"

using namespace std;

int main()
{
    unorderedLinkedList<int> list;

    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999)
    {
        list.insertLast(num);
        cin >> num;
    }

    cout << endl;

    cout << "List: ";
    list.print();
    cout << endl;
    cout << "Length of the list: " << list.length() << endl;

    int k;

    cout << "Enter the position of the item to be retrieved: " << endl;
    cin >> k;
    cout << endl;

    int temp = list.getKThElement(k);

    cout << "Item at position " << k << " = " << temp << endl;

    cout << "Enter the position of the item to be removed: " << endl;
    cin >> k;
    cout << endl;

    list.deteteKthElement(k);

    cout << "List after removing the element at position "
         << k << "." << endl;
    list.print();
    cout << endl;

    return 0;
}



