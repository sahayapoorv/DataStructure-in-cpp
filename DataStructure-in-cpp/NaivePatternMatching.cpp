#include <iostream>
#include <string>

using namespace std;

void ScanForPattern(string& mainText, string& patternString)
{
	bool bFound;
	for (int i = 0; i < mainText.size()- patternString.size(); i++)
	{
		bFound = true;
		for (int j = 0; j < patternString.size(); j++)
		{
			if (mainText.at(i + j) != patternString.at(j))
			{
				bFound = false;
				break;
			}
		}

		if (bFound)
		{
			cout << "Pattern found at " << i << endl;
		}
	}
}

int main()
{
	string mainString, patternString;
	cin >> mainString;
	cin >> patternString;

	ScanForPattern(mainString, patternString);

	return 0;
}