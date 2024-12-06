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

float Elements::CalculateCost(const vector<string>& ingrNames, const vector<float>& ingrQuantities) {
    float totalCost = 0.0;
    for (size_t i = 0; i < ingrNames.size(); i++) {
        for (size_t j = 0; j < name.size(); j++) {
            if (name[j] == ingrNames[i]) {
              
                float ingredientPricePerGram = pricesForG[j]; 
                totalCost += ingredientPricePerGram * ingrQuantities[i];
                break;
            }
        }
    }
    return totalCost;
}
void Elements::AddIngredients(const vector<string>& ingrNames, const vector<float>& ingrQuantities) {
    for (size_t i = 0; i < ingrNames.size(); i++) {
        for (size_t j = 0; j < name.size(); j++) {
            if (name[j] == ingrNames[i]) {
                quantities[j] += ingrQuantities[i];
                break;
            }
        }
    }
}

