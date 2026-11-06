
#include "linkedListType.h"

linkedListType::linkedListType()
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

linkedListType::~linkedListType()
{
    clear();
}

int linkedListType::getLength() const
{
    return count;
}

bool linkedListType::isEmpty() const
{
    return count == 0;
}

bool linkedListType::insertLast(const extPersonType& newItem)
{
    return insertAt(newItem, count);
}

bool linkedListType::insertAt(
    const extPersonType& newItem, int position)
{
    if (position < 0 || position > count)
        return false;

    nodeType* newNode = new nodeType;
    newNode->info = newItem;
    newNode->link = nullptr;

    if (position == 0)
    {
        newNode->link = first;
        first = newNode;

        if (count == 0)
            last = newNode;
    }
    else
    {
        nodeType* current = first;

        for (int i = 0; i < position - 1; i++)
            current = current->link;

        newNode->link = current->link;
        current->link = newNode;

        if (position == count)
            last = newNode;
    }

    count++;
    return true;
}

bool linkedListType::deleteAt(int position)
{
    if (position < 0 || position >= count)
        return false;

    nodeType* current;

    if (position == 0)
    {
        current = first;
        first = first->link;

        if (count == 1)
            last = nullptr;
    }
    else
    {
        nodeType* previous = first;

        for (int i = 0; i < position - 1; i++)
            previous = previous->link;

        current = previous->link;
        previous->link = current->link;

        if (current == last)
            last = previous;
    }

    delete current;
    count--;
    return true;
}

extPersonType linkedListType::getAt(int position) const
{
    if (position < 0 || position >= count)
        return extPersonType();

    nodeType* current = first;

    for (int i = 0; i < position; i++)
        current = current->link;

    return current->info;
}

bool linkedListType::setAt(
    const extPersonType& newItem, int position)
{
    if (position < 0 || position >= count)
        return false;

    nodeType* current = first;

    for (int i = 0; i < position; i++)
        current = current->link;

    current->info = newItem;
    return true;
}

void linkedListType::clear()
{
    while (first != nullptr)
    {
        nodeType* temp = first;
        first = first->link;
        delete temp;
    }

    last = nullptr;
    count = 0;
}
