// miniroot.cpp : Defines the entry point for the application.
//

#include "miniroot.h"

#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"

int main(int argc, char** argv)
{
	std::cout << "Hello CMake." << std::endl;
	
	
	// Start root application.
	TApplication app("app", &argc, argv);
	
	// Drawing canvas.
	TCanvas* c = new TCanvas("c", "Something", 0, 0, 800, 600);
	
	// Connect canvas to system messages.
	TRootCanvas* rc = (TRootCanvas*)c->GetCanvasImp();
	rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");

	
	TF1* f1 = new TF1("f1", "sin(x)", -5, 5);
	f1->SetLineColor(kBlue + 1);
	f1->SetTitle("My graph;x; sin(x)");
	f1->Draw();
	c->Modified();
	c->Update();
	
	// Run the application.
	app.Run();
		
	return 0;

}
