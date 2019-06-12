#include "ProjektGFKRangeDialog.h"

ProjektGFKRangeDialog::ProjektGFKRangeDialog( wxWindow* parent )
:
RangeDialog( parent )
{

}

void ProjektGFKRangeDialog::AcceptRangeDialog( wxCommandEvent& event )
{
// TODO: Implement AcceptRangeDialog
this->EndModal(wxID_OK);
}

void ProjektGFKRangeDialog::CloseRangeDialog( wxCommandEvent& event )
{
// TODO: Implement CloseRangeDialog
this->EndModal(wxID_CANCEL);
}
