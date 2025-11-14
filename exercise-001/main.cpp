#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

// Teil 1: Globale Variablen
int globalVar = 1;
int globalVar2 = 100;
const int globalConst = 50;
static int globalStatic = 200;

// Teil 4: Funktionen (Code-Segment)
void foo() { 
    fmt::print("Hello from foo!\n"); 
}

int main(int argc, char **argv) {
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    fmt::print("\n=== TEIL 1: Globale Variablen (Data Segment) ===\n");
    
    // 1. Globale Variablen ausgeben
    fmt::print("globalVar: Wert = {}, Adresse = {}\n", globalVar, fmt::ptr(&globalVar));
    fmt::print("globalVar2: Wert = {}, Adresse = {}\n", globalVar2, fmt::ptr(&globalVar2));
    fmt::print("globalConst: Wert = {}, Adresse = {}\n", globalConst, fmt::ptr(&globalConst));
    fmt::print("globalStatic: Wert = {}, Adresse = {}\n", globalStatic, fmt::ptr(&globalStatic));
    
    // 4. Weitere globale Variablen
    int globalUninitialized;  // Kein Wert zugewiesen (undefined behavior)
    int globalZero = 0;       // Nullwert
    fmt::print("globalZero: Wert = {}, Adresse = {}\n", globalZero, fmt::ptr(&globalZero));
    
    // 5. Beobachtung: Alle globalen Variablen haben ähnliche Adressbereiche

    fmt::print("\n=== TEIL 2: Lokale Variablen (Stack) ===\n");
    
    // 1. Lokale Variable
    int localVar = 2;
    fmt::print("localVar: Wert = {}, Adresse = {}\n", localVar, fmt::ptr(&localVar));
    
    // 3. Mit static und const
    static int localStatic = 300;
    const int localConst = 400;
    fmt::print("localStatic: Wert = {}, Adresse = {}\n", localStatic, fmt::ptr(&localStatic));
    fmt::print("localConst: Wert = {}, Adresse = {}\n", localConst, fmt::ptr(&localConst));
    
    // 4. Vergleich der Adressen
    fmt::print("\nAdressvergleich:\n");
    fmt::print("Globale Adressen sind im niedrigen Bereich\n");
    fmt::print("Lokale Adressen sind im hohen Bereich (Stack)\n");

    fmt::print("\n=== TEIL 3: Dynamisch allozierte Variablen (Heap) ===\n");
    
    // 1. Speicher auf dem Heap reservieren
    int* heapVar = new int(3);
    fmt::print("heapVar: Wert = {}, Adresse = {}\n", *heapVar, fmt::ptr(heapVar));
    
    // 3. Vergleich der Adressen
    fmt::print("Heap-Adressen liegen zwischen globalen und lokalen Adressen\n");
    
    // 4. Speicher wieder freigeben
    delete heapVar;
    fmt::print("Speicher wurde mit delete freigegeben\n");

    fmt::print("\n=== TEIL 4: Funktionen (Code-Segment) ===\n");
    
    // 2. Adresse der Funktion ausgeben
    fmt::print("Adresse von foo: {}\n", fmt::ptr(reinterpret_cast<void*>(&foo)));
    
    // 3. Funktion aufrufen
    foo();
    
    fmt::print("\n=== ZUSAMMENFASSUNG DER SPEICHERSEGMENTE ===\n");
    fmt::print("Code-Segment: Funktionen (niedrigste Adressen)\n");
    fmt::print("Data-Segment: Globale/static Variablen\n");
    fmt::print("Heap: Dynamischer Speicher (wächst nach oben)\n");
    fmt::print("Stack: Lokale Variablen (höchste Adressen, wächst nach unten)\n");

    return 0;
}