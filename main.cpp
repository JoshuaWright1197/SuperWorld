///**************************************************************************************************
/// file:	main.cpp
/// <author>Joshua Wright</author>
/// <date>2016-11-04</date>
///*************************************************************************************************
#include<memory>
#include<iostream>
#include<vector>
#include"SuperWorld.hpp"
using namespace std;
using namespace SuperWorld;

int main()
{
	vector<Super::pointer_type> v;
	v.push_back(Super::pointer_type(new SpiderMan));
	v.push_back(Super::pointer_type(new SuperHero("Superman")));
	v.push_back(Super::pointer_type(new SuperHero("Batman")));
	v.push_back(Super::pointer_type(new SuperHero("Flash")));
	v.push_back(Super::pointer_type(new Joker));
	v.push_back(Super::pointer_type(new SuperVillain("LexLuthor")));
	v.push_back(Super::pointer_type(new SuperVillain("GreenGoblin")));
	v.push_back(Super::pointer_type(new SuperVillain("Magneto")));

	cout << SuperVillain::SuperVillainCount << " SuperVillain's" << endl;
	cout << SuperHero::SuperHeroCount << " SuperHero's" << endl;
	cout << Super::SuperCount << " Super's" << endl;
	cout << "Characters" << endl;
	cout << "Stating Status:" << endl;
	for (auto i : v)
		cout << i->to_string() << endl;
	cout << endl;


	random_device rd;
	default_random_engine engine(rd());
	uniform_int_distribution<int> range(0, 7);
	HP hp1;
	HP hp2;
	for (int i = 0; i < 10; ++i)
	{
		auto s1 = v[range(engine)];
		auto s2 = v[range(engine)];
		auto p1 = dynamic_pointer_cast<SuperHero>(s1);
		auto p2 = dynamic_pointer_cast<SuperVillain>(s2);

		if (p1 == nullptr && p2 == nullptr) {
			p1 = dynamic_pointer_cast<SuperHero>(s2);
			p2 = dynamic_pointer_cast<SuperVillain>(s1);
		}

		if (p2 != nullptr && p1 != nullptr) {

			cout << i + 1 << ": Fighting " << p1->to_string() << " vs " << p2->to_string() << endl;

			hp1 = p1->Hit();
			hp2 = p2->Hit();

			if (hp1 > hp2) {
				p2->setHp(p2->getHp() - hp1);
				cout << p2->getName() << " HP reduced by " << hp1 << endl;
				continue;
			}
			else if (hp2 > hp1) {
				p1->setHp(p1->getHp() - hp2);
				cout << p1->getName() << " HP reduced by " << hp2 << endl;
				continue;
			}
			cout << "Both are have the same hit power" << endl;
			continue;
		}
		if (p1 == nullptr) {
			cout << i + 1 << ": Both are Villain's " << s1->getName() << " vs " << s2->getName() << endl;
			continue;
		}
		cout << i + 1 << ": Both are Hero's " << s1->getName() << " vs " << s2->getName() << endl;
	}

	cout << endl;
	cout << "Ending Status:" << endl;
	for (auto i : v)
		cout << i->to_string() << endl;
}