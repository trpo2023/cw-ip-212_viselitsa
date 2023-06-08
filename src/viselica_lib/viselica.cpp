#include <viselica_lib/viselica.h>

using namespace std;

void sortWord(char word[], int count)
{
    char t;
    for (int i = 1; i < count; i++) {
        t = word[i];
        int j = i - 1;
        while (j >= 0 and t < word[j]) {
            word[j + 1] = word[j];
            j -= 1;
        }
        word[j + 1] = t;
    }
}

void countLetters(char word[], int count, char latters[], int latters_count[])
{
    for (int i = 0; i < count; i++) {
        latters[i] = word[i];
    }

    int j = 1;
    for (int i = 0; i < count - 1; i++) {
        if (word[i] != word[i + 1]) {
            latters[j] = word[i + 1];
            j++;
        }
    }
    latters[j] = '\0';

    j = 0;
    while (latters[j] != '\0') {
        for (int i = 0; i < count; i++) {
            if (latters[j] == word[i]) {
                latters_count[j]++;
            }
        }
        j++;
    }
}

void playHangman(char word[], int count, char latters[], int latters_count[])
{
    char answer[50];
    memset(answer, '_', count);
    answer[count] = '\0';

    char latters_for_answer[27] = "abcdefghijklmnopqrstuvwxyz";

    int count_of_close = count;
    int misstakes = 0;

    while ((count_of_close > 0) && (misstakes != 7)) {
        cout << answer << endl;
        cout << latters_for_answer << endl;
        cout << "Please, choose a letter: ";

        char t;
        cin >> t;

        for (int p = 0; p < 26; p++) {
            if (latters_for_answer[p] == t)
                latters_for_answer[p] = '_';
        }

        bool found = false;

        for (int i = 0; latters[i] != '\0'; i++) {
            if (latters[i] == t) {
                count_of_close -= latters_count[i];

                for (int j = 0; j < count; j++) {
                    if (word[j] == latters[i]) {
                        answer[j] = t;
                    }
                }

                found = true;
            }
        }

        if (!found)
            misstakes++;
    }

    cout << answer << endl;

    if (misstakes < 7)
        cout << "\n\nWell done!\n\n";
    else
        cout << "\n\nVi mertvi!\n\n";
}