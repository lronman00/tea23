#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <cstdlib>
#include <cstring>

#include "config.h"

// Aufgabe 1: Quiz-Funktion
void aufgabe1_quiz() {
    fmt::print("\n=== AUFGABE 1: Pointer oder Poltergeist? ===\n\n");
    
    std::vector<std::pair<std::string, std::string>> fragen = {
        {"1. Was passiert, wenn ein Pointer auf eine lokale Variable nach Funktionsende zeigt?", "a) Es entsteht ein Zombie-Pointer"},
        {"2. Warum darf free() nur auf dynamisch allozierten Speicher angewendet werden?", "b) Undefined Behavior"},
        {"3. Warum ist Rekursion gefahrlich ohne Abbruchbedingung?", "a) Stack Overflow"},
        {"4. Wie nennt man Speicher, der nie wieder freigegeben wird?", "a) Memory Leak"}
    };
    
    for(const auto& frage : fragen) {
        fmt::print("{}\n", frage.first);
        fmt::print("Antwort: {}\n\n", frage.second);
    }
    
    fmt::print("Diskussion: In Mikrocontrollersystemen sind Memory Leaks und Stack Overflows besonders kritisch,\n");
    fmt::print("da sie zu Systemabsturzen fuhren konnen und schwer zu debuggen sind!\n");
}

// Aufgabe 2: Analyse der fehlerhaften Programme
void aufgabe2_analyse() {
    fmt::print("\n=== AUFGABE 2: Der Heap der verlorenen Seelen ===\n\n");
    
    fmt::print("Beispiel 1: Der vergessene Geist\n");
    fmt::print("Fehler: Memory Leak - malloc() wird aufgerufen, aber free() fehlt\n");
    fmt::print("Losung: free(soul); am Ende der cursed() Funktion einfugen\n\n");
    
    fmt::print("Code-Korrektur:\n");
    fmt::print("void cursed() {\n");
    fmt::print("    char *soul = (char*)malloc(5);\n");
    fmt::print("    strcpy(soul, \"bool\");\n");
    fmt::print("    fmt::println(\"{}\", soul);\n");
    fmt::print("    free(soul);  // EXORZISMUS!\n");
    fmt::print("}\n\n");
    
    fmt::print("Beispiel 2: Der Zombie-Pointer\n");
    fmt::print("Fehler: Use-after-free - Pointer wird nach free() noch verwendet\n");
    fmt::print("Losung: Pointer nach free() auf nullptr setzen\n\n");
    
    fmt::print("Code-Korrektur:\n");
    fmt::print("int main() {\n");
    fmt::print("    char *ghost = (char*)malloc(5);\n");
    fmt::print("    strcpy(ghost, \"evil\");\n");
    fmt::print("    free(ghost);\n");
    fmt::print("    ghost = nullptr;  // EXORZISMUS!\n");
    fmt::print("    // fmt::println(\"{}\", ghost); wurde jetzt crashen (gut!)\n");
    fmt::print("}\n");
}

// Aufgabe 3: Stack vs. Heap Duell
void aufgabe3_duell() {
    fmt::print("\n=== AUFGABE 3: Stack vs. Heap: Das Duell der Untoten ===\n\n");
    
    fmt::print("TEAM STACK Argumente:\n");
    fmt::print("1. Ich bin schnell - Allokation in konstanter Zeit\n");
    fmt::print("2. Ich bin sicher - automatische Speicherbereinigung\n");
    fmt::print("3. Ich bin vorhersehbar - LIFO-Prinzip\n");
    fmt::print("4. Ich sterbe nur bei Overflow - ansonsten stabil!\n\n");
    
    fmt::print("TEAM HEAP Argumente:\n");
    fmt::print("1. Ich bin flexibel - dynamische Grosenanpassung\n");
    fmt::print("2. Ich bin machtig - grose Speichermengen moglich\n");
    fmt::print("3. Ich bin langlebig - lebe uber Funktionsgrenzen hinaus\n");
    fmt::print("4. Ich kontrolliere meinen eigenen Tod - manual memory management!\n\n");
    
    fmt::print("Das Siegerteam: BEIDE! Jeder hat seine Starken fur verschiedene Einsatzgebiete.\n");
}

// Aufgabe 4: Reflexion
void aufgabe4_reflexion() {
    fmt::print("\n=== AUFGABE 4: Der Exorzismus - Reflexion ===\n\n");
    
    fmt::print("Frage: Wann tritt ein Stack Overflow auf?\n");
    fmt::print("Antwort: Bei zu tiefer Rekursion oder zu grosen lokalen Variablen\n\n");
    
    fmt::print("Frage: Warum entstehen Memory Leaks?\n");
    fmt::print("Antwort: Wenn dynamisch allozierter Speicher nicht mit free()/delete freigegeben wird\n\n");
    
    fmt::print("Frage: Was ist gefahrlicher: Ein Zombie-Pointer oder ein Leak?\n");
    fmt::print("Antwort: Zombie-Pointer - sofortiger Crash vs. Leak - langsamer Speicherverbrauch\n\n");
    
    fmt::print("Frage: Wie kann man solche Fehler fruhzeitig erkennen?\n");
    fmt::print("Antwort: Mit Tools wie Valgrind, AddressSanitizer und statischer Code-Analyse\n");
}

// Demonstriert die tatsachlichen Fehler (kommentiert, da sie absturzen wurden)
void demonstriere_fehler() {
    fmt::print("\n=== FEHLER-DEMONSTRATION (kommentiert) ===\n\n");
    
    fmt::print("// FEHLER 1: Memory Leak\n");
    fmt::print("// char* leak = (char*)malloc(100);\n");
    fmt::print("// // free(leak); VERGESSEN!\n\n");
    
    fmt::print("// FEHLER 2: Use-after-free\n");
    fmt::print("// char* zombie = (char*)malloc(50);\n");
    fmt::print("// free(zombie);\n");
    fmt::print("// // strcpy(zombie, \"boo\"); ZOMBIE-POINTER!\n\n");
    
    fmt::print("// FEHLER 3: Stack Overflow\n");
    fmt::print("// void recursive_demon() { recursive_demon(); } ENDLOSE REKURSION!\n");
}

int main(int argc, char **argv) {
    fmt::print("Hello, {}!\n", "exercise-001");
    fmt::print("Willkommen zur Pointer-Exorzismus-Ubung!\n");

    aufgabe1_quiz();
    aufgabe2_analyse();
    aufgabe3_duell();
    aufgabe4_reflexion();
    demonstriere_fehler();

    fmt::print("\n=== EXORZISMUS ABGESCHLOSSEN! ===\n");
    fmt::print("Dein Code ist jetzt frei von Pointer-Poltergeistern!\n");

    return 0;
}