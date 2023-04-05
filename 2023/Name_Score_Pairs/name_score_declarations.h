#pragma once
#include "common_includes.h"

int getSelection(const int choice, std::vector<int>& scores_v,
    std::vector<std::string>& names_v_copy);

void namesWithScore(const int score,
    std::vector<int>& scores_v, std::vector<std::string>& names_v);

inline bool printResult(const std::vector<std::string>& found);
