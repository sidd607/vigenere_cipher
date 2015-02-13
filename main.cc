//Author : Siddartha Sekhar
//email : SiddarthaSekhar.Padhi@iiitb.org
//version 1.0.1
//date : 13-02-2014



#include "Cipher.h"

#include <iostream>
#include <string>

using namespace std;

int main(){

	string message, key;
	cout << "Enter the message : ";
	getline(cin, message);
	cout << "Enter a key: ";
	cin >> key;

	Cipher vigenere(message, key); //creating object for the vigenere cipher class
	
	std::cout << "ENCRYPTED TEXT: " << vigenere.encrypt() << std::endl; // encrypting the message
	
	std::cout << "DECRYPTED TEXT: " << vigenere.decrypt() << std::endl; // decrypting the message

	//standalone decryption by just inputinf the cipher text and a key

	std::cout << vigenere.decrypt("LXFOPVEFRNHR", "LEMON");

	//std::cout << "GOODBYE" << std::endl;
}