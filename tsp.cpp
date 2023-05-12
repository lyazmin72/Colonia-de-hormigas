//Laura Yazmin de la Fuente Bernal

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <locale.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
using namespace std;

double m[26][26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
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
			   
double vecX[130]={334.5909246,397.6446634,503.8741827,444.0479404,311.6137147,662.8551011,40.09790306,526.8941409,209.1887938,683.2674132,
				  280.7494439,252.749309,698.7850452,678.7574678,220.0041131,355.1528557,296.9724228,504.5154072,224.1079497,470.6801297,
				  554.2530513,567.6332684,599.0532671,240.5232959,32.08259728,91.05387369,248.2179895,488.8909044,206.046794,575.8409416,
				  282.6089948,27.65814849,568.573731,269.4638933,417.8004857,32.16809387,561.4775136,342.9482167,399.6752075,571.737105,
				  370.7559843,509.7093253,177.0207,526.1674199,316.5725172,469.29081,572.7630641,29.51769943,454.0082937,416.1546762,
				  535.2514331,265.4455534,478.054211,370.4781203,598.3479202,201.1521139,193.692536,448.5792599,603.2853486,543.0102491,
				  214.5750793,426.3501452,89.04470371,84.49201002,220.0468614,688.4613313,687.2857532,75.4934934,63.41709935,97.93634959,
				  399.5255885,456.3167017,319.8855102,295.9250895,288.4868857,268.3951859,140.4709056,689.8079027,280.5784507,453.3884434,
				  213.5704943,133.6953005,521.1658691,30.26579463,657.0199585,6.925224196,252.4286968,42.85516825,145.8999394,638.4885716,
				  489.2756391,361.2231139,519.9475426,129.3349741,259.7172815,676.342189,84.51338417,77.71640487,335.9802443,264.3554718,
				  51.68269169,692.1376849,169.2191357,194.0131482,415.1928395,415.0432205,169.838986,525.0987124,238.6851191,116.2112468,
				  16.92832581,434.3440768,40.52538604,530.4849979,484.3595849,263.6501249,450.2891918,441.7822806,24.21691054,503.7886861,
				  635.538939,614.5922733,21.71613513,143.826647,637.7191022,566.564561,196.6849168,384.9270449,178.1107816,403.2874387};
				  
double vecY[130]={161.7809319,262.8165331,172.8741151,384.649181,2.009169983,549.2301264,187.2375431,215.7079092,691.0262292,414.2096287,
				  5.920639205,535.7430385,348.441373,410.7256424,409.1225813,76.39120764,313.1312792,240.8866564,358.4872229,309.6259188,
				  279.4242467,352.7162027,361.094869,430.6036008,345.855101,148.721327,343.9528017,3.612231139,437.7639406,141.967096,
				  329.4183806,424.7684582,287.0975661,295.9464636,341.259659,448.8998721,357.354393,492.3321424,156.8435036,375.7575351,
				  151.9060752,435.7975189,295.6044773,409.4859418,65.64001082,281.9891445,373.3208821,330.0382309,537.2178548,227.6133101,
				  471.0648644,684.9987192,509.6452029,332.5390063,446.869328,649.0260269,680.2322841,532.793406,134.4006474,481.5168231,
				  43.64601175,61.7285416,277.1158386,31.84748164,623.0778103,0.470231273,373.5346236,312.9175377,23.70393097,211.0910931,
				  170.8221968,597.1937162,626.8396605,664.6291555,667.7284071,52.90101816,513.5566721,167.5947004,458.7533547,282.9082329,
				  525.8681818,677.1757808,132.8617087,450.0754503,39.77729083,23.87492416,535.1659365,63.82320818,399.5255885,62.62625585,
				  665.3131282,564.2347788,347.9711417,435.669274,454.6495181,371.0979707,183.3260739,354.3833863,660.6321897,377.5743377,
				  676.0429509,543.8010926,547.8194325,263.4791317,78.9133572,479.0801702,245.6103433,213.5063719,33.4932911,363.5742703,
				  656.5711014,92.69968314,424.6829616,183.8390534,49.24603873,426.5852608,126.3853416,299.7724363,500.3474482,514.689502,
				  200.9811207,418.8691931,660.974176,92.69968314,54.20484124,199.9551616,221.8209158,87.4630167,104.6905806,205.8971749};
double m1[130][130];

		
int i, j, h, k=0, u, s,ch=0; bool flag=false, flag1=0, li, fu;
float T, Q, a, B, p, it, sum, r, can, con=0, sumt=0, menor;
vector<float> pro, c, di, dis;
vector<int> rec, menort;
//float fe[26][26], fe1[130][130];

void generarRecorrido(int f, int pr, float **fe){
	cout<<endl;
	rec.clear(); 
	rec.push_back(f);
	if(pr==26){
		while(rec.size()!=pr){
			i=rec.back()-1;
			pro.clear(); c.clear();
			sum=k=con=0; 
			for(j=0; j<pr; j++){
				if(m[i][j]!=0 && find(rec.begin(),rec.end(),j+1)==rec.end()){
					con++;
					pro.push_back(pow(fe[i][j],a)*pow((float)1/m[i][j],B)); 
					c.push_back(j+1);
					sum+=pow(fe[i][j],a)*pow((float)1/m[i][j],B);
				}
			}
			if(con==0) {
				flag=true;
				generarRecorrido(f,pr,fe);
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
	}else{
		while(rec.size()!=pr){
			i=rec.back()-1;
			pro.clear(); c.clear();
			sum=k=con=0; 
			for(j=0; j<pr; j++){
				if(m1[i][j]!=0 && find(rec.begin(),rec.end(),j+1)==rec.end()){
					con++;
					pro.push_back(pow(fe[i][j],a)*pow((float)1/m1[i][j],B)); 
					c.push_back(j+1);
					sum+=pow(fe[i][j],a)*pow((float)1/m1[i][j],B);
				}
			}
			if(con==0) {
				flag=true;
				generarRecorrido(f,pr,fe);
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
		
	}

	if(flag==true){
		s=rec.size(); flag1=1;
	}
	flag=false;
	if(flag1==1)
		rec.resize(s); 
	rec.push_back(rec[0]);
}

void ingresarDatos(){
	cout<<"-> Ingresa el valor de la feromona inicial: "; cin>>T; 
	cout<<"-> Ingresa el valor de la constante Q: "; cin>>Q; 
	cout<<"-> Ingresa el valor de 'a' para controlar la influencia de feromona depositada en cada arista: "; cin>>a; 
	cout<<"-> Ingresa el valor de 'B' para controlar la influencia de la conveniencia del estado de transición en cada arista: "; cin>>B; 
	cout<<"-> Ingresa el valor del coeficiente de evaporación de la feromona: "; cin>>p; 
	cout<<"-> Ingresa el número de iteraciones: "; cin>>it;	
	cout<<"-> Ingresa la cantidad de Hormigas a utilizar: "; cin>>h;
	
}


void actualizarFeromona(int **tabu, int pr, float **fe){
	for(int ii=0; ii<pr; ii++)
		for(int jj=0; jj<pr; jj++)
			if(ii!=jj) fe[ii][jj]=(1-p)*fe[ii][jj];
	
	for(int hh=0; hh<h; hh++){
		for(int d=0; d<pr+1; d++){	
			for(int ii=0; ii<pr; ii++){
				for(int jj=0; jj<pr; jj++){
					if((tabu[hh][d]==ii+1 && tabu[hh][d+1]==jj+1)){
						fe[ii][jj]+=(float)Q/di[hh];
					}
				}
			}
		}
	}
}

int calcularDistancia(int pr){
	sum=0;
	if(pr==26){
		for(j=0; j<rec.size(); j++)
			sum+=m[rec[j]-1][rec[j+1]-1];
	}else{
		for(j=0; j<rec.size(); j++)
			sum+=m1[rec[j]-1][rec[j+1]-1];
	}
		di.push_back(sum);  
	return sum;
}

void mostrarIteracion(int pr){
	ch++;
	cout<<"° El recorrido de la Hormiga '"<<ch<<"' es: ";
	for(i=0; i<rec.size(); i++){
		if(i==0)
			cout<<" ["<<rec[i]<<"]";
		else
			cout<<"-> ["<<rec[i]<<"]";
	}
	cout<<endl<<endl;
	cout<<"	La distancia total recorrida es: '"<<calcularDistancia(pr)<<"'"<<endl<<endl;
}

int mejorCamino(){
	menor=menort[0];
	for(i=1; i<menort.size(); i++){
		if(menor>menort[i])	menor=menort[i];
	}
	return menor;
}

void obtenerMejor(){
	menor=di[0];
	for(i=1; i<di.size(); i++){
		if(menor>di[i])	menor=di[i];
	}
	cout<<endl<<"+El camino más corto econtrado en la iteración es: '"<<(int) menor<<"'";
	menort.push_back(menor);
}
			   
int main(){
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int op,problem;
	do{
		system("cls");
		cout<<"\t\t<============== ALGORITMO DE COLONIA DE HORMIGAS =============>\n\n";
		cout<<"		Problemas TSP disponibles"<<endl<<endl;
		cout<<"			1) 26 City problem (Fricker)"<<endl;
		cout<<"			2) 130 City problem (Churritz)"<<endl<<endl;
		cout<<"		Selecciona el problema al que deseas acceder: ";cin>>op;
		switch (op){
			case 1: problem=26;
				for(i=0; i<26; i++){
					for(j=i+1; j<26; j++){
						m[i][j]=m[j][i];
					}
				}
				break;
			case 2: problem=130;
					for(i=0;i<130;i++){
						for(j=i;j<130;j++){
							m1[i][j]=sqrt(pow((vecX[j]-vecX[i]),2)+(pow((vecY[j]-vecY[i]),2)));
							m1[j][i]=sqrt(pow((vecX[j]-vecX[i]),2)+(pow((vecY[j]-vecY[i]),2)));
							}
					}

				break;
				default: cout<<endl<<endl<<"	OPCIÓN INEXISTENTE, PRESIONA CUALQUIER TECLA PARA REINTENTAR"<<endl;
					system("pause");
					break;
		}
	}while(op<1||op>2);
	system("cls");
	cout<<"\t\t<============== ALGORITMO DE COLONIA DE HORMIGAS =============>\n\n\n";
	ingresarDatos();
	
	
	float **fe = new float*[problem];
	for (i=0; i<problem; i++) 
    	fe[i] = new float[problem];
    	
    
    for(i=0; i<problem; i++){
		for(j=0; j<problem; j++){
			if(j!=i)
				fe[i][j]=T; 
		}
	}
    	
	int **tabu = new int*[h];
	for (i=0; i<h; i++) 
    	tabu[i] = new int[problem+1];
    	
    cout<<endl;
	for(i=0; i<h; i++){
		cout<<"---> Ciudad de inicio de hormiga "<<i+1<<": ";
		cin>>u;
		tabu[i][0]=u;
	}
	
	int il;
	
	for(int li=0; li<it; li++){
	di.resize(0);
		for(il=0; il<h; il++){
			generarRecorrido(tabu[il][0], problem, fe); 
			for(int y=0; y<rec.size(); y++){
				tabu[il][y]=rec[y];
			}
			mostrarIteracion(problem);
		}
		obtenerMejor(); cout<<endl<<endl;
		actualizarFeromona(tabu, problem, fe);

	cout<<endl<<endl;
	/*cout<<"\n\nFeromona actualizada: \n\n\n\tAristas\t\tFeromona\n\t=========================\n";
	for(i=0; i<26; i++){
		for(j=i+1; j<26; j++){
 			cout<<"\t"<<i+1<<" - "<<j+1;
				cout<<"\t  |\t"<<fe[i][j]<<endl;
		}
		cout<<"\t-------------------------\n";
	}*/
}
	cout<<"\n\n+El camino más corto encontrado en todas las iteraciones es: '"<<mejorCamino()<<"'"<<endl;
	
}


