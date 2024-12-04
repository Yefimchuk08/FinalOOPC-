#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Elements.h"
#include <string>
#include <sstream>

using namespace std;

class Pizza
{
	string name;
	vector<string> ingredients;
	vector<float> quantities;
	float mass;
	float price;

public:
	Pizza();

	Pizza(string n, vector<string> ingr, vector<float> qty, float m, float p);

	void Show()const;

	bool Order(Elements& stock);

	bool SaveToFile(const string& path) const;

	bool LoadFromFile(const string& path, vector<Pizza>& pizzas);
};