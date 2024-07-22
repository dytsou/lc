#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    struct Person {
        string name;
        int height;
        bool operator < (const Person& other) const {
            return height == other.height ? name < other.name : height > other.height;
        }
        Person(string name, int height):
            name(name), height(height){}
    };
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<Person> people;
        for (int i = 0; i < names.size(); i++) {
            people.push_back(Person(names[i], heights[i]));
        }
        sort(people.begin(), people.end());
        vector<string> ans;
        for (auto& person : people) {
            ans.push_back(person.name);
        }
        return ans;
    }
};

int main(){
    Solution s;
    int person_num;
    cin >> person_num;
    vector<string> names(person_num);
    vector<int> heights(person_num);
    for (int i = 0; i < person_num; i++) {
        cin >> names[i];
        cin >> heights[i];
    }
    vector<string> ans = s.sortPeople(names, heights);
    for (auto& name : ans) {
        cout << name << " ";
    }
    cout << endl;
    return 0;
}