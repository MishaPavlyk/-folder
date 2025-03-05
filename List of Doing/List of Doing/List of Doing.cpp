#include <iostream>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <vector>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// Structure to store information about a task
struct Task {
    string name;
    string description;
    string priority;
    string time;
};

vector<Task> tasks; // Dynamic list of tasks

void ReWriteData() {
    // Add some test tasks
    tasks.push_back({ "Tidy up", "Clear the table, take clothes to the laundry", "Low", "11:25" });
    tasks.push_back({ "Vacuum the apartment", "Vacuum the living room, kitchen, bedroom. If possible, the balcony too", "High", "13:00" });
    tasks.push_back({ "Pick up the package", "Pick up the package from Nova Poshta", "Low", "9:00" });
    tasks.push_back({ "Meet friends", "Meet friends at Pirogova 25, discuss the new apartment in the Kyiv area", "High", "9:26" });
    tasks.push_back({ "Go to exams", "Go to English language exams, review upon arrival.", "High", "14:45" });
}

typedef void (*Command)();

const size_t COMMAND_NAME_SIZE = 30;

struct CommandInfo {
    char name[COMMAND_NAME_SIZE];
    Command command;
};

// Activated commands
void ShowTask();
void DeleteTask();
void EditTask();
void SearchTask();
void SortTask();
void AddTask();
void SortList();
void HideMenu();
void SaveTask();
void LoadTask(); // New command to load the table
bool null;

// Commands (do not change)
CommandInfo commandsInfo[] = {
    {"Exit", nullptr},
    {"Show tasks", ShowTask},
    {"Add task", AddTask},
    {"Delete task", DeleteTask},
    {"Edit task", EditTask},
    {"Search task", SearchTask},
    {"Sort tasks", SortTask},
    {"", nullptr},
    {"", nullptr},
    {"", nullptr},
    {"Hide menu", HideMenu},
    {"Save table", SaveTask},
    {"Load table", LoadTask}, // Added new command
};

const size_t COMMANDS_COUNT = sizeof commandsInfo / sizeof(CommandInfo);

void InputComm() {
    for (size_t i = 0; i < COMMANDS_COUNT; i++) {
        if (i != 7 && i != 8 && i != 9) {
            cout << setw(4) << i << " - " << commandsInfo[i].name << endl;
        }
        else {
            cout << "\n";
        }
    }
}

void ListOfTasks() {
    if (tasks.empty()) {
        cout << "\tAll cells are empty, create a new one." << endl;
    }
    else {
        constexpr size_t width_n = 31;
        constexpr size_t width_p = 15;
        constexpr size_t width_d = 80;
        cout << "Name" << setw(36) << "Priority" << "\tDescription" << setw(80) << "\tTime\n" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            const size_t needChars_n = width_n - tasks[i].name.length();
            const size_t needChars_p = width_p - tasks[i].priority.length();
            const size_t needChars_d = width_d - tasks[i].description.length();
            cout << i + 1 << ". " << setw(10) << tasks[i].name << string(needChars_n, ' ')
                << tasks[i].priority << string(needChars_p, ' ')
                << tasks[i].description << string(needChars_d, ' ')
                << tasks[i].time << endl;
        }
    }
}

Command command;

int EnterNumber(const char* prompt) {
    int number;
    cout << "\n  " << prompt << " : ";
    cin >> number;
    return number;
}

Command EnterCommand() {
    int index = EnterNumber("Enter a number");
    return commandsInfo[index].command;
}

Command LastCommand;

// Command selection (do not change!)
void ChoosingWork(Command command) {
    if (command == ShowTask) {
        ShowTask();
    }
    else if (command == AddTask) {
        AddTask();
    }
    else if (command == SaveTask) {
        SaveTask();
    }
    else if (command == DeleteTask) {
        DeleteTask();
    }
    else if (command == EditTask) {
        EditTask();
    }
    else if (command == SearchTask) {
        SearchTask();
    }
    else if (command == SortTask) {
        SortTask();
    }
    else if (command == LoadTask) {
        LoadTask();
    }
}

bool ActiveMenu = true;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool WORKING = true;
    null = true;
    ReWriteData();
    do {
        std::system("cls");
        cout << "\t\t\t\t\t\t\t\t\t" << "Task List" << endl;
        ListOfTasks();
        cout << "\n\n";
        if (ActiveMenu == true) {
            cout << "COMMANDS" << endl;
            InputComm();
            Command command = EnterCommand();
            if (command == nullptr) {
                WORKING = false;
            }
            else if (command == HideMenu) {
                ActiveMenu = false;
            }
            else {
                ChoosingWork(command); // Command selection
                LastCommand = command;
            }
        }
        else {
            cout << "\n\n\t10 - Open menu" << endl;
            Command command = EnterCommand();
            if (command == HideMenu) {
                ActiveMenu = true;
            }
        }

    } while (WORKING == true);

    return 0;
}

// Commands
void HideMenu() {}

bool ShowTaskActivated = false;

void ShowTask() {
    if (tasks.empty()) {
        null = true;
    }
    else {
        null = false;
        ShowTaskActivated = true;
    }
}

void DeleteTask() {
    if (ShowTaskActivated == true) {
        int UserChoose = 0;
        bool comp = false;
        do {
            cout << "\n\tDelete task: \n \t1 - Completely \t2 - Specific part" << endl << "\t";
            cin >> UserChoose;
            if (UserChoose == 1) {
                cout << "\n\tDo you want to delete all tasks, or one of them? \t 1 - One of them \t 2 - All tasks: " << endl << "\t";
                cin >> UserChoose;
                if (UserChoose == 1) {
                    cout << "\n\tEnter the task number: \n\t";
                    cin >> UserChoose;
                    if (UserChoose > 0 && UserChoose <= tasks.size()) {
                        tasks.erase(tasks.begin() + UserChoose - 1);
                    }
                    else {
                        cout << "\n\tInvalid task number!";
                        Sleep(2000);
                    }
                }
                else if (UserChoose == 2) {
                    string UserC;
                    cout << "\n\tAre you sure? - \"Yes\" \t-\t \"No\"\n\t";
                    cin >> UserC;
                    if (UserC == "Yes") {
                        tasks.clear();
                        null = true;
                    }
                }
                comp = true;
            }
            else if (UserChoose == 2) {
                cout << "\n\tEnter the paragraph number: " << endl << "\t";
                cin >> UserChoose;
                if (UserChoose > 0 && UserChoose <= tasks.size()) {
                    cout << "\n\t What exactly do you want to delete?\n1 - " << tasks[UserChoose - 1].name << "\t2 - " << tasks[UserChoose - 1].priority << "\t3 - " << tasks[UserChoose - 1].description << "\t4 - " << tasks[UserChoose - 1].time << endl;
                    int UserChoosen;
                    cin >> UserChoosen;
                    if (UserChoosen == 1) {
                        cout << "\n\tEnter new value (up to 31 characters):  " << endl << "\t";
                        cin.get();
                        getline(cin, tasks[UserChoose - 1].name);
                    }
                    else if (UserChoosen == 2) {
                        cout << "\n\tEnter new value (up to 15 characters): " << endl << "\t";
                        cin.get();
                        getline(cin, tasks[UserChoose - 1].priority);
                    }
                    else if (UserChoosen == 3) {
                        cout << "\n\tEnter new value (up to 80 characters): " << endl << "\t";
                        cin.get();
                        getline(cin, tasks[UserChoose - 1].description);
                    }
                    else if (UserChoosen == 4) {
                        cout << "\n\tEnter new value (Digits only (up to 2)): " << endl << "\t";
                        string Hour;
                        string Min;
                        bool cor = false;
                        do {
                            Sleep(1000);
                            cout << "\n\tEnter hour: " << endl << "\t";
                            cin >> setw(2) >> Hour;
                            if (Hour == "00" || Hour == "01" || Hour == "02" || Hour == "03" || Hour == "04" || Hour == "05" || Hour == "06" || Hour == "07" || Hour == "08" || Hour == "09" || Hour == "10" || Hour == "11" || Hour == "12" || Hour == "13" || Hour == "14" || Hour == "15" || Hour == "16" || Hour == "17" || Hour == "18" || Hour == "19" || Hour == "20" || Hour == "21" || Hour == "22" || Hour == "23" || Hour == "24") {
                                cor = true;
                            }
                        } while (cor == false);
                        cor = false;
                        do {
                            Sleep(1000);
                            cout << "\n\tEnter minutes: " << endl << "\t";
                            cin >> setw(2) >> Min;
                            if (Min == "00" || Min == "01" || Min == "02" || Min == "03" || Min == "04" || Min == "05" || Min == "06" || Min == "07" || Min == "08" || Min == "09" || Min == "10" || Min == "11" || Min == "12" || Min == "13" || Min == "14" || Min == "15" || Min == "16" || Min == "17" || Min == "18" || Min == "19" || Min == "20" || Min == "21" || Min == "22" || Min == "23" || Min == "24" || Min == "25" || Min == "26" || Min == "27" || Min == "28" || Min == "29" || Min == "30" || Min == "31" || Min == "32" || Min == "33" || Min == "34" || Min == "35" || Min == "36" || Min == "37" || Min == "38" || Min == "39" || Min == "40" || Min == "41" || Min == "42" || Min == "43" || Min == "44" || Min == "45" || Min == "46" || Min == "47" || Min == "48" || Min == "49" || Min == "50" || Min == "51" || Min == "52" || Min == "53" || Min == "54" || Min == "55" || Min == "56" || Min == "57" || Min == "58" || Min == "59") {
                                cor = true;
                            }
                        } while (cor == false);
                        string Time = Hour + ":" + Min;
                        tasks[UserChoose - 1].time = Time;
                    }
                    else {
                        cout << "\nYou entered an invalid value";
                        Sleep(5000);
                    }
                }
                comp = true;
            }
            else {
                cout << "Error, you entered an invalid value";
                Sleep(2000);
            }
        } while (comp != true);

    }
    else {
        std::system("cls");
        cout << "\n\t\t\t\t\t\tERROR\n\t\tThe table is empty, create it\n";
        Sleep(3000);
    }
}

void AddTask() {
    if (ShowTaskActivated == true) {
        Task newTask;
        cin.get();
        cout << "\n\tName (up to 30 characters): ";
        getline(cin, newTask.name);
        cout << "\n\tPriority (up to 15 characters): ";
        getline(cin, newTask.priority);
        cout << "\n\tDescription (up to 80 characters): ";
        getline(cin, newTask.description);

        // Введення годин
        int hour;
        do {
            cout << "\n\tEnter hour (0-23): ";
            cin >> hour;
        } while (hour < 0 || hour > 23);

        // Введення хвилин
        int minute;
        do {
            cout << "\n\tEnter minute (0-59): ";
            cin >> minute;
        } while (minute < 0 || minute > 59);

        // Форматування часу у вигляді "HH:MM"
        char buffer[6];
        sprintf_s(buffer, sizeof(buffer), "%02d:%02d", hour, minute); // Використання sprintf_s
        newTask.time = buffer;

        tasks.push_back(newTask);
    }
    else {
        std::system("cls");
        cout << "\n\t\t\t\t\t\tERROR\n\t\tThe table is empty, create it\n";
        Sleep(3000);
    }
}

void EditTask() {
    if (ShowTaskActivated == true) {
        size_t UC; // Використовуємо size_t замість int
        cout << "\n\tEdit task: \n \t1 - Completely \t2 - Specific part" << endl << "\t";
        cin >> UC;
        if (UC == 1) {
            cout << "\n\tEnter the task number: \n\t";
            cin >> UC;
            cin.get();
            if (UC > 0 && UC <= tasks.size()) { // Тепер порівняння коректне
                cout << "\n\tName (up to 30 characters): ";
                getline(cin, tasks[UC - 1].name);
                cout << "\n\tPriority (up to 15 characters): ";
                getline(cin, tasks[UC - 1].priority);
                cout << "\n\tDescription (up to 80 characters): ";
                getline(cin, tasks[UC - 1].description);

                // Введення годин
                int hour;
                do {
                    cout << "\n\tEnter hour (0-23): ";
                    cin >> hour;
                } while (hour < 0 || hour > 23);

                // Введення хвилин
                int minute;
                do {
                    cout << "\n\tEnter minute (0-59): ";
                    cin >> minute;
                } while (minute < 0 || minute > 59);

                // Форматування часу у вигляді "HH:MM"
                char buffer[6];
                sprintf_s(buffer, sizeof(buffer), "%02d:%02d", hour, minute); // Використання sprintf_s
                tasks[UC - 1].time = buffer;
            }
            else {
                cout << "\n\tYou entered an invalid value" << endl;
                Sleep(1000);
            }
        }
        // Інші частини функції залишаються без змін
    }
    else {
        std::system("cls");
        cout << "\n\t\t\t\t\t\tERROR\n\t\tThe table is empty, create it\n";
        Sleep(3000);
    }
}

void SearchTask() {
    if (ShowTaskActivated == true) {
        cout << "\n\tEnter the word you want to find: \n\t";
        cin.get();
        string FoundName;
        int tr = 0;
        getline(cin, FoundName);
        if (FoundName != "") {
            std::system("cls");
            cout << "\t\t\t\t\t\t\t\t\t" << "Task List" << endl;
            cout << "Name" << setw(36) << "Priority" << "\tDescription" << setw(80) << "\tTime\n" << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                if (FoundName == tasks[i].name || FoundName == tasks[i].priority || FoundName == tasks[i].description || FoundName == tasks[i].time) {
                    const size_t needChars_n = 31 - tasks[i].name.length();
                    const size_t needChars_p = 15 - tasks[i].priority.length();
                    const size_t needChars_d = 80 - tasks[i].description.length();
                    cout << i + 1 << ". " << setw(10) << tasks[i].name << string(needChars_n, ' ')
                        << tasks[i].priority << string(needChars_p, ' ')
                        << tasks[i].description << string(needChars_d, ' ')
                        << tasks[i].time << endl;
                }
            }
            cout << "\n";
            std::system("pause");
        }
        else {
            cout << "\n\tYou entered an invalid value...";
            Sleep(3000);
        }
    }
    else {
        std::system("cls");
        cout << "\n\t\t\t\t\t\tERROR\n\t\tThe table is empty, create it\n";
        Sleep(3000);
    }
}

string UserChooseSort;

void SortTask() {
    if (ShowTaskActivated == true) {
        string TempName1 = "", TempName2 = "", TempName3 = "", TempName4 = "", TempName5 = "", TempName6 = "", TempName7 = "", TempName8 = "", TempName9 = "", TempName10 = "";
        for (size_t i = 0; i < tasks.size(); i++) {
            if (tasks[i].priority != "" && TempName1 == "") {
                TempName1 = tasks[i].priority;
            }
            else if (tasks[i].priority != "" && TempName2 == "") {
                if (TempName1 != tasks[i].priority) {
                    TempName2 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName3 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority) {
                    TempName3 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName4 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority) {
                    TempName4 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName5 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority && TempName4 != tasks[i].priority) {
                    TempName5 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName6 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority && TempName4 != tasks[i].priority && TempName5 != tasks[i].priority) {
                    TempName6 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName7 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority && TempName4 != tasks[i].priority && TempName5 != tasks[i].priority && TempName6 != tasks[i].priority) {
                    TempName7 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName8 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority && TempName4 != tasks[i].priority && TempName5 != tasks[i].priority && TempName6 != tasks[i].priority && TempName7 != tasks[i].priority) {
                    TempName8 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName9 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority && TempName4 != tasks[i].priority && TempName5 != tasks[i].priority && TempName6 != tasks[i].priority && TempName7 != tasks[i].priority && TempName8 != tasks[i].priority) {
                    TempName9 = tasks[i].priority;
                }
            }
            else if (tasks[i].priority != "" && TempName10 == "") {
                if (TempName1 != tasks[i].priority && TempName2 != tasks[i].priority && TempName3 != tasks[i].priority && TempName4 != tasks[i].priority && TempName5 != tasks[i].priority && TempName6 != tasks[i].priority && TempName7 != tasks[i].priority && TempName8 != tasks[i].priority && TempName10 != tasks[i].priority) {
                    TempName10 = tasks[i].priority;
                }
            }
        }
        cout << "\n\tSort by:";
        if (TempName1 != "")
            cout << "\n\t-" << TempName1;
        if (TempName2 != "")
            cout << "\n\t-" << TempName2;
        if (TempName3 != "")
            cout << "\n\t-" << TempName3;
        if (TempName4 != "")
            cout << "\n\t-" << TempName4;
        if (TempName5 != "")
            cout << "\n\t-" << TempName5;
        if (TempName6 != "")
            cout << "\n\t-" << TempName6;
        if (TempName7 != "")
            cout << "\n\t-" << TempName7;
        if (TempName8 != "")
            cout << "\n\t-" << TempName8;
        if (TempName9 != "")
            cout << "\n\t-" << TempName9;
        if (TempName10 != "")
            cout << "\n\t-" << TempName10;
        cin.get();
        do {
            cout << "\n\tEnter text:\t";
            getline(cin, UserChooseSort);
        } while (UserChooseSort != TempName1 && UserChooseSort != TempName2 && UserChooseSort != TempName3 && UserChooseSort != TempName4 && UserChooseSort != TempName5 && UserChooseSort != TempName6 && UserChooseSort != TempName7 && UserChooseSort != TempName8 && UserChooseSort != TempName9 && UserChooseSort != TempName10);
        SortList();
    }
    else {
        std::system("cls");
        cout << "\n\t\t\t\t\t\tERROR\n\t\tThe table is empty, create it\n";
        Sleep(3000);
    }

}
void SortList() {
    vector<Task> sortedTasks;
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].priority == UserChooseSort) {
            sortedTasks.push_back(tasks[i]);
        }
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        if (tasks[i].priority != UserChooseSort) {
            sortedTasks.push_back(tasks[i]);
        }
    }
    tasks = sortedTasks;
}

void SaveTask() {
    constexpr size_t width_n = 31;
    constexpr size_t width_p = 15;
    constexpr size_t width_d = 80;

    // Use the correct file path
    ofstream file("E:/Savefile/Misha.txt", ios_base::out); // Overwrite the file each time

    if (!file.is_open()) {
        cout << "\n\tError: failed to open file for saving.\n";
        std::system("pause");
        return;
    }

    for (size_t i = 0; i < tasks.size(); i++) {
        file << left << setw(3) << i + 1 << ". "
            << setw(width_n) << tasks[i].name
            << setw(width_p) << tasks[i].priority
            << setw(width_d) << tasks[i].description
            << tasks[i].time << endl;
    }

    file.close();
    cout << "\n\tTable saved.\n";
    std::system("pause");
}

void LoadTask() {
    ifstream file("E:/Savefile/Misha.txt", ios_base::in); // Open the file for reading

    if (!file.is_open()) {
        cout << "\n\tError: failed to open file for loading.\n";
        std::system("pause");
        return;
    }

    tasks.clear(); // Clear the current task list

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        size_t pos1 = line.find(". ");
        size_t pos2 = line.find(" ", pos1 + 2);
        size_t pos3 = line.find(" ", pos2 + 1);
        size_t pos4 = line.find(" ", pos3 + 1);

        Task newTask;
        newTask.name = line.substr(pos1 + 2, pos2 - (pos1 + 2));
        newTask.priority = line.substr(pos2 + 1, pos3 - (pos2 + 1));
        newTask.description = line.substr(pos3 + 1, pos4 - (pos3 + 1));
        newTask.time = line.substr(pos4 + 1);

        tasks.push_back(newTask);
    }

    file.close();
    cout << "\n\tTable loaded.\n";
    std::system("pause");
}