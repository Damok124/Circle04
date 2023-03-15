#include "MaClasse.hpp"

int main() {
    MaClasse obj1; // Appel du constructeur par défaut
    MaClasse obj3(obj1); // Appel du constructeur de copie
    obj1 = obj3; // Appel de l'opérateur d'affectation
    return 0;
}
