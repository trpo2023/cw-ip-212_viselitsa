#include <viselica_lib/viselica.h>
#include <iostream>

using namespace std;

int main()
{
    char word[50];
    cout << "Set the word: ";
    cin >> word;
    
    int count = strlen(word);
    
    for (int i = 0; i < count; i++)
    {
        word[i] = tolower(word[i]);
    }
    
    sortWord(word, count);
    
    char latters[26];
    int latters_count[26] = { 0 };
    
    countLetters(word, count, latters, latters_count);
    
    playHangman(word, count, latters, latters_count);
    
    return 0;
}