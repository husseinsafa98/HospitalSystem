#include "FormMain.h"
#include "Globals.h"
#include "ItemDialog.h"
#include "RoomDialog.h"
#include "PatientDialog.h"
#include "EmployeeDialog.h"
#include "MedicalEmployeeDialog.h"
#include "PersonSelectorDialog.h"

#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

namespace HospitalAdministrationSystem
{
	FormMain::FormMain(void)
	{
		InitializeComponent();

		// set column header fonts to bold.
		for (int i = 0; i < listView_Patients->Columns->Count; i++)
			listView_Patients->Columns[i]->ListView->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Bold);
		for (int i = 0; i < listView_Doctors->Columns->Count; i++)
			listView_Doctors->Columns[i]->ListView->Font = gcnew System::Drawing::Font(listView_Doctors->Font, System::Drawing::FontStyle::Bold);
		for (int i = 0; i < listView_Nurses->Columns->Count; i++)
			listView_Nurses->Columns[i]->ListView->Font = gcnew System::Drawing::Font(listView_Nurses->Font, System::Drawing::FontStyle::Bold);
		for (int i = 0; i < listView_Other->Columns->Count; i++)
			listView_Other->Columns[i]->ListView->Font = gcnew System::Drawing::Font(listView_Other->Font, System::Drawing::FontStyle::Bold);
		for (int i = 0; i < listView_Inventory->Columns->Count; i++)
			listView_Inventory->Columns[i]->ListView->Font = gcnew System::Drawing::Font(listView_Inventory->Font, System::Drawing::FontStyle::Bold);
		for (int i = 0; i < listView_Rooms->Columns->Count; i++)
			listView_Rooms->Columns[i]->ListView->Font = gcnew System::Drawing::Font(listView_Rooms->Font, System::Drawing::FontStyle::Bold);
	}
	FormMain::~FormMain()
	{
		if (components)
		{
			delete components;
		}
	}

	System::Void FormMain::updateData()
	{
		// clear all listViews.
		listView_Doctors->Items->Clear();
		listView_Inventory->Items->Clear();
		listView_Notifications->Items->Clear();
		listView_Nurses->Items->Clear();
		listView_Other->Items->Clear();
		listView_Patients->Items->Clear();
		listView_Rooms->Items->Clear();

		// read all the information to put into each listView from the database.
		std::vector<Patient> patients = Globals::databaseManager->getPatients();
		std::vector<MedicalEmployee> doctors = Globals::databaseManager->getDoctors();
		std::vector<MedicalEmployee> nurses = Globals::databaseManager->getNurses();
		std::vector<Employee> employees = Globals::databaseManager->getOtherEmployees();
		std::vector<Item> items = Globals::databaseManager->getItems();
		std::vector<Room> rooms = Globals::databaseManager->getRooms();
		List<String^> ^notifications = Globals::databaseManager->getNotifications();

		// set occupancy text
		label_TotalOccupancy->Text = gcnew String((patients.size() + doctors.size() + nurses.size() + employees.size()).ToString());
		label_TotalStaff->Text = gcnew String((doctors.size() + nurses.size() + employees.size()).ToString());
		label_Patients->Text = gcnew String(patients.size().ToString());
		label_Doctors->Text = gcnew String(doctors.size().ToString());
		label_Nurses->Text = gcnew String(nurses.size().ToString());

		// populate the listview items.
		for (Patient patient : patients)
		{
			ListViewItem ^item = gcnew ListViewItem(gcnew String(patient.getName().c_str()));
			item->SubItems->Add(gcnew String(patient.getPatientID().c_str()));
			item->SubItems->Add(gcnew String(patient.getRoomNumber().c_str()));
			item->SubItems->Add(gcnew String(Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str())).getName().c_str()));
			item->SubItems->Add(gcnew String(Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str())).getName().c_str()));
			item->SubItems->Add(gcnew String(patient.getAilment().c_str()));
			item->SubItems->Add(gcnew String(patient.getInsurance().c_str()));
			item->SubItems->Add(String::Format("{0:C}", patient.getBillingInfo()));
			item->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Regular);
			listView_Patients->Items->Add(item);
		}

		for (MedicalEmployee doctor : doctors)
		{
			ListViewItem ^item = gcnew ListViewItem(gcnew String(doctor.getName().c_str()));
			item->SubItems->Add(gcnew String(doctor.getEmployeeID().c_str()));
			item->SubItems->Add(gcnew String(doctor.getClockedIn().ToString()));
			item->SubItems->Add(gcnew String(doctor.getHoursWrokedPerWeek().ToString()));
			item->SubItems->Add(gcnew String(doctor.getSpecialization().c_str()));
			item->SubItems->Add(gcnew String(doctor.getPatients().size().ToString()));
			item->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Regular);
			listView_Doctors->Items->Add(item);
		}

		for (MedicalEmployee nurse : nurses)
		{
			ListViewItem ^item = gcnew ListViewItem(gcnew String(nurse.getName().c_str()));
			item->SubItems->Add(gcnew String(nurse.getEmployeeID().c_str()));
			item->SubItems->Add(gcnew String(nurse.getClockedIn().ToString()));
			item->SubItems->Add(gcnew String(nurse.getHoursWrokedPerWeek().ToString()));
			item->SubItems->Add(gcnew String(nurse.getSpecialization().c_str()));
			item->SubItems->Add(gcnew String(nurse.getPatients().size().ToString()));
			item->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Regular);
			listView_Nurses->Items->Add(item);
		}

		for (Employee employee : employees)
		{
			ListViewItem ^item = gcnew ListViewItem(gcnew String(employee.getName().c_str()));
			item->SubItems->Add(gcnew String(employee.getEmployeeID().c_str()));
			item->SubItems->Add(gcnew String(employee.getClockedIn().ToString()));
			item->SubItems->Add(gcnew String(employee.getHoursWrokedPerWeek().ToString()));
			item->SubItems->Add(gcnew String(employee.getExperience().ToString()));
			item->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Regular);
			listView_Other->Items->Add(item);
		}

		for (Item inventoryItem : items)
		{
			ListViewItem ^item = gcnew ListViewItem(gcnew String(inventoryItem.getItemName().c_str()));
			item->SubItems->Add(gcnew String(inventoryItem.getQuantity().ToString()));
			item->SubItems->Add(String::Format("{0:C}", inventoryItem.getItemPrice()));
			item->SubItems->Add(gcnew String(inventoryItem.getDescription().c_str()));
			item->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Regular);
			listView_Inventory->Items->Add(item);
		}

		for (Room room : rooms)
		{
			ListViewItem ^item = gcnew ListViewItem(gcnew String(room.getRoomNumber().c_str()));
			item->SubItems->Add(gcnew String(room.getMaxSize().ToString()));
			item->SubItems->Add(gcnew String(room.getNumPatients().ToString()));
			item->Font = gcnew System::Drawing::Font(listView_Patients->Font, System::Drawing::FontStyle::Regular);
			listView_Rooms->Items->Add(item);
		}

		// display notifications.
		for (int i = 0; i < notifications->Count; i++)
		{
			listView_Notifications->Items->Add(notifications[i]);
		}
	}

	System::Void FormMain::FormMain_Load(System::Object^  sender, System::EventArgs^  e)
	{
		updateData(); // display all data from the database.
	}

	System::Void FormMain::contextMenuStrip_Inventory_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
	{
		if (this->listView_Inventory->SelectedItems->Count == 0)
		{
			this->contextMenuStrip_Inventory->Items[0]->Visible = true;
			this->contextMenuStrip_Inventory->Items[1]->Visible = false;
			this->contextMenuStrip_Inventory->Items[2]->Visible = false;
		}
		else
		{
			this->contextMenuStrip_Inventory->Items[0]->Visible = false;
			this->contextMenuStrip_Inventory->Items[1]->Visible = true;
			this->contextMenuStrip_Inventory->Items[2]->Visible = true;
		}
	}

	System::Void FormMain::addItemToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			// display itemDialog and save the resulting item.
			ItemDialog ^id = gcnew ItemDialog();
			if (id->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Item item(msclr::interop::marshal_as<std::string>(id->getItemName()),
					id->getItemPrice(),
					id->getItemStock(),
					id->getItemsSold(),
					msclr::interop::marshal_as<std::string>(id->getItemDescription()));
				Globals::databaseManager->saveItem(item);
				updateData();
			}
		}
		catch (Exception ^ex)
		{
			MessageBox::Show(String::Format("Error adding item: {0}", ex));
		}
	}
	System::Void FormMain::editItemToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Inventory->SelectedItems->Count > 0)
		{
			try
			{
				// display the itemDialog and save the results.
				String ^itemName = listView_Inventory->SelectedItems[0]->Text;
				ItemDialog ^id = gcnew ItemDialog(itemName);
				if (id->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					Item item(msclr::interop::marshal_as<std::string>(id->getItemName()),
						id->getItemPrice(),
						id->getItemStock(),
						id->getItemsSold(),
						msclr::interop::marshal_as<std::string>(id->getItemDescription()));
					Globals::databaseManager->saveItem(itemName, item);
					updateData();
				}
			}
			catch (Exception ^ex)
			{
				MessageBox::Show(String::Format("Error editing item: {0}", ex));
			}
		}
	}
	System::Void FormMain::removeItemToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Inventory->SelectedItems->Count > 0)
		{
			// remove item from the list.
			Globals::databaseManager->removeItem(listView_Inventory->SelectedItems[0]->Text);
			updateData();
		}
	}

	System::Void FormMain::contextMenuStrip_Rooms_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		if (listView_Rooms->SelectedItems->Count > 0)
		{
			addRoomToolStripMenuItem->Visible = false;
			editRoomToolStripMenuItem->Visible = true;
			removeRoomToolStripMenuItem->Visible = true;
			addPatientToToolStripMenuItem->Visible = true;
			removePatientFromRoomToolStripMenuItem->Visible = true;
			clearRoomToolStripMenuItem->Visible = true;
		}
		else
		{
			addRoomToolStripMenuItem->Visible = true;
			editRoomToolStripMenuItem->Visible = false;
			removeRoomToolStripMenuItem->Visible = false;
			addPatientToToolStripMenuItem->Visible = false;
			removePatientFromRoomToolStripMenuItem->Visible = false;
			clearRoomToolStripMenuItem->Visible = false;
		}
	}

	System::Void FormMain::addRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			// display the room dialog
			RoomDialog ^rd = gcnew RoomDialog();
			if (rd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Room room(
					msclr::interop::marshal_as<std::string>(rd->getRoomNumber()),
					rd->getCapacity());
				List<String^> ^patients = rd->getPatients();
				for (int i = 0; i < patients->Count; i++) // loop through all patients.
				{
					// update patient in the database.
					Patient patient = Globals::databaseManager->getPatient(patients[i]);
					if (patient.getPatientID() != "")
					{
						Room oldRoom = Globals::databaseManager->getRoom(gcnew String(patient.getRoomNumber().c_str()));
						if (oldRoom.getRoomNumber() != "")
						{
							oldRoom.removePatient(patient.getPatientID());
							Globals::databaseManager->saveRoom(oldRoom);
						}
						patient.setRoomNumber(room.getRoomNumber());
						room.addPatient(patient);
						Globals::databaseManager->savePatient(patient);
					}
				}
				Globals::databaseManager->saveRoom(room);
				updateData();
			}
		}
		catch (Exception ^ex)
		{
			MessageBox::Show(String::Format("Error adding room: {0}",ex));
		}
	}
	System::Void FormMain::editRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Rooms->SelectedItems->Count > 0)
		{
			try
			{
				// display the room dialog.
				String ^roomNumber = listView_Rooms->SelectedItems[0]->Text;
				RoomDialog ^rd = gcnew RoomDialog(roomNumber);
				if (rd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					Room room(
						msclr::interop::marshal_as<std::string>(rd->getRoomNumber()),
						rd->getCapacity());
					List<String^> ^patients = rd->getPatients();
					for (int i = 0; i < patients->Count; i++) // loop through all patients
					{
						// update patients in the database.
						Patient patient = Globals::databaseManager->getPatient(patients[i]);
						if (patient.getPatientID() != "")
						{
							Room oldRoom = Globals::databaseManager->getRoom(gcnew String(patient.getRoomNumber().c_str()));
							if (oldRoom.getRoomNumber() != "")
							{
								oldRoom.removePatient(patient.getPatientID());
								Globals::databaseManager->saveRoom(oldRoom);
							}
							patient.setRoomNumber(room.getRoomNumber());
							room.addPatient(patient);
							Globals::databaseManager->savePatient(patient);
						}
					}

					// save the room in the database.
					Globals::databaseManager->saveRoom(roomNumber, room);
					updateData();
				}
			}
			catch (Exception ^ex)
			{
				MessageBox::Show(String::Format("Error editing room: {0}", ex));
			}
		}
	}
	System::Void FormMain::removeRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Rooms->SelectedItems->Count > 0)
		{
			// remove room.
			Room room = Globals::databaseManager->getRoom(listView_Rooms->SelectedItems[0]->Text);
			for (Patient patient : room.getPatients())
			{
				if (patient.getPatientID() != "")
				{
					patient.setRoomNumber("");
					room.removePatient(patient.getPatientID());
					Globals::databaseManager->savePatient(patient);
				}
			}
			Globals::databaseManager->removeRoom(listView_Rooms->SelectedItems[0]->Text);
			updateData();
		}
	}
	System::Void FormMain::addPatientToToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listView_Rooms->SelectedItems->Count > 0)
		{
			PersonSelectorDialog ^psd = gcnew PersonSelectorDialog("Patients");
			if (psd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Room room = Globals::databaseManager->getRoom(listView_Rooms->SelectedItems[0]->Text);
				Patient patient = Globals::databaseManager->getPatient(psd->getPersonID());
				if (patient.getRoomNumber() != "")
				{
					Room oldRoom = Globals::databaseManager->getRoom(gcnew String(patient.getRoomNumber().c_str()));
					oldRoom.removePatient(patient.getPatientID());
					Globals::databaseManager->saveRoom(oldRoom);
				}
				patient.setRoomNumber(room.getRoomNumber());
				room.addPatient(patient);
				Globals::databaseManager->saveRoom(room);
				Globals::databaseManager->savePatient(patient);
				updateData();
			}

			//Globals::databaseManager->removePatientFromRoom()
		}
	}
	System::Void FormMain::removePatientFromRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listView_Rooms->SelectedItems->Count > 0)
		{
			Room room = Globals::databaseManager->getRoom(listView_Rooms->SelectedItems[0]->Text);
			List<String^> ^patients = gcnew List<String^>();
			for (Patient patient : room.getPatients())
				patients->Add(gcnew String(patient.getName().c_str()));

			PersonSelectorDialog ^psd = gcnew PersonSelectorDialog("Patients", patients);
			if (psd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Patient patient = Globals::databaseManager->getPatient(psd->getPersonID());
				room.removePatient(patient.getPatientID());
				patient.setRoomNumber("");
				Globals::databaseManager->saveRoom(room);
				Globals::databaseManager->savePatient(patient);
				updateData();
			}
		}
	}
	System::Void FormMain::clearRoomToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Rooms->SelectedItems->Count > 0)
		{
			Globals::databaseManager->clearRoom(listView_Rooms->SelectedItems[0]->Text);
			updateData();
		}
	}

	System::Void FormMain::addPatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			PatientDialog ^pd = gcnew PatientDialog();
			if (pd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Patient patient(msclr::interop::marshal_as<std::string>(pd->getName()),
					msclr::interop::marshal_as<std::string>(pd->getDateOfBirth()),
					msclr::interop::marshal_as<std::string>(pd->getEmergencyContact()),
					ContactInformation(msclr::interop::marshal_as<std::string>(pd->getAddress()),
						msclr::interop::marshal_as<std::string>(pd->getHomePhone()),
						msclr::interop::marshal_as<std::string>(pd->getCellPhone()),
						msclr::interop::marshal_as<std::string>(pd->getWorkPhone()),
						msclr::interop::marshal_as<std::string>(pd->getFax()),
						msclr::interop::marshal_as<std::string>(pd->getEmail())
					),
					msclr::interop::marshal_as<std::string>(pd->getPatientID()),
					msclr::interop::marshal_as<std::string>(pd->getRoomNumber()),
					msclr::interop::marshal_as<std::string>(pd->getDoctorID()),
					msclr::interop::marshal_as<std::string>(pd->getNurseID()),
					pd->getBill(),
					msclr::interop::marshal_as<std::string>(pd->getAilment()),
					msclr::interop::marshal_as<std::string>(pd->getInsurance())
				);

				MedicalEmployee doctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
				MedicalEmployee nurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
				Room room = Globals::databaseManager->getRoom(gcnew String(patient.getRoomNumber().c_str()));

				if (doctor.getPatient(patient.getPatientID()).getPatientID() == "")
					doctor.addPatient(patient);

				if (nurse.getPatient(patient.getPatientID()).getPatientID() == "")
					nurse.addPatient(patient);

				if (room.getPatient(patient.getPatientID()).getPatientID() == "")
					room.addPatient(patient);

				Globals::databaseManager->saveMedicalEmployee("Doctors",doctor);
				Globals::databaseManager->saveMedicalEmployee("Nurses",nurse);
				Globals::databaseManager->saveRoom(room);
				Globals::databaseManager->savePatient(patient);

				updateData();
			}
		}
		catch (Exception ^ex)
		{
			MessageBox::Show(String::Format("Error adding patient: {0}", ex));
		}
	}
	System::Void FormMain::editPatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			if (listView_Patients->SelectedItems->Count > 0)
			{
				String ^patientID = listView_Patients->SelectedItems[0]->SubItems[1]->Text;
				PatientDialog ^pd = gcnew PatientDialog(patientID);
				if (pd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					Patient patient(msclr::interop::marshal_as<std::string>(pd->getName()),
						msclr::interop::marshal_as<std::string>(pd->getDateOfBirth()),
						msclr::interop::marshal_as<std::string>(pd->getEmergencyContact()),
						ContactInformation(msclr::interop::marshal_as<std::string>(pd->getAddress()),
							msclr::interop::marshal_as<std::string>(pd->getHomePhone()),
							msclr::interop::marshal_as<std::string>(pd->getCellPhone()),
							msclr::interop::marshal_as<std::string>(pd->getWorkPhone()),
							msclr::interop::marshal_as<std::string>(pd->getFax()),
							msclr::interop::marshal_as<std::string>(pd->getEmail())
						),
						msclr::interop::marshal_as<std::string>(pd->getPatientID()),
						msclr::interop::marshal_as<std::string>(pd->getRoomNumber()),
						msclr::interop::marshal_as<std::string>(pd->getDoctorID()),
						msclr::interop::marshal_as<std::string>(pd->getNurseID()),
						pd->getBill(),
						msclr::interop::marshal_as<std::string>(pd->getAilment()),
						msclr::interop::marshal_as<std::string>(pd->getInsurance())
					);

					MedicalEmployee doctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
					MedicalEmployee nurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
					Room room = Globals::databaseManager->getRoom(gcnew String(patient.getRoomNumber().c_str()));

					if (doctor.getPatient(patient.getPatientID()).getPatientID() == "")
						doctor.addPatient(patient);

					if (nurse.getPatient(patient.getPatientID()).getPatientID() == "")
						nurse.addPatient(patient);

					if (room.getPatient(patient.getPatientID()).getPatientID() == "")
						room.addPatient(patient);

					Globals::databaseManager->saveMedicalEmployee("Doctors", doctor);
					Globals::databaseManager->saveMedicalEmployee("Nurses", nurse);
					Globals::databaseManager->saveRoom(room);
					Globals::databaseManager->savePatient(patient);

					updateData();
				}
			}
		}
		catch (Exception ^ex)
		{
			MessageBox::Show(String::Format("Error adding patient: {0}", ex));
		}
	}
	System::Void FormMain::removePatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Patients->SelectedItems->Count > 0)
		{
			Patient patient = Globals::databaseManager->getPatient(listView_Patients->SelectedItems[0]->SubItems[1]->Text);
			MedicalEmployee doctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
			MedicalEmployee nurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
			Room room = Globals::databaseManager->getRoom(gcnew String(patient.getRoomNumber().c_str()));

			if (doctor.getEmployeeID() != "")
			{
				doctor.removePatient(patient.getPatientID());
				Globals::databaseManager->saveMedicalEmployee("Doctors", doctor);
			}
			if (nurse.getEmployeeID() != "")
			{
				nurse.removePatient(patient.getPatientID());
				Globals::databaseManager->saveMedicalEmployee("Nurses", nurse);
			}
			if (room.getPatient(patient.getPatientID()).getPatientID() != "")
			{
				room.removePatient(patient.getPatientID());
				Globals::databaseManager->saveRoom(room);
			}

			Globals::databaseManager->removePatient(listView_Patients->SelectedItems[0]->SubItems[1]->Text);
			updateData();
		}
	}
	System::Void FormMain::assignPatientDoctorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Patients->SelectedItems->Count > 0)
		{
			PersonSelectorDialog ^psd = gcnew PersonSelectorDialog("Doctors");
			if (psd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Patient patient = Globals::databaseManager->getPatient(listView_Patients->SelectedItems[0]->SubItems[1]->Text);
				MedicalEmployee doctor = Globals::databaseManager->getDoctor(psd->getPersonID());
				MedicalEmployee oldDoctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
				if (oldDoctor.getEmployeeID() != "")
				{
					oldDoctor.removePatient(patient.getPatientID());
					Globals::databaseManager->saveMedicalEmployee("Doctors", oldDoctor);
				}
				patient.setDoctor(doctor.getEmployeeID());
				doctor.addPatient(patient);
				Globals::databaseManager->saveMedicalEmployee("Doctors", doctor);
				Globals::databaseManager->savePatient(patient);
				updateData();
			}
		}
	}
	System::Void FormMain::assignPatientNurseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Patients->SelectedItems->Count > 0)
		{
			PersonSelectorDialog ^psd = gcnew PersonSelectorDialog("Nurses");
			if (psd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Patient patient = Globals::databaseManager->getPatient(listView_Patients->SelectedItems[0]->SubItems[1]->Text);
				MedicalEmployee nurse = Globals::databaseManager->getNurse(psd->getPersonID());
				MedicalEmployee oldNurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
				if (oldNurse.getEmployeeID() != "")
				{
					oldNurse.removePatient(patient.getPatientID());
					Globals::databaseManager->saveMedicalEmployee("Nurses", oldNurse);
				}
				patient.setNurse(nurse.getEmployeeID());
				nurse.addPatient(patient);
				Globals::databaseManager->saveMedicalEmployee("Nurses", nurse);
				Globals::databaseManager->savePatient(patient);
				updateData();
			}
		}
	}

	System::Void FormMain::contextMenuStrip_Patients_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		if (listView_Patients->SelectedItems->Count > 0)
		{
			addPatientToolStripMenuItem->Visible = false;
			editPatientToolStripMenuItem->Visible = true;
			removePatientToolStripMenuItem->Visible = true;
			assignPatientDoctorToolStripMenuItem->Visible = true;
			assignPatientNurseToolStripMenuItem->Visible = true;
		}
		else
		{
			addPatientToolStripMenuItem->Visible = true;
			editPatientToolStripMenuItem->Visible = false;
			removePatientToolStripMenuItem->Visible = false;
			assignPatientDoctorToolStripMenuItem->Visible = false;
			assignPatientNurseToolStripMenuItem->Visible = false;
		}
	}

	System::Void FormMain::contextMenuStrip_OtherEmployees_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		if (listView_Other->SelectedItems->Count > 0)
		{
			addEmployeeToolStripMenuItem->Visible = false;
			editEmployeeToolStripMenuItem->Visible = true;
			removeEmployeeToolStripMenuItem->Visible = true;
		}
		else
		{
			addEmployeeToolStripMenuItem->Visible = true;
			editEmployeeToolStripMenuItem->Visible = false;
			removeEmployeeToolStripMenuItem->Visible = false;
		}
	}

	System::Void FormMain::addEmployeeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			EmployeeDialog ^ed = gcnew EmployeeDialog();
			if (ed->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				Employee employee(msclr::interop::marshal_as<std::string>(ed->getName()),
					msclr::interop::marshal_as<std::string>(ed->getDateOfBirth()),
					msclr::interop::marshal_as<std::string>(ed->getEmergencyContact()),
					ContactInformation(msclr::interop::marshal_as<std::string>(ed->getAddress()),
						msclr::interop::marshal_as<std::string>(ed->getHomePhone()),
						msclr::interop::marshal_as<std::string>(ed->getCellPhone()),
						msclr::interop::marshal_as<std::string>(ed->getWorkPhone()),
						msclr::interop::marshal_as<std::string>(ed->getFaxNumber()),
						msclr::interop::marshal_as<std::string>(ed->getEmail())
					),
					msclr::interop::marshal_as<std::string>(ed->getEmployeeID()),
					ed->getClockedIn(),
					ed->getSalary(),
					ed->getHoursWorkedPerWeek(),
					ed->getExperience()
				);
				Globals::databaseManager->saveEmployee(employee);
				updateData();
			}
		}
		catch (Exception ^ex)
		{
			MessageBox::Show(String::Format("Error adding employee: {0}", ex));
		}
	}
	System::Void FormMain::editEmployeeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView_Other->SelectedItems->Count > 0)
		{
			try
			{
				String ^employeeID = listView_Other->SelectedItems[0]->SubItems[1]->Text;
				EmployeeDialog ^ed = gcnew EmployeeDialog(employeeID);
				if (ed->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					Employee employee(msclr::interop::marshal_as<std::string>(ed->getName()),
						msclr::interop::marshal_as<std::string>(ed->getDateOfBirth()),
						msclr::interop::marshal_as<std::string>(ed->getEmergencyContact()),
						ContactInformation(msclr::interop::marshal_as<std::string>(ed->getAddress()),
							msclr::interop::marshal_as<std::string>(ed->getHomePhone()),
							msclr::interop::marshal_as<std::string>(ed->getCellPhone()),
							msclr::interop::marshal_as<std::string>(ed->getWorkPhone()),
							msclr::interop::marshal_as<std::string>(ed->getFaxNumber()),
							msclr::interop::marshal_as<std::string>(ed->getEmail())
						),
						msclr::interop::marshal_as<std::string>(ed->getEmployeeID()),
						ed->getClockedIn(),
						ed->getSalary(),
						ed->getHoursWorkedPerWeek(),
						ed->getExperience()
					);
					Globals::databaseManager->saveEmployee(employeeID, employee);
					updateData();
				}
			}
			catch (Exception ^ex)
			{
				MessageBox::Show(String::Format("Error adding employee: {0}", ex));
			}
		}
	}
	System::Void FormMain::removeEmployeeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (listView_Other->SelectedItems->Count > 0)
		{
			Globals::databaseManager->removeEmployee(listView_Other->SelectedItems[0]->SubItems[1]->Text);
		}
	}

	System::Void FormMain::contextMenuStrip_MedicalEmployee_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
	{
		ListView ^curListView = ((ListView^)((System::Windows::Forms::ContextMenuStrip^)sender)->SourceControl);
		if (curListView->Name == "listView_Doctors")
		{
			addToolStripMenuItem->Text = "Add Doctor";
			editToolStripMenuItem->Text = "Edit Doctor";
			removeToolStripMenuItem->Text = "Remove Doctor";
			assignPatientToolStripMenuItem->Text = "Assign Patient To Doctor";
			removePatientFromToolStripMenuItem->Text = "Remove Patient From Doctor";

			//MessageBox::Show("listView_Doctors");
		}
		else if (curListView->Name == "listView_Nurses")
		{
			addToolStripMenuItem->Text = "Add Nurse";
			editToolStripMenuItem->Text = "Edit Nurse";
			removeToolStripMenuItem->Text = "Remove Nurse";
			assignPatientToolStripMenuItem->Text = "Assign Patient To Nurse";
			removePatientFromToolStripMenuItem->Text = "Remove Patient From Nurse";
			//MessageBox::Show("listView_Nurses");
		}

		if (curListView->SelectedItems->Count > 0)
		{
			addToolStripMenuItem->Visible = false;
			editToolStripMenuItem->Visible = true;
			removeToolStripMenuItem->Visible = true;
			assignPatientToolStripMenuItem->Visible = true;
			removePatientFromToolStripMenuItem->Visible = true;
		}
		else
		{
			addToolStripMenuItem->Visible = true;
			editToolStripMenuItem->Visible = false;
			removeToolStripMenuItem->Visible = false;
			assignPatientToolStripMenuItem->Visible = false;
			removePatientFromToolStripMenuItem->Visible = false;
		}
	}

	System::Void FormMain::addToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^table;
		MedicalEmployeeDialog ^med;
		ListView ^curListView = ((ListView^)((System::Windows::Forms::ContextMenuStrip ^) ((ToolStripMenuItem^)sender)->Owner)->SourceControl);
		if (curListView->Name == "listView_Doctors")
		{
			med = gcnew MedicalEmployeeDialog(EMPLOYEE_TYPE_DOCTOR);
			table = "Doctors";
		}
		else if (curListView->Name == "listView_Nurses")
		{
			med = gcnew MedicalEmployeeDialog(EMPLOYEE_TYPE_NURSE);
			table = "Nurses";
		}
		if (med->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			MedicalEmployee employee(msclr::interop::marshal_as<std::string>(med->getName()),
				msclr::interop::marshal_as<std::string>(med->getDateOfBirth()),
				msclr::interop::marshal_as<std::string>(med->getEmergencyContact()),
				ContactInformation(msclr::interop::marshal_as<std::string>(med->getAddress()),
					msclr::interop::marshal_as<std::string>(med->getHomePhone()),
					msclr::interop::marshal_as<std::string>(med->getCellPhone()),
					msclr::interop::marshal_as<std::string>(med->getWorkPhone()),
					msclr::interop::marshal_as<std::string>(med->getFaxNumber()),
					msclr::interop::marshal_as<std::string>(med->getEmail())
				),
				msclr::interop::marshal_as<std::string>(med->getEmployeeID()),
				med->getClockedIn(),
				med->getSalary(),
				med->getHoursWorkedPerWeek(),
				med->getExperience(),
				msclr::interop::marshal_as<std::string>(med->getDegree()),
				msclr::interop::marshal_as<std::string>(med->getSpecialization()));

			List<String^> ^patients = med->getPatients();
			Patient patient;
			employee.clearPatients();
			for (int i = 0; i < patients->Count; i++)
			{
				patient = Globals::databaseManager->getPatient(patients[i]);
				if (patients[i] == gcnew String(patient.getPatientID().c_str()))
				{
					if (curListView->Name == "listView_Doctors")
					{
						if (patient.getDoctor() != "")
						{
							MedicalEmployee oldDoctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
							if (oldDoctor.getEmployeeID() == patient.getDoctor())
							{
								oldDoctor.removePatient(patient.getPatientID());
								Globals::databaseManager->saveMedicalEmployee("Doctors", oldDoctor);
							}
						}
						patient.setDoctor(employee.getEmployeeID());
					}
					else if (curListView->Name == "listView_Nurses")
					{
						if (patient.getNurse() != "")
						{
							MedicalEmployee oldNurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
							if (oldNurse.getEmployeeID() == patient.getNurse())
							{
								oldNurse.removePatient(patient.getPatientID());
								Globals::databaseManager->saveMedicalEmployee("Nurses", oldNurse);
							}
						}
						patient.setNurse(employee.getEmployeeID());
					}
					Globals::databaseManager->savePatient(patient);
					employee.addPatient(patient);
				}
			}

			Globals::databaseManager->saveMedicalEmployee(table, employee);

			updateData();
		}
	}
	System::Void FormMain::editToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String ^table, ^employeeID;
		MedicalEmployeeDialog ^med;
		ListView ^curListView = ((ListView^)((System::Windows::Forms::ContextMenuStrip ^) ((ToolStripMenuItem^)sender)->Owner)->SourceControl);
		if (curListView->SelectedItems->Count > 0)
		{
			employeeID = curListView->SelectedItems[0]->SubItems[1]->Text;
			if (curListView->Name == "listView_Doctors")
			{
				med = gcnew MedicalEmployeeDialog(EMPLOYEE_TYPE_DOCTOR, employeeID);
				table = "Doctors";
			}
			else if (curListView->Name == "listView_Nurses")
			{
				med = gcnew MedicalEmployeeDialog(EMPLOYEE_TYPE_NURSE, employeeID);
				table = "Nurses";
			}
			if (med->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				MedicalEmployee employee(msclr::interop::marshal_as<std::string>(med->getName()),
					msclr::interop::marshal_as<std::string>(med->getDateOfBirth()),
					msclr::interop::marshal_as<std::string>(med->getEmergencyContact()),
					ContactInformation(msclr::interop::marshal_as<std::string>(med->getAddress()),
						msclr::interop::marshal_as<std::string>(med->getHomePhone()),
						msclr::interop::marshal_as<std::string>(med->getCellPhone()),
						msclr::interop::marshal_as<std::string>(med->getWorkPhone()),
						msclr::interop::marshal_as<std::string>(med->getFaxNumber()),
						msclr::interop::marshal_as<std::string>(med->getEmail())
					),
					msclr::interop::marshal_as<std::string>(med->getEmployeeID()),
					med->getClockedIn(),
					med->getSalary(),
					med->getHoursWorkedPerWeek(),
					med->getExperience(),
					msclr::interop::marshal_as<std::string>(med->getDegree()),
					msclr::interop::marshal_as<std::string>(med->getSpecialization()));

				List<String^> ^patients = med->getPatients();
				Patient patient;
				employee.clearPatients();
				Globals::databaseManager->clearMedicalEmployeeFromPatients(curListView->Name->Split('_')[1]->ToLower()->TrimEnd('s'), gcnew String(employee.getEmployeeID().c_str()));
				for (int i = 0; i < patients->Count; i++)
				{
					patient = Globals::databaseManager->getPatient(patients[i]);
					if (patients[i] == gcnew String(patient.getPatientID().c_str()))
					{
						if (curListView->Name == "listView_Doctors")
						{
							if (patient.getDoctor() != "")
							{
								MedicalEmployee oldDoctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
								if (oldDoctor.getEmployeeID() == patient.getDoctor())
								{
									oldDoctor.removePatient(patient.getPatientID());
									Globals::databaseManager->saveMedicalEmployee("Doctors", oldDoctor);
								}
							}
							patient.setDoctor(employee.getEmployeeID());
						}
						else if (curListView->Name == "listView_Nurses")
						{
							if (patient.getNurse() != "")
							{
								MedicalEmployee oldNurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
								if (oldNurse.getEmployeeID() == patient.getNurse())
								{
									oldNurse.removePatient(patient.getPatientID());
									Globals::databaseManager->saveMedicalEmployee("Nurses", oldNurse);
								}
							}
							patient.setNurse(employee.getEmployeeID());
						}
						Globals::databaseManager->savePatient(patient);
						employee.addPatient(patient);
					}
				}

				Globals::databaseManager->saveMedicalEmployee(employeeID, table, employee);

				updateData();
			}
		}
	}
	System::Void FormMain::removeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		MedicalEmployee employee;
		ListView ^curListView = ((ListView^)((System::Windows::Forms::ContextMenuStrip ^) ((ToolStripMenuItem^)sender)->Owner)->SourceControl);
		if (curListView->Name == "listView_Doctors")
		{
			if (curListView->SelectedItems->Count > 0)
			{
				employee = Globals::databaseManager->getDoctor(curListView->SelectedItems[0]->SubItems[1]->Text);
				for (Patient patient : employee.getPatients())
				{
					patient.setDoctor("");
					Globals::databaseManager->savePatient(patient);
				}
				Globals::databaseManager->removeMedicalEmployee("Doctors", curListView->SelectedItems[0]->SubItems[1]->Text);
				updateData();
			}
		}
		else if (curListView->Name == "listView_Nurses")
		{
			if (curListView->SelectedItems->Count > 0)
			{
				employee = Globals::databaseManager->getNurse(curListView->SelectedItems[0]->SubItems[1]->Text);
				for (Patient patient : employee.getPatients())
				{
					patient.setNurse("");
					Globals::databaseManager->savePatient(patient);
				}
				Globals::databaseManager->removeMedicalEmployee("Nurses", curListView->SelectedItems[0]->SubItems[1]->Text);
				updateData();
			}
		}
	}
	System::Void FormMain::assignPatientToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ListView ^curListView = ((ListView^)((System::Windows::Forms::ContextMenuStrip ^) ((ToolStripMenuItem^)sender)->Owner)->SourceControl);
		PersonSelectorDialog ^psd = gcnew PersonSelectorDialog("Patients");

		if (curListView->SelectedItems->Count > 0)
		{
			if (psd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (curListView->Name == "listView_Doctors")
				{
					MedicalEmployee doctor = Globals::databaseManager->getDoctor(curListView->SelectedItems[0]->SubItems[1]->Text);
					Patient patient = Globals::databaseManager->getPatient(psd->getPersonID());

					if (patient.getDoctor() != "")
					{
						MedicalEmployee oldDoctor = Globals::databaseManager->getDoctor(gcnew String(patient.getDoctor().c_str()));
						oldDoctor.removePatient(patient.getPatientID());
						Globals::databaseManager->saveMedicalEmployee("Doctors", oldDoctor);
					}

					patient.setDoctor(doctor.getEmployeeID());
					doctor.addPatient(patient);
					Globals::databaseManager->saveMedicalEmployee("Doctors", doctor);
					Globals::databaseManager->savePatient(patient);
				}
				else if (curListView->Name == "listView_Nurses")
				{
					MedicalEmployee nurse = Globals::databaseManager->getNurse(curListView->SelectedItems[0]->SubItems[1]->Text);
					Patient patient = Globals::databaseManager->getPatient(psd->getPersonID());

					if (patient.getNurse() != "")
					{
						MedicalEmployee oldNurse = Globals::databaseManager->getNurse(gcnew String(patient.getNurse().c_str()));
						oldNurse.removePatient(patient.getPatientID());
						Globals::databaseManager->saveMedicalEmployee("Nurses", oldNurse);
					}

					patient.setNurse(nurse.getEmployeeID());
					nurse.addPatient(patient);
					Globals::databaseManager->saveMedicalEmployee("Nurses", nurse);
					Globals::databaseManager->savePatient(patient);
				}
				updateData();
			}
		}
	}
	System::Void FormMain::removePatientFromToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ListView ^curListView = ((ListView^)((System::Windows::Forms::ContextMenuStrip ^) ((ToolStripMenuItem^)sender)->Owner)->SourceControl);

		if (curListView->SelectedItems->Count > 0)
		{
			MedicalEmployee employee;
			if (curListView->Name == "listView_Doctors")
				employee = Globals::databaseManager->getDoctor(curListView->SelectedItems[0]->SubItems[1]->Text);
			else if (curListView->Name == "listView_Nurses")
				employee = Globals::databaseManager->getNurse(curListView->SelectedItems[0]->SubItems[1]->Text);

			List<String^> ^patients = gcnew List<String^>();
			for (Patient patient : employee.getPatients())
				patients->Add(gcnew String(patient.getName().c_str()));

			PersonSelectorDialog ^psd = gcnew PersonSelectorDialog("Patients", patients);
			if (psd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				if (curListView->Name == "listView_Doctors")
				{
					MedicalEmployee doctor = Globals::databaseManager->getDoctor(curListView->SelectedItems[0]->SubItems[1]->Text);
					Patient patient = Globals::databaseManager->getPatient(psd->getPersonID());

					patient.setDoctor("");
					doctor.removePatient(patient.getPatientID());
					Globals::databaseManager->saveMedicalEmployee("Doctors", doctor);
					Globals::databaseManager->savePatient(patient);
				}
				else if (curListView->Name == "listView_Nurses")
				{
					MedicalEmployee nurse = Globals::databaseManager->getNurse(curListView->SelectedItems[0]->SubItems[1]->Text);
					Patient patient = Globals::databaseManager->getPatient(psd->getPersonID());

					patient.setDoctor("");
					nurse.removePatient(patient.getPatientID());
					Globals::databaseManager->saveMedicalEmployee("Nurses", nurse);
					Globals::databaseManager->savePatient(patient);
				}
				updateData();
			}
			
		}
	}
	System::Void FormMain::cLoseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Application::Exit();
	}
}