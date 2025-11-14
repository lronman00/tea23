#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

// Teil 3: Funktionen mit Zeigern
void changeValueByParameter(int value) {
    value = 99;
    fmt::print("In changeValueByParameter: Wert = {}\n", value);
}

void changeValueByPointer(int* ptr) {
    *ptr = 77;
    fmt::print("In changeValueByPointer: Wert = {}\n", *ptr);
}

int main(int argc, char **argv) {
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    fmt::print("\n=== TEIL 1: Zeiger-Grundlagen ===\n");
    
    // 1. int-Variable x mit Wert 10
    int x = 10;
    fmt::print("1. x = {}\n", x);
    
    // 2. Zeiger p, der auf x zeigt
    int* p = &x;
    fmt::print("2. Zeiger p zeigt auf x\n");
    
    // 3. Wert und Adresse von x ausgeben
    fmt::print("3. Wert von x: {}, Adresse von x: {}\n", x, fmt::ptr(&x));
    
    // 4. Wert und Adresse über p ausgeben
    fmt::print("4. Wert über p: {}, Adresse in p: {}\n", *p, fmt::ptr(p));
    
    // 5. Wert von x über p auf 42 ändern
    *p = 42;
    fmt::print("5. Wert von x über p auf 42 geändert\n");
    
    // 6. Erneut Werte ausgeben
    fmt::print("6. Neuer Wert von x: {}, Wert über p: {}\n", x, *p);

    fmt::print("\n=== TEIL 2: Dynamische Speicherverwaltung ===\n");
    
    // 1. Zeiger auf double deklarieren
    double* d_ptr;
    
    // 2. Speicher für einen double-Wert reservieren und initialisieren
    d_ptr = new double(3.1415);
    fmt::print("1. Speicher für double reserviert und initialisiert\n");
    
    // 3. Wert und Adresse ausgeben
    fmt::print("2. Wert: {}, Adresse: {}\n", *d_ptr, fmt::ptr(d_ptr));
    
    // 4. Speicher wieder freigeben
    delete d_ptr;
    fmt::print("3. Speicher mit delete freigegeben\n");

    fmt::print("\n=== TEIL 3: Funktionen mit Zeigern ===\n");
    
    // 1. int-Variable y deklarieren
    int y = 5;
    fmt::print("Vor Funktionsaufrufen: y = {}\n", y);
    
    // 2. changeValueByParameter aufrufen
    fmt::print("\nAufruf von changeValueByParameter(y):\n");
    fmt::print("Vor Aufruf: y = {}\n", y);
    changeValueByParameter(y);
    fmt::print("Nach Aufruf: y = {}\n", y);
    fmt::print("→ y hat sich NICHT verändert (Call by Value)\n");
    
    // 3. changeValueByPointer aufrufen
    fmt::print("\nAufruf von changeValueByPointer(&y):\n");
    fmt::print("Vor Aufruf: y = {}\n", y);
    changeValueByPointer(&y);
    fmt::print("Nach Aufruf: y = {}\n", y);
    fmt::print("→ y hat sich VERÄNDERT (Call by Pointer)\n");

    return 0;
}