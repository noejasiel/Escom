#include<iostream>
#include<conio.h>
#include<graphics.h>

#include "utils.cpp"
#include "constantes.cpp"

using namespace std;

void pintarPlano();
void menu_funciones( Plano );
void menu_punto( Plano );
void menu_recta( Plano );
void menu_parabola( Plano );
void menu_circunferencia ( Plano );
void menu_elipse( Plano );

main (){
	
	int eleccion;
	
	Plano plano( ancho, alto, k );
	
//	initwindow( ancho , alto );
//	pintarPlano();
	menu_funciones( plano );
	

	
	system("pause>null");
	
}

void pintarPlano(){
	
	Plano plano = Plano( ancho, alto, k );
	
	Punto p1 = Punto( plano.posX(-ancho/2*k) , plano.posY(0));
	Punto p2 = Punto( plano.posX(ancho/2*k) , plano.posY(0));
	Punto p3 = Punto( plano.posX(0),plano.posY(-alto/2*k));
	Punto p4 = Punto( plano.posX(0),plano.posY( alto/2*k));
	
	// Lineas del plano
//	setcolor(RED);      
	plano.pintar_lineas( -ancho/2*k, ancho/2*k, true );
	plano.pintar_lineas( -alto/2*k, alto/2*k, false );
	
	// Lineas del Eje
	setcolor(WHITE); 
	line( (int) p1.getX(), (int) p1.getY(),
	      (int) p2.getX(), (int) p2.getY());
	line( (int) p3.getX(), (int) p3.getY(),
	      (int) p4.getX(), (int) p4.getY());
	

}

void menu_funciones( Plano plano ){
	int eleccion;
	
	do {
		system("cls");
		cout << " MENU DE FUNCIONES " << endl;
		cout << "1.-Iniciar el modo grafico" << endl;
		//cout << " [1]. Punto " << endl;
		cout << " 2.- Recta " << endl;
		cout << " 3.- Parabola " << endl;
		//cout << " 4.- Circunferencia" << endl;
		//cout << " 5.- Elipse " << endl;
		cout << " 4.- Salir " << endl;
		cin >> eleccion;
		
		switch( eleccion ){
			case 1:
				initwindow( ancho , alto );
				pintarPlano();
				//menu_punto(plano);
				break;
			case 2:
				menu_recta(plano);
				break;
			case 3:
				menu_parabola( plano );
				break;
			case 4:
				menu_circunferencia( plano );
				break;
			case 5:
				menu_elipse( plano );
				break;
			default:
				break;
		}
	}while( eleccion != 0 );
}

void menu_punto( Plano p ){
	
	float x,y;
	int color;
	
	system("cls");
	cout << "MENU PUNTO" << endl;
	cout << " Punto (x,y) " << endl;
	cout << " X: ";
	cin  >> x;
	cout << " Y: ";
	cin  >> y;
	cout << " Color: ";
	cin  >> color;
	
	p.pintar_punto(Punto(x,y), color );
	
	system("pause>null");
}

void menu_recta( Plano p ){
	
	float m,b;
	int color;
	
	system("cls");
	cout << "MENU RECTA" << endl;
	cout << " y = mx + b " << endl;
	cout << " m: ";
	cin  >> m;
	cout << " b: ";
	cin  >> b;
	cout << " Color: ";
	cin  >> color;
	
	p.pintar_recta( m, b, color );
	
	system("pause>null");
}

void menu_parabola( Plano plano ){

	float p, h, c;
	int color, t1;
	bool tipo;
	
	system("cls");
	cout << "MENU PARABOLA" << endl;
	cout << "     Vertical           Horizontal" << endl;
	cout << " (x-h)^2 = 4p(y-c) | (y-c)^2 = 4p(x-h) " << endl;
	cout << " Tipo [v=1/h=0]:";
	cin  >> t1;
	cout << " h: ";
	cin  >> h;
	cout << " c: ";
	cin  >> c;
	cout << " p: ";
	cin  >> p;
	cout << " Color: ";
	cin  >> color;
	
	tipo = ( t1 == 1 ) ? true : false;
	
	plano.pintar_parabola( h, c, p, tipo, color );
	
	system("pause>null");
}

void menu_circunferencia( Plano plano ){
	float h, c, r;
	int color;
	
	system("cls");
	cout << "MENU CIRCUNFERENCIA" << endl;
	cout << " (x-h)^2 + (y-c)^2 = r^2 " << endl;
	cout << " h: ";
	cin  >> h;
	cout << " c: ";
	cin  >> c;
	cout << " r: ";
	cin  >> r;
	cout << " Color: ";
	cin  >> color;
	
	plano.pintar_circunferencia( h, c, r, color );
	
	
	system("pause>null");
}

void menu_elipse( Plano plano ){
	float h,c,a,b;
	int color;
	
	system("cls");
	cout << "MENU ELIPSE" << endl;
	cout << " ((x-h)^2)/a + ((y-c)^2)/b = 1 " << endl;
	cout << " h: ";
	cin  >> h;
	cout << " c: ";
	cin  >> c;
	cout << " a: ";
	cin  >> a;
	do{
		cout << " b: ";
		cin  >> b;
		if ( b == a ){
			cout << " El valor de b debe ser diferente de a. " << endl;
		}
	}while( b == a );
	cout << " Color: ";
	cin  >> color;
	
	plano.pintar_elipse( h, c, a, b, color );
	
	system("pause>null");
}
