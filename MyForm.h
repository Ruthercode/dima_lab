#pragma once

#include "Wirehouse.h"
#include "PurchaseOrder.h"

namespace Mikhalskiy17 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			this->_wirehouses = gcnew System::Collections::Generic::List<Mikhalskiy17::Wirehouse^>();
			this->_orders = gcnew System::Collections::Generic::List<Mikhalskiy17::PurchaseOrder^>();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ Wirehouse;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ numb;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WirehouseName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WirehouseFruit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WirehouseDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ WirehousePounds;

	private: System::Windows::Forms::DataGridView^ PurchaseOrder;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PurchaseOrderNumb;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PurchaseOrderName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PurchaseOrderFruit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PurchaseOrderDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PurchaseOrderPounds;

	private: System::Windows::Forms::Button^ WirehouseUploadButton;
	private: System::Windows::Forms::Button^ WirehouseAddButton;
	private: System::Windows::Forms::Button^ WirehouseUpdateButton;
	private: System::Windows::Forms::Button^ WirehouseDeleteButton;
	private: System::Windows::Forms::Button^ OrderUploadButton;
	private: System::Windows::Forms::Button^ OrderAddButton;
	private: System::Windows::Forms::Button^ OrderUpdateButton;
	private: System::Windows::Forms::Button^ OrderDeleteButton;

	private: System::Windows::Forms::Label^ OrderLable;
	private: System::Windows::Forms::Label^ WirehouseLable;
	private: System::Windows::Forms::TextBox^ OrderLine;
	private: System::Windows::Forms::TextBox^ WirehouseLine;

	private: System::Windows::Forms::ListBox^ Output;
	private: System::Windows::Forms::Button^ Search;

	private: System::Windows::Forms::ListBox^ Orders;
	private: System::Windows::Forms::ListBox^ Wirehouses;

	private: System::Windows::Forms::Button^ AddOrder;
	private: System::Windows::Forms::Button^ DeleteOrder;
	private: System::Windows::Forms::Button^ AddWirehouse;
	private: System::Windows::Forms::Button^ DeleteWirehouse;
	
	private: System::Collections::Generic::List<Mikhalskiy17::Wirehouse^>^ _wirehouses;
	private: System::Collections::Generic::List<Mikhalskiy17::PurchaseOrder^>^ _orders;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Pounds;
	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Wirehouse = (gcnew System::Windows::Forms::DataGridView());
			this->numb = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WirehouseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WirehouseFruit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WirehouseDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WirehousePounds = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PurchaseOrder = (gcnew System::Windows::Forms::DataGridView());
			this->PurchaseOrderNumb = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PurchaseOrderName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PurchaseOrderFruit = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PurchaseOrderDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pounds = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->WirehouseUploadButton = (gcnew System::Windows::Forms::Button());
			this->WirehouseAddButton = (gcnew System::Windows::Forms::Button());
			this->WirehouseUpdateButton = (gcnew System::Windows::Forms::Button());
			this->WirehouseDeleteButton = (gcnew System::Windows::Forms::Button());
			this->OrderUploadButton = (gcnew System::Windows::Forms::Button());
			this->OrderAddButton = (gcnew System::Windows::Forms::Button());
			this->OrderUpdateButton = (gcnew System::Windows::Forms::Button());
			this->OrderDeleteButton = (gcnew System::Windows::Forms::Button());
			this->OrderLable = (gcnew System::Windows::Forms::Label());
			this->WirehouseLable = (gcnew System::Windows::Forms::Label());
			this->OrderLine = (gcnew System::Windows::Forms::TextBox());
			this->WirehouseLine = (gcnew System::Windows::Forms::TextBox());
			this->Output = (gcnew System::Windows::Forms::ListBox());
			this->Search = (gcnew System::Windows::Forms::Button());
			this->Orders = (gcnew System::Windows::Forms::ListBox());
			this->Wirehouses = (gcnew System::Windows::Forms::ListBox());
			this->AddOrder = (gcnew System::Windows::Forms::Button());
			this->DeleteOrder = (gcnew System::Windows::Forms::Button());
			this->AddWirehouse = (gcnew System::Windows::Forms::Button());
			this->DeleteWirehouse = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Wirehouse))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PurchaseOrder))->BeginInit();
			this->SuspendLayout();
			// 
			// Wirehouse
			// 
			this->Wirehouse->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Wirehouse->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->numb, this->WirehouseName,
					this->WirehouseFruit, this->WirehouseDate, this->WirehousePounds
			});
			this->Wirehouse->Location = System::Drawing::Point(535, 12);
			this->Wirehouse->Name = L"Wirehouse";
			this->Wirehouse->Size = System::Drawing::Size(443, 138);
			this->Wirehouse->TabIndex = 59;
			// 
			// numb
			// 
			this->numb->HeaderText = L"є";
			this->numb->Name = L"numb";
			// 
			// WirehouseName
			// 
			this->WirehouseName->HeaderText = L"Wirehouse";
			this->WirehouseName->Name = L"WirehouseName";
			// 
			// WirehouseFruit
			// 
			this->WirehouseFruit->HeaderText = L"Fruit";
			this->WirehouseFruit->Name = L"WirehouseFruit";
			// 
			// WirehouseDate
			// 
			this->WirehouseDate->HeaderText = L"Date";
			this->WirehouseDate->Name = L"WirehouseDate";
			// 
			// WirehousePounds
			// 
			this->WirehousePounds->HeaderText = L"Pounds";
			this->WirehousePounds->Name = L"WirehousePounds";
			// 
			// PurchaseOrder
			// 
			this->PurchaseOrder->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->PurchaseOrder->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->PurchaseOrderNumb,
					this->PurchaseOrderName, this->PurchaseOrderFruit, this->PurchaseOrderDate, this->Pounds
			});
			this->PurchaseOrder->Location = System::Drawing::Point(535, 262);
			this->PurchaseOrder->Name = L"PurchaseOrder";
			this->PurchaseOrder->Size = System::Drawing::Size(443, 138);
			this->PurchaseOrder->TabIndex = 60;
			// 
			// PurchaseOrderNumb
			// 
			this->PurchaseOrderNumb->HeaderText = L"є";
			this->PurchaseOrderNumb->Name = L"PurchaseOrderNumb";
			// 
			// PurchaseOrderName
			// 
			this->PurchaseOrderName->HeaderText = L"Order";
			this->PurchaseOrderName->Name = L"PurchaseOrderName";
			// 
			// PurchaseOrderFruit
			// 
			this->PurchaseOrderFruit->HeaderText = L"Fruit";
			this->PurchaseOrderFruit->Name = L"PurchaseOrderFruit";
			// 
			// PurchaseOrderDate
			// 
			this->PurchaseOrderDate->HeaderText = L"Date";
			this->PurchaseOrderDate->Name = L"PurchaseOrderDate";
			// 
			// Pounds
			// 
			this->Pounds->Name = L"Pounds";
			// 
			// WirehouseUploadButton
			// 
			this->WirehouseUploadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->WirehouseUploadButton->Location = System::Drawing::Point(554, 156);
			this->WirehouseUploadButton->Name = L"WirehouseUploadButton";
			this->WirehouseUploadButton->Size = System::Drawing::Size(96, 27);
			this->WirehouseUploadButton->TabIndex = 61;
			this->WirehouseUploadButton->Text = L"Upload";
			this->WirehouseUploadButton->UseVisualStyleBackColor = true;
			this->WirehouseUploadButton->Click += gcnew System::EventHandler(this, &MyForm::WirehouseUploadButton_Click);
			// 
			// WirehouseAddButton
			// 
			this->WirehouseAddButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->WirehouseAddButton->Location = System::Drawing::Point(656, 156);
			this->WirehouseAddButton->Name = L"WirehouseAddButton";
			this->WirehouseAddButton->Size = System::Drawing::Size(96, 27);
			this->WirehouseAddButton->TabIndex = 62;
			this->WirehouseAddButton->Text = L"Add";
			this->WirehouseAddButton->UseVisualStyleBackColor = true;
			this->WirehouseAddButton->Click += gcnew System::EventHandler(this, &MyForm::WirehouseAddButton_Click);
			// 
			// WirehouseUpdateButton
			// 
			this->WirehouseUpdateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->WirehouseUpdateButton->Location = System::Drawing::Point(758, 156);
			this->WirehouseUpdateButton->Name = L"WirehouseUpdateButton";
			this->WirehouseUpdateButton->Size = System::Drawing::Size(96, 27);
			this->WirehouseUpdateButton->TabIndex = 63;
			this->WirehouseUpdateButton->Text = L"Update";
			this->WirehouseUpdateButton->UseVisualStyleBackColor = true;
			this->WirehouseUpdateButton->Click += gcnew System::EventHandler(this, &MyForm::WirehouseUpdateButton_Click);
			// 
			// WirehouseDeleteButton
			// 
			this->WirehouseDeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->WirehouseDeleteButton->Location = System::Drawing::Point(860, 156);
			this->WirehouseDeleteButton->Name = L"WirehouseDeleteButton";
			this->WirehouseDeleteButton->Size = System::Drawing::Size(96, 27);
			this->WirehouseDeleteButton->TabIndex = 64;
			this->WirehouseDeleteButton->Text = L"Delete";
			this->WirehouseDeleteButton->UseVisualStyleBackColor = true;
			this->WirehouseDeleteButton->Click += gcnew System::EventHandler(this, &MyForm::WirehouseDeleteButton_Click);
			// 
			// OrderUploadButton
			// 
			this->OrderUploadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OrderUploadButton->Location = System::Drawing::Point(554, 406);
			this->OrderUploadButton->Name = L"OrderUploadButton";
			this->OrderUploadButton->Size = System::Drawing::Size(96, 27);
			this->OrderUploadButton->TabIndex = 68;
			this->OrderUploadButton->Text = L"Upload";
			this->OrderUploadButton->UseVisualStyleBackColor = true;
			this->OrderUploadButton->Click += gcnew System::EventHandler(this, &MyForm::OrderUploadButton_Click);
			// 
			// OrderAddButton
			// 
			this->OrderAddButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OrderAddButton->Location = System::Drawing::Point(656, 406);
			this->OrderAddButton->Name = L"OrderAddButton";
			this->OrderAddButton->Size = System::Drawing::Size(96, 27);
			this->OrderAddButton->TabIndex = 67;
			this->OrderAddButton->Text = L"Add";
			this->OrderAddButton->UseVisualStyleBackColor = true;
			this->OrderAddButton->Click += gcnew System::EventHandler(this, &MyForm::OrderAddButton_Click);
			// 
			// OrderUpdateButton
			// 
			this->OrderUpdateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OrderUpdateButton->Location = System::Drawing::Point(758, 406);
			this->OrderUpdateButton->Name = L"OrderUpdateButton";
			this->OrderUpdateButton->Size = System::Drawing::Size(96, 27);
			this->OrderUpdateButton->TabIndex = 66;
			this->OrderUpdateButton->Text = L"Update";
			this->OrderUpdateButton->UseVisualStyleBackColor = true;
			this->OrderUpdateButton->Click += gcnew System::EventHandler(this, &MyForm::OrderUpdateButton_Click);
			// 
			// OrderDeleteButton
			// 
			this->OrderDeleteButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OrderDeleteButton->Location = System::Drawing::Point(860, 406);
			this->OrderDeleteButton->Name = L"OrderDeleteButton";
			this->OrderDeleteButton->Size = System::Drawing::Size(96, 27);
			this->OrderDeleteButton->TabIndex = 65;
			this->OrderDeleteButton->Text = L"Delete";
			this->OrderDeleteButton->UseVisualStyleBackColor = true;
			this->OrderDeleteButton->Click += gcnew System::EventHandler(this, &MyForm::OrderDeleteButton_Click);
			// 
			// OrderLable
			// 
			this->OrderLable->AutoSize = true;
			this->OrderLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OrderLable->Location = System::Drawing::Point(91, 12);
			this->OrderLable->Name = L"OrderLable";
			this->OrderLable->Size = System::Drawing::Size(49, 17);
			this->OrderLable->TabIndex = 69;
			this->OrderLable->Text = L"Order:";
			// 
			// WirehouseLable
			// 
			this->WirehouseLable->AutoSize = true;
			this->WirehouseLable->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->WirehouseLable->Location = System::Drawing::Point(324, 12);
			this->WirehouseLable->Name = L"WirehouseLable";
			this->WirehouseLable->Size = System::Drawing::Size(80, 17);
			this->WirehouseLable->TabIndex = 70;
			this->WirehouseLable->Text = L"Wirehouse:";
			// 
			// OrderLine
			// 
			this->OrderLine->Location = System::Drawing::Point(23, 32);
			this->OrderLine->Name = L"OrderLine";
			this->OrderLine->Size = System::Drawing::Size(196, 20);
			this->OrderLine->TabIndex = 71;
			// 
			// WirehouseLine
			// 
			this->WirehouseLine->Location = System::Drawing::Point(263, 32);
			this->WirehouseLine->Name = L"WirehouseLine";
			this->WirehouseLine->Size = System::Drawing::Size(196, 20);
			this->WirehouseLine->TabIndex = 72;
			// 
			// Output
			// 
			this->Output->FormattingEnabled = true;
			this->Output->Location = System::Drawing::Point(23, 283);
			this->Output->Name = L"Output";
			this->Output->Size = System::Drawing::Size(436, 121);
			this->Output->TabIndex = 73;
			// 
			// Search
			// 
			this->Search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Search->Location = System::Drawing::Point(194, 410);
			this->Search->Name = L"Search";
			this->Search->Size = System::Drawing::Size(96, 27);
			this->Search->TabIndex = 74;
			this->Search->Text = L"Search";
			this->Search->UseVisualStyleBackColor = true;
			this->Search->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);
			// 
			// Orders
			// 
			this->Orders->FormattingEnabled = true;
			this->Orders->Location = System::Drawing::Point(23, 72);
			this->Orders->Name = L"Orders";
			this->Orders->Size = System::Drawing::Size(196, 82);
			this->Orders->TabIndex = 75;
			// 
			// Wirehouses
			// 
			this->Wirehouses->FormattingEnabled = true;
			this->Wirehouses->Location = System::Drawing::Point(263, 72);
			this->Wirehouses->Name = L"Wirehouses";
			this->Wirehouses->Size = System::Drawing::Size(196, 82);
			this->Wirehouses->TabIndex = 76;
			// 
			// AddOrder
			// 
			this->AddOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddOrder->Location = System::Drawing::Point(23, 160);
			this->AddOrder->Name = L"AddOrder";
			this->AddOrder->Size = System::Drawing::Size(96, 27);
			this->AddOrder->TabIndex = 77;
			this->AddOrder->Text = L"Add";
			this->AddOrder->UseVisualStyleBackColor = true;
			this->AddOrder->Click += gcnew System::EventHandler(this, &MyForm::AddOrder_Click);
			// 
			// DeleteOrder
			// 
			this->DeleteOrder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeleteOrder->Location = System::Drawing::Point(125, 160);
			this->DeleteOrder->Name = L"DeleteOrder";
			this->DeleteOrder->Size = System::Drawing::Size(96, 27);
			this->DeleteOrder->TabIndex = 78;
			this->DeleteOrder->Text = L"Delete";
			this->DeleteOrder->UseVisualStyleBackColor = true;
			this->DeleteOrder->Click += gcnew System::EventHandler(this, &MyForm::DeleteOrder_Click);
			// 
			// AddWirehouse
			// 
			this->AddWirehouse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddWirehouse->Location = System::Drawing::Point(263, 160);
			this->AddWirehouse->Name = L"AddWirehouse";
			this->AddWirehouse->Size = System::Drawing::Size(96, 27);
			this->AddWirehouse->TabIndex = 79;
			this->AddWirehouse->Text = L"Add";
			this->AddWirehouse->UseVisualStyleBackColor = true;
			this->AddWirehouse->Click += gcnew System::EventHandler(this, &MyForm::AddWirehouse_Click);
			// 
			// DeleteWirehouse
			// 
			this->DeleteWirehouse->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DeleteWirehouse->Location = System::Drawing::Point(365, 160);
			this->DeleteWirehouse->Name = L"DeleteWirehouse";
			this->DeleteWirehouse->Size = System::Drawing::Size(96, 27);
			this->DeleteWirehouse->TabIndex = 80;
			this->DeleteWirehouse->Text = L"Delete";
			this->DeleteWirehouse->UseVisualStyleBackColor = true;
			this->DeleteWirehouse->Click += gcnew System::EventHandler(this, &MyForm::DeleteWirehouse_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 523);
			this->Controls->Add(this->DeleteWirehouse);
			this->Controls->Add(this->AddWirehouse);
			this->Controls->Add(this->DeleteOrder);
			this->Controls->Add(this->AddOrder);
			this->Controls->Add(this->Wirehouses);
			this->Controls->Add(this->Orders);
			this->Controls->Add(this->Search);
			this->Controls->Add(this->Output);
			this->Controls->Add(this->WirehouseLine);
			this->Controls->Add(this->OrderLine);
			this->Controls->Add(this->WirehouseLable);
			this->Controls->Add(this->OrderLable);
			this->Controls->Add(this->OrderUploadButton);
			this->Controls->Add(this->OrderAddButton);
			this->Controls->Add(this->OrderUpdateButton);
			this->Controls->Add(this->OrderDeleteButton);
			this->Controls->Add(this->WirehouseDeleteButton);
			this->Controls->Add(this->WirehouseUpdateButton);
			this->Controls->Add(this->WirehouseAddButton);
			this->Controls->Add(this->WirehouseUploadButton);
			this->Controls->Add(this->PurchaseOrder);
			this->Controls->Add(this->Wirehouse);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Wirehouse))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PurchaseOrder))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: bool _CheckDataGrid(int index);
		
		private: bool _CheckOrderDataGrid(int index);
		private: System::Void _DBRequest(String^ query);
		
		private: System::Void WirehouseUploadButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void WirehouseAddButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void WirehouseUpdateButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void WirehouseDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void OrderUploadButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void OrderAddButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void OrderUpdateButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void OrderDeleteButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void AddOrder_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void DeleteOrder_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void AddWirehouse_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void DeleteWirehouse_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e);

		private: bool CheckName(String^ name);

		private: bool CheckDate(String^ date);

		private: bool CheckPounds(double^ pounds);
	};
}
