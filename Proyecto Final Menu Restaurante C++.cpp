#include <iostream>
#include <string.h>

using namespace std;

typedef char cadena [30];

typedef struct fecha{
	int dd, mm, aa;
};

typedef struct residencia{
	cadena nombrecalle, localidad, provincia;
	int numcalle;
}; 

typedef struct empleado{
	int legajo;	
	cadena apellido;
	cadena nombre;
	int DNI;
	fecha fechanac;
	residencia domicilio;
	cadena email;
	int telefono;
	int ocup_mesas;
}; 

typedef struct infomesa{
	int nummesa;
	int ocupacion;
	int legmozo;
};

typedef struct ingredi{
	cadena descripingre;
	int cantidad;	
};

typedef struct infoplatos{ 
	int numplato;	
	cadena descripplato;
	cadena ingredientes;
};

typedef struct lista{
	cadena listac;
};

typedef empleado mozo [6];
void infomozo (mozo m, int &ocup);

typedef infomesa mesa [24];
void datosmesa (mesa mezaza, bool band, int &ocup2, mozo &m);

typedef ingredi ig [1000];
void ingredientes (ig ingre, int &ocup3);

typedef infoplatos platos [60]; 
void menus (platos p, bool band2, int &ocup4, bool band3);

typedef lista compras [1000];

bool controlstock (ig ingre, platos p, compras &c, int ocup3, int ocup4, int &ocup5, bool &band3);

void ordenmesa (mesa &mezaza, int ocup2);
void consulta1 (mesa mezaza, int ocup2);

void ordenmenu (platos &p, int ocup4);
void consulta2 (platos p, int ocup4, bool band3);

void consulta3 (compras c, int ocup5);

void consulta4 (mozo m, int ocup);

void consulta5();

int main () {
bool band=false, band2=false, band3=false, realizado1=false, realizado2=false, realizado3=false, realizado4=false;
int opc, opc2, ocup=-1, ocup2=-1, ocup3=-1, ocup4=-1, ocup5=-1;
	
mozo m;
mesa mezaza;
ig ingre;
platos p;
compras c;
	
cout<<"*********** Menu Principal************* "<<endl;
	
	do{
		cout<<"Elija una opcion: "<<endl;
		cout<<"1) Registrar datos de mozos."<<endl;
		cout<<"2) Informacion sobre las mesas."<<endl;
		cout<<"3) Informacion ingredientes."<<endl;
		cout<<"4) Informacion del menu."<<endl;
		cout<<"*********** ************** ************"<<endl;
		cin>>opc;
		
			switch (opc) {
			
			case 1: infomozo (m, ocup); band=true; realizado1=true; break;
			
			case 2:	datosmesa (mezaza, band, ocup2, m); realizado2=true; break;
		
			case 3:	ingredientes (ingre, ocup3); realizado3=true; band2=true; break;
		
			case 4:	menus (p, band2, ocup4, band3); realizado4=true; break; 
			 
			
				if (controlstock (ingre, p, c, ocup3, ocup4, ocup5, band3) == true){
					cout<<"El plato esta disponible. "<<endl;
				}
				else
					cout<<"El plato no esta disponible. "<<endl;
				
		
			default: cout<<"Error en el ingreso."<<endl; break;
			
			}
				
	}while (realizado1!=true || realizado2!=true || realizado3!=true || realizado4!=true);
	
	cout<<"******************* Consultas ********************* "<<endl;
		
	do{
		cout<<"\n Elija una opcion: "<<endl;
		cout<<"1) Listar mesas."<<endl;
		cout<<"2) Listar carta disponible."<<endl;
		cout<<"3) Listar ingredientes faltantes."<<endl;
		cout<<"4) Premio."<<endl;
		cout<<"5) Salir."<<endl;
		cout<<"*********** ************** ************"<<endl;
			
		cin>>opc2;
		
		switch (opc2){
				
			case 1: ordenmesa (mezaza, ocup2);
					consulta1 (mezaza, ocup2);
					break;
			
			case 2: ordenmenu (p, ocup4);
					consulta2 (p, ocup4, band3); 
					break;
			
		
			case 3:	consulta3 (c, ocup5); 
					break;
		
			case 4:	consulta4 (m, ocup);
					 break;
				
			case 5: consulta5 (); 
					break;
			
			default: cout<<"Error en el ingreso. "<<endl; 
					 break;
				
		}
	}while (opc2!=5);

}

void infomozo (mozo m, int &ocup){
	char resp;
	
	if (ocup==5){
		cout<<"\nEl registro de mozos esta completo."<<endl;
	}
	
	else {	
		for (int i=0; i<=5 && resp!='n'; i++){
			ocup++;
			cout<<"Ingresar numero de legajo: "<<endl;
			cin>>m[ocup].legajo;
			cout<<"Ingresar apellido: "<<endl;
			cin>>m[ocup].apellido;
			cout<<"Ingresar nombre: "<<endl;
			cin>>(m[ocup].nombre);
/*			cout<<"Ingresar DNI: "<<endl;
			cin>>(m[ocup].DNI);
			cout<<"Ingresar fecha de nacimiento."<<endl;
			cout<<"Ingresar dia: "<<endl;
			cin>>(m[ocup].fechanac.dd);
			cout<<"Ingresar mes: "<<endl;
			cin>>(m[ocup].fechanac.mm);
			cout<<"Ingresar anio: "<<endl;
			cin>>(m[ocup].fechanac.aa);
			cout<<"Ingresar calle: "<<endl;
			cin>>(m[ocup].domicilio.nombrecalle);
			cout<<"Ingresar numero de calle: "<<endl;
			cin>>(m[ocup].domicilio.numcalle);
			cout<<"Ingresar localidad: "<<endl;
			cin>>(m[ocup].domicilio.localidad);
*/			cout<<"Ingresar provincia: "<<endl;	
			cin>>(m[ocup].domicilio.provincia);	
/*			cout<<"Ingresar e-mail: "<<endl;
			cin>>(m[ocup].email);
			cout<<"Ingresar telefono: "<<endl;
			cin>>(m[ocup].telefono);		
*/			cout<<"Almacenamiento exitoso!"<<endl;	
			cout<<"Presione 'n' para detener el almacenamiento de mozos y s para continuar. "<<endl;
			cin>>resp;
		}
	}
}

void datosmesa (mesa mezaza, bool band, int &ocup2, mozo &m)
{
	char resp;
	int j=0, cont=0;
	
	if (band==true){
		for (int i=0; i<=23 && resp!='n'; i++){
			ocup2++;
			cout<<"Ingrese numero de mesa. "<<endl;		
			cin>>mezaza[i].nummesa;
			cout<<"Ingrese cantidad de ocupaciones. "<<endl;
			cin>>mezaza[i].ocupacion;
		
			if (cont<=4){
				cont++;
			}
			else{
			
				j++;
				cont=0;	
			}
			
			m[j].ocup_mesas++;
			
			mezaza[i].legmozo=m[j].legajo;
			cout<<"El legajo del mozo asignado a la mesa es: "<<endl;
			cout<<mezaza[i].legmozo<<endl;
			
			cout<<"Registro exitoso! "<<endl;
			cout<<"Presione 'n' para detener el agregado de mesas y s para continuar. "<<endl;
			cin>>resp;
		}
	}
	else
	cout<<"No se realizo la operacion anterior.\n ";
}

void ingredientes (ig ingre, int &ocup3){
	char resp;
	
	for(int j=0; j<=999 && resp!='n'; j++ ){
		ocup3++;
		cout<<"Ingrese el ingrediente: "<<endl;
		cin>>ingre[j].descripingre;
		cout<<"Ingrese la cantidad de este ingrediente: "<<endl;
		cin>>ingre[j].cantidad;
		cout<<"Registro exitoso! "<<endl;
		cout<<"Presione 'n' para detener ingreso de ingredientes y 's' para continuar."<<endl;
		cin>>resp;
	}
}

void menus (platos p, bool band2, int &ocup4, bool band3){
	char resp;
	
	if (band2==true){
		
		for(int i=0; i<=59 && resp!='n'; i++){
			ocup4++;
			cout<<"Ingrese el numero del plato: "<<endl;
			cin>>p[i].numplato;
			cout<<"Ingrese su descripcion: "<<endl;
			cin>>p[i].descripplato;
			cout<<"Ingrese sus ingredientes: "<<endl;
			cin>>p[i].ingredientes;
			cout<<"Registro exitoso! "<<endl;
			cout<<"Presione 'n' para detener ingreso de platos y 's' para continuar."<<endl;
			cin>>resp;
		}
	}
	else
	cout<<"No se realizo la operacion anterior.\n ";
}

bool controlstock (ig ingre, platos p, compras &c, int ocup3, int ocup4, int &ocup5, bool &band3){
	
	for (int i=0; i<=ocup4; i++){
		for (int j=0; j<=ocup3; j++){
			if (ingre[j].descripingre==p[i].ingredientes){
				j=0;
			    band3=true;
			    return band3;
			}
		}
		ocup5++;
		strcpy (c[ocup5].listac, p[i].ingredientes);
		return band3=false;
	}
}

void ordenmesa (mesa &mezaza, int ocup2){
	int aux, j;
	for(int i=1; i<=ocup2; i++){
			aux=mezaza[i].nummesa;
			j=i-1;
			while((j>=0) && (mezaza[j].nummesa>aux)){
					mezaza[j+1].nummesa=mezaza[j].nummesa;
					j--;
			}
			mezaza[j+1].nummesa=aux;
	}
}

void consulta1 (mesa mezaza, int ocup2){
	
	for(int i=0; i<=ocup2; i++){
	
		cout<<"El numero de la mesa ["<<i<<"] = es: "<<mezaza[i].nummesa<<endl;
		cout<<"Su ocupacion fue de: "<<mezaza[i].ocupacion<<" veces. "<<endl;
		cout<<"El legajo de su mozo asignado es: "<<mezaza[i].legmozo<<endl;
	}
}

void ordenmenu (platos &p, int ocup4){
	int aux, j;
	for(int i=1; i<=ocup4; i++){
			aux=p[i].numplato;
			j=i-1;
			while((j>=0) && (p[j].numplato>aux)){
					p[j+1].numplato=p[j].numplato;
					j--;
			}
			p[j+1].numplato=aux;
	}
}

void consulta2 (platos p, int ocup4, bool band3){

	
	for(int i=0; i<=ocup4; i++){
	
		cout<<"Menu numero: "<<p[i].numplato<<endl;
		cout<<"Su descripcion: "<<p[i].descripplato<<endl;
		
		
		if (band3==true)
			cout<<"El plato esta disponible. "<<endl;
		else
			cout<<"El plato no esta dispoible. "<<endl;	
	}
}

void consulta3 (compras c, int ocup5){
	cout<<"Los ingredientes que hacen falta reponer son: "<<endl;
	
	for (int i=0; i<=ocup5; i++){
		cout<<c[i].listac<<endl;
	}
}

void consulta4 (mozo m, int ocup){
	int aux=0, j;
	
	for (int i=0; i<=ocup; i++){
		if (aux<=m[i].ocup_mesas){
			aux=m[i].ocup_mesas;
			j=i;
		}	
	}
	
	cout<<"El nombre del mozo premiado es: "<<m[j].nombre<<endl;
	cout<<"El apellido del mozo premiado es: "<<m[j].apellido<<endl;
	cout<<"La provincia del mozo premiado es: "<<m[j].domicilio.provincia<<endl;
	cout<<"La ocupacion en una mesa del mozo premiado es: "<<m[j].ocup_mesas<<endl;		 
}

void consulta5(){
	cout<<"\n Saliendo. Gracias por usar el sistema MenuSanti; Justo Santiago Batto. ";
}
