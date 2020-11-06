#pragma once

#include "DatabaseManager.h"

namespace HospitalAdministrationSystem
{
	using namespace System;

	public ref class Globals
	{
	public:
		static DatabaseManager ^databaseManager = gcnew DatabaseManager("Data Source=HAS.db");
	};
}