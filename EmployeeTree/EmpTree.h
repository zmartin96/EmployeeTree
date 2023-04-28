#pragma once
#include <string>
#include <iostream>
using namespace std;


class EmpTree
{
private:
	int empID;
	string empName;
public:
	EmpTree(int ID=-1, string name = "")
	{
		setEmpID(ID);
		setEmpName(name);
	}
	int getEmpID() { return empID; }
	string getEmpName() { return empName; }
	void setEmpName(string name) { empName = name; }
	void setEmpID(int ID) { empID = ID; }
	bool operator<(EmpTree &compare)
	{
		if (this->empID < compare.empID) return 1;
		else return 0;
	}
	bool operator>(EmpTree& compare)
	{
		if (this->empID > compare.empID) return 1;
		else return 0;
	}
	bool operator==(EmpTree b)
	{
		return this->empID==b.empID;
	}
	friend ostream &operator<<(ostream &out, EmpTree a)
	{
		out<<"Employee name: "<<a.getEmpName()<<
		"\tEmployee ID: "<<a.getEmpID()<<endl;
		return out;
	}
	friend istream &operator>>(istream &in, EmpTree &a)
	{
		string name;
		int id;
		cout<<"Enter employee name: ";
		in>>name;
		cout<<"Enter employee ID: ";
		in>>id;
		a.setEmpID(id);
		a.setEmpName(name);
		return in;
	}
};
