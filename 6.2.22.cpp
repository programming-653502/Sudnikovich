// ConsoleApplication14.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

class Offers
{
public:
	string district, fio;
	int floor, area, countOfRooms, price;

	Offers(string District, int Floor, int Area, int CountOfRooms, int Price, string Fio)
	{
		this->district = District;
		this->floor = Floor;
		this->area = Area;
		this->countOfRooms = CountOfRooms;
		this->price = Price;
		this->fio = Fio;
	}
};

class Demands
{
public:
	string district, fio;
	int floor, area, countOfRooms, price;

	Demands(string District, int Floor, int Area, int CountOfRooms, int Price, string Fio)
	{
		this->district = District;
		this->floor = Floor;
		this->area = Area;
		this->countOfRooms = CountOfRooms;
		this->price = Price;
		this->fio = Fio;
	}
};

class Owner
{
public:
	string surname, name, middleName;

	Owner(string Surname, string Name, string MiddleName)
	{
		this->surname = Surname;
		this->name = Name;
		this->middleName = MiddleName;
	}
};

class Buyer
{
public:
	string surname, name, middleName;

	Buyer(string Surname, string Name, string MiddleName)
	{
		this->surname = Surname;
		this->name = Name;
		this->middleName = MiddleName;
	}
};

static int menu()
{
	int choice;
	system("cls");
	cout << "\t\t����������� �������� 1.0\n";
	cout << "\n\t\t����:";
	cout << "\n1)  �������� �����������;";
	cout << "\n2)  �������� �����;";
	cout << "\n3)  ���������������� ���������;";
	cout << "\n4)  ���������������� ���������;";
	cout << "\n5)  ����� ������� ������ ��� ���������;";
	cout << "\n6)  ����� ������� ������ ��� ���������;";
	cout << "\n7)  ����� �� ����;";
	cout << "\n8)  ��������;";
	cout << "\n9)  �����;";
	cout << "\n10) �����;";
	cout << "\n\nYour choice : ";
	cin >> choice;
	return choice;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	int price1 = 10000;
	vector<Offers> vector_offers;
	vector<Demands> vector_demand;
	vector<Owner> vector_owner;
	vector<Buyer> vector_buyer;
	while (true)
	{
		choice = menu();
		if (choice == 1)
		{
			string surname, name, middleName;
			string owner;
			bool find = false;
			system("cls");
			cout << "���������� ������ �����������";
			cout << "\n��� �� ���������� ���������� ������ �����������?";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			owner += surname;
			owner += " ";
			owner += name;
			owner += " ";
			owner += middleName;
			for (int i = 0; i < vector_owner.size(); i++)
			{
				if (vector_owner[i].surname == surname)
				{
					if (vector_owner[i].name == name)
					{
						if (vector_owner[i].middleName == middleName)
						{
							find = true;
						}
					}
				}
			}
			if (find == true)
			{
				string district;
				int floor, area, countOfRooms, price;
				system("cls");
				cout << "���������� �����������";
				cout << "\n����� - ";
				cin >> district;
				cout << "���� - ";
				cin >> floor;
				cout << "������� �������� - ";
				cin >> area;
				cout << "���������� ������ - ";
				cin >> countOfRooms;
				cout << "���� - ";
				cin >> price;
				Offers offer(district, floor, area, countOfRooms, price, owner);
				vector_offers.push_back(offer);
				cout << "����������� ������� ���������.";
				cout << "\n�������� - " << owner;
				cout << '\n';
			}
			else
			{
				cout << "�������� � ������ ������� �� ������.";
			}
		}
		else if (choice == 2)
		{
			string surname, name, middleName;
			string buyer;
			bool find = false;
			system("cls");
			cout << "���������� ������ ������";
			cout << "\n��� �� ����������� ��������� ���� �����?";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			buyer += surname;
			buyer += " ";
			buyer += name;
			buyer += " ";
			buyer += middleName;
			for (int i = 0; i < vector_buyer.size(); i++)
			{
				if (vector_buyer[i].surname == surname)
				{
					if (vector_buyer[i].name == name)
					{
						if (vector_buyer[i].middleName == middleName)
						{
							find = true;
						}
					}
				}
			}
			if (find == true)
			{
				string district;
				int floor, area, countOfRooms, price;
				system("cls");
				cout << "���������� ������";
				cout << "\n����� - ";
				cin >> district;
				cout << "���� - ";
				cin >> floor;
				cout << "������� �������� - ";
				cin >> area;
				cout << "���������� ������ - ";
				cin >> countOfRooms;
				cout << "���� (��) - ";
				cin >> price;
				Demands demand(district, floor, area, countOfRooms, price, buyer);
				vector_demand.push_back(demand);
				cout << "����� ������� ��������.";
				cout << "\n���������� - " << buyer;
				cout << "\n";
			}
			else
			{
				cout << "���������� � ������ ������� �� ������.";
			}
		}
		else if (choice == 3)
		{
			string surname, name, middleName;
			bool checked = false;
			system("cls");
			cout << "���������� ������ ���������.";
			cout << "\n������� ��� ������";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			for (int i = 0; i < vector_owner.size(); i++)
			{
				if (vector_owner[i].surname == surname)
				{
					if (vector_owner[i].name == name)
					{
						if (vector_owner[i].middleName == middleName)
						{
							cout << "\n�������� � ������ ������� ��� ���� � ����.";
							checked = true;
							break;
						}
					}
				}
			}
			if (!checked)
			{
				Owner fio(surname,name,middleName);
				vector_owner.push_back(fio);
				cout << "\n�������� " << surname << " " << name << " " <<  middleName << " ������� ��������.\n";
			}
		}
		else if (choice == 4)
		{
			string surname, name, middleName;
			bool checked = false;
			system("cls");
			cout << "���������� ������ ����������.";
			cout << "\n������� ��� ������";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			for (int i = 0; i < vector_buyer.size(); i++)
			{
				if (vector_buyer[i].surname == surname)
				{
					if (vector_buyer[i].name == name)
					{
						if (vector_buyer[i].middleName == middleName)
						{
							cout << "\n�������� � ������ ������� ��� ���� � ����.";
							checked = true;
							break;
						}
					}
				}
			}
			if (!checked)
			{
				Buyer fio(surname, name, middleName);
				vector_buyer.push_back(fio);
				cout << "\n�������� " << surname << " " << name << " " << middleName << " ������� ��������.\n";
			}
		}
		else if (choice == 5)
		{
			int counter = 1, wanna = 5, play;
			bool find = false;
			string surname, name, middleName, owner;
			system("cls");
			cout << "����� ���������� ������ ��� ���������.";
			cout << "\n������� ������ ���������.";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			owner += surname;
			owner += " ";
			owner += name;
			owner += " ";
			owner += middleName;
			cout << "��� ������ ����������� �� ������ ����� ����������?\n";
			for (int i = 0; i < vector_offers.size(); i++)
			{
				if (vector_offers[i].fio == owner)
				{
					find = true;
					cout << counter << ")";
					cout << "\n����� - " << vector_offers[i].district;
					cout << "\n���� - " << vector_offers[i].floor;
					cout << "\n������� - " << vector_offers[i].area;
					cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
					cout << "\n���� - " << vector_offers[i].price;
					cout << "\n";
					cout << "\n������ �� �� ����� ���������� ��� ������� �����������? �� - 1, ��� - 0\n";
					cin >> wanna;
					if (wanna == 1)
					{
						int variant = 1;
						system("cls");
						cout << "����� ����������";
						for (int j = 0; j < vector_demand.size(); j++)
						{
							if (vector_demand[j].district == vector_offers[i].district)
							{
								if (vector_demand[j].floor == vector_offers[i].floor)
								{
									if (vector_demand[j].area == vector_offers[i].area)
									{
										if (vector_demand[j].countOfRooms == vector_offers[i].countOfRooms)
										{
											if (vector_demand[j].price >= vector_offers[i].price)
											{
												cout << "\n������� ����� - " << variant << ".\n";
												cout << "\n�� ����� ����������. ��� ��� ��� �����";
												cout << "\n����� - " << vector_demand[j].district;
												cout << "\n���� - " << vector_demand[j].floor;
												cout << "\n������� - " << vector_demand[j].area;
												cout << "\n���������� ������ - " << vector_demand[j].countOfRooms;
												cout << "\n���� ������� (��) - " << vector_demand[j].price;
												cout << "\n�������� - " << vector_demand[j].fio;
												cout << "\n������� 1, ����� ����������.\n";
												cin >> play;
												variant++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (find = false)
			{
				cout << "�� ������ ����������� �� ������� ��������� �� �������.";
			}
		}
		else if (choice == 6)
		{
			int counter = 1, wanna = 5, play;
			bool find = false;
			string surname, name, middleName, buyer;
			system("cls");
			cout << "����� ���������� ������ ��� ����������.";
			cout << "\n������� ������ ����������.";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			buyer += surname;
			buyer += " ";
			buyer += name;
			buyer += " ";
			buyer += middleName;
			cout << "��� ������ ������ �� ������ ����� ������?\n";
			for (int i = 0; i < vector_demand.size(); i++)
			{
				if (vector_demand[i].fio == buyer)
				{
					find = true;
					cout << counter << ")";
					cout << "\n����� - " << vector_demand[i].district;
					cout << "\n���� - " << vector_demand[i].floor;
					cout << "\n������� - " << vector_demand[i].area;
					cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
					cout << "\n���� - " << vector_demand[i].price;
					cout << "\n";
					cout << "\n������ �� �� ����� ������ ��� ������� ������? �� - 1, ��� - 0\n";
					cin >> wanna;
					if (wanna == 1)
					{
						int variant = 1;
						system("cls");
						cout << "����� ������";
						for (int j = 0; j < vector_demand.size(); j++)
						{
							if (vector_offers[j].district == vector_demand[i].district)
							{
								if (vector_offers[j].floor == vector_demand[i].floor)
								{
									if (vector_offers[j].area == vector_demand[i].area)
									{
										if (vector_offers[j].countOfRooms == vector_demand[i].countOfRooms)
										{
											if (vector_offers[j].price <= vector_demand[i].price)
											{
												cout << "\n������� ����� - " << variant << ".\n";
												cout << "\n�� ����� ������. ��� ��� ���������� ��������";
												cout << "\n����� - " << vector_offers[j].district;
												cout << "\n���� - " << vector_offers[j].floor;
												cout << "\n������� - " << vector_offers[j].area;
												cout << "\n���������� ������ - " << vector_offers[j].countOfRooms;
												cout << "\n���� ������� - " << vector_offers[j].price;
												cout << "\n�������� - " << vector_offers[j].fio;
												cout << "\n������� 1, ����� ����������.\n";
												cin >> play;
												variant++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			if (find = false)
			{
				cout << "�� ������ ������ �� ����� ������������ �� �������.";
			}
		}
		else if (choice == 7)
		{
			system("cls");
			int offersOrDemand, field, value;
			string value1;
			cout << "����� ��: \n1) ������������ \n2) �������\n";
			cin >> offersOrDemand;
			if (offersOrDemand == 1)
			{
				cout << "�� ������ ���� ����?";
				cout << "\n1) �����;";
				cout << "\n2) ����;";
				cout << "\n3) �������;";
				cout << "\n4) ���������� ������;";
				cout << "\n5) ����;";
				cout << "\n6) ��������;\n";
				cin >> field;
				if (field == 1)
				{
					cout << "\n����� - ";
					cin >> value1;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].district == value1)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_offers[i].district;
							cout << "\n���� - " << vector_offers[i].floor;
							cout << "\n������� - " << vector_offers[i].area;
							cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 2)
				{
					cout << "\n���� - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].floor == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_offers[i].district;
							cout << "\n���� - " << vector_offers[i].floor;
							cout << "\n������� - " << vector_offers[i].area;
							cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 3)
				{
					cout << "\n������� - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].area == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_offers[i].district;
							cout << "\n���� - " << vector_offers[i].floor;
							cout << "\n������� - " << vector_offers[i].area;
							cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 4)
				{
					cout << "\n���������� ������ - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].countOfRooms == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_offers[i].district;
							cout << "\n���� - " << vector_offers[i].floor;
							cout << "\n������� - " << vector_offers[i].area;
							cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 5)
				{
					cout << "\n���� ������� - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].price == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_offers[i].district;
							cout << "\n���� - " << vector_offers[i].floor;
							cout << "\n������� - " << vector_offers[i].area;
							cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_offers[i].price;
						}
					}
				}
			}
			else if (offersOrDemand == 2)
			{
				cout << "�� ������ ���� ����?";
				cout << "\n1)�����;";
				cout << "\n2) ����;";
				cout << "\n3) �������;";
				cout << "\n4) ���������� ������;";
				cout << "\n5) ����;";
				cout << "\n6) ��������;";
				cin >> field;
				if (field == 1)
				{
					cout << "\n����� - ";
					cin >> value1;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].district == value1)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_demand[i].district;
							cout << "\n���� - " << vector_demand[i].floor;
							cout << "\n������� - " << vector_demand[i].area;
							cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 2)
				{
					cout << "\n���� - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].floor == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_demand[i].district;
							cout << "\n���� - " << vector_demand[i].floor;
							cout << "\n������� - " << vector_demand[i].area;
							cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 3)
				{
					cout << "\n������� - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].area == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_demand[i].district;
							cout << "\n���� - " << vector_demand[i].floor;
							cout << "\n������� - " << vector_demand[i].area;
							cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 4)
				{
					cout << "\n���������� ������ - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].countOfRooms == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_demand[i].district;
							cout << "\n���� - " << vector_demand[i].floor;
							cout << "\n������� - " << vector_demand[i].area;
							cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 5)
				{
					cout << "\n���� ������� - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].price == value)
						{
							cout << "\n������� ����������!";
							cout << "\n����� - " << vector_demand[i].district;
							cout << "\n���� - " << vector_demand[i].floor;
							cout << "\n������� - " << vector_demand[i].area;
							cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
							cout << "\n���� ������� (��) - " << vector_demand[i].price;
						}
					}
				}
			}
			cout << "\n������� 1 ��� ����������� ������.\n";
			cin >> value1;	
		}
		else if (choice == 8)
		{
			string surname, name, middleName, fio;
			int type;
			cout << "��� �� ������� �������?\n1) ����������� \n2) �����\n";
			cin >> type;
			cout << "������� ������ ��������, ������������ ����������.";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			fio += surname;
			fio += " ";
			fio += name;
			fio += " ";
			fio += middleName;
			int yesNo = 5;
			if (type == 1)
			{
				for (int i = 0; i < vector_offers.size(); i++)
				{
					if (vector_offers[i].fio == fio)
					{
						cout << "\n����� - " << vector_offers[i].district;
						cout << "\n���� - " << vector_offers[i].floor;
						cout << "\n������� - " << vector_offers[i].area;
						cout << "\n���������� ������ - " << vector_offers[i].countOfRooms;
						cout << "\n���� ������� - " << vector_offers[i].price;
						cout << "\n\n�� ����� ������ ������� ������ ����������? �� - 1, ��� - 0\n";
						cin >> yesNo;
						if (yesNo == 1)
						{
							vector_offers.erase(vector_offers.begin()+i);
						}
					}
				}
			}
			else if (type == 2)
			{
				for (int i = 0; i < vector_demand.size(); i++)
				{
					if (vector_offers[i].fio == fio)
					{
						cout << "\n����� - " << vector_demand[i].district;
						cout << "\n���� - " << vector_demand[i].floor;
						cout << "\n������� - " << vector_demand[i].area;
						cout << "\n���������� ������ - " << vector_demand[i].countOfRooms;
						cout << "\n���� ������� - " << vector_demand[i].price;
						cout << "\n\n�� ����� ������ ������� ������ ����������? �� - 1, ��� - 0\n";
						cin >> yesNo;
						if (yesNo == 1)
						{
							vector_demand.erase(vector_demand.begin()+i);
						}
					}
				}
			}
		}
		else if (choice == 9)
		{
			system("cls");
			string surname, name, middleName, fio1, fio2;
			cout << "�����";
			cout << "\n����� ������ ��� ������";
			cout << "\n������ ������ ������ ��� ������ ������ � ���������";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			fio1 += surname;
			fio1 += " ";
			fio1 += name;
			fio1 += " ";
			fio1 += middleName;
			cout << "\n������ ������ ������ ��� ������ ������ � ���������";
			cout << "\n������� - ";
			cin >> surname;
			cout << "��� - ";
			cin >> name;
			cout << "�������� - ";
			cin >> middleName;
			fio2 += surname;
			fio2 += " ";
			fio2 += name;
			fio2 += " ";
			fio2 += middleName;
			for (int i = 0; i < vector_offers.size(); i++)
			{
				if (vector_offers[i].fio == fio1)
				{
					for (int j = 0; j < vector_offers.size(); j++)
					{
						if (vector_offers[j].fio == fio2)
						{
							string kek;
							kek = vector_offers[i].fio;
							vector_offers[i].fio = vector_offers[j].fio;
							vector_offers[j].fio = kek;
							cout << "����� ��������.";
							cout << "������� 1, ����� ����������.";
							cin >> kek;
						}
					}
				}
			}
		}
		else if (choice == 10)
		{
			cout << "���������� ���������...";
			return 0;
		}
	}
}