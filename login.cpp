#ifndef LOGIN
#define LOGIN
#include<iostream>
#include<fstream>
#include<cstring>
#include"users.h"
#include<cstdlib>
#include"actions.h"
using namespace std;


bool Login()
{
	userData user;
	string userN, userP;
	bool loggedIn=false;
	cout << "Welcome to CMS login service - potato" << endl;   
	while(loggedIn==false)
	{
		cout << "Please enter your username and password" << endl;  //1.system prompts for user name and password
		cout << "Username: ";
		cin >> userN; //2.user enters username and password
		if(userN=="exit")
		{
			user.priv=-1;
			cout << "Exiting..." << endl;
			return false;
		}
		cout << "Password (username and password is encrypted by OpenSSL); ";
		cin >> userP;
		user.userN=userN;
		user.userP=userP;
		user=searchUser(user);
		//3. sends username and password to be validated
		if(user.userN=="-1")
			cout << "Incorrect username or password, enter exit to cancel login" << endl;
		else
			loggedIn=true;
		//cout << "\033[2J" << endl;
	}
	cout << user.priv << endl;
	switch(user.priv)  //4. adjusts user to appropriate menu
	{
		case 0: adminMenu(user);
			break;
		case 1: 
			break;
		case 2: //manage papers/allocate
			break;
		case 3:
			break;
		case 4: //submitPapers(user);
			break;
		default:
			break;
	}
	return true;
}
userData searchUser(userData &user1)
{
	listClass search;
	cout << search.listUser.size() << endl;
	for(int i=0; i<(signed)search.listUser.size();i++)
	{
		cout << user1.userN << " " << search.listUser[i].userN << endl;
		if(user1.userN==search.listUser[i].userN)
			return search.listUser[i];
	}
	user1.userN="-1";
	return user1;
	/*fstream master;
	master.open("userList.dat");
	cout << "search words" << endl;
	if(master.good())
	{
		string user,pass,priv;
		while(master>>user)  //3. validates username and password
		{
			master>>pass;
			master>>priv;
			if(user1.userN==user && user1.userP==pass)
			{			
				user1.userN=user;
				user1.userP=pass;
				user1.priv=atoi(priv.c_str());
				return true;
			}
		}			
	}
	else
	{
		cout << "userList.dat error " << endl;
	}
	return false;*/
}
bool dbSetup()
{
	listClass setup;
	fstream master;
	master.open("listUser.dat");
	if(!master.good())
	{
		char choice;
		cout << "No user list detected, create admin user, y/n? : ";		//White box testing invalid chars
		cin >> choice;
		if(choice=='y')
		{

			string userN, userP;
			cout <<"Please enter a username: ";
			cin >>userN;
			cout << "Please enter a password: ";
			cin >>userP;
			userData admin;
			admin.userN=userN;
			admin.userP=userP;
			admin.priv=0;
			setup.listUser.push_back(admin);
		}
		else
		{
			cout << "Cannot continue without an admin user, exiting..." << endl;
			master.close();
			return false;
		}
		master.close();
	}
	return true;
}
void dbRead()
{
	
}
#endif

