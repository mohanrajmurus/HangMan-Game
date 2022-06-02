#include <iostream>
#include <string>
#include <ctime> //random number generation
using namespace std;
int Letterfill(char guess, string sect_word,string &guessword);
//Hangman diagram
void drawing(int draw) 
{
	if(draw == 5)
		cout << "\t _________\n\t|\t |\n\t|\t 0\n\t|\t/|\\\n\t|\t |\n\t|\t/ \\\n\t|__\n";
	else if(draw == 4)
			cout << "\t _________\n\t|\t |\n\t|\t  \n\t|\t    \n\t|\t  \n\t|\t    \n\t|__\n";
	else if(draw == 3)
			cout << "\t _________\n\t|\t |\n\t|\t 0\n\t|\t    \n\t|\t  \n\t|\t    \n\t|__\n";
	else if(draw == 2)
			cout << "\t _________\n\t|\t |\n\t|\t 0\n\t|\t |  \n\t|\t |\n\t|\t    \n\t|__\n";
	else if(draw == 1)
			cout << "\t _________\n\t|\t |\n\t|\t 0\n\t|\t/|\\\n\t|\t |\n\t|\t   \n\t|__\n";
	else if(draw == 0)
			cout << "\t _________\n\t|\t |\n\t|\t 0\n\t|\t/|\\\n\t|\t |\n\t|\t/ \\\n\t|__\n";
}


int main()
{
	char op;//menu choice
	do
	{
		srand(time(NULL));
		int tries = 5;
		string words[] = {"trisha","shruti","keerthy","regina","induja","priyamani","andrea","samantha","nayanthara","anushka"};
		int random_word;
		random_word = rand()%10; //random number generated
		string the_word = words[random_word];
		string unknown(the_word.length(), '-');
		cout << "\t\t\t ***************************";
		cout << "\n\t\t\t * WELCOME TO HANGMAN GAME *\n";
		cout << "\t\t\t ***************************\n";
		drawing(tries);
		cout << "\nLets Start the Game\n";
		cout << "\nThe word list contains south-indian actress names\n";
		cout << "\nRandom word has been generated! Word is " << the_word.length() << " letters long!" << endl;
		while(tries > 0)
		{
			cout << unknown << "\n";
			char letter;
			cout << "Enter the guessing word: ";
			cin >> letter;
			if(Letterfill(letter,the_word,unknown) == 0)
			{
				tries--;
				if(tries != 0)
				{
					drawing(tries);
					cout << "Wrong selection. try again\n";
				}
			}
			else
			{
				cout << "Found letter! " << endl;
			}
			if(tries != 0)
				cout << "Guess a letter, you have " << tries << " left." << endl;
			if (the_word == unknown)
			{
				cout << the_word << endl;
				cout << "Yeah! You won the game!\n";
				return 0;
			}
		}
		cout << endl << "Sorry, you lose...you've been hanged." << endl;
		drawing(tries);
		cout << "The word was : " << the_word << endl;
		cout <<"\n Do you want play again?[y/n]";
		cin >> op;
	}while(op == 'y'||op == 'Y');
	
}
int Letterfill(char guess, string sect_word,string &guessword)
{
	int matches = 0;
	int len = sect_word.length();
	for(int i = 0; i < len; i++)
	{
		if(guess == guessword[i])
			return 0;
		if(guess == sect_word[i])
		{
			matches++;
			guessword[i] = guess;
		}
	}
	return matches;
}