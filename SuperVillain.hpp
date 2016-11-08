///**************************************************************************************************
/// file:	SuperVillain.hpp
/// <author>Joshua Wright</author>
/// <date>2016-11-04</date>
///*************************************************************************************************
#pragma once
#include"Super.hpp"

namespace SuperWorld
{

#define Joker SuperVillain("Joker")

	///**************************************************************************************************
	///<summary> A super villain.</summary>
	///<remarks> Joshua Wright, 2016-11-04.</remarks>
	///*************************************************************************************************
	class SuperVillain : public Super
	{
	public:
		static unsigned SuperVillainCount;
		typedef std::shared_ptr<SuperVillain>	pointer_type;
		typedef std::unique_ptr<SuperVillain>	upointer_type;
		///**************************************************************************************************
		///<summary> Initializes a new instance of the SuperVillain class.</summary>
		///<remarks> Joshua Wright, 2016-11-04.</remarks>
		///<param name="n"> [in] The std::string to process.</param>
		///*************************************************************************************************
		SuperVillain(std::string n) :Super(n) { SuperVillainCount++; }
	};
};