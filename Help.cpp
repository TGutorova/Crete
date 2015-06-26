//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Help.h"
#include "Main.h"
#include "Data.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvPanel"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxListBox"
#pragma link "cxMemo"
#pragma link "cxTextEdit"
#pragma link "cxRichEdit"
#pragma resource "*.dfm"
TFormHelp *FormHelp;
//---------------------------------------------------------------------------
__fastcall TFormHelp::TFormHelp(TComponent* Owner) : TForm(Owner) { }
//---------------------------------------------------------------------------

void __fastcall TFormHelp::FormShow(TObject *Sender)
{
  PanelErrType->Caption = FormMain->ComboBoxTypeErrOp->Text;

  RichEditHelp->Lines->Clear();

  DataSt->ErrHelp->Active = false;
  DataSt->ErrHelp->CommandText = "select * from Q_CheckError (nolock) where code=:code";
  DataSt->ErrHelp->Parameters->ParamByName("code")->Value = FormMain->mskErrOper[FormMain->ComboBoxTypeErrOp->ItemIndex];
  DataSt->ErrHelp->Active = true;

  if (DataSt->ErrHelp->RecordCount)
  {
    RichEditHelp->Lines->Assign(DataSt->ErrHelp->FieldByName("Description"));
  }
}
//---------------------------------------------------------------------------
