#include "main-frame.h"
#include <iostream>

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
	contentDofTest->Bind(wxEVT_PAINT, &MainFrame::SetDofTestPaint, this);

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
	btnGameList = new wxButton(contentMenu, wxID_ANY, "Game List", wxPoint(25,25), wxSize(100, 50));
	btnDofTest = new wxButton(contentMenu, wxID_ANY, "6DOF Test", wxPoint(25, 100), wxSize(100, 50));
	/* delete code. (for free position button)
	sizerMenu->Add(btnGameList, 0, wxEXPAND | wxALL, 10);
	sizerMenu->Add(btnDofTest, 0, wxEXPAND | wxALL, 10);
	contentMenu->SetSizer(sizerMenu);
	*/
	btnGameList->Bind(wxEVT_BUTTON, &MainFrame::ShowGameList, this);		// "Game List" button click event.
	btnDofTest->Bind(wxEVT_BUTTON, &MainFrame::ShowDofTest, this);			// "6DOF Test" button click event.

	// Create Game List Box.
	btnAssetto = new wxButton(contentGameList, wxID_ANY, "Assetto Corsa", wxPoint(50,100), wxSize(150,50), wxBORDER_NONE);
	btnEuroTruck = new wxButton(contentGameList, wxID_ANY, "Euro Truck", wxPoint(50, 200), wxSize(150, 50), wxBORDER_NONE);
	//btnEuroTruck = new wxBitmapButton(contentGameList, wxID_ANY, wxBitmap(wxT("button-custom-ico.ico"), wxBITMAP_TYPE_ICO), wxPoint(50, 200), wxSize(150,50));
	btnAssetto->Bind(wxEVT_ENTER_WINDOW, &MainFrame::HoverMouseButton, this);
	btnAssetto->Bind(wxEVT_LEAVE_WINDOW, &MainFrame::LeaveMouseButton, this);
	btnEuroTruck->Bind(wxEVT_ENTER_WINDOW, &MainFrame::HoverMouseButton, this);
	btnEuroTruck->Bind(wxEVT_LEAVE_WINDOW, &MainFrame::LeaveMouseButton, this);
	btnAssetto->SetBackgroundColour(wxColour(50, 60, 75));
	btnEuroTruck->SetBackgroundColour(wxColour(50, 60, 75));

	/* delete code. (for free position button)
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
	dc.GradientFillLinear(gradientRect, wxColour(40, 40, 45), wxColour(38, 38, 43), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(36, 36, 41), wxColour(34, 34, 39), wxSOUTH);

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
	dc.GradientFillLinear(gradientRect, wxColour(40, 40, 45), wxColour(38, 38, 43), wxSOUTH);
	gradientRect.Offset(0, gradientRect.GetHeight());
	dc.GradientFillLinear(gradientRect, wxColour(36, 36, 41), wxColour(34, 34, 39), wxSOUTH);

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

void MainFrame::SetDofTestPaint(const wxEvent &evt) {
	wxLogStatus("execute");
	wxPaintDC dc(contentDofTest);
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


//-----------------------------------------------
// Button event
//-----------------------------------------------
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

//-----------------------------------------------
// Button click event
//-----------------------------------------------
void MainFrame::ResetColor(wxButton *button, const wxColour color) {
	wxLogStatus(" Reset Color !");
	
	button->SetBackgroundColour(color);
}
void MainFrame::ClickButton(wxMouseEvent &evt) {
	wxLogStatus(" default click event ");
	wxColour col = btnEuroTruck->GetBackgroundColour();
	this->btnEuroTruck->SetBackgroundColour(wxColour(100, 100, 100));
	
	//MainFrame::ResetColor(btnEuroTruck, col);
}

void MainFrame::HoverMouseButton(wxMouseEvent &evt) {
	wxLogStatus(" Hover Mouse!! ");

	btn.SetBackgroundColour(wxColour(200, 200, 200));
	//this->btnAssetto->SetBackgroundColour(wxColour(200,200,200));
}
void MainFrame::LeaveMouseButton(wxMouseEvent &evt) {
	wxLogStatus(" Leave Mouse!! ");
	this->btnAssetto->SetBackgroundColour(wxColour(50, 60, 75));
}