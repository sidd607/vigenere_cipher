//Author : Siddartha Sekhar
//email : SiddarthaSekhar.Padhi@iiitb.org
//version 1.0.1
//date : 13-02-2014



// Cipher.h
#include <string>
#include <iostream>

class Cipher
{
	std::string key;
	std::string message;
	std::string encrypted_text;


public:
	Cipher();
	Cipher(std::string message, std::string key);
	std::string generateKey();
	std::string encrypt();
	std::string decrypt();
	std::string decrypt(std::string inp_message, std::string inp_key);

	//~Cipher();
	
};