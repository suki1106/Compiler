#ifndef symbols_h
#define symbols_h

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum data_type{
    STR_TYPE,
    INT_TYPE,
    BOOL_TYPE,
    REAL_TYPE
};

// const, var, function, array
enum form_type{
    CONST_f,
    VAR_f,
    FUNC_f,
    ARRAY_f
};


union value{
    int i_v;
    bool b_v;
    string* s_v;
    double r_v;
};


struct exp_Info {
    bool is_const_exp;
    data_type d_type;
    union {
        int i_v;
        bool b_v;
        string* s_v;
        double r_v;
    };
    exp_Info(bool is_const_exp, data_type d_type, int i_v) : is_const_exp(is_const_exp), d_type(d_type), i_v(i_v) {}
    exp_Info(bool is_const_exp, data_type d_type, bool b_v) : is_const_exp(is_const_exp), d_type(d_type), b_v(b_v) {}
    exp_Info(bool is_const_exp, data_type d_type, string* s_v) : is_const_exp(is_const_exp), d_type(d_type), s_v(s_v) {}
    exp_Info(bool is_const_exp, data_type d_type, double r_v) : is_const_exp(is_const_exp), d_type(d_type), r_v(r_v) {}
    exp_Info() {}
};

// name, value, type, const?
struct Info {
    string name;
    data_type d_type;
    form_type f_type;
    union{
        int i_v;
        bool b_v;
        string* s_v;
        double r_v;
    };
    Info();
    ~Info();
    Info(string name, data_type d_type, form_type f_type);
    Info(string name, data_type d_type, form_type f_type,int i_v) : name(name), d_type(d_type),f_type(f_type), i_v(i_v) {}
    Info(string name, data_type d_type, form_type f_type,bool b_v) : name(name), d_type(d_type), f_type(f_type),b_v(b_v) {}
    Info(string name, data_type d_type, form_type f_type,string* s_v) : name(name), d_type(d_type), f_type(f_type),s_v(s_v) {}
    Info(string name, data_type d_type, form_type f_type,double r_v) : name(name), d_type(d_type), f_type(f_type),r_v(r_v) {}
};

class Symboltable{
    public:
        Symboltable();
        ~Symboltable();
        int Insert(string,data_type,form_type,value);
        int Insert(Info); 
        int lookup(string);
        void dump();
    private:
        string getType(int); // int, bool, real ,string
        string getForm(int); // const, var, func, array?
        vector<Info> identifiers;
        map<string,int> table;
        int index;
};



#endif