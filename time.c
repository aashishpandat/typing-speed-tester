#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

int main() {
    const char *sentences[] = {
        "The quick brown fox jumps over the lazy dog.",
        "C programming is powerful and efficient.",
        "Typing fast helps improve productivity.",
        "Practice makes a person perfect.",
        "Data structures are the backbone of software."
    };

    char userInput[200];
    char choice;

    do {
        system(CLEAR);  // [Clear screen]

        srand(time(0));
        int index = rand() % 5;
        const char *selected = sentences[index];

        printf("✍️  TYPE THIS:\n%s\n\n", selected);

        time_t start, end;

        printf("Start typing below:\n");
        time(&start);
        fgets(userInput, sizeof(userInput), stdin);
        time(&end);

        double timeTaken = difftime(end, start);
        printf("\n⏱️  Time Taken: %.2f seconds\n", timeTaken);

        // [Word count]
        int wordCount = 1;
        for (int i = 0; userInput[i] != '\0'; i++) {
            if (userInput[i] == ' ' && userInput[i + 1] != ' ' && userInput[i + 1] != '\n') {
                wordCount++;
            }
        }

        double wpm = (wordCount * 60.0) / timeTaken;

        // [Accuracy calculation]
        int correctChars = 0;
        int totalChars = strlen(selected);
        for (int i = 0; selected[i] != '\0' && userInput[i] != '\0'; i++) {
            if (selected[i] == userInput[i]) {
                correctChars++;
            }
        }

        double accuracy = (correctChars * 100.0) / totalChars;

        printf("🚀 Typing Speed: %.2f WPM\n", wpm);
        printf("🎯 Accuracy: %.2f%%\n", accuracy);

        printf("\n🔁 Do you want to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar();  // consume newline

    } while (choice == 'y' || choice == 'Y');

    printf("\n👋 Thanks for using the Typing Speed Tester!\n");
    return 0;
}
