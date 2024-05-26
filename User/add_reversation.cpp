#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Reservation {
private:
    const string reservationFile = "reservations.txt";
    const int reservationYear = 2024; // Constant year for all reservations

public:
    bool isValidDate(int month, int day) {
        int days_in_month[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
        if (month < 1 || month > 12 || day < 1 || day > days_in_month[month]) {
            return false;
        }
        return true;
    }

    bool isValidTime(int hour, int minute) {
        return (hour >= 10 && hour < 20) && (minute >= 0 && minute <= 59);
    }

    bool isValidPhone(const string& phone) {
        return phone.length() == 10 && phone.substr(0, 2) == "01";
    }

    bool isValidPeople(int people) {
        return (people > 0 && people <7);
    }

    void addReservation() {
        string customerName, phone, reservationDateTime,Mename;
        int month, day, hour, minute, people, menuSelection;
        float price;

        cout << "\nWelcome to the Restaurant Reservation Page" << endl;
        cout << "============================================" << endl;
        cout << "\tMake Customer Reservation Here\t" << endl;
        cout << "============================================" << endl;

        cout << "Enter the customer name: ";
        getline(cin, customerName);

    while (true) {
        cout << "Enter the reservation date (MM DD): ";
        if (!(cin >> month >> day) || !isValidDate(month, day)) {
            cout << "Invalid date. Please enter a valid date within the specified limits.\n";
            cin.clear(); 
        } else {
            cout << "Enter the reservation time (HH MM) (10:00-20:00): ";
            if (!(cin >> hour >> minute) || !isValidTime(hour, minute)) {
                cout << "Invalid time. Please enter a valid time within the specified limits.\n";
                cin.clear();
            } else {
                break; 
            }
        }
    }


        cout << "Enter the number of customer coming to the restaurant (1-6): ";
        while (!(cin >> people) || !isValidPeople(people)) {
            cout << "Sorry, the maximum number of people is 6."<<endl;
            cout<<"Please enter a selection from 1 to 6: ";
            cin.clear();
            cin>>people;
        }

        cout << "Enter the customer phone number (must start with '01' and be 10 digits long): ";
        cin >> phone;
        while (!isValidPhone(phone)) {
            cout << "Invalid phone number. "<<endl;
            cout<<"Please enter a valid phone number: ";
            cin.clear();
            cin>>phone;
        }

        cout<<"=========================================================="<<endl;
        cout<<"\t Menu \t"<<endl;
        cout<<"=========================================================="<<endl;
        cout<<"1. Personal Set "<<endl;
        cout<<"Lamb Chop [1 pax] "<<endl;
        cout<<"RM 20.00\n"<<endl;
        cout<<"2. Love Set "<<endl;
        cout<<"Lobster, Lamb Chop [2 pax] "<<endl;
        cout<<"RM 30.00\n"<<endl;
        cout<< "3. Family Set "<<endl;
        cout<<"Lobster, Lamb Chop, 2 X Chicken Chop [4 pax] "<<endl;
        cout<<"RM 45.00\n"<<endl;
        cout << "4. Big Family Set "<<endl;
        cout<<"Lobster, 2 X Lamb Chop, 2 X Chicken Chop, Beef Steak [5 pax] "<<endl;
        cout<<"RM 60.00\n"<<endl;
        cout<<"5. Luxury Family Set "<<endl;
        cout<<"Lobster, 2 X Lamb Chop, 2 X Chicken Chop,2 X Beef Steak [6 pax] "<<endl;
        cout<<"RM 80.00\n"<<endl;
        cout<< "Please select customer's set (1-5): ";
        while (!(cin >> menuSelection) || menuSelection < 1 || menuSelection > 5) {
            cout << "Invalid selection, please try again.\n";
            cout << "Please select the right set (1-5): ";
            cin.clear();
        }

        switch(menuSelection) {
            case 1:
                price = 20.00;
                Mename = "Personal Set";
                break;
            case 2:
                price = 30.00;
                Mename = "Love Set";
                break;
            case 3:
                price = 45.00;
                Mename = "Family Set";
                break;
            case 4:
                price = 60.00;
                Mename = "Big Family Set";
                break;
            case 5:
                price = 80.00;
                Mename = "Luxury Family Set";
                break;
        }

        stringstream ss;
        ss << reservationYear << "-" << setw(2) << setfill('0') << month << "-" << setw(2) << day 
           << " " << setw(2) << hour << ":" << setw(2) << minute;
        reservationDateTime = ss.str();

        ofstream outFile(reservationFile, ios::app); 
        if (outFile.is_open()) {
            outFile << "\n---------------------------" << endl;
            outFile << "Customer Name : "<< customerName << endl;
            outFile <<"Reservation Date & Time " << reservationDateTime <<endl;
            outFile << "Number of People : " << people << endl;
            outFile <<"Phone Number : " << phone <<endl;
            outFile <<"Menu Option: " << Mename <<endl;
            outFile <<"Price : RM " << price << endl;
            outFile <<"---------------------------"<<endl;
            outFile.close();
            cout<< "\nReservation Added Successful!!!\n"<<endl;
            cout<<"======================="<<endl;
            cout<<"Reservation Details"<<endl;
            cout<<"======================="<<endl;
            cout << "Reservation made for " << customerName << " \nReservation Time: " << reservationDateTime <<"\nMenu Option :" << Mename << " - RM" << price << endl;
        } else {
            cout << "Error: Unable to open the reservation file." << endl;
        }
    }
};

int main() {
    Reservation reservation;
    reservation.addReservation();
    return 0;
}