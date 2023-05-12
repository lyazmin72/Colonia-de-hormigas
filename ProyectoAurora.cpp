//Laura Yazmin de la Fuente Bernal

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdio.h>
using namespace std;

int m[26][26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   83,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   93,40,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   129,53,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   133,62,42,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   139,64,49,11,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   151,91,59,46,35,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   169,116,81,72,61,65,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   135,93,54,65,55,63,34,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   114,84,44,70,62,71,52,59,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   110,95,58,88,82,90,71,75,39,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   98,98,64,100,95,103,88,92,56,36,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   99,89,54,89,84,92,77,83,47,26,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   95,68,31,66,62,71,63,76,40,20,27,34,23,0,0,0,0,0,0,0,0,0,0,0,0,0,
			   81,67,36,76,74,82,78,91,55,34,32,31,24,15,0,0,0,0,0,0,0,0,0,0,0,0,
			   152,127,86,102,93,100,66,54,37,43,42,56,53,62,73,0,0,0,0,0,0,0,0,0,0,0,
			   159,156,117,142,133,141,110,98,78,74,61,63,68,87,92,44,0,0,0,0,0,0,0,0,0,0,
			   181,175,135,156,146,153,119,103,91,91,80,85,89,106,112,54,22,0,0,0,0,0,0,0,0,0,
			   172,152,112,127,117,124,88,70,62,68,64,75,74,87,96,26,34,33,0,0,0,0,0,0,0,0,
			   185,165,125,139,128,135,98,78,74,82,77,87,87,100,109,39,38,29,13,0,0,0,0,0,0,0,
			   147,160,124,155,148,156,130,122,96,86,68,62,71,93,93,68,30,46,63,68,0,0,0,0,0,0,
			   157,180,147,180,173,181,156,148,122,111,92,83,93,116,113,94,53,64,87,90,26,0,0,0,0,0,
		       185,223,193,228,222,230,206,198,172,160,140,129,140,163,158,144,102,107,135,136,77,50,0,0,0,0,
			   220,268,241,278,272,280,257,250,223,210,190,178,189,212,205,196,154,157,186,186,128,102,51,0,0,0,
			   127,179,157,197,194,202,188,188,155,136,116,100,111,132,122,139,109,125,141,148,80,65,64,93,0,0,
			   181,197,161,190,182,190,160,148,128,121,103,99,107,130,130,95,51,51,81,79,37,27,58,107,90,0};
			   
int i,j, u,h;
float T=0.1, Q=1, a=1, B=1, p=0.01, sum, r, can, con=0;
vector<float> pro, c;
vector<int> rec;

void ingresarDatos(){
	cout<<"Ingresa el numero de hormigas: ";cin>>h;
	int tabu[h][23];	
	for(i=0; i<h; i++){
		cout<<"Ciudad de inicio de hormiga: ";cin>>u;
		tabu[i][0]=u;
		generarRecorrido();
	}
}

void generarRecorrido(){
	rec.clear(); 
	rec.push_back(u);
	while(rec.back()!=4){
		i=rec.back()-1;
		pro.clear(); c.clear();
		sum=k=con=0; 
		for(j=0; j<7; j++){
			if(m[i][j]!=0 && find(rec.begin(),rec.end(),j+1)==rec.end()){
				con++;
				pro.push_back(f[i][j]*(1/m[i][j]));
				c.push_back(j+1);
				sum+=f[i][j]*(1/m[i][j]);
			}
		}
		if(con==0) {
			flag=true;
			generarRecorrido();
		}
		
		for(u=0; u<4; u++)	
			r=0.01+rand()/((RAND_MAX+1u)/1-1.0); 
	    can=0;
		for(k=0; k<pro.size(); k++){
		 	can+=pro[k]/sum; 
			if(can>r){
				rec.push_back(c[k]);break;
			}
		}	
	}

	if(flag==true){
		s=rec.size(); flag1=1;
	}
	flag=false;
	if(flag1==1)
		rec.resize(s);
}

void actualizarFeromona(){
	for(i=0; i<7; i++)
		for(j=0; j<7; j++)
			f[i][j]=(1-p)*f[i][j];

	for(j=0; j<rec.size()-1; j++)
		f[rec[j]-1][rec[j+1]-1]=(1-p)*f[rec[j]-1][rec[j+1]-1]+(1/sum);
	
}

void mostrarIteracion(){
	cout<<"El recorrido es: ";
	for(i=0; i<rec.size(); i++){
		if(i==0)
			cout<<" "<<rec[i];
		else
			cout<<" -> "<<rec[i];
	}
	cout<<"\nLa distancia recorrida es: "<<calcularDistancia();
	
	actualizarFeromona();
	cout<<"\n\nFeromona actualizada: \n\n\n\tAristas\t\tFeromona\n\t=========================\n";
	for(i=0; i<7; i++){
		for(j=0; j<7; j++){
			if(m[i][j]!=0){
				cout<<"\t"<<i+1<<" - "<<j+1;
				cout<<"\t  |\t"<<f[i][j]<<endl;
			}
		}
		cout<<"\t-------------------------\n";
	}
}	
			   
int main(){
	srand(time(NULL));
	cout<<"\t\t<========COLONIA DE HORMIGAS========>\n\n";
	for(i=0; i<26; i++){
		for(j=i+1; j<26; j++){
			m[i][j]=m[j][i];
		}
	}
	ingresarDatos();
	generarRecorrido();
	mostrarIteracion();	
}
