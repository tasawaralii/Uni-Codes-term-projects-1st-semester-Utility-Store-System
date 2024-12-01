#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <fstream>

using namespace std;

// Function Prototypes

void gotoxy(int x, int y);

void setcolor(int color);

string getString(int limit,bool hide = false,bool alphaOnly = false);

void addProduct(string products[],double pro_cprices[],int pro_profit_percent[],int pro_IDs[],int pro_stock[],bool pro_flag[],int MAX_PRODUCTS,int &productCount);

void addmoderator(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], string moder_CNIC[],
                string moder_email[], char moder_phone[][10], int moder_salary[], int moder_IDs[], bool moder_flag[], int& moderID, int MAX_MODERATORS);

void addCustomer(string cust_name[],char cust_CNIC[][16],int cust_IDs[],bool cust_flag[],int custID,int MAX_CUSTOMERS);

void disableProduct(int pro_IDs[],bool pro_active[],bool pro_flag[],int ID,int size);

void deletemoderator(bool moder_flag[], int moder_IDs[], int moderID, int MAX_MODERATORS);

void updatePrice(string products[],int pro_IDs[],double pro_cprices[],int pro_profit_percent[],bool pro_flag[],int ID,int size);

void editStock(string products,int pro_IDs[],int pro_stock[],bool pro_flag[],int productCount,int MAX_PRODUCTS);

void updatemoderator(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], 
                   string moder_CNIC[], string moder_email[], char moder_phone[][10], int moder_salary[], 
                   int moder_IDs[], bool moder_flag[], int moderID, int MAX_MODERATORS);

void buyItems(string products[],int custID,int pro_IDs[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int purchases[],double purchaseBill[],int item_purchases[][4],
bool pro_flag[],int MAX_PRODUCTS,int MAX_PURCHASES,int& purchaseID,int& item_purCount,int productCount);

int* returnBuyedProducts(int custID,int purchases[],int item_purchases[][4],int purchaseID,int item_purCount,int MAX_PRODUCTS,int& distinctCounter);

int* returnReviewedProducts(int custID,int reviewProID[],int reviewCustID[],int reviewType[],bool review_flag[],int MAX_PRODUCTS,int MAX_REVIEWS,int& distinctCounter);

void generalReview(int custID, string reviews[],int reviewProID[], int reviewCustID[], int reviewRating[],bool review_flag[],int reviewType[], int MAX_REVIEWS);

void proReview(int custID,int purchases[],int item_purchases[][4],int purchaseID,int item_purCount,int productCount,int MAX_PRODUCTS,
               string reviews[],int reviewProID[], int reviewCustID[], int reviewRating[],bool review_flag[],int reviewType[], int MAX_REVIEWS);

int navigateMenu(string menuItems[], int menuSize);

int getCredentials(string usernames[], string passwords[],int size,string user);

int loginCustomer(char cust_CNIC[][16],int cust_IDs[],string cust_name[],bool cust_flag[], int MAX_CUSTOMERS);

int intValidation(string text = "\b", string prefix = "",int l_limit = 0,int u_limit = 9);

double doubleValidation(string input = "",double limit = 10,int percesion = 2);

void printBorder();

void displayMenu(string menuItems[], int menuSize, int selected);

void print_logo();

void showPrices(string products[],double pro_cprices[],int pro_profit_percent[],int pro_stock[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,bool& flag);

void showmoderators(string moder_first_name[],string moder_username[],string moder_password[],int moder_IDs[],bool moder_flag[],int MAX_MODERATORS,bool& found);

void showmoderatorProfile(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], 
                        string moder_CNIC[], string moder_email[], char moder_phone[][10], int moder_salary[], 
                        int moder_IDs[], bool moder_flag[], int moderID, int MAX_MODERATORS);

void showHistory(int purchases[],double purchaseBill[],int item_purchases[][4],int custID,string products[],bool pro_flag[],int pro_IDs[],int MAX_PRODUCTS,int MAX_PURCHASES,int& item_purCount);

void viewMyReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS);

int returnIndexByID(int IDs[],bool flag[],int ID,int size);

string centerString(string str,int width);

void hold();

bool yesnt();

void printHeader(string str);

string inputEmail();

void copy(char* c1, char c2[]);

char* inputCNIC();

void printBorder();

void displayMenu(string menuItems[], int menuSize, int selected);

void print_logo();

char intToChar(int n);

string intToString(int n);

string pad(int,int);

string makeIDString(string string,int ID);

string doubleToString(double n,int percesion);

string prefixToDouble(double n, string prefix,int percesion);

string postfixInt(int n,string str);

void showProductsAdmin(string products[],double pro_cprices[],int pro_profit_percent[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS);

void showPrices(string products[],double pro_cprices[],int pro_profit_percent[],int pro_stock[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,bool& flag);

void showDisabledProducts(string products[],double pro_cprices[],int pro_profit_percent[],int pro_stock[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,bool& flag);

void outOfStock(string products[],bool pro_flag[],int pro_IDs[],int pro_stock[],int MAX_PRODUCTS,bool& flag);

void showStock(string products[],bool pro_flag[],int pro_IDs[],int pro_stock[],int MAX_PRODUCTS,bool& flag);

void showmoderatorProfile(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], 
                        string moder_CNIC[], string moder_email[], char moder_phone[][10], int moder_salary[], 
                        int moder_IDs[], bool moder_flag[], int moderID, int MAX_MODERATORS);

string giveReviewStatus(int status);

void viewGeneralReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[],int reviewStatus[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS);

void viewProductReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[],int reviewStatus[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS);

void viewMyReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[],int reviewStatus[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS);

void printBuyedItems(string products[],bool pro_flag[],int custID,int pro_IDs[],int purchases[],int item_purchases[][4],int purchaseID,int item_purCount, int MAX_PRODUCTS,int& distinctCounter);

int navigateMenu(string menuItems[], int menuSize);

int getCredentials(string usernames[], string passwords[],int size,string user);

bool isNum(char a);

char* inputCNIC();

bool isSame(char* c1,char c2[]);

int loginCustomer(char cust_CNIC[][16],int cust_IDs[],string cust_name[],bool cust_flag[], int MAX_CUSTOMERS);

bool isNum(char a);

int charToInt(char a);

int strToInt(string str);

string popOut(string str);

int intValidation(string text,string prefix,int l_limit,int u_limit);

char lastChar(string str);

double strToDouble(string str);

double doubleValidation(string text,double limit,int percesion);

void addProduct(string products[],double pro_cprices[],int pro_profit_percent[],int pro_IDs[],int pro_stock[],bool pro_active[],bool pro_flag[],int MAX_PRODUCTS,int &productCount);

char* inputPhoneNo();

void addmoderator(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], string moder_CNIC[],
                string moder_email[], char moder_phone[][10], int moder_salary[], int moder_IDs[], bool moder_flag[], int& moderID, int MAX_MODERATORS);

void addCustomer(string cust_name[],char cust_CNIC[][16],int cust_IDs[],bool cust_flag[],int custID,int MAX_CUSTOMERS);

void enableProduct(int pro_IDs[],bool pro_active[],bool pro_flag[],int ID,int size);

void disableProduct(int pro_IDs[],bool pro_active[],bool pro_flag[],int ID,int size);

void deletemoderator(bool moder_flag[], int moder_IDs[], int moderID, int MAX_MODERATORS);

void updatePrice(string products[],int pro_IDs[],double pro_cprices[],int pro_profit_percent[],bool pro_flag[],int ID,int size);

void editStock(string products[],int pro_IDs[],int pro_stock[],bool pro_flag[],int productCount,int MAX_PRODUCTS);

void updatemoderator(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], 
                   string moder_CNIC[], string moder_email[], char moder_phone[][10], int moder_salary[], 
                   int moder_IDs[], bool moder_flag[], int moderID, int MAX_MODERATORS);

int returnIndexByID(int IDs[],bool flag[],int ID,int size);

void generalReview(int custID, string reviews[],int reviewProID[], int reviewCustID[], int reviewRating[],int reviewModer[],int reviewStatus[],bool review_flag[],int reviewType[], int MAX_REVIEWS);

void proReview(int custID,int purchases[],int item_purchases[][4],int purchaseID,int item_purCount,int productCount,int MAX_PRODUCTS,
               string reviews[],int reviewProID[], int reviewCustID[], int reviewRating[],int reviewModer[],int reviewStatus[],bool review_flag[],int reviewType[], int MAX_REVIEWS);

void copyIntArray(int arr1[],const int arr2[],int size);

void buyItems(string products[],int custID,int pro_IDs[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int purchases[],double purchaseBill[],int item_purchases[][4],
bool pro_flag[],int MAX_PRODUCTS,int MAX_PURCHASES,int& purchaseID,int& item_purCount,int productCount);

int* returnReviewedProducts(int custID,int reviewProID[],int reviewCustID[],int reviewType[],bool review_flag[],int MAX_PRODUCTS,int MAX_REVIEWS,int& distinctCounter);

int* returnBuyedProducts(int custID,int purchases[],int item_purchases[][4],int purchaseID,int item_purCount,int MAX_PRODUCTS,int& distinctCounter);

void loadData(bool pro_flag[],int pro_IDs[],string products[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int& productCount,int MAX_PRODUCTS,
              bool moder_flag[],string moder_first_name[],string moder_last_name[],string moder_username[],string moder_password[],string moder_CNIC[],string moder_email[],char moder_phone[][10],int moder_salary[],int moder_IDs[],int& moderID,int MAX_MODERATORS,
              bool cust_flag[],string cust_name[],char cust_CNIC[][16],int cust_IDs[],int& custID,int MAX_CUSTOMERS,
              int purchases[],double purchaseBill[],int& purchaseID,
              int item_purchases[][4],int& item_purCount,
              bool review_flag[],int reviewType[],int reviewProID[],int reviewCustID[],string reviews[],int reviewStatus[],int reviewModer[],int reviewRating[],int MAX_REVIEWS,
              string reportSubject[],string reports[],bool report_flag[],int report_status[],int report_moderator[],int MAX_REPORTS);

void storeData(bool pro_flag[],int pro_IDs[],string products[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int& productCount,int MAX_PRODUCTS,
               bool moder_flag[],string moder_first_name[],string moder_last_name[],string moder_username[],string moder_password[],string moder_CNIC[],string moder_email[],char moder_phone[][10],int moder_salary[],int moder_IDs[],int& moderID,int MAX_MODERATORS,
               bool cust_flag[],string cust_name[],char cust_CNIC[][16],int cust_IDs[],int& custID,int MAX_CUSTOMERS,
               int purchases[],double purchaseBill[],int& purchaseID,
               int item_purchases[][4],int& item_purCount,
               bool review_flag[],int reviewType[],int reviewProID[],int reviewCustID[],string reviews[],int reviewStatus[],int reviewModer[],int reviewRating[],int MAX_REVIEWS,
               string reportSubject[],string reports[],bool report_flag[],int report_status[],int report_moderator[],int MAX_REPORTS);

int returnIndexOfReview(int number,bool review_flag[],int reviewStatus[],int MAX_REVIEWS);

void moderateReviews(int moderID,bool review_flag[],int reviewCustID[],int reviewModer[],int reviewProID[],int reviewRating[],string reviews[],int reviewStatus[],int reviewType[],
string cust_name[],bool cust_flag[],int cust_IDs[],int MAX_CUSTOMERS,
string products[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,int MAX_REVIEWS,int type,bool edit = false);

void printHeader(string str);

bool printAble(char c);

void reportToAdmin(int moderator,string reportSubject[],string reports[],bool report_flag[],int report_status[],int report_moderator[],int MAX_REPORTS);

string centerString(string str,int width);

void viewRequest(string moder_first_name[],int moder_IDs[],bool moder_flag[],string reportSubject[],string reports[],int report_moderator[],bool report_flag[],int report_status[],int MAX_MODERATORS,int MAX_REPORTS,int status,int n);

void viewRequests(string moder_first_name[],int moder_IDs[],bool moder_flag[],string reportSubject[],string reports[],int report_moderator[],bool report_flag[],int report_status[],int MAX_MODERATORS,int MAX_REPORTS,int status);

void deleteDisclaimer(string entity);

void initializeByIndex(int arr[],int size);

void sortProducts(int indexes[],unsigned long int numbers[],int size,char order);

void copyULIntArray(unsigned long int arr1[],const unsigned long int arr2[],int size);

void printSortedItems(string products[],int pro_IDs[],unsigned long int pro_sell[],int productCount,char order);

bool isAlpha(char a);

string inputEmail();


// void showProductDetails(string products[],double pro_cprices[],int pro_profit_percent[],int proIndex,bool admin);
// void showProductDetails(string products[],double pro_cprices[],int pro_profit_percent[],int proIndex,bool admin) {

//     cout << "Name : " << products[proIndex] << endl;
//     cout << "Cost Price : " << pro_cprices[proIndex] << endl;
//     cout << "Profit Percent : " << pro_profit_percent[proIndex] << endl;
//     cout << "Sale Price : " << pro_cprices[proIndex] * (1 + pro_profit_percent[proIndex]/100);

// }

int main() {


    // Enable Unicode Support for Console

    system("chcp 65001");
    
    //////////////////// Array Declarations //////////////////////


    // Admin Credentials

    string admin_usernames[] = {"baby"};
    string admin_passwords[] = {"boss"};


    // Login Menus

    string mainMenu[] = {"Admin", "Moderator", "Customer", "Exit"};

    // Main Menu

    string adminMenu[] = {"Products","Stock", "Statics",  "Moderators", "Requests", "Exit"};

    string moderatorMenu[] = {"View Prices", "View Stock", "View Reviews", "Inform Admin","View Profile","Exit"};

    string customerMenu[] = {"View Items", "Buy Items","View History", "Give Review", "View My Reviews", "Exit"};
    
    // Admin Submenu

    string aProductsMenu[] = {"Add Product","Update Product","View Products","View Stock","Delete Product","Enable Products","Go Back"};
    string aStockMenu[] = {"View Stock","Update Stock","Out of Stock","Go Back"};
    string aStaticsMenu[] = {"Most Selling Products","Least Selling Products","Go Back"};
    string aModeratorMenu[] = {"View Moderators","Add Moderator","Edit Moderators","Remove Moderator","Go Back"};
    string aRequestionsMenu[] = {"New Requests","Approved Requests","Disapproved Requests","Go Back"};

    // Sub Menus

    string mReviewMenu[] = {"Pending","Approved","Disapproved","Exit"};

    string cReview_menu[] = {"Item Related","General Review","Exit"};
    string cViewReview[] = {"All Reviews","Product Related","General Reviews","Go Back"};

    // Menu Count

    int mainMenuSize = sizeof(mainMenu) / sizeof(mainMenu[0]);

    int adminMenuSize = sizeof(adminMenu) / sizeof(adminMenu[0]);
    int moderatorMenuSize = sizeof(moderatorMenu) / sizeof(moderatorMenu[0]);
    int customerMenuSize = sizeof(customerMenu) / sizeof(customerMenu[0]);

    int aProductsMenuSize = sizeof(aProductsMenu) / sizeof(aProductsMenu[0]);
    int aStockMenuSize = sizeof(aStockMenu) / sizeof(aStockMenu[0]);
    int aStaticsMenuSize = sizeof(aStaticsMenu) / sizeof(aStaticsMenu[0]);
    int aRequestionsMenuSize = sizeof(aRequestionsMenu) / sizeof(aRequestionsMenu[0]);
    int aModeratorMenuSize = sizeof(aModeratorMenu) / sizeof(aModeratorMenu[0]);

    int cViewReviewSize = sizeof(cViewReview) / sizeof(cViewReview[0]);

    int mReviewMenuSize = sizeof(mReviewMenu) / sizeof(mReviewMenu[0]);
    int cReview_menuSize = sizeof(cReview_menu) / sizeof(cReview_menu[0]);


    // Reports/requests

    const int MAX_REPORTS = 50;
    string reports[MAX_REPORTS] = {""};
    bool report_flag[MAX_REPORTS] = {false};
    int report_moderator[MAX_REPORTS] = {-1};
    int report_status[MAX_REPORTS] = {-1};
    string reportSubject[MAX_REPORTS] = {""};
        
    // Products

    const int MAX_PRODUCTS = 100;
    bool pro_flag[MAX_PRODUCTS] = {false};
    int pro_IDs[MAX_PRODUCTS] = {0};
    string products[MAX_PRODUCTS] = {""};
    double pro_cprices[MAX_PRODUCTS] = {0.0};
    int pro_profit_percent[MAX_PRODUCTS] = {0};
    unsigned long int pro_sell[MAX_PRODUCTS] = {0};
    int pro_stock[MAX_PRODUCTS] = {0};
    int productCount = 0;
    bool pro_active[MAX_PRODUCTS] = {false};

    // Moderators

    const int MAX_MODERATORS = 5;
    bool moder_flag[MAX_MODERATORS] = {false};
    string moder_first_name[MAX_MODERATORS] = {""};
    string moder_last_name[MAX_MODERATORS] = {""};
    string moder_username[MAX_MODERATORS] = {""};
    string moder_password[MAX_MODERATORS] = {""};
    string moder_CNIC[MAX_MODERATORS] = {""};
    string moder_email[MAX_MODERATORS] = {""};
    char moder_phone[MAX_MODERATORS][10] = {0};
    int moder_salary[MAX_MODERATORS] = {0};
    int moder_IDs[MAX_MODERATORS] = {0};
    int moderID = 0;

    // Customer 

    const int MAX_CUSTOMERS = 100;
    string cust_name[MAX_CUSTOMERS] = {""};
    char cust_CNIC[MAX_CUSTOMERS][16] = {};
    int cust_IDs[MAX_CUSTOMERS] = {0};
    bool cust_flag[MAX_CUSTOMERS] = {false};
    int custID = 0;

    // Purchases

    const int MAX_PURCHASES = 100;
    int purchases[MAX_PURCHASES] = {-5};
    double purchaseBill[MAX_PURCHASES] = {-1}; // Index as purchaseID and Value CustomerID  
    int purchaseID = 0;

    // Items of Each Purchase

    int item_purchases[MAX_PURCHASES * 10][4] = {-1,-2,-3,-4}; // purchaseID, item_id,quantity,price
    int item_purCount = 0;

    /// Reviews
    
    const int MAX_REVIEWS = MAX_PRODUCTS * 10; 

    string reviews[MAX_REVIEWS] = {""};
    int reviewProID[MAX_REVIEWS] = {0};
    int reviewCustID[MAX_REVIEWS] = {0};
    int reviewRating[MAX_REVIEWS] = {0};
    bool review_flag[MAX_REVIEWS] = {false};
    int reviewType[MAX_REVIEWS] = {-1};
    int reviewStatus[MAX_REVIEWS] = {-1};
    int reviewModer[MAX_REVIEWS] = {-1};


    ////////////// Array Initializationa ///////////

    
    for(int i = 0; i < MAX_MODERATORS;i++) {

        moder_flag[i] = false;
        moder_first_name[i] = "";
        moder_last_name[i] = "";
        moder_username[i] = "";
        moder_password[i] = "";
        moder_CNIC[i] = "";
        moder_email[i] = "";
        moder_phone[i][0] = '\0';
        moder_salary[i] = -1;
        moder_IDs[i] = -1;

    }

    for(int i = 0;i < MAX_REVIEWS;i++) {
        
        reviews[i] = "";
        reviewProID[i] = 0;
        reviewCustID[i] = 0;
        reviewRating[i] = 0;
        review_flag[i] = false;
        reviewType[i] = -1;
        reviewStatus[i] = -1;
        reviewModer[i] = -1;

    }

    for(int i = 0;i < MAX_PURCHASES * 10;i++) {

        for(int j = 0;j < 4;j++)
            item_purchases[i][j]  = -1;

    }

    for(int i = 0;i < MAX_PURCHASES;i++) {

        purchases[i] = -1;
        purchaseBill[i] = -1;  

    }

    for(int i = 0;i < MAX_CUSTOMERS;i++) {

        cust_name[i] = "";
        cust_CNIC[i][0] = '\0';
        cust_IDs[i] = 0;
        cust_flag[i] = false;

    }

    for(int i = 0;i < MAX_PRODUCTS;i++) {

        pro_flag[i] = false;
        pro_IDs[i] = 0;
        products[i] = "";
        pro_cprices[i] = 0.0;
        pro_profit_percent[i] = 0;
        pro_sell[i] = 0;
        pro_stock[i] = 0;
        productCount = 0;
        pro_active[i] = false;

    }

    for(int i = 0;i < MAX_REPORTS;i++) {

        reports[i] = "";
        report_flag[i] = false;
        report_moderator[i] = -1;
        report_status[i] = -1;
        reportSubject[i] = "";

    }

    ////////////////////// Load Data ////////////////////////


    loadData(pro_flag,pro_IDs,products,pro_cprices,pro_profit_percent,pro_sell,pro_stock,pro_active,productCount,MAX_PRODUCTS,
            moder_flag,moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moderID,MAX_MODERATORS,
            cust_flag,cust_name,cust_CNIC,cust_IDs,custID,MAX_CUSTOMERS,
            purchases,purchaseBill,purchaseID,
            item_purchases,item_purCount,
            review_flag,reviewType,reviewProID,reviewCustID,reviews,reviewStatus,reviewModer,reviewRating,MAX_REVIEWS,
            reportSubject,reports,report_flag,report_status,report_moderator,MAX_REPORTS);


    // Variable Declarations

    int admin = -1,moderator = -1,customer = -1;

    int loggedInUser = -1;

    int loginChoice = -1;

    int nes1 = -1,nes2 = -1;

    int tem = -1;

    char ch = '\0';

    bool end = false;

    bool flag = false;
    
    do { // login Menu (loginChoice)

        loginChoice = navigateMenu(mainMenu, mainMenuSize);

        switch(loginChoice) {

        case 0:

            admin = getCredentials(admin_usernames, admin_passwords,1,"Admin");

            if(admin != -1)
                loggedInUser = 0;

            break;

        case 1:

            moderator = getCredentials(moder_username, moder_password,MAX_MODERATORS,"Moderator");

            if(moderator != -1) {

                moderator = moder_IDs[moderator];

                loggedInUser = 1;

            }

            break;

        case 2:

            printBorder();
            gotoxy(35,18);

            cout << "Are you New Customer : ";   

            if(yesnt())
                addCustomer(cust_name,cust_CNIC,cust_IDs,cust_flag,custID,MAX_CUSTOMERS);

            customer = loginCustomer(cust_CNIC,cust_IDs,cust_name,cust_flag,MAX_CUSTOMERS);

            if(customer != -1)
                loggedInUser = 2;

            break;
        case 3:

            gotoxy(45,36);

            setcolor(3);
            cout << "Thanks For Using System." << endl;
            setcolor(7);

            loggedInUser = -1;

        break;
        default:
            loggedInUser = -1;
        break;
    }

        do { // Main Menu

            end = false;

            if(loggedInUser == 0) { // Admin

                int admin_choice = navigateMenu(adminMenu, adminMenuSize);

                switch(admin_choice) {

                    case 0: // Admin Products Menu

                        while(true) {

                            nes1 = navigateMenu(aProductsMenu,aProductsMenuSize);

                            switch(nes1) {
                                case 0:
                                    
                                    addProduct(products,pro_cprices,pro_profit_percent,pro_IDs,pro_stock,pro_active,pro_flag,MAX_PRODUCTS,productCount);
                                    cout << "\n\t\t\t\t   ";
                                    hold();

                                break;
                                case 1:

                                    while(true) {

                                    showProductsAdmin(products,pro_cprices,pro_profit_percent,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS);
                                    cout << endl << endl << endl << "\t\t";
                                    cout << "Do you want to update Price: ";
                                    if(yesnt()) {

                                        cout << "\n\n\t\t";

                                        nes2 = intValidation("Product ID to Update","PR",1,productCount);
                                        updatePrice(products,pro_IDs,pro_cprices,pro_profit_percent,pro_flag,nes2,MAX_PRODUCTS);

                                    } else break;

                                    }

                                break;
                                case 2:

                                    showProductsAdmin(products,pro_cprices,pro_profit_percent,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS);
                                    cout << "\n\n\t\t";
                                    hold();

                                break;
                                case 3:
                                    flag = false,
                                    showStock(products,pro_flag,pro_IDs,pro_stock,MAX_PRODUCTS,flag);
                                    cout << "\n\n\t\t";
                                    hold();

                                break;
                                case 4:

                                    while(true) {

                                        flag = false;

                                        showPrices(products,pro_cprices,pro_profit_percent,pro_stock,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS,flag);
                                        if(!flag) {
                                            setcolor(14);
                                            cout << "\n\n\t\t\t\tNo Product Found\n\n\t\t";
                                            setcolor(7);
                                            hold();
                                            break;
                                        }
                                        deleteDisclaimer("Products");
                                        
                                        cout << "\n\n\t\tDo you want to Disable Product : ";
                                        if(yesnt()) {

                                            cout << endl << endl << endl << "\t\t";
                                            nes1 = intValidation("Product ID to disable","PR",1,productCount);

                                            disableProduct(pro_IDs,pro_active,pro_flag,nes1,MAX_PRODUCTS);
                                            cout << "\n\t\t";                     
                                            hold();
                                        
                                        } else break;
                                    }

                                break;
                                case 5:

                                    while(true) {

                                        flag = false;

                                        showDisabledProducts(products,pro_cprices,pro_profit_percent,pro_stock,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS,flag);
                                        if(!flag) {
                                            setcolor(14);
                                            cout << "\n\n\t\t\t\tNo Disabled Product Found\n\n\t\t";
                                            setcolor(7);
                                            hold();
                                            break;
                                        }
                                        cout << "\n\n\t\tDo you want to Enable Any Product : ";
                                        if(yesnt()) {

                                            cout << endl << endl << endl << "\t\t";
                                            nes1 = intValidation("Product ID to Enable","PR",1,productCount);

                                            enableProduct(pro_IDs,pro_active,pro_flag,nes1,MAX_PRODUCTS);
                                            cout << "\n\t\t";                     
                                            hold();
                                        
                                        } else break;
                                    }

                                break;
                            }
                            if(nes1 == 6)
                                break;
                        }

                    break;
                    case 1: // Admin Stock Menu
                        
                        while(true) {

                            nes1 = navigateMenu(aStockMenu,aStockMenuSize);

                            switch(nes1) {
                                
                                case 0:

                                    flag = true;

                                    showStock(products,pro_flag,pro_IDs,pro_stock,MAX_PRODUCTS,flag);
                                    cout << "\n\n\t\t";
                                    hold();

                                break;
                                case 1:

                                    flag = false;

                                    while(true) {

                                        showStock(products,pro_flag,pro_IDs,pro_stock,MAX_PRODUCTS,flag);
                                        cout << "\n\n\t\tDo you want to edit stock : ";
                                        if(yesnt()) {

                                            editStock(products,pro_IDs,pro_stock,pro_flag,productCount,MAX_PRODUCTS);

                                        } else break;
                                    }

                                break;
                                case 2:

                                    flag = false;

                                    outOfStock(products,pro_flag,pro_IDs,pro_stock,MAX_PRODUCTS,flag);
                                    if(!flag) {
                                        setcolor(14);
                                        cout << "\n\n\t\t\tNothing is Out Of Stock Dont Worry";
                                        setcolor(7);
                                    }
                                    cout << "\n\n\t\t";
                                    hold();

                                break;

                            }

                            if(nes1 == 3)
                            break;
                        }

                    break;
                    case 2: // Admin Statics Menu

                        while(true) {

                            nes1 = navigateMenu(aStaticsMenu,aStaticsMenuSize);

                            switch(nes1) {
                                case 0:

                                    printSortedItems(products,pro_IDs,pro_sell,productCount,'d');


                                break;
                                case 1:

                                    printSortedItems(products,pro_IDs,pro_sell,productCount,'a');
    
                                break;
                            }

                            if(nes1 == 2)
                                break;
                        }

                    break;
                    case 3: // Admin Moderators Menu

                        while(true) {

                            nes1 = navigateMenu(aModeratorMenu,aModeratorMenuSize);

                            switch(nes1) {

                                case 0:

                                    while(true) {
                                        flag = false;
                                        showmoderators(moder_first_name,moder_username,moder_password,moder_IDs,moder_flag,MAX_MODERATORS,flag);
                                         if(flag) {

                                            cout << "\n\n\t\tDo You Want to See Full Profile of Moderator: ";
                                            if(yesnt()) {
                                                cout << "\n\n\t\t";
                                                nes1 = intValidation("Moderator ID","",1,moderID);
                                                showmoderatorProfile(moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moder_flag,nes1,MAX_MODERATORS);

                                                cout << "\n\n\t\t";
                                                hold();

                                            } else break;
                                        
                                        } else {
                                            cout << "\n\n\t\tNo Moderator Found";
                                            cout << "\n\n\t\t";
                                            hold();
                                            break;
                                        }
                                    }

                                break;
                                case 1:

                                    addmoderator(moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moder_flag,moderID,MAX_MODERATORS);

                                break;
                                case 2:
                                    flag = false;
                                    showmoderators(moder_first_name,moder_username,moder_password,moder_IDs,moder_flag,MAX_MODERATORS,flag);
                                     if(flag) {

                                        cout << "\n\n\t\tDo You Want to edit Moderator: ";
                                        if(yesnt()) {
                                            cout << "\n\n\t\t";
                                            tem = intValidation("Moderator ID","",1,MAX_MODERATORS);
                                            updatemoderator(moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moder_flag,tem,MAX_MODERATORS);
                                       
                                        }
                                    } else {
                                        cout << "\n\n\t\tNo Moderator Found";
                                    }
                                    cout << "\n\n\t\t";
                                    hold();
                                break;
                                case 3:
                                    flag = false;
                                    showmoderators(moder_first_name,moder_username,moder_password,moder_IDs,moder_flag,MAX_MODERATORS,flag);
                                    if(flag) {

                                        cout << "\n\n\t\tDo You Want to Delete Moderator: ";
                                        if(yesnt()) {
                                            
                                            cout << "\n\n\t\t";
                                            tem = intValidation("Moderator ID","",1,MAX_MODERATORS);
                                            deletemoderator(moder_flag,moder_IDs,tem,MAX_MODERATORS);

                                        }
                                    }
                                     else {
                                        cout << "\n\n\t\tNo Moderator Found";
                                    }
                                    cout << "\n\n\t\t";
                                    hold();

                                break;
                            }

                            if(nes1 == 4)
                                break;

                        }
                        
                    break;
                    case 4: // Admin Requests Menu

                        while(true) {

                            nes1 = navigateMenu(aRequestionsMenu,aRequestionsMenuSize);

                            switch(nes1) {
                                case 0:

                                    viewRequests(moder_first_name,moder_IDs,moder_flag,reportSubject,reports,report_moderator,report_flag,report_status,MAX_MODERATORS,MAX_REPORTS,-1);

                                break;
                                case 1:

                                    viewRequests(moder_first_name,moder_IDs,moder_flag,reportSubject,reports,report_moderator,report_flag,report_status,MAX_MODERATORS,MAX_REPORTS,1);

                                break;
                                case 2:

                                    viewRequests(moder_first_name,moder_IDs,moder_flag,reportSubject,reports,report_moderator,report_flag,report_status,MAX_MODERATORS,MAX_REPORTS,2);
                                
                                break;
                            }

                            if(nes1 == 3)
                                break;

                        }
                        break;
                }

                if(admin_choice == 5) {
                    loggedInUser = -1;
                    end = true;
                }
                    
            } else if(loggedInUser == 1) { // Moderator

                int moderator_choice = navigateMenu(moderatorMenu, moderatorMenuSize);

                switch(moderator_choice) {

                    case 0:
                        flag = false;
                        showPrices(products,pro_cprices,pro_profit_percent,pro_stock,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS,flag);
                        cout << "\n\n\t\t";
                        hold();
                        break;
                    case 1:
                        flag = false;
                        showStock(products,pro_flag,pro_IDs,pro_stock,MAX_PRODUCTS,flag);
                        cout << "\n\n\t\t";
                        hold();
                        break;
                    case 2:

                        while(true) {

                            nes1 = navigateMenu(mReviewMenu,mReviewMenuSize);

                            switch(nes1) {
                                case 0:

                                    moderateReviews(moderator,review_flag,reviewCustID,reviewModer,reviewProID,reviewRating,reviews,reviewStatus,reviewType,
                                                    cust_name,cust_flag,cust_IDs,MAX_CUSTOMERS,
                                                    products,pro_IDs,pro_flag,MAX_PRODUCTS,MAX_REVIEWS,-1,true);

                                break;
                                case 1:
                            
                                    moderateReviews(moderator,review_flag,reviewCustID,reviewModer,reviewProID,reviewRating,reviews,reviewStatus,reviewType,
                                                    cust_name,cust_flag,cust_IDs,MAX_CUSTOMERS,
                                            products,pro_IDs,pro_flag,MAX_PRODUCTS,MAX_REVIEWS,1);

                                break;
                                case 2:
                                    
                                    moderateReviews(moderator,review_flag,reviewCustID,reviewModer,reviewProID,reviewRating,reviews,reviewStatus,reviewType,
                                                    cust_name,cust_flag,cust_IDs,MAX_CUSTOMERS,
                                                    products,pro_IDs,pro_flag,MAX_PRODUCTS,MAX_REVIEWS,2);

                                break;
                            }

                            if(nes1 == 3)
                                break;

                        }

                        break;

                    case 3:

                        reportToAdmin(moderator,reportSubject,reports,report_flag,report_status,report_moderator,MAX_REPORTS);

                    break;

                    case 4:

                        showmoderatorProfile(moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moder_flag,moderator,MAX_MODERATORS);

                        cout << "\n\n\t\t";
                        hold();

                    break;

                }

                if(moderator_choice == 5) {

                    loggedInUser = -1;
                    end = true;
                }

            } else if(loggedInUser == 2) { // Customer
                
                int customer_choice = navigateMenu(customerMenu, customerMenuSize);

                switch(customer_choice) {
                    case 0:
                        flag = false;
                        showPrices(products,pro_cprices,pro_profit_percent,pro_stock,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS,flag);
                        cout << "\n\t\t";
                        hold();
                    break;
                    case 1:
                        flag = false;
                        showPrices(products,pro_cprices,pro_profit_percent,pro_stock,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS,flag);
                        if(flag) {

                        cout << "\n\t\tDo you want to Buy Items: ";
                        if(yesnt())
                            buyItems(products,customer,pro_IDs,pro_cprices,pro_profit_percent,pro_sell,pro_stock,pro_active,purchases,purchaseBill,item_purchases,pro_flag,MAX_PRODUCTS,MAX_PURCHASES,purchaseID,item_purCount,productCount);

                        } else {
                            setcolor(14);
                            cout << "\n\n\n\t\tCurrently No Product is Available for Purchase";
                            setcolor(7);
                            cout << "\n\n\t\t";
                            hold();
                        }

                        break;
                    case 2:
                        showHistory(purchases,purchaseBill,item_purchases,customer,products,pro_flag,pro_IDs,MAX_PRODUCTS,MAX_PURCHASES,item_purCount);
                        hold();
                        break;
                    case 3:

                        nes1 = navigateMenu(cReview_menu,cReview_menuSize);

                        if(nes1 == 0){

                            nes2 = 0,

                            printBuyedItems(products,pro_flag,customer,pro_IDs,purchases,item_purchases,purchaseID,item_purCount,MAX_PRODUCTS,nes2);

                            if(nes2 != 0) {

                                proReview(customer,purchases,item_purchases,purchaseID,item_purCount,productCount,MAX_PRODUCTS,reviews,reviewProID,reviewCustID,reviewRating,reviewModer,reviewStatus,review_flag,reviewType,MAX_REVIEWS);
                            
                            } else  {
                                setcolor(14);
                                cout << "\n\n\t\tYou have not buyed any product yet\n\n\t\t";
                                setcolor(7);
                                hold();
                            }

                        }
                        else if(nes1 == 1){
                            generalReview(customer,reviews,reviewProID,reviewCustID,reviewRating,reviewModer,reviewStatus,review_flag,reviewType,MAX_REVIEWS);
                        }
                        break;
                    case 4:

                        while(true) {
                            nes1 = navigateMenu(cViewReview,cViewReviewSize);

                            switch(nes1) {
                                case 0:

                                
                                viewMyReviews(customer,reviews,reviewRating,reviewType,reviewProID,reviewCustID,products,pro_IDs,reviewStatus,pro_flag,review_flag,MAX_PRODUCTS,MAX_REVIEWS);
                                cout << "\n\t\t";
                                hold();

                                break;
                                case 1:

                                system("cls");
                                print_logo();
                                viewProductReviews(customer,reviews,reviewRating,reviewType,reviewProID,reviewCustID,products,pro_IDs,reviewStatus,pro_flag,review_flag,MAX_PRODUCTS,MAX_REVIEWS);
                                hold();

                                break;
                                case 2:

                                system("cls");
                                print_logo();
                                viewGeneralReviews(customer,reviews,reviewRating,reviewType,reviewProID,reviewCustID,products,pro_IDs,reviewStatus,pro_flag,review_flag,MAX_PRODUCTS,MAX_REVIEWS);
                                hold();


                                break;
                            }

                            if(nes1 == 3)
                                break;
                        }

                    break;
                }


                if(customer_choice == customerMenuSize -1) {

                    loggedInUser = -1;
                    end = true;
                }

            } else {
                end = true;
            }
        
        } while(!end);

    } while (loginChoice != 3);


    //////////////////// Store Data ////////////////////

    storeData(pro_flag,pro_IDs,products,pro_cprices,pro_profit_percent,pro_sell,pro_stock,pro_active,productCount,MAX_PRODUCTS,
             moder_flag,moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moderID,MAX_MODERATORS,
             cust_flag,cust_name,cust_CNIC,cust_IDs,custID,MAX_CUSTOMERS,
             purchases,purchaseBill,purchaseID,
             item_purchases,item_purCount,
             review_flag,reviewType,reviewProID,reviewCustID,reviews,reviewStatus,reviewModer,reviewRating,MAX_REVIEWS,
             reportSubject,reports,report_flag,report_status,report_moderator,MAX_REPORTS);

    return 0;
}


// Printing Functions

void printBorder() {

    system("cls");
    print_logo();

    int x = 30, y = 12; // Starting Points

    int columns = 50; // Width
    int rows = 20; // Height

    // □ ■ █

    for(int i = 0; i < rows; i++){
        gotoxy(x,y);
        cout << "██";
        for(int j = 0; j < columns; j++) {

            if(i == 0 || i == rows - 1)
                cout << "█";
            else cout << " ";

        }
        cout << "██";
        cout << endl;
        y++;
    }
}

void printSortedItems(string products[],int pro_IDs[],unsigned long int pro_sell[],int productCount,char order) {

    system("cls");
    print_logo();
    printHeader((order == 'a' ? "Least 10 Selling Products" : "Top 10 Most Selling Products")); // Print Header According to Order

    int* indexes = new int[productCount]; // Create Array to Store Indexes

    initializeByIndex(indexes,productCount); // Initialize Indexes Array

    unsigned long int* tem_sell = new unsigned long int[productCount]; // Array to Copy Stock Array

    copyULIntArray(tem_sell,pro_sell,productCount); // Copy Stock Array so Orignal Data Dont get Modified

    sortProducts(indexes,tem_sell,productCount,order); // Sort using Copied Array

    
    cout << "\n\n\t\t\t\t┏━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━┓\n";
    cout << "\t\t\t\t┃" << centerString("ID",10) << "┃" << centerString("Name",20) << "┃" << centerString("Sell",10) << "┃\n";
    cout << "\t\t\t\t┣━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━┫\n";


    for(int i = 0;i < 10;i++) {
        if(i < productCount) {

            cout << "\t\t\t\t┃" << centerString(makeIDString("PR",pro_IDs[indexes[i]]),10);
            cout << "┃" << centerString(products[indexes[i]],20);
            cout << "┃" << centerString(intToString(pro_sell[indexes[i]]),10) << "┃" << endl;

        }
    }
    cout << "\t\t\t\t┗━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━┛\n";

    cout << "\n\n\n\t\t\t";
    setcolor(14);
    cout << "Here is the list of " << (order == 'a' ? "Least" : "Most") << " Selling Products in " 
         << (order == 'a' ? "Ascending" : "Descending") << " Order";
    setcolor(7);

    cout << "\n\n\n\n\t\t\t";
    delete[] indexes; // Free Memory
    delete[] tem_sell;
    hold();

}

void deleteDisclaimer(string entity) {
    
    cout << endl << endl << endl << "\t\t";
    setcolor(14);
    cout << "Disclaimer : You Cannot Completely Delete " << entity << " From System.\n"s
            << "\t\tAs it will result in losing a major data About it.Causing Erorrs\n"
            << "\t\tin Calculations and Managing Old Records History.\n";
    cout << "\n\t\tBut You Can Disable " << entity <<"\n";
    setcolor(7);

}

void viewRequests(string moder_first_name[],int moder_IDs[],bool moder_flag[],string reportSubject[],string reports[],int report_moderator[],bool report_flag[],int report_status[],int MAX_MODERATORS,int MAX_REPORTS,int status) {

    system("cls");
    print_logo();
    printHeader("Requests");

    cout << left;

    cout << "\t\t" << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "\t\t" << "┃" << setw(5) << centerString("No.",5) << "┃" << setw(17) << centerString("Moderator",17) << "┃" << setw(51) << centerString("Subject",50) << "┃" << endl;
    cout << "\t\t" << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

    int counter  = 0;

    for(int i = 0;i < MAX_REPORTS;i++) {
        if(report_flag[i] && report_status[i] == status) {

            int index = returnIndexByID(moder_IDs,moder_flag,report_moderator[i],MAX_MODERATORS);
            cout << "\t\t┃" << setw(5) << centerString(pad(++counter,2),5) << "┃" << setw(17) << centerString(moder_first_name[index],17) << "┃ " << setw(50) << reportSubject[i] << "┃" << endl;
        }
    }

    if(counter == 0) // if no request available

    cout << "\t\t" << "┃                              No Requests Yet                              ┃" << endl;
    cout << "\t\t" << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    if(counter != 0) { // if request available then check it
            
        cout << "\n\n\t\t";
        cout << "Do you want to Read Request : ";
        if(yesnt()) {

            cout << "\n\n\t\t";
            int n = intValidation("Review Number to View Request","",1,counter);
            viewRequest(moder_first_name,moder_IDs,moder_flag,reportSubject,reports,report_moderator,report_flag,report_status,MAX_MODERATORS,MAX_REPORTS,status,n);
                                            
        }
    }    
        cout << "\n\n\t\t";
        hold();
}

void viewRequest(string moder_first_name[],int moder_IDs[],bool moder_flag[],string reportSubject[],string reports[],int report_moderator[],bool report_flag[],int report_status[],int MAX_MODERATORS,int MAX_REPORTS,int status,int n) {
    
    system("cls");
    print_logo();
    printHeader(makeIDString("Request No. ",n));

    int index = -1;
    int counter = 0;

    for(int i = 0;i < MAX_REPORTS;i++) {

        if(report_flag[i] && report_status[i] == status)
            counter++;
        if(counter == n) {
            index = i;
            break;
        }

    }

    setcolor(12);
    cout << "\n\n\t\tSubject : " ;
    setcolor(7);

    cout << reportSubject[index];

    setcolor(14);
    cout << "\n\n\n\t\t" << reports[index];
    setcolor(7);

    if(report_status[index] == -1) { // if request is pending
        
        cout << "\n\n\t\tDo You Want to Approve/Disapprove Request :";
        if(yesnt()) {
            cout << "\n\n\t\t";
            cout << "\n\n\t\t1.\tApprove\n\t\t2.\tDisapprove\n\n\t\t";
            int option = intValidation("","",1,2);

            if(option == 1)
                report_status[index] = 1; // Approve
            else
                report_status[index] = 2; // Disapprove
        }

    }

}

void printHeader(string str) {

    setcolor(3);
    cout << "\t\t" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    cout << "\t\t" <<  centerString(str,80) << endl; // print in center
    cout << "\t\t" << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << endl;
    setcolor(7);
    cout << endl << endl << endl;


}

void printBuyedItems(string products[],bool pro_flag[],int custID,int pro_IDs[],int purchases[],int item_purchases[][4],int purchaseID,int item_purCount, int MAX_PRODUCTS,int& distinctCounter) {

    system("cls");
    print_logo();
    printHeader("Give Review");

    setcolor(14);
    cout << "\n\n\t\tNote : You Can Give Review Only to Those Items that You Have Purchased Already.\n\n";
    setcolor(7);

    // get array of buyed products IDs
    int* disproducts = returnBuyedProducts(custID,purchases,item_purchases,purchaseID,item_purCount,MAX_PRODUCTS,distinctCounter);

    setcolor(14);
    for(int i = 0;i < distinctCounter; i++) {
        for(int j = 0;j < MAX_PRODUCTS;j++) {

            if(pro_IDs[j] == disproducts[i]) {

                int index = returnIndexByID(pro_IDs,pro_flag,disproducts[i],MAX_PRODUCTS); // get index of product by ID

                cout << "\t\tPoduct ID : " << makeIDString("PR",disproducts[i]);
                cout << "\t\tPoduct Name : " << products[index] << "\t\t";
                cout << endl;
                break;
            }

        }
    }
    setcolor(7);

}

void viewMyReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[],int reviewStatus[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS) {
    system("cls");
    print_logo();

    viewProductReviews(custID,reviews,reviewRating,reviewType,reviewProID,reviewCustID,products,pro_IDs,reviewStatus,pro_flag,review_flag,MAX_PRODUCTS,MAX_REVIEWS);
    viewGeneralReviews(custID,reviews,reviewRating,reviewType,reviewProID,reviewCustID,products,pro_IDs,reviewStatus,pro_flag,review_flag,MAX_PRODUCTS,MAX_REVIEWS);
    


}

void viewProductReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[],int reviewStatus[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS) {

    printHeader("Product Reviews");

    
    int distinctCounter = 0;

    // SELECT * FROM reviews WHERE reviews.custID = custID GROUP BY reviews.proID;
    
    int* disproducts = returnReviewedProducts(custID,reviewProID,reviewCustID,reviewType,review_flag,MAX_PRODUCTS,MAX_REVIEWS,distinctCounter);
    
    if(distinctCounter == 0) {
        setcolor(14);
        cout << "\n\n\t\t\tYou Have Not Review Any Product Yet\n\n";
        setcolor(7);
    }

    cout << left;

    for (int i = 0; i < distinctCounter; i++) {

            int index = returnIndexByID(pro_IDs,pro_flag,disproducts[i],MAX_PRODUCTS);
            cout << "\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
            cout << "\t\t┃" << centerString(("Product " + intToString(i+1) + " : " + products[index]),77) << "┃\n";

            cout << "\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";


            double avg = 0;
            int total = 0;

        for (int j = 0; j < MAX_REVIEWS; j++) {
            if (!review_flag[j]) break;

            if (reviewType[j] != 2) continue; // Only product reviews

            if (reviewProID[j] == disproducts[i] && reviewCustID[j] == custID) {

                avg += reviewRating[j];
                total++;

                string rating = intToString(reviewRating[j]) + "/5";
                cout << "\t\t┃" << centerString("Review:",10) << setw(67) << reviews[j] << "┃\n";


                cout << "\t\t┃" << centerString("Status:",10);

                if(reviewStatus[j] == -1)
                    setcolor(14);
                else if(reviewStatus[j] == 1)
                    setcolor(10);
                else if(reviewStatus[j] == 2)
                    setcolor(12);
            
            
                cout << setw(67) << giveReviewStatus(reviewStatus[j]);
                setcolor(7);
                cout << "┃\n";


                cout << "\t\t┃" << centerString("Rating:",10) << setw(67) << rating << "┃\n";
                cout << "\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";

            }
        }       string rating = " Average Rating : " + doubleToString(avg / total,2);
                cout << "\t\t┃" << setw(77) << rating << "┃\n";
                cout << "\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";

    }
    
}


void viewGeneralReviews(int custID, string reviews[], int reviewRating[], int reviewType[], 
                   int reviewProID[], int reviewCustID[],string products[],int pro_IDs[],int reviewStatus[], bool pro_flag[], bool review_flag[], 
                   int MAX_PRODUCTS, int MAX_REVIEWS) {

        printHeader("General Reviews");

        cout << left;

        int counter = 0;

        for (int j = 0; j < MAX_REVIEWS; j++) {
        if (!review_flag[j]) break;

        if (reviewType[j] != 1) continue; // Only General reviews

        if (reviewCustID[j] == custID) {

            string rating = intToString(reviewRating[j]) + "/5";

            cout << "\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
            cout << "\t\t┃" << centerString(("Review " + intToString(++counter)),77) << "┃\n";

            cout << "\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n";

            cout << "\t\t┃" << centerString("Review:",10) << setw(67) << reviews[j] << "┃\n";
            cout << "\t\t┃" << centerString("Status:",10);

            if(reviewStatus[j] == -1)
                setcolor(14);
            else if(reviewStatus[j] == 1)
                setcolor(10);
            else if(reviewStatus[j] == 2)
                setcolor(12);
            
            
            cout << setw(67) << giveReviewStatus(reviewStatus[j]);
            setcolor(7);
            cout << "┃\n";

            cout << "\t\t┃" << centerString("Rating:",10) << setw(67) << rating << "┃\n";
            cout << "\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\n";

        }
    }

        if(counter == 0) {
            setcolor(14);
            cout << "\n\n\t\t\tYou Have Not Give any General Review\n\n";
            setcolor(7);
        }

}


void showHistory(int purchases[],double purchaseBill[],int item_purchases[][4],int custID,string products[],bool pro_flag[],int pro_IDs[],int MAX_PRODUCTS,int MAX_PURCHASES,int& item_purCount) {

    system("cls");
    print_logo();
    printHeader("Your History");

    bool noPurchase = true;
    int p_count = 0;

    cout << left;


    for(int i = 0; i < MAX_PURCHASES;i++) {

        if(purchases[i] == custID) { // Check CustomerID in Purchases
            if(noPurchase)
                cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl; // 66
            else
                cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl; // 66

            noPurchase = false;

            string purchaseHeader = "Purchase " + pad(++p_count,2) + " - Bill : " + doubleToString(purchaseBill[i],2);

            cout << "\t\t\t┃";
            setcolor(3);
            cout << centerString(purchaseHeader,47);
            setcolor(7);
            cout << "┃" << endl;

            cout << "\t\t\t┣━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┫" << endl; // 66

            cout << "\t\t\t┃ " << setw(14) << "Name" << "┃ " << setw(14) << "Quantity" << "┃ " << setw(14) << "Price" << "┃" << endl; // 66

            cout << "\t\t\t┣━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┫" << endl; // 66

            for(int j = 0;j < item_purCount;j++) {

                int proIndex = returnIndexByID(pro_IDs,pro_flag,item_purchases[j][1],MAX_PRODUCTS);


                if(item_purchases[j][0] == i) { //check purchase ID

                    cout << "\t\t\t┃ " << setw(14) << products[proIndex] << "┃ " << setw(14) << item_purchases[j][2] << "┃ " << setw(14) << item_purchases[j][3] << "┃" << endl; // 66
                    
                }
            }

        }

    }
        if(!noPurchase)
            cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        else {
            setcolor(14);
            cout << "\n\n\t\tNo Purchase Made Yet.\n\n\t\t";
            setcolor(7);
        }

}

void showmoderatorProfile(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], 
                        string moder_CNIC[], string moder_email[], char moder_phone[][10], int moder_salary[], 
                        int moder_IDs[], bool moder_flag[], int moderID, int MAX_MODERATORS) {

    system("cls");
    print_logo();


    cout << left;

    for (int i = 0; i < MAX_MODERATORS; i++) {
        if (moder_flag[i] && moder_IDs[i] == moderID) {  // Check if the moderator record is valid and matches the given ID

            printHeader(moder_first_name[i] + " " + moder_last_name[i]);

            cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
            cout << "\t\t\t┃           ---- Moderator Profile ----           ┃" << endl;
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

            cout << "\t\t\t┃" << setw(19) << " Moderator ID" << "┃" << " " << setw(28) << moder_IDs[i] << "┃" << endl;

            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;

            cout << "\t\t\t┃" << setw(19) << " First Name" << "┃" << " " << setw(28) << moder_first_name[i] << "┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " Last Name" << "┃" << " " << setw(28) << moder_last_name[i] << "┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " Username" << "┃" << " " << setw(28) << moder_username[i] << "┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " Password" << "┃" << " " << setw(28) << moder_password[i] << "┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " CNIC" << "┃" << " " << setw(28) << moder_CNIC[i] << "┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " Email" << "┃" << " " << setw(28) << moder_email[i] << "┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " Phone" << "┃" << " " << "03" << moder_phone[i] << "                 ┃" << endl;
            
            cout << "\t\t\t┣━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << endl;
            
            cout << "\t\t\t┃" << setw(19) << " Salary" << "┃" << " " << setw(28) << postfixInt(moder_salary[i],"rupees")  << "┃" << endl;

            cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

            return;  // Exit the function after finding and displaying the profile
        }
    }

    cout << "Moderator with ID " << moderID << " not found or is inactive." << endl;  // If no match is found
}


void showmoderators(string moder_first_name[],string moder_username[],string moder_password[],int moder_IDs[],bool moder_flag[],int MAX_MODERATORS,bool& found) {

    system("cls");
    print_logo();
    printHeader("Moderators Detail");
    cout << left;

    
    cout << "\n\t\t\t┏━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓" << endl; // 66
    cout << "\t\t\t┃" << setw(16) << " Moderator ID" << "┃" << setw(15) << " First Name" << "┃"  << setw(15) << " Username" << "┃"  << setw(15) << " Password" << "┃" << endl;
    cout << "\t\t\t┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl; // 66



    for(int i = 0; i < MAX_MODERATORS; i++) {
        if(moder_flag[i]) {

            found = true;

            cout << "\t\t\t┃";
            cout << " " << setw(15) << moder_IDs[i] << "┃";
            cout << " " << setw(14) << moder_first_name[i] << "┃";
            cout << " " << setw(14) << moder_username[i] << "┃";
            cout << " " << setw(14) << moder_password[i];
            cout << "┃";
            cout << endl;

        }

    }
    if(!found)
    cout << "\t\t\t┃      N/A       ┃      N/A      ┃     N/A       ┃      N/A      ┃\n";

    cout << "\t\t\t┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl; // 66


}

void showStock(string products[],bool pro_flag[],int pro_IDs[],int pro_stock[],int MAX_PRODUCTS,bool& flag) {

    system("cls");
    print_logo();
    printHeader("Stock Of Items");

    cout << left;

    cout << "\t\t\t\t┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓" << endl; // 66
    cout << "\t\t\t\t┃" << setw(15) << " ID" << "┃"  << setw(15) << " Name" << "┃"  << setw(15) << " Stock" << "┃" << endl;
    cout << "\t\t\t\t┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl; // 66


    for(int i = 0; i < MAX_PRODUCTS; i ++) {
        if(pro_flag[i]) {

            flag = true;

            cout << "\t\t\t\t┃";
            cout << " " << setw(14) << pro_IDs[i] << "┃";
            cout << " " << setw(14) << products[i] << "┃";
            cout << " " << setw(14);

            if(pro_stock[i] <= 10) {
                setcolor(12);
            } else if(pro_stock[i] > 100) {
                setcolor(14);
            } 
            cout << pro_stock[i];
            setcolor(7);

            cout << "┃";
            cout << endl;

        }
    }
    if(!flag)
    cout << "\t\t\t\t┃      N/A      ┃      N/A      ┃      N/A      ┃\n";

    cout << "\t\t\t\t┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl; // 66

}

void outOfStock(string products[],bool pro_flag[],int pro_IDs[],int pro_stock[],int MAX_PRODUCTS,bool& flag) {


    system("cls");
    print_logo();
    printHeader("Out Of Stock Items");

    cout << left;

    cout << "\t\t\t\t┏━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓" << endl; // 66
    cout << "\t\t\t\t┃" << setw(15) << " ID" << "┃"  << setw(15) << " Name" << "┃"  << setw(15) << " Stock" << "┃" << endl;
    cout << "\t\t\t\t┣━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl; // 66


    for(int i = 0; i < MAX_PRODUCTS; i ++) {
        if(pro_flag[i] && pro_stock[i] == 0) {

            flag = true;

            cout << "\t\t\t\t┃";
            cout << " " << setw(14) << pro_IDs[i] << "┃";
            cout << " " << setw(14) << products[i] << "┃";
            cout << " " << setw(14);

            if(pro_stock[i] <= 10) {
                setcolor(12);
            } else if(pro_stock[i] > 100) {
                setcolor(14);
            } 
            cout << pro_stock[i];
            setcolor(7);

            cout << "┃";
            cout << endl;

        }
    }
    if(!flag)
    cout << "\t\t\t\t┃      N/A      ┃      N/A      ┃       N/A     ┃\n";
    cout << "\t\t\t\t┗━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl; // 66

}

void showDisabledProducts(string products[],double pro_cprices[],int pro_profit_percent[],int pro_stock[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,bool& flag) {
    
    system("cls");
    print_logo();
    printHeader("Disabled Products List");

    int count = 0;

    cout << left;

    cout << "\t\t┏━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓" << endl; // 66
    cout << "\t\t┃" << setw(16) << " Count" << "┃" << setw(15) << " ID" << "┃"  << setw(15) << " Name" << "┃"  << setw(15) << " Price" << "┃" << endl;
    cout << "\t\t┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl; // 66

    for(int i = 0; i < MAX_PRODUCTS;i++) {
        if(pro_flag[i] && !pro_active[i]) {
            flag = true;
            cout << "\t\t┃";
            cout << " " << setw(15) << ++count << "┃";
            cout << " " << setw(14) << makeIDString("PR",pro_IDs[i]) << "┃";
            cout << " " << setw(14) << products[i] << "┃";
            cout << " " << setw(14) << pro_cprices[i] * (1 + pro_profit_percent[i] / 100);
            cout << "┃";
            cout << endl;
        }
    }
    if(!flag)
    cout << "\t\t┃       N/A      ┃     N/A       ┃     N/A       ┃    N/A        ┃\n";
    cout << "\t\t┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl; // 66

}

void showPrices(string products[],double pro_cprices[],int pro_profit_percent[],int pro_stock[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,bool& flag) {
    
    system("cls");
    print_logo();
    printHeader("Products Prices List");

    int count = 0;

    cout << left;

    cout << "\t\t┏━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓" << endl; // 66
    cout << "\t\t┃" << setw(16) << " Count" << "┃" << setw(15) << " ID" << "┃"  << setw(15) << " Name" << "┃"  << setw(15) << " Price" << "┃" << endl;
    cout << "\t\t┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl; // 66

    for(int i = 0; i < MAX_PRODUCTS;i++) {
        if(pro_flag[i] && pro_stock[i] != 0 && pro_active[i]) {
            flag = true;
            cout << "\t\t┃";
            cout << " " << setw(15) << ++count << "┃";
            cout << " " << setw(14) << makeIDString("PR",pro_IDs[i]) << "┃";
            cout << " " << setw(14) << products[i] << "┃";
            cout << " " << setw(14) << pro_cprices[i] * (1 + pro_profit_percent[i] / 100.0);
            cout << "┃";
            cout << endl;
        }
    }
    if(!flag)
    cout << "\t\t┃       N/A      ┃     N/A       ┃     N/A       ┃    N/A        ┃\n";
    cout << "\t\t┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl; // 66

}

void showProductsAdmin(string products[],double pro_cprices[],int pro_profit_percent[],bool pro_active[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS) {
    
    system("cls");
    print_logo();
    printHeader("Products With Cost Price And Sale Price");
    int count = 0;
    bool disFound = false;

    cout << left;

    cout << "\t┏━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓" << endl; // 66
    cout << "\t┃" << setw(16) << " Count"
         << "┃" << setw(15) << " ID"
         << "┃"  << setw(17) << centerString("Name",17) 
         << "┃"  << setw(15) << centerString("Cost Price",15) 
         << "┃"  << setw(18) << " Profit Percent" 
         << "┃"  << setw(15) << " Sale Price" 
         << "┃" << endl;

    cout << "\t┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫" << endl; // 66

    for(int i = 0; i < MAX_PRODUCTS;i++) {
        if(pro_flag[i]) {
            cout << "\t┃";
            cout << " " << setw(15) << ++count << "┃";
            cout << " " << setw(14) << makeIDString("PR",pro_IDs[i]) << "┃";
            cout << " ";
            if(!pro_active[i]) {

                disFound = true;
                setcolor(14);

            }
            cout << setw(16) << centerString(products[i],16);
            setcolor(7);
            cout << "┃";
            cout << " " << setw(14) << prefixToDouble(pro_cprices[i],"Rs.",2) << "┃";
            cout << " " << setw(17) << centerString(postfixInt(pro_profit_percent[i],"%"),14) << "┃";
            cout << " " << setw(14) << prefixToDouble(pro_cprices[i] * (1 + pro_profit_percent[i] / 100.0),"Rs.",2);
            cout << "┃";
            cout << endl;
        }
    }
    cout << "\t┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl; // 66

    if(disFound) {

    setcolor(14);
    cout << "\n\t\tNote: The Products with yellow color are disabled.";
    setcolor(7);

    }

}

void print_logo() {

    cout << endl << endl << endl;

    cout << "       ██╗   ██╗████████╗██╗██╗     ██╗████████╗██╗   ██╗    ███████╗████████╗ ██████╗ ██████╗ ███████╗" << endl;
    cout << "       ██║   ██║╚══██╔══╝██║██║     ██║╚══██╔══╝╚██╗ ██╔╝    ██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██╔════╝ " << endl;
    cout << "       ██║   ██║   ██║   ██║██║     ██║   ██║    ╚████╔╝     ███████╗   ██║   ██║   ██║██████╔╝█████╗  " << endl;
    cout << "       ██║   ██║   ██║   ██║██║     ██║   ██║     ╚██╔╝      ╚════██║   ██║   ██║   ██║██╔══██╗██╔══╝  "<< endl;
    cout << "       ╚██████╔╝   ██║   ██║███████╗██║   ██║      ██║       ███████║   ██║   ╚██████╔╝██║  ██║███████╗ "<< endl;
    cout << "        ╚═════╝    ╚═╝   ╚═╝╚══════╝╚═╝   ╚═╝      ╚═╝       ╚══════╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚══════╝ " << endl;

    cout << endl << endl << endl;

}

// Delete/Disable Functions

void deletemoderator(bool moder_flag[], int moder_IDs[], int moderID, int MAX_MODERATORS) {

    for (int i = 0; i < MAX_MODERATORS; i++) {
        if (moder_flag[i] && moder_IDs[i] == moderID) {
            moder_flag[i] = false; // Mark as free index
            cout << "\n\n\t\tModerator deleted successfully." << endl;
            return;
        }
    }

    cout << "\n\n\t\tNo Moderator found with ID " << moderID << "." << endl;
}
void disableProduct(int pro_IDs[],bool pro_active[],bool pro_flag[],int ID,int size) {

    int index = returnIndexByID(pro_IDs,pro_flag,ID,size);

    if(index != -1 && pro_active[index] == true) {

        pro_active[index] = false; // change active state
        cout << "\n\n\t\tProduct Disabled Successfully." << endl;
        setcolor(14);
        cout << "\n\n\t\tNow This Product will not be visible to customers for purchase.You\n\t\tcan enable it again anytime.";
        setcolor(7);
        return;
    
    }

    cout << "\n\t\tProduct Not Found." << endl;
         
}

// Input Output

void buyItems(string products[],int custID,int pro_IDs[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int purchases[],double purchaseBill[],int item_purchases[][4],
bool pro_flag[],int MAX_PRODUCTS,int MAX_PURCHASES,int& purchaseID,int& item_purCount,int productCount) {

    if(purchaseID == MAX_PURCHASES) {
        cout << "Some Error on System." << endl;
        return;
    }

    int tem_int,proIndex = -1;

    int tem_stock[productCount];

    copyIntArray(tem_stock,pro_stock,productCount); // copy stock in array so that it dont get modified untill customer consents to pay bill

    int cart[10][2]; // productID,quantity
    int cartN = 0;

    while(true) {
        cout << "\n\n\t\t";
        tem_int = intValidation("Product ID","PR",1,productCount - 1);
        int index = returnIndexByID(pro_IDs,pro_flag,tem_int,MAX_PRODUCTS);
        if(index == -1 || pro_stock[index] == 0) {

            setcolor(4);
            cout << "\n\n\n\t\tWrong Product ID" << endl;
            setcolor(7);
            continue;
        }
        cart[cartN][0] = tem_int;
        cout << "\n\t\t";
        setcolor(3);
        cout << "\n\t\tProduct Name : " << products[index];
        cout << "\n\t\tAvailable Stock : " << tem_stock[index];
        cout << "\n\t\t\n\t\t";
        setcolor(7);
        cart[cartN][1] = intValidation("Quantity","",1,tem_stock[index]);
        tem_stock[index] -= cart[cartN][1]; // decrease temporary stock in case user again select same product

        cartN++;

        if(cartN == 10) {
            cout << "Max Items Selected for 1 Purchase." << endl;
            break;
        }

        setcolor(10);
        cout << "\n\n\t\tDo you want to buy more items or Print Bill: (1/2)\n";
        cout << "\n\t\t";
        setcolor(7);

        if(intValidation("","",1,2) == 1) {

            bool flag = false;

            showPrices(products,pro_cprices,pro_profit_percent,tem_stock,pro_active,pro_IDs,pro_flag,MAX_PRODUCTS,flag);

        } else break;

    }

    system("cls");
    print_logo();
    printHeader("Your Bill");
    
    cout << left;

    cout << "\n\t\t┏━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┓"; // 66
    cout << "\n\t\t┃" << setw(16) << " Name" << "┃" << setw(15) << " Quantity" << "┃"  << setw(15) << " Unit Price" << "┃"  << setw(15) << " Bill" << "┃";
    cout << "\n\t\t┣━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━┫"; // 66


        double total = 0; // Total Bill of this Purchase

        for(int i = 0;i < cartN;i++) {

            proIndex = returnIndexByID(pro_IDs,pro_flag,cart[i][0],MAX_PRODUCTS);

            double item_price = pro_cprices[proIndex] * (1 + pro_profit_percent[proIndex]/100.0); // Unit price
            double t_price = cart[i][1] * item_price; // Quantity * Unit Price
            total += t_price; // Increase Total

            cout << "\n\t\t┃";
            cout << " " << setw(15) << products[proIndex] << "┃"; // Name
            cout << " " << setw(14) << cart[i][1] << "┃"; // Quantity
            cout << " " << setw(14) << item_price << "┃"; // unit price
            cout << " " << setw(14) << t_price; // price

            cout << "┃";

        }

        cout << "\n\t\t┗━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┛" << endl;

        cout << "\n\t\tTotal Price : " << total << endl;

        cout << "\n\t\tDo you want to pay Bill : ";

        if(yesnt()) {

            purchases[purchaseID] = custID;
            purchaseBill[purchaseID] = total;

            for(int i = 0;i < cartN;i++) {

                proIndex = returnIndexByID(pro_IDs,pro_flag,cart[i][0],MAX_PRODUCTS);

                item_purchases[item_purCount][0] = purchaseID; // purchaseID
                item_purchases[item_purCount][1] = cart[i][0]; // productID
                item_purchases[item_purCount][2] = cart[i][1]; // quantity
                item_purchases[item_purCount][3] = (pro_cprices[proIndex] * (1 + pro_profit_percent[proIndex]/100.0)) * cart[i][1]; // price
                pro_stock[proIndex] -= cart[i][1]; // decrease orignal stock
                pro_sell[proIndex] += cart[i][1]; // increase sell count
                item_purCount++;

            }

            purchaseID++;

            cout << "\n\n\t\tThanks for This Purchase." << endl;
            cout << "\n\t\t";
            hold();

        }

}
void reportToAdmin(int moderator,string reportSubject[],string reports[],bool report_flag[],int report_status[],int report_moderator[],int MAX_REPORTS) {

    system("cls");
    print_logo();

    printHeader("Report To Admin");

    for(int i = 0;i < MAX_REPORTS;i++) {
        if(!report_flag[i]) {

            cout << "\t\tEnter Report Subject (Max 20 Characters)" << endl;
            cout << endl << endl <<"\t\t";

            setcolor(14);

            reportSubject[i] = getString(20);

            setcolor(7);

            
            system("cls");
            print_logo();

            printHeader("Report To Admin");

            cout << "\t\tSubject : " << reportSubject[i];

            cout << endl << endl << endl;

            cout << "\t\tEnter Your Report (Max 200 Characters)" << endl;

            cout << endl << endl << endl << "\t\t";

            setcolor(14);
            reports[i] = getString(200);
            setcolor(7);

            report_flag[i] = true;
            report_status[i] = -1; // pending
            report_moderator[i] = moderator; // moderator ID to check my request

            cout << endl << endl << endl;
            cout << "\t\tReport Send to Admin Successfully" << endl;

            int n = 0;
            while(n != 13)
                n = getch();
                    
            return;
        }
    }

    cout << "Some Error in System" << endl;
    getch();

}

void moderateReviews(int moderID,bool review_flag[],int reviewCustID[],int reviewModer[],int reviewProID[],int reviewRating[],string reviews[],int reviewStatus[],int reviewType[],
                    string cust_name[],bool cust_flag[],int cust_IDs[],int MAX_CUSTOMERS,
                    string products[],int pro_IDs[],bool pro_flag[],int MAX_PRODUCTS,int MAX_REVIEWS,int type,bool edit) {

    system("cls");
    print_logo();
    printHeader(giveReviewStatus(type) + " Reviews");

    bool found = false;

    cout << left;

    cout << "┏━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━┓" << endl;

    cout << "┃" << setw(14) << centerString("Number",14)
         << "┃" << setw(14) << centerString("Customer",14)
         << "┃"<< setw(66) << centerString("Review",66)
         << "┃"<< setw(14) << centerString("Product",14)
         << "┃" << endl;

    cout << "┣━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━┫" << endl;
    int count = 0;

    for(int i = 0;i < MAX_REVIEWS;i++) {
        if(!review_flag[i]) break;

        if(reviewStatus[i] == type) {

            found = true;

            cout << "┃" << setw(14) << centerString(pad(++count,2),14)
                 << "┃" << setw(14) << centerString(cust_name[returnIndexByID(cust_IDs,cust_flag,reviewCustID[i],MAX_CUSTOMERS)],14)
                 << "┃ "<< setw(65) << reviews[i];

            int index = returnIndexByID(pro_IDs,pro_flag,reviewProID[i],MAX_PRODUCTS);
            
            cout << "┃"<< setw(14);

                
                if(index != -1) {
                    setcolor(6);

                    cout << centerString(products[returnIndexByID(pro_IDs,pro_flag,reviewProID[i],MAX_PRODUCTS)],14);

                    setcolor(7);

                }
                else {
                    setcolor(3);

                    cout << centerString("General",14);

                    setcolor(7);
                }
        
            cout << "┃" << endl;

        }

    }

    if(!found)
    cout << "┃              ┃              ┃                        No review found                           ┃              ┃\n";
    cout << "┗━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━┛" << endl;


    if(edit && found) {

        cout << "\n\n\t\tDo You Want to Edit Status : ";
        
        if(yesnt()) {
            
            cout << "\n\n\t\t";
            int number = intValidation("Review Number to Change Status","",1,count);

            cout << "\n\n\t\tDo you want to \n\n\n\t\t 1.\tApprove\n\t\t 2.\tDissaprove\n\n\n\t\t";
            int choice = intValidation("","",1,2);

            if(choice == 1) {

                int index = returnIndexOfReview(number,review_flag,reviewStatus,MAX_REVIEWS);

                reviewStatus[index] = 1; // approve
                reviewModer[index] = moderID; // approved by which moderator

                moderateReviews(moderID,review_flag,reviewCustID,reviewModer,reviewProID,reviewRating,reviews,reviewStatus,reviewType,
                                            cust_name,cust_flag,cust_IDs,MAX_CUSTOMERS,
                                            products,pro_IDs,pro_flag,MAX_PRODUCTS,MAX_REVIEWS,-1,true);
            }
                                            
            if(choice == 2) {

                
                int index = returnIndexOfReview(number,review_flag,reviewStatus,MAX_REVIEWS);

                reviewStatus[index] = 2; // disapprove
                reviewModer[index] = moderID; // disapprove by which moderator

                moderateReviews(moderID,review_flag,reviewCustID,reviewModer,reviewProID,reviewRating,reviews,reviewStatus,reviewType,
                                            cust_name,cust_flag,cust_IDs,MAX_CUSTOMERS,
                                            products,pro_IDs,pro_flag,MAX_PRODUCTS,MAX_REVIEWS,-1,true);

                }
            }
        } else {
            cout << "\n\n";
            hold();
        }

}

void proReview(int custID,int purchases[],int item_purchases[][4],int purchaseID,int item_purCount,int productCount,int MAX_PRODUCTS,
               string reviews[],int reviewProID[], int reviewCustID[], int reviewRating[],int reviewModer[],int reviewStatus[],bool review_flag[],int reviewType[], int MAX_REVIEWS) {

    int hehe = -1;
    cout << "\n\t\tDo you want to give Review about any of Product : ";
    if(!yesnt())
        return;

    cout << "\n\n\t\t";
    hehe = intValidation("Product ID","PR",1,productCount);

    int counter = 0;
    bool buyed = false;

    int* buyedItems = returnBuyedProducts(1,purchases,item_purchases,purchaseID,item_purCount,MAX_PRODUCTS,counter);

    for(int i = 0;i < counter;i++) {
        if(hehe == buyedItems[i]) {
            buyed = true;
            break;
        }
    }

    if(!buyed) {
        setcolor(12);
        cout << "\n\n\t\tYou Have not buyed this item.\n\n\t\t";
        setcolor(7);
        hold();
        return;
    }

    for(int i = 0; i < MAX_REVIEWS; i++) {
        if(!review_flag[i]) {

            cout << "\n\n\t\tEnter your Review : ";
            setcolor(14);
            reviews[i] = getString(60);
            cout << "\n\t\t";
            setcolor(7);

            reviewRating[i] = intValidation("Your Rating ","",0,5);

            reviewCustID[i] = custID;

            reviewProID[i] = hehe;
            review_flag[i] = true;
            reviewStatus[i] = -1;
            reviewModer[i] = -1;
            reviewType[i] = 2;

            setcolor(14);
            cout << "\n\n\t\tYour Review is Submitted.Our moderator will Approve your review soon\n\n\t\t";
            setcolor(7);
            hold();

            return;
        }

    }

    cout << "Some Error on System." << endl;

}
void generalReview(int custID, string reviews[],int reviewProID[], int reviewCustID[], int reviewRating[],int reviewModer[],int reviewStatus[],bool review_flag[],int reviewType[], int MAX_REVIEWS) {

    system("cls");
    print_logo();
    printHeader("Give General Review About Your Experience");

    for(int i = 0; i < MAX_REVIEWS; i++) {
        if(!review_flag[i]) {

            cout << "\t\tEnter your Review (Max 60 Characters)";
            cout << "\n\n\t\t";
            setcolor(14);
            reviews[i] = getString(60);
            setcolor(7);
            cout << "\n\n\t\t";
            reviewRating[i] = intValidation("Rating ","",0,5);

            reviewCustID[i] = custID;

            reviewProID[i] = -1;
            review_flag[i] = true;
            reviewStatus[i] = -1;
            reviewModer[i] = -1;
            reviewType[i] = 1;

            setcolor(14);
            cout << "\n\n\t\tYour Review is Submitted.Our Moderator will Approve your review soon\n\n\t\t";
            setcolor(7);
            hold();

            return;
        }

    }

    cout << "Some Error on System." << endl;

}
void updatemoderator(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], 
                   string moder_CNIC[], string moder_email[], char moder_phone[][10], int moder_salary[], 
                   int moder_IDs[], bool moder_flag[], int moderID, int MAX_MODERATORS) {


    int choice = -1;
    int index = -1;

    for (int i = 0; i < MAX_MODERATORS; i++) {

        if (moder_flag[i] && moder_IDs[i] == moderID) {

            index = i;
            break;

        }
    }



    if(index != -1) {

            while (true) { // show updated details each time it changes
            
                showmoderatorProfile(moder_first_name,moder_last_name,moder_username,moder_password,moder_CNIC,moder_email,moder_phone,moder_salary,moder_IDs,moder_flag,moderID,MAX_MODERATORS);
                cout << "\n\n\n";
                printHeader("Edit Moderator Detail");


                cout << "\n\n\t\tWhat would you like to update?\n\n\n\n";
                setcolor(14);
                cout << "\t\t1. First Name\n\t\t2. Last Name\n\t\t3. Username\n\t\t4. Password\n\t\t5. CNIC\n\t\t6. Email\n\t\t7. Phone\n\t\t8. Salary\n\t\t9. Exit\n";
                setcolor(7);
                
                cout << "\n\n\t\t";
                choice = intValidation("","",1,9);

                if(choice == 9)
                    break;
                

                switch (choice) {
                    case 1:
                        cout << "\n\t\tEnter new First Name: ";
                        moder_first_name[index] = getString(15,false,true);

                        break;
                    case 2:
                        cout << "\n\t\tEnter new Last Name: ";
                        moder_last_name[index] = getString(15,false,true);

                        break;
                    case 3:
                        cout << "\n\t\tEnter new Username: ";
                        moder_username[index] = getString(8,false,true);
                        break;
                    case 4:
                        cout << "\n\t\tEnter new Password: ";
                        moder_password[index] = getString(8);
                        break;
                    case 5:
                        cout << "\n\t\tEnter new CNIC: ";
                        moder_CNIC[index] = inputCNIC();
                        break;
                    case 6:
                        cout << "\n\t\tEnter new Email: ";
                        moder_email[index] = inputEmail();
                        break;
                    case 7:
                        cout << "\n\t\tEnter new Phone: ";
                        copy(inputPhoneNo(),moder_phone[index]);
                        break;
                    case 8:
                        cout << "\n\t\tEnter new Salary: ";
                        moder_salary[index] = intValidation("","",1,100000);
                        break;
                }

            }

            return;
    }

    cout << "\n\n\t\tModerator with ID " << moderID << " not found or is inactive." << endl;
    cout << "\n\n\t\t";
    hold();
}
void editStock(string products[],int pro_IDs[],int pro_stock[],bool pro_flag[],int productCount,int MAX_PRODUCTS) {

    int temStock = 0;

    cout << "\n\n\t\t";
    int ID = intValidation("Product ID to edit Stock","PR",1,productCount);

    setcolor(14);
    for(int i = 0; i < MAX_PRODUCTS;i++) {
        if(pro_flag[i] && pro_IDs[i] == ID) {
            cout << "\n\n\t\tProuct Name : " << products[i];
            cout << "\n\n\t\tExisting Stock : " << pro_stock[i];
            setcolor(7);
            cout << "\n\n\t\t";
            cout << "\n\n\t\t1.\tAdd Stock\n\t\t2.\tRemove Stock\n\t\t";
            if(intValidation("","",1,2) == 1) {

                if(pro_stock[i] < 1000) {

                cout << "\n\n\t\t";
                temStock = intValidation("Stock to Add","",1,1000 - pro_stock[i]);
                pro_stock[i] += temStock;

                } else  {
                    cout << "\n\n\t\tMaximum Stock Reached\n\n\t\t";
                    hold();
                }

            } else {

                if(pro_stock[i] > 0) {

                cout << "\n\n\t\t";
                temStock = intValidation("Stock to Remove","",1,pro_stock[i]);
                pro_stock[i] -= temStock;

                } else  {
                    cout << "\n\n\t\tNo Stock Available to Remove\n\n\t\t";
                    hold();
                }
            }

            bool flag = false;
            showStock(products,pro_flag,pro_IDs,pro_stock,MAX_PRODUCTS,flag);

            return;
        }
    }

    cout << "Product Not Found." << endl;
}
void updatePrice(string products[],int pro_IDs[],double pro_cprices[],int pro_profit_percent[],bool pro_flag[],int ID,int size) {

    for(int i = 0; i < size; i++) {
        if(pro_flag[i] && pro_IDs[i] == ID) {

            cout << endl << endl << endl << "\t\t";
            cout << "Product Name : " << products[i] << endl;
            cout << "\t\tOld Price: " << pro_cprices[i] << endl;
            cout << "\t\tOld Profit Percent: " << pro_profit_percent[i] << "%" << endl;

            cout << endl << endl << endl << "\t\t";
            double price = doubleValidation("New Price",10000);
            pro_cprices[i] = price;
            cout << "\n\t\t";
            pro_profit_percent[i] = intValidation("New Profit Percent","",1,99);
            cout << "\n\t\tPrice Updated Successfully." << endl;
            return;
        }
    }

    cout << "\t\tNo Product Found." << endl;

}


// Validation Functions


string inputEmail() {

    string tem = "";

    int bat = 0; // characters before @ excluding '.'
    bool at = false; // @ is present or not
    bool dotAat = false; // '.' is present after @
    int adot = 0; // characters after '.'

    while(true) {

        char ch = _getch(); // get input from user

        if(ch == 13) {

            if(adot >= 2) // if user press enter and all previous conditions are good and there are atleast two characters in domain
                break;
            else
                continue;
        }
            
        if(ch == 8) {
            if(tem.length() == 0) // if user press backsapce and nothing typed
                continue;
            if(lastChar(tem) == '@') { // if erasing character is @ then mark at flag as false

                at = false;
                tem = popOut(tem);
                cout << "\b \b";
                continue;

            }

            if(!at) { // @ is present or not 
                if(lastChar(tem) != '.') // if @ is not encountered and erasing character is not '.' then decrease characters before @
                    bat--;
                tem = popOut(tem);
                cout << "\b \b";
                continue;
            } else {
                if(lastChar(tem) == '.') { // if @ is encountered and erasing character is '.' then mark dotAfter@ to false
                    dotAat = false;
                    tem = popOut(tem);
                    cout << "\b \b";
                    continue;
                } else if(!dotAat) { // if there is no '.' after @ just remove character
                    tem = popOut(tem);
                    cout << "\b \b";
                    continue;
                } else if(dotAat) { // if there is '.' after @ then decrease after dot count
                    adot--;
                    tem = popOut(tem);
                    cout << "\b \b";
                    continue;
                }
            }
                


        }

        if(ch == '@') {
            if(bat < 3) // if user press @ and there are less than 3 characters before @
                continue;
            if(at) // if @ is already present (@ can occur only once)
                continue;

            at = true; // if no @ is present before display @ and maek at flag as true
            cout << ch;
            tem += ch;
            continue;
        }

        if(ch == '.') {
            if(tem.length() == 0) // '.' cannot occur at start
                continue;
            if(lastChar(tem) == '.' || lastChar(tem) == '@') // two consective dots and dot next to @
                continue;
            if(at) { // if @ is present and '.' occurs mark dotAfter@ as true
                cout << ch;
                tem += ch;
                dotAat = true;
                continue;
            }

            // simply print '.'
            cout << ch;
            tem += ch;
            continue;
        }

        if(!isNum(ch) && !isAlpha(ch) && ch != '.') // if typed character is not alphabet,number or '.'
            continue;

        if(isNum(ch)) {
            cout << ch;
            tem += ch;

            if(!at) // if @ is not present then increase beforeAt counter
                bat++;
            if(dotAat) // if '.' is present after @ then increase afterdot count
                adot++;

            continue;
        }

        if(isAlpha(ch)) {
            if(ch < 97) // if Uppercase convert to lower
                ch = ch + 32;
            cout << ch;
            tem += ch;

            if(!at) // if @ is not present then increase beforeAt counter
                bat++;
            if(dotAat) // if '.' is present after @ then increase afterdot count
                adot++;
            continue;
        }

    }

    return tem;

}

string getString(int limit,bool hide,bool alphaOnly) {

    string str = "";

    while(true) {

        char c = getch();

        if(c == 13 && str.length() != 0) // enter after typing something
            break;
        else if(c == 13 && str.length() == 0) // enter without typing
            continue;

        if(str.length() == limit) { // if max limit is reached only can submit
            if(c == 13)
            break;
            else if(c != 8)
                continue;
        }


        if(c == 8) {

            if(str.length() != 0) { // erase if something is present

                cout << "\b \b";
                str = popOut(str); // remove last character from string
                continue;
            
            } else continue;
        }

        if(!printAble(c)) // if character is not printable then ignore
            continue;

        if(alphaOnly) {
            if(!isalpha(c) && c != ' ')
                continue;
        }

            if(hide) // if hides then dont show typed charcater
                cout << "●";
            else cout << c;
            str += c;
    }

    return str;

}

char* inputPhoneNo() {

    char* phone = new char[10];
    cout << "+92 3"; // shows fixed prefix

    int index = 0;

    while(true) {

        char ch = _getch();

        if(ch == 13) {
            if(index != 9) // if length is not complete
                continue;
            else break;
        }

        if(ch == 8) {
            if(index == 0) // erase without typing
                continue;
            if(index == 2) // remove 2 if index is 2
                cout << "\b \b";
            cout << "\b \b";
            index--;
        }

        if(index == 9) // if max length reached
            continue;

        if(isNum(ch)) { // if not number ignore
            cout << ch;
            phone[index++] = ch;
        }

        if(index == 2) // auto add space after company code
            cout << " ";


    }

    phone[9] = '\0'; // insert null character
    return phone;

}

double doubleValidation(string text,double limit,int percesion) {

    string tem;
    int decPlaces = 0; // count digits after '.' to fix precesion

    cout << "Enter " << text << " : ";

    bool point = false; // if '.' is entered or not

    while (true) {
        
        char c = getch();

        if(point && c == '.') // only one '.' can occur
            continue;

        if(c == '.') {
            
            point = true;
            tem += '.';
            cout << '.';
            continue;

        }
        

        if(c == 13 && tem.length() != 0 && strToDouble(tem) != 0) // if user press enter and length is not 0 and value is not 0
            break;

        if(c == 8 && tem.length() != 0) { // erase if something presents

            if(lastChar(tem) == '.') // if erasing character is '.' mark point flag to false
                point = false;

            if(point) // erasing after '.' decrease after dot count
                decPlaces--;

            cout << "\b \b";
            tem = popOut(tem);
            continue;
        }

        if(!isdigit(c)) // if not number ignore
            continue;

        if(decPlaces == percesion) // if precesion reached
            continue;

        if(point) { // increasing after dot counter
            decPlaces++;
        }

        if(strToDouble(tem + c) > limit || strToDouble(tem + c) == 0) // if with typed character value remain in bounderies
            continue;

            tem += c;
            cout << c;
    }
        return strToDouble(tem); // convert inputted string to double and return
}

int intValidation(string text,string prefix,int l_limit,int u_limit) {

    string tem;
    cout << "Enter " << text << " (" << l_limit << " - " << u_limit <<") : " << prefix; // show message with limit and prefix (if any)

    while (true) {
        
        char c = getch();

        if(c == 13 && tem.length() != 0)
            break;

        if(c == 8 && tem.length() != 0) {
            cout << "\b \b";
            tem = popOut(tem);
            continue;
        }

        if(!isdigit(c)) // if not number ignore
            continue;

        if(strToInt(tem + c) > u_limit || strToInt(tem + c) < l_limit) // if not in limits
            continue;

            tem += c;
            cout << c;
    }
        return strToInt(tem);
}

char* inputCNIC() {
    char* CNIC = new char[16]; // 15 characters + null terminator
    int count = 0;            // Number of actual digits present

    while (true) {
        char tem = _getch();

        if (tem == 8) { // Backspace
            if (count > 0) {
                if (count == 6 || count == 14) {
                    // Skip back over the dash
                    cout << "\b \b";
                    count--;
                }
                cout << "\b \b";
                count--;
            }
            continue;
        }

        // Handle Enter Key (Submit only when 15 characters are entered)
        if (tem == 13) {
            if (count == 15) {
                CNIC[count] = '\0'; // Null-terminate the string
                break;
            } else {
                continue; // Ignore Enter if less than 15 characters
            }
        }

        // Handle Numeric Input
        if (isNum(tem)) {

            // Add digit
            if (count < 15) {
                cout << tem;
                CNIC[count] = tem;
                count++;
            }

            // Auto-place dashes
            if (count == 5 || count == 13) {
                cout << '-';
                CNIC[count] = '-';
                count++;
            }
        }
    }

    return CNIC;
}

// Operations

void gotoxy(int x, int y) { // manipulate the position of cursor
    COORD c;

    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void setcolor(int color) { // change color of text

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}

void enableProduct(int pro_IDs[],bool pro_active[],bool pro_flag[],int ID,int size) {

    int index = returnIndexByID(pro_IDs,pro_flag,ID,size);

    if(index != -1 && pro_active[index] != true) { // enable if disabled

        pro_active[index] = true;
        cout << "\n\n\t\tProduct Enabled Successfully." << endl;
        setcolor(14);
        cout << "\n\n\t\tNow This Product will be visible to customers for purchase.";
        setcolor(7);
        return;
    
    }

    cout << "\n\t\tProduct Not Found." << endl;
         
}

void addCustomer(string cust_name[],char cust_CNIC[][16],int cust_IDs[],bool cust_flag[],int custID,int MAX_CUSTOMERS) {

    printBorder();

    for(int i = 0;i < MAX_CUSTOMERS;i++) {
        if(!cust_flag[i]) { // check empty index

            gotoxy(35,18);
            cout << "Enter Your Name (max 15): ";
            setcolor(14);
            cust_name[i] = getString(15,false,true); // get input with limit 15
            setcolor(7);

            gotoxy(35,19);
            cout << "Enter Your CNIC : ";
            setcolor(14);
            copy(inputCNIC(),cust_CNIC[i]);
            setcolor(7);

            cust_flag[i] = true;
            cust_IDs[i] = ++custID;

            gotoxy(40,23);
            setcolor(14);
            cout << "Sign up Successfully." << endl;
            setcolor(7);


            gotoxy(40,27);

            hold();
            return;
        }
    }


    gotoxy(35,18);
    cout << "There is some issue in System" << endl;
    gotoxy(35,20);
    hold();
}

void addmoderator(string moder_first_name[], string moder_last_name[], string moder_username[], string moder_password[], string moder_CNIC[],
                string moder_email[], char moder_phone[][10], int moder_salary[], int moder_IDs[], bool moder_flag[], int& moderID, int MAX_MODERATORS) {

    system("cls");
    print_logo();
    printHeader("Add Moderator to System");
    
    for (int i = 0; i < MAX_MODERATORS; i++) {
        if (!moder_flag[i]) {
            moder_flag[i] = true;

            cout << "\n\n\t\tEnter Moderator First Name (max 15): ";
            setcolor(14);
            moder_first_name[i] = getString(15,false,true);
            setcolor(7);

            cout << "\n\n\t\tEnter Moderator Last Name (max 15): ";
            setcolor(14);
            moder_last_name[i] = getString(15,false,true);
            setcolor(7);

            cout << "\n\n\t\tEnter Moderator Username (max 8): ";
            setcolor(14);
            moder_username[i] = getString(8,false,true);
            setcolor(7);

            cout << "\n\n\t\tEnter Moderator Password (max 8): ";
            setcolor(14);
            moder_password[i] = getString(8);
            setcolor(7);

            cout << "\n\n\t\tEnter Moderator CNIC: ";
            setcolor(14);
            moder_CNIC[i] = inputCNIC();
            setcolor(7);

            cout << "\n\n\t\tEnter Moderator Email: ";
            setcolor(14);
            moder_email[i] = inputEmail();
            setcolor(7);

            cout << "\n\n\t\tEnter Phone Number: ";
            
            setcolor(14);
            copy(inputPhoneNo(),moder_phone[i]);
            setcolor(7);

            cout << "\n\n\t\t";
            moder_salary[i] = intValidation("Moderator Salary","",1,100000);

            moder_IDs[i] = ++moderID;

            cout << "\n\n\t\tModerator added successfully with ID " << moder_IDs[i] << endl;
            cout << "\n\n\t\t";
            hold();
            return;
        }
    }

    cout << "No available slots to add a new moderator." << endl;
}
void addProduct(string products[],double pro_cprices[],int pro_profit_percent[],int pro_IDs[],int pro_stock[],bool pro_active[],bool pro_flag[],int MAX_PRODUCTS,int &productCount) {

    printBorder();

    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(!pro_flag[i]) {
            pro_flag[i] = true;
            pro_active[i] = true;

            gotoxy(35,19);
            cout << "Enter Product Name (max 15): ";
            products[i] = getString(15);

            gotoxy(35,20);
            pro_cprices[i] = doubleValidation("Product Price",10000);

            pro_IDs[i] = ++productCount;

            gotoxy(35,21);
            pro_profit_percent[i] = intValidation("Profit Percent","",1,99);
            
            gotoxy(35,22);
            pro_stock[i] = intValidation("Product Stock","",1,1000);

            gotoxy(35,25);
            
            cout << "Product Addded Successfully." << endl;
            return;
        }
    }

    gotoxy(35,19);
    cout << "No Slot Available for New Product.";
}

// Helping Functions

string prefixToDouble(double n, string prefix,int percesion) {
    prefix += ' '; // make string by adding prefix i.e "Rs. 56.67"
    prefix += doubleToString(n,percesion);
    return prefix;
}

string postfixInt(int n,string str) { // return string by adding prefix
    return intToString(n) + ' ' + str;
}

string giveReviewStatus(int status) { // return review status string
    if(status == 1)
        return "Approved";
    if(status == 2)
        return "Disapproved";
    return "Pending";
}

bool isSame(char* c1,char c2[]) { // compare character arrays

    int i = 0;

    while(c1[i] != '\0') {

        if(c1[i] != c2[i])
            return false;
        i++;
    }
    
    return true;
}

bool isNum(char a) { // check if it is number
    if(a < '0' || a > '9')
        return false;
    return true;
}

char lastChar(string str) { // return last character of the string

    return str[str.length() - 1];

}

bool isAlpha(char a) { // check if alphabet
    if(a >= 'a' && a <= 'z')
        return true;
    if(a >= 'A' && a <= 'Z')
        return true;
    return false;
}

void copyULIntArray(unsigned long int arr1[],const unsigned long int arr2[],int size) {
    for(int i = 0;i < size;i++) // copy unsigned long int array
        arr1[i] = arr2[i];
}

void initializeByIndex(int arr[],int size) { // initialixe array with index number
    for(int i = 0;i < size;i++)
        arr[i] = i;
}

void hold() {

    cout << "Press Enter To Continue"; // holds the program unter user press enter

    while(true) {

        char ch = _getch();
        if(ch == 13)
            break;

    }
}

bool yesnt() { // get yes/no input from user
    
    bool typed = false;
    bool yes = false;

    while(true) {

        char ch = _getch();

        if(ch == 'Y' || ch == 'y' && !typed) {
            typed = true;
            yes = true;
            cout << "Yes";
        }
        else if(ch == 'N' || ch == 'n' && !typed) {
            typed = true;
            yes = false;
            cout << "No ";
        } else if(ch == 8 && typed) {
            typed = false;
            cout << "\b\b\b   \b\b\b";
        }
        else if(ch == 13 && typed)
                break;
    }
    return yes;
}

void sortProducts(int indexes[],unsigned long int numbers[],int size,char order) {
    // Sort array and change corresponding indexes of other array
    for(int i = 0;i < size;i++) {
        for(int j = 0;j < size - 1 - i;j++) {

            bool condition = (order == 'a') ? (numbers[j] > numbers[j+1]) : (numbers[j] < numbers[j+1]);

            if(condition) {
                
                unsigned long int tem = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = tem;

                int item = indexes[j];
                indexes[j] = indexes[j+1];
                indexes[j+1] = item;

            }
        }
    }

}

string centerString(string str,int width) { // add leading and trailing spaces to center string in given space

    string centeredString = "";
    int space = width - str.length();
    int Lspace = space % 2 == 0 ? space / 2 : space / 2 + 1;
    int Rspace = space % 2 == 0 ? space / 2 : space / 2;

    for(int i = 0;i < Lspace;i++)
        centeredString += " ";
    centeredString += str;
    
    for(int i = 0;i < Rspace;i++)
        centeredString += " ";

    return centeredString;
}

bool printAble(char c) { // check is character is printable
    if(c < 32 || c > 127)
        return false;
    return true;
}

int returnIndexOfReview(int number,bool review_flag[],int reviewStatus[],int MAX_REVIEWS) {

    int count = 0;

    for(int i = 0;i < MAX_REVIEWS;i++) {
        if(review_flag[i] && reviewStatus[i] == -1)
            count++;
        if(count == number)
            return i;
    }

    return -1;

}

void copyIntArray(int arr1[],const int arr2[],int size) { // copy int array
    for(int i = 0;i < size;i++)
        arr1[i] = arr2[i];
}

void copy(char* c1, char c2[]) { // copy char arrays

    int i = 0;
    while(c1[i] != '\0') {

        c2[i] = c1[i];
        i++;

    }
    c2[i] = '\0';

}

string popOut(string str) { // remove last character from string

    string tem = "";

    for(int i = 0;i < str.length() - 1 ;i++)
        tem += str[i];
    return tem;
}

string makeIDString(string string,int ID) { // add prefix and pad by adding '0's

    return string + pad(ID,2);
}

int power(int n,int p) { // calculate power of int

    for(int i = 1;i < p;i++)
        n *= n;
    return n;

}

string pad(int n,int width) { // add '0's in start to fill width

    string padded = intToString(n);

    while(padded.length() < width)
        padded = '0' + padded;

    return padded;

}


// Conversions

double strToDouble(string str) {

    double tem = 0;
    bool point = false;
    double place = 0.1;

    for(int i = 0;i < str.length();i++) {

        if(str[i] == '.') {
            point = true;
            continue;
        }

        if(!point) {
            tem = tem * 10 + charToInt(str[i]);
        } else {
            tem = tem + (charToInt(str[i]) * place);
            place /= 10;
        }

    }

    return tem;

}

int charToInt(char a) {
    return a - 48;
}

int strToInt(string str) {

    int n = 0;

    for(int i = 0;i < str.length();i++) {
        n *= 10;
        n += charToInt(str[i]);
    }

    return n;

}

string doubleToString(double n,int percesion) {

    string str = "";
    percesion = power(10,percesion);
    int dec = n;
    str += intToString(dec);

    if(n - dec != 0) {

    int point = (n - dec) * percesion;

    str += '.';
    str += intToString(point);

    }

    return str;
}


char intToChar(int n) {
    return n + 48;
}

string intToString(int n) {

    if(n == 0)
        return "0";

    string tem;

    while(n != 0) {
        tem  = intToChar(n % 10) + tem;
        n /= 10;
    }

    return tem;

}

// Navigation

int navigateMenu(string menuItems[], int menuSize) {
    int selected = 0;
    char key;
    
    printBorder();

    while (true) {

        displayMenu(menuItems, menuSize, selected);
        
        key = _getch();  // Get user input without requiring Enter
        switch (key) {
            case 72:  // Up arrow
                selected = (selected - 1 + menuSize) % menuSize;
                break;
            case 80:  // Down arrow
                selected = (selected + 1) % menuSize;
                break;
            case 13:  // Enter key
                return selected;  // Return the selected index
        }
    }
}

void displayMenu(string menuItems[], int menuSize, int selected) {

    int x = 35; int y = 15;
    gotoxy(x,y);

    cout << "       "<< "■■■ Utility Store System ■■■\n\n";
    x += 5;y += 2;
    for (int i = 0; i < menuSize; i++) {
        gotoxy(x, ++y);
        if (i == selected) {
            setcolor(12);
            cout << " -> ";  // Highlight selected option
        } else {
            cout << "    ";  // Unselected options
        }
        cout << menuItems[i] << "\n";

        setcolor(7);
    }
}

// Authorize Users

int loginCustomer(char cust_CNIC[][16],int cust_IDs[],string cust_name[],bool cust_flag[], int MAX_CUSTOMERS) {

    printBorder();

    gotoxy(45,16);

    cout << "Login as a Customer";

    char* CNIC;

    gotoxy(35,18);
    setcolor(14);
    cout << "Enter Your CNIC : ";
    CNIC = inputCNIC();
    setcolor(7);

    for(int i = 0;i < MAX_CUSTOMERS;i++)
        if(cust_flag[i] && isSame(CNIC,cust_CNIC[i])) { // match CNIC
            gotoxy(42,23);
            cout << "Welcome ";
            setcolor(10);
            cout << cust_name[i] << endl;
            setcolor(7); // Print Customer name
            gotoxy(44,25);
            hold();
            return cust_IDs[i];
        }

    gotoxy(48,23);
    cout << "!Welcome Ooops"; // if CNIC dont match

    gotoxy(40,25);
    hold();
    return -1;
}

int getCredentials(string usernames[], string passwords[],int size,string user) {

    printBorder();

    gotoxy(40,17);
    cout << "\tLogin as " << user;

    string uname, pwd;

    gotoxy(35,19);

    cout << "Enter Username: ";
    setcolor(14);
    uname = getString(8,false,true);
    setcolor(7);
    
    gotoxy(35,20);

    cout << "Enter Password: ";

    pwd = getString(8,true);
    
    for(int i = 0;i < size;i++) {
        if(usernames[i] == uname && passwords[i] == pwd)
            return i; // if credentials are correct return index
    }

    gotoxy(35,22);

    cout << "Ooops!!";

    gotoxy(35,24);
    hold();

    return -1;

}

// Returning FUnctions


int* returnBuyedProducts(int custID,int purchases[],int item_purchases[][4],int purchaseID,int item_purCount,int MAX_PRODUCTS,int& distinctCounter) {

    int* distinctIDs = new int[MAX_PRODUCTS]; // array to store unique IDs

    for(int i = 0;i < purchaseID;i++) { // loop over purchases

        if(purchases[i] == custID) { // if purchase is of requested customer

            for(int j = 0;j < item_purCount;j++) { // loop over items buyed in that purchase

                if(item_purchases[j][0] == i) { // check if this item is of that purchase

                    bool duplicate = false; // consider it as unique

                    for(int k = 0;k < distinctCounter;k++) { // loop over unique IDs array

                        if(distinctIDs[k] == item_purchases[j][1]) { // if ID is already present then mark as duplicate

                            duplicate = true;
                            break;

                        }
                    }

                    if(!duplicate) // if not already present add it to unique IDs array
                        distinctIDs[distinctCounter++] = item_purchases[j][1];

                }

            }
        }

    }

    return distinctIDs; // return unique IDs array
}
int* returnReviewedProducts(int custID,int reviewProID[],int reviewCustID[],int reviewType[],bool review_flag[],int MAX_PRODUCTS,int MAX_REVIEWS,int& distinctCounter) {

    int* distinctIDs = new int[MAX_PRODUCTS]; // array to store unique IDs

    for(int i = 0;i < MAX_REVIEWS;i++) { // loop over reviews

        if(!review_flag[i])  break; // if review not present break loop

        if(reviewType[i] == 2 && reviewCustID[i] == custID) { // if review is of requested user

            bool duplicate = false;

            for(int k = 0;k < distinctCounter;k++) { // check productID of the review with unique IDs array

                if(distinctIDs[k] == reviewProID[i]) {

                    duplicate = true;
                    break;

                }
            }

            if(!duplicate) // if not already present add it
                distinctIDs[distinctCounter++] = reviewProID[i];
         
        }

    }
        
        return distinctIDs; // return unique IDs

}
int returnIndexByID(int IDs[],bool flag[],int ID,int size) {

    for(int i = 0;i < size;i++)
        if(flag[i] && IDs[i] == ID)
            return i;
    return -1;

} 


// File Handling

//// Load the Data Stored in Comma Seperated files to arrays

void loadData(bool pro_flag[],int pro_IDs[],string products[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int& productCount,int MAX_PRODUCTS,
              bool moder_flag[],string moder_first_name[],string moder_last_name[],string moder_username[],string moder_password[],string moder_CNIC[],string moder_email[],char moder_phone[][10],int moder_salary[],int moder_IDs[],int& moderID,int MAX_MODERATORS,
              bool cust_flag[],string cust_name[],char cust_CNIC[][16],int cust_IDs[],int& custID,int MAX_CUSTOMERS,
              int purchases[],double purchaseBill[],int& purchaseID,
              int item_purchases[][4],int& item_purCount,
              bool review_flag[],int reviewType[],int reviewProID[],int reviewCustID[],string reviews[],int reviewStatus[],int reviewModer[],int reviewRating[],int MAX_REVIEWS,
              string reportSubject[],string reports[],bool report_flag[],int report_status[],int report_moderator[],int MAX_REPORTS) {

    int IDcounter = -1;

    ifstream repin("requests.csv");
    IDcounter = 0;

    while(repin) {

        if(!(repin >> report_moderator[IDcounter]))
            break;
        repin.ignore();
        getline(repin,reportSubject[IDcounter], ',');
        repin >> report_status[IDcounter]; repin.ignore();
        getline(repin,reports[IDcounter]);

        report_flag[IDcounter] = true;
        IDcounter++;
    }


    repin.close();



    ifstream revin("reviews.csv");
    IDcounter = 0;

    while(revin) {

        if(!(revin >> reviewStatus[IDcounter]))
            break; 
        
        revin.ignore();
        revin >> reviewType[IDcounter]; revin.ignore();
        revin >> reviewModer[IDcounter]; revin.ignore();
        revin >> reviewProID[IDcounter]; revin.ignore();
        revin >> reviewCustID[IDcounter]; revin.ignore();
        revin >> reviewRating[IDcounter]; revin.ignore();
        getline(revin, reviews[IDcounter]);
        review_flag[IDcounter] = true;

        IDcounter++;

    }

    revin.close();


    // Item Purchase

    ifstream itemin("item-purchase.csv");

    while(itemin) {
    
        if(!(itemin >> item_purchases[item_purCount][0]))
            break;
        itemin.ignore();
        itemin >> item_purchases[item_purCount][1];
        itemin.ignore();
        itemin >> item_purchases[item_purCount][2];
        itemin.ignore();
        itemin >> item_purchases[item_purCount][3];
        itemin.ignore();
        
        item_purCount++;
    }

    itemin.close();

    // Purchase

    ifstream purin("purchases.csv");

    while(purin) {
        if(!(purin >> purchases[purchaseID]))
            break;
        purin.ignore();
        purin >> purchaseBill[purchaseID];
        purin.ignore();
        purchaseID++;
    }

    purin.close();

    // Customers

    ifstream custin("customers.csv");
    IDcounter = 0;

    while(custin) {

        getline(custin, cust_name[custID], ',');
        if(cust_name[custID] == "")
            break;

        custin.getline(cust_CNIC[IDcounter], 16, ',');

        custin >> cust_IDs[custID]; custin.ignore();

        if(IDcounter < cust_IDs[custID])
            IDcounter = cust_IDs[custID];
        cust_flag[custID] = true;        
        custID++;

    }

    custID = IDcounter;

    custin.close();

    // Moderators

    ifstream moderin("moderators.csv");
    IDcounter = 0;

    while(moderin) {

        getline(moderin, moder_first_name[moderID], ',');

        if(moder_first_name[moderID] == "")   break;

        moder_flag[moderID] = true;
        getline(moderin, moder_last_name[moderID], ',');
        getline(moderin, moder_username[moderID], ',');
        getline(moderin, moder_password[moderID], ',');
        getline(moderin, moder_CNIC[moderID], ',');
        getline(moderin, moder_email[moderID], ',');
        moderin.getline(moder_phone[moderID], 10,',');
        moderin >> moder_salary[moderID];   moderin.ignore();
        moderin >> moder_IDs[moderID];   moderin.ignore();

        if(IDcounter < moder_IDs[moderID])
            IDcounter = moder_IDs[moderID];

        moderID++;
    }

    moderID = IDcounter;

    moderin.close();


    // Products


    ifstream proin("products.csv");
    IDcounter = 0;

    while(proin) {

        if(!(proin >> pro_IDs[productCount]))
            break;

        proin.ignore();

        getline(proin,products[productCount],',');
        
        proin >> pro_cprices[productCount];
        proin.ignore();
        proin >> pro_profit_percent[productCount];
        proin.ignore();
        proin >> pro_stock[productCount];
        proin.ignore();
        proin >> pro_active[productCount];
        proin.ignore();
        proin >> pro_sell[productCount];
        proin.ignore();

        pro_flag[productCount] = true;

        if(pro_IDs[productCount] > IDcounter)
            IDcounter = pro_IDs[productCount];

        productCount++;

    }

    productCount = IDcounter;


    proin.close();

}

//// Store the data stored in arrays to files with comma separated

void storeData(bool pro_flag[],int pro_IDs[],string products[],double pro_cprices[],int pro_profit_percent[],unsigned long int pro_sell[],int pro_stock[],bool pro_active[],int& productCount,int MAX_PRODUCTS,
               bool moder_flag[],string moder_first_name[],string moder_last_name[],string moder_username[],string moder_password[],string moder_CNIC[],string moder_email[],char moder_phone[][10],int moder_salary[],int moder_IDs[],int& moderID,int MAX_MODERATORS,
               bool cust_flag[],string cust_name[],char cust_CNIC[][16],int cust_IDs[],int& custID,int MAX_CUSTOMERS,
               int purchases[],double purchaseBill[],int& purchaseID,
               int item_purchases[][4],int& item_purCount,
               bool review_flag[],int reviewType[],int reviewProID[],int reviewCustID[],string reviews[],int reviewStatus[],int reviewModer[],int reviewRating[],int MAX_REVIEWS,
               string reportSubject[],string reports[],bool report_flag[],int report_status[],int report_moderator[],int MAX_REPORTS) {

    ofstream repout("requests.csv");

    for(int i = 0;i < MAX_REPORTS;i++) {

        if(report_flag[i]) {
            repout << report_moderator[i] << ","
                   << reportSubject[i] << ","
                   << report_status[i] << ","
                   << reports[i] << endl;
        }

    }

    repout.close();


    ofstream revout("reviews.csv");

    for(int i = 0;i < MAX_REVIEWS;i++) {
        if(review_flag[i]) {

            revout << reviewStatus[i] << ","
                   << reviewType[i] << ","
                   << reviewModer[i] << ","
                   << reviewProID[i] << ","
                   << reviewCustID[i] << ","
                   << reviewRating[i] << ","
                   << reviews[i] << endl;
        }
    }

    revout.close();

    // item Purchase

    ofstream itemout("item-purchase.csv");

    for(int i = 0;i < item_purCount; i++) {

        itemout << item_purchases[i][0] << ","
                << item_purchases[i][1] << ","
                << item_purchases[i][2] << ","
                << item_purchases[i][3] << endl;

    }

    itemout.close();

    // Purchases

    ofstream purout("purchases.csv");

    for(int i = 0; i < purchaseID; i++) {
        purout << purchases[i] << ","
               << purchaseBill[i] << endl;
    }

    purout.close();

    // Customers 

    ofstream custout("customers.csv");

    for(int i = 0; i < MAX_CUSTOMERS;i++) {
        if(cust_flag[i]) {
            custout << cust_name[i] << ","
                    << cust_CNIC[i] << ","
                    << cust_IDs[i] << endl;
        }
    }

    custout.close();


    // Moderator

    ofstream moderout("moderators.csv");

    for(int i = 0;i < MAX_MODERATORS;i++) {
        if(moder_flag[i]) {
            moderout << moder_first_name[i] << ","
                    << moder_last_name[i] << ","
                    << moder_username[i] << ","
                    << moder_password[i] << ","
                    << moder_CNIC[i] << ","
                    << moder_email[i] << ","
                    << moder_phone[i] << ","
                    << moder_salary[i] << ","
                    << moder_IDs[i]
                    << endl;            
        }
    }

    moderout.close();

    ofstream prout("products.csv");

    for(int i = 0; i < MAX_PRODUCTS; i++) {
        if(pro_flag[i]) {
            prout << pro_IDs[i] << ","
                  << products[i] << ","
                  << pro_cprices[i] << ","
                  << pro_profit_percent[i] << ","
                  << pro_stock[i] << ","
                  << pro_active[i] << ","
                  << pro_sell[i]
                  << endl;
        }
    }

    prout.close();

}