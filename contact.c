#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) {
if (addressBook->contactCount == 0) {
    printf("No contacts available!\n");
    return;
    }
    for (int i=0;i<addressBook->contactCount;i++)
    {
        printf("Contact of person %d :\n",i+1);
        printf("Name : %s \n",addressBook->contacts[i].name);
        printf("Phone : %s \n",addressBook->contacts[i].phone);
        printf("E-Mail : %s \n",addressBook->contacts[i].email);

    }
    
}
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    //saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
	if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Address book is full!\n");
        return;
    }

    Contact newContact;
    printf("Enter name: ");
    scanf("%s", newContact.name);
    printf("Enter phone number: ");
    scanf("%s", newContact.phone);
    printf("Enter email: ");
    scanf("%s", newContact.email);

    addressBook->contacts[addressBook->contactCount++] = newContact;
    printf("Contact created successfully!\n");
}
void searchContact(AddressBook *addressBook) 
{
    char searchName[50];
    printf("Enter the name of the contact to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, searchName) == 0) 
        {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            return;
        }
    }
    printf("Contact not found!\n");
}


void editContact(AddressBook *addressBook)
{
    char searchName[50];
    printf("Enter the name of the contact to edit: ");
    scanf("%s", searchName);

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, searchName) == 0) {
            printf("Editing contact:\n");
            printf("Enter new name: ");
            scanf("%s", addressBook->contacts[i].name);
            printf("Enter new phone number: ");
            scanf("%s", addressBook->contacts[i].phone);
            printf("Enter new email: ");
            scanf("%s", addressBook->contacts[i].email);
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
  
}

void deleteContact(AddressBook *addressBook)
{
   char searchName[50];
    printf("Enter the name of the contact to delete: ");
    scanf("%s", searchName);

    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].name, searchName) == 0) {
            for (int j = i; j < addressBook->contactCount - 1; j++) {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
            }
            addressBook->contactCount--;
            printf("Contact deleted successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}
