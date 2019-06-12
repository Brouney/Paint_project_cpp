///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/clrpicker.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MainFrame
///////////////////////////////////////////////////////////////////////////////
class MainFrame : public wxFrame 
{
	private:
	
	protected:
		wxListBox* shapeListControl;
		wxStaticText* fillColorTxt;
		wxColourPickerCtrl* fillColorPicker;
		wxStaticText* rotationAngle;
		wxTextCtrl* rotationAngleTextControl;
		wxStaticText* rotationXPos;
		wxTextCtrl* rotationXPosTextCtrl;
		wxStaticText* rotationYPos;
		wxTextCtrl* rotationYPosTextCtrl;
		wxStaticText* xlTxt;
		wxTextCtrl* xlTextControl;
		wxStaticText* ylTxt;
		wxTextCtrl* ylTextControl;
		wxStaticText* xrTxt;
		wxTextCtrl* xrTextControl;
		wxStaticText* yrTxt;
		wxTextCtrl* yrTextControl;
		wxStaticText* xTxt;
		wxTextCtrl* xCenterTextControl;
		wxStaticText* yTxt;
		wxTextCtrl* yCenterTextControl;
		wxStaticText* radiusTxt;
		wxTextCtrl* radiusTextControl;
		wxStaticText* ellipseRadiusxTxt;
		wxTextCtrl* radiusxTextControl;
		wxStaticText* ellipseRadiusyTxt;
		wxTextCtrl* radiusyTextControl;
		wxStaticText* beginAngleTxt;
		wxTextCtrl* beginAngleTextControl;
		wxStaticText* endAngleTxt;
		wxTextCtrl* endAngleTextControl;
		wxTextCtrl* commandLineTextControl;
		wxStaticText* commandLineTxt;
		wxMenuBar* m_menubar1;
		wxMenu* File;
		wxMenu* Edit;
		wxToolBar* m_toolBar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void shapeListItemSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void shapeListOnRightDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnMouseMoved( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void OnResizeDrawingPanel( wxSizeEvent& event ) { event.Skip(); }
		virtual void DrawingPanelRepaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void OnCommandEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void openFileMenuItemSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void saveFileMenuItemSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void saveImageMenuItemSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void clearMenuItemSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void rangeMenuItemSelected( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxPanel* drawingPanel;
		
		MainFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Project #38"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1078,713 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MainFrame();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class RangeDialog
///////////////////////////////////////////////////////////////////////////////
class RangeDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* rangeTitleTxt;
		wxStaticText* rangex0Txt;
		wxStaticText* rangey0Txt;
		wxStaticText* rangex1Txt;
		wxStaticText* rangey1Txt;
		wxButton* rangeOkButton;
		wxButton* rangeCloseButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void AcceptRangeDialog( wxCommandEvent& event ) { event.Skip(); }
		virtual void CloseRangeDialog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxTextCtrl* rangex0TextControl;
		wxTextCtrl* rangey0TextControl;
		wxTextCtrl* rangex1TextControl;
		wxTextCtrl* rangey1TextControl;
		
		RangeDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~RangeDialog();
	
};

#endif //__GUI_H__
