#include "MyApplication.h"

int main()
{
	MyApplication app(800, 600, "Game");
	app.run(app);
	
	return 0;
}