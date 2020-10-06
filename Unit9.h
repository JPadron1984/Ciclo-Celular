//---------------------------------------------------------------------------

#ifndef Unit9H
#define Unit9H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <FStream.h>

//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TOpenDialog *OpenDialog1;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

float W,H,n,m;

float *datos1;
float *datos2;

float fmaximo (float *lista,int k);
float fminimo (float *lista,int k);
float integral(float *dato, int I,int k);

void Areagrafica();

void Graficar (float * dato,int k);

TRect R;


	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
