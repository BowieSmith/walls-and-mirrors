#include <iostream>
#include "ArrayMaxHeap.h"

int main()
{
	int intArr[] = {6, 3, 5, 9, 2, 10};
	ArrayMaxHeap<int> amh(intArr, 6);

	for (int i = 0; i < 8; i++)
	{
		try {
			std::cout << "Is Empty: " << amh.isEmpty() << std::endl;
			std::cout << "Top Item: " << amh.peekTop() << std::endl;
			std::cout << "Number of nodes: " << amh.getNumberOfNodes() << std::endl;
			std::cout << "Heap Height: " << amh.getHeight() << std::endl << std::endl;
		} catch(PrecondViolatedExcept e) {
			std::cout << e.what();
		}
		

		bool canRemove = amh.remove();
		if (canRemove) {
			std::cout << "Can remove top." << std::endl;
		} else {
			std::cout << "Can't remove top." << std::endl;
		}
	}

	return 0;
}