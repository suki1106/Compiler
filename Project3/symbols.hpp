#ifndef symbols_h
#define symbols_h

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <fstream>



using namespace std;

//extern ofstream out_f;

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
    int size; // for array
    int index_local; // for local variable
    bool isGlobalVar;
    union{
        int i_v;
        bool b_v;
        string* s_v;
        double r_v;
    };
    Info();
    ~Info();
    Info(string name, data_type d_type, form_type f_type);
    Info(string name, data_type d_type, form_type f_type,int i_v) : name(name), d_type(d_type),f_type(f_type), i_v(i_v) {this->size=1;}
    Info(string name, data_type d_type, form_type f_type,bool b_v) : name(name), d_type(d_type), f_type(f_type),b_v(b_v) {this->size=1;}
    Info(string name, data_type d_type, form_type f_type,string* s_v) : name(name), d_type(d_type), f_type(f_type),s_v(s_v) {this->size=1;}
    Info(string name, data_type d_type, form_type f_type,double r_v) : name(name), d_type(d_type), f_type(f_type),r_v(r_v) {this->size=1;}
    Info(string name, data_type d_type, form_type f_type,const vector<arg_info>& params) : name(name), d_type(d_type),f_type(f_type),params(params){this->size=1;}
    // void getValue();
    // int getInt(){return this->i_v;};
    // string* getString(){return this->s_v;};
    // bool getBool(){return this->b_v;};
    // double getDouble(){ return this->r_v;};
};

bool sameType(Info,Info);


class Symboltable{
    public:
        Symboltable();
        ~Symboltable();
        //int Insert(string,data_type,form_type,value);
        int Insert(Info); 
        int lookup(string);
        int getTableSize();
        Info* getInfo(int);
        void dump();
        void setGlobal(){this->isGlobalScope=1;}
    private:
        string getType(int); // int, bool, real ,string
        string getForm(int); // const, var, func, array?
        vector<Info> identifiers;
        map<string,int> table;
        int index; // id index
        bool isGlobalScope;
        //int counter_local_var; // ?
};


class Symboltable_List{
    public:
        Symboltable_List();
        ~Symboltable_List();
        void create_table(); // when enter block
        void popTable(); // when block ends
        void dumpCurrentTable(); // dump current scope table
        void dumpAllTable(); // from top to bottom
        Info* lookup(string);
        Symboltable* getCurrentTable(); // get current scope table
        Info* getFunc(); // used to check function return type
        bool isGlobal(){return st.top() == 0;};
    private:
        vector<Symboltable> Symboltables; // store all tables
        stack<int> st; //deal with scope
        int index;
};

string getType(int); // use in project3
int getValue_IntBool(const Info&);

#endif