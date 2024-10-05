#include <stdio.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  FILE *file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error opening file for saving contacts!\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(file, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(file);
    printf("Contacts saved to file successfully!\n");
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("No saved contacts found!\n");
        return;
    }

    char line[150];
    while (fgets(line, sizeof(line), file)) {
        Contact newContact;
        sscanf(line, "%[^,],%[^,],%s", newContact.name, newContact.phone, newContact.email);
        addressBook->contacts[addressBook->contactCount++] = newContact;
    }
    fclose(file);
    printf("Contacts loaded from file successfully!\n");
}
