#include <iostream>
#include <vector>

using namespace std;

// Function to display current cache contents
void displayCache(vector<int> cache)
{
    cout << "Current Cache: ";

    for (int i = 0; i < cache.size(); i++)
    {
        cout << "[" << cache[i] << "] ";
    }

    cout << endl;
}

int main()
{
    int cacheSize, n;

    cout << "Enter Cache Size: ";
    cin >> cacheSize;

    cout << "Enter Number of Memory Accesses: ";
    cin >> n;

    vector<int> memory(n);

    cout << "\nEnter Memory Access Sequence:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> memory[i];
    }

    vector<int> cache;

    int hits = 0;
    int misses = 0;
    int pointer = 0;

    for (int i = 0; i < n; i++)
    {
        bool hit = false;

        for (int j = 0; j < cache.size(); j++)
        {
            if (cache[j] == memory[i])
            {
                hit = true;
                break;
            }
        }

        cout << "\n--------------------------------------\n";
        cout << "Access #" << i + 1 << endl;
        cout << "Memory Block : " << memory[i] << endl;

        if (hit)
        {
            hits++;
            cout << "Status : HIT" << endl;
        }
        else
        {
            misses++;
            cout << "Status : MISS" << endl;

            if (cache.size() < cacheSize)
            {
                cache.push_back(memory[i]);
            }
            else
            {
                cache[pointer] = memory[i];
                pointer = (pointer + 1) % cacheSize;
            }
        }

        displayCache(cache);
    }

    float hitRatio = (float)hits / n;
    float missRatio = (float)misses / n;

    cout << "\n======================================\n";
    cout << "           FINAL REPORT\n";
    cout << "======================================\n";

    cout << "Total Accesses : " << n << endl;
    cout << "Cache Size     : " << cacheSize << endl;
    cout << "Total Hits     : " << hits << endl;
    cout << "Total Misses   : " << misses << endl;
    cout << "Hit Ratio      : " << hitRatio * 100 << "%" << endl;
    cout << "Miss Ratio     : " << missRatio * 100 << "%" << endl;

    return 0;
}