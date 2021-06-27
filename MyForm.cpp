#include "MyForm.h"
#include <iostream>
#include "pch.h"

using namespace Mikhalskiy17;
using namespace System;

System::Void MyForm::WirehouseUploadButton_Click(System::Object^ sender, System::EventArgs^ e) {
	OleDbConnection^ dbConnection = gcnew OleDbConnection(L"provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb");

	dbConnection->Open(); //открываем соединение
	OleDbCommand^ dbComand = gcnew OleDbCommand("SELECT * FROM [Wirehouses]", dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//считываем данные

	//Проверяем данные
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Ошибка считывания данных!", "Warning!");
	}
	else
	{ //заполним данные в табоицу формы
		while (dbReader->Read())
		{
			if (!(CheckName(dbReader["Wirehouse"]->ToString()) && CheckName(dbReader["Fruit"]->ToString()) && CheckDate(dbReader["Date"]->ToString()) && CheckPounds(Convert::ToDouble(dbReader["Pounds"]))))
			{
				MessageBox::Show("Incorrect data!", "Attention!");
				return System::Void();
			}
			Wirehouse->Rows->Add(dbReader["ID"], dbReader["Wirehouse"], dbReader["Fruit"], dbReader["Date"], dbReader["Pounds"]);

			bool isExist = false;
			for each (Mikhalskiy17::Wirehouse ^ var in _wirehouses)
			{
				if (String::Compare(var->GetName(), dbReader["Wirehouse"]->ToString()) == 0)
				{
					isExist = true;
					var->AddFruit(gcnew Fruit(dbReader["Fruit"]->ToString(), dbReader["Wirehouse"]->ToString(), Convert::ToDouble(dbReader["Pounds"])));
				}
			}

			if (!isExist)
			{
				_wirehouses->Add(gcnew Mikhalskiy17::Wirehouse(dbReader["Wirehouse"]->ToString()));
				_wirehouses[_wirehouses->Count - 1]->AddFruit(gcnew Fruit(dbReader["Fruit"]->ToString(), dbReader["Date"]->ToString(), Convert::ToDouble(dbReader["Pounds"])));
			}
		}
	}

	//Закрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}

System::Void MyForm::WirehouseAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = this->Wirehouse->SelectedRows[0]->Index;

	if (_CheckDataGrid(index))
	{
		System::Void();
	}

	String^ id = this->Wirehouse->Rows[index]->Cells[0]->Value->ToString();
	String^ wirehouse = this->Wirehouse->Rows[index]->Cells[1]->Value->ToString();
	String^ fruit = this->Wirehouse->Rows[index]->Cells[2]->Value->ToString();
	String^ date = this->Wirehouse->Rows[index]->Cells[3]->Value->ToString();
	double^ pounds = Convert::ToDouble(this->Wirehouse->Rows[index]->Cells[4]->Value);

	if (!(CheckName(wirehouse) && CheckName(fruit) && CheckDate(date) && CheckPounds(pounds)))
	{
		MessageBox::Show("Incorrect data!", "Attention!");
		return System::Void();
	}
	bool isExist = false;
	for each (Mikhalskiy17::Wirehouse ^ var in _wirehouses)
	{
		if (var->GetName()->ToString() == wirehouse->ToString())
		{
			isExist = true;
			var->AddFruit(gcnew Fruit(fruit, date, pounds));
		}
	}

	if (!isExist)
	{
		_wirehouses->Add(gcnew Mikhalskiy17::Wirehouse(wirehouse));
		_wirehouses[_wirehouses->Count - 1]->AddFruit(gcnew Fruit(fruit, date, pounds));
	}

	String^ query = "INSERT INTO [Wirehouses] VALUES (" + id + ", '" + wirehouse + "', '" + fruit + "', '" + date + "', '" + pounds + "')";
	_DBRequest(query);

	return System::Void();
}

System::Void MyForm::WirehouseUpdateButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = this->Wirehouse->SelectedRows[0]->Index;

	if (_CheckDataGrid(index))
	{
		System::Void();
	}

	String^ id = this->Wirehouse->Rows[index]->Cells[0]->Value->ToString();
	String^ wirehouse = this->Wirehouse->Rows[index]->Cells[1]->Value->ToString();
	String^ fruit = this->Wirehouse->Rows[index]->Cells[2]->Value->ToString();
	String^ date = this->Wirehouse->Rows[index]->Cells[3]->Value->ToString();
	double^ pounds = Convert::ToDouble(this->Wirehouse->Rows[index]->Cells[4]->Value);

	if (!(CheckName(wirehouse) && CheckName(fruit) && CheckDate(date) && CheckPounds(pounds)))
	{
		MessageBox::Show("Incorrect data!", "Attention!");
		return System::Void();
	}

	bool isExist = false;
	for each (Mikhalskiy17::Wirehouse ^ var in _wirehouses)
	{
		if (var->GetName() == wirehouse)
		{
			isExist = true;
			var->AddFruit(gcnew Fruit(fruit, date, pounds));
		}
	}

	if (!isExist)
	{
		_wirehouses->Add(gcnew Mikhalskiy17::Wirehouse(wirehouse));
		_wirehouses[_wirehouses->Count - 1]->AddFruit(gcnew Fruit(fruit, date, pounds));
	}

	String^ query = "DELETE FROM [Wirehouses] WHERE ID = " + id;
	_DBRequest(query);

	query = "INSERT INTO [Wirehouses] VALUES (" + id + ", '" + wirehouse + "', '" + fruit + "', '" + date + "', '" + pounds + "')";
	_DBRequest(query);

	return System::Void();
}

System::Void MyForm::WirehouseDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = this->Wirehouse->SelectedRows[0]->Index;

	if (_CheckDataGrid(index))
	{
		System::Void();
	}

	String^ id = this->Wirehouse->Rows[index]->Cells[0]->Value->ToString();
	String^ wirehouse = this->Wirehouse->Rows[index]->Cells[1]->Value->ToString();
	String^ fruit = this->Wirehouse->Rows[index]->Cells[2]->Value->ToString();
	String^ date = this->Wirehouse->Rows[index]->Cells[3]->Value->ToString();
	double^ pounds = Convert::ToDouble(this->Wirehouse->Rows[index]->Cells[4]->Value);

	for (int i = 0; i < _wirehouses->Count; ++i)
	{

		if (_wirehouses[i]->GetName() == wirehouse)
		{
			for (int j = 0; j < _wirehouses[i]->GetFruits()->Count; ++j)
			{
				if (_wirehouses[i]->GetFruits()[j]->GetName() == fruit && _wirehouses[i]->GetFruits()[j]->GetDate() == date && _wirehouses[i]->GetFruits()[j]->GetPounds() == pounds)
				{
					_wirehouses[i]->RemoveFruit(_wirehouses[i]->GetFruits()[j]);
				}
			}
		}
	}

	String^ query = "DELETE FROM [Wirehouses] WHERE ID = " + id;
	_DBRequest(query);

	this->Wirehouse->Rows->RemoveAt(index);
	return System::Void();
}

bool MyForm::_CheckDataGrid(int index)
{
	if (this->Wirehouse->SelectedRows->Count != 1)
	{
		MessageBox::Show("Choose row to add!", "Attention!");
		return true;
	}

	if (this->Wirehouse->Rows[index]->Cells[0]->Value == nullptr ||
		this->Wirehouse->Rows[index]->Cells[1]->Value == nullptr ||
		this->Wirehouse->Rows[index]->Cells[2]->Value == nullptr ||
		this->Wirehouse->Rows[index]->Cells[3]->Value == nullptr ||
		this->Wirehouse->Rows[index]->Cells[4]->Value == nullptr)
	{
		MessageBox::Show("There is empty fields!", "Attention!");
		return true;
	}

	return false;
}

bool MyForm::_CheckOrderDataGrid(int index)
{
	if (this->PurchaseOrder->SelectedRows->Count != 1)
	{
		MessageBox::Show("Choose row to add!", "Attention!");
		return true;
	}

	if (this->PurchaseOrder->Rows[index]->Cells[0]->Value == nullptr ||
		this->PurchaseOrder->Rows[index]->Cells[1]->Value == nullptr ||
		this->PurchaseOrder->Rows[index]->Cells[2]->Value == nullptr ||
		this->PurchaseOrder->Rows[index]->Cells[3]->Value == nullptr ||
		this->PurchaseOrder->Rows[index]->Cells[4]->Value == nullptr)
	{
		MessageBox::Show("There is empty fields!", "Attention!");
		return true;
	}

	return false;
}
System::Void MyForm::_DBRequest(String^ query)
{
	String^ connectionString = "provider=Microsoft.Jet.OLEDB.4.0; Data Source=Database.mdb";
	OleDbConnection^ dbConnection = gcnew OleDbConnection(connectionString);

	dbConnection->Open();


	try
	{
		OleDbCommand^ dbComand;
		dbComand = gcnew OleDbCommand(query, dbConnection);

		if (dbComand->ExecuteNonQuery() != 1)
			MessageBox::Show("Database error", "Warning!");
		else
			MessageBox::Show("Ok!", "Succesful!");
	}
	catch (const System::Exception^)
	{
		MessageBox::Show("Key error", "Warning!");
	}

	dbConnection->Close();

	return System::Void();
}

System::Void MyForm::OrderUploadButton_Click(System::Object^ sender, System::EventArgs^ e) {
	OleDbConnection^ dbConnection = gcnew OleDbConnection(L"provider=Microsoft.Jet.OLEDB.4.0;Data Source=Database.mdb");

	dbConnection->Open(); //открываем соединение
	OleDbCommand^ dbComand = gcnew OleDbCommand("SELECT * FROM [Orders]", dbConnection);
	OleDbDataReader^ dbReader = dbComand->ExecuteReader();//считываем данные

	//Проверяем данные
	if (dbReader->HasRows == false)
	{
		MessageBox::Show("Ошибка считывания данных!", "Warning!");
	}
	else
	{ //заполним данные в табоицу формы
		while (dbReader->Read())
		{
			if (!(CheckName(dbReader["Order"]->ToString()) && CheckName(dbReader["Fruit"]->ToString()) && CheckDate(dbReader["Date"]->ToString()) && CheckPounds(Convert::ToDouble(dbReader["Pounds"]))))
			{
				MessageBox::Show("Incorrect data!", "Attention!");
				return System::Void();
			}
			PurchaseOrder->Rows->Add(dbReader["ID"], dbReader["Order"], dbReader["Fruit"], dbReader["Date"], dbReader["Pounds"]);

			bool isExist = false;
			for each (Mikhalskiy17::PurchaseOrder ^ var in _orders)
			{
				if (String::Compare(var->GetName(), dbReader["Order"]->ToString()) == 0)
				{
					isExist = true;
					var->AddFruit(gcnew Fruit(dbReader["Fruit"]->ToString(), dbReader["Order"]->ToString(), Convert::ToDouble(dbReader["Pounds"])));
				}
			}

			if (!isExist)
			{
				_orders->Add(gcnew Mikhalskiy17::PurchaseOrder(dbReader["Order"]->ToString()));
				_orders[_orders->Count - 1]->AddFruit(gcnew Fruit(dbReader["Fruit"]->ToString(), dbReader["Date"]->ToString(), Convert::ToDouble(dbReader["Pounds"])));
			}
		}
	}

	//Закрываем соединение
	dbReader->Close();
	dbConnection->Close();

	return System::Void();
}
System::Void MyForm::OrderAddButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = this->PurchaseOrder->SelectedRows[0]->Index;

	if (_CheckOrderDataGrid(index))
	{
		System::Void();
	}

	String^ id = this->PurchaseOrder->Rows[index]->Cells[0]->Value->ToString();
	String^ order = this->PurchaseOrder->Rows[index]->Cells[1]->Value->ToString();
	String^ fruit = this->PurchaseOrder->Rows[index]->Cells[2]->Value->ToString();
	String^ date = this->PurchaseOrder->Rows[index]->Cells[3]->Value->ToString();
	double^ pounds = Convert::ToDouble(this->PurchaseOrder->Rows[index]->Cells[4]->Value);

	if (!(CheckName(order) && CheckName(fruit) && CheckDate(date) && CheckPounds(pounds)))
	{
		MessageBox::Show("Incorrect data!", "Attention!");
		return System::Void();
	}

	bool isExist = false;
	for each (Mikhalskiy17::PurchaseOrder ^ var in _orders)
	{
		if (var->GetName()->ToString() == _orders->ToString())
		{
			isExist = true;
			var->AddFruit(gcnew Fruit(fruit, date, pounds));
		}
	}

	if (!isExist)
	{
		_orders->Add(gcnew Mikhalskiy17::PurchaseOrder(order));
		_orders[_orders->Count - 1]->AddFruit(gcnew Fruit(fruit, date, pounds));
	}

	String^ query = "INSERT INTO [Orders] VALUES (" + id + ", '" + order + "', '" + fruit + "', '" + date + "', '" + pounds + "')";
	_DBRequest(query);

	return System::Void();
}
System::Void MyForm::OrderUpdateButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = this->PurchaseOrder->SelectedRows[0]->Index;

	if (_CheckOrderDataGrid(index))
	{
		System::Void();
	}

	String^ id = this->PurchaseOrder->Rows[index]->Cells[0]->Value->ToString();
	String^ order = this->PurchaseOrder->Rows[index]->Cells[1]->Value->ToString();
	String^ fruit = this->PurchaseOrder->Rows[index]->Cells[2]->Value->ToString();
	String^ date = this->PurchaseOrder->Rows[index]->Cells[3]->Value->ToString();
	double^ pounds = Convert::ToDouble(this->PurchaseOrder->Rows[index]->Cells[4]->Value);

	if (!(CheckName(order) && CheckName(fruit) && CheckDate(date) && CheckPounds(pounds)))
	{
		MessageBox::Show("Incorrect data!", "Attention!");
		return System::Void();
	}

	bool isExist = false;
	for each (Mikhalskiy17::PurchaseOrder ^ var in _orders)
	{
		if (var->GetName() == order)
		{
			isExist = true;
			var->AddFruit(gcnew Fruit(fruit, date, pounds));
		}
	}

	if (!isExist)
	{
		_orders->Add(gcnew Mikhalskiy17::PurchaseOrder(order));
		_orders[_orders->Count - 1]->AddFruit(gcnew Fruit(fruit, date, pounds));
	}

	String^ query = "DELETE FROM [Wirehouses] WHERE ID = " + id;
	_DBRequest(query);

	query = "INSERT INTO [Orders] VALUES (" + id + ", '" + order + "', '" + fruit + "', '" + date + "', '" + pounds + "')";
	_DBRequest(query);

	return System::Void();
}
System::Void MyForm::OrderDeleteButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int index = this->PurchaseOrder->SelectedRows[0]->Index;

	if (_CheckOrderDataGrid(index))
	{
		System::Void();
	}

	String^ id = this->PurchaseOrder->Rows[index]->Cells[0]->Value->ToString();
	String^ order = this->PurchaseOrder->Rows[index]->Cells[1]->Value->ToString();
	String^ fruit = this->PurchaseOrder->Rows[index]->Cells[2]->Value->ToString();
	String^ date = this->PurchaseOrder->Rows[index]->Cells[3]->Value->ToString();
	double^ pounds = Convert::ToDouble(this->PurchaseOrder->Rows[index]->Cells[4]->Value);

	for (int i = 0; i < _orders->Count; ++i)
	{

		if (_orders[i]->GetName() == order)
		{
			for (int j = 0; j < _orders[i]->GetFruits()->Count; ++j)
			{
				if (_orders[i]->GetFruits()[j]->GetName() == fruit && _orders[i]->GetFruits()[j]->GetDate() == date && _orders[i]->GetFruits()[j]->GetPounds() == pounds)
				{
					_orders[i]->RemoveFruit(_orders[i]->GetFruits()[j]);
				}
			}
		}
	}

	String^ query = "DELETE FROM [Orders] WHERE ID = " + id;
	_DBRequest(query);

	this->PurchaseOrder->Rows->RemoveAt(index);
}
System::Void MyForm::AddOrder_Click(System::Object^ sender, System::EventArgs^ e) {
	Orders->Items->Add(OrderLine->Text);
}
System::Void MyForm::DeleteOrder_Click(System::Object^ sender, System::EventArgs^ e) {
	Orders->Items->Remove(Orders->SelectedItem);
}
System::Void MyForm::AddWirehouse_Click(System::Object^ sender, System::EventArgs^ e) {
	Wirehouses->Items->Add(WirehouseLine->Text);
}
System::Void MyForm::DeleteWirehouse_Click(System::Object^ sender, System::EventArgs^ e) {
	Wirehouses->Items->Remove(Wirehouses->SelectedItem);
}
System::Void MyForm::Search_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Collections::Generic::SortedSet<Fruit^>^ items = gcnew System::Collections::Generic::SortedSet<Fruit^>();

	for each (Mikhalskiy17::Wirehouse ^ var in _wirehouses)
	{
		for each (Fruit ^ f in var->GetFruits())
		{
			for each (Mikhalskiy17::PurchaseOrder ^ order in _orders)
			{
				for each (Fruit ^ ff in order->GetFruits())
				{
					if (f->GetName() == ff->GetName())
					{
						Output->Items->Add(f->GetName());
					}
				}
			}
		}
	}
}

bool MyForm::CheckName(String^ name)
{
	if (name == "") return false;
	return true;
}

bool MyForm::CheckDate(String^ date)
{
	return Regex::IsMatch(date,
		"^\d{4}-((0\d)|(1[012]))-(([012]\d)|3[01])$",
		RegexOptions::IgnoreCase, TimeSpan::FromMilliseconds(250));
}

bool MyForm::CheckPounds(double^ pounds)
{
	return &pounds > 0;
}