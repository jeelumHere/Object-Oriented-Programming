// Question #3:	(Approximate time to solve: 25min)				(Covering CLO: 2)          08 Marks
// Design and implement the energy efficient system to reduce electricity expense at Arid Agriculture University Rawalpindi and monitoring these three SmartDevice  i.e. SmartLight, SmartFan, and SmartThermostat. All the parent and child classes should have the functionality of turnOn(), turnOff(), and getStatus(). Using the base class pointer you have to call the own functions of each device separately. Also draw the class hierarchy for these devices and mention important points in each class.


#include<iostream>
#include<cstring>
using namespace std;

class SmartDevice{

    protected: 
    string status;
    public : 
    void virtual turnOn() = 0;
    void virtual turnOff() = 0;
    void virtual getStatus() = 0;

};

class SmartLight : public SmartDevice{
    public : 
    void turnOn() override {
        status = "On" ;
        cout<<"<<<<<------>>>>>"<<endl;
        cout<<"<<<Turning on light>>>>>"<<endl;

    }
    void turnOff() override {
        status = "Off" ;
        cout<<"<<<<<------>>>>>"<<endl;
        cout<<"<<<Turning off light>>>>>"<<endl;
    }
    void getStatus() override {
        cout<<"Status : "<< status<<endl;
    }
};
class SmartFan : public SmartDevice{
    public : 

    void turnOn() override {
        status = "On" ;
        cout<<"<<<<<------>>>>>"<<endl;
        cout<<"<<<Turning on Fan>>>>>"<<endl;

    }
    void turnOff() override {
        status = "Off" ;
        cout<<"<<<<<------>>>>>"<<endl;
        cout<<"<<<Turning off Fan>>>>>"<<endl;
    }
    void getStatus() override {
        cout<<"Status : "<< status<<endl;
    }
};
class SmartThermoStat : public SmartDevice{
    public : 

    void turnOn() override {
        status = "On" ;
        cout<<"<<<<<------>>>>>"<<endl;
        cout<<"<<<Turning on ThermoStat>>>>>"<<endl;
    }
    void turnOff() override {
        status = "Off" ;
        cout<<"<<<<<------>>>>>"<<endl;
        cout<<"<<<Turning off ThermoStat>>>>>"<<endl;
    }
    void getStatus() override {
        cout<<"Status : "<< status<<endl;
    }
};

int main(){
    SmartDevice *smDev;
    SmartLight smL;
    SmartFan smf;
    SmartThermoStat smt;
    smDev = &smL;
    smDev->turnOff();
    smDev->turnOn();
    smDev->getStatus();
    smDev = &smf;
    smDev->turnOff();
    smDev->turnOn();
    smDev->getStatus();
    smDev = &smt;
    smDev->turnOff();
    smDev->turnOn();
    smDev->getStatus();
}