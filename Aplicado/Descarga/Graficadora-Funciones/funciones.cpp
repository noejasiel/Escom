#include <math.h>

class Recta{
	private:
		float m;
		float b;
	
	public:
		
		Recta( float _m, float _b ){
			m = _m;
			b = _b;
		}
		
		float getY( float x ){
			return ( m * x ) + b;
		}
};

class Parabola{
	private:
		float h;
		float c;
		float p;
		
	public:
		Parabola( float _h, float _c, float _p ){
			h = _h;
			c = _c;
			p = _p;
		}
		
		float getY( float x ){
			return ( ( pow( ( x - h ), 2 ) / ( 4 * p ) ) + c );
		}
		
		float getX( float y ){
			return ( ( pow( ( y - c ), 2 ) / ( 4 * p ) ) + h );
		}
	
	
};

class Circunferencia{
	private:
		float h;
		float c;
		float r;
	public:
		Circunferencia( float _h, float _c, float _r ){
			h = _h;
			c = _c;
			r = _r;
		}
		
		float getY1( float x ){
			return ( c + sqrt( pow( r, 2 ) - pow ( ( x - h ), 2 )));
		}
		
		float getY2( float x ){
			return ( c - sqrt( pow( r, 2 ) - pow ( ( x - h ), 2 )));
		}
};

class Elipse{
	private:
		float h;
		float c;
		float a;
		float b;
	public:
		Elipse( float _h, float _c, float _a, float _b ){
			h = _h;
			c = _c;
			a = _a;
			b = _b;
		}
		
		float getY1( float x ){
			return (c + sqrt( pow(b, 2) * ( 1 - (pow(x - h,2) / pow(a, 2)))));
		}
		
		float getY2( float x ){
			return (c - sqrt( pow(b, 2) * ( 1 - (pow(x - h,2) / pow(a, 2)))));
		}
};






