////////////////////////////////////////////////////////////////////////////////////////////////////
// file:	Super.cpp
// Coder:	Joshua Wright
// Date:	2016-11-03
// summary:	Implements the super class implementation
////////////////////////////////////////////////////////////////////////////////////////////////////
#include"Super.hpp"
using namespace std;

namespace SuperWorld
{
	unsigned Super::SuperCount = 0;

	Super::Super(string n):name_(n) {
		random_device rd;
		default_random_engine engine(rd());
		uniform_int_distribution<HP> range(50, 100);
		hp_ = range(engine);
		SuperCount++;
	}

	HP Super::Hit() const{
		random_device rd;
		default_random_engine engine(rd());
		uniform_int_distribution<HP> range(1, 5);
		return range(engine);
	}

	string Super::to_string() const {
		ostringstream oss;
		oss << name_ << ", HP: " << hp_;
		return oss.str();
	}
};
