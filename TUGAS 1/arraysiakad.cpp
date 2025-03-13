#include <iostream>
using namespace std;

void open(){
	cout<<"======================================="<<endl;
	cout<<"=       PROGRAM PENGECEKKAN NILAI     ="<<endl;
	cout<<"======================================="<<endl;
	cout<<endl;
	
}

void close(){
	cout<<"======================================="<<endl;
	cout<<"=           PROGRAM SELESAI           ="<<endl;
	cout<<"======================================="<<endl;
	
	cout<<"Bismillah Nilainya A++"<<endl;
	
}


int main() {
    string nama;
    string stambuk;

 open();
 
cout<<"masukkan nama :";getline (cin,nama);
cin.ignore();
cout<<"masukkan stambuk :";getline(cin,stambuk);


string user[5] = {"La Ode Muhammad", "La ode Dhaifan", "La ode Hijas", "La ode Januar", "La ode Raim"};
string stam[5] = {"13020230232", "13020230253", "13020230255", "13020230256", "13020230257"};
string kelas[5] = {"A7", "A4", "A5", "A1", "A9"};

string matkul[5] = {"ALPRO", "Metode Numerik", "Basis Data", "Elektronika", "Sistem Digital"};
string kodeM[5] = {"MK 1", "MK 2", "MK 3", "MK 4", "MK 5"};
string nilai[5] = {"A+", "A-", "B+", "B+", "A"};

cout<<"=================================================================="<<endl;
cout<<endl;

if(nama == "La Ode Muhammad" && stambuk == "13020230232" ){
	
	
	cout<<"Nama    :" << user[1] <<endl; 
	cout<<"Stambuk :" <<stam[1]<<endl;
	cout<<"Kelas   :" <<kelas[1]<<endl;
	
	
	cout<<"==============================================="<<endl;
	for(int a = 0; a < 5; a++){
		cout<<"Mata Kuliah :" <<matkul[a]<<endl;
		cout<<"Kode Mata kuliah :" <<kodeM[a]<<endl;
		cout<<"Nilai :"<<nilai[a]<<endl;
		cout<<"---------------------------"<<endl;
		}
	
}

else if(nama == "La Ode Dhaifan" && stambuk == "13020230253"){
	
	
	cout<<"Nama    :" << user[2] <<endl; 
	cout<<"Stambuk :" <<stam[2]<<endl;
	cout<<"Kelas   :" <<kelas[2]<<endl;
	
	cout<<"==============================================="<<endl;
	for(int a = 0; a < 5; a++){
		cout<<"Mata Kuliah :" <<matkul[a]<<endl;
		cout<<"Kode Mata kuliah :" <<kodeM[a]<<endl;
		cout<<"Nilai :"<<nilai[a]<<endl;
		cout<<"---------------------------"<<endl;
	}
		
}

else if(nama == "La Ode Hijas" && stambuk == "13020230255"){
	
		cout<<"Nama    :" << user[3] <<endl; 
	cout<<"Stambuk :" <<stam[3]<<endl;
	cout<<"Kelas   :" <<kelas[3]<<endl;
	
	cout<<"==============================================="<<endl;
	for(int a = 0; a < 5; a++){
		cout<<"Mata Kuliah :" <<matkul[a]<<endl;
		cout<<"Kode Mata kuliah :" <<kodeM[a]<<endl;
		cout<<"Nilai :"<<nilai[a]<<endl;
		cout<<"---------------------------"<<endl;
	}
	
}

else if(nama == "La Ode Januar" && stambuk == "13020230256"){
	
		cout<<"Nama    :" << user[4] <<endl; 
	cout<<"Stambuk :" <<stam[4]<<endl;
	cout<<"Kelas   :" <<kelas[4]<<endl;
	cout<<"==============================================="<<endl;
	
	for(int a = 0; a < 5; a++){
		cout<<"Mata Kuliah :" <<matkul[a]<<endl;
		cout<<"Kode Mata kuliah :" <<kodeM[a]<<endl;
		cout<<"Nilai :"<<nilai[a]<<endl;
		cout<<"---------------------------"<<endl;
	}
	
}

else if(nama == "La Ode Raim" && stambuk == "13020230257"){
	
		cout<<"Nama    :" << user[5] <<endl; 
	cout<<"Stambuk :" <<stam[5]<<endl;
	cout<<"Kelas   :" <<kelas[5]<<endl;
	cout<<"==============================================="<<endl;
	
	for(int a = 0; a < 5; a++){
		cout<<"Mata Kuliah :" <<matkul[a]<<endl;
		cout<<"Kode Mata kuliah :" <<kodeM[a]<<endl;
		cout<<"Nilai :"<<nilai[a]<<endl;
		cout<<"---------------------------"<<endl;
	}
	
}

close();

return 0;

}