#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include"Elements.h"
#include "Pizza.h"
using namespace std;


void Menu(Elements& stock) {
    vector<Pizza> pizzas;
    Pizza piza;
    string filename = "pizzas.txt";
    int choice;

    while (true) {
        system("cls");
        cout << "[1] - Show stock;\n[2] - Create and order a pizza;\n[3] - Show pizzas;\n[4] - Save to file;\n[5] - Load from file;\n[6] - Exit;\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            stock.ShowStock();
            system("pause");
            break;

        case 2: {
            string name;
            int count;
            vector<string> ingrNames;
            vector<float> ingrQuantities;
            float mass, price;

            cin.ignore();
            cout << "Enter pizza name: ";
            getline(cin, name);

            cout << "Enter number of ingredients: ";
            cin >> count;

            for (int i = 0; i < count; i++) {
                string ingredient;
                float quantity;
                cout << "Enter ingredient #" << (i + 1) << ": ";
                cin >> ingredient;
                cout << "Enter quantity (g): ";
                cin >> quantity;
                ingrNames.push_back(ingredient);
                ingrQuantities.push_back(quantity);
            }

            cout << "Enter mass (g): ";
            cin >> mass;
            cout << "Enter price: $";
            cin >> price;

            Pizza newPizza(name, ingrNames, ingrQuantities, mass, price);
            if (newPizza.Order(stock)) {
                pizzas.push_back(newPizza);
                cout << "Pizza ordered successfully!" << endl;
            }
            else {
                cout << "Failed to order pizza due to insufficient stock!" << endl;
            }
            system("pause");
            break;
        }

        case 3:
            if (pizzas.empty()) {
                cout << "No pizzas ordered yet!" << endl;
            }
            else {
                for (const auto& pizza : pizzas) {
                    pizza.Show();
                }
            }
            system("pause");
            break;

        case 4:
            for (const auto& pizza : pizzas) {
                if (!pizza.SaveToFile(filename)) {
                    cout << "Failed to save some pizzas to file!" << endl;
                }
            }
            cout << "Pizzas saved to file!" << endl;
            system("pause");
            break;

        case 5:
            if (piza.LoadFromFile(filename, pizzas)) {
                std::cout << "Pizzas loaded successfully!" << std::endl;
            }
            else {
                cout << "Failed to load pizzas from file!" << std::endl;
            }
            system("pause");
            break;
        case 6:
            return;

        default:
            cout << "Invalid choice! Try again." << endl;
            system("pause");
            break;
        }
    }
}

int main() {
    Elements stock;
    Menu(stock);
}