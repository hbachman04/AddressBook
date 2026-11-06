
#ifndef H_linkedListType
#define H_linkedListType

#include "extPersonType.h"

class linkedListType
{
private:
    struct nodeType
    {
        extPersonType info;
        nodeType* link;
    };

    nodeType* first;
    nodeType* last;
    int count;

public:
    linkedListType();
    ~linkedListType();

    int getLength() const;
    bool isEmpty() const;

    bool insertLast(const extPersonType& newItem);
    bool insertAt(const extPersonType& newItem, int position);
    bool deleteAt(int position);

    extPersonType getAt(int position) const;
    bool setAt(const extPersonType& newItem, int position);

    void clear();
};

#endif
