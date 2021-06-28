#include "Fruit.h"

using namespace Mikhalskiy17;

Fruit::Fruit(String^ name, String^ date, double^ pounds)
{
	_name = name;
	_date = date;
	_pounds = pounds;
}

String^ Fruit::GetName()
{
	return _name;
}

String^ Fruit::GetDate()
{
	return _date;
}
double^ Fruit::GetPounds()
{
	return _pounds;
}

int Fruit::CompareTo(System::Object^ obj)
{
	if (obj == nullptr) return 1;

	Fruit^ otherFruit = (Fruit^)obj;
	if (otherFruit != nullptr)
		return this->_name->CompareTo(otherFruit->_name);
	else
		throw gcnew ArgumentException("Object is not a Temperature");
}
