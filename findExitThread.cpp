//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "findExitThread.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall findExitThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall findExitThread::findExitThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall findExitThread::Execute()
{
	//---- Place thread code here ----
    FreeOnTerminate = true;
    findEixt();
}
//---------------------------------------------------------------------------
