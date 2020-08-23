#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<iterator>
#include<algorithm>
using namespace std;
vector<pair<char, int>> sbwt;
std::map<char, int> start_index;

void find_start_index()
{
	start_index.insert(pair<char, int>('A', -1));
	start_index.insert(pair<char, int>('G', -1));
	start_index.insert(pair<char, int>('T', -1));
	start_index.insert(pair<char, int>('C', -1));
	start_index.insert(pair<char, int>('$', -1));
	for (int i = 0; i < sbwt.size(); i++)
	{
		if (start_index[sbwt[i].first] == -1)
			start_index[sbwt[i].first] = i;
	}

}

vector<char> ibtw(vector<pair<char, int>>bwt)
{
	vector<char> final;
	int i = 0;
	char c = bwt[i].first;
	while(c != '$')
	{
		// cout << i << " "<<c;
		i = start_index[bwt[i].first] + bwt[i].second - 1;
		final.push_back(c);
		// final.push_back(sbwt[i].first);
		c = bwt[i].first;
	}

	return final;
}


int main()
{
	map<char, int> dict;
	dict.insert(pair<char, int>('A', 0));
	dict.insert(pair<char, int>('C', 0));
	dict.insert(pair<char, int>('G', 0));
	dict.insert(pair<char, int>('T', 0));
	dict.insert(pair<char, int>('$', 0));
	string text;
	cin >> text;
	for (int i = 0; i < text.length(); i++)
	{
		sbwt.push_back(pair<char, int>(text[i], ++dict[text[i]]));

	}
	vector<pair<char, int>> bwt = sbwt;
	sort(sbwt.begin(), sbwt.end());

	find_start_index();
	//map<char, int>::iterator  itr;
	//for (itr = start_index.begin(); itr != start_index.end(); ++itr)
		//cout << itr->first << " " << itr->second << "\n";

	vector<char> p = ibtw(bwt);
	for (int i = p.size() -1; i >= 0; i--)
	{
		cout << p[i];
	}
	cout << "$";
}