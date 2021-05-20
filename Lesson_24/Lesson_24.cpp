#include<iostream>

using namespace std;


int main()
{
	//	errors
	//	weak_ptr<int> a(new int(10));
	//	weak_ptr<int> a = new int(10);

	
	
	shared_ptr<int> sp (new int(10)); //  <------  shared use_count = 1

	weak_ptr<int> wp1; //  <------  Boş object
	weak_ptr<int> wp2 (wp1); //  <------  Boş objecti boş mənimsədəndə use_count artmır
	weak_ptr<int> wp3 (sp);  //  <------  use_count() count burda artır 

	// wp3.reset();  <------  shared ptr-le olan əlaqəni kəsir
	// 
	/////---------------------------------------------------------------------/////
	// 
	// 	   Əgər object boşdursa true, əks halda false...
	// cout << boolalpha << wp2.expired() << endl; //  ------>  true
	// cout << boolalpha << wp3.expired() << endl; //  ------>  false

	//  cout << "use_count:\n";
	//  cout << "wp1: " << wp1.use_count() << '\n'; //	------>  wp1: 0
	//  cout << "wp2: " << wp2.use_count() << '\n'; //	------>  WP2: 0
	//  cout << "wp3: " << wp3.use_count() << '\n'; //	------>  WP3: 1

	/////---------------------------------------------------------------------/////

	//  wp2.swap(wp3); //  ------>  wp2 ilə wp3-lə yerdəyişmə edir.
	
	//  cout << "use_count:\n";
	//  cout << "wp1: " << wp1.use_count() << '\n'; //	------>  wp1: 0
	//  cout << "wp2: " << wp2.use_count() << '\n'; //	------>  WP2: 1
	//  cout << "wp3: " << wp3.use_count() << '\n'; //	------>  WP3: 0

	/////---------------------------------------------------------------------/////

	//  Bu nümunədə məlumatı digər yerdə saxlaya bilmədiyimiz üçün məlumat geri qaytarmaq mümkün olmur və boş qayıdır.
	//  .lock() - Funksiyası ya məlumatı geri qaytarır, əks halında boş qaytarır.
	//  wp3.reset();
	//  cout << "wp3: " << wp3.use_count() << '\n'; //	------>  WP2: 1
	//  wp3.lock();
	//  cout << "wp3: " << wp3.use_count() << '\n'; //	------>  WP2: 1


	//  Bu nümunədəd data sp2 - də kilidləndiyi üçün yəni saxlandığı üçün geri qaytarmaq mümkün olur.
	//  shared_ptr<int> sp1, sp2;
	//  weak_ptr<int> wp;
	//  sharing group:
	//// --------------
	//  sp1 = make_shared<int>(20);     //  sp1
	//  wp = sp1;                       //  sp1, wp

	//  sp2 = wp.lock();                //  sp1, wp, sp2

	//  sp1.reset();                    //       wp, sp2
										
	//  sp1 = wp.lock();                //  sp1, wp, sp2

	//  std::cout << "*sp1: " << *sp1 << '\n';
	//  std::cout << "*sp2: " << *sp2 << '\n';
	

	/////---------------------------------------------------------------------/////

	//  int* p = new int(10);
	    
	//  shared_ptr<int> a(new int(10));
	//  shared_ptr<int> b(a, p);  // alias constructor
	//  
	//  weak_ptr<int> c(b);
	    
	//  owner before funksiyasinda aradakı böyük, kiçik və ya bərabərlik fərqliliyi tapdıqda true tapa bilmədikdə false qaytarır.
	//  cout << "comparing a and c...\n" << boolalpha;
	//  cout << "value-based: " << (!(a < c.lock()) && !(c.lock() < a)) << '\n';
	//  cout << "owner-based: " << (!a.owner_before(c) && !c.owner_before(a)) << '\n';

	return 0;
};