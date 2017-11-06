#include <iostream>
#include <string>
using namespace std;
enum class months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

struct Wrong_Day {};
struct Wrong_Month {};

bool leap_control(const unsigned int y); //control if a year is leap
void is_leap (const unsigned int y); // tells us if the year is leap
unsigned int set_threshold (const unsigned int month, const unsigned int y); // sets the threshold for the day in the date

class Date {
  unsigned int _day;
  unsigned _month;
  unsigned int _year;
  
  public:
 // Date ();
  Date(unsigned int day, unsigned int month, unsigned int year) : _day{day}, _month{month}, _year{year} {
        unsigned int threshold { set_threshold (_month, _year)};
        if (_month >= 13 || month == 0)
        throw Wrong_Month {};
        if(_day > threshold || _day == 0)
        throw Wrong_Day {};
        }

  //~Date() {}
  unsigned int day() const { return _day; }
  unsigned int year() const { return _year; }
  unsigned int month() const { return _month; }
  void add_day(const unsigned int n); // prints the expected date 
  
};

void Date::add_day(const unsigned int n){
    
    unsigned int new_day { _day + n};
    unsigned int new_month { _month};  //new variables in order not to loose the current date 
    unsigned int new_year = {_year};
    unsigned int threshold{28};

    while (new_day > threshold){
        unsigned int threshold {set_threshold (new_month, new_year)};
        if(new_day <= threshold){
        break;
        }
        new_day = new_day - threshold;
        if (new_month == 12){
            new_month = 1;
            new_year = new_year + 1;
        }
        else{
            new_month = new_month + 1;
        }
  }
    cout << "In " << n << " days the date will be: " << new_day << " " << new_month << " " << new_year << endl;
} 

// HELPER FUNCTIONS

bool leap_control(const unsigned int y){
    if ( (y%4 == 0) && (y%100 != 0)){
        return true ;
    }
    else if (y%400 == 0){
        return true;
    }
    else{
        return false;
    }
}

void is_leap(const unsigned int y){
    bool control = leap_control(y);
    if (control == true){
        cout << y << " is leap" << endl;;
    }
    else{
        cout << y << " is NOT leap" << endl;;
    }
}

unsigned int set_threshold (const unsigned int month, const unsigned int y){
    bool control = leap_control(y);
      unsigned int threshold;
      if ((month == 2) && (control == false)){
            threshold = 28;
            }
        else if ((month == 2) && (control == true)){
            threshold = 29;
            }
        else if((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
            threshold = 30;
            }
        else {  
            threshold = 31;
            }
        return threshold;
}

// OPERATORS

bool operator==(const Date& lhs, const Date& rhs){
    if ((lhs.day() == rhs.day()) && (lhs.month() == rhs.month()) && (lhs.year() == rhs.year()) ){
    return true;
    }
    else{
    return false;
    }
    };

bool operator!=(const Date& lhs, const Date& rhs){
return !(lhs == rhs);
    };
    
std::ostream& operator<<(std::ostream& os, const Date& d){
 return os << d.day() << "/" << d.month() << "/" << d.year() << endl; 
}

int main(){
    try{
    months oct = months::oct;
    Date date (23, int(oct), 2017);
    cout << date.day() << endl;
    cout << date.month() << endl;
    cout << date.year() << endl;
    date.add_day(465); // expected 31/1/2019
    is_leap(1992); // expected is leap
    is_leap(date.year()); // expected not leap
    Date other_date(22, int(oct), 2017);
    if(date == other_date){
        cout << "The two dates are the same!" << endl;
    }
    else{
        cout << "They are two different dates!" <<endl;
        } //expected "They are two different dates!"
    if(date != other_date){
        cout << "They are two different dates!"  << endl;
    }
    else{
        cout << "The two dates are the same!" <<endl;
        } // expected "They are two different dates!"
    std::cout << date << other_date;


return 0;
}
catch (const Wrong_Day) {
    cerr << "Day out of range" <<endl;
    return 1;
}
catch (const Wrong_Month) {
    cerr << "Month out of range" <<endl;
    return 2;
}
}
