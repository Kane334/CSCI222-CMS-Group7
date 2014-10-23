#include "login.h"
using namespace std;
int main()
{
	bool setup=dbSetup(); //checks server has relevant files, if not prompts to make them
	if(setup==false)
		return -1;
	//else
	//	dbRead();
	Login();
	//dbOutput(masterList);
}


