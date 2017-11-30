#ifndef PONTO_H
#define PONTO_H

#include <math.h>
#include "vetor.h"
class Ponto {
public:  
    float x;
    float y;
    float z; 	


public:
	Ponto (float x1 = 0.0f, float y1 = 0.0f, float z1 = 0.0f) {

		__asm {
			mov eax,dword ptr [this]

			mov ebx,dword ptr[x1]
			mov dword ptr[eax], ebx

			mov ebx, dword ptr[y1]
			mov dword ptr[eax+4], ebx

			mov ebx, dword ptr[z1]
			mov dword ptr[eax+8], ebx
		}
    }

	Ponto operator + (const Ponto &p) const {
        return Ponto(x + p.x, y + p.y, z + p.z);
    }

	Ponto operator + (const Vetor &v) const {
        return Ponto(x + v.x, y + v.y, z + v.z);
    }
    
    Ponto operator - (const Vetor &v) const {
		return Ponto(x - v.x, y - v.y, z - v.z);
    }

	Vetor operator - (const Ponto &p) const {
		return Vetor(this->x - p.x,this->y - p.y,this->z - p.z);
	}

	//MULTIPLICAÇÃO POR ESCALAR 'K'
    Ponto operator * (const float k) const {
    	return Ponto(x * k, y * k, z * k);
    }

	//DIVISÃO POR ESCALAR
	Ponto operator / (const float k) const {
		if(k != 0.0f)
    		return Ponto(x / k, y / k, z / k);
		else
			return Ponto(x, y, z);
    }

	const Ponto & operator += (const Vetor &v){

		__asm {
			mov eax, dword ptr [this]
			mov ecx,dword ptr [v]

			  fld dword ptr [eax]
			  fadd dword ptr [ecx]
			  fstp dword ptr [eax]

			  fld dword ptr [eax+4]
			  fadd dword ptr [ecx+4]
			  fstp dword ptr [eax+4]

			  fld dword ptr [eax+8]
			  fadd dword ptr [ecx+8] 
			  fstp dword ptr [eax+8]
		}
		

		return *this;
    }

	const Ponto & operator -= (const Vetor &v){

		__asm {

			mov eax, dword ptr [this]
			mov ecx,dword ptr [v]

			  fld dword ptr [eax]
			  fsub dword ptr [ecx]
			  fstp dword ptr [eax]

			  fld dword ptr [eax+4]
			  fsub dword ptr [ecx+4]
			  fstp dword ptr [eax+4]

			  fld dword ptr [eax+8]
			  fsub dword ptr [ecx+8]
			  fstp dword ptr [eax+8]
		}

		return *this;
    }

	const Ponto & operator *= (const float k) {

		__asm {
			mov eax, dword ptr [this]

			  fld dword ptr [eax]
			  fmul dword ptr [k]
			  fstp dword ptr [eax]

			  fld dword ptr [eax+4]
			  fmul dword ptr [k]  
			  fstp dword ptr [eax+4] 

			  fld dword ptr [eax+8] 
			  fmul dword ptr [k]  
			  fstp dword ptr [eax+8]
		}

		return *this;
    }

	const Ponto & operator /= (const float k) {
		if(k != 0.0f){

			__asm {
				mov eax, dword ptr [this]

				 fld dword ptr [eax]
				 fdiv dword ptr [k]
				 fstp dword ptr [eax]

				  fld dword ptr [eax+4]
				  fdiv dword ptr [k]  
				 fstp dword ptr [eax+4] 

				 fld dword ptr [eax+8] 
				 fdiv dword ptr [k]  
				  fstp dword ptr [eax+8]
			}
		}
		return *this;
    }

	void setCoordenadas(const float x1, const float y1, const float z1) {

		__asm {
			mov eax,dword ptr [this]

			mov ebx,dword ptr[x1]
			mov dword ptr[eax],ebx

			mov ebx, dword ptr[y1]
			mov dword ptr[eax+4],ebx

			mov ebx, dword ptr[z1]
			mov dword ptr[eax+8],ebx
	}
		//this->x = x;
		//this->y = y;
		//this->z = z;
	}

	float distancia (const Ponto &p) const {
		return sqrt((this->x - p.x)*(this->x - p.x) + (this->y - p.y)*(this->y - p.y) + (this->z - p.z)*(this->z - p.z));
	}

	Ponto copia() const {
        return Ponto(this->x, this->y, this->z);
    }
};
#endif