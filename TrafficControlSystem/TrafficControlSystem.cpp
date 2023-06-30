#include <iostream>
#include<string>
using namespace std;

struct  Date
{
	int day;
	int month;
	int year;
};

struct Cars
{
	int fine_count;
	string Plate_Number;
	int Production_Year;
	string model;

}car[100000];

struct Fines
{
	string plate_number;
	int fines_id;
	float fine_cost;
	string street_name;
	bool fine_case = false;
	Date registration_date;
}fine[100000];

struct driverInformation
{
	string name;
	Date birthday;
}driver[100000];

string plateNum;
int number;
int arr_fine_size = 0;
int arr_car_size = 0;
char chooseLetter;
bool is_plateNum = false;
int arr_name_size = 0;

int menu();
void inquire_fine(string plateNum);

void pay_the_fines(string plateNum)
{
	float sumTotalCost = 0;
	float netTotalCost = 0;
	int index[100];
	int lastIndex = 1;
	bool pay_fine = false;

	for (int i = 0; i < arr_fine_size; i++)
	{
		if (fine[i].plate_number.compare(plateNum) == 0)
		{

			sumTotalCost += fine[i].fine_cost;
			if (!fine[i].fine_case)
			{
				index[lastIndex] = i;
				cout << "  " << lastIndex << ". ";
				lastIndex++;
				cout << "Street name: ";
				cout << fine[i].street_name << endl;
				cout << " Fine registration date: ";
				cout << fine[i].registration_date.day << "/";
				cout << fine[i].registration_date.month << "/";
				cout << fine[i].registration_date.year << endl;
				cout << " Fine cost: ";
				cout << fine[i].fine_cost << " L.E" << endl;
				netTotalCost += fine[i].fine_cost;
				pay_fine = true;
				cout << " ******************************************************** " << endl;

			}
		}
	}

	if (pay_fine)
	{
		if (lastIndex > 2)
		{
			cout << " " << lastIndex << ". " << "for pay all fines" << endl;
			cout << " *************************************************** " << endl;
			cout << " Total fine cost: " << sumTotalCost << " L.E" << endl;
			cout << " Total Not Pay cost: " << netTotalCost << " L.E" << endl;
			cout << " ******************************************************** " << endl;
		}

		cout << " Enter the number you chose in order to pay the fine: " << endl;
		cout << "  ";
		cin >> number;
		cout << endl;

		if (lastIndex == number) {
			for (int i = 0; i < arr_fine_size; i++)
			{
				if (fine[i].plate_number.compare(plateNum) == 0)
				{
					if (!fine[i].fine_case) {
						fine[i].fine_case = true;
					}
				}
			}
			cout << " ************************************************* " << endl;
			inquire_fine(plateNum);
		}
		else
		{
			fine[index[number]].fine_case = true;
			cout << " *************************************************** " << endl;
			inquire_fine(plateNum);
		}
	}
	else
	{
		cout << " There are no fines " << endl;
		cout << " ************************************************************ " << endl;
		cout << " Do you want to search again or Exit? " << "\n" << endl;
		cout << " Press 'y' for yes or 'n' for No" << endl;
		cin >> chooseLetter;   // The letter the driver enters
		cout << " ************************************************************* " << endl;
		switch (chooseLetter)
		{
		case'y':
		case'Y':
			cout << " Enter the plate number: " << endl;
			cout << "  ";
			cin >> plateNum;
			pay_the_fines(plateNum);
			break;
		case'n':
		case'N':
			menu();
			break;
		default:
			cout << " you enter a wrong letter" << endl;
			cout << " ****************************************** " << endl;
			menu();
			break;
		}
	}
	cout << " ********************************************** " << endl;
	cout << " Total fine cost: " << sumTotalCost << " L.E" << endl;
	cout << " Total Not Pay cost: " << netTotalCost << " L.E" << endl;
}

void fine_registration(string plateNum)
{
	float fine_cost, road_speed, car_speed;

	int counterForFines = 0;
	bool is_plateNum = false;
	for (int i = 0; i < arr_car_size; i++)
	{
		if (car[i].Plate_Number.compare(plateNum) == 0)
		{
			is_plateNum = true;
			counterForFines = i;
			break;
		}
	}
	if (is_plateNum)
	{

		cout << " Enter the speed of the road: " << endl;
		cout << "  ";
		cin >> road_speed;
		cout << " Enter the speed of the car: " << endl;
		cout << "  ";
		cin >> car_speed;
		if (car_speed > road_speed)
		{
			cout << " There is a fine " << endl;
			fine_cost = 2 * (car_speed - road_speed);
			cout << " Worth: " << fine_cost << " L.E" << endl;

			fine[arr_fine_size].fines_id = arr_fine_size + 1;
			fine[arr_fine_size].plate_number = plateNum;
			fine[arr_fine_size].fine_cost = fine_cost;
			cout << " Enter the name of the road: " << endl;
			cout << "  ";
			cin >> fine[arr_fine_size].street_name;
			cout << " Enter the registration date: " << endl;
			cout << " Enter day: ";
			cin >> fine[arr_fine_size].registration_date.day;
			for (int i = 0; i < 2; i++)
			{
				if (fine[arr_fine_size].registration_date.day > 31)
				{
					cout << " You entered the day after 31 and this is an error " << endl;
					cout << " Enter again" << endl;
					cout << " Enter day: ";
					cin >> fine[arr_fine_size].registration_date.day;
				}
			}
			cout << " Enter month: ";
			cin >> fine[arr_fine_size].registration_date.month;
			for (int i = 0; i < 2; i++)
			{
				if (fine[arr_fine_size].registration_date.month > 12)
				{
					cout << " You entered the day after 12 and this is an error " << endl;
					cout << " Enter again" << endl;
					cout << " Enter month: ";
					cin >> fine[arr_fine_size].registration_date.month;
				}
			}
			cout << " Enter year: ";
			cin >> fine[arr_fine_size].registration_date.year;
			cout << endl;
			fine[arr_fine_size].fine_case = false;
			car[counterForFines].fine_count++;
			arr_fine_size++;
			cout << " *********************************************************** " << endl;
			cin.ignore();
			cout << " press enter to main menu " << endl;
			cin.ignore();
			cout << " ************************************************************* " << endl;
			menu();
		}
		else
		{
			cout << " Not found fine" << endl;
			cout << " ************************************************************ " << endl;
			cin.ignore();
			cout << " press enter to main menu " << endl;
			cin.ignore();
			cout << " ************************************************************* " << endl;
			menu();

		}
	}
	else
	{
		cout << " The plate number not found" << endl;
		cout << " ************************************************************ " << endl;
		cin.ignore();
		cout << " Do you want to search again? " << endl;
		cout << " Press 'y' for yes or 'n' for No" << endl;
		cout << "  ";
		cin >> chooseLetter;
		switch (chooseLetter)
		{
		case'y':
		case'Y':
			cout << " Enter plate number:  " << endl;
			cout << "  ";
			cin >> plateNum;
			fine_registration(plateNum);
			break;
		case'n':
		case'N':
			menu();
			break;
		default:
			cout << " you enter a wrong letter" << endl;
			cout << " ******************************** " << endl;
			menu();
			break;

		}
	}

	cout << " ************************************************************* " << endl;
}

void information_cars(int number)
{

	if (number > 3)
	{
		cout << " Cannot register more than 3 cars" << endl;
		cout << " Enter again " << endl;
		cout << " ***************************************************************** " << endl;
		cout << " How many cars do you have?  " << endl;
		cout << "  ";
		cin >> number;
		cin.ignore();

		information_cars(number);
	}
	else
	{
		for (int i = 0; i < number; i++)
		{
			car[i].fine_count = 0;
			cout << " # " << i + 1 << " # " << "\n";
			cout << " Enter the car plate number: " << endl;
			cout << "  ";
			cin >> car[i].Plate_Number;
			cout << "\n";
			cout << " Enter the car model: " << endl;
			cout << "  ";
			cin >> car[i].model;
			cout << "\n";
			cout << " Enter the car production year: " << endl;
			cout << "  ";
			cin >> car[i].Production_Year;
			cout << "\n";
			arr_car_size++;

		}
	}
}

void infotmation_driver()
{

	for (int i = 0; i < 1; i++)
	{
		arr_name_size++;
		cout << " Enter your name: ";
		cin >> driver[i].name;
		cout << "\n";
		cout << " Enter you birthday: " << endl;
		cout << " Enter your day: ";
		cin >> driver[i].birthday.day;
		for (int i = 0; i < 2; i++)
		{
			if (driver[i].birthday.day > 31)
			{
				cout << " You entered the day after 31 and this ia an error " << endl;
				cout << " Enter again" << endl;
				cout << " Enter your day: ";
				cin >> driver[i].birthday.day;
			}
		}

		cout << " Enter your month: ";
		cin >> driver[i].birthday.month;
		for (int i = 0; i < 2; i++)
		{
			if (driver[i].birthday.month > 12)
			{
				cout << " You entered the month after 12 and this ia an error " << endl;
				cout << " Enter again" << endl;
				cout << " Enter your month: ";
				cin >> driver[i].birthday.month;
			}
		}

		cout << " Enter your year: ";
		cin >> driver[i].birthday.year;
		cout << "\n";

		cout << " Enter the driver license number: ";
		cin >> number;
		cout << "\n";
		cout << " How many cars do you have?  " << endl;
		cout << "  ";
		cin >> number;
		cin.ignore();

		information_cars(number);
	}
}

void inquire_car()
{
	string plateNum;
	string name;
	int index = 0;
	cout << " What do you want: " << endl;
	cout << " 1. Enter the plate number" << endl;
	cout << " 2. Enter the name" << endl;
	cout << " ***************************************** " << endl;
	cout << " Enter you choose: ";
	cin >> number;
	cout << endl;
	cout << " *************************************** " << endl;
	switch (number)
	{
	case 1:
		cout << " Enter the plate number: ";
		cin >> plateNum;
		cout << endl;
		cout << " ********************************** " << endl;
		for (int i = 0; i < arr_car_size; i++)
		{
			if (car[i].Plate_Number.compare(plateNum) == 0)
			{
				cout << car[i].Plate_Number << endl;
				is_plateNum = true;
				index = i;
				break;
			}
		}

		if (is_plateNum)
		{
			cout << " The driver has name: ";
			cout << driver[index].name << endl;
			cout << " The driver has birthday: " << driver[index].birthday.day << " /";
			cout << driver[index].birthday.month << " /" << driver[index].birthday.year << endl;
			cout << " Fine count: ";
			cout << car[index].fine_count << endl;
			cout << " Fine plate number: ";
			cout << car[index].Plate_Number << endl;
			cout << " Fine model: ";
			cout << car[index].model << endl;
			cout << " Fine production year: ";
			cout << car[index].Production_Year << endl;

			cout << " Do you want to show fines for this car or Exit? " << "\n" << endl;
			cout << " Press 'y' for yes or 'n' for No" << endl;
			cout << "  ";
			cin >> chooseLetter;   // The letter the driver enters
			cout << " ************************************************************* " << endl;
			switch (chooseLetter)
			{
			case'y':
			case'Y':
				cout << " Enter the plate number: " << endl;
				cout << "  ";
				cin >> plateNum;
				inquire_fine(plateNum);
				break;
			case'n':
			case'N':
				menu();
				break;
			default:
				cout << " you enter a wrong letter" << endl;
				cout << " ******************************** " << endl;
				menu();
				break;

			}
		}
		else
		{
			cout << " There is no lincense plate number you entered" << endl;
			cout << " Enter again" << endl;
			cout << " ************************************************************* " << endl;
			inquire_car();
		}
		break;
	case 2:
		cout << " Enter your name: ";
		cin >> name;
		cout << endl;
		cout << " ******************************* " << endl;
		for (int i = 0; i < arr_name_size; i++)
		{
			if (driver[i].name.compare(name) == 0)
			{
				is_plateNum = true;
				index = i;
				break;
			}
		}

		if (is_plateNum)
		{
			cout << " The driver has name: ";
			cout << driver[index].name << endl;
			cout << " The driver has birthday: " << driver[index].birthday.day << " /";
			cout << driver[index].birthday.month << " /" << driver[index].birthday.year << endl;

			cout << " Fine count: ";
			cout << car[index].fine_count << endl;
			cout << " Fine plate number: ";
			cout << car[index].Plate_Number << endl;
			cout << " Fine model: ";
			cout << car[index].model << endl;
			cout << " Fine production year: ";
			cout << car[index].Production_Year << endl;

			cout << " Do you want to show fines for this car or Exit? " << "\n" << endl;
			cout << " Press 'y' for yes or 'n' for No" << endl;
			cout << "  ";
			cin >> chooseLetter;   // The letter the driver enters
			cout << " ************************************************************* " << endl;
			switch (chooseLetter)
			{
			case'y':
			case'Y':
				cout << " Enter the plate number: " << endl;
				cout << "  ";
				cin >> plateNum;
				inquire_fine(plateNum);

				break;
			case'n':
			case'N':
				menu();
				break;
			default:
				cout << " you enter a wrong letter" << endl;
				cout << " ******************************** " << endl;
				menu();
				break;

			}
		}
		else
		{
			cout << " There is no lincense plate number you entered" << endl;
			cout << " Enter again" << endl;
			cout << " ************************************************************* " << endl;
			inquire_car();
		}
		break;
	default:
		cout << " you enter a wrong number " << endl;
		cout << " Enter again" << endl;
		cout << " ************************************************************* " << endl;
		inquire_car();
		break;
	}
}

void menu_traffic_man() {

	cout << " 1. Do you want to register a new fine for the car? " << endl;
	cout << " 2. Do you want to inquire about a fine car? " << endl;
	cout << " 3. Do you want to inquire about a car? " << endl;
	cout << " ************************************************************* " << endl;
	cout << " Enter your choise: " << endl;
	cout << "   ";
	cin >> number;       //the number chosen from the traffic man
	cout << " ************************************************************* " << endl;

	switch (number)
	{
	case 1:
		cout << " Enter plate number:  " << endl;
		cout << "  ";
		cin >> plateNum;
		fine_registration(plateNum);
		break;
	case 2:
		cout << " Enter the plate number" << endl;
		cout << "  ";
		cin >> plateNum;
		inquire_fine(plateNum);
		break;
	case 3:
		inquire_car();
		break;
	default:
		cout << " You entered a wrong number" << endl;
		cout << " Enter again" << endl;
		cout << " ************************************************************* " << endl;
		menu_traffic_man();
		break;
	}

}

void menu_driver()
{

	cout << " 1. Do you want to log data? " << endl;
	cout << " 2. Do you want to see a fine car? " << endl;
	cout << " 3. Do you want to pay fines? " << endl;
	cout << " ************************************************************* " << endl;
	cout << " Enter your choise: " << endl;
	cout << "  ";
	cin >> number;
	cout << " ************************************************************* " << endl;

	switch (number)
	{
	case 1:
		infotmation_driver();
		break;
	case 2:
		cout << " Enter the plate number:  " << endl;
		cout << "  ";
		cin >> plateNum;
		inquire_fine(plateNum);
		break;
	case 3:
		cout << " Enter plate number:  " << endl;
		cout << "  ";
		cin >> plateNum;
		cout << endl;
		pay_the_fines(plateNum);
		break;
	default:
		cout << " You entered a wrong number" << endl;
		cout << " Enter again" << endl;
		cout << " ************************************************************* " << endl;
		menu_driver();
		break;
	}
	cout << " ************************************************************* " << endl;
}

int main()
{
	cout << endl;
	cout << "                           ******************** Traffic Control System **********************      " << endl;
	cout << endl;
	cout << "                               ************************ Welcome ************************             " << endl;
	cout << endl;
	for (int i = 0; i < 2; i++) {
		if (i == 0) {
			car[i].Plate_Number = "100";
			car[i].model = "bmw";
			car[i].Production_Year = 2020;
			car[i].fine_count = 1;
			arr_car_size++;

			fine[i].fine_cost = 200;
			fine[i].registration_date.day = 15;
			fine[i].registration_date.month = 9;
			fine[i].registration_date.year = 2020;
			fine[i].street_name = "Ahamed st";
			fine[i].fine_case = false;
			fine[i].fines_id = 1;
			fine[i].plate_number = "100";
			arr_fine_size++;
		}
		else
		{
			car[i].Plate_Number = "201";
			car[i].model = "bmw";
			car[i].Production_Year = 2018;
			car[i].fine_count = 2;
			arr_car_size++;

			for (int j = i; j < car[i].fine_count + 1; j++) {
				fine[j].fine_cost = 200 + (j * 100);
				fine[j].registration_date.day = 5;
				fine[j].registration_date.month = 9;
				fine[j].registration_date.year = 2019;
				fine[j].street_name = "Ahamed st";
				if (j == 2) {
					fine[j].fine_case = true;
				}
				else
				{
					fine[j].fine_case = false;
				}

				fine[j].fines_id = j + 1;
				fine[j].plate_number = "201";
				arr_fine_size++;
			}

		}

	}

	menu();

	return 0;
}

void inquire_fine(string plateNum)
{
	float sumTotalCost = 0;     // The total fines that are found on the driver
	float netTotalCost = 0;       // Total fines not paid
	bool isFinePlate = false; // Total fines not paid

	for (int i = 0; i < arr_fine_size; i++)
	{
		if (fine[i].plate_number.compare(plateNum) == 0)
		{
			isFinePlate = true;
			cout << " Fine id: ";
			cout << fine[i].fines_id << endl;
			cout << " Fine plate number: ";
			cout << fine[i].plate_number << endl;
			cout << " Fine case: ";
			if (fine[i].fine_case) {
				cout << " Pay" << endl;
			}
			else
			{
				cout << " Not Pay" << endl;
			}
			cout << " Fine cost: ";
			cout << fine[i].fine_cost << " L.E " << endl;
			cout << " Fine registration date: ";
			cout << fine[i].registration_date.day << "/" << fine[i].registration_date.month << "/";
			cout << fine[i].registration_date.year << endl;
			cout << " Street name: ";
			cout << fine[i].street_name << endl;

			cout << " ************************************************************* " << endl;

			sumTotalCost += fine[i].fine_cost;

			if (!fine[i].fine_case)
			{
				netTotalCost += fine[i].fine_cost;
			}
		}
	}if (isFinePlate)
	{

		cout << " Total fine cost: " << sumTotalCost << " L.E" << endl;
		cout << " Total Not Pay cost: " << netTotalCost << " L.E" << endl;
		cout << " *********************************************************** " << endl;
		cin.ignore();
		cout << " press enter to main menu " << endl;
		cin.ignore();
		cout << " ************************************************************* " << endl;
		menu();
	}
	else
	{
		cout << " There are no fines " << endl;
		cout << " ************************************************************ " << endl;
		cout << " Do you want to search again or Exit? " << "\n" << endl;
		cout << " Press 'y' for yes or 'n' for No" << endl;
		cout << "  ";
		cin >> chooseLetter;   // The letter the driver enters
		cout << " ************************************************************* " << endl;
		switch (chooseLetter)
		{
		case'y':
		case'Y':
			cout << " Enter the plate number: " << endl;
			cout << "  ";
			cin >> plateNum;
			inquire_fine(plateNum);
			break;
		case'n':
		case'N':
			menu();
			break;
		default:
			cout << " you enter a wrong letter" << endl;
			cout << " *************************************************** " << endl;
			cin.ignore();
			cout << " press enter to main menu " << endl;
			cin.ignore();
			cout << " ************************************************************* " << endl;
			menu();
			break;
		}
	}
}

int menu()
{
	cout << " Who are you?" << endl;
	cout << "  1. Driver" << endl;
	cout << "  2. Traffic Man" << endl;
	cout << " *************************************************************" << endl;
	cout << " If you want to close the screen enter 0 " << endl;
	cout << " *************************************************************" << endl;
	cout << " Enter your choise: " << endl;
	cout << "  ";
	cin >> number;
	cout << " *************************************************************" << endl;
	switch (number)
	{
	case 1:
		menu_driver();
		break;
	case 2:
		menu_traffic_man();
		break;
	case 0:
		return 0;
		break;

	default:
		cout << " You entered a wrong number" << endl;
		cout << " Enter again" << endl;
		cout << " *************************************************************" << endl;
		menu();
		break;
	}
	cin.ignore();
	cout << " press enter to main menu " << endl;
	cin.ignore();
	cout << " ************************************************************* " << endl;
	menu();
}