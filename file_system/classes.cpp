#include<bits/stdc++.h>
using namespace std;

class file{
    private:
    string name;
    string data;
    // string extension;

    public:

    file(string name,string data){
        this->name=name;
        this->data=data;

    }

    void getdata(){
        cout<<data;
    }

    void setdata(string newdata){
        this->data=newdata;
    }

};


//can contain both files or subdirectory
class directory{
    private:
    string name;

    unordered_map<string,file*> files; //store all files, name-object
    unordered_map<string,directory*> subdirectories;

    public:

    directory(string n){
        this->name=n;
    }

    file* getFile(string name){
        if(files.find(name) != files.end()){
            return files[name];

        }
        return NULL; //not found

    }

    directory* getDirectory(string name){
        if(subdirectories.find(name) != subdirectories.end()){
            return subdirectories[name];
        }
        return NULL;
    }

};

class filesystem{
    private:

    directory* root;


    public:

    filesystem(){
        root=new directory("/");
    }





}