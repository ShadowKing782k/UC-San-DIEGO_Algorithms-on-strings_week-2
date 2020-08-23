#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

string shift(string text, int len)
{
	string s;
	s.resize(len);
	s[0] = text[len - 1];
	for (int i = 1; i <= len - 1; i++)
	{
		s[i] = text[i - 1];
	}
	return s;
}


vector<string> BWT(string text, int len)
{
	int rot = 1;
	vector<string> btw_mat;
	for (int i = 0; i < len; i++)
	{
		text = shift(text, len);
		btw_mat.push_back(text);

	}
	sort(btw_mat.begin(), btw_mat.end());
	return btw_mat;
}

int main()
{
	string text;
	cin >> text;
	int len = text.length();
	vector<string> mat = BWT(text, len);
	for (int i = 0; i < mat.size(); i++)
		cout << mat[i][len - 1];
}