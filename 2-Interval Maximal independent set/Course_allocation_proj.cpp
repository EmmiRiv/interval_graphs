#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<pair<int, int>> &a, vector<pair<int, int>> &b)
{ // sort wrt leftmost right endpoint
    return a[0].second <= b[0].second;
}
void display(vector<pair<int, int>> &v)
{
    int x3 = v[0].first, y3 = v[0].second;
    int x4 = v[1].first, y4 = v[1].second;
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';
}
int main()
{ // Reference taken from bar- yehuda paper
    int courses;
    cout << "Type the num of courses for which you want to allot maximal number of courses to a student\n";
    cin >> courses;
    vector<vector<pair<int, int>>> lecture_timings(courses);
    cout << "Now, Enter the class intervals where the first class timings are before the second class\n";
    for (int i = 0; i < courses; i++)
    {
        int Num_of_lectures = 2;
        // cin>>Num_of_lectures;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lecture_timings[i] = {{x1, y1}, {x2, y2}};
    }
    // sorting wrt rightmost point of the first interval
    sort(lecture_timings.begin(), lecture_timings.end(), comparator);
    vector<vector<pair<int, int>>> Maximal_independent_set;
    while (lecture_timings.size() != 0)
    {
        // cout << '\n';
        vector<vector<pair<int, int>>> temp;
        Maximal_independent_set.push_back(lecture_timings[0]);
        int x1 = lecture_timings[0][0].first, y1 = lecture_timings[0][0].second;
        int x2 = lecture_timings[0][1].first, y2 = lecture_timings[0][1].second;
        for (int i = 1; i < lecture_timings.size(); i++)
        {
            int x3 = lecture_timings[i][0].first, y3 = lecture_timings[i][0].second;
            int x4 = lecture_timings[i][1].first, y4 = lecture_timings[i][1].second;
            if (x3 < y1)
                continue;

            if (x3 >= y2)
            {
                temp.push_back(lecture_timings[i]);
                // display(lecture_timings[i]);
                continue;
            }
            if (y3 > x2 && y3 <= y2)
                continue;
            else if (y4 <= x2)
            {
                temp.push_back(lecture_timings[i]);
                // display(lecture_timings[i]);
            }
            else if (x4 >= y2)
            {
                temp.push_back(lecture_timings[i]);
                // display(lecture_timings[i]);
            }
        }
        lecture_timings = temp;
    }
    cout << "Maximal independent set\n";
    for (int i = 0; i < Maximal_independent_set.size(); i++)
    {
        display(Maximal_independent_set[i]);
    }
}
