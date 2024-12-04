#include "Pizza.h"

Pizza::Pizza() : name("No name"), mass(0), price(0) {}

Pizza::Pizza(string n, vector<string> ingr, vector<float> qty, float m, float p)
    : name(n), ingredients(ingr), quantities(qty), mass(m), price(p) {}

void Pizza::Show() const {
    cout << "Pizza: " << name << endl;
    cout << "Ingredients: ";
    for (size_t i = 0; i < ingredients.size(); i++) {
        cout << ingredients[i] << " (" << quantities[i] << "g)";
        if (i < ingredients.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "Mass: " << mass << " grams" << endl;
    cout << "Price: $" << price << endl;
}

bool Pizza::Order(Elements& stock) {
    return stock.DeductIngredients(ingredients, quantities);
}

bool Pizza::SaveToFile(const string& path) const {
    ofstream file(path, ios::app);
    if (file.is_open()) {
        file << name << ";";
        for (size_t i = 0; i < ingredients.size(); i++) {
            file << ingredients[i] << ":" << quantities[i];
            if (i < ingredients.size() - 1) file << ",";
        }
        file << ";" << mass << ";" << price << endl;
        file.close();
        return true;
    }
    cout << "Failed to save pizza to file!" << endl;
    return false;
}

bool Pizza::LoadFromFile(const string& path, vector<Pizza>& pizzas) {
    ifstream file(path);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name, ingredientsPart, massStr, priceStr;
            getline(ss, name, ';');
            getline(ss, ingredientsPart, ';');
            getline(ss, massStr, ';');
            getline(ss, priceStr);

            vector<string> ingredients;
            vector<float> quantities;
            stringstream ingrStream(ingredientsPart);
            string ingredientPair;

            while (getline(ingrStream, ingredientPair, ',')) {
                size_t delimiterPos = ingredientPair.find(':');
                if (delimiterPos != string::npos) {
                    ingredients.push_back(ingredientPair.substr(0, delimiterPos));
                    quantities.push_back(stof(ingredientPair.substr(delimiterPos + 1)));
                }
            }
            float mass = stof(massStr);
            float price = stof(priceStr);
            pizzas.emplace_back(name, ingredients, quantities, mass, price);
        }
        file.close();
        return true;
    }
    else {
        cout << "Failed to open file!" << endl;
        return false;
    }
}
