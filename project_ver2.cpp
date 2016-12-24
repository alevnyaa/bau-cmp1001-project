// 1001project.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<ctime>
#include "data.h"

using namespace std;

void choice1();
void choice2();
void choice3();
void choice4();
void choice5();
void choice6();
void choice7();
void choice8();
void choice9();

int main()
{
	int choice = -1; //to initialize while loop
	while (choice < 0 || choice > 9) {		//to enter 0-9 only
	cout<< "1) Display number of files and sum of file sizes for each user\n"
		<< "2) Display usernames of the users who have no files in the system\n"
		<< "3) Display average file size for each user\n"
		<< "4) Enter a username to see the password\n"
		<< "5) Search user\n"
		<< "6) Display the minimum file size\n"
		<< "7) Display the maximum file size\n"
		<< "8) Upload a new file for a user\n"
		<< "9) Enter a character to see the usernames beginning with the entered character\n"
		<< "0) Exit\n\n"
		<< "Enter your choice : ";
	cin >> choice;
	}

	switch (choice) //choice switch
	{
	case 1:
		choice1();
		break;
	case 2:
		choice2();
		break;
	case 3:
		choice3();
		break;
	case 4:
		choice4();
		break;
	case 5:
		choice5();
		break;
	case 6:
		choice6();
		break;
	case 7:
		choice7();
		break;
	case 8:
		choice8();
		break;
	case 9:
		choice9();
		break;
	case 0:
		break;
	} //end of switch

	return 0;
}

void choice1() {
	cout << "User\t" << "Number of Files\t" << "\tSum of Files\n";
	cout << "----\t" << "----------------\t" << "------------\n\n";
	for (int i = 0; i < 82; i++) // to display all 82 users
	{
		int counter = 0, sum = 0;
		for (int j = 0; j < 5; j++)  // to get each 5 file sizes
		{
			if (!(file_sizes[i][j] == 0)) {
				counter++;
				sum = sum + file_sizes[i][j];
			} // end of if
		} // end of inner loop
		cout << usernames[i] << "\t" << counter << "\t" << sum << endl;
	} // end of outer loop
	cout << endl;
	main();
}
//done

void choice2() {
	for (int i = 0; i < 82; i++) // to display all 82 users
	{
		int counter = 0;
		for (int j = 0; j < 5; j++)  // to get each 5 file sizes
		{
			if (file_sizes[i][j] == 0) {
				counter++;
			} // end of if
		} // end of inner loop
		if (counter == 5)
			cout << usernames[i] << " has no files in the system." << endl;
	} // end of outer loop
	cout << endl;
	main();
}
//done

void choice3() {
	cout << "User\t" << "Average File Size\n";
	cout << "----\t" << "------------------\n\n";
	for (int i = 0; i < 82; i++) // to display all 82 users
	{
		double sum = 0;
		for (int j = 0; j < 5; j++)  // to get each 5 file sizes
		{
			sum = sum + file_sizes[i][j];
		} // end of inner loop
		sum = sum / 5;
		cout << usernames[i] << "\t" << sum << endl;
	} // end of outer loop
	cout << endl;
	main();
}
//done

void choice4() {

}

void choice5() {

}

void choice6() {
	int min = file_sizes[0][0];
	for (int i = 0; i < 82; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (file_sizes[i][j] <= min && file_sizes[i][j] != 0) //if file_size is smaller than the next one and not zero
				min = file_sizes[i][j];
		}
	}
	cout << "Minimum file size is " << min << endl << endl;
	main();
}
//done

void choice7() {
	int max = file_sizes[0][0];
	for (int i = 0; i < 82; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (file_sizes[i][j] >= max && file_sizes[i][j] != 0) //if file_size is smaller than the next one and not zero
				max = file_sizes[i][j];
		}
	}
	cout << "Maximum file size is " << max << endl << endl;
	main();
}
//done

void choice8() {

}

void choice9() {

}
