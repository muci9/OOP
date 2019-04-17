#include "UI.h"
#include <crtdbg.h>

int main()
{
	Repository repository{};
	Repository transferred{};
	Controller controller{ repository, transferred };
	UI ui{ controller };
	try {
		ui.userInterface();
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}