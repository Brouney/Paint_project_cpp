///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* Window;
	Window = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* Workspace;
	Workspace = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* Tools;
	Tools = new wxBoxSizer( wxVERTICAL );
	
	Tools->SetMinSize( wxSize( 150,-1 ) ); 
	wxBoxSizer* listSizer;
	listSizer = new wxBoxSizer( wxVERTICAL );
	
	shapeListControl = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( -1,400 ), 0, NULL, 0 ); 
	shapeListControl->SetMinSize( wxSize( -1,150 ) );
	
	listSizer->Add( shapeListControl, 0, wxALL, 5 );
	
	
	Tools->Add( listSizer, 1, wxEXPAND, 5 );
	
	
	Workspace->Add( Tools, 0, wxEXPAND, 5 );
	
	wxBoxSizer* DrawingPanel;
	DrawingPanel = new wxBoxSizer( wxVERTICAL );
	
	drawingPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	drawingPanel->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	
	DrawingPanel->Add( drawingPanel, 1, wxALL|wxEXPAND, 5 );
	
	
	Workspace->Add( DrawingPanel, 12, wxEXPAND, 5 );
	
	wxBoxSizer* Info;
	Info = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* colorSizer;
	colorSizer = new wxBoxSizer( wxHORIZONTAL );
	
	fillColorTxt = new wxStaticText( this, wxID_ANY, wxT("Fill Color"), wxDefaultPosition, wxDefaultSize, 0 );
	fillColorTxt->Wrap( -1 );
	colorSizer->Add( fillColorTxt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	fillColorPicker = new wxColourPickerCtrl( this, wxID_ANY, *wxBLACK, wxDefaultPosition, wxDefaultSize, wxCLRP_DEFAULT_STYLE );
	colorSizer->Add( fillColorPicker, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	Info->Add( colorSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* rotationSizer;
	rotationSizer = new wxBoxSizer( wxHORIZONTAL );
	
	rotationAngle = new wxStaticText( this, wxID_ANY, wxT("Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	rotationAngle->Wrap( -1 );
	rotationSizer->Add( rotationAngle, 0, wxALL, 5 );
	
	rotationAngleTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	rotationSizer->Add( rotationAngleTextControl, 0, wxALL, 5 );
	
	rotationXPos = new wxStaticText( this, wxID_ANY, wxT("RotX"), wxDefaultPosition, wxDefaultSize, 0 );
	rotationXPos->Wrap( -1 );
	rotationSizer->Add( rotationXPos, 0, wxALL, 5 );
	
	rotationXPosTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	rotationSizer->Add( rotationXPosTextCtrl, 0, wxALL, 5 );
	
	rotationYPos = new wxStaticText( this, wxID_ANY, wxT("RotY"), wxDefaultPosition, wxDefaultSize, 0 );
	rotationYPos->Wrap( -1 );
	rotationSizer->Add( rotationYPos, 0, wxALL, 5 );
	
	rotationYPosTextCtrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	rotationSizer->Add( rotationYPosTextCtrl, 0, wxALL, 5 );
	
	
	Info->Add( rotationSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* xylSizer;
	xylSizer = new wxBoxSizer( wxHORIZONTAL );
	
	xlTxt = new wxStaticText( this, wxID_ANY, wxT("XL"), wxDefaultPosition, wxDefaultSize, 0 );
	xlTxt->Wrap( -1 );
	xylSizer->Add( xlTxt, 0, wxALL, 5 );
	
	xlTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	xylSizer->Add( xlTextControl, 0, wxALL, 5 );
	
	ylTxt = new wxStaticText( this, wxID_ANY, wxT("YL"), wxDefaultPosition, wxDefaultSize, 0 );
	ylTxt->Wrap( -1 );
	xylSizer->Add( ylTxt, 0, wxALL, 5 );
	
	ylTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	xylSizer->Add( ylTextControl, 0, wxALL, 5 );
	
	
	Info->Add( xylSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* xyrSizer;
	xyrSizer = new wxBoxSizer( wxHORIZONTAL );
	
	xrTxt = new wxStaticText( this, wxID_ANY, wxT("XR"), wxDefaultPosition, wxDefaultSize, 0 );
	xrTxt->Wrap( -1 );
	xrTxt->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_APPWORKSPACE ) );
	
	xyrSizer->Add( xrTxt, 0, wxALL, 5 );
	
	xrTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	xyrSizer->Add( xrTextControl, 0, wxALL, 5 );
	
	yrTxt = new wxStaticText( this, wxID_ANY, wxT("YR"), wxDefaultPosition, wxDefaultSize, 0 );
	yrTxt->Wrap( -1 );
	xyrSizer->Add( yrTxt, 0, wxALL, 5 );
	
	yrTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	xyrSizer->Add( yrTextControl, 0, wxALL, 5 );
	
	
	Info->Add( xyrSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* xySizer;
	xySizer = new wxBoxSizer( wxHORIZONTAL );
	
	xTxt = new wxStaticText( this, wxID_ANY, wxT("X"), wxDefaultPosition, wxDefaultSize, 0 );
	xTxt->Wrap( -1 );
	xySizer->Add( xTxt, 0, wxALL, 5 );
	
	xCenterTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	xySizer->Add( xCenterTextControl, 0, wxALL, 5 );
	
	yTxt = new wxStaticText( this, wxID_ANY, wxT("Y"), wxDefaultPosition, wxDefaultSize, 0 );
	yTxt->Wrap( -1 );
	xySizer->Add( yTxt, 0, wxALL, 5 );
	
	yCenterTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	xySizer->Add( yCenterTextControl, 0, wxALL, 5 );
	
	
	Info->Add( xySizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* radiusSizer;
	radiusSizer = new wxBoxSizer( wxHORIZONTAL );
	
	radiusTxt = new wxStaticText( this, wxID_ANY, wxT("Radius"), wxDefaultPosition, wxDefaultSize, 0 );
	radiusTxt->Wrap( -1 );
	radiusSizer->Add( radiusTxt, 0, wxALL, 5 );
	
	radiusTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	radiusSizer->Add( radiusTextControl, 1, wxALL, 5 );
	
	
	Info->Add( radiusSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* ellipseSizer;
	ellipseSizer = new wxBoxSizer( wxHORIZONTAL );
	
	ellipseRadiusxTxt = new wxStaticText( this, wxID_ANY, wxT("Radius X"), wxDefaultPosition, wxDefaultSize, 0 );
	ellipseRadiusxTxt->Wrap( -1 );
	ellipseSizer->Add( ellipseRadiusxTxt, 0, wxALL, 5 );
	
	radiusxTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	ellipseSizer->Add( radiusxTextControl, 0, wxALL, 5 );
	
	ellipseRadiusyTxt = new wxStaticText( this, wxID_ANY, wxT("Radius Y"), wxDefaultPosition, wxDefaultSize, 0 );
	ellipseRadiusyTxt->Wrap( -1 );
	ellipseSizer->Add( ellipseRadiusyTxt, 0, wxALL, 5 );
	
	radiusyTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	ellipseSizer->Add( radiusyTextControl, 0, wxALL, 5 );
	
	
	Info->Add( ellipseSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	wxBoxSizer* arcSizer;
	arcSizer = new wxBoxSizer( wxHORIZONTAL );
	
	beginAngleTxt = new wxStaticText( this, wxID_ANY, wxT("Begin Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	beginAngleTxt->Wrap( -1 );
	arcSizer->Add( beginAngleTxt, 0, wxALL, 5 );
	
	beginAngleTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	arcSizer->Add( beginAngleTextControl, 0, wxALL, 5 );
	
	endAngleTxt = new wxStaticText( this, wxID_ANY, wxT("End Angle"), wxDefaultPosition, wxDefaultSize, 0 );
	endAngleTxt->Wrap( -1 );
	arcSizer->Add( endAngleTxt, 0, wxALL, 5 );
	
	endAngleTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 50,25 ), 0 );
	arcSizer->Add( endAngleTextControl, 0, wxALL, 5 );
	
	
	Info->Add( arcSizer, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	Workspace->Add( Info, 0, wxEXPAND, 5 );
	
	
	Window->Add( Workspace, 15, wxEXPAND, 5 );
	
	wxBoxSizer* CommandLine;
	CommandLine = new wxBoxSizer( wxHORIZONTAL );
	
	commandLineTextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	commandLineTextControl->SetForegroundColour( wxColour( 255, 255, 255 ) );
	commandLineTextControl->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	
	CommandLine->Add( commandLineTextControl, 1, wxALL|wxEXPAND, 5 );
	
	commandLineTxt = new wxStaticText( this, wxID_ANY, wxT("X: 0.000 Y: 0.000"), wxDefaultPosition, wxDefaultSize, 0 );
	commandLineTxt->Wrap( -1 );
	CommandLine->Add( commandLineTxt, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	Window->Add( CommandLine, 0, wxALIGN_BOTTOM|wxEXPAND, 5 );
	
	
	this->SetSizer( Window );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	File = new wxMenu();
	wxMenuItem* openFile;
	openFile = new wxMenuItem( File, wxID_ANY, wxString( wxT("Open File") ) , wxEmptyString, wxITEM_NORMAL );
	File->Append( openFile );
	
	wxMenuItem* saveFile;
	saveFile = new wxMenuItem( File, wxID_ANY, wxString( wxT("Save File") ) , wxEmptyString, wxITEM_NORMAL );
	File->Append( saveFile );
	
	wxMenuItem* saveImage;
	saveImage = new wxMenuItem( File, wxID_ANY, wxString( wxT("Save as image") ) , wxEmptyString, wxITEM_NORMAL );
	File->Append( saveImage );
	
	m_menubar1->Append( File, wxT("File") ); 
	
	Edit = new wxMenu();
	wxMenuItem* clear;
	clear = new wxMenuItem( Edit, wxID_ANY, wxString( wxT("Clear") ) , wxEmptyString, wxITEM_NORMAL );
	Edit->Append( clear );
	
	wxMenuItem* range;
	range = new wxMenuItem( Edit, wxID_ANY, wxString( wxT("Range") ) , wxEmptyString, wxITEM_NORMAL );
	Edit->Append( range );
	
	m_menubar1->Append( Edit, wxT("Edit") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	m_toolBar1 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar1->Realize(); 
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	shapeListControl->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrame::shapeListItemSelected ), NULL, this );
	shapeListControl->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MainFrame::shapeListOnRightDown ), NULL, this );
	drawingPanel->Connect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::OnMouseMoved ), NULL, this );
	drawingPanel->Connect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), NULL, this );
	drawingPanel->Connect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnResizeDrawingPanel ), NULL, this );
	drawingPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::DrawingPanelRepaint ), NULL, this );
	commandLineTextControl->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnCommandEnter ), NULL, this );
	this->Connect( openFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::openFileMenuItemSelected ) );
	this->Connect( saveFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::saveFileMenuItemSelected ) );
	this->Connect( saveImage->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::saveImageMenuItemSelected ) );
	this->Connect( clear->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::clearMenuItemSelected ) );
	this->Connect( range->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::rangeMenuItemSelected ) );
}

MainFrame::~MainFrame()
{
	// Disconnect Events
	shapeListControl->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( MainFrame::shapeListItemSelected ), NULL, this );
	shapeListControl->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( MainFrame::shapeListOnRightDown ), NULL, this );
	drawingPanel->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MainFrame::OnMouseMoved ), NULL, this );
	drawingPanel->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MainFrame::OnPaint ), NULL, this );
	drawingPanel->Disconnect( wxEVT_SIZE, wxSizeEventHandler( MainFrame::OnResizeDrawingPanel ), NULL, this );
	drawingPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MainFrame::DrawingPanelRepaint ), NULL, this );
	commandLineTextControl->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MainFrame::OnCommandEnter ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::openFileMenuItemSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::saveFileMenuItemSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::saveImageMenuItemSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::clearMenuItemSelected ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::rangeMenuItemSelected ) );
	
}

RangeDialog::RangeDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* rangeDialogSizer;
	rangeDialogSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* rangeTitleSizer;
	rangeTitleSizer = new wxBoxSizer( wxVERTICAL );
	
	rangeTitleTxt = new wxStaticText( this, wxID_ANY, wxT("Range:"), wxDefaultPosition, wxDefaultSize, 0 );
	rangeTitleTxt->Wrap( -1 );
	rangeTitleSizer->Add( rangeTitleTxt, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	rangeDialogSizer->Add( rangeTitleSizer, 0, wxEXPAND, 5 );
	
	wxBoxSizer* rangex0y0Sizer;
	rangex0y0Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	rangex0Txt = new wxStaticText( this, wxID_ANY, wxT("x0:"), wxDefaultPosition, wxDefaultSize, 0 );
	rangex0Txt->Wrap( -1 );
	rangex0y0Sizer->Add( rangex0Txt, 0, wxALL, 5 );
	
	rangex0TextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rangex0y0Sizer->Add( rangex0TextControl, 0, wxALL, 5 );
	
	rangey0Txt = new wxStaticText( this, wxID_ANY, wxT("y0:"), wxDefaultPosition, wxDefaultSize, 0 );
	rangey0Txt->Wrap( -1 );
	rangex0y0Sizer->Add( rangey0Txt, 0, wxALL, 5 );
	
	rangey0TextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rangex0y0Sizer->Add( rangey0TextControl, 0, wxALL, 5 );
	
	
	rangeDialogSizer->Add( rangex0y0Sizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rangex1y1Sizer;
	rangex1y1Sizer = new wxBoxSizer( wxHORIZONTAL );
	
	rangex1Txt = new wxStaticText( this, wxID_ANY, wxT("x1:"), wxDefaultPosition, wxDefaultSize, 0 );
	rangex1Txt->Wrap( -1 );
	rangex1y1Sizer->Add( rangex1Txt, 0, wxALL, 5 );
	
	rangex1TextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rangex1y1Sizer->Add( rangex1TextControl, 0, wxALL, 5 );
	
	rangey1Txt = new wxStaticText( this, wxID_ANY, wxT("y1:"), wxDefaultPosition, wxDefaultSize, 0 );
	rangey1Txt->Wrap( -1 );
	rangex1y1Sizer->Add( rangey1Txt, 0, wxALL, 5 );
	
	rangey1TextControl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	rangex1y1Sizer->Add( rangey1TextControl, 0, wxALL, 5 );
	
	
	rangeDialogSizer->Add( rangex1y1Sizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* rangeButtonsSizer;
	rangeButtonsSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* rangeOkButtonSizer;
	rangeOkButtonSizer = new wxBoxSizer( wxVERTICAL );
	
	rangeOkButton = new wxButton( this, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	rangeOkButtonSizer->Add( rangeOkButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	rangeButtonsSizer->Add( rangeOkButtonSizer, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* rangeCloseButtonSizer;
	rangeCloseButtonSizer = new wxBoxSizer( wxVERTICAL );
	
	rangeCloseButton = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	rangeCloseButtonSizer->Add( rangeCloseButton, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	rangeButtonsSizer->Add( rangeCloseButtonSizer, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	rangeDialogSizer->Add( rangeButtonsSizer, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( rangeDialogSizer );
	this->Layout();
	rangeDialogSizer->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	rangeOkButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RangeDialog::AcceptRangeDialog ), NULL, this );
	rangeCloseButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RangeDialog::CloseRangeDialog ), NULL, this );
}

RangeDialog::~RangeDialog()
{
	// Disconnect Events
	rangeOkButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RangeDialog::AcceptRangeDialog ), NULL, this );
	rangeCloseButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( RangeDialog::CloseRangeDialog ), NULL, this );
	
}
