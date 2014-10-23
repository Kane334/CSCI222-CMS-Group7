#ifndef USER
#define USER

#include<vector>
#include<cstdlib>
#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;


class userData {
	public:
	string  userN;
	string userP;
	int priv;
	vector<string> expertise;
	userData& operator=(const userData &insert)
	{
		userN=insert.userN;
		userP=insert.userP;
		priv=insert.priv;
		expertise.assign(insert.expertise.begin(),insert.expertise.end());
		return *this;
	}
	friend istream& operator>> (istream &master, userData &insert)
	{
		string temp;
		master>>temp;	
		insert.userN=temp;
		master>>temp;
		insert.userP=temp;
		master>>temp;
		insert.priv=atoi(temp.c_str());
		master>>temp;
		while(temp!="-1")
		{
			insert.expertise.push_back(temp);
			master>>temp;						
		}
		return master;
	}
	friend ostream& operator<< (ostream &master, userData &insert)
	{
		master<<insert.userN<< " ";
		master<<insert.userP << " ";
		master<<insert.priv << " ";
		for(int i=0; i<(signed)insert.expertise.size(); i++)
		{
			master<<insert.expertise[i]<< " ";
		}
		master << "-1";
		return master;
	}
};


class PC : public userData
{	
	public:	
	PC& operator=(const userData &insert)
	{
		userN=insert.userN;
		userP=insert.userP;
		priv=insert.priv;
		return *this;
	}
	friend istream& operator>> (istream &master, PC &insert)
	{
		cout << "PC INSERTION" << endl;
		master>>static_cast<userData &>(insert);
		
		string temp;
		master>>temp;		
		insert.PCID=atoi(temp.c_str());
		master >> temp;
		int tmp;
		master >> tmp;
		while(tmp!=-1)
		{
			insert.reviewPapers.push_back(tmp);
			master >> tmp;
		}	
		return master;
	}
	friend ostream& operator<< (ostream &master, PC &insert)
	{
		master<<static_cast<userData &>(insert);
		master<<" "<<insert.PCID<<" ";
		for(int i=0; i<(signed)insert.reviewPapers.size(); i++)
		{
			master<<insert.reviewPapers[i]<< " ";
		}
		master << "-1";
		return master;
	}
	int PCID;
	vector<int> reviewPapers;
};
class Author : public userData 
{
	public:
	Author& operator=(const userData &insert)
	{
		userN=insert.userN;
		userP=insert.userP;
		priv=insert.priv;
		return *this;
	}
	friend istream& operator>> (istream &master, Author &insert2)
	{
		master>>static_cast<userData &>(insert2);
		cout << "AUTHOR INSERTION" << endl;
		int tmp;
		master >> tmp;
		while(tmp!=-1)
		{
			insert2.submissions.push_back(tmp);
			master >> tmp;
		}
		return master;
	}
	friend ostream& operator<< (ostream &master, Author &insert)
	{
		master<<static_cast<userData &>(insert);
		cout << " ";
		for(int i=0; i<(signed)insert.submissions.size(); i++)
		{
			master<<insert.submissions[i]<< " ";
		}
		master << "-1" << " ";
		return master;
	}
	vector <int>submissions;
};




class Paper {
	public:
	friend istream& operator>> (istream &in, Paper &pap)
	{
		cout << "PAPER INSERTION" << endl;
		in>>pap.paperID;
		in>>pap.author;
		in>>pap.university;
		in>>pap.email;
		string temp;
		in>>temp;
		while(temp!="-1")
		{
			pap.keywords.push_back(temp);
			in>>temp;				
		}
		in>>pap.numberOfReviewers;
		int tmp;
		in >> tmp;
		while(tmp!=-1)
		{
			pap.reviewers.push_back(tmp);
			in >> tmp;
		}
		return in;
	}
	friend ostream& operator<< (ostream &master, Paper &insert)
	{
		master<<insert.paperID<< " ";
		master<<insert.author<< " ";
		master<<insert.university<< " ";
		master<<insert.email<< " ";
		for(int i=0; i<(signed)insert.keywords.size(); i++)
		{
			master<<insert.keywords[i]<< " ";
		}
		master << "-1" << " ";
		master<<insert.numberOfReviewers<< " ";
		for(int i=0; i<(signed)insert.reviewers.size(); i++)
		{
			master<<insert.reviewers[i]<< " ";
		}
		master << "-1" << " ";
		return master;
	}
	int paperID;
	string author;
	string university;
	string email;
	vector<string> keywords;
	int numberOfReviewers;
	vector<int>reviewers;
};


class listClass {
	public:
	~listClass() 
	{
		cout << "LIST CLASS DESTRUCTOR" << endl;
		ofstream out;
		if(listUser.size()!=0)
		{
			out.open("listUser.dat");
			if(out.good())
			{
				out << listUser.size() << endl;
				for(int i=0; i<(signed)listUser.size(); i++)
				{
					out<<listUser[i] << endl;
				}	
			}
			out.close();
		}
		if(listPC.size()!=0)
		{
			out.open("listPC.dat");
			if(out.good() )
			{
				out << listPC.size() << endl;
				for(int i=0; i<(signed)listPC.size(); i++)
				{
					out<<listPC[i]<< endl;
				}	
			}
			out.close();
		}
		
		if(listAuthor.size()!=0)
		{
			out.open("listAuthor.dat");
			if(out.good())
			{
				out << listAuthor.size() << endl;
				for(int i=0; i<(signed)listAuthor.size(); i++)
				{
					out<<listAuthor[i]<< endl;
				}	
			}
			out.close();
		}
		
		if(listPaper.size()!=0)
		{
			out.open("listPaper.dat");
			if(out.good())
			{
				out << listAuthor.size() << endl;
				for(int i=0; i<(signed)listPaper.size(); i++)
				{
					out<<listPaper[i]<< endl;
				}			
			}
			out.close();
		}
	}
	listClass()
	{
		cout << "LIST CLASS CONSTRUCTOR" << endl;
		fstream master;
		master.open("listUser.dat");
		if(master.good())
		{
			userData temp;
			master>>userSize;
			for(int i=0; i<userSize;i++)
			{
				master>>temp;
				listUser.push_back(temp);
			}
		}
		master.close();
		master.open("listPC.dat");
		if(master.good())
		{
			
			PC insert;
			master>>PCSize;
			for(int i=0; i<PCSize;i++)
			{	
				master>>insert;
				listPC.push_back(insert);
			}
		}
		master.close();
		master.open("listAuthor.dat");
		if(master.good())
		{
			Author insert2;
			master>>AuthorSize;
			for(int i=0; i<AuthorSize;i++)
			{	
				master>>insert2;
				listAuthor.push_back(insert2);
			}
		}
		master.close();
		master.open("listPaper.dat");
		if(master.good())
		{
			Paper insert3;
			master>>PaperSize;
			for(int i=0; i<PaperSize;i++)
			{
				master>>insert3;
				listPaper.push_back(insert3);
			}
		}
		master.close();
	}
	int userSize, PCSize, AuthorSize, PaperSize;
	vector<PC> listPC;
	vector<Author> listAuthor;
	vector<Paper> listPaper;
	vector<userData>listUser;
};
#endif

