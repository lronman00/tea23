#include "list.hpp"

// -----------------------
// 2.1 Knotenverwaltung
// -----------------------

ListNode_t* NewListNode(void)
{
    // Speicher für neuen Knoten
    ListNode_t* node = new ListNode_t;

    // Vorgaben aus der Aufgabe
    node->data  = 0;
    node->pNext = nullptr;

    return node;
}

void FreeListNode(ListNode_t* elem)
{
    // Element wird nur freigegeben, NICHT aus der Liste entfernt
    delete elem;
}

// -----------------------
// 2.2 Listenverwaltung
// -----------------------

List_t* NewList(void)
{
    List_t* list = new List_t;

    list->pHead = nullptr;
    list->pTail = nullptr;
    list->size  = 0;

    return list;
}

void FreeList(List_t* list)
{
    if (!list) return;

    // Alle Knoten traversieren und freigeben
    ListNode_t* current = list->pHead;
    while (current != nullptr)
    {
        ListNode_t* next = current->pNext;
        FreeListNode(current);
        current = next;
    }

    // Liste selbst freigeben
    delete list;
}

// -----------------------
// 2.3 Einfügen
// -----------------------

int InsertIntoLinkedList(List_t* list, ListNode_t* elem)
{
    if (!list || !elem) return -1;

    // Wir fügen am Ende ein → elem zeigt danach auf nichts
    elem->pNext = nullptr;

    if (list->pHead == nullptr)
    {
        // Sonderfall: leere Liste
        list->pHead = elem;
        list->pTail = elem;
    }
    else
    {
        // Nicht-leere Liste → an pTail anhängen
        list->pTail->pNext = elem;
        list->pTail = elem;
    }

    list->size++;
    return 0;
}

int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem)
{
    if (!list || !node || !elem) return -1;

    // elem hinter node einfügen
    elem->pNext = node->pNext;
    node->pNext = elem;

    // Wenn node bisher das letzte Element war, Tail anpassen
    if (list->pTail == node)
    {
        list->pTail = elem;
    }

    list->size++;
    return 0;
}

// -----------------------
// 2.4 Entfernen
// -----------------------

int RemoveFromList(List_t* list, ListNode_t* elem)
{
    if (!list || !elem) return -1;
    if (!list->pHead)    return -1;

    ListNode_t* prev = nullptr;
    ListNode_t* curr = list->pHead;

    // Vorgänger von elem suchen
    while (curr != nullptr && curr != elem)
    {
        prev = curr;
        curr = curr->pNext;
    }

    // Element nicht gefunden
    if (!curr) return -1;

    // curr == elem

    // Sonderfall: Element ist Kopf
    if (prev == nullptr)
    {
        list->pHead = curr->pNext;
    }
    else
    {
        // Element liegt irgendwo in der Mitte oder am Ende
        prev->pNext = curr->pNext;
    }

    // Sonderfall: Element ist Tail
    if (curr == list->pTail)
    {
        list->pTail = prev;
    }

    FreeListNode(curr);

    // Größe anpassen (nur wenn > 0)
    if (list->size > 0)
        list->size--;

    return 0;
}

// -----------------------
// 2.5 Traversieren
// -----------------------

ListNode_t* GetNext(const List_t* list, ListNode_t* elem)
{
    if (!list) return nullptr;

    // Start eines Traversals
    if (elem == nullptr)
    {
        return list->pHead;
    }

    // Nächstes Element
    return elem->pNext;
}
