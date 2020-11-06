#pragma once

namespace HospitalAdministrationSystem 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Summary for FormMain
	/// </summary>
	public ref class FormMain : public System::Windows::Forms::Form
	{
	public:
		FormMain(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormMain();
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	protected:
	private: System::Windows::Forms::ToolStripDropDownButton^  toolStripDropDownButton1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::ListView^  listView_Notifications;

	private: System::Windows::Forms::GroupBox^  groupBox1;




	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage_Patients;
	private: System::Windows::Forms::TabPage^  tabPage_Doctors;
	private: System::Windows::Forms::TabPage^  tabPage_Nurses;
	private: System::Windows::Forms::TabPage^  tabPage_Other;
	private: System::Windows::Forms::TabControl^  tabControl_Main;
	private: System::Windows::Forms::TabPage^  tabPage_People;

	private: System::Windows::Forms::TabPage^  tabPage_Inventory;
	private: System::Windows::Forms::TabPage^  tabPage_Rooms;
	private: System::Windows::Forms::ListView^  listView_Patients;

	private: System::Windows::Forms::ColumnHeader^  columnName;
	private: System::Windows::Forms::ColumnHeader^  columnId;
	private: System::Windows::Forms::ColumnHeader^  columnRoom;
	private: System::Windows::Forms::ColumnHeader^  columnDoctor;
	private: System::Windows::Forms::ColumnHeader^  columnNurse;
	private: System::Windows::Forms::ColumnHeader^  columnAilment;
	private: System::Windows::Forms::ColumnHeader^  columnInsurance;
	private: System::Windows::Forms::ColumnHeader^  columnBilling;
	private: System::Windows::Forms::ListView^  listView_Doctors;

	private: System::Windows::Forms::ColumnHeader^  columnHeader_Name;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_EmployeeID;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_ClockedIn;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_WorkHours;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Specialization;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_NumPatients;
	private: System::Windows::Forms::ListView^  listView_Nurses;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::ColumnHeader^  columnHeader6;
	private: System::Windows::Forms::ListView^  listView_Other;

	private: System::Windows::Forms::ColumnHeader^  columnHeader7;
	private: System::Windows::Forms::ColumnHeader^  columnHeader8;
	private: System::Windows::Forms::ColumnHeader^  columnHeader9;
	private: System::Windows::Forms::ColumnHeader^  columnHeader10;
	private: System::Windows::Forms::ColumnHeader^  columnHeader11;
	private: System::Windows::Forms::ListView^  listView_Inventory;

	private: System::Windows::Forms::ColumnHeader^  columnHeader_ItemName;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_ItemQuantity;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_ItemPrice;
	private: System::Windows::Forms::ColumnHeader^  columnHeader_Description;

	private: System::Windows::Forms::ListView^  listView_Rooms;

	private: System::Windows::Forms::ColumnHeader^  columnHeader12;
	private: System::Windows::Forms::ColumnHeader^  columnHeader13;
	private: System::Windows::Forms::ColumnHeader^  columnHeader14;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label_Doctors;

	private: System::Windows::Forms::Label^  label_Patients;

	private: System::Windows::Forms::Label^  label_TotalStaff;

	private: System::Windows::Forms::Label^  label_TotalOccupancy;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_Inventory;
	private: System::Windows::Forms::ToolStripMenuItem^  addItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editItemToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeItemToolStripMenuItem;
	private: System::Windows::Forms::Label^  label_Nurses;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_Rooms;
	private: System::Windows::Forms::ToolStripMenuItem^  addRoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editRoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removeRoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addPatientToToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removePatientFromRoomToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearRoomToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_Patients;
	private: System::Windows::Forms::ToolStripMenuItem^  addPatientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editPatientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  removePatientToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  assignPatientDoctorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  assignPatientNurseToolStripMenuItem;
private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_OtherEmployees;
private: System::Windows::Forms::ToolStripMenuItem^  addEmployeeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  editEmployeeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  removeEmployeeToolStripMenuItem;
private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_MedicalEmployee;
private: System::Windows::Forms::ToolStripMenuItem^  addToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  removeToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  assignPatientToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  removePatientFromToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  cLoseToolStripMenuItem;



	private: System::ComponentModel::IContainer^  components;
















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Void updateData();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->cLoseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->listView_Notifications = (gcnew System::Windows::Forms::ListView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label_Nurses = (gcnew System::Windows::Forms::Label());
			this->label_Doctors = (gcnew System::Windows::Forms::Label());
			this->label_Patients = (gcnew System::Windows::Forms::Label());
			this->label_TotalStaff = (gcnew System::Windows::Forms::Label());
			this->label_TotalOccupancy = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_Patients = (gcnew System::Windows::Forms::TabPage());
			this->listView_Patients = (gcnew System::Windows::Forms::ListView());
			this->columnName = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnId = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnRoom = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnDoctor = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnNurse = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnAilment = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnInsurance = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBilling = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_Patients = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addPatientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editPatientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removePatientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->assignPatientDoctorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->assignPatientNurseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage_Doctors = (gcnew System::Windows::Forms::TabPage());
			this->listView_Doctors = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_Name = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_EmployeeID = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_ClockedIn = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_WorkHours = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Specialization = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_NumPatients = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_MedicalEmployee = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->assignPatientToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removePatientFromToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage_Nurses = (gcnew System::Windows::Forms::TabPage());
			this->listView_Nurses = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->tabPage_Other = (gcnew System::Windows::Forms::TabPage());
			this->listView_Other = (gcnew System::Windows::Forms::ListView());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader10 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_OtherEmployees = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addEmployeeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editEmployeeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeEmployeeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl_Main = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_People = (gcnew System::Windows::Forms::TabPage());
			this->tabPage_Inventory = (gcnew System::Windows::Forms::TabPage());
			this->listView_Inventory = (gcnew System::Windows::Forms::ListView());
			this->columnHeader_ItemName = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_ItemQuantity = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_ItemPrice = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader_Description = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_Inventory = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeItemToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage_Rooms = (gcnew System::Windows::Forms::TabPage());
			this->listView_Rooms = (gcnew System::Windows::Forms::ListView());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader13 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader14 = (gcnew System::Windows::Forms::ColumnHeader());
			this->contextMenuStrip_Rooms = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->addRoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editRoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removeRoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addPatientToToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->removePatientFromRoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearRoomToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage_Patients->SuspendLayout();
			this->contextMenuStrip_Patients->SuspendLayout();
			this->tabPage_Doctors->SuspendLayout();
			this->contextMenuStrip_MedicalEmployee->SuspendLayout();
			this->tabPage_Nurses->SuspendLayout();
			this->tabPage_Other->SuspendLayout();
			this->contextMenuStrip_OtherEmployees->SuspendLayout();
			this->tabControl_Main->SuspendLayout();
			this->tabPage_People->SuspendLayout();
			this->tabPage_Inventory->SuspendLayout();
			this->contextMenuStrip_Inventory->SuspendLayout();
			this->tabPage_Rooms->SuspendLayout();
			this->contextMenuStrip_Rooms->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripDropDownButton1 });
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1318, 27);
			this->toolStrip1->TabIndex = 0;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->cLoseToolStripMenuItem });
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(46, 24);
			this->toolStripDropDownButton1->Text = L"File";
			// 
			// cLoseToolStripMenuItem
			// 
			this->cLoseToolStripMenuItem->Name = L"cLoseToolStripMenuItem";
			this->cLoseToolStripMenuItem->Size = System::Drawing::Size(120, 26);
			this->cLoseToolStripMenuItem->Text = L"Close";
			this->cLoseToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::cLoseToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->listView_Notifications);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox2->Location = System::Drawing::Point(1056, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(262, 825);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Notifications";
			// 
			// listView_Notifications
			// 
			this->listView_Notifications->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Notifications->Location = System::Drawing::Point(3, 18);
			this->listView_Notifications->Name = L"listView_Notifications";
			this->listView_Notifications->Size = System::Drawing::Size(256, 804);
			this->listView_Notifications->TabIndex = 0;
			this->listView_Notifications->UseCompatibleStateImageBehavior = false;
			this->listView_Notifications->View = System::Windows::Forms::View::List;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->panel2);
			this->groupBox1->Controls->Add(this->panel1);
			this->groupBox1->Location = System::Drawing::Point(12, 30);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 141);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Info";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label_Nurses);
			this->panel2->Controls->Add(this->label_Doctors);
			this->panel2->Controls->Add(this->label_Patients);
			this->panel2->Controls->Add(this->label_TotalStaff);
			this->panel2->Controls->Add(this->label_TotalOccupancy);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(148, 18);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(49, 120);
			this->panel2->TabIndex = 1;
			// 
			// label_Nurses
			// 
			this->label_Nurses->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_Nurses->Location = System::Drawing::Point(0, 92);
			this->label_Nurses->Name = L"label_Nurses";
			this->label_Nurses->Size = System::Drawing::Size(49, 23);
			this->label_Nurses->TabIndex = 12;
			this->label_Nurses->Text = L"0";
			this->label_Nurses->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_Doctors
			// 
			this->label_Doctors->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_Doctors->Location = System::Drawing::Point(0, 69);
			this->label_Doctors->Name = L"label_Doctors";
			this->label_Doctors->Size = System::Drawing::Size(49, 23);
			this->label_Doctors->TabIndex = 11;
			this->label_Doctors->Text = L"0";
			this->label_Doctors->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_Patients
			// 
			this->label_Patients->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_Patients->Location = System::Drawing::Point(0, 46);
			this->label_Patients->Name = L"label_Patients";
			this->label_Patients->Size = System::Drawing::Size(49, 23);
			this->label_Patients->TabIndex = 10;
			this->label_Patients->Text = L"0";
			this->label_Patients->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_TotalStaff
			// 
			this->label_TotalStaff->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_TotalStaff->Location = System::Drawing::Point(0, 23);
			this->label_TotalStaff->Name = L"label_TotalStaff";
			this->label_TotalStaff->Size = System::Drawing::Size(49, 23);
			this->label_TotalStaff->TabIndex = 9;
			this->label_TotalStaff->Text = L"0";
			this->label_TotalStaff->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_TotalOccupancy
			// 
			this->label_TotalOccupancy->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_TotalOccupancy->Location = System::Drawing::Point(0, 0);
			this->label_TotalOccupancy->Name = L"label_TotalOccupancy";
			this->label_TotalOccupancy->Size = System::Drawing::Size(49, 23);
			this->label_TotalOccupancy->TabIndex = 8;
			this->label_TotalOccupancy->Text = L"0";
			this->label_TotalOccupancy->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(3, 18);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(145, 120);
			this->panel1->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Location = System::Drawing::Point(0, 92);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 23);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Nurses: ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Dock = System::Windows::Forms::DockStyle::Top;
			this->label5->Location = System::Drawing::Point(0, 69);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(145, 23);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Doctors: ";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Dock = System::Windows::Forms::DockStyle::Top;
			this->label6->Location = System::Drawing::Point(0, 46);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(145, 23);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Patients: ";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Dock = System::Windows::Forms::DockStyle::Top;
			this->label7->Location = System::Drawing::Point(0, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(145, 23);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Total Staff: ";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label8
			// 
			this->label8->Dock = System::Windows::Forms::DockStyle::Top;
			this->label8->Location = System::Drawing::Point(0, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(145, 23);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Total Occupancy:";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage_Patients);
			this->tabControl1->Controls->Add(this->tabPage_Doctors);
			this->tabControl1->Controls->Add(this->tabPage_Nurses);
			this->tabControl1->Controls->Add(this->tabPage_Other);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(821, 784);
			this->tabControl1->TabIndex = 4;
			// 
			// tabPage_Patients
			// 
			this->tabPage_Patients->Controls->Add(this->listView_Patients);
			this->tabPage_Patients->Location = System::Drawing::Point(4, 25);
			this->tabPage_Patients->Name = L"tabPage_Patients";
			this->tabPage_Patients->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Patients->Size = System::Drawing::Size(813, 755);
			this->tabPage_Patients->TabIndex = 0;
			this->tabPage_Patients->Text = L"Patients";
			this->tabPage_Patients->UseVisualStyleBackColor = true;
			// 
			// listView_Patients
			// 
			this->listView_Patients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(8) {
				this->columnName,
					this->columnId, this->columnRoom, this->columnDoctor, this->columnNurse, this->columnAilment, this->columnInsurance, this->columnBilling
			});
			this->listView_Patients->ContextMenuStrip = this->contextMenuStrip_Patients;
			this->listView_Patients->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Patients->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->listView_Patients->FullRowSelect = true;
			this->listView_Patients->GridLines = true;
			this->listView_Patients->Location = System::Drawing::Point(3, 3);
			this->listView_Patients->Name = L"listView_Patients";
			this->listView_Patients->Size = System::Drawing::Size(807, 749);
			this->listView_Patients->TabIndex = 0;
			this->listView_Patients->UseCompatibleStateImageBehavior = false;
			this->listView_Patients->View = System::Windows::Forms::View::Details;
			// 
			// columnName
			// 
			this->columnName->Text = L"Patient Name";
			this->columnName->Width = 142;
			// 
			// columnId
			// 
			this->columnId->Text = L"Patient ID";
			this->columnId->Width = 113;
			// 
			// columnRoom
			// 
			this->columnRoom->Text = L"Room";
			this->columnRoom->Width = 69;
			// 
			// columnDoctor
			// 
			this->columnDoctor->Text = L"Doctor";
			this->columnDoctor->Width = 134;
			// 
			// columnNurse
			// 
			this->columnNurse->Text = L"Nurse";
			this->columnNurse->Width = 150;
			// 
			// columnAilment
			// 
			this->columnAilment->Text = L"Ailment";
			this->columnAilment->Width = 155;
			// 
			// columnInsurance
			// 
			this->columnInsurance->DisplayIndex = 7;
			this->columnInsurance->Text = L"Insurance";
			this->columnInsurance->Width = 105;
			// 
			// columnBilling
			// 
			this->columnBilling->DisplayIndex = 6;
			this->columnBilling->Text = L"Bill";
			this->columnBilling->Width = 99;
			// 
			// contextMenuStrip_Patients
			// 
			this->contextMenuStrip_Patients->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip_Patients->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addPatientToolStripMenuItem,
					this->editPatientToolStripMenuItem, this->removePatientToolStripMenuItem, this->assignPatientDoctorToolStripMenuItem, this->assignPatientNurseToolStripMenuItem
			});
			this->contextMenuStrip_Patients->Name = L"contextMenuStrip_Patients";
			this->contextMenuStrip_Patients->Size = System::Drawing::Size(221, 124);
			this->contextMenuStrip_Patients->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::contextMenuStrip_Patients_Opening);
			// 
			// addPatientToolStripMenuItem
			// 
			this->addPatientToolStripMenuItem->Name = L"addPatientToolStripMenuItem";
			this->addPatientToolStripMenuItem->Size = System::Drawing::Size(220, 24);
			this->addPatientToolStripMenuItem->Text = L"Add Patient";
			this->addPatientToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::addPatientToolStripMenuItem_Click);
			// 
			// editPatientToolStripMenuItem
			// 
			this->editPatientToolStripMenuItem->Name = L"editPatientToolStripMenuItem";
			this->editPatientToolStripMenuItem->Size = System::Drawing::Size(220, 24);
			this->editPatientToolStripMenuItem->Text = L"Edit Patient";
			this->editPatientToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::editPatientToolStripMenuItem_Click);
			// 
			// removePatientToolStripMenuItem
			// 
			this->removePatientToolStripMenuItem->Name = L"removePatientToolStripMenuItem";
			this->removePatientToolStripMenuItem->Size = System::Drawing::Size(220, 24);
			this->removePatientToolStripMenuItem->Text = L"Remove Patient";
			this->removePatientToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removePatientToolStripMenuItem_Click);
			// 
			// assignPatientDoctorToolStripMenuItem
			// 
			this->assignPatientDoctorToolStripMenuItem->Name = L"assignPatientDoctorToolStripMenuItem";
			this->assignPatientDoctorToolStripMenuItem->Size = System::Drawing::Size(220, 24);
			this->assignPatientDoctorToolStripMenuItem->Text = L"Assign Patient Doctor";
			this->assignPatientDoctorToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::assignPatientDoctorToolStripMenuItem_Click);
			// 
			// assignPatientNurseToolStripMenuItem
			// 
			this->assignPatientNurseToolStripMenuItem->Name = L"assignPatientNurseToolStripMenuItem";
			this->assignPatientNurseToolStripMenuItem->Size = System::Drawing::Size(220, 24);
			this->assignPatientNurseToolStripMenuItem->Text = L"Assign Patient Nurse";
			this->assignPatientNurseToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::assignPatientNurseToolStripMenuItem_Click);
			// 
			// tabPage_Doctors
			// 
			this->tabPage_Doctors->Controls->Add(this->listView_Doctors);
			this->tabPage_Doctors->Location = System::Drawing::Point(4, 25);
			this->tabPage_Doctors->Name = L"tabPage_Doctors";
			this->tabPage_Doctors->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Doctors->Size = System::Drawing::Size(813, 755);
			this->tabPage_Doctors->TabIndex = 1;
			this->tabPage_Doctors->Text = L"Doctors";
			this->tabPage_Doctors->UseVisualStyleBackColor = true;
			// 
			// listView_Doctors
			// 
			this->listView_Doctors->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader_Name,
					this->columnHeader_EmployeeID, this->columnHeader_ClockedIn, this->columnHeader_WorkHours, this->columnHeader_Specialization,
					this->columnHeader_NumPatients
			});
			this->listView_Doctors->ContextMenuStrip = this->contextMenuStrip_MedicalEmployee;
			this->listView_Doctors->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Doctors->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->listView_Doctors->FullRowSelect = true;
			this->listView_Doctors->GridLines = true;
			this->listView_Doctors->Location = System::Drawing::Point(3, 3);
			this->listView_Doctors->Name = L"listView_Doctors";
			this->listView_Doctors->Size = System::Drawing::Size(807, 749);
			this->listView_Doctors->TabIndex = 0;
			this->listView_Doctors->UseCompatibleStateImageBehavior = false;
			this->listView_Doctors->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_Name
			// 
			this->columnHeader_Name->Text = L"Name";
			this->columnHeader_Name->Width = 189;
			// 
			// columnHeader_EmployeeID
			// 
			this->columnHeader_EmployeeID->Text = L"Employee ID";
			this->columnHeader_EmployeeID->Width = 165;
			// 
			// columnHeader_ClockedIn
			// 
			this->columnHeader_ClockedIn->Text = L"Clocked In";
			this->columnHeader_ClockedIn->Width = 123;
			// 
			// columnHeader_WorkHours
			// 
			this->columnHeader_WorkHours->Text = L"Hours Worked";
			this->columnHeader_WorkHours->Width = 132;
			// 
			// columnHeader_Specialization
			// 
			this->columnHeader_Specialization->Text = L"Specialization";
			this->columnHeader_Specialization->Width = 195;
			// 
			// columnHeader_NumPatients
			// 
			this->columnHeader_NumPatients->Text = L"Patient Count";
			this->columnHeader_NumPatients->Width = 97;
			// 
			// contextMenuStrip_MedicalEmployee
			// 
			this->contextMenuStrip_MedicalEmployee->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip_MedicalEmployee->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->addToolStripMenuItem,
					this->editToolStripMenuItem, this->removeToolStripMenuItem, this->assignPatientToolStripMenuItem, this->removePatientFromToolStripMenuItem
			});
			this->contextMenuStrip_MedicalEmployee->Name = L"contextMenuStrip_MedicalEmployee";
			this->contextMenuStrip_MedicalEmployee->Size = System::Drawing::Size(224, 124);
			this->contextMenuStrip_MedicalEmployee->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::contextMenuStrip_MedicalEmployee_Opening);
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(223, 24);
			this->addToolStripMenuItem->Text = L"Add ";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::addToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(223, 24);
			this->editToolStripMenuItem->Text = L"Edit ";
			this->editToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::editToolStripMenuItem_Click);
			// 
			// removeToolStripMenuItem
			// 
			this->removeToolStripMenuItem->Name = L"removeToolStripMenuItem";
			this->removeToolStripMenuItem->Size = System::Drawing::Size(223, 24);
			this->removeToolStripMenuItem->Text = L"Remove ";
			this->removeToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removeToolStripMenuItem_Click);
			// 
			// assignPatientToolStripMenuItem
			// 
			this->assignPatientToolStripMenuItem->Name = L"assignPatientToolStripMenuItem";
			this->assignPatientToolStripMenuItem->Size = System::Drawing::Size(223, 24);
			this->assignPatientToolStripMenuItem->Text = L"Assign Patient To ";
			this->assignPatientToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::assignPatientToolStripMenuItem_Click);
			// 
			// removePatientFromToolStripMenuItem
			// 
			this->removePatientFromToolStripMenuItem->Name = L"removePatientFromToolStripMenuItem";
			this->removePatientFromToolStripMenuItem->Size = System::Drawing::Size(223, 24);
			this->removePatientFromToolStripMenuItem->Text = L"Remove Patient From ";
			this->removePatientFromToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removePatientFromToolStripMenuItem_Click);
			// 
			// tabPage_Nurses
			// 
			this->tabPage_Nurses->Controls->Add(this->listView_Nurses);
			this->tabPage_Nurses->Location = System::Drawing::Point(4, 25);
			this->tabPage_Nurses->Name = L"tabPage_Nurses";
			this->tabPage_Nurses->Size = System::Drawing::Size(813, 755);
			this->tabPage_Nurses->TabIndex = 2;
			this->tabPage_Nurses->Text = L"Nurses";
			this->tabPage_Nurses->UseVisualStyleBackColor = true;
			// 
			// listView_Nurses
			// 
			this->listView_Nurses->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->columnHeader1,
					this->columnHeader2, this->columnHeader3, this->columnHeader4, this->columnHeader5, this->columnHeader6
			});
			this->listView_Nurses->ContextMenuStrip = this->contextMenuStrip_MedicalEmployee;
			this->listView_Nurses->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Nurses->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView_Nurses->FullRowSelect = true;
			this->listView_Nurses->GridLines = true;
			this->listView_Nurses->Location = System::Drawing::Point(0, 0);
			this->listView_Nurses->Name = L"listView_Nurses";
			this->listView_Nurses->Size = System::Drawing::Size(813, 755);
			this->listView_Nurses->TabIndex = 1;
			this->listView_Nurses->UseCompatibleStateImageBehavior = false;
			this->listView_Nurses->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Name";
			this->columnHeader1->Width = 189;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Employee ID";
			this->columnHeader2->Width = 165;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Clocked In";
			this->columnHeader3->Width = 123;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Hours Worked";
			this->columnHeader4->Width = 127;
			// 
			// columnHeader5
			// 
			this->columnHeader5->Text = L"Specialization";
			this->columnHeader5->Width = 195;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Patient Count";
			this->columnHeader6->Width = 97;
			// 
			// tabPage_Other
			// 
			this->tabPage_Other->Controls->Add(this->listView_Other);
			this->tabPage_Other->Location = System::Drawing::Point(4, 25);
			this->tabPage_Other->Name = L"tabPage_Other";
			this->tabPage_Other->Size = System::Drawing::Size(813, 755);
			this->tabPage_Other->TabIndex = 3;
			this->tabPage_Other->Text = L"Other";
			this->tabPage_Other->UseVisualStyleBackColor = true;
			// 
			// listView_Other
			// 
			this->listView_Other->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader7,
					this->columnHeader8, this->columnHeader9, this->columnHeader10, this->columnHeader11
			});
			this->listView_Other->ContextMenuStrip = this->contextMenuStrip_OtherEmployees;
			this->listView_Other->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Other->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listView_Other->FullRowSelect = true;
			this->listView_Other->GridLines = true;
			this->listView_Other->Location = System::Drawing::Point(0, 0);
			this->listView_Other->Name = L"listView_Other";
			this->listView_Other->Size = System::Drawing::Size(813, 755);
			this->listView_Other->TabIndex = 1;
			this->listView_Other->UseCompatibleStateImageBehavior = false;
			this->listView_Other->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Name";
			this->columnHeader7->Width = 189;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Employee ID";
			this->columnHeader8->Width = 165;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"Clocked In";
			this->columnHeader9->Width = 123;
			// 
			// columnHeader10
			// 
			this->columnHeader10->Text = L"Hours Worked";
			this->columnHeader10->Width = 135;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"Years Experience";
			this->columnHeader11->Width = 151;
			// 
			// contextMenuStrip_OtherEmployees
			// 
			this->contextMenuStrip_OtherEmployees->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip_OtherEmployees->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addEmployeeToolStripMenuItem,
					this->editEmployeeToolStripMenuItem, this->removeEmployeeToolStripMenuItem
			});
			this->contextMenuStrip_OtherEmployees->Name = L"contextMenuStrip_OtherEmployees";
			this->contextMenuStrip_OtherEmployees->Size = System::Drawing::Size(203, 76);
			this->contextMenuStrip_OtherEmployees->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::contextMenuStrip_OtherEmployees_Opening);
			// 
			// addEmployeeToolStripMenuItem
			// 
			this->addEmployeeToolStripMenuItem->Name = L"addEmployeeToolStripMenuItem";
			this->addEmployeeToolStripMenuItem->Size = System::Drawing::Size(202, 24);
			this->addEmployeeToolStripMenuItem->Text = L"Add Employee";
			this->addEmployeeToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::addEmployeeToolStripMenuItem_Click);
			// 
			// editEmployeeToolStripMenuItem
			// 
			this->editEmployeeToolStripMenuItem->Name = L"editEmployeeToolStripMenuItem";
			this->editEmployeeToolStripMenuItem->Size = System::Drawing::Size(202, 24);
			this->editEmployeeToolStripMenuItem->Text = L"Edit Employee";
			this->editEmployeeToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::editEmployeeToolStripMenuItem_Click);
			// 
			// removeEmployeeToolStripMenuItem
			// 
			this->removeEmployeeToolStripMenuItem->Name = L"removeEmployeeToolStripMenuItem";
			this->removeEmployeeToolStripMenuItem->Size = System::Drawing::Size(202, 24);
			this->removeEmployeeToolStripMenuItem->Text = L"Remove Employee";
			this->removeEmployeeToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removeEmployeeToolStripMenuItem_Click);
			// 
			// tabControl_Main
			// 
			this->tabControl_Main->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl_Main->Controls->Add(this->tabPage_People);
			this->tabControl_Main->Controls->Add(this->tabPage_Inventory);
			this->tabControl_Main->Controls->Add(this->tabPage_Rooms);
			this->tabControl_Main->Location = System::Drawing::Point(218, 30);
			this->tabControl_Main->Name = L"tabControl_Main";
			this->tabControl_Main->SelectedIndex = 0;
			this->tabControl_Main->Size = System::Drawing::Size(835, 819);
			this->tabControl_Main->TabIndex = 5;
			// 
			// tabPage_People
			// 
			this->tabPage_People->Controls->Add(this->tabControl1);
			this->tabPage_People->Location = System::Drawing::Point(4, 25);
			this->tabPage_People->Name = L"tabPage_People";
			this->tabPage_People->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_People->Size = System::Drawing::Size(827, 790);
			this->tabPage_People->TabIndex = 0;
			this->tabPage_People->Text = L"People";
			this->tabPage_People->UseVisualStyleBackColor = true;
			// 
			// tabPage_Inventory
			// 
			this->tabPage_Inventory->Controls->Add(this->listView_Inventory);
			this->tabPage_Inventory->Location = System::Drawing::Point(4, 25);
			this->tabPage_Inventory->Name = L"tabPage_Inventory";
			this->tabPage_Inventory->Padding = System::Windows::Forms::Padding(3);
			this->tabPage_Inventory->Size = System::Drawing::Size(827, 790);
			this->tabPage_Inventory->TabIndex = 1;
			this->tabPage_Inventory->Text = L"Inventory";
			this->tabPage_Inventory->UseVisualStyleBackColor = true;
			// 
			// listView_Inventory
			// 
			this->listView_Inventory->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader_ItemName,
					this->columnHeader_ItemQuantity, this->columnHeader_ItemPrice, this->columnHeader_Description
			});
			this->listView_Inventory->ContextMenuStrip = this->contextMenuStrip_Inventory;
			this->listView_Inventory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Inventory->FullRowSelect = true;
			this->listView_Inventory->GridLines = true;
			this->listView_Inventory->Location = System::Drawing::Point(3, 3);
			this->listView_Inventory->Name = L"listView_Inventory";
			this->listView_Inventory->Size = System::Drawing::Size(821, 784);
			this->listView_Inventory->TabIndex = 0;
			this->listView_Inventory->UseCompatibleStateImageBehavior = false;
			this->listView_Inventory->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader_ItemName
			// 
			this->columnHeader_ItemName->Text = L"Item Name";
			this->columnHeader_ItemName->Width = 286;
			// 
			// columnHeader_ItemQuantity
			// 
			this->columnHeader_ItemQuantity->Text = L"Quantity";
			this->columnHeader_ItemQuantity->Width = 95;
			// 
			// columnHeader_ItemPrice
			// 
			this->columnHeader_ItemPrice->Text = L"Price";
			this->columnHeader_ItemPrice->Width = 123;
			// 
			// columnHeader_Description
			// 
			this->columnHeader_Description->Text = L"Description";
			this->columnHeader_Description->Width = 329;
			// 
			// contextMenuStrip_Inventory
			// 
			this->contextMenuStrip_Inventory->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip_Inventory->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->addItemToolStripMenuItem,
					this->editItemToolStripMenuItem, this->removeItemToolStripMenuItem
			});
			this->contextMenuStrip_Inventory->Name = L"contextMenuStrip_Inventory";
			this->contextMenuStrip_Inventory->Size = System::Drawing::Size(167, 76);
			this->contextMenuStrip_Inventory->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::contextMenuStrip_Inventory_Opening);
			// 
			// addItemToolStripMenuItem
			// 
			this->addItemToolStripMenuItem->Name = L"addItemToolStripMenuItem";
			this->addItemToolStripMenuItem->Size = System::Drawing::Size(166, 24);
			this->addItemToolStripMenuItem->Text = L"Add Item";
			this->addItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::addItemToolStripMenuItem_Click);
			// 
			// editItemToolStripMenuItem
			// 
			this->editItemToolStripMenuItem->Name = L"editItemToolStripMenuItem";
			this->editItemToolStripMenuItem->Size = System::Drawing::Size(166, 24);
			this->editItemToolStripMenuItem->Text = L"Edit Item";
			this->editItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::editItemToolStripMenuItem_Click);
			// 
			// removeItemToolStripMenuItem
			// 
			this->removeItemToolStripMenuItem->Name = L"removeItemToolStripMenuItem";
			this->removeItemToolStripMenuItem->Size = System::Drawing::Size(166, 24);
			this->removeItemToolStripMenuItem->Text = L"Remove Item";
			this->removeItemToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removeItemToolStripMenuItem_Click);
			// 
			// tabPage_Rooms
			// 
			this->tabPage_Rooms->Controls->Add(this->listView_Rooms);
			this->tabPage_Rooms->Location = System::Drawing::Point(4, 25);
			this->tabPage_Rooms->Name = L"tabPage_Rooms";
			this->tabPage_Rooms->Size = System::Drawing::Size(827, 790);
			this->tabPage_Rooms->TabIndex = 2;
			this->tabPage_Rooms->Text = L"Rooms";
			this->tabPage_Rooms->UseVisualStyleBackColor = true;
			// 
			// listView_Rooms
			// 
			this->listView_Rooms->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader12,
					this->columnHeader13, this->columnHeader14
			});
			this->listView_Rooms->ContextMenuStrip = this->contextMenuStrip_Rooms;
			this->listView_Rooms->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listView_Rooms->FullRowSelect = true;
			this->listView_Rooms->GridLines = true;
			this->listView_Rooms->Location = System::Drawing::Point(0, 0);
			this->listView_Rooms->Name = L"listView_Rooms";
			this->listView_Rooms->Size = System::Drawing::Size(827, 790);
			this->listView_Rooms->TabIndex = 1;
			this->listView_Rooms->UseCompatibleStateImageBehavior = false;
			this->listView_Rooms->View = System::Windows::Forms::View::Details;
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"Room Number";
			this->columnHeader12->Width = 109;
			// 
			// columnHeader13
			// 
			this->columnHeader13->Text = L"Maximum Occupancy";
			this->columnHeader13->Width = 147;
			// 
			// columnHeader14
			// 
			this->columnHeader14->Text = L"Total Occupancy";
			this->columnHeader14->Width = 123;
			// 
			// contextMenuStrip_Rooms
			// 
			this->contextMenuStrip_Rooms->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip_Rooms->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->addRoomToolStripMenuItem,
					this->editRoomToolStripMenuItem, this->removeRoomToolStripMenuItem, this->addPatientToToolStripMenuItem, this->removePatientFromRoomToolStripMenuItem,
					this->clearRoomToolStripMenuItem
			});
			this->contextMenuStrip_Rooms->Name = L"contextMenuStrip_Rooms";
			this->contextMenuStrip_Rooms->Size = System::Drawing::Size(264, 148);
			this->contextMenuStrip_Rooms->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::contextMenuStrip_Rooms_Opening);
			// 
			// addRoomToolStripMenuItem
			// 
			this->addRoomToolStripMenuItem->Name = L"addRoomToolStripMenuItem";
			this->addRoomToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->addRoomToolStripMenuItem->Text = L"Add Room";
			this->addRoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::addRoomToolStripMenuItem_Click);
			// 
			// editRoomToolStripMenuItem
			// 
			this->editRoomToolStripMenuItem->Name = L"editRoomToolStripMenuItem";
			this->editRoomToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->editRoomToolStripMenuItem->Text = L"Edit Room";
			this->editRoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::editRoomToolStripMenuItem_Click);
			// 
			// removeRoomToolStripMenuItem
			// 
			this->removeRoomToolStripMenuItem->Name = L"removeRoomToolStripMenuItem";
			this->removeRoomToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->removeRoomToolStripMenuItem->Text = L"Remove Room";
			this->removeRoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removeRoomToolStripMenuItem_Click);
			// 
			// addPatientToToolStripMenuItem
			// 
			this->addPatientToToolStripMenuItem->Name = L"addPatientToToolStripMenuItem";
			this->addPatientToToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->addPatientToToolStripMenuItem->Text = L"Add Patient To Room";
			this->addPatientToToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::addPatientToToolStripMenuItem_Click);
			// 
			// removePatientFromRoomToolStripMenuItem
			// 
			this->removePatientFromRoomToolStripMenuItem->Name = L"removePatientFromRoomToolStripMenuItem";
			this->removePatientFromRoomToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->removePatientFromRoomToolStripMenuItem->Text = L"Remove Patient From Room";
			this->removePatientFromRoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::removePatientFromRoomToolStripMenuItem_Click);
			// 
			// clearRoomToolStripMenuItem
			// 
			this->clearRoomToolStripMenuItem->Name = L"clearRoomToolStripMenuItem";
			this->clearRoomToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->clearRoomToolStripMenuItem->Text = L"Clear Room";
			this->clearRoomToolStripMenuItem->Click += gcnew System::EventHandler(this, &FormMain::clearRoomToolStripMenuItem_Click);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1318, 852);
			this->Controls->Add(this->tabControl_Main);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->toolStrip1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormMain";
			this->Text = L"Hospital Administration System";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPage_Patients->ResumeLayout(false);
			this->contextMenuStrip_Patients->ResumeLayout(false);
			this->tabPage_Doctors->ResumeLayout(false);
			this->contextMenuStrip_MedicalEmployee->ResumeLayout(false);
			this->tabPage_Nurses->ResumeLayout(false);
			this->tabPage_Other->ResumeLayout(false);
			this->contextMenuStrip_OtherEmployees->ResumeLayout(false);
			this->tabControl_Main->ResumeLayout(false);
			this->tabPage_People->ResumeLayout(false);
			this->tabPage_Inventory->ResumeLayout(false);
			this->contextMenuStrip_Inventory->ResumeLayout(false);
			this->tabPage_Rooms->ResumeLayout(false);
			this->contextMenuStrip_Rooms->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void FormMain_Load(System::Object^  sender, System::EventArgs^  e);
		System::Void contextMenuStrip_Inventory_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
		System::Void addItemToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void editItemToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void removeItemToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void contextMenuStrip_Rooms_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
private: System::Void addRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void editRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void removeRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void addPatientToToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void removePatientFromRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void clearRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void addPatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void editPatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void removePatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void assignPatientDoctorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void assignPatientNurseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void contextMenuStrip_Patients_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
private: System::Void contextMenuStrip_OtherEmployees_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
private: System::Void addEmployeeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void editEmployeeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void removeEmployeeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void contextMenuStrip_MedicalEmployee_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e);
private: System::Void addToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void removeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void assignPatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void removePatientFromToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void cLoseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
};
}
