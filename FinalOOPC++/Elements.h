#pragma once
#include <iostream>
#include <vector>
#include<string>
using namespace std;

struct Elements {
	vector<string> name = { "mozzarella", "salami", "pineapple", "tomato", "papper", "chicken", "olives", "mushrooms", "parmezan", "dor blue", "bacon" };
	vector<float> quantities = { 2000, 2000, 500, 800, 600, 700, 800, 1000, 600, 400, 600 };	
	vector<float> pricesForG = { 0.3, 0.4, 0.15, 0.1, 0.12, 0.2, 0.17, 0.2, 0.6, 0.45, 0.07 };
	bool DeductIngredients(const vector<string>& inghrNames, const vector<float>& ingrQuant);
	void ShowStock()const;
	float CalculateCost(const vector<string>& ingrNames, const vector<float>& ingrQuantities);
	void AddIngredients(const vector<string>& ingrNames, const vector<float>& ingrQuantities);
};
