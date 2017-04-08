#include "City.h"
#include "BinarySearchTree.h"
using namespace std;

int main() {
	City dublin = City("Dublin", 2, make_pair(53.3498, -6.2603), 14.1);
	City paris = City("Paris", 100000, make_pair(48.8566, 2.3522), 11.1);
	City newYork = City("New York", 545454, make_pair(40.7128, -74.0059), 9.1);
	City london = City("London", 5454, make_pair(51.5074,-0.1278), 19.1);
	City cork = City("Cork", 3178878, make_pair(51.9942, -8.7285), 15.1);
	City manchester = City("Manchester", 1700000, make_pair(53.4808, -2.24261), 14.9);
	City chicago = City("Chicago", 5000000, make_pair(41.8781, -87.6298), 22);

	BinarySearchTree tree = BinarySearchTree();

	tree.add(dublin);
	tree.add(paris);
	tree.add(newYork);
	tree.add(london);
	tree.add(cork);
	tree.add(manchester);
	tree.add(chicago);
	cout << tree.height() << endl;
	//cout <<"ROOT::::"<< tree.getRootName() << endl;

	////tree.deleteNode("Cork");

	//cout << tree.height() << endl;

	//tree.inorder();

	//tree.deleteNode("Manchester");
	//cout << "ROOT::::" << tree.getRootName() << endl;

	//cout << "\n\n\n\n\n" << endl;
	//tree.inorder();

	//cout << "\n" << endl;
	//cout << tree.height() << endl;

	//cout << endl;

	tree.citiesNearby(dublin.getCoordinates(), 300);

	system("pause");
	return 1;
}