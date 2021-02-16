#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h> 

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() { }
    Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }

    void printDate(){
      std::cout << "" << day << "/";
      std::cout << "" << month << "/";
      std::cout << "" << year << "\n";
  }
};

class Blood{
  public:
    int systolic;
    int diastolic;
    Date dat;

    Blood(int sys, int dia, Date dat): systolic(sys), diastolic(dia), dat(dat){
    
  } 

  void printBlood() {
    dat.printDate();

    std::cout<<"Systolic pressure:  "<<systolic<<"\n";
    std::cout<<"Diastolic pressure: "<<diastolic<<"\n";
  }

  int getSystolic(){
      return systolic;
  }

  int getDiastolic(){
    return diastolic;
  }

};

class Patient {
  private:
    std::string name;
    std::vector <Blood> vect;

  public:
    Patient(std::string n){
      name = n;
    }

    void addRecord(Blood k){
      vect.push_back(k);
    }
    
    void printReport() {
      int j=0, maxSystolic = 0;
      double avg= 0;
      std::vector<Blood> maxPressures;
      std::cout << "Report of: "<< name << std::endl; 
      for(int i=0;i<vect.size();i++){

        avg+=vect[i].getDiastolic();

        if(vect[i].getSystolic() > maxSystolic){
          maxPressures.clear();
          maxPressures.push_back(vect[i]);
          maxSystolic = vect[i].getSystolic();
        
        } else if(vect[i].getSystolic() == maxSystolic) {
          maxPressures.push_back(vect[i]);
        
        }
        

        if(vect[i].getSystolic()>140){
          std::cout<<"The systolic pressure was high that day:  \n";
          vect[i].printBlood();
          std::cout << "" << std::endl;
          j++;
        }
      }
    for(int i = 0; i < maxPressures.size(); i++){
      std::cout << "Highest measurement(s): " <<"\n";
      maxPressures[i].printBlood();
      std::cout << "" << std::endl;
    }
    avg=avg/vect.size();
    std::cout<<"The average diastolic pressure is: " << avg <<"\n";
    std::cout << "" << std::endl;
    if(j==0){
        std::cout<< "No measurement was not too high" <<"\n";
        std::cout << "" << std::endl;
    }
  }
};

int main() {
  Patient mary("Mary");
    mary.addRecord(Blood(94,61, Date(2,5,2013)));
    mary.addRecord(Blood(97,65, Date(3,5,2013)));
    mary.addRecord(Blood(144,99, Date(4,5,2013)));
    mary.addRecord(Blood(123,88, Date(5,5,2013)));
    mary.addRecord(Blood(177,110, Date(6,5,2013)));
    mary.addRecord(Blood(145,89, Date(7,5,2013)));
    mary.printReport();

  Patient john("John");
    john.addRecord(Blood(88,57, Date(15,5,2013)));
    john.addRecord(Blood(95,61, Date(16,5,2013)));
    john.addRecord(Blood(114,80, Date(17,5,2013)));
    john.addRecord(Blood(151,96, Date(18,5,2013)));
    john.addRecord(Blood(176,104, Date(19,5,2013)));
    john.addRecord(Blood(176,110, Date(20,5,2013)));
    john.printReport();

  Patient hugo("Hugo");
    hugo.addRecord(Blood(88,250, Date(15,5,2013)));
    hugo.addRecord(Blood(95,200, Date(16,5,2013)));
    hugo.addRecord(Blood(114,80, Date(17,5,2013)));
    hugo.addRecord(Blood(120,96, Date(18,5,2013)));
    hugo.addRecord(Blood(105,104, Date(19,5,2013)));
    hugo.addRecord(Blood(99,110, Date(20,5,2013)));
    hugo.printReport();

  Patient pauline("Pauline");
    pauline.addRecord(Blood(110,120, Date(31,12,2018)));
    pauline.addRecord(Blood(110,95, Date(05,7,2019)));
    pauline.addRecord(Blood(170,120, Date(19,2,2020)));
    pauline.addRecord(Blood(130,105, Date(18,3,2020)));
    pauline.addRecord(Blood(101,104, Date(25,5,2020)));
    pauline.addRecord(Blood(168,110, Date(30,5,2020)));
    pauline.printReport();
    return 0;
}