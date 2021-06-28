#include "PurchaseOrder.h"

using namespace Mikhalskiy17;

PurchaseOrder::PurchaseOrder(String^ name)
{
	_name = name;
	_fruits = gcnew List<Fruit^>();
}

String^ PurchaseOrder::GetName()
{
	return _name;
}

List<Fruit^>^ PurchaseOrder::GetFruits()
{
	return _fruits;
}

Void PurchaseOrder::AddFruit(Fruit^ fruit)
{
	_fruits->Add(fruit);
}


Void PurchaseOrder::RemoveFruit(Fruit^ f)
{
	this->_fruits->Remove(f);
	return System::Void();
}