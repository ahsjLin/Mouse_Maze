//---------------------------------------------------------------------------

#ifndef findExitThreadH
#define findExitThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class findExitThread : public TThread
{
private:
protected:
	void __fastcall Execute();
public:
	__fastcall findExitThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
