//
// Created by vpangul on 2019-04-03.
//

#ifndef ARRAYLISTTYPE_ARRAYLISTTYPE_H
#define ARRAYLISTTYPE_ARRAYLISTTYPE_H

#include <iostream>
using namespace std;

template <class elemType>
class arrayListType{
public:

    /* Copy constructor */
    arrayListType(const arrayListType<elemType>& otherList);
    /* operator overloading = */
    arrayListType<elemType>& operator=(const arrayListType<elemType>& otherList);

    /** SEQUENTIAL SEARCH **/
    int seqSearch(const elemType& listParam);

    /** INSERT An ELEMENT  **/
    void insert(const elemType&);

    /** REMOVE AN ELEMENT **/
    void remove(const elemType&);

    /* Overload the assignment operator */

    /* Update List Functions */
    void print() const;
    bool isItemAtEqual(int location, const elemType& listParam) const;
    void insertAt(int location, const elemType& listParam);
    void insertAtEnd(const elemType& listParam);
    void removeAt(int location);
    void replaceAt(int location, const elemType& listParam);

    /* Get size/list Status functions */
    int getSize();
    int getMaxSize();
    bool isFULL();
    bool isEmpty();
    void clearList();

    /* constructors and Destructors */
    arrayListType(int size=100);
    ~arrayListType();
protected:
    int length;
    int maxSize;
    elemType* list;
};
#endif //ARRAYLISTTYPE_ARRAYLISTTYPE_H
