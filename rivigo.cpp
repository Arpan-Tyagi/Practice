#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int factor(int x, int y, int g)
{
    int arr[x/2];
    for(int i=g+1; i < x/2; i++)
    {
        if((x%i) == 0)
            arr[i] = i;
    }   
    for(int i=g+1; i < y/2; i++)
    {
        if((y%i) == 0)
        {
            for(int j=g+1; j < x/2; j++)
            {
                if(arr[j] == i)
                    return 1;
            }
        }    
    }
    return 0;
}

vector<int> connectedCities(int n, int g, vector<int> originCities, vector<int> destinationCities) {

    vector<int> ifpathexists;
    int i = originCities.size();
    auto ite = destinationCities.begin();
    for(auto it = originCities.begin(); i>0 ; it++, ite++)
    {   
        ifpathexists.push_back(factor(*it,*ite,g));
            i++;
    }
    return ifpathexists;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    string originCities_count_temp;
    getline(cin, originCities_count_temp);

    int originCities_count = stoi(ltrim(rtrim(originCities_count_temp)));

    vector<int> originCities(originCities_count);

    for (int i = 0; i < originCities_count; i++) {
        string originCities_item_temp;
        getline(cin, originCities_item_temp);

        int originCities_item = stoi(ltrim(rtrim(originCities_item_temp)));

        originCities[i] = originCities_item;
    }

    string destinationCities_count_temp;
    getline(cin, destinationCities_count_temp);

    int destinationCities_count = stoi(ltrim(rtrim(destinationCities_count_temp)));

    vector<int> destinationCities(destinationCities_count);

    for (int i = 0; i < destinationCities_count; i++) {
        string destinationCities_item_temp;
        getline(cin, destinationCities_item_temp);

        int destinationCities_item = stoi(ltrim(rtrim(destinationCities_item_temp)));

        destinationCities[i] = destinationCities_item;
    }

    vector<int> res = connectedCities(n, g, originCities, destinationCities);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
