// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;

// ---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner) : TForm(Owner) {
	datos1 = new float[20000];
	datos2 = new float[20000];

	Edit1->Text="";
	Edit2->Text="";
	Edit3->Text="";

	Edit4->Text="";
	Edit5->Text="";
	Edit6->Text="";
}

// ---------------------------------------------------------------------------
void __fastcall TForm9::Button1Click(TObject *Sender) {
	fstream fin; // declaracion de variable tipo fstream

	if (OpenDialog1->Execute()) // condicion ejecutar opendialog
	{
		AnsiString Fila = OpenDialog1->FileName;
		// declaracion de variable ansistring

		char * filename = Fila.c_str(); // declaracion de lista tipo char con el nombre de archivo y ubicacion a traves de la variable Fila

		fin.open(filename); // Posicionando sobre el archivo
		fin >> n; // Primer valor que seria de la cantidad de lineas se guarda en n


		for (int i = 0; i < (n/2); i++) {
			fin >>datos1[i]; // carga de datos del archivo en la lista en la posicion i
		}

		for (int i = 0; i < (n/2); i++) {
			fin>>datos2[i];
		}
		fin.close(); // cierre archivo
	}




	R = Bevel1->BoundsRect;
	Areagrafica();
	Graficar(datos1, n/2);

	Edit1->Text=integral(datos1,0,(n/2));
	Edit2->Text=integral(datos1,(n/4),(n/2));
	Edit3->Text=((integral(datos1,(n/4),(n/2)))/(integral(datos1,0,(n/2))));



	R = Bevel2->BoundsRect;
	Areagrafica();
	Graficar(datos2, n/2);

	Edit4->Text=integral(datos2,0,(n/2));
	Edit5->Text=integral(datos2,(n/4),(n/2));
	Edit6->Text=((integral(datos2,(n/4),(n/2)))/(integral(datos2,0,(n/2))));




}

// ---------------------------------------------------------------------------
void TForm9::Graficar(float * dato, int k) {

	int y1, y2, x1, x2, escY, escX, xoffset, yoffset;

	TPoint pts[10000];

	Canvas->Pen->Style = psSolid;
	Canvas->Pen->Width = 1;
	Canvas->Pen->Color = clBlack;

	W = R.Width()/2; // ancho del bevel1
	H = R.Height(); // alto bevel1

	escX = k*0.5; // escala en x en funcion de la cantidad de valores de la lista
	escY = fmaximo(dato, k) - fminimo(dato, k); // escala en y en funcion del valor mas alto en la lista

	xoffset = R.Left; // alineamiento en eje x
	yoffset = R.Top + H; // elineamiento en eje y

	for (int i = 0; i < k - 1; i++) {


	   y1 = (dato[i] * H) / escY; // datos[i]"valor de lista"*H"alto medio del bevel"
	   y2 = (dato[i + 1] * H) / escY; // datos[i+1]"valor siguiente de lista"
	   x1 = (i * W) / escX; // i"posicion en x"*(W/2)"punto medio del bevel"
	   x2 = ((i + 1) * W) / escX; // valor en y de la linea
	   y1 = yoffset - y1;
	   y2 = yoffset - y2;
	   x1 = x1 + xoffset;
	   x2 = x2 + xoffset;

	   Canvas->MoveTo(x1, y1);
	   Canvas->LineTo(x2, y2);
	}
	for (int i = 0; i < k; i++) {


	   y1 = (dato[i] * H) / escY; // datos[i]"valor de lista"*H"alto medio del bevel"
	   y2 = (dato[i + 1] * H) / escY; // datos[i+1]"valor siguiente de lista"
	   x1 = (i * W) / escX; // i"posicion en x"*(W/2)"punto medio del bevel"
	   x2 = ((i + 1) * W) / escX; // valor en y de la linea
	   y1 = yoffset - y1;
	   y2 = yoffset - y2;
	   x1 = x1 + xoffset;
	   x2 = x2 + xoffset;

	   pts[i]=Point(x1,y1);

	}
	   Canvas->Brush->Color=clGreen;
	   Canvas->Polygon(pts,(k-1));

	   Canvas->Brush->Color=clRed;
	   Canvas->Polygon(pts,((k-1)/2));


}
// ---------------------------------------------------------------------------
void TForm9::Areagrafica() {

	Canvas->Pen->Style = psDot; // estilo punteado de pluma
	Canvas->Pen->Width = 0.1;
	Canvas->Brush->Color = clWhite; // color blanco de pluma
	Canvas->FillRect(R); // rellenar en tamaño y posicion en relacion en R
	Canvas->Pen->Color = clGreen; // color de linea punteada

	W = R.Width(); // ancho del bevel1
	H = R.Height(); // alto bevel1

}

// ---------------------------------------------------------------------------
float TForm9::fmaximo(float *lista, int k) { // Funcion que ubica el valor maximo de una lista

	float max = lista[0];

	for (int i = 0; i < k; i++) {
		if (lista[i] > max) {
			max = lista[i];
		}

	}
	return max;
}

// ---------------------------------------------------------------------------
float TForm9::fminimo(float *lista, int k) { // Funcion que ubica el valor minimo de una lista

	float min = lista[0];

	for (int i = 0; i < k; i++) {
		if (lista[i] < min) {
			min = lista[i];
		}

	}
	return min;
}

// ---------------------------------------------------------------------------
float TForm9::integral(float *dato, int I,int k){

	float a=0;

		for (int i = I; i < k-1; i++) {
			a=a+(dato[i]*2)+((abs ((dato[i+1]-dato[i]))*2)/2);
		}
			return a;
}

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------

