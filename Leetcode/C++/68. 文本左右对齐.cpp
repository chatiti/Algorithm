class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        vector<string> t;
        int count = 0;
        for (auto s: words) {
            if (count + s.size() + t.size() - 1 < maxWidth) {
                t.push_back(s);
                count += s.size();
            } else {
                string temp = "";
                if (t.size() == 1) {
                    temp += t[0] + string(maxWidth - count, ' ');
                } else {
                    int left = maxWidth - count - (t.size() - 1);
                    vector<int> space(t.size() - 1,0);
                    int k = 0;
                    while (left > 0) {
                        space[k]++;
                        left--;
                        k = (k + t.size()) % (t.size() - 1);
                    }
                    for (int i = 0; i < t.size(); ++i) {
                        if (i != t.size() - 1) {
                            temp += t[i] + ' ';
                            if (i == 0 && left % 2 != 0) {
                                temp += string(space[i], ' ');
                            } else {
                                temp += string(space[i], ' ');
                            }
                        } else {
                            temp += t[i];
                        }
                    }
                }
                res.push_back(temp);
                count = s.size();
                t = vector<string>{s};
            }
        }
        if (t.size() != 0) {
            string temp = "";
            for (int i = 0; i < t.size(); ++i) {
                if (i != 0) {
                    temp += ' ';
                }
                temp += t[i];
            }
            if (temp.size() < maxWidth) {
                temp += string(maxWidth - temp.size(), ' ');
            }
            res.push_back(temp);

        }
        return res;
    }


};