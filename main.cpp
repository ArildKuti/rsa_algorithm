//codificare e decodificare con RSA la prima lettere in maiuscolo del proprio nome in ASCII
#include <iostream>
#include <cmath>

using namespace std;

unsigned long MCD(unsigned long k[], unsigned long m);
unsigned long cifratura(unsigned long a, unsigned long b);
unsigned long decifratura(unsigned long h[], unsigned long c);


unsigned long MCD(unsigned long a, unsigned long b){
	unsigned long r = a % b;
	
	if(r==0){
		return b;
	}
	
	return MCD(b,r);
}

unsigned long cifratura(unsigned long k[], unsigned long m){
	unsigned long s = 1;
	
	for(unsigned long i = 0; i < k[1]; i++){
		s = (s * m) % k[0];
	}
	
	return s;
}

unsigned long decifratura(unsigned long h[], unsigned long c){
	unsigned long s = 1;
	
	for(unsigned long i = 0; i < h[1]; i++){
		s = (s * c) % h[0];
	}
	
	return s;
}


int main() {
	unsigned long p;
	cout << "inserisci p: ";
	cin >> p;
	
	unsigned long q;
	cout << "inserisci q: ";
	cin >> q;
	
	unsigned long e;
	cout << "inserisci e: ";
	cin >> e;
	
	unsigned long n = p * q;
	cout << "n = p * q					:  " << n << endl;
	
	unsigned long f = (p-1) * (q-1);
	cout << "f(n) = (p-1) * (q-1)				:  " << f << endl;
	
	if(! (MCD(e,f)) == 1 && e < f){
		return -1;
	}
	
	unsigned long d;
	
    if (!((e*d) % f == 1)){
    	return -1;
	}
	
	cout << "Esponente privato d				: " << d << endl;
	
	unsigned long k[] = {n, e};
	unsigned long h[] = {n, d};
	cout << "Chiave pubblica: 				k(" << k[0] << "," << k[1] << ")" << endl;
	cout << "Chiave privata: 				h(" << h[0] << "," << h[1] << ")" << endl;
	
	unsigned long m;
	cout << "Messaggio da cifrare:				m=";
	cin >> m;
	
	unsigned long c = cifratura(k, m);
	
	cout << "Cifratura di m: 				c= " << c << endl;
	cout << "Decifratura di c:				 m= " << m << endl;
	
	system("PAUSE");
	return 0;
}
