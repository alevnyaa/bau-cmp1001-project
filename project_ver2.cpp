// C++ TEAM PROJECT.

#include<iostream>
#include "data.h"
#include<string>
#include<cctype>

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
    while (choice != 0){
        choice = -1;
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
    }

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
}
//Display number of files and sum of file sizes for each user

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
}
//Display usernames of the users who have no files in the system

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
}
//Display average file size for each user

void choice4() {
	cout << "Enter the username: ";
	string username;
	int counter = 0;
	cin >> username;
	for(int i = 0; i < 82; i++) {
		if(username == usernames[i]){
			cout << "Password: " << passwords[i] << endl << endl;
			break;
		}
		else
			counter++;
	}
	if (counter==82)
		cout << "You entered a wrong username." << endl << endl;
}
//Display password of a username entered by the user

void choice5() {
	cout << "Enter username: ";
	string username;
	int counter = 0;
	cin >> username;
	for (int i = 0; i < 82; i++) {
		if(username == usernames[i]) {
			cout << "Password: " << passwords[i] << endl;
			for (int j = 0; j < 5; j++) {
				cout << "Size " << j+1 << ": " << file_sizes[i][j] << endl;
			}
			cout << endl;
			break;
		}
		else
			counter++;
	}
	if (counter==82)
		cout << "You entered a wrong username." << endl << endl;
}
//Search user (get username as input and display password and size of each file of that user)

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

/*	cout << "Username" << "\t" << "MinSize" << endl;
  for(int i = 0; i < 82; i++){
    int minSize = 1001;
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > 0 && currentSize < minSize){
        minSize = currentSize;
      }
  	}
    if(minSize < 1001){
      cout << usernames[i] << "\t" << minSize << endl;
    }
  } */ //Displaying min file size for each user.
}
//Display the minimum file size (0 (zero) means nothing which should be ignored)

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

/*	cout << "Username" << "\t" << "MaxSize" << endl;
  for(int i = 0; i < 82; i++){
    int maxSize = 0;
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > maxSize){
        maxSize = currentSize;
      }
  	}
    if(maxSize > 0){
      cout << usernames[i] << "\t" << maxSize << endl;
    }
  } */ //Displaying max file size for each user.
}
//Display the maximum file size (0 (zero) means nothing which should be ignored)

void choice8() {
	int counter = 0;
	cout << "Enter username: ";
  string username;
  cin >> username;

  int userID = -1;
  for(int i = 0; i < 82; i++){
    if(username == usernames[i]){
      userID = i;
      break;
    }
		else {
			counter++;
		}
  }

	if (counter == 82) {
		cout << "You entered a wrong username.\n" << endl;
		main();
	}

  int slotID = -1;
  for(int i = 0; i < 5; i++){
    if(file_sizes[userID][i] == 0){
      slotID = i;
      break;
    }
  }

  if(slotID == -1){
    cout << "There is no free file slot for this user.\n" << endl;
    main();
  }

  cout << "Enter the file size: ";
  int fileSize;
  cin >> fileSize;
  if(fileSize < 1000 && fileSize > 0) {
    file_sizes[userID][slotID] = fileSize;
		cout << "File size is set to the free file slot.\n" << endl;
  }
	else {
    cout << "You should enter the file size between 0-1000!\n" << endl;
  }
}
//Upload a new file for a user
	//a) Get the username
	//b) If there is no available free file slot for that user, display warning message and the menu
	//c) If there is available free file slot get the file size
		//i) If file size is less than or equal to 1000, set it to free slot of that user
			//ii) If file size is greater than 1000, display warning message and the menu

void choice9() {
	cout << "Input a character: ";
	string rawInput = "";
	cin >> rawInput;
	char firstChar;
	if (rawInput.length() == 1) {
		firstChar = rawInput[0];
		
		if (isupper(firstChar)) {
			for (int i = 0; i < 82; i++) {
				if (usernames[i][0] == firstChar) {
					cout << usernames[i] << endl;
				}
			}
		}
		else {
			cout << "Invalid input. Enter an uppercase letter!\n" << endl;
			main();
		}
	}
	else {
		cout << "Invalid input. Enter only 1 character.\n" << endl;
		main();
	}
	cout<<endl;
}
//Get a character (a single char) from the user and display all usernames beginning with the entered character
