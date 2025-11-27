#include <fmt/format.h>

#include "list.hpp"
#include "vector.hpp"

auto main(int /*argc*/, char** /*argv*/) -> int
{
    // ========================
    // 4.1 Liste testen
    // ========================

    // 1. Liste erzeugen
    List_t* list = NewList();

    // 2. Fünf neue Knoten erzeugen, Werte setzen, einfügen
    ListNode_t* n1 = NewListNode(); n1->data = 1;
    ListNode_t* n2 = NewListNode(); n2->data = 2;
    ListNode_t* n3 = NewListNode(); n3->data = 3;
    ListNode_t* n4 = NewListNode(); n4->data = 4;
    ListNode_t* n5 = NewListNode(); n5->data = 5;

    InsertIntoLinkedList(list, n1);
    InsertIntoLinkedList(list, n2);
    InsertIntoLinkedList(list, n3);
    InsertIntoLinkedList(list, n4);
    InsertIntoLinkedList(list, n5);

    // 3. Einfügen nach dem zweiten Knoten
    ListNode_t* nAfter2 = NewListNode();
    nAfter2->data = 99; // beliebiger Testwert
    InsertIntoLinkedListAfterNode(list, n2, nAfter2);

    // 4. Ein bestimmtes Element entfernen (z.B. n4)
    RemoveFromList(list, n4);

    // 5. Traversieren mit GetNext
    fmt::print("Listenelemente:\n");
    for (ListNode_t* it = GetNext(list, nullptr);
         it != nullptr;
         it = GetNext(list, it))
    {
        fmt::print("{} ", it->data);
    }
    fmt::print("\n(Listen-Groesse: {})\n\n", list->size);

    // Liste freigeben
    FreeList(list);

    // ========================
    // 4.2 Vector testen
    // ========================

    Vector_t vec;

    // 1. Vector initialisieren
    vector_init(&vec);

    // 2. Fünf Werte einfügen
    vector_push_back(&vec, 10);
    vector_push_back(&vec, 20);
    vector_push_back(&vec, 30);
    vector_push_back(&vec, 40);
    vector_push_back(&vec, 50);

    // 3. Element an Index 2 ausgeben
    unsigned int value = 0;
    if (vector_get(&vec, 2, &value) == 0) {
        fmt::print("Element an Index 2 im Vector: {}\n", value);
    } else {
        fmt::print("Fehler beim Lesen von Index 2\n");
    }

    // 4. Vector ausgeben
    fmt::print("Vector-Inhalt:\n");
    vector_print(&vec);
    fmt::print("Vector size = {}, capacity = {}\n", vec.size, vec.capacity);

    // Vector aufraeumen
    vector_clear(&vec);

    return 0;
}
