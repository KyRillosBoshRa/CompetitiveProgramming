#include <bits/stdc++.h>

using namespace std;

int main()
{
	int partecepants, budget, hotelsAvilable, weekends;
	cin >> partecepants >> budget >> hotelsAvilable >> weekends;
	int hotelPrice, avilableBeds,output = budget + 1 ;
	for (int i = 0; i < hotelsAvilable; i++)
	{
		cin >> hotelPrice;
		for (int j = 0; j < weekends; j++)
		{
			cin >> avilableBeds;
			if (avilableBeds >= partecepants && hotelPrice * partecepants < output)
			{
				output = hotelPrice * partecepants;
			}
		}
	}
	output <= budget ? cout << output << endl : cout << "stay home" << endl;
    return 0;
}
