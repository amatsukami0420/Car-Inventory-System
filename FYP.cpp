#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Date {
    int day;
    int month;
    int year;
};
struct MaintenanceRecord {
    struct Date serviceDate;
    char description[200];
    float cost;
};
struct ImportDetails {
    int isImported;
    char importCountry[30];
    int importYear;
    char auctionSheetGrade[5];
    int isAuctionSheetVerifiable;
};
struct Car {

    int vehicleID;
    char make[30];
    char model[30];
    int modelYear;
    char registrationCity[30];
    char color[20];
    char engineNumber[30];
    char chassisNumber[30];
    int engineCC;
    char transmissionType[10];
    int mileage_km;


    char bodyConditionNotes[250];
    int isAccidental;
    struct ImportDetails importInfo;
    struct MaintenanceRecord maintenanceHistory[10];
    int maintenanceRecordCount;

    struct Date dateAcquired;
    float purchasePrice;
    float totalRepairCosts;
    int isSold;
    struct Date dateSold;
    float salePrice;
    char buyerName[100];
    float profitOrLoss;
};

int admin_perms=0;
int carCount = 10;
float current_assets=0.0;
float cash_in_bank = 10000000.0; 

Car inventory[20] = {
    {
        1001, "Toyota", "Corolla GLi", 2018, "Lahore", "White", "1NZFE1234567", "JT1BA67J70N12345", 1300, "Manual", 65000,
        "Minor scratches on rear bumper. Original paint.", 0,
        {0, "N/A", 0, "N/A", 0},
        {
            {{10, 5, 2024}, "Oil change, air filter replacement", 3500.00},
            {{20, 1, 2025}, "Wheel balancing and alignment", 2000.00}
        },
        2,
        {1, 6, 2024}, 2800000.00, 5500.00,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1002, "Honda", "Civic Oriel", 2020, "Islamabad", "Black", "R18A12345678", "MRHFC27G50012345", 1800, "Auto", 42000,
        "Clean interior. One fender repainted (minor touchup).", 0,
        {0, "N/A", 0, "N/A", 0},
        {},
        0,
        {15, 7, 2024}, 4500000.00, 0.0,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1003, "Suzuki", "Alto VXR", 2022, "Karachi", "Silver", "R06A12345678", "MMGCL12G60012345", 660, "Manual", 18000,
        "Excellent condition. First owner.", 0,
        {0, "N/A", 0, "N/A", 0},
        {},
        0,
        {5, 9, 2024}, 1950000.00, 0.0,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1004, "Toyota", "Aqua", 2016, "Rawalpindi", "Blue", "1NZFXE123456", "NHP101234567", 1500, "Auto", 85000,
        "Fresh import. Minor scratches on left door, original condition.", 0,
        {1, "Japan", 2023, "4B", 1},
        {
            {{1, 10, 2024}, "Hybrid battery checkup", 7000.00}
        },
        1,
        {20, 9, 2024}, 3300000.00, 7000.00,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1005, "Daihatsu", "Mira", 2018, "Faisalabad", "White", "KFVE1234567", "LA350S1234567", 660, "Auto", 35000,
        "Very neat car. Minor paint touch-up on front bumper.", 0,
        {1, "Japan", 2024, "3.5C", 1},
        {},
        0,
        {10, 11, 2024}, 2350000.00, 0.0,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1006, "Suzuki", "Cultus VXL", 2019, "Peshawar", "Grey", "K10B12345678", "MMGPL12S70012345", 1000, "Manual", 50000,
        "Bonnet repainted due to stone chips. Otherwise good.", 0,
        {0, "N/A", 0, "N/A", 0},
        {
            {{1, 12, 2024}, "General service, spark plugs changed", 4000.00}
        },
        1,
        {1, 12, 2024}, 2400000.00, 4000.00,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1007, "Toyota", "Vitz", 2014, "Lahore", "Silver", "1NRFE1234567", "NCP131234567", 1000, "Auto", 95000,
        "Front right fender replaced, minor front damage repaired.", 1,
        {1, "Japan", 2023, "R", 0},
        {
            {{10, 10, 2024}, "Body work and paint", 50000.00},
            {{15, 11, 2024}, "Suspension check", 6000.00}
        },
        2,
        {1, 10, 2024}, 2500000.00, 56000.00,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1008, "Honda", "City Aspire", 2017, "Islamabad", "White", "L15A12345678", "MRHGF28C60012345", 1500, "Auto", 70000,
        "Original condition, well maintained.", 0,
        {0, "N/A", 0, "N/A", 0},
        {
            {{25, 12, 2024}, "Transmission fluid change", 8000.00}
        },
        1,
        {10, 12, 2024}, 3000000.00, 8000.00,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1009, "Suzuki", "Wagon R VXL", 2021, "Lahore", "Blue", "K10B12345678", "MMGBL12S80012345", 1000, "Manual", 28000,
        "Minor dents on left side. Original paint.", 0,
        {0, "N/A", 0, "N/A", 0},
        {},
        0,
        {5, 1, 2025}, 2200000.00, 0.0,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    },
    {
        1010, "Toyota", "Corolla Axio", 2015, "Karachi", "Pearl White", "1NZFE1234567", "NKE1651234567", 1500, "Auto", 110000,
        "Used with care. Minor scratches.", 0,
        {1, "Japan", 2023, "3.5B", 1},
        {
            {{10, 1, 2024}, "Engine tuning and general checkup", 7500.00},
            {{20, 2, 2024}, "Brake service", 3000.00}
        },
        2,
        {1, 1, 2024}, 3000000.00, 10500.00,
        0, {0, 0, 0}, 0.0, "N/A", 0.0
    }
};

void asciilogo();
void displayMenu();
void accessdenied();
int adminLogin();
void adminLogout();
void displayAvailableCars();
void displaySoldCars();
int FindIndex(int);
void searchCar();
void lowercase(char []);
void viewCarDetails();
void sortCarsMenu();
void sellCar();
void viewSalesReport();
void displayMostProfitableSale();
void displayLeastProfitableSale();
void addNewCar();
void decideID(int );
void addMaintenanceRecord();
void updateCarInfo();
void calculateAssets();
void displayFinancialReport();
void removeCar();
void deleteInventory();

int main() {
    int choice=-1;
    while (choice != 0){
    	system("cls");
        displayMenu();
        printf("\033[0mEnter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        system("cls");

        switch (choice) {
            case 1: displayAvailableCars(); break;
            case 2: displaySoldCars(); break;
            case 3: searchCar(); break;
            case 4: viewCarDetails(); break;
            case 5: sortCarsMenu(); break;
            case 6: sellCar(); break;
            case 7: viewSalesReport(); break;
            case 8: displayMostProfitableSale(); break;
			case 9: displayLeastProfitableSale(); break;
            case 10:
                if (admin_perms) addNewCar();
                else accessdenied();
                break;
            case 11:
                if (admin_perms) addMaintenanceRecord();
                else accessdenied();
                break;
            case 12:
                if (admin_perms) updateCarInfo();
                else accessdenied();
                break;
            case 13:
                if (admin_perms) displayFinancialReport();
                else accessdenied();
                break;
            case 14:
                if (admin_perms) removeCar();
                else accessdenied();
                break;
            case 15:
				if (admin_perms) deleteInventory();
                else accessdenied();
                break;
            case 16:
                if (!admin_perms) {
                    admin_perms = adminLogin();
                } else {
                    adminLogout();
                    admin_perms = 0;
                }
                break;
            case 0:
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (choice != 0) {
            printf("\nPress Enter to continue>>>");
            getchar();
            fflush(stdin);
        }

    }
    return 0;
}
void asciilogo(){
	printf(" \033[91m\n ____ ____ ____ _________ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____");
	printf(" \033[91m\n||C |||a |||r |||       |||D |||e |||a |||l |||e |||r |||s |||h |||i |||p ||");
	printf(" \033[91m\n||__|||__|||__|||_______|||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||");
	printf(" \033[91m\n|/__\\|/__\\|/__\\|/_______\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|/__\\|");
}
void displayMenu() {
    asciilogo();
    printf("\n\033[34m1. Display Available Cars\n");
    printf("2. Display Sold Cars\n");
    printf("3. Search for a Car\n");
    printf("4. View Full Details of a Car\n");
    printf("5. Sort Available Cars\n");
    printf("6. Sell a Car\n");
    printf("7. View Sales Report\n");
    printf("8. View Most Profitable Sale\n");
    printf("9. View Least Profitable Sale\n");
    if (admin_perms) {
        printf("\033[32m10. Add New Car to Inventory\n");
        printf("11. Add Maintenance Record\n");
        printf("12. Update Car Information\n");
        printf("13. View Financial Report\n");
        printf("14. Remove Car from Inventory\n");
        printf("15. Delete Inventory\n");
        printf("16. Admin Logout\n");
    } else {
    	printf("\033[31m==x== Admin Access Required ==x==\n");
        printf("\033[34m16. Admin Login\n");
    }
    printf("0. Exit\n");
    printf("------------------------------\n");
}
void accessdenied(){
	printf("Access Denied: Please log in as Admin to update car information.\n");
}
int adminLogin() {
    char username[50]; 
    char password[50]; 

    printf("\n--- Admin Login ---\n");
    printf("Enter Username: ");
    gets(username);
    printf("Enter Password: ");
    gets(password);
    if (strcmp(username, "Waleed") == 0 && strcmp(password, "waleed110") == 0) {
        printf("Login successful! Welcome, Admin.\n");
        return 1;
    } else {
        printf("Invalid username or password. Access denied.\n");
        return 0;
    }
}
void adminLogout(){
	printf("\nAdmin logged out successfully.\n");
}
void displayAvailableCars(){
	printf("\n=== All Available Cars in Inventory ===\n");
    int available_count = 0;
    printf("%-10s %-15s %-15s %-10s %-15s %-12s\n",
           "ID", "Make", "Model", "Year", "Reg. City", "Price (PKR)");
    printf("---------------------------------------------------------------------------------\n");
    for(int i=0;i<carCount; i++){
    	if(!inventory[i].isSold){
    	printf("%-10d %-15s %-15s %-10d %-15s %-12.2f\n",
           inventory[i].vehicleID,
		   inventory[i].make, 
		   inventory[i].model, 
		   inventory[i].modelYear, 
		   inventory[i].registrationCity, 
		   inventory[i].purchasePrice);
		   available_count++;
		}
	}
	if(available_count==0){
		printf("No Available Cars in inventory.\n");
	} 
}
void displaySoldCars(){
	printf("\n===== All Sold Cars in Inventory =====\n");
    int sold_count = 0;
    printf("%-10s %-15s %-15s %-10s %-15s %-12s\n",
           "ID", "Make", "Model", "Year", "Buyer", "Sale Price (PKR)");
    printf("--------------------------------------------------------------------------------------\n");
    for(int i=0;i<carCount; i++){
    	if(inventory[i].isSold){
    	printf("%-10d %-15s %-15s %-10d %-15s %-12.2f\n",
           inventory[i].vehicleID,
		   inventory[i].make, 
		   inventory[i].model, 
		   inventory[i].modelYear, 
		   inventory[i].buyerName, 
		   inventory[i].salePrice);
		   sold_count++;
		}
	}
	if(sold_count==0){
		printf("No Cars Sold yet.\n");
	}
}
int FindIndex(int id){
	int index=-1;
	for(int i=0; i<carCount; i++){
		if(id==inventory[i].vehicleID){
			index=i;
			break;
		}
	}
	return index;
}
void lowercase(char a[]){
	int i=0;
	while(a[i]!='\0'){
		if(a[i]>='A'&&a[i]<='Z'){
			a[i]+=32;
		}
		i++;
	}
}
void searchCar(){
	printf("Search Cars: \n");
	printf("1. Search by VehicleID\n2. Search by Make/Model\nEnter Your Choice: ");
	int choice;
	scanf("%d", &choice);
	fflush(stdin);
	switch(choice){
		case 1:
			{
			int idtofind;
			printf("Enter Vehicle ID to search: ");
			scanf("%d", &idtofind);
			fflush(stdin);
			int found=FindIndex(idtofind);
			if(found!=-1){
				printf("\n%-10s %-15s %-15s %-10s %-15s %-12s\n",
				"ID", "Make", "Model", "Year", "Reg. City", "Price (PKR)");
				printf("---------------------------------------------------------------------------------\n");
				printf("%-10d %-15s %-15s %-10d %-15s %-12.2f\n",
				inventory[found].vehicleID,
				inventory[found].make, 
				inventory[found].model,
				inventory[found].modelYear, 
				inventory[found].registrationCity, 
				inventory[found].purchasePrice);
				printf("\nUse 'Option 4' to View Full Details of this Car\n");
			}
			else{
				printf("Car with ID %d not found\n", idtofind);
			}
			break;
			}
		case 2:
			{
			char ModelSearch[50];
			char MakeSearch[50];
			int foundcars=0;
			printf("\nEnter Make(or leave empty for any): ");
			gets(MakeSearch);
			fflush(stdin);
			printf("\nEnter Model(or leave empty for any): ");
			gets(ModelSearch);
			fflush(stdin);
			system("cls");
			lowercase(MakeSearch);
			lowercase(ModelSearch);
			printf("\n=== Search Results ===\n");
			printf("\n%-10s %-15s %-15s %-10s %-15s %-12s\n",
				"ID", "Make", "Model", "Year", "Reg. City", "Status");
				printf("---------------------------------------------------------------------------------\n");
			for(int i=0; i<carCount; i++){
				char LowerMake[50];
				char LowerModel[50];
				strcpy(LowerMake, inventory[i].make);
				strcpy(LowerModel, inventory[i].model);
				lowercase(LowerMake);
				lowercase(LowerModel);
				int foundmake=(strlen(MakeSearch)==0||strcmp(LowerMake, MakeSearch)==0);
				int foundmodel=(strlen(ModelSearch)==0||strcmp(LowerModel, ModelSearch)==0);

				if(foundmake&&foundmodel){
					printf("%-10d %-15s %-15s %-10d %-15s %-12s\n",
					inventory[i].vehicleID,
					inventory[i].make, 
					inventory[i].model,
					inventory[i].modelYear, 
					inventory[i].registrationCity, 
					(inventory[i].isSold)? "Sold":"Available");
					foundcars++;
				}
			}
			
			if(foundcars==0){
				printf("No Cars Match the Search Criteria");
			}
			else{
				printf("Found %d Car(s) Matching the Search Criteria\n", foundcars);
				printf("Choose 'Option 4' to View Full Details of the Car you want\n");
			}
			break;
			}
		default:
			printf("Invalid Choice");
			break;
	}
}
void viewCarDetails(){
	int searchID;
	printf("Enter The Vehicle ID for the car you want to search: ");
	scanf("%d", &searchID);
	fflush(stdin);
	int f=FindIndex(searchID);
	if(f!=-1){
		printf("Car Found, Full Details Below: \n");
		printf("ID: %d\n", inventory[f].vehicleID);
		printf("Make: %s\n", inventory[f].make);
		printf("Model: %s\n", inventory[f].model);
		printf("Model Year: %d\n", inventory[f].modelYear);
		printf("Registration City: %s\n", inventory[f].registrationCity);
		printf("Colour: %s\n", inventory[f].color);
		printf("Engine Number: %s\n",inventory[f].engineNumber);
		printf("Chassis Number: %s\n", inventory[f].chassisNumber);
		printf("Engine CC: %d\n", inventory[f].engineCC);
		printf("Transmission: %s\n", inventory[f].transmissionType);
		printf("Mileage (km): %d\n", inventory[f].mileage_km);
		
		printf("\npress ENTER to go to next page>>>");
		getchar();
		system("cls");
		
		printf("Body Condition Notes: \n %s \n", inventory[f].bodyConditionNotes);
		printf("Accidental?: %s\n", inventory[f].isAccidental? "Yes":"No");
		if(inventory[f].importInfo.isImported){
			printf("Import Details: \n");
			printf("Import Country: %s\n", inventory[f].importInfo.importCountry);
			printf("Import Year: %d\n", inventory[f].importInfo.importYear);
			printf("Auction Sheet Grade: %s\n", inventory[f].importInfo.auctionSheetGrade);
			printf("Is Auction Sheet Verifiable?: %s\n", inventory[f].importInfo.isAuctionSheetVerifiable? "Yes":"No");
		}
		else{
			printf("Car is Not Imported\n");
		}
		
		printf("\npress ENTER to go to next page>>>");
		getchar();
		system("cls");
		
		printf("\nFound %d Maintenance Record(s): \n", inventory[f].maintenanceRecordCount);
		if(!inventory[f].maintenanceRecordCount==0){
			for(int i=0;i<inventory[f].maintenanceRecordCount;i++){
				printf("\nRecord %d\n", i+1);
				printf("Maintenance Date: %d %d %d\n", inventory[f].maintenanceHistory[i].serviceDate.day,
				inventory[f].maintenanceHistory[i].serviceDate.month, inventory[f].maintenanceHistory[i].serviceDate.year);
				printf("Description: \n%s\n", inventory[f].maintenanceHistory[i].description);
    			printf("Cost: %.2f\n", inventory[f].maintenanceHistory[i].cost);
			}
		}
	
		printf("\npress ENTER to go to next page>>>");
		getchar();
		system("cls");
		
		printf("Date Acquired: %d %d %d\n", inventory[f].dateAcquired.day, inventory[f].dateAcquired.month,
		inventory[f].dateAcquired.year);
		printf("Purchase Price: %.2f\n", inventory[f].purchasePrice);
		printf("Total Repair Cost: %.2f\n", inventory[f].totalRepairCosts);
		printf("Status: %s\n", inventory[f].isSold?"Sold":"Available");
		if(inventory[f].isSold){
			printf("Date Sold: %d %d %d\n", inventory[f].dateSold.day, inventory[f].dateSold.month,
			inventory[f].dateSold.year);
			printf("Sale Price: %.2f\n", inventory[f].salePrice);
    		printf("Buyer Name: %s\n", inventory[f].buyerName);
    		printf("Profit/Loss: %.2f\n", inventory[f].profitOrLoss);
		}
	}
}
void sortCarsMenu(){
	printf("Sort By: \n1. Purchase Price \n2. Make \n3. ID \n4. Model Year \n Choice: ");
	int choice;
	scanf("%d", &choice);
	fflush(stdin);
	switch(choice){
		case 1:
			for(int i=0;i<carCount-1;i++){
				for(int j=0;j<carCount-i-1;j++){
					if(inventory[j].purchasePrice<inventory[j+1].purchasePrice){
						Car temp=inventory[j];
						inventory[j]=inventory[j+1];
						inventory[j+1]=temp;
					}
				}
			}
			displayAvailableCars();
			break;
		case 2:
			for(int i=0;i<carCount-1;i++){
				for(int j=0;j<carCount-i-1;j++){
					if(strcmp(inventory[j].make, inventory[j+1].make)>0){
						Car temp=inventory[j];
						inventory[j]=inventory[j+1];
						inventory[j+1]=temp;
					}
				}
			}
			displayAvailableCars();
			break;
		case 3:
			for(int i=0;i<carCount-1;i++){
				for(int j=0;j<carCount-i-1;j++){
					if(inventory[j].vehicleID>inventory[j+1].vehicleID){
						Car temp=inventory[j];
						inventory[j]=inventory[j+1];
						inventory[j+1]=temp;
					}
				}
			}
			displayAvailableCars();
			break;
		case 4:
			for(int i=0;i<carCount-1;i++){
				for(int j=0;j<carCount-i-1;j++){
					if(inventory[j].modelYear>inventory[j+1].modelYear){
						Car temp=inventory[j];
						inventory[j]=inventory[j+1];
						inventory[j+1]=temp;
					}
				}
			}
			displayAvailableCars();
			break;
		default:
			printf("Invalid Choice!\n");
			break;
	}
}
void sellCar(){
	printf("==== Sell Car ====\n");
	printf("Enter The ID of the car you want to sell: ");
	int sellID;
	scanf("%d", &sellID);
	fflush(stdin);
	int index=FindIndex(sellID);
	if(index==-1){
		printf("\nCar with ID %d not found.\n", sellID);
	}
	else{
		if(inventory[index].isSold){
			printf("\nCar is Already Sold!\n");
		}
		else{
			printf("Sale Date(DD MM YYYY): ");
			scanf("%d %d %d", &inventory[index].dateSold.day, &inventory[index].dateSold.day, 
			&inventory[index].dateSold.day);
			fflush(stdin);
			printf("Enter Sale Price: ");
			scanf("%f", &inventory[index].salePrice);
			fflush(stdin);
			printf("Enter Buyer Name: ");
			gets(inventory[index].buyerName);
			inventory[index].isSold=1;
			inventory[index].profitOrLoss=inventory[index].salePrice-(inventory[index].purchasePrice+inventory[index].totalRepairCosts);
			printf("Profit/Loss = %.2f\n", inventory[index].profitOrLoss);
			cash_in_bank+=inventory[index].salePrice;
			printf("Cash in Bank: %.2f\n", cash_in_bank);
		}
	}
}
void viewSalesReport(){
	int soldcars=0;
	float salesrev=0;
	float netprof_loss=0;
	for(int i=0;i<carCount;i++){
		if(inventory[i].isSold){
			soldcars++;
			salesrev+=inventory[i].salePrice;
			netprof_loss+=inventory[i].profitOrLoss;
		}
	}
	printf("=== Summary ===\n");
	printf("Cars Sold: %d\n", soldcars);
	printf("Sales Revenue: %.2f\n", salesrev);
	printf("Net Profit/Loss: %.2f\n", netprof_loss);
}
void displayMostProfitableSale(){
	int i=0;
	int index=-1;
	float highest;
	int first=1;
	for(;i<carCount;i++){
		if(inventory[i].isSold){
			if(first){
				highest=inventory[i].profitOrLoss;
				index=i;
			}
			else{
				if(highest<inventory[i].profitOrLoss){
					highest=inventory[i].profitOrLoss;
					index=i;
				}
			}
		}
		first=0;
	}
	if(index!=-1){
		printf("==== Highest Profit From ====\n");
		printf("%-10s %-15s %-15s %-10s %-15s %-12s\n",
		"ID", "Make", "Model", "Year", "Buyer", "Profit (PKR)");
		printf("--------------------------------------------------------------------------------------\n");
		printf("%-10d %-15s %-15s %-10d %-15s %-12.2f\n",
		inventory[index].vehicleID,
		inventory[index].make, 
		inventory[index].model, 
		inventory[index].modelYear, 
		inventory[index].buyerName, 
		inventory[index].profitOrLoss);
	}
	else{
		printf("No Car Sold Yet");
	}
}
void displayLeastProfitableSale(){
	int i=0;
	int index=-1;
	float lowest=inventory[i].profitOrLoss;
	int first=1;
	for(;i<carCount;i++){
		if(inventory[i].isSold){
			if(first){
				lowest=inventory[i].profitOrLoss;
				index=i;
			}
			else{
				if(lowest>inventory[i].profitOrLoss){
					lowest=inventory[i].profitOrLoss;
					index=i;
				}
			}
		}
		first=0;
	}
	if(index!=-1){
		printf("==== Least Profit From ====\n");
		printf("%-10s %-15s %-15s %-10s %-15s %-12s\n",
		"ID", "Make", "Model", "Year", "Buyer", "Profit (PKR)");
		printf("--------------------------------------------------------------------------------------\n");
		printf("%-10d %-15s %-15s %-10d %-15s %-12.2f\n",
		inventory[index].vehicleID,
		inventory[index].make, 
		inventory[index].model, 
		inventory[index].modelYear, 
		inventory[index].buyerName, 
		inventory[index].profitOrLoss);
	}
	else{
		printf("No Car Sold Yet");
	}
}
void decideID(int index){
	int temp=0;
	for(int i=0;i<carCount;i++){
		temp=(temp>inventory[i].vehicleID)?temp:inventory[i].vehicleID;
	}
	inventory[index].vehicleID=temp+1;
}
void addNewCar(){
	if(carCount<20){
	int f=carCount;
	decideID(f);
	printf("ID: %d\n", inventory[f].vehicleID);
	printf("Make: ");
	gets(inventory[f].make);
	fflush(stdin);
	printf("Model: ");
	gets(inventory[f].model);
	fflush(stdin);
	printf("Model Year(YYYY): ");
	scanf("%d", &inventory[f].modelYear);
	fflush(stdin);
	printf("Registration City: ");
	gets(inventory[f].registrationCity);
	fflush(stdin);
	printf("Colour: ");
	gets(inventory[f].color);
	fflush(stdin);
	printf("Engine Number: ");
	gets(inventory[f].engineNumber);
	fflush(stdin);
	printf("Chassis Number: ");
	gets(inventory[f].chassisNumber);
	fflush(stdin);
	printf("Engine CC: ");
	scanf("%d", &inventory[f].engineCC);
	fflush(stdin);
	printf("Transmission Type (Auto/Manual): ");
	gets(inventory[f].transmissionType);
	fflush(stdin);
	printf("Mileage (km): ");
	scanf("%d", &inventory[f].mileage_km);
	fflush(stdin);
	printf("Body Condition Notes: \n");
	gets(inventory[f].bodyConditionNotes);
	fflush(stdin);
	printf("Is it Accidental?(1/0 for Yes/No): ");
	scanf("%d", &inventory[f].isAccidental);
	fflush(stdin);
	printf("\nIs it Imported(1/0 for Yes/No): ");
	scanf("%d", &inventory[f].importInfo.isImported);
	fflush(stdin);
	if(inventory[f].importInfo.isImported){
		printf("Import Country: ");
		gets(inventory[f].importInfo.importCountry);
		fflush(stdin);
		printf("Import Year: ");
		scanf("%d", &inventory[f].importInfo.importYear);
		fflush(stdin);
		printf("Auction Sheet Grade: ");
		gets(inventory[f].importInfo.auctionSheetGrade);
		fflush(stdin);
		printf("Is Auction Sheet Verifiable?(1/0 for Yes/No): ");
		scanf("%d", &inventory[f].importInfo.isAuctionSheetVerifiable);
		fflush(stdin);
	}
	printf("Date Acquired(DD MM YYYY): ");
	scanf("%d %d %d", &inventory[f].dateAcquired.day, &inventory[f].dateAcquired.month,
	&inventory[f].dateAcquired.year);
	fflush(stdin);
	printf("Purchase Price: ");
	scanf("%f", &inventory[f].purchasePrice);
	fflush(stdin);
	cash_in_bank-=inventory[f].purchasePrice;
	printf("\nCar Added To Inventory.");
	printf("\nCash in Bank Updated: %.2f\n", cash_in_bank);
	carCount++;
	inventory[f].maintenanceRecordCount=0;
	inventory[f].isSold=0;
	inventory[f].profitOrLoss=0;
	inventory[f].totalRepairCosts=0;
	}
	else{
		printf("No More Space For New Cars");
	}
}
void addMaintenanceRecord(){
	printf("Enter the VehicleID: ");
	int search;
	scanf("%d", &search);
	fflush(stdin);
	int id=FindIndex(search);
	if(id!=-1){
		int i=inventory[id].maintenanceRecordCount;
		printf("\nRecord %d\n", i+1);
		printf("Maintenance Date(DD MM YYYY): ");
		scanf("%d %d %d", &inventory[id].maintenanceHistory[i].serviceDate.day,
		&inventory[id].maintenanceHistory[i].serviceDate.month, &inventory[id].maintenanceHistory[i].serviceDate.year);
		printf("Description: ");
		fflush(stdin);
		gets(inventory[id].maintenanceHistory[i].description);
		fflush(stdin);
    	printf("Cost: ");
    	scanf("%f", &inventory[id].maintenanceHistory[i].cost);
    	fflush(stdin);
    	inventory[id].maintenanceRecordCount++;
    	inventory[id].totalRepairCosts+=inventory[id].maintenanceHistory[i].cost;
    	
	}
	else{
		printf("Car with ID %d not found", search);
	}
}
void updateCarInfo(){
	printf("Enter vehicleID to Update: ");
	int srch;
	scanf("%d", &srch);
	fflush(stdin);
	int i=FindIndex(srch);
	if(i!=-1){
		printf("What do you want to Update: \n");
		printf("1. Mileage\n2. Body Condition Notes\n3. Colour\n4. Transmission Type\nEnter Choice: ");
		int choice;
		scanf("%d", &choice);
		fflush(stdin);
		switch(choice){
			case 1:
				printf("New Mileage (km): ");
				scanf("%d", &inventory[i].mileage_km);
				fflush(stdin);
				break;
			case 2:
				printf("Body Condition Notes: \n");
				gets(inventory[i].bodyConditionNotes);
				fflush(stdin);
				break;
			case 3:
				printf("Colour: ");
				gets(inventory[i].color);
				fflush(stdin);
				break;
			case 4:
				printf("Transmission Type (Auto/Manual): ");
				gets(inventory[i].transmissionType);
				fflush(stdin);
				break;
			default:
				printf("Invalid Choice");
				break;
		}
	}
	else{
		printf("Car With ID %d Not Found\n");
	}
}
void calculateAssets(){
	for(int i=0; i<carCount;i++){
		if(!inventory[i].isSold){
			current_assets+=inventory[i].purchasePrice;
		}
	}
}
void displayFinancialReport(){
	printf("\n========== Overall Financial Report ==========\n");
    calculateAssets();
    int soldCarCount = 0;
    float totalSalesRevenue = 0.0f;
    float netProfitLoss = 0.0f;
    for (int i = 0; i < carCount; i++) {
        if (inventory[i].isSold) {
            totalSalesRevenue += inventory[i].salePrice;
            netProfitLoss += inventory[i].profitOrLoss;
            soldCarCount++;
        }
    }

    printf("Assets:\n");
    printf("  - Cash in Bank:               %.2f PKR\n", cash_in_bank);
    printf("  - Value of Current Inventory: %.2f PKR\n", current_assets);
    printf("  - Total Current Assets:       %.2f PKR\n", cash_in_bank + current_assets);
    
    printf("\nSales Summary:\n");
    printf("  - Total Cars Sold:            %d\n", soldCarCount);
    printf("  - Total Sales Revenue:        %.2f PKR\n", totalSalesRevenue);
    printf("  - Net Profit/Loss from Sales: %.2f PKR\n", netProfitLoss);
    printf("==============================================\n");
}
void removeCar(){
	printf("Enter The vehicleID of the Car You Want to Remove: ");
	int rid;
	scanf("%d", &rid);
	fflush(stdin);
	int rin=FindIndex(rid);
	if(rin!=-1){
		printf("This Car Will Be Removed: \n");
		printf("%-10d %-15s %-15s %-10d\n", inventory[rin].vehicleID, 
		inventory[rin].make, inventory[rin].model, inventory[rin].modelYear);
		carCount--;
		for(int i=rin;i<carCount;i++){
			inventory[i]=inventory[i+1];
		}
		printf("Car Removed From Inventory Successfully\n");
	}
	else{
		printf("Car with ID %d not Found\n", rid);
	}
}
void deleteInventory(){
	printf("Are You Sure You want To Delete Inventory?(1/0 for Yes/No): ");
	int confirm;
	scanf("%d", &confirm);
	fflush(stdin);
	if(confirm){
		carCount=0;
		printf("Inventory Deleted!");
	}
	else{
		printf("Avoided That!");
	}
}