// TODO: add file header comments here
//Milestone 2
//Assignment Submission
//hahmad20@myseneca.ca
//Haasher Ahmad
//OOP244SFG
//136588167
//03/11/2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace ama{
	ErrorState::ErrorState(const char* errorStateMessage){
		if(errorStateMessage == nullptr){
			messages = nullptr;
		}else if(errorStateMessage[0] == '\0'){
			messages = nullptr;
		}else{
			messages = new char[strlen(errorStateMessage) + 1];
			strcpy(messages, errorStateMessage);
		}
	}

	ErrorState::~ErrorState(){
		//deallocates memory that has been dynamically allocated by the current object
		delete messages;
	}

	ErrorState::operator bool() const{
		bool valid;
		//returns true/false if message object is empty
		if(isEmpty()){
			valid = false;
		}else{
			valid = true;
		}
		return valid;
	}

	void ErrorState::message(const char* pText){
		if(pText == nullptr || pText[0] == '\0'){
			messages = nullptr;
		}else{
			//stores a copy the text received in the parameter
			delete messages;
			messages = new char[strlen(pText) + 1];
			strcpy(messages, pText);
		}
	}

	ErrorState& ErrorState::operator=(const char* pText){
		//stores a copy the text received in the parameter
		message(pText);
		return *this;
	}

	const char* ErrorState::message() const{
		//returns address of the message stored in current object
		return messages;
	}

	bool ErrorState::isEmpty() const{
		bool valid;
		//returns true/false if message object is empty
		if(messages == nullptr || messages[0] == '\0'){
			valid = true;
		}else{
			valid = false;
		}
		return valid;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorState& es){
		if (!es.isEmpty()){
			//displays messages stored in message object
			os << es.message();
		}
		return os;
	}
}