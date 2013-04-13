#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	vector<int>count(26,0);
	
	int number,length,n,beauty;
	int result,case_number=1;
	char letter;
	char ar[1024];
	cin >> number;
	
	cin.getline(ar,1024);
	
	for(int i=0; i<number;i++)
	{
		result =0;
		beauty=26;
		n=0;
		cin.getline(ar,1024);
		length = strlen(ar);
		for(int j=0; j<length; j++)
		{
			letter = ar[j];
			if(letter >= 'a' && letter <= 'z')
				count[letter-'a']++;
			if(letter >= 'A' && letter <= 'Z')
				count[letter-'A']++;
		}
		
		sort(count.begin(), count.end());
		
		while(!count.empty())
		{
			result += count.back()*(beauty-n);
			count.pop_back();
			n++;
		}
		count.resize(26,0);
		cout << "Case #" << case_number << ": " << result << endl;
		case_number++;
	}
}
