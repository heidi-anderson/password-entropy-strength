#pragma once
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

void passwordCalc(string pp, int &ppEntropy, string &ppStrength);
int getEntropy(string pp);
string getStrength(int strength);
