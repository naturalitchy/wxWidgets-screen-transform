#include "main-frame.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(nullptr, wxID_ANY, title) {
	CreateStatusBar();

	// Create Panel.
	//contentTop = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(-1,100));
	//contentMenu = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(150,-1));
	contentTop = new wxPanel(this);
	contentMenu = new wxPanel(this);
	contentGameList = new wxPanel(this);
	contentDofTest = new wxPanel(this);
	contentTop->SetBackgroundColour(*wxRED);
	contentMenu->SetBackgroundColour(*wxBLUE);
	contentGameList->SetBackgroundColour(*wxBLACK);
	contentDofTest->SetBackgroundColour(*wxGREEN);
	
	
	// Create Sizer.
	sizerMain = new wxBoxSizer(wxHORIZONTAL);
	sizerTop = new wxBoxSizer(wxVERTICAL);
	sizerContent = new wxBoxSizer(wxVERTICAL);
	sizerMenu = new wxBoxSizer(wxVERTICAL);
	sizerGameListInner = new wxBoxSizer(wxVERTICAL);
	sizerGameList = new wxBoxSizer(wxVERTICAL);
	sizerDofTestInner = new wxBoxSizer(wxVERTICAL);
	sizerDofTest = new wxBoxSizer(wxVERTICAL);

	// Create Menu Box.
	btnGameList = new wxButton(contentMenu, wxID_ANY, "Game List", wxDefaultPosition, wxSize(50, 100));
	btnDofTest = new wxButton(contentMenu, wxID_ANY, "6DOF Test", wxDefaultPosition, wxSize(50, 100));
	sizerMenu->Add(btnGameList, 0, wxEXPAND | wxALL, 10);
	sizerMenu->Add(btnDofTest, 0, wxEXPAND | wxALL, 10);
	contentMenu->SetSizer(sizerMenu);
	btnDofTest->Bind(wxEVT_BUTTON, &MainFrame::ShowDofTest, this);			// "6DOF Test" button click event.

	// Create Game List Box.
	btnAssetto = new wxButton(contentGameList, wxID_ANY, "Assetto Corsa", wxDefaultPosition, wxSize(50,100));
	btnEuroTruck = new wxButton(contentGameList, wxID_ANY, "Euro Truck", wxDefaultPosition, wxSize(50,100));
	sizerGameListInner->Add(btnAssetto, 0, wxEXPAND | wxALL, 10);
	sizerGameListInner->Add(btnEuroTruck, 0, wxEXPAND | wxALL, 10);
	contentGameList->SetSizer(sizerGameListInner);
	sizerGameList->Add(contentGameList, 1, wxEXPAND | wxALL);

	// Create 6DOF Test Box.
	btnPitchTest = new wxButton(contentDofTest, wxID_ANY, "Pitch Test", wxDefaultPosition, wxSize(50,100));
	btnRollTest = new wxButton(contentDofTest, wxID_ANY, "Roll Test", wxDefaultPosition, wxSize(50,100));
	sizerDofTestInner->Add(btnPitchTest, 0, wxEXPAND | wxALL, 10);
	sizerDofTestInner->Add(btnRollTest, 0, wxEXPAND | wxALL , 10);
	contentDofTest->SetSizer(sizerDofTestInner);
	sizerDofTest->Add(contentDofTest, 1, wxEXPAND | wxALL);
	sizerDofTest->ShowItems(false);									// for only show "Game List"

	// Setting the Sizers.
	sizerTop->Add(contentTop, 1, wxEXPAND | wxALL);
	sizerContent->Add(sizerTop, 1, wxEXPAND | wxALL);
	sizerContent->Add(sizerGameList, 4, wxEXPAND | wxALL);
	sizerContent->Add(sizerDofTest, 4, wxEXPAND | wxALL);
	sizerMain->Add(contentMenu, 1, wxEXPAND | wxALL);
	sizerMain->Add(sizerContent, 4, wxEXPAND | wxALL);
	
	
	
	this->SetSizer(sizerMain);
}


void MainFrame::ShowDofTest(const wxCommandEvent &evt) {
	sizerGameList->ShowItems(false);
	sizerDofTest->ShowItems(true);

	sizerMain->Layout();
}
