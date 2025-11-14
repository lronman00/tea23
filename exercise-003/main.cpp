#include <fmt/chrono.h>
#include <fmt/format.h>
#include <iostream>
#include <string>

enum class GaragenState {
    ZU,
    AUF,
    HOCHFAHREND,
    RUNTERFAHREND,
    GESTOPPT
};

class Garagentor {
private:
    GaragenState currentState;
    bool endschalterOben;
    bool endschalterUnten;
    bool tasteGedrueckt;

public:
    Garagentor() : currentState(GaragenState::ZU), 
                   endschalterOben(false), 
                   endschalterUnten(true),
                   tasteGedrueckt(false) {}

    void setEndschalterOben(bool status) {
        endschalterOben = status;
        updateState();
    }

    void setEndschalterUnten(bool status) {
        endschalterUnten = status;
        updateState();
    }

    void setTasteGedrueckt(bool gedrueckt) {
        tasteGedrueckt = gedrueckt;
        if (gedrueckt) {
            handleTaste();
        }
    }

private:
    void handleTaste() {
        switch (currentState) {
            case GaragenState::ZU:
                fmt::print("Taste gedrückt - Fahre hoch\n");
                currentState = GaragenState::HOCHFAHREND;
                break;
                
            case GaragenState::AUF:
                fmt::print("Taste gedrückt - Fahre runter\n");
                currentState = GaragenState::RUNTERFAHREND;
                break;
                
            case GaragenState::HOCHFAHREND:
            case GaragenState::RUNTERFAHREND:
                fmt::print("Taste gedrückt - Stop\n");
                currentState = GaragenState::GESTOPPT;
                break;
                
            case GaragenState::GESTOPPT:
                fmt::print("Taste gedrückt - Fahre hoch\n");
                currentState = GaragenState::HOCHFAHREND;
                break;
        }
    }

    void updateState() {
        if (currentState == GaragenState::HOCHFAHREND && endschalterOben) {
            fmt::print("Endschalter oben erreicht - Tor offen\n");
            currentState = GaragenState::AUF;
        }
        else if (currentState == GaragenState::RUNTERFAHREND && endschalterUnten) {
            fmt::print("Endschalter unten erreicht - Tor zu\n");
            currentState = GaragenState::ZU;
        }
    }

public:
    void printStatus() {
        std::string stateStr;
        switch (currentState) {
            case GaragenState::ZU: stateStr = "ZU"; break;
            case GaragenState::AUF: stateStr = "AUF"; break;
            case GaragenState::HOCHFAHREND: stateStr = "HOCHFAHREND"; break;
            case GaragenState::RUNTERFAHREND: stateStr = "RUNTERFAHREND"; break;
            case GaragenState::GESTOPPT: stateStr = "GESTOPPT"; break;
        }
        
        fmt::print("Status: {}, Endschalter Oben: {}, Unten: {}\n", 
                   stateStr, endschalterOben, endschalterUnten);
    }
};

auto main(int argc, char** argv) -> int
{
    fmt::print("Garagentor Steuerung - {}\n", argv[0]);
    
    Garagentor tor;
    
    // Testablauf
    tor.printStatus();
    
    // Taste drücken um hochzufahren
    tor.setTasteGedrueckt(true);
    tor.printStatus();
    
    // Endschalter oben erreicht
    tor.setEndschalterOben(true);
    tor.printStatus();
    
    // Taste drücken um runterzufahren
    tor.setTasteGedrueckt(true);
    tor.printStatus();
    
    // Endschalter unten erreicht
    tor.setEndschalterUnten(true);
    tor.printStatus();
    
    // Während der Fahrt stoppen
    tor.setTasteGedrueckt(true); // Hochfahren
    tor.printStatus();
    tor.setTasteGedrueckt(true); // Stoppen
    tor.printStatus();
    tor.setTasteGedrueckt(true); // Weiterfahren
    tor.printStatus();

    return 0;
}