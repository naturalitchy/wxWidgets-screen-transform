#ifndef main_frame_h
#define main_frame_h

#include <wx/wx.h>

class MainFrame : public wxFrame {
	private:
	void SetTopPaint(const wxEvent &evt);			// Set Top Paint.
	void SetMenuPaint(const wxEvent &evt);			// Set Menu Paint.
	void SetGameListPaint(const wxEvent &evt);		// Set Game List Paint.
	void SetDofTestPaint(const wxEvent &evt);		// Set 6DOF Test Paint

	public:
		MainFrame(const wxString &title);

		// Setting the basic panel.
		wxScrolledWindow *contentTop;
		wxScrolledWindow *contentMenu;
		wxScrolledWindow *contentGameList;
		wxScrolledWindow *contentDofTest;
		
		// Setting the basic sizer.
		wxBoxSizer *sizerMain;				// Main Sizer.
		wxBoxSizer *sizerTop;				// Top position Sizer.
		wxBoxSizer *sizerMenu;				// Left position(Menu Bar) Sizer.
		wxBoxSizer *sizerContent;			// Middle position Sizer. (Add sizerMenu + Right position)
		wxBoxSizer *sizerGameListInner;		// Right position(Game List design) Sizer.
		wxBoxSizer *sizerGameList;			// Right position(Game List) Sizer. (Add sizerGameListInner)
		wxBoxSizer *sizerDofTestInner;		// Right position(6DOF Test design) Sizer.
		wxBoxSizer *sizerDofTest;			// Right position(6DOF Test) Sizer. (Add sizerDofTestInner)
		
		// Setting the Menu button.
		wxButton *btnGameList;
		wxButton *btnDofTest;
		
		// Setting the Game List button.
		wxButton *btnAssetto;
		wxBitmapButton *btnEuroTruck;

		// Setting the 6DOF Test button.
		wxButton *btnPitchTest;
		wxButton *btnRollTest;


		// Setting the button event.
		void ShowGameList(const wxCommandEvent &evt);
		void ShowDofTest(const wxCommandEvent &evt);
		

};

#endif