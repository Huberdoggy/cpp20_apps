#pragma once

#include "common_includes.h"

double heightCalc(double m, double g);
void printResult(int seconds, double nm);
bool validateInput(const std::string u_imp, const std::regex re);