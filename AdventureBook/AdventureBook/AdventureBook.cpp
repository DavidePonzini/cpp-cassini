#include "Page.h"
#include "Constants.h"


#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "Usage:" << endl;
		cerr << '\t' << argv[0] << " <pages folder> <first page>" << endl;

		exit(1);
	}

	PAGES_DIR = argv[1];
	string firstPageName = argv[2];

	try {
		Page* firstPage = new Page(firstPageName);

		system("pause");

		firstPage->ShowText();
	}
	catch (Error e) {
		switch (e) {
		case Error::ERR_FILE_READ:
			cerr << "Error reading file" << endl;
			break;
		case Error::ERR_INDEX_OUT_OF_BOUNDS:
			cerr << "Index of out bounds" << endl;
			break;
		default:
			cerr << "Unknown error" << endl;
		}
	}
}
