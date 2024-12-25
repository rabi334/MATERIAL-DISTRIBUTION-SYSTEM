#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

// Define a struct to represent course materials
struct CourseMaterial {
    std::string title;
    std::string author;
    std::string description;
};

// Function to add a new material
void addMaterial(std::vector<CourseMaterial>& materials) {
    CourseMaterial newMaterial;
    std::cout << "Enter material title: ";
    std::cin.ignore(); // Clear newline from previous input
    std::getline(std::cin, newMaterial.title);
    std::cout << "Enter author: ";
    std::getline(std::cin, newMaterial.author);
    std::cout << "Enter description: ";
    std::getline(std::cin, newMaterial.description);
    materials.push_back(newMaterial);
}

// Function to delete a material
void deleteMaterial(std::vector<CourseMaterial>& materials) {
    std::string titleToDelete;
    std::cout << "Enter the title of the material to delete: ";
    std::cin.ignore(); // Clear newline from previous input
    std::getline(std::cin, titleToDelete);

    // Search for the material by title
    for (size_t i = 0; i < materials.size(); ++i) {
        if (materials[i].title == titleToDelete) {
            materials.erase(materials.begin() + i); // Remove the material
            std::cout << "Material '" << titleToDelete << "' deleted.\n";
            return; // Exit the function
        }
    }

    std::cout << "Material not found.\n";
}


// Function to display all materials
void displayMaterials(const std::vector<CourseMaterial>& materials) {
    std::cout << "\nCourse Materials:\n";
    std::cout << std::left << std::setw(20) << "Title"
              << std::setw(20) << "Author"
              << "Description\n";
    std::cout << std::string(60, '-') << "\n";

    for (size_t i = 0; i < materials.size(); ++i) {
        const CourseMaterial& material = materials[i];
        std::cout << std::setw(20) << material.title
                  << std::setw(20) << material.author
                  << material.description << "\n";
    }
}


// Function to save materials to a file
void saveToFile(const std::vector<CourseMaterial>& materials) {
    std::ofstream outFile("materials.txt");
    if (outFile.is_open()) {
        for (size_t i = 0; i < materials.size(); ++i) {
            const CourseMaterial& material = materials[i];
            outFile << material.title << "," << material.author << ","
                    << material.description << "\n";
        }
        outFile.close();
        std::cout << "Materials saved to 'materials.txt'.\n";
    } else {
        std::cerr << "Error opening file for writing.\n";
    }
}

int main() {
    std::vector<CourseMaterial> materials;
    std::cout<<"*******************************************************\n";
    std::cout<<"* WELCOME TO ASTU COURSE MATERIAL DISTRIBUTION SYSTEM *\n";
    std::cout<<"*******************************************************\n";
    while (true) {
        std::cout << "\nWhat do you want to do?:\n\n";
        std::cout << "	1. Add Material\n";
        std::cout << "	2. Display Materials\n";
        std::cout << "	3. Save to File\n";
        std::cout << "	4. Delete Material\n";
        std::cout << "	5. Exit\n\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMaterial(materials);
                break;
            case 2:
                displayMaterials(materials);
                break;
            case 3:
                saveToFile(materials);
                break;
            case 4:
                deleteMaterial(materials);
                return 0;
            case 5:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;    
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

