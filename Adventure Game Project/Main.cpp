
// Libraries
#include <string>
#include <iostream>
#include <vector>

// Needed to avoid having to type std:: a lot!
using namespace std;

// Main function where program code execution begins and ends.
int main()
{

	// INITIALISE variables
	string playerName = "";
	vector <string> roomNames = { "Courtyard", "Entry Hall", "Gate" };
	vector <string> roomDescs = { 
		"A barren, weed-filled courtyard of a crumbling ruined castle.", 
		"A once-grand hll with a rotting red carpet, lined with rusted suits of armour..",
		"The dilapidated gates hang crookedly from their hinges, set into the crumbling stone wall that surrounds the ruined castle." };

	int playerStamina = 100;
	string playerChoice = "";
	int newRoomIndex = -1;
	int moveCost = 5;

	// DISPLAY the title of the program.
	cout << "Welcome to the Example Adventure Game!" << endl;

	// DISPLAY a message to the player asking their name.
	cout << "What are you called, brave adventurer?" << endl;

	// READ the player's response into the playerName variable
	getline(cin, playerName);
	cout << endl;

	// DISPLAY a greeting to the player, using the playerName variable
	cout << "Welcome, " << playerName << ", soon to be hero of the realm!" << endl << endl;

	// DISPLAY the name of the room where the player currently is, using the room1Name variable
	cout << "You find yourself in the " << roomNames[0] << " - ";

	// DISPLAY the description of the room where the player currently is, using the room1Desc variable
	cout << roomDescs[0] << endl << endl;

	// DISPLAY the player's current stamina, using the playerStamina variable
	cout << "Stamina remaining: " << playerStamina << endl;

	// DISPLAY the names of the other two rooms, numbered, 
	// as potential exits, and ask the player where they want to go
	cout << "Exits are:" << endl;
	cout << "1.   " << roomNames[1] << endl;
	cout << "2.   " << roomNames[2] << endl;
	cout << "Where would you like to go?" << endl;

	// READ the player's response into the playerChoice variable
	getline(cin, playerChoice);

	// IF the player has chosen the first room...
	if (playerChoice == "1")
	{
		// SET the index to 1
		newRoomIndex = 1;
	}
	// ELSE IF the player has chosen the second room...
	else if (playerChoice == "2")
	{
		// SET the index to 2
		newRoomIndex = 2;
	}
	// ELSE 
	else
	{
		// DISPLAY an error message due to unrecognised input
		cout << "Sorry, I couldn't understand what you meant by \"" << playerChoice << "\"" << endl;
	}
	// ENDIF

	// IF the new room index is not -1 (it is valid)
	if (newRoomIndex != -1)
	{
		// SUBTRACT the stamina required to move from the player's stamina value
		playerStamina = playerStamina - moveCost;

		// DISPLAY the name and description of the chosen room and the player's
		// new stamina
		cout << "You move to the " << roomNames[newRoomIndex] << " - ";
		cout << roomDescs[newRoomIndex] << endl << endl;
		cout << "Stamina remaining: " << playerStamina << endl;
	}
}