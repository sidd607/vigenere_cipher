//Author : Siddartha Sekhar
//email : SiddarthaSekhar.Padhi@iiitb.org
//version 1.0.1
//date : 13-02-2014



//Cipher.cc
#include "Cipher.h"

Cipher::Cipher(){}

Cipher::Cipher(std::string inp_message, std::string inp_key) : message(inp_message), key(inp_key) {}

std::string Cipher::generateKey(){
	int msg_size = message.size();
	int key_size = key.size();
	std::string temp;
	int loop = msg_size/key_size;
	int rem = msg_size%key_size;
	for(int i=0 ; i<loop; i++)
		temp = temp + key;
	for(int i = 0; i < rem ; i++)
		temp = temp + key[i];
	return temp;
}

std::string Cipher::encrypt(){
	//SPace is 32
	std::string cipher_key = generateKey();
	std::string cipher_text;
	//std::cout << "KEY : "<< cipher_key << "\n";
	for(int i=0; i < message.size(); i++){
		//std::cout << int(message[i]) - 65 << " " <<int(cipher_key[i]) -65<<"\n";
		cipher_text = cipher_text + char(((int(message[i]) + int(cipher_key[i]) - 130) % 26) + 65);
		//std::cout << cipher_text << "\n";
	}

	encrypted_text = cipher_text;
	//std::cout << encrypted_text;
	return encrypted_text;

}

std::string Cipher::decrypt(){
	std::string cipher_key = generateKey();
	std::string decrypt_message ;

	
	for(int i = 0; i < cipher_key.size(); i++){

		int temp2 = int(encrypted_text[i]) - int(cipher_key[i]);
		if(temp2 < 0)
			temp2 = 26 + temp2;
		int temp = ( temp2 % 26) + 65;
		decrypt_message = decrypt_message + char(temp);
	}

	return decrypt_message;

}

std::string Cipher::decrypt(std::string inp_message, std::string inp_key){	
	std::string cipher_key;

	int msg_size = inp_message.size();
	int key_size = inp_key.size();
	std::string temp1;
	int loop = msg_size/key_size;
	int rem = msg_size%key_size;
	for(int i=0 ; i<loop; i++)
		temp1 = temp1 + key;
	for(int i = 0; i < rem ; i++)
		temp1 = temp1 + key[i];
	cipher_key = temp1;
	std::string decrypt_message ;
	for(int i = 0; i < cipher_key.size(); i++){
		int temp2 = int(inp_message[i]) - int(cipher_key[i]);
		if(temp2 < 0)
			temp2 = 26 + temp2;
		int temp = ( temp2 % 26) + 65;	
		decrypt_message = decrypt_message + char(temp);
	}

	return decrypt_message;

}