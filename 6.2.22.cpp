// ConsoleApplication14.cpp: определяет точку входа для консольного приложения.
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
	cout << "\t\tРиэлторская компания 1.0\n";
	cout << "\n\t\tМЕНЮ:";
	cout << "\n1)  Добавить предложение;";
	cout << "\n2)  Добавить заказ;";
	cout << "\n3)  Зарегистрировать владельца;";
	cout << "\n4)  Зарегестрировать заказчика;";
	cout << "\n5)  Найти вариант сделки для владельца;";
	cout << "\n6)  Найти вариант сделки для заказчика;";
	cout << "\n7)  Поиск по полю;";
	cout << "\n8)  Удаление;";
	cout << "\n9)  Обмен;";
	cout << "\n10) Выход;";
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
			cout << "Добавление нового предложения";
			cout << "\nКто из владельцев выставляет данной предложение?";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
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
				cout << "Добавление предложения";
				cout << "\nРайон - ";
				cin >> district;
				cout << "Этаж - ";
				cin >> floor;
				cout << "Площадь квартиры - ";
				cin >> area;
				cout << "Количество комнат - ";
				cin >> countOfRooms;
				cout << "Цена - ";
				cin >> price;
				Offers offer(district, floor, area, countOfRooms, price, owner);
				vector_offers.push_back(offer);
				cout << "Предложение успешно добавлено.";
				cout << "\nВладелец - " << owner;
				cout << '\n';
			}
			else
			{
				cout << "Владелец с такими данными не найден.";
			}
		}
		else if (choice == 2)
		{
			string surname, name, middleName;
			string buyer;
			bool find = false;
			system("cls");
			cout << "Добавление нового заказа";
			cout << "\nКто из покупателей добавляет этот заказ?";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
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
				cout << "Добавление заказа";
				cout << "\nРайон - ";
				cin >> district;
				cout << "Этаж - ";
				cin >> floor;
				cout << "Площадь квартиры - ";
				cin >> area;
				cout << "Количество комнат - ";
				cin >> countOfRooms;
				cout << "Цена (до) - ";
				cin >> price;
				Demands demand(district, floor, area, countOfRooms, price, buyer);
				vector_demand.push_back(demand);
				cout << "Заказ успешно добавлен.";
				cout << "\nПокупатель - " << buyer;
				cout << "\n";
			}
			else
			{
				cout << "Покупатель с такими данными не найден.";
			}
		}
		else if (choice == 3)
		{
			string surname, name, middleName;
			bool checked = false;
			system("cls");
			cout << "Добавление нового владельца.";
			cout << "\nВведите его данные";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
			cin >> middleName;
			for (int i = 0; i < vector_owner.size(); i++)
			{
				if (vector_owner[i].surname == surname)
				{
					if (vector_owner[i].name == name)
					{
						if (vector_owner[i].middleName == middleName)
						{
							cout << "\nВладелец с такими данными уже есть в базе.";
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
				cout << "\nВладелец " << surname << " " << name << " " <<  middleName << " успешно добавлен.\n";
			}
		}
		else if (choice == 4)
		{
			string surname, name, middleName;
			bool checked = false;
			system("cls");
			cout << "Добавление нового покупателя.";
			cout << "\nВведите его данные";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
			cin >> middleName;
			for (int i = 0; i < vector_buyer.size(); i++)
			{
				if (vector_buyer[i].surname == surname)
				{
					if (vector_buyer[i].name == name)
					{
						if (vector_buyer[i].middleName == middleName)
						{
							cout << "\nВладелец с такими данными уже есть в базе.";
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
				cout << "\nВладелец " << surname << " " << name << " " << middleName << " успешно добавлен.\n";
			}
		}
		else if (choice == 5)
		{
			int counter = 1, wanna = 5, play;
			bool find = false;
			string surname, name, middleName, owner;
			system("cls");
			cout << "Поиск подходящей сделки для владельца.";
			cout << "\nВведите данные владельца.";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
			cin >> middleName;
			owner += surname;
			owner += " ";
			owner += name;
			owner += " ";
			owner += middleName;
			cout << "Для какого предложения вы хотите найти покупателя?\n";
			for (int i = 0; i < vector_offers.size(); i++)
			{
				if (vector_offers[i].fio == owner)
				{
					find = true;
					cout << counter << ")";
					cout << "\nРайон - " << vector_offers[i].district;
					cout << "\nЭтаж - " << vector_offers[i].floor;
					cout << "\nПлощадь - " << vector_offers[i].area;
					cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
					cout << "\nЦена - " << vector_offers[i].price;
					cout << "\n";
					cout << "\nХотите ли вы найти покупателя для данного предложения? Да - 1, Нет - 0\n";
					cin >> wanna;
					if (wanna == 1)
					{
						int variant = 1;
						system("cls");
						cout << "Поиск покупателя";
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
												cout << "\nВариант номер - " << variant << ".\n";
												cout << "\nМы нашли покупателя. Вот что ему нужно";
												cout << "\nРайон - " << vector_demand[j].district;
												cout << "\nЭтаж - " << vector_demand[j].floor;
												cout << "\nПлощадь - " << vector_demand[j].area;
												cout << "\nКоличество комнат - " << vector_demand[j].countOfRooms;
												cout << "\nЦена покупки (до) - " << vector_demand[j].price;
												cout << "\nВладелец - " << vector_demand[j].fio;
												cout << "\nВведите 1, чтобы продолжить.\n";
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
				cout << "Ни одного предложения от данного владельца не найдено.";
			}
		}
		else if (choice == 6)
		{
			int counter = 1, wanna = 5, play;
			bool find = false;
			string surname, name, middleName, buyer;
			system("cls");
			cout << "Поиск подходящей сделки для покупателя.";
			cout << "\nВведите данные покупателя.";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
			cin >> middleName;
			buyer += surname;
			buyer += " ";
			buyer += name;
			buyer += " ";
			buyer += middleName;
			cout << "Для какого заказа вы хотите найти сделку?\n";
			for (int i = 0; i < vector_demand.size(); i++)
			{
				if (vector_demand[i].fio == buyer)
				{
					find = true;
					cout << counter << ")";
					cout << "\nРайон - " << vector_demand[i].district;
					cout << "\nЭтаж - " << vector_demand[i].floor;
					cout << "\nПлощадь - " << vector_demand[i].area;
					cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
					cout << "\nЦена - " << vector_demand[i].price;
					cout << "\n";
					cout << "\nХотите ли вы найти сделку для данного заказа? Да - 1, Нет - 0\n";
					cin >> wanna;
					if (wanna == 1)
					{
						int variant = 1;
						system("cls");
						cout << "Поиск сделки";
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
												cout << "\nВариант номер - " << variant << ".\n";
												cout << "\nМы нашли сделку. Вот что предлагает владелец";
												cout << "\nРайон - " << vector_offers[j].district;
												cout << "\nЭтаж - " << vector_offers[j].floor;
												cout << "\nПлощадь - " << vector_offers[j].area;
												cout << "\nКоличество комнат - " << vector_offers[j].countOfRooms;
												cout << "\nЦена покупки - " << vector_offers[j].price;
												cout << "\nВладелец - " << vector_offers[j].fio;
												cout << "\nВведите 1, чтобы продолжить.\n";
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
				cout << "Ни одного заказа от этого пользователя не найдено.";
			}
		}
		else if (choice == 7)
		{
			system("cls");
			int offersOrDemand, field, value;
			string value1;
			cout << "Поиск по: \n1) Предложениям \n2) Заказам\n";
			cin >> offersOrDemand;
			if (offersOrDemand == 1)
			{
				cout << "По какому полю ищем?";
				cout << "\n1) Район;";
				cout << "\n2) Этаж;";
				cout << "\n3) Площадь;";
				cout << "\n4) Количество комнат;";
				cout << "\n5) Цена;";
				cout << "\n6) Владелец;\n";
				cin >> field;
				if (field == 1)
				{
					cout << "\nРайон - ";
					cin >> value1;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].district == value1)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_offers[i].district;
							cout << "\nЭтаж - " << vector_offers[i].floor;
							cout << "\nПлощадь - " << vector_offers[i].area;
							cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 2)
				{
					cout << "\nЭтаж - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].floor == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_offers[i].district;
							cout << "\nЭтаж - " << vector_offers[i].floor;
							cout << "\nПлощадь - " << vector_offers[i].area;
							cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 3)
				{
					cout << "\nПлощадь - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].area == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_offers[i].district;
							cout << "\nЭтаж - " << vector_offers[i].floor;
							cout << "\nПлощадь - " << vector_offers[i].area;
							cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 4)
				{
					cout << "\nКоличество комнат - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].countOfRooms == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_offers[i].district;
							cout << "\nЭтаж - " << vector_offers[i].floor;
							cout << "\nПлощадь - " << vector_offers[i].area;
							cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_offers[i].price;
						}
					}
				}
				if (field == 5)
				{
					cout << "\nЦена покупки - ";
					cin >> value;
					for (int i = 0; i < vector_offers.size(); i++)
					{
						if (vector_offers[i].price == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_offers[i].district;
							cout << "\nЭтаж - " << vector_offers[i].floor;
							cout << "\nПлощадь - " << vector_offers[i].area;
							cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_offers[i].price;
						}
					}
				}
			}
			else if (offersOrDemand == 2)
			{
				cout << "По какому полю ищем?";
				cout << "\n1)Район;";
				cout << "\n2) Этаж;";
				cout << "\n3) Площадь;";
				cout << "\n4) Количество комнат;";
				cout << "\n5) Цена;";
				cout << "\n6) Владелец;";
				cin >> field;
				if (field == 1)
				{
					cout << "\nРайон - ";
					cin >> value1;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].district == value1)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_demand[i].district;
							cout << "\nЭтаж - " << vector_demand[i].floor;
							cout << "\nПлощадь - " << vector_demand[i].area;
							cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 2)
				{
					cout << "\nЭтаж - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].floor == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_demand[i].district;
							cout << "\nЭтаж - " << vector_demand[i].floor;
							cout << "\nПлощадь - " << vector_demand[i].area;
							cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 3)
				{
					cout << "\nПлощадь - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].area == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_demand[i].district;
							cout << "\nЭтаж - " << vector_demand[i].floor;
							cout << "\nПлощадь - " << vector_demand[i].area;
							cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 4)
				{
					cout << "\nКоличество комнат - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].countOfRooms == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_demand[i].district;
							cout << "\nЭтаж - " << vector_demand[i].floor;
							cout << "\nПлощадь - " << vector_demand[i].area;
							cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_demand[i].price;
						}
					}
				}
				if (field == 5)
				{
					cout << "\nЦена покупки - ";
					cin >> value;
					for (int i = 0; i < vector_demand.size(); i++)
					{
						if (vector_demand[i].price == value)
						{
							cout << "\nНайдено совпадение!";
							cout << "\nРайон - " << vector_demand[i].district;
							cout << "\nЭтаж - " << vector_demand[i].floor;
							cout << "\nПлощадь - " << vector_demand[i].area;
							cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
							cout << "\nЦена покупки (до) - " << vector_demand[i].price;
						}
					}
				}
			}
			cout << "\nВведите 1 для продолжения работы.\n";
			cin >> value1;	
		}
		else if (choice == 8)
		{
			string surname, name, middleName, fio;
			int type;
			cout << "Что вы желаете удалить?\n1) Предложение \n2) Заказ\n";
			cin >> type;
			cout << "Введите данные человека, выставившего объявление.";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
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
						cout << "\nРайон - " << vector_offers[i].district;
						cout << "\nЭтаж - " << vector_offers[i].floor;
						cout << "\nПлощадь - " << vector_offers[i].area;
						cout << "\nКоличество комнат - " << vector_offers[i].countOfRooms;
						cout << "\nЦена продажи - " << vector_offers[i].price;
						cout << "\n\nВы точно хотите удалить данное объявление? Да - 1, Нет - 0\n";
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
						cout << "\nРайон - " << vector_demand[i].district;
						cout << "\nЭтаж - " << vector_demand[i].floor;
						cout << "\nПлощадь - " << vector_demand[i].area;
						cout << "\nКоличество комнат - " << vector_demand[i].countOfRooms;
						cout << "\nЦена продажи - " << vector_demand[i].price;
						cout << "\n\nВы точно хотите удалить данное объявление? Да - 1, Нет - 0\n";
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
			cout << "Обмен";
			cout << "\nНайдём сделки для обмена";
			cout << "\nНайдем первую сделку при помощи данных о владельце";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
			cin >> middleName;
			fio1 += surname;
			fio1 += " ";
			fio1 += name;
			fio1 += " ";
			fio1 += middleName;
			cout << "\nНайдем вторую сделку при помощи данных о владельце";
			cout << "\nФамилия - ";
			cin >> surname;
			cout << "Имя - ";
			cin >> name;
			cout << "Отчество - ";
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
							cout << "Обмен завершен.";
							cout << "Введите 1, чтобы продолжить.";
							cin >> kek;
						}
					}
				}
			}
		}
		else if (choice == 10)
		{
			cout << "Выключение программы...";
			return 0;
		}
	}
}
