#ifndef MENU_HPP
#define MENU_HPP

class Menu {
public:
    static void run();
    static void displayMainMenu();
    static int getUserChoice();

    static void handleAddEmployee();
    static void handleShowAllEmployees();
    static void handleFindByNumber();
    static void handleFindByLastName();
    static void handleClearDatabase();
};

#endif