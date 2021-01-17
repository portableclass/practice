#include "MyForm.h"
#include <Windows.h>
#include <iostream>
#include <ctime>
#include  "../Project1/functions.cpp"

using namespace std;
using namespace System;
using  namespace Microsoft::Win32;
using namespace Project1; // Название проекта

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

/*int division (int x, int y)
{
	return y == 0 ? throw overflow_error("Error") : (x / y);
}*/
int save()
{
	RegistryKey^ rk;
	rk = Registry::CurrentUser->OpenSubKey("Software", true);
	if (!rk)
	{
		Console::WriteLine("Failed to open CurrentUser/Software key");
		return -1;
	}

	RegistryKey^ nk = rk->CreateSubKey("NewRegKey");
	if (!nk)
	{
		Console::WriteLine("Failed to create 'NewRegKey'");
		return -1;
	}

	String^ newValue = "GGpokerok";
	try
	{
		nk->SetValue("NewKey", newValue);
		nk->SetValue("NewKey2", 44);
	}
	catch (Exception^)
	{
		Console::WriteLine("Failed to set new values in 'NewRegKey'");
		return -1;
	}

	Console::WriteLine("New key created.");
	Console::Write("Use REGEDIT.EXE to verify ");
	Console::WriteLine("'CURRENTUSER/Software/NewRegKey'\n");
	return 0;
}
int download()
{
	cli::array<String^>^ key = Registry::CurrentUser->GetSubKeyNames();

	Console::WriteLine("Subkeys within CurrentUser root key:");
	for (int i = 0; i < key->Length; i++)
	{
		Console::WriteLine("   {0}", key[i]);
	}

	Console::WriteLine("Opening subkey 'Identities'...");
	RegistryKey^ rk = nullptr;
	rk = Registry::CurrentUser->OpenSubKey("Identities");
	if (rk == nullptr)
	{
		Console::WriteLine("Registry key not found - aborting");
		return -1;
	}

	Console::WriteLine("Key/value pairs within 'Identities' key:");
	cli::array<String^>^ name = rk->GetValueNames();
	for (int i = 0; i < name->Length; i++)
	{
		String^ value = rk->GetValue(name[i])->ToString();
		Console::WriteLine("   {0} = {1}", name[i], value);
	}

	return 0;
}
System::Void MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));

	/*try {
		cout << division(1, 0) << '\n';
	}
	catch (const overflow_error& e) {
		cout << e.what() << '\n';
	}*/
	const int size = 20001;
	int* a = new int[size];
	int* b = new int[size];

	textBox3->Text = System::Convert::ToString(size);
	generateArray(a, size);
	cloneArray(a, b, size);
	sortingMax(a, size);
	sortingMin(b, size);

	textBox1->Text = System::Convert::ToString(a[size - 1]);
	textBox2->Text = System::Convert::ToString(b[size - 1]);

	delete[] a;
	delete[] b;
}
System::Void MyForm::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	save();
}
System::Void MyForm::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	download();
}