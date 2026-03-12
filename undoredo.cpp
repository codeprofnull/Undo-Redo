#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Command{
    public:
    string action;
    int pos;
    char charec;

    Command(string a,int p,char c){
        action = a;
        charec = c;
        pos = p;
    }
};

void insert(vector<char>&doc,stack<Command>&undoStack,stack<Command>&redoStack,char c,int p){
    doc.insert(doc.begin()+p,c);
    Command cmd("insert",p,c);
    undoStack.push(cmd);
    while(!redoStack.empty()){redoStack.pop();};
}

void deleteChar(vector<char>&doc,stack<Command>&undoStack,stack<Command>&redoStack,int p){
    char temp = doc[p]; 
    doc.erase(doc.begin()+p);
    Command cmd("delete",p,temp);
    undoStack.push(cmd);
    while(!redoStack.empty()){redoStack.pop();};
}

void undo(vector<char>&doc,stack<Command>&undoStack,stack<Command>&redoStack){
    if(!undoStack.empty()){
        Command top = undoStack.top();
        if(top.action == "insert"){
            doc.erase(doc.begin()+top.pos);
        }
        else if(top.action == "delete"){
            doc.insert(doc.begin()+top.pos,top.charec);
        };
        undoStack.pop();
        redoStack.push(top);
    }
    else{return;};
}

void redo(vector<char>&doc,stack<Command>&undoStack,stack<Command>&redoStack){
    if(!redoStack.empty()){
        Command top = redoStack.top();
        if(top.action == "insert"){
            doc.insert(doc.begin()+top.pos,top.charec);
        }
        else if(top.action == "delete"){
            doc.erase(doc.begin()+top.pos);
        };
        redoStack.pop();
        undoStack.push(top);
    }
    else{return;};
}

void printDoc(vector<char>&doc){
    for(int i=0;i<doc.size();i++){cout<<doc.at(i);};
    cout<<endl;
}

int main(){
        vector<char> doc;
        stack<Command> undoStack;
        stack<Command> redoStack;

        insert(doc,undoStack,redoStack,'h',0);
        printDoc(doc);
        insert(doc,undoStack,redoStack,'e',1);
        printDoc(doc);
        insert(doc,undoStack,redoStack,'l',2);
        printDoc(doc);
        insert(doc,undoStack,redoStack,'l',3);
        printDoc(doc);
        insert(doc,undoStack,redoStack,'o',4);
        printDoc(doc);
        undo(doc,undoStack,redoStack);
        printDoc(doc);
        undo(doc,undoStack,redoStack);
        printDoc(doc);
        redo(doc,undoStack,redoStack);
        printDoc(doc);


    }