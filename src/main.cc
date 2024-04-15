#include <iostream>
using namespace std;

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
				std::cout << "Encontrei uma segunda ocorrencia" << std::endl;
			} else {
				std::cout << "Somente uma ocorrencia" << std::endl;
			}
	}

	return 0;
}