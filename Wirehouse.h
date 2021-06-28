#pragma once
#include "Fruit.h"
#include "PurchaseOrder.h"

namespace Mikhalskiy17
{
	using namespace System;
	using namespace System::Collections::Generic;

	public ref class Wirehouse
	{
	public:
		Wirehouse(String^ name);
		String^ GetName();
		List<Fruit^>^ GetFruits();
		Void AddFruit(Fruit^ fruit);
		List<Fruit^>^ SearchByOrder(PurchaseOrder^ order);
		System::Void RemoveFruit(Fruit^ f);
	private:
		String^ _name;
		SortedSet<Fruit^>^ _fruits;
	};
}