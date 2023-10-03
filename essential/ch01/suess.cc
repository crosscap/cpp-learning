#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string user_name;
	bool next_seq = true;  // show next sequence?
	bool go_for_it = true; // user wants to guess?
	bool got_it = false;   // user guessed correctly?
	int num_tries = 0;     // number of tries per sequence
	int num_right = 0;
	const int seq_cnt = 6;
	const int seq_size = 6;
	vector<int> fibonacci = {1, 1, 2, 3, 5, 8}; // C++11 支持的语法
	vector<int> lucas = {1, 3, 4, 7, 11, 18};
	vector<int> pell = {1, 2, 5, 12, 29, 70};
	vector<int> triangular = {1, 3, 6, 10, 15, 21};
	vector<int> square = {1, 4, 9, 16, 25, 36};
	vector<int> pentagonal = {1, 5, 12, 22, 35, 51};
	vector<int> *seq_addrs[seq_cnt] = {
		&fibonacci,
		&lucas,
		&pell,
		&triangular,
		&square,
		&pentagonal,
	};
	vector<string> seq_names = {
		"fibonacci",
		"lucas",
		"pell",
		"triangular",
		"square",
		"pentagonal",
	};
	string seq_name;
	vector<int> *current_vec = nullptr;
	int next_elem;
	int seq_index, cur_tuple = 0;

	cout << "Please enter your first name: ";
	cin >> user_name;

	while (next_seq == true) {
		srand(seq_cnt);
		seq_index = rand() % seq_cnt;
		current_vec = seq_addrs[seq_index];
		cout << "The first two elements of the sequence are: "
			 << (*current_vec)[cur_tuple]
			 << " "
			 << (*current_vec)[cur_tuple + 1]
			 << "\nWhat is the next element?\n";
		next_elem = (*current_vec)[cur_tuple + 2];
		seq_name = seq_names[seq_index];
		while ((got_it == false) && (go_for_it == true)) {
			unsigned int usr_guess;
			cin >> usr_guess;
			++num_tries;
			if (usr_guess == next_elem) {
				cout << "Very good, yes "
					 << next_elem
					 << " is the next element in the "
					 << seq_name
					 << "."
					 << endl;
				++num_right;
				got_it = true;
			} else {
				switch (num_tries) {
				case 1:
					cout << "Oops! Nice guess but not quite it.\n";
					break;
				case 2:
					cout << "Hmm. Sorry. Wrong a second time.\n";
					break;
				case 3:
					cout << "Ah, this is hader than it looks, isn't it?\n";
					break;
				default:
					cout << "It must be getting pretty frustarting by now!\n";
					break;
				}
				cout << " Would you like to try again? (y/n) ";

				char usr_rsp;
				cin >> usr_rsp;
				if (usr_rsp == 'N' || usr_rsp == 'n')
					go_for_it = false;
				else {
					cout << "Your next guess? ";
				}
			}
		}

		cout << "Want to try another sequence? (y/n) ";
		char try_again;
		cin >> try_again;
		if (try_again == 'N' || try_again == 'n')
			next_seq = false;
		else {
			got_it = false;
		}
	}

	return 0;
}
