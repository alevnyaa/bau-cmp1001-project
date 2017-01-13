//Final code
//1608420 Yerlikaya
//1607038 Pata

#include <iostream>
#include "data.h"

using namespace std;

void displayMenu(){
  cout << "1) Display number of files and sum of file sizes for each user" << endl;
  cout << "2) Display usernames of the users who have no files in the system" << endl;
  cout << "3) Display average file size for each user" << endl;
  cout << "4) Display password of a username entered by the user" << endl;
  cout << "5) Search user and display password and size of each file of that user" << endl;
  cout << "6) Display the minimum file size" << endl;
  cout << "7) Display the maximum file size" << endl;
  cout << "8) Upload a new file for a user" << endl;
  cout << "9) Display all usernames beginning with the entered character" << endl;
  cout << "0 or q) Exit" << endl;
  cout << "m) Display this menu" << endl;
}

void allFileNumAndSizeSum(){
  cout << "Username" << "\t" << "Number" << "Sum" << endl;
  for(int i = 0; i < 82; i++){
    int numOfFiles = 0;
    int sumOfFiles = 0;
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > 0){
        numOfFiles++;
        sumOfFiles+=currentSize;
      }
  	}
    cout << usernames[i] << "\t" << numOfFiles << "\t" << sumOfFiles << endl;
  }
}

void allUsersWithNoFiles(){
  for(int i = 0; i < 82; i++){
    int numOfFiles = 0;
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > 0){
        numOfFiles++;
      }
  	}
    if(numOfFiles == 0){
      cout << usernames[i] << endl;
    }
  }
}

void allAverageSizes(){
  cout << "Username" << "\t" << "Average" << endl;
  for(int i = 0; i < 82; i++){
    int numOfFiles = 0;
    int sumOfFiles = 0;
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > 0){
        numOfFiles++;
        sumOfFiles+=currentSize;
      }
  	}
    if(numOfFiles > 0){
      cout << usernames[i] << "\t" << (float) (sumOfFiles) / numOfFiles << endl;
    }
  }
}

void passwordOfUser(){
  cout << "Input a username, with underscores" << endl;
  std::string username;
  cin >> username;
  for(int i = 0; i < 82; i++){
    if(username == usernames[i]){
      cout << "User: " << username << " Password: " << passwords[i] << endl;
      break;
    }
  }
}

void passwordAndSizeOfEachFile(){
  cout << "Input a username, with underscores" << endl;
  std::string username;
  cin >> username;
  for(int i = 0; i < 82; i++){
    if(username == usernames[i]){
      cout << "User: " << username << " Password: " << passwords[i] << " Files:";
      for(int j = 0; j < 5; j++){
        int currentSize = file_sizes[i][j];
	if(file_sizes[i][j] > 0){
	  cout << " " << file_sizes[i][j];
	}
      }
      cout << endl;
      break;
    }
  }
}
/* Commented out because this code finds min and max for all users independently, and after asking about it we found out that you want a global search
void minFileSize(){
  cout << "Username" << "\t" << "MinSize" << endl;
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
  }
}

void maxFileSize(){
  cout << "Username" << "\t" << "MaxSize" << endl;
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
  }
}
*/

void minFileSize(){
  int minSize = 1000;
  for(int i = 0; i < 82; i++){
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > 0 && currentSize < minSize){
        minSize = currentSize;
      }
  	}
  }
  cout << "Min file size: " << minSize << endl;
}

void maxFileSize(){
  int maxSize = 0;
  for(int i = 0; i < 82; i++){
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > maxSize){
        maxSize = currentSize;
      }
  	}
  }
  cout << "Max file size: " << maxSize << endl;
}

void uploadFile(){
  cout << "Enter your username" << endl;
  std::string username;
  cin >> username;

  int userID = -1;
  for(int i = 0; i < 82; i++){
    if(username == usernames[i]){
      userID = i;
      break;
    }
  }

  //the following if statement is used to prevent a case where a file is uploaded without a user
  if(userID = -1){
      cout << "This user does not exist." << endl;
      return;
  }

  int slotID = -1;
  for(int i = 0; i < 5; i++){
    if(file_sizes[userID][i] == 0){
      slotID = i;
      break;
    }
  }

  if(slotID == -1){
    cout << "You don't have any empty file slots" << endl;
    return;
  }

  cout << "Enter file size" << endl;
  int fileSize;
  cin >> fileSize;
  if(fileSize <= 1000){
    file_sizes[userID][slotID] = fileSize;
  }else{
    cout << "The file is too large" << endl;
  }
}

void startingWithCharacter(){
  cout << "Input a character" << endl;
  std::string rawInput = "";
  cin >> rawInput;
  char firstChar;
  if(rawInput.length() == 1){
    firstChar = rawInput[0];
  }else{
    cout << "Invalid input";
    return;
  }

  for(int i = 0; i < 82; i++){
    if(usernames[i][0] == firstChar){
      cout << usernames[i] << endl;
    }
  }
}


int main(){
  bool exitStatus = false;
  while(!exitStatus){
    cout << "Waiting for input, enter \"m\" for menu" << endl;
    std::string rawInput = "";
    cin >> rawInput;
    char code;
    //parse input
    if(rawInput.length() == 1){
      code = rawInput[0];
    }else{
      code = 'e';
    }
    switch(code){
      //Display number of files and sum of file sizes for each user
      case '1':
        allFileNumAndSizeSum();
        break;
      //Display usernames of the users who have no files in the system
      case '2':
        allUsersWithNoFiles();
        break;
      //Display average file size for each user
      case '3':
        allAverageSizes();
        break;
      //Display password of a username entered by the user
      case '4':
        passwordOfUser();
        break;
      //Search user (get username as input and display password and size of each file of that user)
      case '5':
        passwordAndSizeOfEachFile();
        break;
      //Display the minimum file size (0 (zero) means nothing which should be ignored)
      case '6':
        minFileSize();
        break;

      //Display the maximum file size (0 (zero) means nothing which should be ignored)
      case '7':
        maxFileSize();
        break;

      //Upload a new file for a user
        //a) Get the username
        //b) If there is no available free file slot for that user, display warning message and the menu
        //c) If there is available free file slot get the file size
          //i) If file size is less than or equal to 1000, set it to free slot of that user
            //ii) If file size is greater than 1000, display warning message and the menu
      case '8':
        uploadFile();
        break;

      //Get a character (a single char) from the user and display all usernames beginning with the entered character
      case '9':
        startingWithCharacter();
        break;

      //exit
      case '0':
        cout << "Quitting..." << endl;
        exitStatus = true;
        break;
      //exit with q
        case 'q':
          cout << "Quitting..." << endl;
          exitStatus = true;
          break;
      //menu
      case 'm':
        displayMenu();
        break;
      //invalid input
      default:
        cout << "Invalid input, please enter \"m\" for the menu." << endl;
    }
  }
	return 0;
}


//Mert's code below
/*
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
  } *//* //Displaying min file size for each user.
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
  } */ /*//Displaying max file size for each user.
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
*/
