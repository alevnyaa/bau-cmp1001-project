#include <iostream>
#include "data.h"
//#include<fstream>
//#include<ctime>

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
  cout << "Username" << "\t" << "Password" << "\t" << "Sizes" << endl;
  for(int i = 0; i < 82; i++){
    cout << usernames[i] << "\t" << passwords[i];
  	for(int j = 0; j < 5; j++){
      int currentSize = file_sizes[i][j];
      if(currentSize > 0){
        cout << "\t" << currentSize;
      }
  	}
    cout << endl;
  }
}

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

  int slotID = -1;
  for(int i = 0; i < 5; i++){
    if(file_sizes[userID][i] == 0){
      slotID = i;
      break;
    }
  }

  if(slotID == -1){
    cout << "You don't have any empty file slots" << endl;
    displayMenu;
    return;
  }

  cout << "Enter file size" << endl;
  int fileSize;
  cin >> fileSize;
  if(fileSize <= 1000){
    file_sizes[userID][slotID] = fileSize;
  }else{
    cout << "The file is too large" << endl;
    displayMenu();
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
