#include "Wirehouse.h"
#include "pch.h"

using namespace Mikhalskiy17;

Wirehouse::Wirehouse(String^ name)
{
	_name = name;
	_fruits = gcnew SortedSet<Fruit^>();
}

String^ Wirehouse::GetName()
{
	return _name;
}

List<Fruit^>^ Wirehouse::GetFruits()
{
	List<Fruit^>^ toReturn = gcnew List<Fruit^>();
	for each (Fruit^ var in _fruits)
	{
		toReturn->Add(var);
	}
	return toReturn;
}

Void Wirehouse::AddFruit(Fruit^ fruit)
{
	_fruits->Add(fruit);
	return System::Void();
}

List<Fruit^>^ Wirehouse::SearchByOrder(PurchaseOrder^ order)
{
	List<Fruit^>^ result = gcnew List<Fruit^>();
	for (int i = 0; i < order->GetFruits()->Count; ++i)
	{
		if (_fruits->Contains(order->GetFruits()[i]))
		{
			result->Add(order->GetFruits()[i]);
		}
	}

	return result;
}

System::Void Wirehouse::RemoveFruit(Fruit^ f)
{
	this->_fruits->Remove(f);
	return System::Void();
}