#ifndef _Template_H_
#define _Template_H_
#include <iostream>
#include <string.h>

using namespace std;

class Template {
private:
  char id[256];
public:
  Template () {};

  Template (char *id) {
    strcpy(this->id, id);
  };

  ~Template () {
  };

  bool operator<(const Template& dt)
  {  
    return this->id < dt.id;
  } 

  bool operator<(const Template *dt)
  {  
    return this->id < dt->id;
  } 

  bool operator>(const Template& dt)
  {  
    return this->id > dt.id;
  } 

  
  bool operator>(const Template *dt)
  {  
    return this->id > dt->id;
  } 
  
  
  bool operator==(const Template& dt) 
  {
    return this->id == dt.id;
  }

    bool operator>(const Template& dt)
  {  
    return this->id > dt.id;
  } 


  bool operator<(const Template& dt)
  {  
    return this->id < dt.id;
  } 
    
  bool operator==(const Template* dt) 
  {
    return this->id == dt->id;
  }

  bool operator<=(const Template& dt) 
  {
    return this->id <= dt.id;
  }
    
  bool operator<=(const Template* dt) 
  {
    return this->id <= dt->id;
  }

  bool operator>=(const Template& dt) 
  {
    return this->id >= dt.id;
  }
    
  bool operator>=(const Template* dt) 
  {
    return this->id >= dt->id;
  }

  friend ostream& operator<<(ostream& os, const Template& dt)
  {  
      os << dt.id;  
      return os;  
  } 
  
  friend ostream& operator<<(ostream& os, const Template *dt)
  {  
      os << dt->id;  
      return os;  
  } 
};

#endif
