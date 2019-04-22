#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool compare_x(pair<long,long> x1, pair<long,long> x2) {
    if (x1.first < x2.first) {
        return true;
    } else {
        if (x1.first == x2.first) {
            return x1.second < x2.second;
        } else {
            return false;
        }
    }
}

bool compare_y(pair<long,long> y1, pair<long,long> y2) {
    if (y1.second < y2.second) {
        return true;
    } else {
        if (y1.second == y2.second) {
            return y1.first < y2.first;
        } else {
            return false;
        }
    }
}

int main() {
    long m,n,k;
    cin >> n >> m >> k;

    vector<pair<long,long>> black;
    set<pair<long,long>> one;

    for (int i = 0; i < k; i++) {
      int a,b;
      cin >> a >> b;
      black.push_back(make_pair(a,b));
    }
    long result = 0;

    if (k == 0) {
        if (m != 1 && n != 1) {
            cout << m + n;
        } else {
            if (m == 1 || n != 1) {

                    cout << 1;

            }
        }
        return 0;
    }

    sort(black.begin(),black.end(), compare_x);

    long i = 0;
    long line = 0;
    while (i < black.size()) {
        if (i == 0) {
            if (black.at(i).first > 1) {
                line =  black.at(i).first - 1;
                if (line == 1 && m == 1) {
                    one.insert(make_pair(black.at(i).first-1,black.at(i).second ));
                } else {
                    if (line > 0) {
                        result += line;
                    }
                }
            }
            line = black.at(i).second -1;
            if (line == 1) {
                one.insert(make_pair(black.at(i).first,black.at(i).second - 1));
            } else {
                if (line > 0) {
                    result++;
                }
            }
            i ++;
        } else {
            if (black.at(i).first > black.at(i - 1).first) {
                result += black.at(i).first - black.at(i - 1).first - 1;

                line =  m - black.at(i-1).second;

                if (line == 1) {
                    one.insert(make_pair(black.at(i-1).first,black.at(i-1).second + 1));
                } else {
                    if (line > 0) {
                        result++;
                    }
                }
                line = black.at(i).second - 1;
                if (line == 1) {
                    one.insert(make_pair(black.at(i).first,black.at(i).second - 1));
                } else {
                    if (line > 0) {
                        result++;
                    }
                }
                i++;
            } else {
                if (black.at(i).first == black.at(i - 1).first) {
                    line = (black.at(i).second - black.at(i-1).second) - 1;
                    if (line == 1) {
                        one.insert(make_pair(black.at(i).first,black.at(i).second - 1));
                    } else {
                        if (line > 0) {
                            result++;
                        }
                    }
                    i ++;
                }
            }
        }
    }


        line = m - black.at(black.size() - 1).second;
        if (line == 1) {
            one.insert(make_pair(black.at(black.size() - 1).first, black.at(black.size() - 1).second + 1));
        } else {
            if (line > 0) {
                result++;
            }
        }
        if (m != 1) {
            result += n - black.at(black.size() - 1).first;
        }


    sort(black.begin(),black.end(), compare_y);

    i = 0;
    line = 0;
    while (i < black.size()) {
        if (i == 0) {
            if (black.at(i).second > 1) {
                line =  black.at(i).second - 1;
                if (line == 1 && n == 1) {
                    if (one.find(make_pair(black.at(i).first - 1, black.at(i).second)) != one.end()) {
                        result++;
                    }
                } else {
                    if (line > 0) {
                        result += line;
                    }
                }
            }
            line = black.at(i).first -1;
            if (line == 1) {
                if (one.find(make_pair(black.at(i).first - 1, black.at(i).second)) != one.end()) {
                    result++;
                }
            } else {
                if (line > 0) {
                    result++;
                }
            }
            i ++;
        } else {
            if (black.at(i).second > black.at(i - 1).second) {
                result += black.at(i).second - black.at(i - 1).second - 1;

                line = black.at(i).first - 1;

                if (line == 1) {
                    if (one.find(make_pair(black.at(i).first - 1, black.at(i).second)) != one.end()) {
                        result++;
                    }
                } else {
                    if (line > 0) {
                        result++;
                    }
                }
                line =  n - black.at(i-1).first;

                if (line == 1) {
                    if (one.find(make_pair(black.at(i-1).first + 1, black.at(i-1).second)) != one.end()) {
                        result++;
                    }
                } else {
                    if (line > 0) {
                        result++;
                    }
                }
                i++;
            } else {
                if (black.at(i).second == black.at(i - 1).second) {
                    line = (black.at(i).first - black.at(i-1).first) - 1;
                    if (line == 1) {
                        if (one.find(make_pair(black.at(i).first - 1, black.at(i).second)) != one.end()) {
                            result++;
                        }
                    } else {
                        if (line > 0) {
                            result++;
                        }
                    }
                    i ++;
                }
            }
        }
    }


        line = n - black.at(black.size() - 1).first;
        if (line == 1) {
            if (one.find(make_pair(black.at(black.size() - 1).first + 1, black.at(black.size() - 1).second)) != one.end()) {
                result++;
            }
        } else {
            if (line > 0) {
                result++;
            }
        }
        if (n != 1) {
            result += m - black.at(black.size() - 1).second;
        }

    cout << result;

    return 0;
}