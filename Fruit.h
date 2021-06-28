#pragma once
namespace Mikhalskiy17 
{
	using namespace System;

	public ref class Fruit : IComparable
	{
	public:
		Fruit(String^ name, String^ _date, double^ pounds);
		String^ GetName();
		String^ GetDate();
		double^ GetPounds();
		virtual int CompareTo(System::Object^ obj);
	private:
		String^ _name;
		String^ _date;
		double^ _pounds;
	};
}