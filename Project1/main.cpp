#include <iostream>
#include "setup.h"

int main(int argc, char *argv[])
{
	printf("Now starting Knoob Server manager for windows.\n");

	// Setup:
	SetupData *s = new SetupData();
	s->takeRemainingInput();

	printf("Setup complete\n");

	// Cleanup:
	delete s;
	s = NULL;

	system("pause");

	return 0;
}