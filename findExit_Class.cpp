//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "findExit_Class.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
void __fastcall findExit::UpdateCaption()
{
		//Form1->Caption = "Updated in a thread";
}
//---------------------------------------------------------------------------

__fastcall findExit::findExit(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall findExit::Execute()
{
    // auto free when finished
	FreeOnTerminate = true;
	findEixt();
	Synchronize(UpdateCaption);
}
//---------------------------------------------------------------------------
