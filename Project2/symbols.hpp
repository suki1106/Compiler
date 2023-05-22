#ifndef symbols_h
#define symbols_h

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

enum data_type{
    STR_TYPE,
    INT_TYPE,
    BOOL_TYPE,
    REAL_TYPE,
    VOID_TYPE // procedure
};

// const , var, function, array
enum form_type{
    CONST_f,  // const expression or const vairable
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

struct arg_info{
    string name;
    data_type d_type;
    arg_info(string name,data_type d_type): name(name),d_type(d_type){}
    arg_info():name(""),d_type(STR_TYPE){}
};

// name, value, type, const?
struct Info {
    string name;
    data_type d_type;
    form_type f_type;
    vector<arg_info> params; // function parameter
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
    Info(string name, data_type d_type, form_type f_type,const vector<arg_info>& params) : name(name), d_type(d_type),f_type(f_type),params(params){}
};

class Symboltable{
    public:
        Symboltable();
        ~Symboltable();
        int Insert(string,data_type,form_type,value);
        int Insert(Info); 
        int lookup(string);
        void printTableSize();
        Info* getInfo(int);
        void dump();
    private:
        string getType(int); // int, bool, real ,string
        string getForm(int); // const, var, func, array?
        vector<Info> identifiers;
        map<string,int> table;
        int index; // id index
};


class Symboltable_List{
    public:
        Symboltable_List();
        ~Symboltable_List();
        void create_table(); // when enter block
        void popTable(); // when block ends
        void dumpCurrentTable(); // dump current scope table
        void dumpAllTable(); // from top to bottom
        Symboltable* getCurrentTable(); // get current scope table
    private:
        vector<Symboltable> Symboltables; // store all tables
        stack<int> st; //deal with scope
        int index;
};


#endif