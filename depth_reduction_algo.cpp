#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

vector<vector<pair<int, int>>> test1()
{
    vector<vector<pair<int, int>>> v;
    v.push_back({{2, 10}, {100, 110}});
    v.push_back({{4, 11}, {105, 111}});
    v.push_back({{14, 19}, {120, 130}});
    v.push_back({{21, 23}, {140, 145}});
    return v;
}
vector<vector<pair<int, int>>> test2()
{
    vector<vector<pair<int, int>>> v;
    v.push_back({{0, 3}});            // c
    v.push_back({{1, 4}, {20, 22}});  // a
    v.push_back({{1, 3}, {21, 25}});  // b
    v.push_back({{5, 10}, {23, 28}}); // e
    v.push_back({{6, 8}, {24, 25}});  // d
    v.push_back({{9, 11}, {26, 29}}); // f
    v.push_back({{27, 30}});          // g
    return v;
}
vector<vector<pair<int, int>>> northwestern()
{
    return {
        {{600, 650}, {3480, 3530}, {6360, 6410}},
        {{780, 830}, {3660, 3710}, {6540, 6590}},
        {{840, 890}, {3720, 3770}, {6700, 6650}},
        {{720, 770}, {3600, 3650}, {6480, 6530}},
        {{2190, 2270}, {5070, 5150}},
        {{2010, 2180}, {4890, 4970}},
        {{2190, 2270}, {5070, 5150}},
        {{2110, 2190}, {4990, 5070}},
        {{2110, 2190}, {4990, 5070}},
        {{2010, 2180}, {4890, 4970}},
        {{6600, 6710}},
        {{2010, 2190}, {4990, 5070}},
        {{2280, 2360}, {5160, 5240}},
        {{830, 1010}, {3810, 3890}},
        {{2110, 2190}, {4990, 5070}},
        {{6480, 6590}},
        {{2370, 2450}, {5250, 5330}},
        {{2460, 2540}, {5340, 5420}},
        {{660, 710}, {3540, 3590}, {6420, 6470}},
        {{480, 530}, {3360, 3310}, {6240, 6310}},
        {{720, 830}, {3600, 3710}},
        {{2370, 2450}, {5250, 5330}},
        {{930, 1010}, {3810, 3890}},
        {{2580, 2660}, {5460, 5540}},
        {{2220, 2300}, {5100, 5180}},
        {{2460, 2510}},
        {{2460, 2510}},
        {{930, 1010}, {3810, 3890}},
        {{2220, 2300}, {5100, 5180}},
        {{2280, 2360}, {5160, 5240}},
        {{2010, 2090}, {4890, 4970}},
        {{660, 740}, {3540, 3620}},
        {{660, 740}, {3540, 3620}},
        {{960, 1010}, {3840, 3890}, {6720, 6770}},
        {{900, 950}, {3780, 3830}, {6660, 6710}},
        {{660, 710}, {3540, 3590}, {6420, 6470}},
        {{2220, 2300}, {5100, 5180}},
        {{2370, 2450}, {5250, 5330}},
        {{2220, 2300}, {5100, 5180}},
        {{2280, 2390}, {5160, 5270}},
        {{600, 650}, {3480, 3530}, {6360, 6410}},
        {{2280, 2360}, {5160, 5240}},
        {{2220, 2300}, {5100, 5180}},
        {{6480, 6650}},
        {{2010, 2090}, {4890, 4970}},
        {{2190, 2270}, {5070, 5150}},
        {{2370, 2450}, {5250, 5330}},
        {{2220, 2300}, {5100, 5180}},
        {{2010, 2180}},
        {{660, 740}, {3540, 3620}},
        {{2010, 2090}, {4890, 4890}},
        {{6600, 6780}},
        {{900, 1020}},
        {{2220, 2390}},
        {{2280, 2390}, {5160, 5270}},
        {{930, 1010}, {3810, 3890}}};
}
vector<vector<pair<int, int>>> tc3()
{
    return {
        {{1, 3}, {10, 12}}, // e 0
        {{2, 5}},           // a 1
        {{4, 6}},           // b 2
        {{6, 7}, {13, 15}}, // c 3
        {{11, 14}}          // d 4

    };
}

void independent_intervals(vector<vector<pair<int, int>>> Intervals)
{
    int numCourses = Intervals.size();
    vector<vector<bool>> valid, deleted;
    vector<vector<int>> sortedIntervals;
    int cnt = 0;
    for (auto course : Intervals)
    {
        int cnt2 = 0;
        for (auto classInterval : course)
        {
            sortedIntervals.push_back({classInterval.first, classInterval.second, cnt, cnt2++});
        }
        vector<bool> val(cnt2, true);
        valid.push_back(val);
        vector<bool> val2(cnt2, false);
        deleted.push_back(val2);
        cnt++;
    }
    int max_depth = 0;
    vector<int> depth;
    sort(sortedIntervals.begin(), sortedIntervals.end(), compare);

    for (int i = 0; i < sortedIntervals.size(); i++)
    {
        int cur_depth = 1;
        // to claculate the depht for the current interval in the sorted list
        for (int j = i + 1; j < sortedIntervals.size(); j++)
        {
            // count the interval if it intersects the current interval
            if (i != j && sortedIntervals[i][1] <= sortedIntervals[j][1] && sortedIntervals[i][1] >= sortedIntervals[j][0])
            {
                cur_depth++;
            }
        }
        depth.push_back(cur_depth);
        max_depth = max(cur_depth, max_depth);
    }
    //  cout << "Max Depth : " << max_depth << '\n';
    int r = 4;
    while (max_depth > 1)
    {
        cout << "\n\nMax Depth : " << max_depth << '\n';

        for (int i = 0; i < sortedIntervals.size(); i++)
        {
            if (deleted[sortedIntervals[i][2]][sortedIntervals[i][3]])
                continue;

            // cout << sortedIntervals.size() << ' ' << i << ' ' << sortedIntervals[i][0] << ' ' << sortedIntervals[i][1] << ' ' << depth[i] << '\n';
            if (depth[i] == max_depth)
            {
                if (valid[sortedIntervals[i][2]][sortedIntervals[i][3]])
                {
                    // cout << "Valid\n";
                    for (int j = 0; j < Intervals[sortedIntervals[i][2]].size(); j++)
                    {
                        deleted[sortedIntervals[i][2]][j] = true;
                        // cout<<Intervals[sortedIntervals[i][2]][j].first<<' '<<Intervals[sortedIntervals[i][2]][j].second<<'\n';
                    }
                    for (int j = 0; j < Intervals[sortedIntervals[i][2]].size(); j++)
                    {
                        for (auto inv : sortedIntervals)
                        {
                            if (inv[0] >= Intervals[sortedIntervals[i][2]][j].first && inv[0] <= Intervals[sortedIntervals[i][2]][j].second)
                            {
                                valid[inv[2]][inv[3]] = false;
                            }
                            else if (inv[1] >= Intervals[sortedIntervals[i][2]][j].first && inv[1] <= Intervals[sortedIntervals[i][2]][j].second)
                            {
                                valid[inv[2]][inv[3]] = false;
                            }
                        }
                    }

                    // |______|
                    //     |______|

                    //        |__________|
                }
                else
                {
                    // cout << "Else\n";

                    int x = -1, y = -1;
                    for (int j = i + 1; j < sortedIntervals.size(); j++)
                    {
                        if (deleted[sortedIntervals[j][2]][sortedIntervals[j][3]] == 0 && sortedIntervals[i][1] <= sortedIntervals[j][1] && sortedIntervals[i][1] >= sortedIntervals[j][0])
                        {
                            if (valid[sortedIntervals[j][2]][sortedIntervals[j][3]])
                            {
                                x = sortedIntervals[j][2];
                                y = sortedIntervals[j][3];
                                break;
                            }
                        }
                    }
                    if (x == -1 || y == -1)
                        continue;

                    for (int j = 0; j < Intervals[x].size(); j++)
                    {
                        deleted[x][j] = true;
                        // cout<<"Else:delete\n";
                        // cout<<Intervals[x][j].first<<' '<<Intervals[x][j].second<<'\n';
                    }
                    for (int j = 0; j < Intervals[sortedIntervals[x][2]].size(); j++)
                    {
                        for (auto inv : sortedIntervals)
                        {
                            if (inv[0] >= Intervals[sortedIntervals[x][2]][j].first && inv[0] <= Intervals[sortedIntervals[x][2]][j].second)
                            {
                                if (valid[inv[2]][inv[3]] == false)
                                    continue;
                                for (int k = 0; k < valid[inv[2]].size(); k++)
                                {
                                    valid[inv[2]][k] = false;
                                }
                            }
                            else if (inv[1] >= Intervals[sortedIntervals[x][2]][j].first && inv[1] <= Intervals[sortedIntervals[x][2]][j].second)
                            {
                                if (valid[inv[2]][inv[3]] == false)
                                    continue;
                                for (int k = 0; k < valid[inv[2]].size(); k++)
                                {
                                    valid[inv[2]][k] = false;
                                }
                            }
                        }
                    }
                }

                // for (int j = 0; j < deleted.size(); j++)
                // {
                //     if (deleted[j][0])
                //     {
                //         cout << j << ' ';
                //     }
                // }
                // cout << '\n';
            }
        }

        for (int i = 0; i < deleted.size(); i++)
        {
            if (deleted[i][0])
            {
                cout << i << ' ';
            }
        }
        cout << '\n';
        max_depth = 0;
        for (int i = 0; i < sortedIntervals.size(); i++)
        {
            valid[sortedIntervals[i][2]][sortedIntervals[i][3]] = 1;
            depth[i] = 1;
            if (deleted[sortedIntervals[i][2]][sortedIntervals[i][3]] == true)
                continue;
            int cur_depth = 1;
            // to claculate the depht for the current interval in the sorted list
            for (int j = i + 1; j < sortedIntervals.size(); j++)
            {
                // count the interval if it intersects the current interval
                if (deleted[sortedIntervals[j][2]][sortedIntervals[j][3]] == 0 && sortedIntervals[i][1] <= sortedIntervals[j][1] && sortedIntervals[i][1] >= sortedIntervals[j][0])
                {
                    cur_depth++;
                }
            }
            depth[i] = cur_depth;
            // cout<<sortedIntervals[i][0]<<' '<<sortedIntervals[i][1]<<' '<<cur_depth<<'\n';
            max_depth = max(cur_depth, max_depth);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // reduceDepth(test1(), 2);
    // reduceDepth(test2(), 3);
    independent_intervals(northwestern());
    // independent_intervals(tc3());

}

// there is not
//  depht is d but almost all the courses can be coloured d colors, leaving only a few uncolored courses
//