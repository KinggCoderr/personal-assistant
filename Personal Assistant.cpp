#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

//***************************************FUNCTIONS********************************************

//greeting
void greeting() {
	string welcome = "\n*****W E L C O M E   T O   Y O U R   P E R S O N A L   A S S I S T A N T*****\n\n";
	for (int i = 0; i < welcome.length(); i++) {
		cout << welcome[i];
		Sleep(50);
	}
	cout << "Press any key to continue...";
	_getch();
	system("CLS");
}

//functions for finance feature
void DateAndTime() {
	// Get the current date and time
	time_t now = time(0);
	struct tm localTime;

	// Open the file for writing
	ofstream F("Finance.txt", ios::app);

	if (localtime_s(&localTime, &now) != 0) {
		cerr << "Error getting local time." << endl;
		return;
	}

	// Write the date and time to the file
	F << "Entry Date and Time: ";
	F << 1900 + localTime.tm_year << "-"
		<< 1 + localTime.tm_mon << "-"
		<< localTime.tm_mday << " "
		<< localTime.tm_hour << ":"
		<< localTime.tm_min << ":"
		<< localTime.tm_sec << std::endl;

	// Close the file
	F.close();
}

void NewExpense(string expense, double cost) {
	system("CLS");
	ofstream F("Finance.txt", ios::app);
	DateAndTime();
	cout << "Expense: ";
	getline(cin, expense);
	F << "Expense: " << expense << endl;
	cout << "Cost: ";
	cin >> cost;
	F << "Cost: " << cost << endl << endl;
	F.close();
}

void Read(string read) {
	system("CLS");
	ifstream F("Finance.txt");
	while (getline(F, read)) {
		cout << read << endl;
	}
	F.close();
	cout << "Press any key to continue...";
	_getch();
	system("CLS");
}

//functions for calender feature
int days(int month, int year) {
	//this function determines the days in a given month
	if (month == 2) {
		if ((year % 4) == 0)
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}

	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
		return 30;
	}
	else
	{
		return 31;
	}
}

void use() {
	cout << "\n\nPress\n";
	cout << "Left Arrow              Previous Month\n";
	cout << "Right Arrow             Next Month\n";
	cout << "Escape                  Exit\n";
}

void Calender(int month, int year) {
	system("CLS");
	//very complicated code to determine 1st day of month
	int F, c, d;
	c = month;
	d = year;

	if (month < 3) {
		month += 12;
		year--;
	}

	int q = 1;
	int m = month;
	int K = year % 100;
	int J = year / 100;

	F = (q + 13 * (m + 1) / 5 + K + K / 4 + J / 4 - 2 * J) % 7;
	F--;
	if (F < 0) {
		F += 7;
	}

	//display calender
	cout << "    Month: " << c << "  Year: " << d << endl;
	cout << " SUN MON TUE WED THU FRI SAT\n";

	for (int i = 0; i < F; i++) {
		cout << setw(4) << " ";
	}

	int counter = F;

	for (int i = 1; i <= days(c, d); i++) {
		counter++;
		cout << setw(4) << i;
		if (counter == 7)
		{
			counter = 0;
			cout << endl;
		}
	}

	use();

}

//functions for alarm feature
bool isAlarmTime(const tm& targetTime) {
	// Function to check if the current time matches the specified date and time
	// Get the current time
	auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
	tm localTime;

	// Use localtime_s for safer handling
	if (localtime_s(&localTime, &now) != 0) {
		cerr << "Error getting local time. Exiting program." << endl;
		exit(1);
	}

	// Check if it's the specified date and time
	return (localTime.tm_year == targetTime.tm_year &&
		localTime.tm_mon == targetTime.tm_mon &&
		localTime.tm_mday == targetTime.tm_mday &&
		localTime.tm_hour == targetTime.tm_hour &&
		localTime.tm_min == targetTime.tm_min);
}

//funtions for islamic trading
void rules()

{
	system("CLS");

	string rule = "\n\n"
		"\n\n========================================================================================\n\n"
		"\t\tRULES OF ISLAMIC ONLINE  TRADING FOLLOWS\n"
		"\n\n========================================================================================\n\n"
		"\t1. Choose the islamic stock wheather its high(6-10) or its low (1-5)\n"
		"\t2. If you win you will get 10 times of money as reward/gift you invested\n"
		"\t3. If you predicted wrong you will lose your invested amount as we both are responsible\n\n"
		"\n\n========================================================================================\n\n";

	for (int i = 0; i < rule.size(); i++)
	{
		Sleep(10);
		cout << rule[i];

	}

}
	
void display()

{

	string var = " ********** W E L C O M E    T O   I S L A M I C    O N L I N E    T R A D I N G***************    "
		"\n#W E  T R U S T   Y O U R  B E L E I V E";

	for (int i = 0; i < var.size(); i++)
	{
		Sleep(80);
		cout << var[i];
	}

}

//****************************************************************************************************



int main() {
	greeting();


	while (true) {

		system("CLS");
		cout << "What would you like to do:\n\n";
		cout << "1.Finance\n";
		cout << "2.Calender\n";
		cout << "3.Reminder\n";
		cout << "4.Calculator\n";
		cout << "5.Browser\n";
		cout << "6.Islamic Trading\n";
		cout << "7.Exit\n";

		Sleep(300);
		_getch();

		if (GetAsyncKeyState('1')) {                 //finance

			system("CLS");

			string expense, read;
			double cost = 0;
			cout << "Welcome to Finance\n";

			while (true) {

				cout << "What would you like to do:\n1. Create New Entry\n2. View \n3. Exit\n";
				Sleep(300);
				_getch();
				//new entry
				if (GetAsyncKeyState('1')) {
					NewExpense(expense, cost);
				}

				//view expenses
				else if (GetAsyncKeyState('2')) {
					Read(read);
				}

				//exit finance
				else if (GetAsyncKeyState('3')) {
					string end = "\nG O O D B Y E :(  ";
					for (int i = 0; i < end.length(); i++) {
						cout << end[i];
						Sleep(50);
					}
					break;
				}

				//invalid
				else {
					cout << "\nyour response is invalid.\n";
					continue;
				}

				//continue...?
				cout << "Do you want to continue operations(y/n): ";
				char b;
				cin >> b;
				if (b != 'y') {
					break;
				}
				system("CLS");
			}
		}

		else if (GetAsyncKeyState('2')) {            //calender

			system("CLS");

			int m, year;
			cout << "Enter Year:";
			cin >> year;
			cout << "Enter Month:";
			cin >> m;
			Calender(m, year);

			while (true) {

				_getch();

				if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
					m++;
					if (m == 13) {
						m = 1;
						year++;
					}
					Calender(m, year);
					Sleep(100);
				}

				if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
					m--;
					if (m == 0) {
						m = 12;
						year--;
					}
					Calender(m, year);
					Sleep(100);
				}

				if (GetAsyncKeyState(VK_ESCAPE)) {
					system("CLS");
					string sad = "\nS A Y O N A R A :( ";
					for (int i = 0; i < sad.length(); i++) {
						cout << sad[i];
						Sleep(50);
					}
					Sleep(100);
					break;
				}

			}

		}

		else if (GetAsyncKeyState('3')) {            //alarm

			int year, month, day, hour, minute;

			system("CLS");

			// Get the date and time for the alarm
			cout << "Enter the year: ";
			cin >> year;

			cout << "Enter the month (1-12): ";
			cin >> month;

			cout << "Enter the day of the month: ";
			cin >> day;

			cout << "Enter the hour (0-23): ";
			cin >> hour;

			cout << "Enter the minute (0-59): ";
			cin >> minute;

			// Validate input
			if (month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
				cerr << "Invalid input. Exiting program." << endl;
				return 1;
			}

			// Set the target time
			tm targetTime = {};
			targetTime.tm_year = year - 1900; // tm_year is years since 1900
			targetTime.tm_mon = month - 1;    // tm_mon is 0-based
			targetTime.tm_mday = day;
			targetTime.tm_hour = hour;
			targetTime.tm_min = minute;

			system("CLS");

			cout << "Alarm set for " << year << "/" << month << "/" << day << " " << hour << ":" << minute << ".\n Waiting for the alarm..." << endl;

			// Check for the alarm time every second
			while (true) {
				if (isAlarmTime(targetTime)) {
					for (int i = 0; i < 3; i++) {
						cout << "\a\aALARM!" << endl;
						Sleep(1000);
					}
					break;
				}

				// Wait for a second before checking again
				this_thread::sleep_for(chrono::seconds(1));
			}
			cout << "\n\nPress any key to continue...";
			_getch();

		}

		else if (GetAsyncKeyState('4')) {            //calculator

			char operation;
			double num1, num2, result;
			const double M_PI = 3.1416;

			while (true) {
				system("CLS");

				// Input
				cout << "Enter first number: ";
				cin >> num1;
				cout << "Enter operation (+, -, *, /): ";
				cin >> operation;
				cout << "Enter second number: ";
				cin >> num2;
				

				// Perform calculations
				switch (operation) {
				case '+':
					result = num1 + num2;
					break;
				case '-':
					result = num1 - num2;
					break;
				case '*':
					result = num1 * num2;
					break;
				case '/':
					if (num2 != 0) {
						result = num1 / num2;
					}
					else {
						cout << "Error: Division by zero!" << endl;
						cout << "\n\nPress any key to continue...";
						_getch();
						continue;
					}
					break;
				default:
					cout << "Invalid operation!" << endl;
					cout << "\n\nPress any key to continue...";
					_getch();
					continue;
				}
				break;
			}
			// Output result
			cout << "Result: " << result << endl;

			cout << "\n\nPress any key to continue...";
			_getch();

		}

		else if (GetAsyncKeyState('5')) {            //browser

			system("CLS");

			char choicem, ch;
			string brow = "******W E L C O M E    T O     M I N I     B R O W S E R ****** "
				"\n\t here you can access popular websites";

			for (int i = 0; i < brow.size(); i++) {
				cout << brow[i];
				if (_kbhit() == 1) {
					Sleep(0);
				}
				else {
					Sleep(70);//to hold the output and display slowly
				}
			}


			cout << "\nLOADING PLEASE WAIT";

			string load = ".  .  .  .  .";

			for (int j = 0; j < load.size(); j++) {
				Sleep(200);
				cout << load[j];
			}


			//urls saved in characters to dispaly with start command
			string C = "start https://www.chrome.com/";
			string F = "start https://www.facebook.com/";
			string W = "start https://www.accuweather.com/en/pk/islamabad/258278/weather-forecast/258278";
			string I = "start https://www.instagram.com/";
			string N = "start https://www.netflix.com/";
			string A = "start https://www.amazon.com/";
			string T = "start https://www.twitter.com/";
			string L = "start https://www.linkdin.com/";
			string H = "start https://www.hotstar.com/";
			string Y = "start https://www.youtube.com/";


			do {
				system("CLS");
				cout << endl << endl << endl;
				cout << "\n We offer the following websites direct path way feel free to visit them     :\n ";
				cout << "__________________________________________________________________________________________________________________";
				cout << "\n\n\n\t\t\t1.Enter C for chrome browser .";
				cout << "\n\t\t\t2.Enter F for facebook.";
				cout << "\n\t\t\t3.Enter W for weather updates.";
				cout << "\n\t\t\t4.Enter Y for Youtube.";
				cout << "\n\t\t\t5.Enter I for instagram.";
				cout << "\n\t\t\t6.Enter N for Netflix.";
				cout << "\n\t\t\t7.Enter A for Amazon.";
				cout << "\n\t\t\t8.Enter T for Twitter.";
				cout << "\n\t\t\t9.Enter L for linkdn.";
				cout << "\n\t\t\t10.Enter H for hotsar.\n";
				cout << "___________________________________________________________________________________________________________________\n\n";

				cin >> choicem;
				if (choicem == 'C' || choicem == 'c') {
					cout << "Loading";
					for (int k = 0; k < load.size(); k++) {
						Sleep(150);
						cout << load[k];
					}
					system(C.c_str());//system command link to url setting it as constant pointer
				}
				else if (choicem == 'F' || choicem == 'f') {
					cout << "Loading";
					for (int kk = 0; kk < load.size(); kk++) {
						Sleep(150);
						cout << load[kk];
					}
					system(F.c_str());
				}
				else if (choicem == 'W' || choicem == 'w') {
					cout << "Loading";
					for (int kkk = 0; kkk < load.size(); kkk++) {
						Sleep(150);
						cout << load[kkk];
					}
					system(W.c_str());
				}
				else if (choicem == 'Y' || choicem == 'y') {
					cout << "Loading";
					for (int jj = 0; jj < load.size(); jj++) {
						Sleep(150);
						cout << load[jj];
					}
					system(Y.c_str());
				}
				else if (choicem == 'I' || choicem == 'i') {
					cout << "Loading";
					for (int m = 0; m < load.size(); m++) {
						Sleep(150);
						cout << load[m];
					}
					system(I.c_str());
				}
				else if (choicem == 'N' || choicem == 'n') {
					cout << "Loading";
					for (int mm = 0; mm < load.size(); mm++) {
						Sleep(150);
						cout << load[mm];
					}
					system(N.c_str());
				}
				else if (choicem == 'A' || choicem == 'a') {
					cout << "Loading";
					for (int n = 0; n < load.size(); n++) {
						Sleep(150);
						cout << load[n];
					}
					system(A.c_str());
				}
				else if (choicem == 'T' || choicem == 't') {
					cout << "Loading";
					for (int a = 0; a < load.size(); a++) {
						Sleep(150);
						cout << load[a];
					}
					system(T.c_str());
				}
				else if (choicem == 'L' || choicem == 'l') {
					cout << "Loading";
					for (int c = 0; c < load.size(); c++) {
						Sleep(150);
						cout << load[c];
					}
					system(L.c_str());
				}
				else if (choicem == 'H' || choicem == 'h') {
					cout << "Loading";
					for (int d = 0; d < load.size(); d++) {
						Sleep(150);
						cout << load[d];
					}
					system(H.c_str());
				}
				cout << "\nDo You Want To Continue(y/n)\n";
				cin >> ch;
			} while (ch == 'y' || ch == 'Y');


		}

		else if (GetAsyncKeyState('6')) {            //islamic trading

			system("CLS");

			bool flag = 0;

			display();

			string name;
			int amount;
			char input;

			cout << "\nEnter name  :   ";
			getline(cin, name);
			cout << endl;
			cout << "Enter input your assets amount $ :   ";
			cin >> amount;
			cout << endl;

			do
			{
				rules();
				//game code

				int deposit;

				//start from it if condition fails
			label1:
				cout << name << ", Enter amount you want you wnat to enter in the app trade $ : ";
				cin >> deposit;
				cout << endl;

				if (deposit > amount)
				{
					cout << "Invalid input";

					cout << " You have not enough money" << endl;

					goto label1;
				}

				int trade = rand() % 10 + 1;
				int guess;
			label2:
				cout << "Enter input method : " << endl;
				cout << "Press 1 if you think stock will be high " << endl;
				cout << "Press 2 if you think stock will be low " << endl;
				cout << "Enter input :   ";
				cin >> guess;
				cout << endl;
				if (guess == 1)
				{

					if (trade >= 0 && trade <= 5)
					{
						flag = 1;
					}
					else
					{
						flag = 0;
					}
				}
				else if (guess == 2) //=
				{
					if (trade > 6)
					{
						flag = 1;
					}
					else
					{
						flag = 0;
					}
				}

				else
				{
					cout << "Invalid input " << endl;

					goto label2;
				}

				if (flag == 1)
				{
					cout << "Congratulations ! you win mashallah  " << endl;
					cout << "You win  = $" << deposit * 10 << endl;

					amount = amount + deposit * 10;

					cout << "\n Your  current balance is     :" << amount;
				}
				else
				{
					cout << "Sorry ";
					cout << "You lose= $" << deposit << endl;

					amount = amount - deposit;

					cout << endl << name << "\t Your  current balance is :" << amount;
					cout << endl;
				}
				cout << "\nWould you like to play again y/n : ";
				cin >> input;
				cout << endl;

				if (amount == 0)
				{
					cout << "You have not enough money to play" << endl;
					break;
				}
			} while (input != 'n');

			cout << name << " , " << " you have " << amount << "$" << endl;
			cout << "\n\n************************************************************************************" << endl;
		}
		
		else if (GetAsyncKeyState('7')) {            //exit
			system("CLS");
			string bye = "F A R E W E L L :| ";
			for (int i = 0; i < bye.length(); i++) {
				cout << bye[i];
				Sleep(50);
			}
			break;
		}

	}

	return 0;
}