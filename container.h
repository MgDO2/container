#include <iostream>
#include <algorithm>
using namespace std;

/*
to use it, you must to use namespace ctr.
*/

namespace ctr{
  template<class type>
  class container{
    public:
      container(int len);
      int size();
      void connect(container<type> a);
      void swap(type& i,type& j);
      void order();
      type* start();
      type* end();
      type* direction(int ind);
      type operator[](int i); 
      void insert(int i,type n);
      bool operator==(container<type> a);
      void operator=(container<type> a);
      void operator+=(type a);
      int operator++(type);
      void operator--(type);
      void delete_ind(int ind);
      void replace(int i,type n);
      void free();
      double sum();
      ~container();
    private:
      type* p=NULL;
      int lengh=0;
  };

  template<class type>
  container<type>::~container(){
    delete [] p;
    lengh=0;
  }

  template<class type>
  container<type>::container(int len){
    lengh=len;
    p= new type[lengh];
  }

  template<class type>
  void container<type>::insert(int ind,type n){
    type* ip=NULL;
    ip=new type[lengh];
    for(int i=0;i<lengh;i++){
      ip[i]=p[i];
    }
    delete[] p;
    p=new type[++lengh];
    for(int i=0;i<ind;i++){
      p[i]=ip[i];
    }
    p[ind]=n;
    for(int i=ind+1;i<lengh;i++){
      p[i]=ip[i-1];
    }
    delete [] ip;
  }

  template<class type>
  void container<type>::connect(container<type> a){
    type* ip=NULL;
    ip=new type[lengh];
    for(int i=0;i<lengh;i++){
      ip[i]=p[i];
    }
    delete [] p;
    p=NULL;
    p=new type[lengh+a.lengh];
    for(int i=0;i<lengh;i++){
      p[i]=ip[i];
    }
    delete [] ip;
    for(int i=lengh;i<lengh+a.lengh;i++){
      p[i]=a[i-lengh];
    }
    lengh+=a.lengh;
  }

  template<class type>
  int container<type>::size(){
    return lengh;
  }

  template<class type>
  void container<type>::swap(type& i,type& j){
    type a=i;
    i=j;
    j=a;
  }

  template<class type>
  void container<type>::order(){
    sort(p,p+lengh);
  }

  template<class type>
  type* container<type>::start(){
    return p;
  }

  template<class type>
  type* container<type>::end(){
    return &p[lengh-1];
  }

   template<class type>
  type* container<type>::direction(int ind){
    return &p[ind];
  }

  template<class type>
  type container<type>::operator[](int i){
    return p[i];
  }

  template<class type>
  bool container<type>::operator==(container<type> a){
    if(this->lengh!=a.lengh){return false;}
    else{
      for(int i=0;i<this->lengh;i++){
        if(a[i]!=p[i]){return false;}
      }
    }
    return true;
  }

  template<class type>
  void container<type>::operator=(container<type> a){
    delete [] p;
    p=new type[a.lengh];
    for(int i=0;i<a.lengh;i++){
      p[i]=a[i];
    }
  }

  template<class type>
  void container<type>::operator+=(type a){
    type* ip=NULL;
    ip=new type[++lengh];
    for(int i=0;i<lengh-1;i++){
      ip[i]=p[i];
    }
    ip[lengh-1]=a;
    delete [] p;
    p=new type[lengh];
    for(int i=0;i<lengh;i++){
      p[i]=ip[i];
    }
    delete [] ip;
  }

  template<class type>
  int container<type>::operator++(type){
    lengh++;
    return lengh-1;
  }

  template<class type>
  void container<type>::operator--(type){
    type* ip=NULL;
    ip=new type[lengh];
    for(int i=0;i<lengh;i++){
      ip[i]=p[i];
    }
    delete [] p;
    p=new type[--lengh];
    for(int i=0;i<lengh;i++){
      p[i]=ip[i];
    }
    delete [] ip;
  }

  template<class type>
  void container<type>::delete_ind(int ind){
    lengh--;
    type* ip=NULL;
    ip=new type[lengh];
    int j=0;
    for(int i=0;i<lengh+1;i++){
      if(i!=ind){
        ip[j]=p[i];
        j++;
      }
    }
    delete [] p;
    p=new  type[lengh];
    for(int i=0;i<lengh;i++){
        p[i]=ip[i];
    }
    delete [] ip;
  }

  template<class type>
  void container<type>::replace(int i,type n){
    *(p+i)=n;
  }

  template<class type>
  double container<type>::sum(){
    double a=0;
    if(sizeof(p[0])!=1){
      for(int i=0;i<lengh;i++){
        a+=p[i];
      }
    }
    else{return -10e8;}
    return a;
  }

  template<class type>
  void container<type>::free(){
    delete [] p;
  }
}
