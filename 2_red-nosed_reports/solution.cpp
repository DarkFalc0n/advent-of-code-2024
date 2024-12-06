// Advent of Code 2024 - DarkFalc0n
// --- Day 2: Red-Nosed Reports ---

#include <bits/stdc++.h>
using namespace std;

bool is_report_safe(vector<int> &report, int32_t ignore = -1)
{
    set<int> pos_diff = {1, 2, 3}, neg_diff = {-1, -2, -3};
    for (int i = 1; i < report.size(); i++)
    {
        if (i == ignore)
        {
            continue;
        }
        if (i == ignore + 1)
        {
            if (i > 1)
            {
                pos_diff.insert(report[i] - report[i - 2]);
                neg_diff.insert(report[i] - report[i - 2]);
            }
            continue;
        }
        pos_diff.insert(report[i] - report[i - 1]);
        neg_diff.insert(report[i] - report[i - 1]);
    }

    return pos_diff.size() == 3 || neg_diff.size() == 3;
}

bool is_damped_report_safe(vector<int> &report)
{
    bool result = false;
    for (int i = 0; i < report.size(); i++)
    {
        if (is_report_safe(report, i))
        {
            result = true;
            break;
        }
    }
    return result;
}

int32_t main()
{

    ifstream f("2_red-nosed_reports/input.txt");

    if (!f.is_open())
    {
        cerr << "File not found!";
        return 1;
    }

    int32_t safe_reports = 0, damped_safe_reports = 0;
    while (!f.eof())
    {
        vector<int> report;
        string line;
        getline(f, line);
        stringstream ss(line);
        while (!ss.eof())
        {
            int i;
            ss >> i;
            report.push_back(i);
        }
        if (is_report_safe(report))
        {
            safe_reports++;
        }
        if (is_damped_report_safe(report))
        {
            damped_safe_reports++;
        }
    }
    cout << "Safe reports " << safe_reports << endl;
    cout << "Damped safe reports " << damped_safe_reports << endl;

    return 0;
}
