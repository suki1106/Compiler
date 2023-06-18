#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbols.hpp"



Info::Info(){
    name = "";
}

Info::~Info(){

}



// without initial value
Info::Info(string name, data_type d_type, form_type f_type){
    this->name = name;
    this->d_type = d_type;
    this->f_type = f_type;
    this->size = 1;
    switch (d_type) {
        case INT_TYPE:
            this->i_v = 0;
            break;
        case BOOL_TYPE:
            this->b_v = 0;
            break;
        case STR_TYPE:
            this->s_v = NULL;
            break;
        case REAL_TYPE:
            this->r_v = 0.0;
            break;
    }
}
int getValue_IntBool(const Info& info){
    return info.d_type == INT_TYPE ? info.i_v : info.b_v ;
}
bool sameType(Info a,Info b){
    if(a.f_type == ARRAY_f || b.f_type == ARRAY_f){
        if(a.f_type == b.f_type && a.d_type == b.d_type && a.size == b.size){
            return 1;
        }else{
            return 0;
        }
    }else{
        return a.d_type == b.d_type;
    }
}

Symboltable::Symboltable(){
    index=0;
    isGlobalScope=0;
}

Symboltable::~Symboltable(){
    
}



int Symboltable::Insert(Info id){
    if(table.find(id.name) == table.end()){
        table[id.name] = index;
        this->identifiers.push_back(Info());
        
        identifiers[index].name = id.name;
        identifiers[index].d_type = id.d_type;
        identifiers[index].f_type = id.f_type;
        identifiers[index].size = id.size;
        if(this->isGlobalScope)
            identifiers[index].isGlobalVar = 1;
        else
            identifiers[index].isGlobalVar = 0;
        if(id.f_type != FUNC_f){
        
            switch (id.d_type) {
                case INT_TYPE:
                    identifiers[index].i_v = id.i_v;
                    break;
                case BOOL_TYPE:
                    identifiers[index].b_v = id.b_v;
                    break;
                case STR_TYPE:
                    //cout << *(id.s_v) << endl;
                    identifiers[index].s_v = id.s_v;
                    break;
                case REAL_TYPE:
                    identifiers[index].r_v = id.r_v;
                    break;
            }
        }else{
            identifiers[index].params = id.params; // parameters
        }
        return index++;
    }else{
        return -1;
    }
}

// int Symboltable::Insert(string id,data_type d_type, form_type f_type,value v){
//     if( table.find(id) == table.end() ){
//         table[id] = index;

//         this->identifiers.push_back(Info());
        
//         identifiers[index].name = id;
//         identifiers[index].d_type = d_type;
//         identifiers[index].f_type = f_type;
        
//         switch (d_type) {
//             case INT_TYPE:
//                 identifiers[index].i_v = v.i_v;
//                 break;
//             case BOOL_TYPE:
//                 identifiers[index].b_v = v.b_v;
//                 break;
//             case STR_TYPE:

//                 identifiers[index].s_v = v.s_v;
//                 break;
//             case REAL_TYPE:
//                 identifiers[index].r_v = v.r_v;
//                 break;
//         }
//         return index++;   
//     }else{
//         // already exists
//         return -1;
//     }
// }

Info* Symboltable::getInfo(int index){
    return (index < this->identifiers.size())? &identifiers[index] :  NULL; 
}

int Symboltable::lookup(string id){
    if( table.find(id) != table.end() ){
        return table[id];
    }else{
        return -1;
    }
}
string getType(int Type){
    switch (Type) {
            case INT_TYPE:
                return "int";
                break;
            case BOOL_TYPE:
                return "bool";
                break;
            case STR_TYPE:            
                return "string";
                break;
            case REAL_TYPE:
                return "real";
                break;
            case VOID_TYPE:
                return "void";
            default:
                return "ERROR!";
                break;
        }
}
string Symboltable::getType(int Type){
    switch (Type) {
            case INT_TYPE:
                return "INT";
                break;
            case BOOL_TYPE:
                return "BOOL";
                break;
            case STR_TYPE:            
                return "STRING";
                break;
            case REAL_TYPE:
                return "REAL";
                break;
            case VOID_TYPE:
                return "VOID";
            default:
                return "ERROR!";
                break;
        }
}
string Symboltable::getForm(int Type){
    switch (Type) {
            case CONST_f:
                return "CONST";
                break;
            case VAR_f:
                return "VARIABLE";
                break;
            case FUNC_f:            
                return "FUNCTION";
                break;
            case ARRAY_f:
                return "ARRAY";
                break;
            default:
                return "ERROR!";
                break;
        }

}

int Symboltable::getTableSize(){
    return this->index;
}

void Symboltable::dump(){
    int cnt=0;
    cout << "------Symboltable------" << endl;
    //cout << "index\tid\tdata_type\tform_type\tvalue" << endl; 
    cout << "index" << setw(15) << "id" << setw(20) << "data_type" << setw(20) << "form_type" << setw(20) << "value" << endl;
    for(auto& id :identifiers){
        cout << cnt 
        << setw(20)  << id.name 
        << setw(20) << getType(id.d_type) 
        << setw(20) << getForm(id.f_type);
        if(id.f_type == ARRAY_f){
            cout << setw(20);
            cout << id.size << endl;
        }else if(id.f_type != FUNC_f){
            cout << setw(20);
            switch (id.d_type) {
                case INT_TYPE:
                    cout  <<id.i_v;
                    break;
                case BOOL_TYPE:
                    cout   << id.b_v;
                    break;
                case STR_TYPE:
                    if(id.s_v != NULL)cout << *(id.s_v);
                    else cout  << "\"\"";//empty string
                    break;
                case REAL_TYPE:
                    cout  << id.r_v ;
                    break;
            }
            //for test
            if(id.f_type == VAR_f)
                cout << "\t" << id.index_local;
            cout << endl;

        }else{
            // print formal parameters
            //cout << "\tsize:" << id.params.size();
            if(id.params.size() >0){
                cout << setw(8);
                for(auto& arg : id.params)
                    cout << "(" << arg.name << ":" << getType(arg.d_type) << ")";
            }
            cout << endl;
            
        }
        ++cnt;
    }
    cout << "------FINISH------" << endl;
}

Symboltable_List::Symboltable_List(){
    Symboltables.push_back(Symboltable());
    this->index=0;
    Symboltables[0].setGlobal();
    st.push(this->index);
}

Symboltable_List::~Symboltable_List(){

}

void Symboltable_List::create_table(){
    Symboltables.push_back(Symboltable());
    this->index++;
    st.push(this->index);
}

void Symboltable_List::popTable(){
    this->st.pop();
}

void Symboltable_List::dumpCurrentTable(){
    this->Symboltables[st.top()].dump();
}

Symboltable* Symboltable_List::getCurrentTable(){
    return &Symboltables[st.top()];
}

void Symboltable_List::dumpAllTable(){

    cout << "\n\n------Start dump all Symbol tables------\n\n";

    for(auto& Symboltable : Symboltables)
        Symboltable.dump();
}
Info* Symboltable_List::lookup(string id){

    // int current_table = st.top();
    // if(Symboltables[current_table].lookup(id) != -1)return Symboltables[current_table].getInfo(Symboltables[current_table].lookup(id));
    // if(Symboltables[0].lookup(id) !=-1)return Symboltables[0].getInfo(Symboltables[0].lookup(id));
    // return NULL;
    stack<int> tmp_st = this->st;

    while(!tmp_st.empty()){
        int index = tmp_st.top();
        if(Symboltables[index].lookup(id) != -1)return Symboltables[index].getInfo(Symboltables[index].lookup(id));
        tmp_st.pop();
    }
    return NULL;
}
Info* Symboltable_List::getFunc(){ // get first symbol table's last element
    Symboltable first = Symboltables[0];
    if (first.getTableSize()>0 ) return first.getInfo(first.getTableSize()-1);
    return NULL;
}