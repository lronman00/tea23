#include <fmt/format.h>
#include "graveyard.h"


// Eigene globale Variable im Hauptmodul
int undead = 7;

int main() {
    fmt::println("🪦 Globale Variable sagt: {} (addr: {})", undead, fmt::ptr(&undead));

    awaken();       // lokale "undead" (Stack)
    persistent();   // statische lokale "undead" (Data)
    persistent();   // bleibt erhöht

    fmt::println("🪦 Globale Variable nach Aufruf: {} (addr: {})",
                 undead, fmt::ptr(&undead));

    // Bonus
    curse();

    // Adressen der globalen Variablen aus verschiedenen TUs kann man
    // nicht direkt alle hier auslesen, aber man sieht unterschiedliche
    // Werte & Adressen in den jeweiligen Funktionen.
    return 0;
}
