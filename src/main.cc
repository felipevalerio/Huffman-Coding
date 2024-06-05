#include <iostream>
using namespace std;

struct Node{
	int frequency;
	char letter;

	struct Node* right;
	struct Node* left;
};


Node *empty_node(int frequency, char letter) {

	Node *root_node = (Node *)malloc(sizeof(Node));
	root_node->frequency = frequency;
	root_node->letter = letter;
	root_node->left = NULL;
	root_node->right = NULL;

	return root_node;
}

Node *insert(Node *root_node, int frequency, char letter) {

	if (root_node == NULL) { return empty_node(frequency, letter); } 
	
	if (frequency < root_node->frequency) {
			root_node->left = insert(root_node->left, frequency, letter);
	} else {
			root_node->right = insert(root_node->right, frequency, letter);
	}
	
	return root_node;
}


int main() {
	// just a sentence to start, later on it will be a text file
	string sentence = "o rato roeu a roupa do rei de roma";
	auto count = 0;

	// string to array of char
	auto length = sentence.length();
	char* char_sentence = new char[length + 1];

	//copying the content of sentence to char_sentence
	strcpy(char_sentence, sentence.c_str());

	for (auto i = 0; i < length; i++) {
		for (auto j = 0; j < length; j++)
			if (char_sentence[i] == char_sentence[j]) {
				std::cout << "Sequencia encontrada: " << char_sentence[i] << " => " << char_sentence[j] << std::endl;
				count = count + 1;
				// empty_node(count, char_sentence[i]);
			} else {
				std::cout << "Somente uma ocorrencia: " << char_sentence[i] << " => " << char_sentence[j] << std::endl;
				// empty_node(0, char_sentence[i]);
			}
	}

	return 0;
}