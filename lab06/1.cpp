#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Car{

            //private members
      private:
             string type, model;
             int year, power, maxSpeed;
             bool isMoving, isTurnedOn, safetyBelt;
             //state members
             int speed = 0;
           //public mambers
      public:
          //set functions
             void setYear(int);
       	     void setPower(int);
       	     void setMaxSpeed(int);
       	     void settype(string);
       	     void setModel(string);

             void setSafety(bool);
             void start(bool);
             void accelerate(int);
        	 void brake(int);
        	 void stop(bool);

        	 void currentSpeed();
        	 void displayInfo();
};

void Car::setYear(int y)
{
    if(y<2017)
     year = y;
}
void Car::setPower(int p)
{
     power = p;
}
void Car::setMaxSpeed(int y)
{
     maxSpeed = y;
}
void Car::settype(string y)
{
     type = y;
}
void Car::setModel(string e)
{
     model = e;
}
void Car::setSafety(bool a)
{
    if(a) safetyBelt = 1;
    else safetyBelt =0;
}
void Car::start(bool a)
{
    if(safetyBelt){
        isTurnedOn = 1;
        cout << "Car has started" << endl;}
    else
        cout << "Please use your safety belt" << endl;
}
void Car::accelerate(int a)
{
    if((isTurnedOn)&&(a>0)&&(a<maxSpeed))
    {
        speed = a;
        cout << "speed is now: " << speed << endl;
    }
    else
        cout << "start the car" << endl;
}
void Car::brake(int a)
{
    if(speed < a)
        cout << "Enter correct number that is lower than real speed"<< endl;
    if(speed > a)
    {
        speed -= a;
        cout << "speed is now: " << speed << endl;
    }
    else
        cout << "Car is already not moving" << endl;
}
void Car::stop(bool a)
{
    if((isTurnedOn)&&(speed == 0))
    {

        cout << "Turning off" << endl;
        isTurnedOn = 0;
    }
}
void Car::currentSpeed()
{
    cout << "Speed is " << speed << "kmph at the moment" << endl;
}

void Car::displayInfo()
{
     cout << "This car is a : " <<type;
     cout<<endl;
     cout << "The car's model is : " <<model;
     cout<<endl;
     cout << "The car was made in : " <<year;
     cout<<endl;
     cout << "The car has power of  : " <<power << "W and can speed up to " << maxSpeed;
     cout<<endl;
}

int main()
{
    Car honda;
    honda.setModel("ICX2");
    honda.setMaxSpeed(200);
    honda.setPower(3000);
    honda.settype("SUV");
    honda.setYear(1990);
    honda.setSafety(1);
    honda.start(1);
    honda.accelerate(20);
    honda.accelerate(30);
    honda.brake(50);
    honda.stop();
    honda.displayInfo();
   return 0;
}
