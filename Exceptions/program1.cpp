#include<iostream>
#include<string>
using namespace std;



class Distance{
	int meters;
	double inches;
	
	
	public : 
	// Exception class
class error{
	public : 
	int var1;
	
	error(int var1){
		this->var1 = var1;
	}
};
	Distance(int meters){
		this->meters = meters;
		if(this->meters<0)
		throw error(meters);
	}
	
	Distance(double inches){
		this->inches = inches;
		throw this->inches;
	}
	
	void display() const{
		cout<<"Distance : "<<meters<<endl;
	}
};

int main(){
	try{
		
		Distance d1(150);
		d1.display();
		
		
		Distance d2(-400);
		d2.display();
		
		
		
		Distance d3(5.567);
		d3.display();
	}
	catch(int err){
		cout<<"Exception : Negative distance : "<<err<<" not allowed ."<<endl;
	}
	catch(double err){
		cout<<"Exception : Double distance : "<<err<<" not allowed ."<<endl;
	}
//	catch(error e){
//		cout<<"Object Exception : Negative distance "<<e.var1<<" not allowed : "<<endl;
//	}
	catch(Distance::error e){
		cout<<"Object Exception : Negative distance "<<e.var1<<" not allowed : "<<endl;
	}
	catch(...) // default catcher
	{
		cout<<"Unwanted error occured."<<endl;
	}
}
