// This is a code for simple bus reservation system

#include <iostream>
#include <string.h>
#include <stdio.h>

int p = 0; // p is the number of buses in the system

using namespace std;

class Bus
{
private:
    char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:
    void addNewBus();
    void reserveSeat();
    void empty();
    void showReservedBusSeats(int n);
    void showAvailableBus();

} bus[25]; // 25 buses in the system

void Bus::addNewBus()
{
    cout << "\t\t\tEnter the Bus Number: ";
    cin >> bus[p].busn;
    cout << "\t\t\tEnter the Driver's Name: ";
    cin >> bus[p].driver;
    cout << "\t\t\tEnter the Arrival Time: ";
    cin >> bus[p].arrival;
    cout << "\t\t\tEnter the Departure Time: ";
    cin >> bus[p].depart;
    cout << "\t\t---------------------------------------------\n";
    cout << "\t\t\tForm: ";
    cin >> bus[p].from;
    cout << endl;
    cout << "\t\t\tTo: ";
    cin >> bus[p].to;

    bus[p].empty(); // calling empty function to make all seats empty
    p++;            // incrementing the number of buses in the system
    cout << "\t\t\tBus Added Successfully...." << endl;
    system("pause");
}

void Bus::reserveSeat()
{
    int seat;
    char number[5];

top:
    cout << "\t\tEnter the Bus Number in which you want to reservation: ";
    cin >> number;
    int n;
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0) // comparing the bus number entered by the user with the bus number in the system
            break;
    }
    while (n <= p)
    {
        cout << "\t\tEnter the Seat Number: ";
        cin >> seat;
        if (seat > 32)
        {
            cout << "\t\tThere are only 32 seats available in this bus." << endl;
        }
        else
        {
            if (strcmp(bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0)
            {
                cout << "\t\tEnter the Passenger's Name: ";
                cin >> bus[n].seat[seat / 4][(seat % 4) - 1];
                cout << "\t\t---------------------------------------------\n";
                cout << "\t\t\tThe seat number " << seat << " is reserved for " << bus[n].seat[seat / 4][(seat % 4) - 1] << "." << endl;
                break;
            }
            else
            {
                cout << "\t\tThe seat number is already reserved." << endl;
            }
        }
    }
    if (n > p)
    {
        cout << "\t\tEnter the correct Bus Number." << endl;
        goto top;
    }
}

void Bus::empty()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            strcpy(bus[p].seat[i][j], "Empty");
        }
    }
}

void Bus::showAvailableBus()
{
    int n;
    char number[5];
    cout << "\t\tEnter the Bus Number: ";
    cin >> number;
    system("cls");
    // comparing the bus number entered by the user with the bus number in the system
    for (n = 0; n <= p; n++)
    {
        if (strcmp(bus[n].busn, number) == 0)
        {
            break;
        }
    }
    while (n <= p)
    {
        cout << "\t\tBus Number: " << bus[n].busn << endl;
        cout << "\t\tArival Time: " << bus[n].arrival << endl;
        cout << "\t\tDeparture Time: " << bus[n].depart << endl;
        cout << "\t---------------------------------------------\n";
        cout << "\t\tFrom: " << bus[n].from << "\t\tTo: " << bus[n].to << endl;

        bus[0].showReservedBusSeats(n);

        int a = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                a++;
                if (strcmp(bus[n].seat[i][j], "Empty") != 0)
                    
                    cout << "\t\tThe seat number " << (a - 1) << " is reserved for " << bus[n].seat[i][j] << "." << endl;
            }
        }
        break;
    }
    if (n > p)
    {
        cout << "\t\tEnter the correct Bus Number." << endl;
    }
}

void Bus::showReservedBusSeats(int n)
{
    // hels to create a table output for the seats and reserved seats with the passenger's name

    int s = 0, h = 0;
    for (int i = 0; i < 8; i++)
    {
        
        for (int j = 0; j < 4; j++)
        {
            s++;
            if (strcmp(bus[n].seat[i][j], "Empty") == 0)
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[n].seat[i][j];
                h++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << bus[n].seat[i][j];
            }
        }
    }
    cout << "\t\t" << endl;
    cout << "\t\t---------------------------------------------\n";
    cout << "\t\t Theere are " << h << " seats available in the bus No : " << bus[n].busn << endl;
}

int main()
{
    
    int choice;
    while (1)
    {
         system("cls");
        cout << "\t\t---------------------------------------------\n";
        cout << "\t\t\tWelcome to Bus Reservation System." << endl;
        cout << "\t\t---------------------------------------------\n";
        cout << "\t\t\t1. Add New Bus." << endl;
        cout << "\t\t\t2. Reserve Seat." << endl;
        cout << "\t\t\t3. Show all seats available in a Bus" << endl;
        cout << "\t\t\t4. All Buses in the system." << endl;
        cout << "\t\t\t5. Exit." << endl;
        cout << "\t\t---------------------------------------------\n";
        cout << "\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bus[p].addNewBus();
            break;
        case 2:
            bus[p].reserveSeat();
            break;
        case 3:
            bus[p].showAvailableBus();
            break;
        case 5:
            cout << "\t\t\tThank you for using our system." << endl
                 << "\t\t\tHave a nice day." << endl;
            break;
            exit(0);
        }
    }
    return 0;
}