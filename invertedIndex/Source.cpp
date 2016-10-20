#include <iostream>
#include <fstream>
#include <string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
set<string> fields;
void split(string s)
{
	string a;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ',' || s[i] == ':' || s[i] == ' ' || s[i] == ';' || s[i] == '-' || s[i] == '.')
		{
			if (!a.empty())
			{
				fields.insert(a);
			}
			a.clear();
			continue;
		}
		a.push_back(s[i]);
	}
	if (!a.empty())
		fields.insert(a);
}
vector<int> ANDD(vector<int> p, vector<int> q)
{
	vector<int> ans;
	int i = 0, j = 0;
	for (; i != p.size() && j != q.size();)
	{
		if (p[i] == q[j]) {
			ans.push_back(p[i]);
			i++;
			j++;
		}
		else if (p[i] < q[j])
			i++;
		else
			j++;
	}
	return ans;
}
vector<int> andNot(vector<int> p, vector<int> q)
{
	vector<int> ans;
	int i = 0;
	for (; i != p.size();)
	{
		if (upper_bound(q.begin(), q.end(), p[i]) - lower_bound(q.begin(), q.end(), p[i]) == 0)
			ans.push_back(p[i]);
		i++;
	}
	return ans;
}
set<string> splitTwo(string s)
{
	set<string> ans;
	int words = 0;
	string a;
	string b;
	int i = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == ',' || s[i] == ':' || s[i] == ' ' || s[i] == ';' || s[i] == '-' || s[i] == '.')
			break;
		else
			a.push_back(s[i]);
	i++;
	for (; i < s.size(); ++i) {
		if (s[i] == ',' || s[i] == ':' || s[i] == ' ' || s[i] == ';' || s[i] == '-' || s[i] == '.')
		{
				ans.insert(a + " " + b);
				a = b;
				b.clear();
				words = 0;
		}
		b.push_back(s[i]);
	}
	ans.insert(a + " " + b);
	return ans;
}
map<string, vector<int> > input;
int main() {
	string s;
	ifstream read("input.txt");
	ofstream write("output.txt");
	int line = 1;
	while (getline(read, s))
	{
		fields.clear();
		split(s);
		set<string>::iterator it;
		for (it = fields.begin(); it != fields.end(); it++)
			input[*it].push_back(line);
		line++;
	}
	map<string, vector<int> > ::iterator v;
	for (v = input.begin(); v != input.end(); ++v)
	{
		sort(v->second.begin(), v->second.end());
		for (int i = 0; i < v->second.size(); ++i)
			write << v->second[i] << " ";
		write << endl;
	}
	vector<int> both;
	both = ANDD(input["want"], input["major"]);
	for (int i = 0; i < both.size(); ++i)
		write << both[i] << " ";
	write << endl;
	vector<int> first;
	first = andNot(input["want"], input["major"]);
	for (int i = 0; i < first.size(); ++i)
		write << first[i] << " ";
	write << endl;
	return 0;
}