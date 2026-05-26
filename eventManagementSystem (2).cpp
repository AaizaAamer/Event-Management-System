//Muhammad Awais(SP24-BCS-076)
//Aaiza Aamer(SP24-BCS-001)
//Amna Arshad Butt(SP24-BCS-016)
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Constants
const int MAX_ACTIVITIES = 100;
const int MAX_EVENTS = 100;
const int MAX_RESOURCES = 100;
const int MAX_ROWS = 10;
const int MAX_COLS = 10;
const int MAX_VENUES = 6;
const int MAX_VENDORS = 5;
const int MAX_FOOD = 5;
const int MAX_DESSERTS = 4;
const int MAX_DRINKS = 4;
const int MAX_EQUIPMENT = 7;
const int MAX_userS = 100;

const int DAYS_IN_WEEK = 7;
const int WEEKS_IN_MONTH = 4;
const int HOURS_IN_DAY = 12; // Assuming 12-hour slots for simplicity

const string FILENAME = "users.txt";

// Structures
struct Activity {
    string id;
    string eventId;
    string participantId;
    string type;  // e.g., "Check-In", "Session Attendance"
    string timestamp;  // YYYY-MM-DD HH:MM:SS format
};

struct Event {
    int id;
    string name;
    string date;  // Format: YYYY-MM-DD
    string location;
};

struct Resource {
    int id;
    string name;
    int usageCount;
};

struct ResourceBundle {
    int bundleId;
    string bundleName;
    Resource resources[MAX_RESOURCES];
    int numResources;
};

struct user {
    int id;
    string name;
    string email;
    string phone;
};

user users[MAX_userS];
int userCount = 0;


// Global arrays
Activity activities[MAX_ACTIVITIES];
int numActivities = 0; // Track the number of activities stored

Event events[MAX_EVENTS];
int numEvents = 0; // Track the number of events stored

ResourceBundle resourceBundles[MAX_RESOURCES];
int numResourceBundles = 0; // Track the number of resource bundles stored

char seatingChart[MAX_ROWS][MAX_COLS];
string venues[MAX_VENUES] = {"Garden", "Ballroom", "Terrace", "Banquet Hall", "Courtyard", "Roof Terrace"};
string roomTypes[MAX_VENUES] = {"Outdoor", "Indoor", "Outdoor", "Indoor", "Indoor", "Outdoor"};
string price6[MAX_VENUES] = {"25,000", "30,000", "25,000", "50,000", "40,000" ,"35,000"};
string foodItems[MAX_FOOD] = {"Chicken Biryani", "Chinese Menu", "BBQ", "Chicken Burgers", "Pizzas"};
string price[MAX_FOOD] = {"20,000", "35,000", "35,000", "20,000", "30,000"};
string dessertItems[MAX_DESSERTS] = {"Brownie" , "Ice-cream" , " Ghulab Jaman" , "Custard " };
string price4[MAX_DESSERTS] = {"250","200","180","200"};
string drinks[MAX_DRINKS] = {"NESTLE Water","Coca-Cola","Sprite","Milk shake"};
string price5[MAX_DRINKS] ={"100","140","140","200"};
string vendors[MAX_VENDORS] = {"Food Vendor", "Servers", "Audio Player", "Photographer", "Lighting"};
string price2[MAX_VENDORS] = {"10,000", "15,000", "10,000", "20,000", "25,000"};
string equipment[MAX_EQUIPMENT] = {"Decorations", "Balloons", "Chairs", "Tables", "Flowers", "Carpets", "Lights"};
string price3[MAX_EQUIPMENT] = {"15,000", "5,000", "13,000", "13,000", "5,000", "12,000", "24,000"};

bool booked[MAX_VENUES] = {false};
bool food[MAX_FOOD] = {false};
bool resource[MAX_EQUIPMENT] = {false};
bool dessert[MAX_DESSERTS] = { false};
bool drink[MAX_DRINKS] = { false };
// Function prototypes
void readActivities();
void writeActivities();
void addActivity();
void showActivities();
void loadEvents();
void saveEvents();
void createEvent();
void listEvents();
void updateEvent();
void deleteEvent();
void createResourceBundle();
void displayResourceBundles();
void checkMaintenance();
void displayMenu();
void displaySeatingChart();
void updateSeatingChart(int row, int col);
void displayWeather(string cityName);
void showMainMenu();
void handleUserChoice(int choice);
void saveToFile(string data);
void displayVenues();
void displayFood();
void displayDesserts();
void displayDrinks();
void bookEvent(int venueIndex);
void unbookEvent(int venueIndex);
void checkAvailability(int venueIndex);
void checkResources(int resourceIndex);
void bookResources(int resourceIndex);
void bookVendors(int vendorIndex);
void displayData(); // Function to display employee menu
void adduser();
void viewusers();
void updateuser();
void deleteuser();
int finduserById(int id);
void saveToFile();
void loadFromFile();

void displayDailyView();
void displayWeeklyView();
void displayMonthlyView();


void chooseTypeOfUser() {
    cout << "Are you an employee or a customer." << endl;
    cout << endl;
    cout << "Enter 1 if you are an employee. Enter 2 if you are a customer." << endl;

}
// Main function
int main() {
     for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            seatingChart[i][j] = 'O'; // O represents available seats
        }
    }

    readActivities();
    loadEvents();
    loadFromFile();
    int choice1, choice2, choice3;

    cout << "               ****************************************************************************************** " << endl;
    cout << "                                        WELCOME TO AAA'S EVENT MANAGEMENT SYSTEM                              " << endl;
    cout << "               ****************************************************************************************** " << endl;
    cout << endl;
    cout << "                                                  HOW MAY WE HELP YOU?     " << endl;
    cout << "                _________________________________________________________________________________________           " << endl;
    cout << endl;

    chooseTypeOfUser();
    cin>>choice1;

    if (choice1 == 1) {
            cout<<"Select from the following :"<<endl;
        do {
            displayData();
            cout<<endl;
            cout << "Enter your choice to proceed. " << endl;
            cin >> choice2;
            switch (choice2) {
                case 1:
                    addActivity();
                    break;
                case 2:
                    showActivities();
                    break;
                case 3:
                    createEvent();
                    break;
                case 4:
                    listEvents();
                    break;
                case 5:
                    updateEvent();
                    break;
                case 6:
                    deleteEvent();
                    break;
                case 7:
                    createResourceBundle();
                    break;
                case 8:
                    displayResourceBundles();
                    break;
                case 9:
                    checkMaintenance();
                    break;
                case 10:
                     adduser();
                     saveToFile();
                     break;
                case 11 :
                    viewusers();
                    saveToFile();
                    break;
                case 12:
                    updateuser();
                    saveToFile();
                    break;
                case 13:
                    deleteuser();
                    saveToFile();

                    break;

                case 14:
                    main();
                    cout << "Exiting program. " << endl;

                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice2 != 14);
    } else if (choice1 == 2) {
        cout<<endl;
        cout<<"To proceed forward choose an option : "<<endl;
        do {
            displayMenu();
            cout << "Enter your choice. ";
            cin >> choice3;

            int venueIndex, resourceIndex, vendorIndex;

            switch (choice3) {

                case 1:
                    displayVenues();
                    break;
                case 2:
                    displayFood();
                    break;
                case 3:
                    displayDesserts();
                    break;
                case 4:
                    displayDrinks();
                        break;
                case 5:

                    bookEvent(venueIndex);
                    break;
                case 6:
                    cout << "Enter venue index to unbook: ";
                    cin >> venueIndex;
                    unbookEvent(venueIndex);
                    break;
                case 7:
                    cout << "Enter resource index to check: ";
                    cin >> resourceIndex;
                    checkResources(resourceIndex);
                    break;
                case 8:
                    cout << "Enter the venue number to check availability: ";
                    cin >> venueIndex;
                    if (venueIndex >= 1 && venueIndex <= MAX_VENUES) {
                        checkAvailability(venueIndex);
                    } else {
                        cout << "Invalid venue number.\n";
                    }
                    break;

                case 9:
                    displaySeatingChart();
                    break;
                case 10:
                {
                    int row, col;
                    cout << "Enter row and column numbers for your seat (row col): ";
                    cin >> row >> col;
                    if (row >= 1 && row <= MAX_ROWS && col >= 1 && col <= MAX_COLS) {
                        updateSeatingChart(row - 1, col - 1);
                    } else {
                        cout << "Invalid row or column number!" << endl;
                    }
                }
                break;
                case 11:
                {
                    string cityName;
                    cout << "Enter city name for weather update: ";
                    cin >> cityName;
                    displayWeather(cityName);
                }
                break;

                case 12:
                    displayDailyView();
                    break;

                case 13:
                    displayWeeklyView();
                    break;

                case 14:
                    displayMonthlyView();
                    break;

                case 15:
                    main();
                    cout << "Exiting program." << endl;
                    break;

                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice3 != 15);
    }

    return 0;
}

// Define other functions here

void displayData() {
    cout <<endl;
    cout << "                                         EMPLOYEE MENU                                             \n";
    cout << "\t______________________________________________________________________________________________\n";
    cout << "\t\t\t1. Add Activity  \t\t2. Show Activities\n";
    cout << "\t\t\t3. Create Event  \t\t4. List Events\n";
    cout << "\t\t\t5. Update Event  \t\t6. Delete Event\n";
    cout << "\t\t\t7. Create Resource Bundle \t8. Display Resource Bundles\n";
    cout << "\t\t\t9. Check Maintenance \t\t10. Add users\n";
    cout << "\t\t\t11. View users  \t\t12. Update user \n";
    cout << "\t\t\t13. Delete user \t\t14. Exit\n";
    cout << "\t______________________________________________________________________________________________\n";

}

void saveToFile(string data) {
    ofstream file("bookings.txt", ios::app);
    if (file.is_open()) {
        file << data << endl;
        file.close();
    } else {
        cout << "Error: Unable to open file for writing." << endl;
    }
}



void displayVenues() {
    cout << "Venue List:" << endl;
    for (int i = 0; i < MAX_VENUES; i++) {
        cout << i + 1 << ". " << venues[i] << " (" << roomTypes[i] << ")" << "(" << price6[i] << ")" << endl;
    }
}

void displayFood() {
    cout << "Food List:" << endl;
    for (int i = 0; i < MAX_FOOD; i++) {
        cout << i + 1 << ". " << foodItems[i] << " (" << price[i] << ")" << endl;
    }
}

void displayDesserts() {
    cout << "Desserts List:" << endl;
    for (int i = 0; i < MAX_DESSERTS; i++) {
        cout << i + 1 << ". " << dessertItems[i] << " (" << price[i] << ")" << endl;
    }
}

void displayDrinks() {
    cout << "Drinks List:" << endl;
    for (int i = 0; i < MAX_DRINKS; i++) {
        cout << i + 1 << ". " << drinks[i] << " (" << price[i] << ")" << endl;
    }
}
void bookEvent(int venueIndex) {
    int responce;
 displayVenues();
 displayFood();
 displayDesserts();
 displayDrinks();

 adduser();
 createEvent();

    cout << "Enter Venue Code" << endl;
    cin >> venueIndex;

    if (!booked[venueIndex]) {
        cout << "Booking " << venues[venueIndex - 1] << "..." << endl;
        cout << venues[venueIndex - 1] << " has been booked." << endl;

        cout<<"Enter 1 to return to Main menu ";
        cin>>responce;

        if (responce== 1)
        {
            displayMenu();
        }
        system ("pause");

        // Log booking
        string logEntry = venues[venueIndex - 1] + " booked  " ; // getCurrentTime();
        saveToFile(logEntry);

        //Booking Food
        int foodIndex;
        cout << "Choose Food Option:" << endl;
        cin >> foodIndex;

        if (!food[foodIndex]) {
            cout << "Booking food..." << endl;
            cout << foodItems[foodIndex - 1] << " has been booked." << endl;
            cout << "Food booked." << endl;

            // Log food booking
            logEntry = "Food booked for " + foodItems[foodIndex - 1] ;//+ " at " + getCurrentTime();
            saveToFile(logEntry);
        }
        int dessertsIndex;
        cout << "Choose Dessert Option:" << endl;
        cin >> dessertsIndex;

        if (!dessert[dessertsIndex]) {
            cout << "Booking deserts..." << endl;
            cout << dessertItems[dessertsIndex - 1] << " has been booked." << endl;
            cout << "Dessert booked." << endl;

            // Log food booking
            logEntry = "Dessert booked for " + dessertItems[dessertsIndex - 1] ; //+ " at " + getCurrentTime();
            saveToFile(logEntry);
        }
        int drinksIndex;
        cout << "Choose drinks Option:" << endl;
        cin >> drinksIndex;

        if (!drink[drinksIndex]) {
            cout << "Booking drinks..." << endl;
            cout << drinks[drinksIndex - 1] << " has been booked." << endl;
            cout << "Drinks booked." << endl;

            // Log food booking
            logEntry = "Drinks booked for " + drinks[drinksIndex - 1] ;//+ " at " + getCurrentTime();
            saveToFile(logEntry);
        }

        int resourceIndex, vendorIndex;
        bookResources(resourceIndex);
        bookVendors(vendorIndex);

        booked[venueIndex] = true;
        booked[foodIndex] = true;

        cout << "BOOKING SUCCESSFUL!" << endl;
    } else {
        cout << "Sorry, " << venues[venueIndex] << " is already booked." << endl;
    }
}

void unbookEvent(int venueIndex) {
    cout << "Enter Venue Code" << endl;
    cin >> venueIndex;

    if (booked[venueIndex]) {
        cout << "Unbooking " << venues[venueIndex - 1] << "..." << endl;

        // Log unbooking
        string logEntry = venues[venueIndex - 1] + " unbooked  " ;//+ getCurrentTime();
        saveToFile(logEntry);

        booked[venueIndex] = false;
        cout << "Unbooking successful!" << endl;
    } else {
        cout << "No booking found for " << venues[venueIndex - 1] << "." << endl;
    }
}

void checkAvailability(int venueIndex) {
    if (!booked[venueIndex]) {
        cout << venues[venueIndex - 1] << " is available for booking." << endl;
    } else {
        cout << venues[venueIndex - 1] << " is already booked." << endl;
    }
}

void checkResources(int resourceIndex) {
    cout << "Enter resource code: " << endl;
    cin >> resourceIndex;

    if (!resource[resourceIndex]) {
        cout << equipment[resourceIndex - 1] << " is available for booking." << endl;
    } else {
        cout << equipment[resourceIndex - 1] << " is already booked." << endl;
    }
}

void bookResources(int resourceIndex) {
    cout << "Equipment List:" << endl;
    for (int i = 0; i < MAX_EQUIPMENT; i++) {
        cout << i + 1 << ". " << equipment[i] << " (" << price2[i] << ")" << endl;
    }

    cout << "Enter resource code: " << endl;
    cin >> resourceIndex;

    cout << "Booking " << equipment[resourceIndex - 1] << "..." << endl;
    cout << equipment[resourceIndex - 1] << " has been booked." << endl;

    // Log booking
    string logEntry = equipment[resourceIndex - 1] + " booked  " ;//+ getCurrentTime();
    saveToFile(logEntry);
}

void bookVendors(int vendorIndex) {
    cout << "Vendor List:" << endl;
    for (int i = 0; i < MAX_VENDORS; i++) {
        cout << i + 1 << ". " << vendors[i] << " (" << price3[i] << ")" << endl;
    }

    cout << "Enter vendor code: " << endl;
    cin >> vendorIndex;

    cout << "Booking " << vendors[vendorIndex - 1] << "..." << endl;
    cout << vendors[vendorIndex - 1] << " has been booked." << endl;

    // Log booking
    string logEntry = vendors[vendorIndex - 1] + " booked " ;//+ getCurrentTime();
    saveToFile(logEntry);
}

void displaySeatingChart() {
    cout << "\n*** Seating Chart ***" << endl;
    cout << "   ";
    for (int i = 1; i <= MAX_COLS; ++i) {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < MAX_ROWS; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < MAX_COLS; ++j) {
            cout << seatingChart[i][j] << " ";
        }
        cout << endl;
    }
}

void updateSeatingChart(int row, int col) {
    if (seatingChart[row][col] == 'O') {
        seatingChart[row][col] = 'X'; // X represents booked seats
        cout << "Seat booked successfully!" << endl;
    } else {
        cout << "Sorry, the seat is already booked. Please choose another seat." << endl;
    }
}

void displayWeather(string cityName) {
    ifstream inFile(cityName + ".txt");
    if (inFile.is_open()) {
        string weather;
        while (getline(inFile, weather)) {
            cout << weather << endl;
        }
        inFile.close();
    } else {
        cout << "Weather information for " << cityName << " not available." << endl;
    }
}

// Function to display daily calendar view
void displayDailyView()
{
    cout<<endl;
    cout << "Daily Calendar View:\n";
    cout << "Time Slots for each venue:\n";
    for(int i = 0; i < HOURS_IN_DAY; i++)
    {
        for(int j = 0; j < MAX_VENUES; j++)
        {
            cout << setw(2) << i+1 << " PM - " << (booked[j] ? "Booked" : "Available") << " (" << venues[j] << ")\n";
        }
    }
}

// Function to display weekly calendar view
void displayWeeklyView()
{
    cout<<endl;
    cout << "Weekly Calendar View:\n";
    for(int i = 0; i < DAYS_IN_WEEK; i++)
    {
        cout << "Day " << i+1 << ":\n";
        for(int j = 0; j < MAX_VENUES; j++)
        {
            cout << "  " << venues[j] << ": " << (booked[j] ? "Booked" : "Available") << "\n";
        }
    }
}

// Function to display monthly calendar view
void displayMonthlyView()
{
    cout<<endl;
    cout << "Monthly Calendar View:\n";
    for(int i = 0; i < WEEKS_IN_MONTH; i++)
    {
        cout << "Week " << i+1 << ":\n";
        for(int j = 0; j < DAYS_IN_WEEK; j++)
        {
            cout << "  Day " << j+1 << ":\n";
            for(int k = 0; k < MAX_VENUES; k++)
            {
                cout << "    " << venues[k] << ": " << (booked[k] ? "Booked" : "Available") << "\n";
            }
        }
    }
}


void readActivities() {
    ifstream inFile("activities.txt");
    if (inFile.is_open()) {
        while (inFile >> activities[numActivities].id
                      >> activities[numActivities].eventId
                      >> activities[numActivities].participantId
                      >> activities[numActivities].type
                      >> activities[numActivities].timestamp) {
            numActivities++;
            if (numActivities >= MAX_ACTIVITIES) break;
        }
        inFile.close();
    }
}

void writeActivities() {
    ofstream outFile("activities.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < numActivities; i++) {
            outFile << activities[i].id << " "
                    << activities[i].eventId << " "
                    << activities[i].participantId << " "
                    << activities[i].type << " "
                    << activities[i].timestamp << "\n";
        }
        outFile.close();
    }
}

void addActivity() {
    if (numActivities >= MAX_ACTIVITIES) {
        cout << "Max capacity reached." << endl;
        return;
    }

    cout << "Enter activity ID: ";
    cin >> activities[numActivities].id;
    cout << "Enter event ID: ";
    cin >> activities[numActivities].eventId;
    cout << "Enter participant ID: ";
    cin >> activities[numActivities].participantId;
    cout << "Enter activity type: ";
    cin >> activities[numActivities].type;
    cout << "Enter timestamp (YYYY-MM-DD HH:MM:SS): ";
    cin >> activities[numActivities].timestamp;
    cout << "Activity added successfully.";
    cout << endl;
    numActivities++;
    writeActivities();
}

void showActivities() {
    for (int i = 0; i < numActivities; i++) {
        cout << "Activity ID: " << activities[i].id
             << ", Event ID: " << activities[i].eventId
             << ", Participant ID: " << activities[i].participantId
             << ", Type: " << activities[i].type
             << ", Timestamp: " << activities[i].timestamp << endl;
    }
}

void loadEvents() {
    ifstream inFile("events.txt");
    Event evt;
    while (inFile >> evt.id >> evt.name >> evt.date >> evt.location) {
        if (numEvents < MAX_EVENTS) {
            events[numEvents++] = evt;
        }
    }
    inFile.close();
}

void saveEvents() {
    ofstream outFile("events.txt");
    for (int i = 0; i < numEvents; i++) {
        outFile << events[i].id << " "
                << events[i].name << " "
                << events[i].date << " "
                << events[i].location << endl;
    }
    outFile.close();
}

void createEvent() {
    if (numEvents >= MAX_EVENTS) {
        cout << "Max events reached." << endl;
        return;
    }

    Event newEvent;
    cout << "Enter event ID: ";
    cin >> newEvent.id;
    cin.ignore(); // Clear the buffer before taking string input
    cout << "Enter event name: ";
    getline(cin, newEvent.name);
    cout << "Enter event date (YYYY-MM-DD): ";
    getline(cin, newEvent.date);
    cout << "Enter event location: ";
    getline(cin, newEvent.location);

    events[numEvents++] = newEvent;
    saveEvents();
}

void listEvents() {
    for (int i = 0; i < numEvents; i++) {
        cout << "ID: " << events[i].id << ", Name: " << events[i].name
             << ", Date: " << events[i].date << ", Location: " << events[i].location << endl;
    }
}

void updateEvent() {
    int id;
    cout << "Enter event ID to update: ";
    cin >> id;
    for (int i = 0; i < numEvents; i++) {
        if (events[i].id == id) {
            cin.ignore(); // Clear the buffer before taking string input
            cout << "Enter new name: ";
            getline(cin, events[i].name);
            cout << "Enter new date (YYYY-MM-DD): ";
            getline(cin, events[i].date);
            cout << "Enter new location: ";
            getline(cin, events[i].location);
            saveEvents();
            return;
        }
    }
    cout << "Event not found." << endl;
}

void deleteEvent() {
    int id;
    cout << "Enter event ID to delete: ";
    cin >> id;
    bool found = false;
    int position = 0;
    for (int i = 0; i < numEvents; i++) {
        if (events[i].id == id) {
            found = true;
            position = i;
            break;
        }
    }
    if (found) {
        for (int i = position; i < numEvents - 1; i++) {
            events[i] = events[i + 1]; // Shift events down
        }
        numEvents--; // Decrease the count of events
        saveEvents();
    } else {
        cout << "Event not found." << endl;
    }
}

void createResourceBundle() {
    if (numResourceBundles >= MAX_RESOURCES) {
        cout << "Maximum number of bundles reached." << endl;
        return;
    }

    ResourceBundle &bundle = resourceBundles[numResourceBundles++];
    cout << "Enter bundle ID: ";
    cin >> bundle.bundleId;
    cin.ignore();  // Clears the input buffer
    cout << "Enter bundle name: ";
    getline(cin, bundle.bundleName);

    cout << "How many resources to add to this bundle? ";
    int count;
    cin >> count;
    bundle.numResources = count;
    for (int i = 0; i < count; i++) {
        cout << "Enter resource ID: ";
        cin >> bundle.resources[i].id;
        cin.ignore();
        cout << "Enter resource name: ";
        getline(cin, bundle.resources[i].name);
        cout << "Enter initial usage count: ";
        cin >> bundle.resources[i].usageCount;
    }
}

void displayResourceBundles() {
    for (int i = 0; i < numResourceBundles; i++) {
        ResourceBundle &bundle = resourceBundles[i];
        cout << "Bundle ID: " << bundle.bundleId << ", Name: " << bundle.bundleName << endl;
        for (int j = 0; j < bundle.numResources; j++) {
            cout << "  Resource ID: " << bundle.resources[j].id
                 << ", Name: " << bundle.resources[j].name
                 << ", Usage: " << bundle.resources[j].usageCount << endl;
        }
    }
}

void checkMaintenance() {
    cout << "Maintenance check for all resources:" << endl;
    for (int i = 0; i < numResourceBundles; i++) {
        for (int j = 0; j < resourceBundles[i].numResources; j++) {
            if (resourceBundles[i].resources[j].usageCount >= 1000) {
                cout << "Resource ID: " << resourceBundles[i].resources[j].id
                     << " (" << resourceBundles[i].resources[j].name << ")"
                     << " requires maintenance." << endl;
            } else
            cout << "Resource ID: " << resourceBundles[i].resources[j].name << "requires no maintainance."<<endl;
        }
    }
}

void displayMenu() {
    cout << endl;

    cout << "                                                 MAIN MENU                                                                \n";
    cout << "__________________________________________________________________________________________________________________\n";
    cout << "\t\t1. Display Venues  \t\t2. Display Food  \t\t3. Display desserts                                                \n";
    cout << "\t\t4. Display Drinks   \t\t5. Book Event    \t\t6. Unbook Event                                 \n";
    cout << "\t\t7. Check Resources    \t\t8. Check Venue Availability  \t9. Display Seating Chart                                         \n";
    cout << "\t\t10. Book a seat        \t\t11.  Display Weather   \t\t12. Review Daily Calender                 \n";
    cout << "\t\t13. Review Weekly Calender  \t14. Review Monthly Calender    \t15. Exit                                     .\n";
    cout << "__________________________________________________________________________________________________________________\n";
}

void adduser() {
    if (userCount >= MAX_userS) {
        cout << "user limit reached. Cannot add more users.\n";
        return;
    }

    user newuser;
    newuser.id = userCount + 1;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newuser.name);
    cout << "Enter email: ";
    getline(cin, newuser.email);
    cout << "Enter phone: ";
    getline(cin, newuser.phone);

    users[userCount] = newuser;
    userCount++;
    cout << "user added successfully!\n";
}

void viewusers() {
    if (userCount == 0) {
        cout << "No users to display.\n";
        return;
    }

    for (int i = 0; i < userCount; i++) {
        cout << "ID: " << users[i].id << "\n";
        cout << "Name: " << users[i].name << "\n";
        cout << "Email: " << users[i].email << "\n";
        cout << "Phone: " << users[i].phone << "\n";
        cout << "--------------------------\n";
    }
}

void updateuser() {
    int id;
    cout << "Enter user ID to update: ";
    cin >> id;

    int index = finduserById(id);
    if (index == -1) {
        cout << "user not found.\n";
        return;
    }

    cout << "Enter new name (or press enter to keep current): ";
    cin.ignore();
    getline(cin, users[index].name);
    cout << "Enter new email (or press enter to keep current): ";
    getline(cin, users[index].email);
    cout << "Enter new phone (or press enter to keep current): ";
    getline(cin, users[index].phone);

    cout << "user updated successfully!\n";
}

void deleteuser() {
    int id;
    cout << "Enter user ID to delete: ";
    cin >> id;

    int index = finduserById(id);
    if (index == -1) {
        cout << "user not found.\n";
        return;
    }

    for (int i = index; i < userCount - 1; i++) {
        users[i] = users[i + 1];
    }
    userCount--;
    cout << "user deleted successfully!\n";
}

int finduserById(int id) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            return i;
        }
    }
    return -1;
}

void saveToFile() {
    ofstream file(FILENAME);

    if (!file) {
        cout << "Error saving to file.\n";
        return;
    }

    file << userCount << "\n";
    for (int i = 0; i < userCount; i++) {
        file << users[i].id << "\n";
       file << users[i].name << "\n" ;
       file << users[i].email <<"\n";
       file << users[i].phone <<"\n";

   }

    file.close();
    cout << "Data saved successfully!\n";
}

void loadFromFile() {
    ifstream file(FILENAME);

    if (!file) {
        cout << "No existing data file found. Starting with empty user list.\n";
        return;
    }

    file >> userCount;
    file.ignore();  // Ignore the newline character after the count

    for (int i = 0; i < userCount; i++) {
        file >> users[i].id;
        file.ignore();  // Ignore the newline character after the id
        getline(file, users[i].name);
        getline(file, users[i].email);
        getline(file, users[i].phone);
    }
//     cout << "Data loaded successfully!\n";
    file.close();

}

