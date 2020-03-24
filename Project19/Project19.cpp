
#include "pch.h"
#include <iostream>
using namespace std;
/*Dilara karaduman
Bir karmaşık sayı (complex number) gerçel ve sanal kısmımdan oluşan bir sayıdır. a ve b sayıları gerçek sayılar ve i =
√−1 olduğunda z karmaşık sayısı z = a + bi olarak ifade edilir.*/

class KarmasikSayi { //Karmaşık sayılar üzerinde işlem yapabilmek için bir sınıf oluşturduk.
private:  //sınıfın iki temel ögesinin kolay erişilebilir ve değiştirilebilir olmaması için özel kısımda tanımladık. 
	double gercel;
	double imaginal;

public:
	KarmasikSayi() { //bir değer girilmediği sürece default constructor çalışır ve sıfır değerini verir.
		gercel = 0;
		imaginal = 0;
	}

	void setGercel(int gercek) { //özel kısma tanımladığımız iki ögeye değer atamak için set fonk.'nu kullanıyoruz.
		gercel = gercek;
	}
	void setImaginal(int sanal) {
		imaginal = sanal;
	}
	int getGercel() {//özel kısma tanımladığımız iki ögenin gösterilmesi için get fonksiyonunu kullanıyoruz.
		return gercel;
	}
	int getImaginal() {
		return imaginal;
	}

	KarmasikSayi(int tamSayi) { //girilen tam sayı değeri ise karmaşık sayi halini verir
		gercel = tamSayi;
		imaginal = 0;
		cout << "verilen tam sayi degeri ile elde edilen karmasik sayi: " << gercel << " + " << imaginal << "i" << endl;
	}
	KarmasikSayi(double reel) { //reel sayıyı karmaşık sayıya döndüren constructor
		gercel = reel;
		imaginal = 0;
		cout << "verilen reel sayi değeri ile elde edilen karmasik sayi: " << gercel << " + " << imaginal << "i" << endl;
	}
	KarmasikSayi(int k, int l) { //iki tam sayı parametre ile karmaşık sayi olusturan constructor
		gercel = k;
		imaginal = l;
		if (k > 0) { // imaginal olan kısım sıfırdan büyük(pozitif) ise
			cout << "iki parametre ile oluşturulan karmaşık sayi: " << gercel << " + " << imaginal << "i" << endl;
		}
		else {//imaginal olan kısım sıfırdan küçük(negatif)ise
			cout << "iki parametre ile oluşturulan karmasik sayi: " << gercel << imaginal << "i" << endl;
		}
	}

	void print(double gercek, double sanal) { //Karmaşık sayıyı yazdıran print üye fonksiyonu.
		if (sanal > 0) {
			cout << "Karmasik sayiniz: " << gercek << " + " << sanal << "i" << endl;
		}
		else {
			cout << "Karmasik sayiniz: " << gercek << sanal << "i" << endl;

		}
	}
	void ekle(double gercek, double sanal) { //birbirinin üzerine ekleme yapan fonksiyon
		double tam = gercel + gercek; //reel sayının üstüne eklenen reel sayi toplanır.
		double irreel = imaginal + sanal; //imaginal sayının üstüne eklene imaginal sayi toplanır.
		if (irreel < 0) {
			cout << "karmasik sayinin toplanmıs son hali= " << tam << irreel << "i" << endl;
		}
		else {
			cout << "karmasik sayinin toplanmıs son hali= " << tam << " + " << irreel << "i" << endl;
		}
	}
	void cıkar(double gercek, double sanal) { //karmasik sayi çıkarma işlemi için fonk.
		double tam = gercel - gercek; //reel kısımdaki sayilarin farkını alır.
		double irreel = imaginal - sanal; //imaginal kısımdaki sayıların farkını alır
		if (irreel > 0) {
			cout << "karmasik sayinin cıkarilmis son hali= " << tam << " + " << irreel << "i" << endl;

		}
		else {
			cout << "karmasik sayinin cıkarilmis son hali= " << tam << irreel << "i" << endl;
		}
	}
	void bol(double gercek, double sanal) { //aldığı parametrelerle olan karmasık sayıyı var olan karmaşık sayıya bölen fonk.
		double x1, x2, y1, y2; //eşleniği ile çarptık .Bu sayede bölme işlemini sağladık.
		x1 = (gercel * gercek) + (imaginal * sanal);
		x2 = (gercek * gercek) + (sanal * sanal);
		double tam = x1 / x2;
		y1 = (imaginal * gercek) - (gercel * sanal);
		y2 = (gercek * gercek) + (sanal * sanal);
		double irreel = y1 / y2;
		if (irreel > 0) {
			cout << "karmasik sayinin bölünmüs hali= " << tam << " + " << irreel << "i" << endl;
		}
		else {
			cout << "karmasik sayinin bölünmüs hali= " << tam << irreel << "i" << endl;
		}
	}
};

int main() {
	
	KarmasikSayi sanal; //karmasik sayi sınıfına ait bir  sanal nesnesi.
	double q, t, a, b; 
	cout << "Lutfen istediginiz karmasik sayinin gercel kismini giriniz: ";
	cin >> q;
	cout << "Lutfen istediginiz karmasik sayinin imaginal kismini giriniz: ";
	cin >> t;
	sanal.setGercel(q); //Özel tanımlanan ögeleri değiştirdik.
	sanal.setImaginal(t);
	a = sanal.getGercel(); //Özel tanımlanan ögeleri çağırdık.
	b = sanal.getImaginal();
	cout << endl;
	sanal.print(a, b); //istenen ilk karmaşık sayı bastırılır.
	cout << endl;

	KarmasikSayi(9); //constructorın içine değer atayarak çağırdık.
	cout << endl;
	KarmasikSayi(-12, -5);
	cout << endl;
	KarmasikSayi(5.21);
	cout << endl;

	double m, n; //yapacağımız üç işlem(toplama,çıkarma,bölme) için karmaşık sayı istedik.
	cout << "Lutfen üzerinde islem yapmak istediginiz karmasik sayinin gercel kismini giriniz: ";
	cin >> m; 
	cout << "Lutfen islem yapmak istediginiz karmasik sayinin imaginal kismini giriniz: ";
	cin >> n;
	cout << endl;
	sanal.ekle(m, n); //Toplama fonksiyonunu çağırıyoruz.
	sanal.cıkar(m, n); //Çıkarma fonksiyonunu çağırıyoruz.
	cout << endl;
	sanal.bol(m, n); //Bölme fonksiyonunu çağırıyoruz.
	return 0;
}
