#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define FILE_NAME "users.txt"

// Define the structure for a User
struct User {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
};

//Create a new user
void createUser() {
    FILE *fp = fopen(FILE_NAME, "a");
   

    struct User newUser;
    printf("Enter ID: ");
    scanf("%d", &newUser.id);
    getchar();
   
    if (newUser.id <= 0) {
        printf("ID must be a positive integer.\n");
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    fgets(newUser.name, MAX_NAME_LENGTH, stdin);
    newUser.name[strcspn(newUser.name, "\n")] = '\0';

    
    printf("Enter Age: ");
    scanf("%d", &newUser.age);

    
    if (newUser.age <= 0) {
        printf("Age must be a positive integer.\n");
        fclose(fp);
        return;
    }
  
     fwrite(&newUser, sizeof(struct User), 1, fp);
    
    printf("User added successfully!\n");
    fclose(fp);
}


// Read and display all the users 
void readUsers() {
    FILE *fp = fopen(FILE_NAME, "r");
   

    struct User user;
    printf("\n--- All Users ---\n");
    while (fread(&user, sizeof(struct User), 1, fp)) {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }

    fclose(fp);
}

// Function to update a user's details based on their ID
void updateUser() {
    FILE *fp = fopen(FILE_NAME, "r+");
    FILE *fp1=fopen("temp.txt", "w");
   

    int idToUpdate;
    printf("Enter the ID of user to update: ");
    scanf("%d", &idToUpdate);

    struct User user;
    int found = 0;

    while (fread(&user, sizeof(struct User), 1, fp)) {
        if (user.id == idToUpdate) {
            found = 1;
           
            getchar(); 
            printf("Enter new Name: ");
            fgets(user.name, MAX_NAME_LENGTH, stdin);
            user.name[strcspn(user.name, "\n")] = '\0';

            printf("Enter new Age: ");
            scanf("%d", &user.age);
            fwrite(&user, sizeof(struct User), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    
    if(found)
    {
        fp1=fopen("temp.txt", "r");
        fp=fopen(FILE_NAME, "w");
        
        while (fread(&user, sizeof(struct User), 1, fp1)) {
            fwrite(&user, sizeof(struct User), 1, fp);
        }

        fclose(fp);
        fclose(fp1);
        remove("temp.txt");
    }
    if (!found) {
        printf("User with ID %d not found!\n", idToUpdate);
    }

    

}

//Delete a user by their ID
void deleteUser() {
    FILE *fp = fopen(FILE_NAME, "r+"); 
  

    FILE *fp1 = fopen("temp.txt", "w");
   

    int idToDelete;
    printf("Enter the ID of the user to delete: ");
    scanf("%d", &idToDelete);

    struct User user;
    int found = 0;

    
    while (fread(&user, sizeof(struct User), 1, fp)) {
        if (user.id == idToDelete) {
            found = 1;
            continue;    //If found it will skip other code
        }
        fwrite(&user, sizeof(struct User), 1, fp1);  // Write to temp file
    }
    fclose(fp);
    fclose(fp1);

    if(found)
    {
        fp1=fopen("temp.txt", "r");
        fp=fopen(FILE_NAME, "w");
        
        while (fread(&user, sizeof(struct User), 1, fp1)) {
            fwrite(&user, sizeof(struct User), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
        remove("temp.txt");
        printf("User deleted successfully!\n");
    }

    else {
        printf("User with ID %d not found!\n", idToDelete);
        remove("temp.txt");
    }
}


//Display the menu
void displayMenu() {

    int choice;

    do {
        printf("\n--- User Management System ---\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.Please try again.\n");
        }
    } while (choice != 0);
}

int main() {
    displayMenu();
    return 0;
}
