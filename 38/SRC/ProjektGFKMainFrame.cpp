#include "ProjektGFKMainFrame.h"

int Shape::lastId;

ProjektGFKMainFrame::ProjektGFKMainFrame(wxWindow* parent)
	:
	MainFrame(parent)
{
	wxInitAllImageHandlers();

	timer.Bind(wxEVT_TIMER, &ProjektGFKMainFrame::OnTimer, this);

	commandList["test"] = &ProjektGFKMainFrame::TestCmd;
	commandList["rectangle"] = &ProjektGFKMainFrame::RectangleCmd;
	commandList["fill"] = &ProjektGFKMainFrame::FillCmd;
	commandList["delete"] = &ProjektGFKMainFrame::DeleteCmd;
	commandList["range"] = &ProjektGFKMainFrame::RangeCmd;
	commandList["background"] = &ProjektGFKMainFrame::BackgroundCmd;
	commandList["line"] = &ProjektGFKMainFrame::LineCmd;
	commandList["circle"] = &ProjektGFKMainFrame::CircleCmd;
	commandList["ellipse"] = &ProjektGFKMainFrame::EllipseCmd;
	commandList["arc"] = &ProjektGFKMainFrame::ArcCmd;
	commandList["clear"] = &ProjektGFKMainFrame::ClearCmd;
	commandList["move"] = &ProjektGFKMainFrame::MoveCmd;
	commandList["rotate"] = &ProjektGFKMainFrame::RotateCmd;
	commandList["show"] = &ProjektGFKMainFrame::ShowCmd;
	commandList["save"] = &ProjektGFKMainFrame::SaveCmd;
	commandList["write"] = &ProjektGFKMainFrame::WriteCmd;
	commandList["read"] = &ProjektGFKMainFrame::ReadCmd;

	cmdBuffer = "clear\n";
}

void ProjektGFKMainFrame::shapeListItemSelected(wxCommandEvent& event)
{
	// TODO: Implement shapeListItemSelected
	std::string selectedId = shapeListControl->GetString(shapeListControl->GetSelection());

	for (Shape* shape : shapes)
	{
		if (shape->GetIdText() == selectedId)
		{
			selectedShape = shape;
			fillColorPicker->SetColour(selectedShape->color);
			break;
		}
	}
}

void ProjektGFKMainFrame::shapeListOnRightDown(wxMouseEvent& event)
{
	// TODO: Implement shapeListOnRightDown
	wxMenu popupMenu;

	popupMenu.Append(999, "Delete");

	popupMenu.Bind(wxEVT_COMMAND_MENU_SELECTED, &ProjektGFKMainFrame::DeleteMenu, this, 999, 999);
	PopupMenu(&popupMenu);
}

void ProjektGFKMainFrame::OnMouseMoved(wxMouseEvent& event)
{
	// TODO: Implement OnMouseMoved
	long x, y;
	event.GetPosition(&x, &y);

	int w, h;
	drawingPanel->GetSize(&w, &h);
	double Sx = (double)w / (x1 - x0);
	double Sy = (double)h / (y1 - y0);

	double X, Y;
	X = (double)x / Sx + x0;
	Y = (double)y / Sy + y0;

	X = floor(100 * X) / 100;
	Y = floor(100 * Y) / 100;

	std::string xStr = std::to_string(X);
	xStr.erase(xStr.begin() + 4, xStr.end());
	std::string yStr = std::to_string(Y);
	yStr.erase(yStr.begin() + 4, yStr.end());

	commandLineTxt->SetLabelText("X: " + xStr + " Y: " + yStr);
}

void ProjektGFKMainFrame::OnPaint(wxPaintEvent& event)
{
	// TODO: Implement OnPaint
	Repaint();
}

void ProjektGFKMainFrame::OnResizeDrawingPanel(wxSizeEvent& event)
{
	// TODO: Implement OnResizeDrawingPanel
	Repaint();
}

void ProjektGFKMainFrame::DrawingPanelRepaint(wxUpdateUIEvent& event)
{
	// TODO: Implement DrawingPanelRepaint
	Repaint();
	UpdateShapeProperties();
}

void ProjektGFKMainFrame::OnCommandEnter(wxCommandEvent& event)
{
	// TODO: Implement OnCommandEnter
	std::string cmdLine = commandLineTextControl->GetValue();

	ParseCommand(cmdLine);
	commandLineTextControl->Clear();
}

void ProjektGFKMainFrame::openFileMenuItemSelected(wxCommandEvent& event)
{
	// TODO: Implement openFileMenuItemSelected
	wxFileDialog dialog(this, _("Load file"), "", "", "Any extension (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

	if (dialog.ShowModal() == wxID_OK)
	{
		this->Refresh();
		wxString path = dialog.GetPath().ToAscii();
		std::ifstream file(path.ToStdString());
		std::string str;

		while (std::getline(file, str))
		{
			ParseCommand(str);
		}
	}
}

void ProjektGFKMainFrame::saveFileMenuItemSelected(wxCommandEvent& event)
{
	// TODO: Implement saveFileMenuItemSelected
	wxFileDialog dialog(this, _("Save file"), "", "", "", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (dialog.ShowModal() == wxID_OK)
	{
		this->Refresh();
		wxString path = dialog.GetPath() + dialog.GetName();
		std::ofstream file(path.ToStdString());
		file << cmdBuffer;
		file.close();
	}
}

void ProjektGFKMainFrame::saveImageMenuItemSelected(wxCommandEvent& event)
{
	// TODO: Implement saveImageMenuItemSelected
	wxFileDialog dialog(this, _("Save image"), "", "", "png files (*.png)|*.png", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (dialog.ShowModal() == wxID_OK)
	{
		this->Refresh();
		wxString path = dialog.GetPath() + dialog.GetName();

		int w, h;
		drawingPanel->GetSize(&w, &h);
		screenBufferImg = screenBufferImg.Rescale(w, h);
		screenBufferImg.SaveFile(path);
	}
}

void ProjektGFKMainFrame::clearMenuItemSelected(wxCommandEvent& event)
{
	// TODO: Implement clearMenuItemSelected
	ParseCommand("clear");
}

void ProjektGFKMainFrame::rangeMenuItemSelected(wxCommandEvent& event)
{
	// TODO: Implement rangeMenuItemSelected
	ProjektGFKRangeDialog rangeDlg(this);
	if (rangeDlg.ShowModal() == wxID_OK)
	{
		x0 = atof(std::string(rangeDlg.rangex0TextControl->GetValue()).c_str());
		y0 = atof(std::string(rangeDlg.rangey0TextControl->GetValue()).c_str());
		x1 = atof(std::string(rangeDlg.rangex1TextControl->GetValue()).c_str());
		y1 = atof(std::string(rangeDlg.rangey1TextControl->GetValue()).c_str());

		UpdatePanelSize();
	}
}


void ProjektGFKMainFrame::UpdateShapeList()
{
	int selection = shapeListControl->GetSelection();
	shapeListControl->Clear();

	for (int i = 0; i < shapes.size(); i++)
	{
		shapeListControl->Insert(shapes[i]->GetIdText(), i);
	}

	if (shapes.size() > 0)
	{
		if (shapes.size() > selection)
			shapeListControl->Select(selection);
	}
}

void ProjektGFKMainFrame::RotateCmd(std::vector<std::string> args)
{
	if (args.size() >= 4)
	{
		std::string id = args[0];

		double x = atof(args[1].c_str());
		double y = atof(args[2].c_str());
		double angle = atof(args[3].c_str());

		for (Shape* shape : shapes)
		{
			if (id == "all")
			{
				shape->Rotate(angle, x, y);
			}
			else if (shape->GetId() == id)
			{
				shape->Rotate(angle, x, y);
			}
		}
	}
}

void ProjektGFKMainFrame::ClearCmd(std::vector<std::string> args)
{
	std::vector<std::string> deleteArgs;
	deleteArgs.insert(deleteArgs.end(), "all");

	std::vector<std::string> rangeArgs;
	rangeArgs.insert(rangeArgs.end(), "0");
	rangeArgs.insert(rangeArgs.end(), "0");
	rangeArgs.insert(rangeArgs.end(), "1");
	rangeArgs.insert(rangeArgs.end(), "1");

	DeleteCmd(deleteArgs);
	RangeCmd(rangeArgs);

	Shape::lastId = 0;

	cmdBuffer = "clear\n";
}

void ProjektGFKMainFrame::DeleteCmd(std::vector<std::string> args)
{
	if (args.size() >= 1)
	{
		std::string id = args[0];

		for (int i = 0; i < shapes.size(); i++)
		{
			if (id == "all")
			{
				selectedShape = nullptr;
				delete shapes[i];
				shapes.erase(shapes.begin() + i);
				i--;
				UpdateShapeList();
			}
			else if (shapes[i]->GetId() == id)
			{
				if (selectedShape == shapes[i])
					selectedShape = nullptr;

				delete shapes[i];
				shapes.erase(shapes.begin() + i);
				i--;
				UpdateShapeList();
			}
		}
	}
}

void ProjektGFKMainFrame::ArcCmd(std::vector<std::string> args)
{
	if (args.size() >= 6)
	{
		double x = atof(args[0].c_str());
		double y = atof(args[1].c_str());
		double rx = atof(args[2].c_str());
		double ry = atof(args[3].c_str());
		double b = atof(args[4].c_str());
		double e = atof(args[5].c_str());

		ArcShape* newShape = new ArcShape(x, y, rx, ry, b, e);

		shapes.insert(shapes.end(), newShape);
		UpdateShapeList();
		UpdatePanelSize();
	}
}

void ProjektGFKMainFrame::DeleteMenu(wxCommandEvent& event)
{
	std::string deleteCmd = "delete " + selectedShape->GetId();
	ParseCommand(deleteCmd);
}

void ProjektGFKMainFrame::CircleCmd(std::vector<std::string> args)
{
	if (args.size() >= 4)
	{
		double x = atof(args[0].c_str());
		double y = atof(args[1].c_str());
		double r = atof(args[2].c_str());

		wxColor color;
		color.Set(args[3]);

		CircleShape* newShape = new CircleShape(x, y, r, color);

		shapes.insert(shapes.end(), newShape);
		UpdateShapeList();
		UpdatePanelSize();
	}
}

void ProjektGFKMainFrame::MoveCmd(std::vector<std::string> args)
{
	if (args.size() >= 3)
	{
		std::string id = args[0];

		double x = atof(args[1].c_str());
		double y = atof(args[2].c_str());

		for (int i = 0; i < shapes.size(); i++)
		{
			if (id == "all")
			{
				shapes[i]->Move(x, y);
			}
			else if (shapes[i]->GetId() == id)
			{
				shapes[i]->Move(x, y);
			}
		}
	}
}

void ProjektGFKMainFrame::UpdateShapeProperties()
{
	if (shapes.size() > 0)
	{
		if (!selectedShape)
		{
			selectedShape = shapes[0];
			shapeListControl->Select(0);
			fillColorPicker->SetColour(selectedShape->color);
		}

		RectangleShape* rectangle = dynamic_cast<RectangleShape*>(selectedShape);

		if (rectangle)
		{
			xlTextControl->SetValue(std::to_string(rectangle->xl));
			ylTextControl->SetValue(std::to_string(rectangle->yl));
			xrTextControl->SetValue(std::to_string(rectangle->xr));
			yrTextControl->SetValue(std::to_string(rectangle->yr));

			rotationAngleTextControl->SetValue(std::to_string(rectangle->rotateAngle));
			rotationXPosTextCtrl->SetValue(std::to_string(rectangle->rotateX));
			rotationYPosTextCtrl->SetValue(std::to_string(rectangle->rotateY));

			xCenterTextControl->SetValue("");
			yCenterTextControl->SetValue("");
			radiusTextControl->SetValue("");

			radiusxTextControl->SetValue("");
			radiusyTextControl->SetValue("");

			beginAngleTextControl->SetValue("");
			endAngleTextControl->SetValue("");

			return;
		}

		LineShape* line = dynamic_cast<LineShape*>(selectedShape);

		if (line)
		{
			xlTextControl->SetValue(std::to_string(line->xl));
			ylTextControl->SetValue(std::to_string(line->yl));
			xrTextControl->SetValue(std::to_string(line->xr));
			yrTextControl->SetValue(std::to_string(line->yr));

			rotationAngleTextControl->SetValue(std::to_string(line->rotateAngle));
			rotationXPosTextCtrl->SetValue(std::to_string(line->rotateX));
			rotationYPosTextCtrl->SetValue(std::to_string(line->rotateY));

			xCenterTextControl->SetValue("");
			yCenterTextControl->SetValue("");
			radiusTextControl->SetValue("");

			radiusxTextControl->SetValue("");
			radiusyTextControl->SetValue("");

			beginAngleTextControl->SetValue("");
			endAngleTextControl->SetValue("");

			return;
		}

		CircleShape* circle = dynamic_cast<CircleShape*>(selectedShape);

		if (circle)
		{
			xCenterTextControl->SetValue(std::to_string(circle->x));
			yCenterTextControl->SetValue(std::to_string(circle->y));

			rotationAngleTextControl->SetValue(std::to_string(circle->rotateAngle));
			rotationXPosTextCtrl->SetValue(std::to_string(circle->rotateX));
			rotationYPosTextCtrl->SetValue(std::to_string(circle->rotateY));

			radiusTextControl->SetValue(std::to_string(circle->r));

			xlTextControl->SetValue("");
			ylTextControl->SetValue("");
			xrTextControl->SetValue("");
			yrTextControl->SetValue("");

			radiusxTextControl->SetValue("");
			radiusyTextControl->SetValue("");

			beginAngleTextControl->SetValue("");
			endAngleTextControl->SetValue("");

			return;
		}

		EllipseShape* ellipse = dynamic_cast<EllipseShape*>(selectedShape);

		if (ellipse)
		{
			xCenterTextControl->SetValue(std::to_string(ellipse->x));
			xCenterTextControl->SetValue(std::to_string(ellipse->y));

			rotationAngleTextControl->SetValue(std::to_string(ellipse->rotateAngle));
			rotationXPosTextCtrl->SetValue(std::to_string(ellipse->rotateX));
			rotationYPosTextCtrl->SetValue(std::to_string(ellipse->rotateY));

			radiusxTextControl->SetValue(std::to_string(ellipse->rx));
			radiusyTextControl->SetValue(std::to_string(ellipse->ry));

			xlTextControl->SetValue("");
			ylTextControl->SetValue("");
			xrTextControl->SetValue("");
			yrTextControl->SetValue("");

			radiusTextControl->SetValue("");

			return;
		}

		ArcShape* arc = dynamic_cast<ArcShape*>(selectedShape);

		if (arc)
		{
			xCenterTextControl->SetValue(std::to_string(arc->x));
			yCenterTextControl->SetValue(std::to_string(arc->y));

			rotationAngleTextControl->SetValue(std::to_string(arc->rotateAngle));
			rotationXPosTextCtrl->SetValue(std::to_string(arc->rotateX));
			rotationYPosTextCtrl->SetValue(std::to_string(arc->rotateY));

			radiusxTextControl->SetValue(std::to_string(arc->rx));
			radiusyTextControl->SetValue(std::to_string(arc->ry));

			beginAngleTextControl->SetValue(std::to_string(arc->beginAngle));
			endAngleTextControl->SetValue(std::to_string(arc->endAngle));

			xlTextControl->SetValue("");
			ylTextControl->SetValue("");
			xrTextControl->SetValue("");
			yrTextControl->SetValue("");

			radiusTextControl->SetValue("");

			return;
		}
	}
	else
	{
		selectedShape = nullptr;

		rotationAngleTextControl->SetValue("");
		rotationXPosTextCtrl->SetValue("");
		rotationYPosTextCtrl->SetValue("");

		xlTextControl->SetValue("");
		ylTextControl->SetValue("");
		xrTextControl->SetValue("");
		yrTextControl->SetValue("");

		xCenterTextControl->SetValue("");
		yCenterTextControl->SetValue("");
		radiusTextControl->SetValue("");

		radiusxTextControl->SetValue("");
		radiusyTextControl->SetValue("");

		beginAngleTextControl->SetValue("");
		endAngleTextControl->SetValue("");
	}
}

void ProjektGFKMainFrame::EllipseCmd(std::vector<std::string> args)
{
	if (args.size() >= 5)
	{
		double x = atof(args[0].c_str());
		double y = atof(args[1].c_str());
		double rx = atof(args[2].c_str());
		double ry = atof(args[3].c_str());

		wxColor color;
		color.Set(args[4]);

		EllipseShape* newShape = new EllipseShape(x, y, rx, ry, color);

		shapes.insert(shapes.end(), newShape);
		UpdateShapeList();
		UpdatePanelSize();
	}
}

void ProjektGFKMainFrame::LineCmd(std::vector<std::string> args)
{
	if (args.size() >= 5)
	{
		double xl = atof(args[0].c_str());
		double yl = atof(args[1].c_str());
		double xr = atof(args[2].c_str());
		double yr = atof(args[3].c_str());

		wxColor color;
		color.Set(args[4]);

		LineShape* newShape = new LineShape(xl, yl, xr, yr, color);

		shapes.insert(shapes.end(), newShape);
		UpdateShapeList();
		UpdatePanelSize();
	}
}

void ProjektGFKMainFrame::SaveCmd(std::vector<std::string> args)
{
	if (args.size() >= 3)
	{
		double w = atof(args[0].c_str());
		double h = atof(args[1].c_str());
		std::string name = args[2];

		screenBufferImg = screenBufferImg.Rescale(w, h);

		screenBufferImg.SaveFile(name);
	}
}

void ProjektGFKMainFrame::RangeCmd(std::vector<std::string> args)
{
	if (args.size() >= 4)
	{
		x0 = atof(args[0].c_str());
		y0 = atof(args[1].c_str());
		x1 = atof(args[2].c_str());
		y1 = atof(args[3].c_str());

		UpdatePanelSize();
	}
}

void ProjektGFKMainFrame::ReadCmd(std::vector<std::string> args)
{
	if (args.size() >= 1)
	{
		std::string name = args[0];

		std::ifstream file(name);
		std::string str;

		while (std::getline(file, str))
		{
			ParseCommand(str);
		}
	}
}

void ProjektGFKMainFrame::WriteCmd(std::vector<std::string> args)
{
	if (args.size() == 1)
	{
		std::string name = args[0];

		std::ofstream file(name);
		file << cmdBuffer;
		file.close();
	}
}

void ProjektGFKMainFrame::ShowCmd(std::vector<std::string> args)
{
	if (args.size() >= 1)
	{
		std::string id = args[0];

		for (Shape* shape : shapes)
		{
			if (id == "all")
			{
				shape->Show(timer);
			}
			else if (shape->GetId() == id)
			{
				shape->Show(timer);
			}
		}
	}
}

void ProjektGFKMainFrame::FillCmd(std::vector<std::string> args)
{
	if (args.size() >= 2)
	{
		std::string id = args[0];
		wxColor color;
		color.Set(args[1]);

		for (Shape* shape : shapes)
		{
			if (id == "all")
			{
				shape->Fill(color);
			}
			else if (shape->GetId() == id)
			{
				shape->Fill(color);
			}
		}

		fillColorPicker->SetColour(selectedShape->color);
	}
}

void ProjektGFKMainFrame::UpdatePanelSize()
{
	for (Shape* shape : shapes)
	{
		shape->UpdatePanelSize(x0, y0, x1, y1);
	}
}

void ProjektGFKMainFrame::BackgroundCmd(std::vector<std::string> args)
{
	if (args.size() >= 1)
	{
		backgroundColor.Set(args[0]);
	}
}

void ProjektGFKMainFrame::RectangleCmd(std::vector<std::string> args)
{
	if (args.size() >= 5)
	{
		double xl = atof(args[0].c_str());
		double yl = atof(args[1].c_str());
		double xr = atof(args[2].c_str());
		double yr = atof(args[3].c_str());

		wxColor color;
		color.Set(args[4]);

		RectangleShape* newShape = new RectangleShape(xl, yl, xr, yr, color);

		shapes.insert(shapes.end(), newShape);
		UpdateShapeList();
		UpdatePanelSize();
	}
}

void ProjektGFKMainFrame::OnTimer(wxTimerEvent& e)
{
	for (Shape* shape : shapes)
	{
		shape->Hide();
	}
}

void ProjektGFKMainFrame::ParseCommand(std::string cmdLine)
{
	std::stringstream strstream(cmdLine);

	std::string cmdName;
	strstream >> cmdName;

	bool saveCmd = !(cmdName == "write" || cmdName == "read" || cmdName == "save");

	if (saveCmd)
		cmdBuffer += cmdName;

	std::vector<std::string> cmdArgs;
	while (strstream.good())
	{
		std::string arg;
		strstream >> arg;
		cmdArgs.insert(cmdArgs.end(), arg);

		if (saveCmd)
			cmdBuffer += " " + arg;
	}

	if (saveCmd)
		cmdBuffer += "\n";

	if (commandList.find(cmdName) != commandList.end())
	{
		(*this.*commandList[cmdName])(cmdArgs);
	}
}

void ProjektGFKMainFrame::Repaint()
{
	wxClientDC dc1(drawingPanel);

	int w = 0;
	int h = 0;
	drawingPanel->GetSize(&w, &h);
	screenBufferBitmap = wxBitmap(w, h);
	wxBufferedDC dc(&dc1, screenBufferBitmap);

	dc.Clear();
	drawingPanel->SetBackgroundColour(backgroundColor);

	for (Shape* shape : shapes)
	{
		shape->DrawShape(&dc, w, h);
	}

	screenBufferImg = screenBufferBitmap.ConvertToImage();
}

void ProjektGFKMainFrame::TestCmd(std::vector<std::string> args)
{
	args.insert(args.end(), "0.25");
	args.insert(args.end(), "0.25");
	args.insert(args.end(), "0.75");
	args.insert(args.end(), "0.75");
	args.insert(args.end(), "#ff0000");
	RectangleCmd(args);
}