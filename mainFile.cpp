#include <iostream>
#include <string>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <iomanip>

/*
 * Below header file has been included only for case conversions on strings.
 */

#include <algorithm>

/*
 * Below headers are only added for delay.
 */

#include <chrono>
#include <thread>

using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

/*
 * End delay headers.
 */

// To avoid using std::
using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;

#define TOTAL_CARS 4

// Base class
class DatabaseCar
{
protected:
    double maxSpeed;
    double mileage;
    double fuelCapacity;
    string fuelType;
    int year;
    string modelName;
    double odometerReading;
    double price;

public:
    // Calling below constructor with default values
    DatabaseCar()
        : DatabaseCar(0, 0, 0, "", 0, "", 0, 0) {}

    DatabaseCar(double mxSpeed, double mlg, double flCap, string flType,
                int yr, string name, double odoReading, double cost)
        : maxSpeed{mxSpeed}, mileage{mlg}, fuelCapacity{flCap}, fuelType{flType}, year{yr}, modelName{name}, odometerReading{odoReading}, price{cost} {}
};

class Luxury : protected DatabaseCar
{
    bool hasUmbrella;
    bool hasFridge;
    bool hasTV;
    double currentSunRoofOpacity;

public:
    // Class constructor calling base constructor (super in other languages)
    // and initializing its own variables.

    Luxury(double mxSpeed, double mlg, double flCap, string flType,
           int yr, string name, double odoReading, double cost, bool umb,
           bool fridge, bool tv, double roofOp)
        : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading, cost), hasUmbrella{umb}, hasFridge{fridge}, hasTV{tv}, currentSunRoofOpacity{roofOp} {}

    Luxury()
        : Luxury(0, 0, 0, "", 0, "", 0, 0, false, false, false, 0) {}

    void displayInfoLux();
    double giveCost(int days);
    string giveName();
    double givePrice();
    double giveMileage();
};

void Luxury ::displayInfoLux()
{
    cout << "Successfully Selected " << modelName <<endl;
    cout << endl << "Specifications " << endl;
    cout << left << setw(25) << "Max Speed" << " : " << maxSpeed << " kmph" << endl;
    cout << left << setw(25) << "Mileage" << " : " << mileage << " kmpL" << endl;
    cout << left << setw(25) << "Fuel Capacity" << " : " << fuelCapacity << " L" << endl;
    cout << left << setw(25) << "Fuel Type" << " : " << fuelType << endl;
    cout << left << setw(25) << "Model Year" << " : " << year << endl;
    cout << "Current Odometer Reading  : " << odometerReading << endl;

    cout<<"\nSpecial Features"<<endl;
    if (hasUmbrella)
    {
        cout << "Has an umbrella holder"<<endl;
    }
    if (hasFridge)
    {
        cout << "Has a fridge for your beverages and meals" << endl;
    }
    if (hasTV)
    {
        cout << "Has a TV for your priceless entertainment" << endl;
    }
    cout << "Current sun roof opacity is set to "
         << currentSunRoofOpacity << endl;
    cout << "\nIts rent price per day is: " << price << " rupees" << endl;
    cout << endl;
}

double Luxury ::giveCost(int days)
{
    return (price * days);
}

string Luxury ::giveName()
{
    return modelName;
}
double Luxury ::givePrice()
{
    return price;
}
double Luxury ::giveMileage()
{
    return mileage;
}

class Suv : protected DatabaseCar
{
    double groundClearance;
    bool allWheelDrive;
    double heightSeatingPos;

public:
    // Class constructor calling base constructor (super in other languages)
    // and initializing its own variables.

    Suv(double mxSpeed, double mlg, double flCap, string flType,
        int yr, string name, double odoReading, double cost, double GC,
        bool AWD, double seatingPos)
        : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading, cost), groundClearance{GC}, allWheelDrive{AWD}, heightSeatingPos{seatingPos} {}

    Suv()
        : Suv(0, 0, 0, "", 0, "", 0, 0, 0, false, 0) {}

    void displayInfoSuv();
    double giveCost(int days);
    string giveName();
    double givePrice();
    double giveMileage();
};

void Suv ::displayInfoSuv()
{
    cout << "Your selected car is: " << modelName << " with : " << endl;
    cout << left << setw(25) << "Max Speed" << " : " << maxSpeed << " kmph" << endl;
    cout << left << setw(25) << "Mileage" << " : " << mileage << " kmpL" << endl;
    cout << left << setw(25) << "Fuel Capacity" << " : " << fuelCapacity << " L" << endl;
    cout << left << setw(25) << "Fuel Type" << " : " << fuelType << endl;
    cout << left << setw(25) << "Model Year" << " : " << year << endl;
    cout << "Current Odometer Reading  : " << odometerReading << endl;
    cout << left << setw(25) << "Gruond Clearance Level" << " : " << groundClearance << "mm" << endl;
    cout << left << setw(25) << "Seat Height" << " : " << heightSeatingPos << "mm" << endl;

    if (allWheelDrive)
    {
        cout << "Your car is super powerful since it has an all wheel drive!" << endl;
    }
    cout << "\nIts rent price per day is: " << price << " rupees" << endl;
    cout << endl;
}
double Suv ::giveCost(int days)
{
    return (price * days);
}
string Suv ::giveName()
{
    return modelName;
}
double Suv ::givePrice()
{
    return price;
}
double Suv ::giveMileage()
{
    return mileage;
}

class Sedan : protected DatabaseCar
{
    double bootSpace;
    double headSpace;

public:
    // Class constructor calling base constructor (super in other languages)
    // and initializing its own variables.

    Sedan(double mxSpeed, double mlg, double flCap, string flType,
          int yr, string name, double odoReading, double cost, double boot_space, double head_space)
        : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading, cost), bootSpace{boot_space}, headSpace{head_space} {}

    Sedan() : Sedan(0, 0, 0, "", 0, "", 0, 0, 0, 0) {}

    void displayInfoSedan();
    double giveCost(int days);
    string giveName();
    double givePrice();
    double giveMileage();
};

void Sedan ::displayInfoSedan()
{
    cout << "Your selected car is: " << modelName << " with : " << endl;
    cout << left << setw(25) << "Max Speed" << " : " << maxSpeed << " kmph" << endl;
    cout << left << setw(25) << "Mileage" << " : " << mileage << " kmpL" << endl;
    cout << left << setw(25) << "Fuel Capacity" << " : " << fuelCapacity << " L" << endl;
    cout << left << setw(25) << "Fuel Type" << " : " << fuelType << endl;
    cout << left << setw(25) << "Model Year" << " : " << year << endl;
    cout << "Current Odometer Reading  : " << odometerReading << endl;
    cout << left << setw(25) << "Trunk Capacity" << " : " << bootSpace << "ltrs" << endl;
    cout << left << setw(25) << "Head Space" << " : " << headSpace << "mm" << endl;
    cout << "\nIts rent price per day is: " << price << " rupees" << endl;
    cout << endl;
}
double Sedan ::giveCost(int days)
{
    return (price * days);
}
string Sedan ::giveName()
{
    return modelName;
}
double Sedan ::givePrice()
{
    return price;
}
double Sedan ::giveMileage()
{
    return mileage;
}

/***************** Utility Functions *****************/
// cosmetic delay function to give sense of processing
void delay()
{
    int i, j, k;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 10; j++)
        {
            for (k = 0; k < 10000000; k++)
            {
                k++;
                k--;
            }
            cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

//error handling - check 10 digit valid mobile number
void valid_num(char number[]){
    int flag = 0;
    for (int i = 0; i < 10; i++){
        if (isalpha(number[i]))
            flag = 1;
    }

    if (flag == 1){
        cout << "\nInvalid Number Entered, Retry !" << endl;
        cin >> number;
        valid_num(number);
    }
}

//merge sort function
void mergeAsc(double *arr, int l, int r, int mid)
{
    /*
    Here we will assume we have two arrays,
    one from l to mid, the other from
    mid + 1 to r
    */

    // We will take starting index of main array to be 0
    // Consider that.

    int l_size = mid - l + 1; // Take an array and try it out
    int r_size = r - mid;     // r_size = r - (mid+1) + 1

    double L[l_size + 1]; // Our left array. Also, why +1? For line 37
    double R[r_size + 1]; // Our right array. Also, why +1? For line 37

    // Now we will put l to mid elements into L
    // and mid+1 to r elements into R
    for (int i = 0; i < l_size; i++)
    {
        L[i] = arr[i + l]; // a[l] is first element in left array
                           // assign it to L[0] and so on.
    }
    for (int i = 0; i < r_size; i++)
    {
        R[i] = arr[i + mid + 1]; // a[mid + 1] is first element in left array
                                 // assign it to R[0] and so on.
    }

    L[l_size] = R[r_size] = INT_MAX; // https://youtu.be/cWvruDR-hJA?list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&t=1078

    int l_i = 0;
    int r_i = 0;

    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            arr[i] = L[l_i];
            l_i++;
        }
        else
        {
            arr[i] = R[r_i];
            r_i++;
        }
    }
}

void mergeSortAsc(double *arr, int l, int r)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;
    mergeSortAsc(arr, l, mid);
    mergeSortAsc(arr, mid + 1, r);
    mergeAsc(arr, l, r, mid);
}

void mergeDesc(double *arr, int l, int r, int mid)
{
    /*
    Here we will assume we have two arrays,
    one from l to mid, the other from
    mid + 1 to r
    */

    // We will take starting index of main array to be 0
    // Consider that.

    int l_size = mid - l + 1; // Take an array and try it out
    int r_size = r - mid;     // r_size = r - (mid+1) + 1

    double L[l_size + 1]; // Our left array. Also, why +1? For line 37
    double R[r_size + 1]; // Our right array. Also, why +1? For line 37

    // Now we will put l to mid elements into L
    // and mid+1 to r elements into R
    for (int i = 0; i < l_size; i++)
    {
        L[i] = arr[i + l]; // a[l] is first element in left array
                           // assign it to L[0] and so on.
    }
    for (int i = 0; i < r_size; i++)
    {
        R[i] = arr[i + mid + 1]; // a[mid + 1] is first element in left array
                                 // assign it to R[0] and so on.
    }

    L[l_size] = R[r_size] = INT_MAX; // https://youtu.be/cWvruDR-hJA?list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&t=1078

    int L_i = 0;
    int R_j = 0;
    int k = l;
    while (L_i < l_size && R_j < r_size)
    {
        if (L[L_i] >= R[R_j])
        {
            arr[k] = L[L_i];
            L_i++;
        }
        else
        {
            arr[k] = R[R_j];
            R_j++;
        }
        k++;
    }
    // checking and adding if any elements left for second subarray
    while (R_j < r_size)
    {
        arr[k] = R[R_j];
        R_j++;
        k++;
    }
    // checking and adding if any elements left for first subarray
    while (L_i < l_size)
    {
        arr[k] = L[L_i];
        L_i++;
        k++;
    }
}

void mergeSortDesc(double *arr, int l, int r)
{
    if (l == r)
        return;

    int mid = l + (r - l) / 2;
    mergeSortDesc(arr, l, mid);
    mergeSortDesc(arr, mid + 1, r);
    mergeDesc(arr, l, r, mid);
}

int welcomeMenu()
{
    int choice_in_wm;
    cout << endl;
    cout << "What type of car you would like to book:" << endl;
    cout << "1.Luxury " << endl;
    cout << "2.SUV " << endl;
    cout << "3.Sedan " << endl;
    cout << "Enter your choice: " << endl;
    cin >> choice_in_wm;
    cout << endl;
    if (choice_in_wm < 1 || choice_in_wm > 3)
    {
        cout << "Please enter a valid number " << endl;
        cout << endl;
        return (-1);
    }
    else
        return (choice_in_wm);
}

double *filterSortAsc(double *arr)
{
    mergeSortAsc(arr, 0, TOTAL_CARS - 1);
    return arr;
}

double *filterSortDesc(double *arr)
{
    mergeSortDesc(arr, 0, TOTAL_CARS);
    return arr;
}

Luxury &luxFilterPrice(double *arr, Luxury &car1, Luxury &car2, Luxury &car3, Luxury &car4)
{
    int carChoice{};
    Luxury invalid;

    cout << endl
         << "Choose which car you would like to ride in" << endl;
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        if (arr[i] == car1.givePrice())
        {
            cout << i + 1 << ") " << car1.giveName() << endl;
            cout << "Price : Rs. " << car1.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car1.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car2.givePrice())
        {
            cout << i + 1 << ") " << car2.giveName() << endl;
            cout << "Price : Rs. " << car2.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car2.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car3.givePrice())
        {
            cout << i + 1 << ") " << car3.giveName() << endl;
            cout << "Price : Rs. " << car3.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car3.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car4.givePrice())
        {
            cout << i + 1 << ") " << car4.giveName() << endl;
            cout << "Price : Rs. " << car4.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car4.giveMileage() << " kmpl" << endl
                 << endl;
        }
    }
    cin >> carChoice;
    cout << endl;

    if (carChoice >= 1 && carChoice <= 4)
    {
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            if (arr[carChoice - 1] == car1.givePrice())
            {
                return car1;
            }
            else if (arr[carChoice - 1] == car2.givePrice())
            {
                return car2;
            }
            else if (arr[carChoice - 1] == car3.givePrice())
            {
                return car3;
            }
            else if (arr[carChoice - 1] == car4.givePrice())
            {
                return car4;
            }
        }
    }
    cout << "Please enter a valid number " << endl;
    return invalid;
}

Luxury &luxFilterMileage(double *arr, Luxury &car1, Luxury &car2, Luxury &car3, Luxury &car4)
{
    int carChoice{};
    Luxury invalid;

    cout << endl
         << "Choose which car you would like to ride in" << endl;
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        if (arr[i] == car1.giveMileage())
        {
            cout << i + 1 << ") " << car1.giveName() << endl;
            cout << "Price : Rs. " << car1.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car1.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car2.giveMileage())
        {
            cout << i + 1 << ") " << car2.giveName() << endl;
            cout << "Price : Rs. " << car2.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car2.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car3.giveMileage())
        {
            cout << i + 1 << ") " << car3.giveName() << endl;
            cout << "Price : Rs. " << car3.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car3.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car4.giveMileage())
        {
            cout << i + 1 << ") " << car4.giveName() << endl;
            cout << "Price : Rs. " << car4.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car4.giveMileage() << " kmpl" << endl
                 << endl;
        }
    }
    cin >> carChoice;
    cout << endl;

    if (carChoice >= 1 && carChoice <= 4)
    {
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            if (arr[carChoice - 1] == car1.giveMileage())
            {
                return car1;
            }
            else if (arr[carChoice - 1] == car2.giveMileage())
            {
                return car2;
            }
            else if (arr[carChoice - 1] == car3.giveMileage())
            {
                return car3;
            }
            else if (arr[carChoice - 1] == car4.giveMileage())
            {
                return car4;
            }
        }
    }
    cout << "Please enter a valid number " << endl;
    return invalid;
}

Suv &suvFilterPrice(double *arr, Suv &car1, Suv &car2, Suv &car3, Suv &car4)
{
    int carChoice{};
    Suv invalid;

    cout << endl
         << "Choose which car you would like to ride in" << endl;
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        if (arr[i] == car1.givePrice())
        {
            cout << i + 1 << ") " << car1.giveName() << endl;
            cout << "Price : Rs. " << car1.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car1.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car2.givePrice())
        {
            cout << i + 1 << ") " << car2.giveName() << endl;
            cout << "Price : Rs. " << car2.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car2.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car3.givePrice())
        {
            cout << i + 1 << ") " << car3.giveName() << endl;
            cout << "Price : Rs. " << car3.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car3.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car4.givePrice())
        {
            cout << i + 1 << ") " << car4.giveName() << endl;
            cout << "Price : Rs. " << car4.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car4.giveMileage() << " kmpl" << endl
                 << endl;
        }
    }
    cin >> carChoice;
    cout << endl;

    if (carChoice >= 1 && carChoice <= 4)
    {
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            if (arr[carChoice - 1] == car1.givePrice())
            {
                return car1;
            }
            else if (arr[carChoice - 1] == car2.givePrice())
            {
                return car2;
            }
            else if (arr[carChoice - 1] == car3.givePrice())
            {
                return car3;
            }
            else if (arr[carChoice - 1] == car4.givePrice())
            {
                return car4;
            }
        }
    }
    cout << "Please enter a valid number " << endl;
    return invalid;
}

Suv &suvFilterMileage(double *arr, Suv &car1, Suv &car2, Suv &car3, Suv &car4)
{
    int carChoice{};
    Suv invalid;

    cout << endl
         << "Choose which car you would like to ride in" << endl;
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        if (arr[i] == car1.giveMileage())
        {
            cout << i + 1 << ") " << car1.giveName() << endl;
            cout << "Price : Rs. " << car1.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car1.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car2.giveMileage())
        {
            cout << i + 1 << ") " << car2.giveName() << endl;
            cout << "Price : Rs. " << car2.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car2.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car3.giveMileage())
        {
            cout << i + 1 << ") " << car3.giveName() << endl;
            cout << "Price : Rs. " << car3.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car3.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car4.giveMileage())
        {
            cout << i + 1 << ") " << car4.giveName() << endl;
            cout << "Price : Rs. " << car4.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car4.giveMileage() << " kmpl" << endl
                 << endl;
        }
    }
    cin >> carChoice;
    cout << endl;

    if (carChoice >= 1 && carChoice <= 4)
    {
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            if (arr[carChoice - 1] == car1.giveMileage())
            {
                return car1;
            }
            else if (arr[carChoice - 1] == car2.giveMileage())
            {
                return car2;
            }
            else if (arr[carChoice - 1] == car3.giveMileage())
            {
                return car3;
            }
            else if (arr[carChoice - 1] == car4.giveMileage())
            {
                return car4;
            }
        }
    }
    cout << "Please enter a valid number " << endl;
    return invalid;
}

Sedan &sedanFilterPrice(double *arr, Sedan &car1, Sedan &car2, Sedan &car3, Sedan &car4)
{
    int carChoice{};
    Sedan invalid;

    cout << endl
         << "Choose which car you would like to ride in" << endl;
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        if (arr[i] == car1.givePrice())
        {
            cout << i + 1 << ") " << car1.giveName() << endl;
            cout << "Price : Rs. " << car1.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car1.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car2.givePrice())
        {
            cout << i + 1 << ") " << car2.giveName() << endl;
            cout << "Price : Rs. " << car2.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car2.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car3.givePrice())
        {
            cout << i + 1 << ") " << car3.giveName() << endl;
            cout << "Price : Rs. " << car3.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car3.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car4.givePrice())
        {
            cout << i + 1 << ") " << car4.giveName() << endl;
            cout << "Price : Rs. " << car4.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car4.giveMileage() << " kmpl" << endl
                 << endl;
        }
    }
    cin >> carChoice;
    cout << endl;

    if (carChoice >= 1 && carChoice <= 4)
    {
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            if (arr[carChoice - 1] == car1.givePrice())
            {
                return car1;
            }
            else if (arr[carChoice - 1] == car2.givePrice())
            {
                return car2;
            }
            else if (arr[carChoice - 1] == car3.givePrice())
            {
                return car3;
            }
            else if (arr[carChoice - 1] == car4.givePrice())
            {
                return car4;
            }
        }
    }
    cout << "Please enter a valid number " << endl;
    return invalid;
}
                          
Sedan &sedanFilterMileage(double *arr, Sedan &car1, Sedan &car2, Sedan &car3, Sedan &car4)
{
    int carChoice{};
    Sedan invalid;

    cout << endl
         << "Choose which car you would like to ride in" << endl;
    for (int i = 0; i < TOTAL_CARS; i++)
    {
        if (arr[i] == car1.giveMileage())
        {
            cout << i + 1 << ") " << car1.giveName() << endl;
            cout << "Price : Rs. " << car1.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car1.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car2.giveMileage())
        {
            cout << i + 1 << ") " << car2.giveName() << endl;
            cout << "Price : Rs. " << car2.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car2.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car3.giveMileage())
        {
            cout << i + 1 << ") " << car3.giveName() << endl;
            cout << "Price : Rs. " << car3.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car3.giveMileage() << " kmpl" << endl
                 << endl;
        }
        else if (arr[i] == car4.giveMileage())
        {
            cout << i + 1 << ") " << car4.giveName() << endl;
            cout << "Price : Rs. " << car4.givePrice() << " Per Day" << endl;
            cout << "Mileage : " << car4.giveMileage() << " kmpl" << endl
                 << endl;
        }
    }
    cin >> carChoice;
    cout << endl;

    if (carChoice >= 1 && carChoice <= 4)
    {
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            if (arr[carChoice - 1] == car1.giveMileage())
            {
                return car1;
            }
            else if (arr[carChoice - 1] == car2.giveMileage())
            {
                return car2;
            }
            else if (arr[carChoice - 1] == car3.giveMileage())
            {
                return car3;
            }
            else if (arr[carChoice - 1] == car4.giveMileage())
            {
                return car4;
            }
        }
    }
    cout << "Please enter a valid number " << endl;
    return invalid;
}
 
int main()
{
    // int chosenCar{};
    string userName;
    char userNumber[10] = {'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n', 'n' } ;
    double *carPrice = new double[TOTAL_CARS];
    double *carMileage = new double[TOTAL_CARS];
    string FinalChoice;

    /*
     * Object initialization start
     */

    Luxury bmwx1(129, 17.5, 51, "Petrol",
                 2018, "BMW X1", 120, 5500, false,
                 false, true, 1.6);

    Luxury mercEClass(224, 15.1, 80, "Diesel",
                      2021, "MERCEDES E-CLASS E 220D BS4",
                      245, 7800, false, false, false, 1.4);

    Luxury mercSClass(250, 6.7, 80, "Petrol",
                      2021, "MERCEDES S-CLASS 5500 W223 BS4",
                      100, 16000, true, true, true, 1.8);

    Luxury audiA8(250, 7.92, 80, "Hybrid (Electric + Petrol)",
                  2022, "AUDI A8L TECHNOLOGY MODEL", 120, 15000,
                  true, true, true, 2);

    Luxury luxFinalCar;

    Suv xuv700(200, 16, 60, "Diesel", 2022, "MAHINDRA XUV 700",
               100, 3000, 200, true, 840);

    Suv scorpioS3(160, 15.4, 58, "Diesel", 2021,
                  "MAHINDRA SCORPIO S3", 100, 2400, 180, false,
                  840);

    Suv fortuner(186, 13.4, 80, "Petrol", 2020,
                 "TOYOTA FORTUNER", 100, 3800, 225, true,
                 820);

    Suv seltos(165, 18.6, 50, "Petrol", 2022,
               "KIA SELTOS FWD", 100, 2500, 190, false,
               800);

    Suv suvFinalCar;

    Sedan ciazA(185, 20, 43, "Petrol", 2021, "MARUTI CIAZ ALPHA",
                100, 2400, 510, 900);

    Sedan ciazS(185, 20.65, 43, "Petrol", 2022, "MARUTI CIAZ SIGMA",
                100, 2600, 510, 900);

    Sedan hondaCity(195, 17.55, 40, "Diesel", 2022, "HONDA CITY V MT",
                    100, 2800, 506, 910);

    Sedan verna(200, 21.5, 45, "Petrol", 2022, "HYUNDAI VERNA SX",
                100, 2500, 480, 860);

    Sedan sedanFinalCar;

    /*
     * Object initialization end
     */

    // Create a file pointer fptr
    fstream fptr;
    // Open customerInfo.txt file in append mode
    fptr.open("customerInfo.txt", std::ios::app);

    if (!fptr)
    {
        cout << "Please create a customerInfo.txt file and re-run this program!" << endl;
        return 0;
    }

    cout << "Welcome to Car Rental System! And ......." << endl;
    cout << "Made by: " << endl;
    cout << "1. Mudit Garg " << endl;
    cout << "2. Nihar Phansalkar " << endl;
    cout << "3. Ojaswini Kohale " << endl;
    cout << "4. P. Karthik Krishna " << endl;

    /*
     * Functions for delay start
     */
    sleep_for(10ns);
    sleep_until(system_clock::now() + 2s);1

    /*
     * Functions for delay end
     */

    // In-built function to clear terminal/console
    // system("cls"); // Windows command
    system("clear"); // Linux command

    cout << "Hello Customer! " << userName << endl;
    cout << "Welcome to Car Rental System!" << endl
         << endl;

    cout << "Please press '1' to book a car" << endl;
    cout << "Please press '2' to exit" << endl;

    int initialChoice;
    cin >> initialChoice;

    cout << "Welcome to Car Rental System!" << endl
         << endl;
    cout << "Please Enter Your Name: ";
    cin.ignore();
    fflush(stdin);
    getline(cin, userName);
    fflush(stdin);
    // std::transform(input begin, input end, output begin, operation);
    std::transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
    fptr << "Name: " << userName;
    fptr << endl;
    cout << "Please Enter Your Contact Number: ";
    cin >> userNumber;
    valid_num(userNumber);    
    fptr << "Number: " << userNumber;
    fptr << endl;

    fptr.close();

    // In-built function to clear terminal/console
    // system("cls"); // Windows command
    system("clear"); // Linux command

    int val_from_wm{}, filterValue{};

    while (initialChoice == 1)
    {
        switch (initialChoice)
        {
        case 1:
        {
            val_from_wm = welcomeMenu();

            while (val_from_wm == -1)
            {
                val_from_wm = welcomeMenu();
            }

            if (val_from_wm == 1)
            {
                cout << "1) Choose a car based on price" << endl;
                cout << "2) Choose a car based on mileage" << endl;
                cin >> filterValue;

                if (filterValue == 1)
                {
                    carPrice[0] = bmwx1.givePrice();
                    carPrice[1] = mercEClass.givePrice();
                    carPrice[2] = mercSClass.givePrice();
                    carPrice[3] = audiA8.givePrice();
                    carPrice = filterSortAsc(carPrice);
                    luxFinalCar = luxFilterPrice(carPrice, bmwx1, mercEClass, mercSClass, audiA8);
                    while (luxFinalCar.giveName() == "")
                    {
                        luxFinalCar = luxFilterPrice(carPrice, bmwx1, mercEClass, mercSClass, audiA8);
                    }
                }
                else if (filterValue == 2)
                {
                    carMileage[0] = bmwx1.giveMileage();
                    carMileage[1] = mercEClass.giveMileage();
                    carMileage[2] = mercSClass.giveMileage();
                    carMileage[3] = audiA8.giveMileage();
                    carMileage = filterSortDesc(carMileage);
                    luxFinalCar = luxFilterMileage(carMileage, bmwx1, mercEClass, mercSClass, audiA8);
                    while (luxFinalCar.giveName() == "")
                    {
                        luxFinalCar = luxFilterMileage(carMileage, bmwx1, mercEClass, mercSClass, audiA8);
                    }
                }

                break;
            }
            else if (val_from_wm == 2)
            {
                cout << "1) Choose a car based on price" << endl;
                cout << "2) Choose a car based on mileage" << endl;
                cin >> filterValue;

                if (filterValue == 1)
                {
                    carPrice[0] = xuv700.givePrice();
                    carPrice[1] = scorpioS3.givePrice();
                    carPrice[2] = fortuner.givePrice();
                    carPrice[3] = seltos.givePrice();
                    carPrice = filterSortAsc(carPrice);
                    suvFinalCar = suvFilterPrice(carPrice, xuv700, scorpioS3, fortuner, seltos);
                    while (suvFinalCar.giveName() == "")
                    {
                        suvFinalCar = suvFilterPrice(carPrice, xuv700, scorpioS3, fortuner, seltos);
                    }
                }
                else if (filterValue == 2)
                {
                    carMileage[0] = xuv700.giveMileage();
                    carMileage[1] = scorpioS3.giveMileage();
                    carMileage[2] = fortuner.giveMileage();
                    carMileage[3] = seltos.giveMileage();
                    carMileage = filterSortDesc(carMileage);
                    suvFinalCar = suvFilterMileage(carMileage, xuv700, scorpioS3, fortuner, seltos);
                    while (suvFinalCar.giveName() == "")
                    {
                        suvFinalCar = suvFilterMileage(carMileage, xuv700, scorpioS3, fortuner, seltos);
                    }
                }

                break;
            }
            else if (val_from_wm == 3)
            {
                cout << "1) Choose a car based on price" << endl;
                cout << "2) Choose a car based on mileage" << endl;
                cin >> filterValue;

                if (filterValue == 1)
                {
                    carPrice[0] = ciazA.givePrice();
                    carPrice[1] = ciazS.givePrice();
                    carPrice[2] = hondaCity.givePrice();
                    carPrice[3] = verna.givePrice();
                    carPrice = filterSortAsc(carPrice);
                    sedanFinalCar = sedanFilterPrice(carPrice, ciazA, ciazS, hondaCity, verna);
                    while (sedanFinalCar.giveName() == "")
                    {
                        sedanFinalCar = sedanFilterPrice(carPrice, ciazA, ciazS, hondaCity, verna);
                    }
                }
                else if (filterValue == 2)
                {
                    carMileage[0] = ciazA.giveMileage();
                    carMileage[1] = ciazS.giveMileage();
                    carMileage[2] = hondaCity.giveMileage();
                    carMileage[3] = verna.giveMileage();
                    carMileage = filterSortDesc(carMileage);
                    sedanFinalCar = sedanFilterMileage(carMileage, ciazA, ciazS, hondaCity, verna);
                    while (sedanFinalCar.giveName() == "")
                    {
                        sedanFinalCar = sedanFilterMileage(carMileage, ciazA, ciazS, hondaCity, verna);
                    }
                }

                break;
            }
        }
        }

        // In-built function to clear terminal/console
        // system("cls"); // Windows command
        system("clear"); // Linux command

        double billPrice{};
        int days{};
        int dayCount{};

        if (luxFinalCar.giveName() != "")
        {
            luxFinalCar.displayInfoLux();

            cout << "How many days you would like to book the car for?" << endl;
            cin >> days;

            billPrice = luxFinalCar.giveCost(days);
            FinalChoice = luxFinalCar.giveName();

            fptr.open("customerInfo.txt", std::ios::app);

            if (!fptr)
            {
                cout << "Please create a customerInfo.txt file and re-run this program!" << endl;
                return 0;
            }
            fptr << "Car booked: " << luxFinalCar.giveName() << endl;
            fptr.close();
        }
        else if (suvFinalCar.giveName() != "")
        {
            suvFinalCar.displayInfoSuv();

            cout << "How many days you would like to book the car for?" << endl;
            cin >> days;

            billPrice = suvFinalCar.giveCost(days);
            FinalChoice = suvFinalCar.giveName();

            fptr.open("customerInfo.txt", std::ios::app);

            if (!fptr)
            {
                cout << "Please create a customerInfo.txt file and re-run this program!" << endl;
                return 0;
            }
            fptr << "Car booked: " << suvFinalCar.giveName() << endl;
            fptr.close();
        }
        else if (sedanFinalCar.giveName() != "")
        {
            sedanFinalCar.displayInfoSedan();

            cout << "How many days you would like to book the car for?" << endl;
            cin >> days;

            billPrice = sedanFinalCar.giveCost(days);
            FinalChoice = sedanFinalCar.giveName();

            fptr.open("customerInfo.txt", std::ios::app);

            if (!fptr)
            {
                cout << "Please create a customerInfo.txt file and re-run this program!" << endl;
                return 0;
            }
            fptr << "Car booked: " << sedanFinalCar.giveName() << endl;
            fptr.close();
        }

        fptr.open("customerInfo.txt", std::ios::app);

        if (!fptr)
        {
            cout << "Please create a customerInfo.txt file and re-run this program!" << endl;
            return 0;
        }
        fptr << "Days booked for: " << days << endl;
        fptr.close();

        int dayTemp = days;

        while(dayTemp) {
            dayCount++;
            dayTemp /= 10;
        }

        cout << endl << endl;

        delay();

        cout << "+----------------------------------------------+" << endl;
        cout << "|----------------- GAS N' GO ------------------|" << endl;
        cout << "|------------- CAR RENTAL RECEIPT -------------|" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "|" << right << setw(47) << "|" << endl;
        cout << "| Customer Details:-" << right << setw(28) << "|" << endl;
        cout << "| " << left << setw(11) << "Name" << " : " << left << setw(30) << userName << setw(2) << right << "|" << endl;
        cout << "| Contact No." << " : " << userNumber << right << setw(22) << "|" << endl; 
        cout << "|" << right << setw(47) << "|" << endl;
        cout << "| Booking Details:-" << right << setw(29) << "|" << endl;
        cout << "| " << left << setw(11) << "Car Model" << " : " << left << setw(30) << FinalChoice << setw(2) << right << "|" << endl;
        if (dayCount == 1) {
            cout << "| " << left << setw(11) << "Booked For" << " : " << left << setw(1) << days << " Days" << setw(26) << right << "|" << endl;
        }
        else if (dayCount == 2) {
            cout << "| " << left << setw(11) << "Booked For" << " : " << left << setw(2) << days << " Days" << setw(25) << right << "|" << endl;
        }
        else if (dayCount == 3) {
            cout << "| " << left << setw(11) << "Booked For" << " : " << left << setw(3) << days << " Days" << setw(24) << right << "|" << endl;
        }
        cout << "|" << right << setw(47) << "|" << endl;;
        cout << "| Cost Structure:-" << right << setw(30) << "|" << endl;
        cout << "+----------------------------------------------+" << endl;
        cout << "|" << setw(22) << "    Particulars    " << " | " << setw(21) << "        Amount       " << "|" << endl;    
        cout << "+----------------------------------------------+" << endl;
        cout << "|" << setw(22) << "   Base Rental Cost  " << " | " << "     Rs. " << left << setw(12) << billPrice << "|" << endl;    
        cout << "|" << setw(22) << "   Security Deposit  " << " | " << "     Rs. " << setw(12) << "20000" << "|" << endl;    
        cout << "|" << setw(22) << "   Taxes - 5 % GST   " << " | " << "     Rs. " << setw(12) << billPrice*0.05 << "|" << endl;    
        cout << "+----------------------------------------------+" << endl;
        cout << "|" << setw(22) << "   Total Bill Cost   " << " | " << "     Rs. " << setw(12) << billPrice + 20000 + (billPrice * 0.05) << "|" << endl;    
        cout << "+----------------------------------------------+" << endl << endl;
        
        cout << "Thank you for using this car rental system!" << endl;
        cout << "Expect your vehicle to arrive soon!" << endl;
        cout << "We hope you enjoy your ride to the fullest!" << endl;

        fptr.open("customerInfo.txt", std::ios::app);

        if (!fptr)
        {
            cout << "Please create a customerInfo.txt file and re-run this program!" << endl;
            return 0;
        }
        fptr << "Bill: " << billPrice + 20000 + (billPrice * 0.05) << endl
             << endl;
        fptr.close();

        /*
         * Functions for delay start
         */

        sleep_for(10ns);
        sleep_until(system_clock::now() + 15s);

        /*
         * Functions for delay end
         */

        // In-built function to clear terminal/console
        // system("cls"); // Windows command
        system("clear"); // Linux command

        cout << "Hello Customer! " << endl;
        cout << "Welcome to Car Rental System!" << endl
             << endl;

        cout << "Please press '1' to book a car" << endl;
        cout << "Please press '2' to exit" << endl;

        int initialChoice;
        cin >> initialChoice;

        if (initialChoice != 1)
        {
            break;
        }

        fptr.open("customerInfo.txt", std::ios::app);

        cout << "Welcome to Car Rental System!" << endl
             << endl;
        cout << "Please Enter Your Name: ";
        cin.ignore();
        fflush(stdin);
        getline(cin, userName);
        fflush(stdin);
        // std::transform(input begin, input end, output begin, operation);
        std::transform(userName.begin(), userName.end(), userName.begin(), ::tolower);
        fptr << "Name: " << userName;
        fptr << endl;
        cout << "Please Enter Your Contact Number: ";
        cin >> userNumber;
        valid_num(userNumber);
        fptr << "Number: " << userNumber;
        fptr << endl;

        fptr.close();

        // In-built function to clear terminal/console
        // system("cls"); // Windows command
        system("clear"); // Linux command

        // Resetting values
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            carPrice[i] = 0;
        }
        for (int i = 0; i < TOTAL_CARS; i++)
        {
            carMileage[i] = 0;
        }

        days = 0;
        billPrice = 0;
        luxFinalCar = Luxury();
        suvFinalCar = Suv();
        sedanFinalCar = Sedan();
    }

    fptr.close();
    delete[]carMileage;
    delete[]carPrice;

    cout << endl;
    return 0;
}
