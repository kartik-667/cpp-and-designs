#include <bits/stdc++.h>
using namespace std;

class student{
    public:

    string name;
    int exilecount;
    bool isExiled;
    bool isPromoted;

    student(string n){
        name=n;
        exilecount=0;
        isExiled=isPromoted=false;
        
    }

};

class spell{
    
    public:
    string name;
    int day;
    string house;
    bool isValid;
    int strength;

    spell(string n, int d, string house){
        name=n;
        day=d;
        house=house;
        if(isPalindrome(n)){
            isValid=true;
        }else{
            isValid=false;
        }

    }

    bool isPalindrome(string name){
        int l=0;
        int r=name.size()-1;
        while(l<r){
            if(name[l] != name[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }





};


class house{
    public:
    string housename;
    int correctspell;
    int wrongspell;
    int maxhealth;
    int currhealth;
    int trait;
    int maxcapacity;
    int promoidx=0;

    vector<student*> students;
    vector<spell*> spells;

    unordered_map<int,string> dayspell; //day , spell 

    house(string hname,int maxh, int trait){
        housename=hname;
        maxhealth=maxh;
        trait=trait;
        currhealth=maxh;
        maxcapacity=5;

    }



};

class Hogwarts
{
public:
    
    unordered_map<string,house*> houses;
    set<int> days; //ordered 

    //seeker beater keeper chaser
    Hogwarts(){
        house* seeker=new house("seeker",100,1);
        house* keeper=new house("seeker",220,2);
        house* chaser=new house("seeker",90,4);
        house* beater=new house("seeker",130,8);

        houses["Seekers"]=seeker;
        houses["Keepers"]=keeper;
        houses["Chasers"]=chaser;
        houses["Beaters"]=beater;




    }
    /**
     * Enroll a student with the given name and trait.
     * A student can be enrolled into one of the available houses:
     * Seekers (trait 1),
     * Keepers (trait 2),
     * Chasers (trait 4),
     * Beaters (trait 8).
     * Each house can only have at most 5 students.
     * If the student is successfully enrolled, return true.
     * If the student cannot be enrolled, return false.
     */
    bool enrollStudent(string name, int trait)
    {
        for(auto itr:houses){
            if(itr.second->trait == trait){
                if(itr.second->students.size() >= itr.second->maxcapacity){
                    return false;
                }else{
                    student* news=new student(name);
                    itr.second->students.push_back(news);
                    return true;
                    // break;

                }

            }

        }

        return false;
    }

    /**
     * Add a spell with the given name to the given house on the given day.
     * Each house can only learn one spell per day.
     * Each spell has a strength equal to (20 * number of current students in the house).
     * Day number willl always be >= 0.
     * 
     * 
     * Bonus:
     *      How will you optimize if addSpell(), checkSpells(), and printSpells() 
     *      are called upon days with large gaps in between, eg: 1,2,3,5000,5001,10000,10006.
     */
    void addSpell(string spellName, string houseName, int day)
    {
        house* obj=houses[houseName];
        spell* newspell=new spell(spellName,day,houseName);
        newspell->strength= 20 * (obj->students.size());
        obj->dayspell[day]=spellName;
        obj->spells.push_back(newspell);

        if(newspell->isValid){
            obj->correctspell++;
        }else{
            obj->wrongspell++;
        }



    }

    /**
     * Check all spells if they are correct or not.
     * A spell is correct if it is a palindrome.
     * If spell is wrong, remove it. And (health of house which gave that spell) -= (strength of the spell).
     * If health of any house <= 0, remove all students of that house, house becomes empty and reset health to max.
     * Seekers (max health 100),
     * Keepers (max health 220),
     * Chasers (max health 90),
     * Beaters (max health 130).
     */
    void checkSpells()
    {
        for(auto itr:houses){

            house* curr=itr.second;

            vector<spell*> newspells;
            
            for(auto sp:curr->spells){
                if(sp->isValid == false){
                    curr->currhealth-=sp->strength;

                }else{
                    newspells.push_back(sp);
                }

            }

            if(curr->currhealth <=0){
                curr->students.clear();
                curr->currhealth=curr->maxhealth;
            }else{
                //remove all invalid spell
                curr->spells=newspells;
                
            }


        }
    }

    /**
     * Print the status of all houses.
     * Format:
     * House: <house_name>
     * Health: <health>
     * Students: <number_of_students>
     * Total Spells: <total_number_of_spells>
     * Correct Spells: <number_of_correct_spells>
     * Wrong Spells: <number_of_wrong_spells>
     * Accuracy: <accuracy_percentage>% (round to nearest integer)
     */
    void printStatus()
    {
        for(auto itr:houses){
            cout<<"house "<<itr.first<<endl;
            cout<<"heath "<<itr.second->currhealth<<endl;
            cout<<"students "<<itr.second->students.size()<<endl;
            cout<<"total spell "<<itr.second->wrongspell + itr.second->correctspell<<endl;
            
            double temp=((itr.second->correctspell) / (itr.second->correctspell + itr.second->wrongspell) ) * 100;
            cout<<"accuracy "<<temp<<endl;
        }
    }

    /**
     * Print all spells learned by all houses from startDay to endDay (inclusive).
     * Format:
     * Day <startDay>:
     * <house_name>: <spell_name> (Strength: <strength>)
     * <house_name>: <spell_name> (Strength: <strength>)
     * <house_name>: <spell_name> (Strength: <strength>)
     * Day <startDay + 1>:
     * ...
     * Day <endDay>:
     * ...
     */
    void printSpells(int startDay, int endDay)
    {
        for(int i=startDay; i<=endDay;i++){
            if(days.find(i) != days.end()){
                cout<<"day"<<i<<endl;
                for(auto itr:houses){
                    if(itr.second->dayspell.find(i) != itr.second->dayspell.end()){
                        //found spell
                        cout<<itr.first<<" "<<itr.second->dayspell[i]<<endl;
    
    
                    }
                }

            }

        }
    }

    /**
     * Student1 of houseName exiles student2 of the same house.
     * Do nothing if can't exile.
     * Exiled students are removed from the house.
     */
    void exile(string houseName, string student1, string student2)
    {
        house* obj=houses[houseName];
        student* s1=NULL;
        student* s2=NULL;

        int s2index=-1;

        int curridx=0;
        for(auto itr:obj->students){
            if(itr->name==student1){
                s1=itr;
            }else if(itr->name== student2){
                s2=itr;
                s2index=curridx;
            }
            if(s1!=NULL && s2!=NULL){
                break;
            }
            curridx++;
        }
        
        if(s2->isExiled==false){
            s2->isExiled=true;
            s1->exilecount++;
            obj->students.erase(obj->students.begin() + curridx);

        }

        return;







    }

    /**
     * Promote the oldest unpromoted student from the provided house.
     * Promoted students can't be exiled.
     */
    void promoteStudent(string houseName)
    {
        house* obj=houses[houseName];
        if(obj->students.size() >0){
            int idx=obj->promoidx;
            if(idx>=obj->students.size()){
                return; // do nothing

            }
            student* student=obj->students[idx];
            student->isExiled=true;
            obj->promoidx++;
        }

    }

    /**
     * Print all students of all houses.
     * Format:
     * <Student1 Name> : <IsPromoted> <ExileUsageCount>
     * <Student2 Name> : <IsPromoted> <ExileUsageCount>
     * ...
     */
    void printStudents()
    {
        for(auto itr:houses){
            for(auto student:itr.second->students){
                bool ispromo=student->isPromoted;
                if(ispromo){
                    cout<<student->name<<" : "<<"true "<<student->exilecount<<endl;
                    
                }else{
                    cout<<student->name<<" : "<<"false "<<student->exilecount<<endl;

                }

            }

        }
    }
};

int main()
{
    Hogwarts hogwarts;

    size_t enrolledStudents = 0;
    enrolledStudents += hogwarts.enrollStudent("Harry", 1) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Ron", 2) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Hermione", 4) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Draco", 8) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Luna", 16) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Luna", 10) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Neville", 1) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Fred", 1) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("George", 1) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Ginny", 1) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Parvati", 1) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Seamus", 2) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Dean", 2) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Lavender", 8) ? 1 : 0;
    enrolledStudents += hogwarts.enrollStudent("Cho", 3) ? 1 : 0;
    cout << "Enrolled students: " << enrolledStudents << endl;

    hogwarts.promoteStudent("Seekers");
    hogwarts.promoteStudent("Keepers");
    hogwarts.promoteStudent("Keepers");

    hogwarts.addSpell("madams", "Seekers", 3);
    hogwarts.addSpell("aasaa", "Seekers", 1);
    hogwarts.addSpell("eve", "Keepers", 3);
    hogwarts.addSpell("ppooppoopp", "Beaters", 1);
    hogwarts.addSpell("yes", "Keepers", 2);
    hogwarts.addSpell("spelleps", "Chasers", 2);
    hogwarts.addSpell("accicca", "Beaters", 2);
    hogwarts.addSpell("fgdbjhka", "Chasers", 1);
    hogwarts.addSpell("racecar", "Chasers", 3);
    hogwarts.addSpell("wow", "Seekers", 2);
    hogwarts.addSpell("hello", "Beaters", 3);
    hogwarts.addSpell("da", "Keepers", 1);
    hogwarts.addSpell("wwoww", "Seekers", 2);

    hogwarts.exile("Seekers", "Harry", "Neville");
    hogwarts.addSpell("wwwowww", "Seekers", 4);
    
    hogwarts.enrollStudent("Maddie", 1);
    hogwarts.exile("Seekers", "Maddie", "Harry");

    hogwarts.printStudents();

    hogwarts.checkSpells();

    hogwarts.printStatus();

    hogwarts.printSpells(2, 4);

    hogwarts.printStudents();

    return 0;
}