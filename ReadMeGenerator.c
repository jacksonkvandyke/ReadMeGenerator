#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
    //Ask the user to determine a name for their file
    char fileName[36] = { 0 };
    printf("%s", "Please enter a name for your file, must be under 32 characters(Recommended: README): \n");
    fgets(fileName, 32, stdin);

    //Remove new line character
    for (int i = 0; i < 32; i++){
        if (fileName[i] == 10){
            fileName[i] = 0;

        }

    }
    //Add file extension
    strcat(fileName, ".txt");

    //Open file to write to
    FILE* README;
    README = fopen(fileName, "w+");
    char currentPrompt[10001] = { 0 };
    int inputSize = 1;

    //Ask user for project name
    printf("%s", "\n\nPlease follow the prompts to complete your README file. All inputs will only accept up to 10000 characters. \n\n");
    printf("%s", "Project Name: \n\n");
    fgets(currentPrompt, 10000, stdin);

    //Get total input size
    for (int i = 0; i < 10000; i++){
        if (currentPrompt[i] != 10){
            inputSize += 1;

        }else {
            break;

        }
    }

    //Write project name
    fwrite("Project Name:           ", 1, 24, README);
    fwrite(currentPrompt, 1, inputSize, README);
    fputc('\n', README);

    //Add spacer
    fwrite("____________________________________________________________________________________________________\n", 1, 101, README);

    //Ask user for project description
    printf("%s", "\nProject Description: \n\n");
    memset(currentPrompt, 0, 10000);
    fgets(currentPrompt, 10000, stdin);

    //Get total input size
    inputSize = 1;
    for (int i = 0; i < 10000; i++){
        if (currentPrompt[i] != 10){
            inputSize += 1;

        }else {;
            break;

        }
    }

    //Write project description
    fwrite("Project Description:    ", 1, 24, README);
    int totalPrinted = 0;
    while (totalPrinted < inputSize){
        fputc(currentPrompt[totalPrinted], README);

        //Check if a space is starting the current line
        if (totalPrinted % 50 == 0 && currentPrompt[totalPrinted] == ' ' && totalPrinted >= 50){
            totalPrinted += 1;
            fputc('\n', README);
            fwrite("                        ", 1, 24, README);
            continue;

        }

        //Check if a dash to show to complete a word
        if (currentPrompt[totalPrinted] != ' ' && currentPrompt[totalPrinted - 1] != ' ' && totalPrinted % 50 == 0 && totalPrinted >= 50){
            fputc('-', README);
            fputc('\n', README);
            fwrite("                        ", 1, 24, README);

        }else if (totalPrinted % 50 == 0 && totalPrinted >= 50){
            fputc('\n', README);
            fwrite("                        ", 1, 24, README);

        }

        totalPrinted += 1;

    }
    fputc('\n', README);

    //Add spacer
    fwrite("____________________________________________________________________________________________________\n", 1, 101, README);

    //Ask user for all dependencies
    printf("%s", "\nNumber of Project Dependencies: \n\n");
    int numberofDependencies;
    fgets(currentPrompt, 10000, stdin);
    sscanf(currentPrompt, "%d", &numberofDependencies);
    fwrite("Dependencies:\n\n", 1, 15, README);

    //Loop through for each dependency
    for (int i = 0; i < numberofDependencies; i++){
        //Dependency Name
        printf("%s%d%s", "Dependency Name(", i, "):\n");
        memset(currentPrompt, 0, 10000);
        fgets(currentPrompt, 10000, stdin);
        fwrite("--------------------------------------------------\n", 1, 51, README);
        fwrite("    Dependency Name:        ", 1, 24, README);
        fputs(currentPrompt, README);
        fputs("\n\n", README);

        //Dependency Author
        printf("%s%d%s", "Dependency Author(", i, "):\n");
        memset(currentPrompt, 0, 10000);
        fgets(currentPrompt, 10000, stdin);
        fwrite("    Dependency Author:      ", 1, 24, README);
        fputs(currentPrompt, README);
        fputs("\n\n", README);

        //Dependency Version
        printf("%s%d%s", "Dependency Version(", i, "):\n");
        memset(currentPrompt, 0, 10000);
        fgets(currentPrompt, 10000, stdin);
        fwrite("    Dependency Version:     ", 1, 24, README);
        fputs(currentPrompt, README);
        fputs("\n\n", README);

        //Dependency Date Accessed
        printf("%s%d%s", "Date Accessed(", i, "):\n");
        memset(currentPrompt, 0, 10000);
        fgets(currentPrompt, 10000, stdin);
        fwrite("    Date Accessed:          ", 1, 24, README);
        fputs(currentPrompt, README);
        fputs("\n\n", README);

        //Source Location
        printf("%s%d%s", "Source Location(", i, "):\n");
        memset(currentPrompt, 0, 10000);
        fgets(currentPrompt, 10000, stdin);
        fwrite("    Source Location:        ", 1, 24, README);
        fputs(currentPrompt, README);
        fwrite("--------------------------------------------------\n", 1, 51, README);

    }

    //Close the file
    fclose(README);

    return 0;
}