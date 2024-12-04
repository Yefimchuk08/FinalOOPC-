#pragma once
#include <iostream>
#include <vector>
#include<string>
using namespace std;

struct Elements {
	vector<string> name = { "mozzarella", "salami", "pineapple", "tomato", "papper", "chicken", "olives", "mushrooms", "parmezan", "dor blue", "bacon" };
	vector<float> quantities = { 2000, 2000, 500, 800, 600, 700, 800, 1000, 600, 400, 600 };
	bool DeductIngredients(const vector<string>& inghrNames, const vector<float>& ingrQuant);
	void ShowStock()const;
};