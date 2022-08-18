//
// Created by salih on 22.12.2021.
//

#include "Executor.h"



void Executor::execute(string input, string output) {

    string message ="";
    Node root;
    root.key="-61k"; root.value="-61v"; root.children.push_back(&root);//temporary root creation

    vector<string> allInputLines = Helper::readFile(input);
    vector<Node> vec;


    for(auto line : allInputLines){//read all lines and perform the given order
        char order = line[0];
        string key, value;


        switch (order) {


            case 'l'://if the order is list

                //cout<<line+"-->"+key+" "+value+"\n";
                list(vec,message);

                break;
            case 'i'://if the order is insert(key,value)

                key = //convert insert(key,value) to key
                Helper::split(Helper::split(Helper::split(line,"(")[1],")")[0],",")[0];

                value = //convert insert(key,value) to value
                Helper::split(Helper::split(Helper::split(line,"(")[1],")")[0],",")[1];

                insert(vec, key,value,message);


                break;
            case 'd'://if the order is delete(key)

                key = // convert delete(key) to key
                        Helper::split(Helper::split(line,"(")[1],")")[0];
                del(vec, key,message);

                //cout<<line+"-->"+key+" "+value+"\n";

                break;
            case 's'://if the order is search

                key = // convert search(key) to key
                        Helper::split(Helper::split(line,"(")[1],")")[0];
                search(vec,key,message);

                //cout<<line+"-->"+key+" "+value+"\n";



                break;
            default://if there is something wrong

                //cout<<line+"\nsomething wrong with that line";

                message+= line+"\nsomething wrong with that line";
                break;
        }



    }

    Helper::write(output,message);


}

void Executor::del(vector<Node> &vec ,string key, string &message) {

    //cout<<"\n---deletion---"+key+"\n";
    int counter=-1;

    //if already inserted find index
    for(int i=0; i < vec.size();i++){

        if(vec.at(i).key==key){

            counter=i;
            break;

        }
    }

    if(counter==-1){// if it is not in trie

        bool a = false;//is substr
        bool b = false;//is not enough

        for(auto i: vec){

            string s1 = i.key;
            string s2 = key;

            if(s2[0]==s1[0]){
                b= true;
                if (s1.find(s2) != std::string::npos) {
                    a = true;
                    break;
                }
            }else{
                continue;
            }


        }
        if (b){

            if(a){
                message+="\"not enough Dothraki word\"\n";
            }else{
                message+="\"incorrect Dothraki word\"\n";
            }

        }else{
            message+="\"no record\"\n";

        }

    }else{//if already existed


        message+="\""+vec.at(counter).key+"\" deletion is successful\n";
        vec.erase(vec.begin()+counter);


    }


}

void Executor::search(vector<Node> &vec ,string key, string &message) {

    //cout<<"\n---search---"+key+"\n";

    int counter=-1;

    //if already inserted find index
    for(int i=0; i < vec.size();i++){

        if(vec.at(i).key==key){

            counter=i;
            break;

        }
    }

    if(counter==-1){// if it is not in trie

        bool a = false;//is substr
        bool b = false;//is not enough
        for(auto i: vec){

            string s1 = i.key;
            string s2 = key;

            if(s2[0]==s1[0]){
                b= true;
                if (s1.find(s2) != std::string::npos) {
                    a = true;
                    break;
                }
            }else{
                continue;
            }

            if (s1.find(s2) != std::string::npos) {
                a = true;
                break;
            }
        }
        if (b){
            if(a){
                message+="\"not enough Dothraki word\"\n";//kemo kem
            }else{
                message+="\"incorrect Dothraki word\"\n";// kemo komo
            }

        }else{
            message+="\"no record\"\n";

        }

    }else{//if already existed

        message+="\"The English equivalent is "+vec.at(counter).value+"\"\n";


    }



}

void Executor::insert(vector<Node> &vec ,string key, string value, string &message) {
    //cout<<key+" "+ value;
    //cout<<"\n---insert---"+key+"\n";


    Node node;
    node.value=value;

    //cout<<node.value;
    int counter=-1;

    //if already inserted find index
    for(int i=0; i < vec.size();i++){

        if(vec.at(i).key==key){

            counter=i;
            break;

        }
    }

    if(counter==-1){// if it is not in trie

        node.key=key; node.value = value;
        //cout<<"sa";

        vec.push_back(node);
        message+="\""+key+"\" was added\n";

    }else{//if already existed

        if(vec[counter].value==value){

            message+="\""+key+"\" already exists\n";
        }else{
            vec[counter].value=value;
            message+="\""+key+"\" was updated\n";
        }

    }


}

void Executor::list(vector<Node> &vec, string &message) {


    std::sort(vec.begin(), vec.end(),less_than_key());


    for (auto i: vec){

        message+="-"+i.key+"("+i.value+")\n";

    }


}

