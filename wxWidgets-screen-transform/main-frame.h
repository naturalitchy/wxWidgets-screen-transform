#ifndef main_frame_h
#define main_frame_h

#include <wx/wx.h>

class MainFrame : public wxFrame {
	private:

	public:
		MainFrame(const wxString &title);

		// Setting the basic panel.
		wxPanel *contentTop;
		wxPanel *contentMenu;
		wxPanel *contentGameList;
		wxPanel *contentDofTest;
		
		// Setting the basic sizer.
		wxBoxSizer *sizerMain;				// Main Sizer.
		wxBoxSizer *sizerTop;				// Top position Sizer.
		wxBoxSizer *sizerMenu;				// Left position(Menu Bar) Sizer.
		wxBoxSizer *sizerContent;			// Middle position Sizer. (Add sizerMenu + Right position)
		wxBoxSizer *sizerGameListInner;		// Right position(Game List design) Sizer.
		wxBoxSizer *sizerGameList;			// Right position(Game List) Sizer. (Add sizerGameListInner)
		wxBoxSizer *sizerDofTestInner;		// Right position(6DOF Test design) Sizer.
		wxBoxSizer *sizerDofTest;			// Right position(6DOF Test) Sizer. (Add sizerDofTestInner)
		

};

#endif