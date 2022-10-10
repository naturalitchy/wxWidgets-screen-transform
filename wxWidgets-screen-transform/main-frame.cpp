#include "main-frame.h"

MainFrame::MainFrame(const wxString &title)
	: wxFrame(nullptr, wxID_ANY, title) {
	CreateStatusBar();

	// Create Panel.
	contentTop = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(-1,100));
	contentMenu = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxSize(150,-1));
	contentGameList = new wxScrolledWindow(this);
	contentDofTest = new wxScrolledWindow(this);
	contentTop->Bind(wxEVT_PAINT, &MainFrame::SetTopPaint, this);
	contentMenu->Bind(wxEVT_PAINT, &MainFrame::SetMenuPaint, this);
	contentGameList->Bind(wxEVT_PAINT, &MainFrame::SetGameListPaint, this);
	//contentDofTest->Bind(wxEVT_PAINT, &MainFrame::SetGameListPaint, this);
	//contentTop->SetBackgroundColour(*wxRED);
	//contentMenu->SetBackgroundColour(*wxBLUE);
	//contentGameList->SetBackgroundColour(*wxBLACK);
	//contentDofTest->SetBackgroundColour(*wxGREEN);
	
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
	btnGameList->Bind(wxEVT_BUTTON, &MainFrame::ShowGameList, this);		// "Game List" button click event.
	btnDofTest->Bind(wxEVT_BUTTON, &MainFrame::ShowDofTest, this);			// "6DOF Test" button click event.

	// Create Game List Box.
	btnAssetto = new wxButton(contentGameList, wxID_ANY, "Assetto Corsa", wxPoint(50,100), wxSize(150,50));
	btnEuroTruck = new wxButton(contentGameList, wxID_ANY, "Euro Truck", wxPoint(50,550), wxSize(150, 50));
	/* for free button.
	sizerGameListInner->Add(btnAssetto, 0, wxEXPAND | wxALL);
	sizerGameListInner->Add(btnEuroTruck, 0, wxEXPAND | wxALL);
	contentGameList->SetSizer(sizerGameListInner);
	*/
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
	sizerTop->Add(contentTop, 0, wxEXPAND | wxALL);
	sizerContent->Add(sizerTop, 0, wxEXPAND | wxALL);
	sizerContent->Add(sizerGameList, 1, wxEXPAND | wxALL);
	sizerContent->Add(sizerDofTest, 1, wxEXPAND | wxALL);
	sizerMain->Add(contentMenu, 0, wxEXPAND | wxALL);
	sizerMain->Add(sizerContent, 1, wxEXPAND | wxALL);
	
	this->SetSizer(sizerMain);
}

void MainFrame::SetTopPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(contentTop);
	wxRect clientRect = GetClientRect();
	wxRect gradientRect = clientRect;
	dc.GradientFillLinear(gradientRect, wxColour(30, 30, 35), wxColour(28, 28, 33), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(26, 26, 31), wxColour(24, 24, 29), wxSOUTH);

	dc.SetPen(wxColor(255, 0, 0));
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.DrawRectangle(0, 0, clientRect.GetWidth(), clientRect.GetHeight());
	dc.SetFont(GetFont());
	dc.SetTextForeground(GetForegroundColour());
}

void MainFrame::SetMenuPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(contentMenu);
	wxRect clientRect = GetClientRect();
	wxRect gradientRect = clientRect;
	dc.GradientFillLinear(gradientRect, wxColour(50, 50, 55), wxColour(48, 48, 53), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(46, 46, 51), wxColour(44, 44, 49), wxSOUTH);

	dc.SetPen(wxColor(255, 0, 0));
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.DrawRectangle(0, 0, clientRect.GetWidth(), clientRect.GetHeight());
	dc.SetFont(GetFont());
	dc.SetTextForeground(GetForegroundColour());
}

void MainFrame::SetGameListPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(contentGameList);
	wxRect clientRect = GetClientRect();
	wxRect gradientRect = clientRect;
	dc.GradientFillLinear(gradientRect, wxColour(40, 40, 45), wxColour(38, 38, 43), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(36, 36, 41), wxColour(34, 34, 39), wxSOUTH);

	dc.SetPen(wxColor(255, 0, 0));
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.DrawRectangle(0, 0, clientRect.GetWidth(), clientRect.GetHeight());
	dc.SetFont(GetFont());
	dc.SetTextForeground(GetForegroundColour());
}
void MainFrame::ShowDofTest(const wxCommandEvent &evt) {
	sizerGameList->ShowItems(false);
	sizerDofTest->ShowItems(true);

	sizerMain->Layout();
}

void MainFrame::ShowGameList(const wxCommandEvent &evt) {
	sizerDofTest->ShowItems(false);
	sizerGameList->ShowItems(true);

	sizerMain->Layout();
}
