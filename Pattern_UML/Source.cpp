#include<iostream>
#include"FactoryMethod.h"


using namespace std;



int main()
{
	setlocale(LC_ALL, "");
/*Creator* creator = new TrackCreator;
	Transport* track = creator->create();
		track->delivery("IT STEP");

		creator = new ShipCreator;
		Transport* ship = creator->create();
		ship->delivery("MorPort");*/



	Transport* transport;
	Creator* creator;
	int n;
	cout << "Type transport: 1-Track, 2-Ship, 3-Plane" << endl;
	cin >> n;
	switch (n)
	{

	case 1:
		creator = new TrackCreator;
		break;
	case 2:
		creator = new ShipCreator;
		break;
	case 3:
		creator = new PlaneCreator;
		break;
	default:
		creator = new TrackCreator;
		break;
	}
	transport = creator->create();
	transport->delivery("в деревню дедушке");
	system("pause");
}