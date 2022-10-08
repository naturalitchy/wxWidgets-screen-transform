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
	contentTop->SetBackgroundColour(*wxRED);
	contentMenu->SetBackgroundColour(*wxBLUE);
	contentGameList->SetBackgroundColour(*wxBLACK);
	
	// Create Sizer.
	sizerMain = new wxBoxSizer(wxHORIZONTAL);
	sizerContent = new wxBoxSizer(wxVERTICAL);
	sizerMenu = new wxBoxSizer(wxVERTICAL);
	sizerGameListInner = new wxBoxSizer(wxVERTICAL);
	sizerGameList = new wxBoxSizer(wxVERTICAL);

	




}

