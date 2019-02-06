#pragma once
#include "Export.h"
#include<iostream>
#include<vector>

using namespace std;

template<typename Target, typename... AttrTypes>
struct  builder {
	vector<Target> results;

	void operator()(AttrTypes... args) {
		results.emplace_back(std::forward<AttrTypes&&>(args)...);
	};
};