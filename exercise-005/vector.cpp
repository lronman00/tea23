#include "vector.hpp"
#include <fmt/format.h>   // für vector_print (kannst du bei Bedarf auch weglassen)
#include <new>            // optional, falls du std::nothrow verwenden willst

// Startkapazität
static const size_t VECTOR_START_CAPACITY = 4;

void vector_init(Vector_t* vec)
{
    if (!vec) return;

    vec->size     = 0;
    vec->capacity = VECTOR_START_CAPACITY;
    vec->data     = new unsigned int[vec->capacity]; // dynamisch allokieren
}

void vector_clear(Vector_t* vec)
{
    if (!vec) return;

    // Speicher für die Daten freigeben
    delete[] vec->data;

    // Zustand zurücksetzen
    vec->data     = nullptr;
    vec->size     = 0;
    vec->capacity = 0;
}

int vector_push_back(Vector_t* vec, unsigned int value)
{
    if (!vec) return -1;

    // Falls kein Speicher vorhanden (oder voll), Kapazität vergrößern
    if (vec->capacity == 0) {
        vec->capacity = VECTOR_START_CAPACITY;
        vec->data = new unsigned int[vec->capacity];
    } else if (vec->size >= vec->capacity) {
        // Kapazität verdoppeln
        size_t newCapacity = vec->capacity * 2;
        unsigned int* newData = new unsigned int[newCapacity];

        // alte Daten kopieren
        for (size_t i = 0; i < vec->size; ++i) {
            newData[i] = vec->data[i];
        }

        // alten Speicher freigeben
        delete[] vec->data;

        vec->data     = newData;
        vec->capacity = newCapacity;
    }

    // neues Element hinten anhängen
    vec->data[vec->size] = value;
    vec->size++;

    return 0;
}

int vector_get(const Vector_t* vec, size_t index, unsigned int* outValue)
{
    if (!vec || !outValue) return -1;
    if (index >= vec->size) return -1; // Index außerhalb

    *outValue = vec->data[index];
    return 0;
}

void vector_print(const Vector_t* vec)
{
    if (!vec || !vec->data) {
        fmt::print("(empty vector)\n");
        return;
    }

    for (size_t i = 0; i < vec->size; ++i) {
        fmt::print("{} ", vec->data[i]);
    }
    fmt::print("\n");
}
