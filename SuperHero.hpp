///**************************************************************************************************
/// file:	SuperHero.hpp
/// <author>Joshua Wright</author>
/// <date>2016-11-04</date>
///*************************************************************************************************
#pragma once
#include"Super.hpp"

namespace SuperWorld
{

#define SpiderMan SuperHero("Spiderman")

	///**************************************************************************************************
	///<summary> A super hero.</summary>
	///<remarks> Joshua Wright, 2016-11-04.</remarks>
	///*************************************************************************************************
	class SuperHero : public Super
	{
	public: 
		static unsigned SuperHeroCount;
		typedef std::shared_ptr<SuperHero>	pointer_type;
		typedef std::unique_ptr<SuperHero>	upointer_type;
		///**************************************************************************************************
		///<summary> Initializes a new instance of the SuperHero class.</summary>
		///<remarks> Joshua Wright, 2016-11-04.</remarks>
		///<param name="n"> [in] The std::string to process.</param>
		///*************************************************************************************************
		SuperHero(std::string n) :Super(n) { SuperHeroCount++; }
	};

};
