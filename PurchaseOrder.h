#pragma once
#include "Fruit.h"
#include "pch.h"
namespace Mikhalskiy17
{
	using namespace System;
	using namespace System::Collections::Generic;
	
	public ref class PurchaseOrder
	{
	public:
		PurchaseOrder(String^ name);
		String^ GetName();
		List<Fruit^>^ GetFruits();
		Void AddFruit(Fruit^ fruit);
		Void RemoveFruit(Fruit^ fruit);

	private:
		String^ _name;
		List<Fruit^>^ _fruits;
	};
}