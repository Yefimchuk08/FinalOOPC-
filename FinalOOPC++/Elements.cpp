#include "Elements.h"

bool Elements::DeductIngredients(const vector<string>& ingrNames, const vector<float>& ingrQuant) {
    for (size_t i = 0; i < ingrNames.size(); i++) {
        const string& ingredient = ingrNames[i];
        float requiredQuant = ingrQuant[i];

        bool found = false;
        for (size_t j = 0; j < name.size(); j++) {
            if (name[j] == ingredient) {
                found = true;
                if (quantities[j] < requiredQuant) {
                    cout << "Not enough " << ingredient << " in stock!" << endl;
                    return false;
                }
                break;
            }
        }

        if (!found) {
            cout << "Ingredient " << ingredient << " not found in stock!" << endl;
            return false;
        }
    }

    
    for (size_t i = 0; i < ingrNames.size(); i++) {
        for (size_t j = 0; j < name.size(); j++) {
            if (name[j] == ingrNames[i]) {
                quantities[j] -= ingrQuant[i];
                break;
            }
        }
    }

    return true;
}

void Elements::ShowStock() const {
    cout << "Current stock: " << endl;
    for (size_t i = 0; i < name.size(); i++) {
        cout << name[i] << ": " << quantities[i] << " grams" << endl;
    }
}
