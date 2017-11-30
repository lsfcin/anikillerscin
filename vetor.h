#ifndef VETOR_H
#define VETOR_H

#include <math.h>


class Vetor {
public:    
    float x;
    float y;
    float z;
    
    Vetor (float x1 =0.0f, float y1 = 0.0f, float z1 = 0.0f) {
    
		__asm {
			mov eax,dword ptr [this]

			mov ebx,dword ptr[x1]
			mov dword ptr[eax],ebx

			mov ebx, dword ptr[y1]
			mov dword ptr[eax+4],ebx

			mov ebx, dword ptr[z1]
			mov dword ptr[eax+8],ebx
		}
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

	}

	bool vetorNulo() const{		
		if(this->x != 0.0f || this->y != 0.0f || this->z != 0.0f )
			return false;
		return true;
	}

	void anular(){

		__asm {
			mov eax,dword ptr [this]

			mov dword ptr[eax], 0

			mov dword ptr[eax+4], 0
			
			mov dword ptr[eax+8], 0
		}
		//this->x = 0.0f;
		//this->y = 0.0f;
		//this->z = 0.0f;
	}

	void calibrarVetor(){

		if(!this->vetorNulo()){
			float delta = 0.000000001f;
			if(this->x >= -delta && this->x <= delta)
				this->x = 0.0f;
			if(this->y >= -delta && this->y <= delta)
				this->y = 0.0f;
			if(this->z >= -delta && this->z <= delta)
				this->z = 0.0f;
		}
	}

	Vetor copia() const {
        return Vetor(this->x, this->y, this->z);
    }

	Vetor copiaNormalizada() const {
		Vetor retorno(this->x, this->y, this->z);
		retorno.normalizar();
        return retorno;
    }

	// OPERADORES
	//SOMA E SUBTRAÇÃO
    Vetor operator + (const Vetor &v) const {
        return Vetor(x + v.x, y + v.y, z + v.z);
    }
    
    Vetor operator - (const Vetor &v) const {
		return Vetor(x - v.x, y - v.y, z - v.z);
    }
    
	//MULTIPLICAÇÃO POR ESCALAR 'K'
    Vetor operator * (const float k) const {
    	return Vetor(x * k, y * k, z * k);
    }
	
	//PRODUTO VETORIAL OPERADOR
	Vetor operator * (const Vetor &v) const {
    	return Vetor (y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }

	//DIVISÃO POR ESCALAR
	Vetor operator / (const float k) const {
		if(k != 0.0f)
    		return Vetor(x / k, y / k, z / k);
		else
			return Vetor(x, y, z);
    }

	//SOMA E SUBTRAÇÃO DE VETORES
	const Vetor & operator += (const Vetor &v){

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

	const Vetor & operator -= (const Vetor &v){

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

	//MULTIPLICAR E DIVIDIR NORMA
	const Vetor & operator *= (const float k) {

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

	const Vetor & operator /= (const float k) {
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
			/*this->x /= k;
			this->y /= k;
			this->z /= k;*/
		}
		return *this;
    }

	//OPERAÇÕES ALGÉBRICAS:	
	float norma () const {
        return sqrt(x*x + y*y + z*z);
    }
	
    void normalizar() {
        float n = norma();
		if(n != 0.0f){
			__asm {
			  mov eax, dword ptr [this]

			  fld dword ptr [eax]
			  fdiv dword ptr [n]
			  fstp dword ptr [eax]

			  fld dword ptr [eax+4]
			  fdiv dword ptr [n]
			  fstp dword ptr [eax+4]

			  fld dword ptr [eax+8]
			  fdiv dword ptr [n]
			  fstp dword ptr [eax+8]
		}
		}
    }

	void setNorma(const float norma){		
		this->normalizar();
		*this *= norma;
	}

	Vetor oposto() const {
		return Vetor(-x,-y,-z);
	}

	Vetor projecao(const Vetor &u) const{
		float vu = this->produtoInterno(u);
		float uu = u.produtoInterno(u);
		return u * (vu/uu);  
	}

	float produtoInterno (const Vetor &v) const {
        return x * v.x + y * v.y + z * v.z;
    }

	// PRODUTO VETORIAL FUNÇÃO
	Vetor produtoVetorial (const Vetor &v) const {
        return Vetor (y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
	}

	float cosEntre(const Vetor &v) const{
		float temp = this->produtoInterno(v);
		return (temp/(this->norma()*v.norma()));		
	}
    
	float anguloEntre(const Vetor &b) const{
		Vetor v1 = copiaNormalizada();
		Vetor v2 = b.copiaNormalizada();

		float angulo = (float)acos(v1.produtoInterno(v2));
		
		Vetor temp = v1 * v2;
		if(temp.y < 0.f)
			angulo = -angulo;	
		
		return angulo;		
	}

	void rotacionarEmY(const float angulo){
		float tempx = this->x;
		float tempz = this->z;		
		this->x = cos(angulo)*tempx - sin(angulo)*tempz;
		this->z = sin(angulo)*tempx + cos(angulo)*tempz;
	}

	Vetor reflexo(const Vetor &refletido) const{		
		return ( *this * ((this->produtoInterno(refletido) *2)) ) - refletido;
	}
};

#endif