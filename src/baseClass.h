#pragma once
#include "aslPoliDebugger.h"
class baseClass{
public:
	virtual ~baseClass(){
	}
	
	virtual void setup(){
	}
	
	virtual void update(){
	}
		
	virtual void draw(){
	}
	
	virtual void drive(){
	}
	
	virtual operator std::string(){
		return this -> name();
	}
	
private: 
	virtual std::string name(){
		return asl::easyTypename(*this);
	}
};


