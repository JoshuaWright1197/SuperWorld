///**************************************************************************************************
/// file:	Super.hpp
/// <author>Joshua Wright</author>
/// <date>2016-11-04</date>
///*************************************************************************************************
#pragma once
#include<string>
#include<random>
#include<memory>
#include<sstream>
#include<iostream>
#include<ctime>

namespace SuperWorld
{
	typedef int		HP;
	///**************************************************************************************************
	///<summary> A super.</summary>
	///<remarks> Joshua Wright, 2016-11-04.</remarks>
	///*************************************************************************************************
	class Super
	{
	public:
		typedef std::shared_ptr<Super>		pointer_type;
		typedef std::unique_ptr<Super>		upointer_type;
		
	private:
		std::string name_;
		HP hp_;

	public:
		static unsigned SuperCount;
		///**************************************************************************************************
		///<summary> Initializes a new instance of the Super class.</summary>
		///<remarks> Joshua Wright, 2016-11-04.</remarks>
		///<param name="n"> The std::string to process.</param>
		///*************************************************************************************************
		Super(std::string n);		
		///**************************************************************************************************
		///<summary> Gets the hit.</summary>
		///<remarks> Joshua Wright, 2016-11-04.</remarks>
		///<returns> A HP.</returns>
		///*************************************************************************************************
		HP Hit() const;

		std::string getName() const { return name_; }
		void setName(std::string val) { name_ = val; }
		HP getHp() const { return hp_; }
		void setHp(HP val) { hp_ = val; }
		///**************************************************************************************************
		///<summary> Converts this object to a string.</summary>
		///<remarks> Joshua Wright, 2016-11-04.</remarks>
		///<returns> This object as a std::string.</returns>
		///*************************************************************************************************
		std::string to_string() const;
		///**************************************************************************************************
		///<summary> Finalizes an instance of the Super class.</summary>
		///<remarks> Joshua Wright, 2016-11-04.</remarks>
		///*************************************************************************************************
		virtual ~Super() {}
	};
};
