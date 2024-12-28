// miniroot.cpp : Defines the entry point for the application.
//

#include "miniroot.h"

#include "TF1.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TRint.h"

int main(int argc, char** argv)
{
	std::cout << "Hello CMake." << std::endl;
	
	
	// Start root application.
	//TRint app("app", &argc, argv); // Use if you want/need the root interpreter.
	TApplication app("app", &argc, argv);
	
	// Drawing canvas.
	TCanvas* c = new TCanvas("c", "Something V2", 200, 200, 800, 600);
	
	// Connect canvas to system messages.
	TRootCanvas* rc = (TRootCanvas*)c->GetCanvasImp();
	rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");


	// Make a new canvas.
	TCanvas* c2 = new TCanvas("c22", "Pippo", 250, 250, 1200, 400);
	TRootCanvas* rc2 = (TRootCanvas*)c2->GetCanvasImp();
	rc2->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");


	// Build a graph and plot something.
	TF1* f1 = new TF1("f1", "sin(x)", -5, 5);
	f1->SetLineColor(kBlue + 1);
	f1->SetTitle("My graph;x; sin(x)");
	c->cd();
	f1->Draw();
	c->Modified();
	c->Update();
	
	c2->Modified();
	c2->Update();


	
	// Run the application.
	app.Run();
		
	return 0;

}
