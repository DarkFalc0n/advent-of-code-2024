// Advent of Code 2024 - DarkFalc0n
// --- Day 1: Historian Hysteria ---

#include <bits/stdc++.h>
using namespace std;

void print_distance_between_lists(vector<int> &list1, vector<int> &list2)
{
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int32_t distance = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        distance += abs(list1[i] - list2[i]);
    }
    cout << "Distance " << distance << endl;
}

void print_similarity_score(vector<int> &list1, vector<int> &list2)
{
    int32_t score = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        if (list1[i] == 0)
            continue;
        int32_t c = count(list2.begin(), list2.end(), list1[i]);
        score += c * list1[i];
    }
    cout << "Score " << score << endl;
}

int32_t main()
{

    ifstream f("1_historian_hysteria/input.txt");

    if (!f.is_open())
    {
        cerr << "File not found!";
        return 1;
    }

    vector<int> list1, list2;
    while (!f.eof())
    {
        int first, second;
        f >> first;
        f >> second;
        list1.push_back(first);
        list2.push_back(second);
    }

    print_distance_between_lists(list1, list2);
    print_similarity_score(list1, list2);

    return 0;
}
