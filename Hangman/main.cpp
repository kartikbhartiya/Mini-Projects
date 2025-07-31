#include "wordlists.h"
using namespace std;
#include <ctime>
#include <cstdlib>
#include <vector>

int chances = 7;

class fun {
public:
	fun() {
		 exists = "";
	}
	string guess;
	int input(string word) {
		cout << chances << " chances left , Please Enter your Guess:- ";
		cin >> guess;
		for (int i = 0; i < guess.size(); i++) {
			guess[i] = tolower(guess[i]);
		}
		if (guess.size() != word.size()) {
			cout << "(Error) the size of word and your guess is not same"<< endl;
			input(word);
		}
		else {
			chances--;
		}
		if (guess == word) return 1;
		return 0; // Added return to avoid warning
	}
	vector<char> arr;
	string exists = "";
	int search(string word) {
		int pos1, pos2, temp = 0;
		for (int i = 0; i < word.size(); i++) {
			for (int j = 0; j < guess.size(); j++) {
				if (word[i] == guess[j]) {
					temp = 1;
					pos1 = i;
					pos2 = j;
					if (i == j) {
						arr.push_back(word[i]);
					}
					else {
						arr.push_back('_');
						exists = exists + word[i];
						exists = exists + ',';
					}
					break;
				}
				
			}
			if (temp == 0) arr.push_back('_');
			temp = 0;
		}
		return 0; // Added return to avoid warning
	}
	void display() {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
        if(exists!="") cout << " ,Correct Letters with Wrong position:- "<< exists;
        cout<<endl;
		exists = "";
		arr.clear();
	}
};

int main() {
	cout<<"Note:- Dont make a guess of word with repeated characters : Program may not work properly (All the answer are those words with no repitition)"<<endl;
	srand(time(0)); // Seed the random number generator
	string word = words[rand() % 192]; // Randomly select a word from the list
	cout << "The word format is :- ";
	for (int i = 0; i < word.size(); i++) {
		cout << "_ ";
	}
    cout<<endl;
	fun e; int temp = 0;
	while (chances != 0) {
		temp = e.input(word);
		if (temp == 1) {
			temp = 7;
			break;
		}
		e.search(word);
		e.display();
	}
	if (temp == 7) {
		cout << "Congrats!! You Guessed The Correct word in "<<chances<<" Attempt the correct word was" << word<<endl;
	}
	else {
		cout << "Better Luck Next Time! You Lost The correct word was "<<word<<endl;
	}
	int tp = 0;
	cout<<"Enter Any Thing To Exit:- ";
	cin>>tp;
	return 0; // Added return to avoid warning
}
