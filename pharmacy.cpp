#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

// Team Members: [List team members' names here]

// Define struct for medicine
struct Medicine {
    string name;
    double dose;
    int price;
};
// Define struct for Bills
struct Bill {
    string customerName;
    string date;
    double totalAmount;
    vector<Medicine> medicines; // Vector to store multiple medicines in a bill
};
// variables
const int MAX_SIZE=200;

// Function prototypes


// Function to manage bills, including generating new bills, reading all bills, and exiting
void manageBills(const Medicine meds[], int count);

// Function to create a new bill based on selected medicines
void createBill(const Medicine meds[], int count);

// Function to display the details of a bill
void displayBill(const Bill& bill);

// Function to save a bill to a file
void saveBill(const Bill& bill);

// Function to read all bills from a file
void readAllBills();

// Function to allow the user to choose medicines for a bill
void chooseMedicines(const Medicine meds[], int count);

// Function to add a new item (medicine) to the inventory
void addNewItem(Medicine meds[], int& count);

// Function to search for a specific item (medicine) in the inventory
void searchItem(const Medicine meds[], int count);

// Function to update an existing record (medicine) in the inventory
void updateRecord(Medicine meds[], int count);

// Function to delete an item (medicine) from the inventory
void deleteItem(Medicine meds[], int& count);

// Function to sort medicines in the inventory
void sortMeds(Medicine meds[], int count);

// Function to display all medicines in the inventory
void displayMeds(const Medicine meds[], int count);

// Function to save inventory data to a file
void saveToFile(const Medicine meds[], int count);

// Function to manage reports, including generating and reading reports
void reportsManagement(int count);

// Function to read reports from a file
string readReports();

// Function to generate a report
void generateReport(int count);



//main func
int main() {
    int arraySize;
    cout << "Enter the size of the medicines array: ";
    while (!(cin >> arraySize) || arraySize <= 0 || arraySize>MAX_SIZE ) {
        cout << "Invalid input. Please enter a positive integer for array size: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    Medicine* medicines = new Medicine[arraySize];
    int medsCount = 0;
    char choice;

    // Load data from file
    ifstream inFile("medicines.txt");
    if (inFile.is_open()) {
        while (medsCount < arraySize && inFile >> medicines[medsCount].name >> medicines[medsCount].dose >>medicines[medsCount].price ) {
            medsCount++;
        }
        inFile.close();
    } else {
      //  cout << "Error opening file. or File is empty.\n";
      //  delete[] medicines; // Free allocated memory
       // return 1;
    }

    // Menu loop
    do {
        system("cls");
        cout << "\n\t\t\t\tMain Menu\n\n\n";
        cout << "0. Manage Bills\n";
        cout << "1. Add New Item\n";
        cout << "2. Search for Specific Item\n";
        cout << "3. Update Existing Record\n";
        cout << "4. Delete Item\n";
        cout << "5. Sort Medicines\n";
        cout << "6. Display Medicines\n";
        cout << "7. Save to File\n";
        cout << "8. Report Mangement\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        system("cls");
        switch (choice) {
            case '0':
                manageBills(medicines, medsCount);
                break;
            case '1':
                addNewItem(medicines, medsCount);
                break;
            case '2':
                searchItem(medicines, medsCount);
                break;
            case '3':
                updateRecord(medicines, medsCount);
                break;
            case '4':
                deleteItem(medicines, medsCount);
                break;
            case '5':
                sortMeds(medicines, medsCount);
                break;
            case '6':
                displayMeds(medicines, medsCount);           
                break;
            case '7':
                saveToFile(medicines, medsCount);
                break;
            case '8':
                reportsManagement(medsCount);
                break;
            case '9':
          // Save data to file before exiting
                saveToFile(medicines, medsCount);
                delete[] medicines; // Free allocated memory
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
        cout<<endl<<endl<<endl;
        system("pause");
    } while (choice != '9');

    return 0;
}

//manageBills func
void manageBills(const Medicine meds[], int count) {
    char choice;
    do {
        system("cls");
        cout << "\n\t\t\t\tBill Management Menu\n\n\n";
        cout << "1. Generate New Bill\n";
        cout << "2. Read All Bills\n";
        cout << "3. Exit Bill Management\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");
        switch (choice) {
            case '1':
                createBill(meds, count);
                system("pause");
                break;
            case '2':
                readAllBills();
                system("pause");
                break;
            case '3':
                cout << "Exiting Bill Management.\n";
                break;
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
        cout << endl << endl << endl;
    //    system("pause");
    } while (choice != '3');
}

// Function to manage reports
void reportsManagement(int count)
{
	char choice;
        system("cls");
        cout << "\n\t\t\t\tReports Menu\n\n\n";
        cout << "1. Generate Report\n";
        cout << "2. Read Reports\n";
        cout << "3. Go Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        system("cls");
        switch (choice) {
            case '1':
                generateReport(count);
                break;
            case '2':
        {
                string reports = readReports();
                cout << reports;}
                break;
            case '3':
                cout << "Going Back.\n";
                break;
            default:
                cout << "Invalid choice! Please enter again.\n";
        }
        cout<<endl<<endl<<endl;

	
	}


// Function to add a new item to the array
void addNewItem(Medicine meds[], int& count) {
    if (count < 100) {
        cout << "Enter medicine name: ";
        getline(cin, meds[count].name);
        cout << "Enter dose: ";
        while (!(cin >> meds[count].dose) || meds[count].dose <= 0) {
            cout << "Invalid input. Please enter a positive number for dose: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // Clear input buffer
               cout << "Enter price: ";
        while (!(cin >> meds[count].price) || meds[count].price <= 0) {
            cout << "Invalid input. Please enter a positive number for price: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(); // Clear input buffer
        count++;
        cout << "Medicine added successfully.\n";
    } else {
        cout << "Maximum medicines limit reached!\n";
    }
}


// Function to search for a specific item in the array
void searchItem(const Medicine meds[], int count) {
    string searchName;
    cout << "Enter medicine name to search: ";
 getline(cin, searchName);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (meds[i].name == searchName) {
            cout << "Medicine found:\n";
            cout << "Name: " << meds[i].name << endl;
            cout << "Dose: " << meds[i].dose << endl;
            cout << "Price: " << meds[i].price << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Medicine not found.\n";
    }
}


// Function to update an existing record in the array
void updateRecord(Medicine meds[], int count) {
   string updateName;
    cout << "Enter medicine name to update: ";
    getline(cin, updateName);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (meds[i].name == updateName) {
            cout << "Enter new dose: ";
            while (!(cin >> meds[i].dose) || meds[i].dose <= 0) {
                cout << "Invalid input. Please enter a positive number for dose: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(); // Clear input buffer
            cout << "Enter new price ";
            while (!(cin >> meds[i].price) || meds[i].price <= 0) {
                cout << "Invalid input. Please enter a positive number for price ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(); // Clear input buffer
            cout << "Record updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Medicine not found.\n";
    }
}

// Function to delete an item from the array
void deleteItem(Medicine meds[], int& count) {
      string deleteName;
    cout << "Enter medicine name to delete: ";
    getline(cin, deleteName);
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (meds[i].name == deleteName) {
            for (int j = i; j < count - 1; j++) {
                meds[j] = meds[j + 1];
            }
            count--;
            cout << "Medicine deleted successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Medicine not found.\n";
    }
}

// Function to sort medicines by name
void sortMeds(Medicine meds[], int count) {
    // Sort medicines by name (bubble sort)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (meds[j].name > meds[j + 1].name) {
                Medicine temp = meds[j];
                meds[j] = meds[j + 1];
                meds[j + 1] = temp;
            }
        }
    }
    cout << "Medicines sorted by name.\n";
}


   // Function to display all medicines in the array
void displayMeds(const Medicine meds[], int count) {
    if (count != 0) {
        cout << "Medicines List:\n\n ";
        cout << "ID" << "| Name " << " | Dose" << " | Price"<< endl << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << "  | " << meds[i].name << "  |   " << meds[i].dose << "  |   " << meds[i].price << endl;
        }
    } else {
        cout << "No Data Yet.\n";
    }
}


// Function to save medicines data to file
void saveToFile(const Medicine meds[], int count) {
    ofstream outFile("medicines.txt");
    if (outFile.is_open()) {
        for (int i = 0; i < count; i++) {
            if(i!=count-1)
            {
            outFile << meds[i].name << " " << meds[i].dose  << " " << meds[i].price << endl;}
            else{
            	outFile << meds[i].name << " " << meds[i].dose << " " << meds[i].price;
            	}
        }
        outFile.close();
        cout << "Data saved to file.\n";
    } else {
        cout << "Error saving to file.\n";
    }
}

// Function to read reports from file and return as a string
string readReports() {
    string reports;
    ifstream inFile("report.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            reports += line + "\n";
        }
        inFile.close();
    }
    return reports;
}
// report generate func
void generateReport(int count) {
   ofstream reportFile("report.txt", ios::app); // Append mode to add new report at the beginning
    if (reportFile.is_open()) {
        // Generate new report
        string newReport = "Number of Records: " + to_string(count) + "\n";
        time_t now = time(0);
        tm* currentTime = localtime(&now);
        newReport += "Last Update Date: " + to_string(currentTime->tm_mday) + "/" + to_string(currentTime->tm_mon + 1) + "/" + to_string(currentTime->tm_year + 1900) + "\n";
        newReport += "Last Update Time: " + to_string(currentTime->tm_hour) + ":" + to_string(currentTime->tm_min) + ":" + to_string(currentTime->tm_sec) + "\n\n";

reportFile << newReport;
        reportFile.close();
        cout << "Report generated and added to file.\n";
    } else {
        cout << "Error generating report.\n";
    }

}

// Function to allow the user to choose medicines for the bill by name
void chooseMedicines(const Medicine meds[], int count, Bill& bill) {
    // Display medicines list for selection
    cout << "\nMedicines List:\n\n";
    cout << "ID" << "| Name " << " | Dose" << " | Price" << endl << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << "  | " << meds[i].name << "  |   " << meds[i].dose << "  |   " << meds[i].price << endl;
    }

    // Ask user to enter medicine names for the bill
    string medicineName;
    do {
        cout << "\nEnter medicine name to add to the bill (or '0' to finish): ";
        getline(cin, medicineName);
        if (medicineName != "0") {
            bool found = false;
            for (int i = 0; i < count; i++) {
                if (meds[i].name == medicineName) {
                    bill.medicines.push_back(meds[i]); // Add selected medicine to bill
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Medicine not found! Please enter a valid medicine name.\n";
            }
        }
    } while (medicineName != "0");
}
void createBill(const Medicine meds[], int count) {
    Bill bill;
    cout << "Enter customer name: ";
    getline(cin, bill.customerName);
    
    // Get current date
    time_t now = time(0);
    tm* currentTime = localtime(&now);
    bill.date = to_string(currentTime->tm_mday) + "/" + to_string(currentTime->tm_mon + 1) + "/" + to_string(currentTime->tm_year + 1900);
    
    chooseMedicines(meds, count, bill);

    // Calculate total amount
    bill.totalAmount = 0;
    for (const auto& med : bill.medicines) {
        bill.totalAmount += med.price;
    }

    // Display and save the bill
    displayBill(bill);
    saveBill(bill);

    // Clear the bill from memory
    bill.customerName.clear();
    bill.date.clear();
    bill.totalAmount = 0;
    bill.medicines.clear();
}
// Function to display the bill
void displayBill(const Bill& bill) {
    cout << "\nBill Details:\n";
    cout << "Customer Name: " << bill.customerName << endl;
    cout << "Date: " << bill.date << endl;
    cout << "Medicines:\n";
    cout << "ID" << "| Name " << " | Dose" << " | Price" << endl << endl;
    for (size_t i = 0; i < bill.medicines.size(); i++) {
        const Medicine& med = bill.medicines[i];
        cout << i + 1 << "  | " << med.name << "  |   " << med.dose << "  |   " << med.price << endl;
    }
    cout << "\nTotal Amount: " << bill.totalAmount << endl;
}

// Function to save the bill to a file
void saveBill(const Bill& bill) {
    ofstream outFile("bills.txt", ios::app); // Append mode to add new bill at the end
    if (outFile.is_open()) {
        outFile << "Customer Name: " << bill.customerName << endl;
        outFile << "Date: " << bill.date << endl;
        outFile << "Medicines:\n";
        for (const auto& med : bill.medicines) {
            outFile << "Name: " << med.name << "  | Dose: " << med.dose << "  | Price: " << med.price << endl;
        }
        outFile << "Total Amount: " << bill.totalAmount << endl << endl;
        outFile.close();
        cout << "Bill saved to file.\n";
    } else {
        cout << "Error saving bill to file.\n";
    }
}
// Function to read all bills from the file
void readAllBills() {
    ifstream inFile("bills.txt");
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl; // Display each line (bill) in the file
        }
        inFile.close();
    } else {
        cout << "Error opening file.\n";
    }
}