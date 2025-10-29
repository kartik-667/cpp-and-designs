#include<bits/stdc++.h>
using namespace std;

class file{
    private:
    string name;
    string data;
    // string extension;

    public:

    file(string name){
        this->name=name;
        this->data="";
    }

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

    void addSubDirectory(string name){
        if(subdirectories.find(name) == subdirectories.end()){
            subdirectories[name]=new directory(name);

        }
        return;
    }

    void addFile(string name){
        if(files.find(name) == files.end()){
            files[name]=new file(name);


        }
        return ;
    }

};

class filesystem{
    private:

    vector<string> splitPath(string path){
        stringstream ss(path);
        vector<string> arr;
        string word;

        while(getline(ss,word,'/')){
            if(!word.empty()){
                arr.push_back(word);

            }
        }
        return arr;

    }

    

    directory* root;


    public:

    filesystem(){
        root=new directory("/");
    }

    bool addfile(string path){
        vector<string> arr=splitPath(path);
        directory* curr=root; //this holds parent
        for(int i=0;i<arr.size()-1;i++){
            if(curr->getDirectory(arr[i]) ==NULL ){
                //create a new directory
                curr->addSubDirectory(arr[i]);
                curr=curr->getDirectory(arr[i]);
            }
        }

        //now add file
        string filename=arr[arr.size()-1];
        if(curr->getFile(filename)==NULL){
            curr->addFile(filename);

        }
        return true;

       
    }





}