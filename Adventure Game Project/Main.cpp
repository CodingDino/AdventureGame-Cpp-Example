
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
		"The dilapidated gates hang crookedly from their hinges, set into the crumbling stone wall that surrounds the ruined castle." 
	};
	int playerChoice = -1;
	int moveCost = 5;
	int playerStamina = 20;
	int roomIndex = 0;
	bool exit = false;

	// DISPLAY the title of the program.
	cout << "Welcome to the Example Adventure Game!" << endl;

	// DISPLAY a message to the player asking their name.
	cout << "What are you called, brave adventurer?" << endl;

	// READ the player's response into the playerName variable
	getline(cin, playerName);
	cout << endl;

	// DISPLAY a greeting to the player, using the playerName variable
	cout << "Welcome, " << playerName << ", soon to be hero of the realm!" << endl << endl;

	// WHILE exit is false...
	while (!exit)
	{
		// DISPLAY the name of the room where the player currently is, using the roomNames vector and roomIndex
		cout << "You find yourself in the " << roomNames[roomIndex] << " - ";

		// DISPLAY the description of the room where the player currently is, using the roomDescs vector and roomIndex
		cout << roomDescs[roomIndex] << endl << endl;

		// DISPLAY the player's current stamina, using the playerStamina variable
		cout << "Stamina remaining: " << playerStamina << endl;

		// DISPLAY a message asking the player where they want to go
		cout << "Where would you like to go? (type the number)" << endl;
		cout << "Exits are:" << endl;

		// FOR each room in the roomNames vector...
		for (unsigned int i = 0; i < roomNames.size(); ++i)
		{
			// DISPLAY the loop index + 1 and the name of the room at that index
			cout << (i+1) << ".   " << roomNames[i] << endl;
		}
		// END FOR

		// DISPLAY a final option to quit, numbered equal to the size of roomNames+1
		cout << (roomNames.size() + 1) << ".   " << "QUIT" << endl;


		// READ the player's response into the playerChoice variable
		cin >> playerChoice;

		// IF the player's choice between 1 and the roomNames vector size...
		if (playerChoice >= 1 && playerChoice <= roomNames.size())
		{
			// SET the new roomIndex to be the player's choice minus one
			roomIndex = playerChoice - 1;

			// SUBTRACT the stamina required to move from the player's stamina value
			playerStamina = playerStamina - moveCost;

			// DISPLAY a message that the player has moved and used moveCost stamina
			cout << "You have changed rooms and used " << moveCost << " stamina." << endl;
		}
		// ELSE IF the player's choice is equal to the size of the room vector...
		else if (playerChoice == roomNames.size()+1)
		{
			// DISPLAY a goodbye message to the player
			cout << "Thank you for playing!" << endl;

			// SET exit to true
			exit = true;
		}
		// ELSE 
		else
		{
			// DISPLAY an error message due to unrecognised input
			cout << "Sorry, the number you typed was not one of the options: " << playerChoice << endl;
		}
		// END IF

		// IF the player stamina reaches 0 or lower...
		if (playerStamina <= 0)
		{
			// DISPLAY a message to the player telling them they have died
			cout << "You have run out of stamina and died! Better luck next time. Please play again!" << endl;

			// SET exit to true
			exit = true;
		}
		// ENDIF

	}
	// END WHILE

}