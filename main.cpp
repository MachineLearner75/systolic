#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Date {
protected:
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

    std::cout<<"Systolic pressure is: "<<systolic<<"\n";
    std::cout<<"Diastolic pressure is: "<<diastolic<<"\n";
  }

  int getSystolic(){
      return systolic;
  }

  int getDiastolic(){
    return diastolic;
  }

};

class Patient {
  protected:
    std::string name;
    std::vector <Blood> vect_normal;
    std::vector <Blood> vect_abnormal;
    float avg;

  public:
    Patient(std::string n){
      name = n;
    }

    void addRecord(Blood k){
      vect_normal.push_back(k);
      if(k.systolic>140){
        vect_abnormal.push_back(k);
      }
    }

    std::vector <Blood> vect_maxsystolic(){
      int maxsys = 0;
      std::vector<Blood> sub_maxsystolic;

      for(std::vector<Blood>::const_iterator it = vect_abnormal.begin(); it != vect_abnormal.end(); ++it){
        
      }

    }

    void printReport() {
      //the highest abnormal systolic blood pressures, together with the corresponding diastolic value, and the day it has been measured;
      int j=0;
      double avg= 0;
      std::cout << "Report of: "<< name << std::endl; 
      for(int i=0;i<vect.size();i++){
        avg+=vect[i].getDiastolic();
        if(vect[i].getSystolic()>140){
          std::cout<<"The systolic pressure was high this day: \n";
          vect[i].printBlood();
          j++;
        }
      }
    avg=avg/vect.size();
    std::cout<<"The average diastolic pressure is : " << avg <<"\n";
    if(j==0){
        std::cout<< "No measurement was not too high";
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
    return 0;
}